#include <stdio.h>
#define TAM 150

int main(){
    int linhas = 0;
    char linha[TAM];
    FILE *arq, arqread;

    arq = fopen("novo.txt", "w");

    if(arq == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        return 0;
    }

    fprintf(arq, "ESTOU ABRINDO UM NOVO ARQUIVO.\n VOU ADICIONAR MAIS UMA LINHA.");
    fclose(arq);

    arq = fopen("novo.txt", "r");

    if(arq == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        return 0;
    }

    while (fgets(linha, sizeof(linha), arq) != NULL)
    {
        linhas++;
        printf("%s", linha);
    }

    printf("\nNUMERO DE LINHAS: %d.\n", linhas);

    fclose(arq);

    printf("\nFIM DO PROGRAMA.\n");
    
    return 0;
}