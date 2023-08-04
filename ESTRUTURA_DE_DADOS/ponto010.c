/*
Escreva uma função que receba um vetor de inteiros 
e retorne o maior elemento encontrado no vetor.
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



int main(void){
    int vetor[] = {1, 2, 4, 7, 10};
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);
    
    
    printf("O MAIOR NUMERO DO VETOR E: %d.\n", maior(vetor, tamanho));

    return 0;
}