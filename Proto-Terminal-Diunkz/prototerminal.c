// Prototerminal - Sistemas Operacionais
// Alunos: 
// Noah Diunkz
// Gabriel Pacheco
// Max Souza

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_ARGS 10
#define MAX_INPUT_LENGTH 1024

// Função que executa um comando
void execute_command(char *args[], int background, const char *output_filename) {
    // Cria um processo filho
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork error");
    } else if (pid == 0) {  // Processo filho
        // Redireciona a saída, se necessário
        if (output_filename != NULL) {
            int output_fd = open(output_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (output_fd == -1) {
                perror("Output file open error");
                exit(EXIT_FAILURE);
            }
            dup2(output_fd, STDOUT_FILENO); // Redireciona a saída padrão para o arquivo
            close(output_fd); // Fecha o descritor de arquivo
        }

        // Executa o comando, substituindo o processo filho
        if (execvp(args[0], args) == -1) {
            perror("Command execution error");
            exit(EXIT_FAILURE);
        }

        // Redireciona a saída de volta para o terminal
        dup2(STDOUT_FILENO, 1);
    } else {  // Processo pai
        if (!background) {
            waitpid(pid, NULL, 0); // Aguarda pelo término do processo filho
        }
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_ARGS];

    while (1) {
        printf("Proto Terminal> ");
        fflush(stdout);

        ssize_t bytes_read = read(0, input, sizeof(input));

        if (bytes_read <= 0) {
            break; // Encerra o loop se não houver mais entrada
        }

        input[bytes_read] = '\0';
        input[strcspn(input, "\n")] = '\0'; // Remove a quebra de linha

        if (strcmp(input, "exit") == 0) {
            break; // Encerra o loop se o comando for "exit"
        }

        char *token = strtok(input, " ");
        int arg_count = 0;
        int background = 0;
        const char *output_filename = NULL;

        // Analisa os tokens da entrada
        while (token != NULL) {
            if (strcmp(token, "&") == 0) {
                background = 1; // Define o sinalizador para execução em segundo plano
            } else if (strcmp(token, ">") == 0) {
                token = strtok(NULL, " ");
                if (token != NULL) {
                    output_filename = token; // Define o nome do arquivo de saída
                } else {
                    printf("Usage: > <output_filename>\n");
                }
            } else {
                args[arg_count++] = token; // Armazena os argumentos
            }
            token = strtok(NULL, " ");
        }

        if (arg_count > 0) {
            args[arg_count] = NULL; // Finaliza a lista de argumentos
            if (strcmp(args[0], "cd") == 0) {
                if (arg_count > 1) {
                    if (chdir(args[1]) != 0) {
                        perror("cd error");
                    }
                } else {
                    printf("Usage: cd <directory>\n");
                }
            } else {
                execute_command(args, background, output_filename); // Executa o comando
            }
        }
    }

    return 0;
}
