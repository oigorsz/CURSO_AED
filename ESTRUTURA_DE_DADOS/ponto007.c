/*
Encontrar o maior elemento de um array
Escreva uma função que receba um array de inteiros e seu tamanho como argumentos, 
e use ponteiros para encontrar o maior elemento do array.
*/

#include <stdio.h>
#include <stdlib.h>

int maior(int *vetor, int tamanho){
    int maior = vetor[0];

    for(int i = 0; i < tamanho; i++){
        if(vetor[i] >= maior){
            maior = vetor[i];
        }
    }

    return maior;
}

int menor(int *vetor, int tamanho){
    int menor = vetor[0];

    for(int i = 0; i < tamanho; i++){
        if(vetor[i] <= menor){
            menor = vetor[i];
        }
    }

    return  menor;
}


int main(void){
    int vetor[] = {10, 7, 17, 3800, 2};
    int tamanho = sizeof(vetor)/ sizeof(vetor[0]);

    printf("O MAIOR NUMERO DO VETOR E: %d.\n", maior(vetor, tamanho));
    printf("O MENOR NUMERO DO VETOR E : %d.\n", menor(vetor, tamanho));
    return 0;
}