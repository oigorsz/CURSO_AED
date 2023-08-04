#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int somaVetor(int *vetor, int tamanho){
    int soma = 0;

    for(int j = 0; j < tamanho; j++){
        soma += vetor[j];
    }

    return soma;
}

int main(void){
    int vetor[TAM];
    int tamanho = TAM;

    system("cls");

    for(int i = 0; i < TAM; i++){
        printf("DIGITE UM NUMERO INTEIRO(%d/5):\n => ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("SOMA DO VETOR: %d\n", somaVetor(vetor, tamanho));


    return 0;
}