#include <stdio.h>

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
    int vetor[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);

    printf("SOMA DO VETOR: %d\n", soma(vetor, tamanho));
    printf("MENOR VALOR DO VETOR: %d\n", menor(vetor, tamanho));
    printf("MAIOR VALOR DO VETOR: %d\n", maior(vetor, tamanho));


    return 0;
}