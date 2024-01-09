#include <stdio.h>
#include <stdlib.h>

int main(){
    int caracteres = 0, linhas = 0;
    char caracter;
    FILE *arq;

    system("cls");

    arq = fopen("teste6.txt", "w");

    if(arq == NULL){
        printf("ARQUIVO NÃO ENCONTRADO.\n");
        return 1;
    }

    fprintf(arq, "start file\n");

    fclose(arq);

    arq = fopen("teste6.txt", "r");

    if(arq == NULL){
        printf("ARQUIVO NÃO ENCONTRADO.\n");
        return 1;
    }

    printf("LEITURA 1.\n");

    while ((caracter = fgetc(arq)) != EOF)
    {
        if(caracter == '\n'){
            linhas++;
        }
        caracteres++;
        printf("%c", caracter);
    }

    if(caracteres > 0){
        linhas++;
    }

    printf("LINHAS: %d\nCARACTERES: %d\n", linhas, caracteres);

    fclose(arq);

    linhas = 0, caracteres = 0;

    arq = fopen("teste6.txt", "a");

    if(arq == NULL){
        printf("ARQUIVO NÃO ENCONTRADO.\n");
        return 1;
    }

    fprintf(arq, "igor\njose\nsimao\npedro\n");

    fclose(arq);

    arq = fopen("teste6.txt", "r");

    if(arq == NULL){
        printf("ARQUIVO NÃO ENCONTRADO.\n");
        return 1;
    }

    printf("\nLEITURA 2\n");

    while ((caracter = fgetc(arq)) != EOF)
    {
        if(caracter == '\n'){
            linhas++;
        }
        caracteres++;
        printf("%c", caracter);
    }

    if(caracter > 0){
        linhas++;
    }

    printf("\nLINHAS: %d\nCARACTERES: %d\n", linhas, caracteres);
    

    printf("\nFIM\n");

    return 0;
}