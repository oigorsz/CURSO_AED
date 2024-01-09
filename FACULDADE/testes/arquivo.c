#include <stdio.h>
#define TAM 200

int main() {
    char linha[TAM];
    FILE *arquivo;

    arquivo = fopen("t.txt", "r");

    if (arquivo == NULL) {
        printf("[ERRO DE ABERTURA].\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    printf("\nFIM.\n");

    fclose(arquivo);

    return 0;
}
