#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terminal.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h> 
#include <fcntl.h>


void funcao_pwd(void){
	char dir[200];
	printf("\n %s \n\n",getcwd(dir,200));
}

void funcao_cd(char * dir){	
	if(chdir(dir))
		printf("Diretório inexistente.\n");
    else{
	    funcao_pwd();
    }
}

void funcao_ls(void){
	printf("Arquivos e pastas do diretorio atual : \n");
	system("ls");	
}


void funcao_dois_processos(char *args1[ARG_LIMITE], char *args2[ARG_LIMITE]){
	int descritor[2];
	int pstat = pipe(descritor); // Cria um canal de comunicação unidirecional (pipe) que permite a transferência de dados entre processos

	if(pstat < 0){
		printf("Falha ao tentar usar pipe\n");
		exit(1);
	}

	int processo_filho = fork();
	if(processo_filho < 0){
		printf("Falha ao criar processo\n");
		exit(1);
	}else if(processo_filho == 0){
		close(1); // Fecha a saída padrão (stdout) no processo filho
		close(descritor[0]); // Fecha o descritor de leitura do pipe no processo filho
		dup(descritor[1]); // Redireciona a saída padrão do processo filho para o pipe
		execvp(args1[0],args1); // Executa o primeiro comando (args1) no contexto do processo filho
		exit(1); // Encerra o processo filho em caso de erro na execução do comando
	}else{
		wait(NULL); // Aguarda o término do processo filho
		close(0); // Fecha a entrada padrão (stdin) no processo pai
		close(descritor[1]); // Fecha o descritor de escrita do pipe no processo pai
		dup(descritor[0]); // Redireciona a entrada padrão do processo pai para ler do pipe
		execvp(args2[0],args2); // Executa o segundo comando (args2) no contexto do processo pai
	}
}

void funcao_in_out(char * args[ARG_LIMITE], char *filename, int mode){
	int i = 0;
	while (args[i]){
		printf("%s\n",args[i++]);
    }

    close(STDOUT_FILENO);
    
    open(filename, O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);   // Abre o arquivo especificado em "filename" com opções de abertura

    printf("%s", filename); // Imprime o nome do arquivo

    printf("%s", filename);

	execvp(args[0],args);   // Executa o comando 
	
	execvp(args[0],args);
}


void processo_comando(char * arq){
	char * auxiliar_tokens;
	char * args[ARG_LIMITE];
	char * pargs[ARG_LIMITE];
	char filename[FILENAME_LIMITE];
	int i = 0,j = 0;
	int piping = 0;
	int in_out = 0;

	auxiliar_tokens = strtok(arq," "); // Divide a entrada em tokens (partes) usando espaços como delimitadores

	while(auxiliar_tokens != NULL){

		if(!strcmp(auxiliar_tokens,"|")){
            // Se encontrar o caractere "|", indica que há uma piping
			piping = 1;

            // Copia os argumentos anteriores para pargs e redefine args
			for(j = 0; j<i;j++){
				pargs[j] = args[j];
				args[j] = NULL;
			}
			pargs[j] = NULL;
			i = 0;
		}else if(!strcmp(auxiliar_tokens,">")){ // Se encontrar o caractere ">", indica redirecionamento de saída
			args[i] = NULL;
			auxiliar_tokens = strtok(NULL," ");
			strcpy(filename,auxiliar_tokens); // Copia o nome do arquivo de redirecionamento
			funcao_in_out(args,filename,1);
			i = 0;
		}else if(!strcmp(auxiliar_tokens,"<")){ // Se encontrar o caractere "<", indica redirecionamento de entrada
			in_out = 1;
			args[i] = NULL;
			auxiliar_tokens = strtok(NULL," ");
			strcpy(filename,auxiliar_tokens);
		}else
			args[i++] = auxiliar_tokens; // Se não for um caractere especial, trata como um argumento e armazena em "args"

		auxiliar_tokens = strtok(NULL," ");
	}
	args[i] = NULL;

	if(piping) // Se houver piping, chama funcao_dois_processos
		funcao_dois_processos(pargs,args);	
	else if(in_out){
            // Se houver redirecionamento de entrada/saída, faz o redirecionamento e executa o comando
			close(0);
			int ap = open(filename, O_RDONLY);
			dup(ap);
			if(fork() == 0){
				execvp(args[0], args);
				exit(1);
			}else wait(NULL);
		

		}
	else
        // Se não houver piping ou redirecionamento, executa um novo programa
		execvp(args[0],args);

}



void processa_entradas(char * str){
    char *arg; // Variável para armazenar os tokens
    char entrada[INPUT_LIMITE]; // Vetor para armazenar a entrada digitada no terminal
	char buffer[BUFFER_SIZE]; 

	strcpy(entrada,str); // Copia a entrada digitada(str) para a variável entrada
	arg = strtok(str," ");  // Divide a entrada em palavras (tokens) usando espaços como delimitadores

	if(!strcmp(arg,"exit")){ // Se o primeiro token for "exit"
		printf("Encerrando terminal! !\n");
		exit(0);
	}

	int processo_filho = fork(); // Cria um novo processo (filho)

	if(processo_filho < 0){
		printf("Fork falhou !\n");
		return;
	}else if(processo_filho == 0){

		if(!strcmp(arg,"cd")){
			arg = strtok(NULL," ");
            funcao_cd(arg);

		}else if(!strcmp(arg,"pwd")){
			funcao_pwd();
		}  else {
            // Se não for "cd" nem "pwd", assume que é um comando a ser executado
			processo_comando(entrada); // processa comando
		}
	}else wait(NULL);
}
