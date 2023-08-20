#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terminal.h"


// CRIAR AS FUNÇÕES


void processaEntradas(char * str){
    char * arg; // Variável para armazenar os tokens
    char entrada[INPUT_LIMITE]; // Vetor para armazenar a entrada digitada no terminal

    strcpy(entrada,str);  // Copia a entrada digitada(str) para a variável entrada
    arg = strtok(str," ");  // Divide a entrada em palavras (tokens) usando espaços como delimitadores

    if(!strcmp(arg,"exit")){
        printf("Encerrando terminal!\n");  // Se o primeiro token for "exit"
        exit(0);  // Encerra o programa
    }

    // Aqui entre os outros casos chamando as funções (ls, pwd, etc )
}
