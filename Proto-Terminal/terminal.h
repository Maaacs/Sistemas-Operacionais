#ifndef TERMINAL_H // Evita inclusão múltipla do cabeçalho no terminal.c (evita refedinição de símbolos)
#define TERMINAL_H

#define INPUT_LIMITE 300
#define BUFFER_SIZE 600
#define ARG_LIMITE 10
#define FILENAME_LIMITE 200


void funcao_pwd(void);
void funcao_cd(char * str);
void funcao_ls(void);
void funcao_dois_processos(char *args1[ARG_LIMITE], char *args2[ARG_LIMITE]);
void funcao_in_out(char * args[ARG_LIMITE], char *filename,int mode);
void processo_comando(char * arq);
void processa_entradas(char *str);

#endif
