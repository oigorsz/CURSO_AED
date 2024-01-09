#include <stdio.h>
#include <stdlib.h>
#define TAM 150

int main(){
    int linhas = 0;
    char linha[TAM];
    FILE *arq;

    arq = fopen("teste.txt", "w");

    if(arq == NULL){
        printf("[ERRO DE ABRIR ARQUIVO].\n");
        return 1;
    }

    fprintf(arq, "STAR FILE\n");

    fclose(arq);

    arq = fopen("teste.txt", "r");

    if(arq == NULL){
        printf("[ERRO DE ABRIR ARQUIVO].\n");
        return 1;
    }

    printf("LEITURA 1.\n");

    while (fgets(linha, sizeof(linha), arq) != NULL)
    {
        printf("%s", linha);
        linhas++;
    }

    printf("TOTAL DE LINHAS LEITURA 1: %d.\n", linhas);

    fclose(arq);

    arq = fopen("teste.txt", "a");

    if(arq == NULL){
        printf("[ERRO DE ABRIR ARQUIVO].\n");
        return 1;
    }

    fprintf(arq, "igor\njoao\nreinaldo\njoaquim");
    fclose(arq);

    arq = fopen("teste.txt", "r");

    printf("\nLEITURA 2\n");

    linhas = 0;

    while (fgets(linha, sizeof(linha), arq) != NULL)
    {
        linhas++;
        printf("%s", linha);
    }

    printf("TOTAL DE LINHAS LEITURA 2: %d", linhas);

    fclose(arq);
    
    return 0;
}