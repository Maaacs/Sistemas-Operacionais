#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "terminal.h"

int main(void) {
    char entrada[INPUT_LIMITE];
    char caminho_diretorio[200]; 
    printf("Bem vindo ao Proto Terminal!\n");

    while (printf("%s $>", getcwd(caminho_diretorio, 200))) { // getcwd retorna o  dir atual
        scanf("%[^\n]%*c", entrada); // lê todos os caracteres digitados incluindo espaço em branco %*c
        processaEntradas(entrada);
    }

    return 0;
}