#include <stdio.h>
#define TAM 150

int main(){
    int linhas = 0;
    char linha[TAM];
    FILE *arq;

    arq = fopen("new.txt", "w");

    if(arq == NULL){
        printf("[ERRO PARA ABRIR ARQUIVO.\n");
        return 1;
    }

    fprintf(arq, "OLA MUNDO\n VOCES TAO BAUM\nTESTANDO :)");
    fclose(arq);

    arq = fopen("new.txt", "r");

    if(arq == NULL){
        printf("[ERRO PARA ABRIR ARQUIVO.\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), arq) != NULL)
    {
        linhas++;
        printf("%s", linha);
    }

    printf("\nTOTAL DE LINHAS: %d.\n", linhas);

    printf("\nFIM\n");

    fclose(arq);

    return 0;
}