#include <stdio.h>
#include <stdlib.h>

void preencherVetor(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("DIGITE O VALOR DO VETOR[%d]:\n => ", i);
        scanf("%d", vetor);
        *vetor++;
        system("cls");
    }
}

void printVetor(int *vetor, int tamanho){
    printf("ANALISE DO VETOR:\n");

    for(int i = 0; i < tamanho; i++){
        printf(" %d,", *vetor);
        *vetor++;
    }

}

int soma(int *vetor, int tamanho){
    int soma = 0;

    for(int i = 0; i < tamanho; i++){
        soma += *vetor;
        *vetor++;
    }

    return soma;
}

int maior(int *vetor, int tamanho){
    int maior = *vetor;

    for(int i = 0; i < tamanho; i++){
        if(*vetor >= maior){
            maior = *vetor;
        }

        *vetor++;
    }

    return maior;
}

int menor(int *vetor, int tamanho){
    int menor = *vetor;

    for(int i = 0; i < tamanho; i++){
        if(*vetor <= menor){
            menor = *vetor;
        }

        *vetor++;
    }

    return menor;
}

int main(){
    int tamanho;

    system("cls");

    printf("QUNTOS VALORES SERAO INSERIDOS ?");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    preencherVetor(vetor, tamanho);
    printVetor(vetor, tamanho);

    printf("\nSOMA DO VETOR: %d\n", soma(vetor, tamanho));
    printf("MENOR VALOR DO VETOR: %d\n", menor(vetor, tamanho));
    printf("MAIOR VALOR DO VETOR: %d\n", maior(vetor, tamanho));
}