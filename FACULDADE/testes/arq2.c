#include <stdio.h>

int main(){
    int caracteres = 0, linhas = 0;
    char caracter;
    FILE *arquivo;

    arquivo = fopen("t.txt", "r");

    if(arquivo == NULL){
        printf("[ERRO DE LEITURA].\n");
        return 1;
    }

    while ((caracter = fgetc(arquivo)) != EOF)
    {
        caracteres++;
        if(caracter == '\n'){
            linhas++;
        }
        printf("%c", caracter);
    }

    if(caracteres > 0){
        linhas++;
    }

    printf("\nTOTAL DE CARACTERES: %d.\nTOTAL DE LINHAS: %d.\n", caracteres, linhas);

    fclose(arquivo);


    return 0;

}