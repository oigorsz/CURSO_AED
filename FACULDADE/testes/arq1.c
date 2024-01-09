#include <stdio.h>
#define TAM 150

int main(){
    int linhas = 0;
    char linha[TAM];
    FILE *arquivo;

    arquivo = fopen("t.txt", "r");

    if(arquivo == NULL){
        printf("[ARQUIVO NÃO FOI ABERTO].\n");
        return 1;
    }

    while (fgets(linha, TAM, arquivo) != NULL){
        linhas++;
        printf("%s\n", linha);
    }

    printf("TOTAL DE LINHAS: %d", linhas);
    fclose(arquivo);


    
    return 0;
}