/*
Alocação dinâmica de memória
Escreva um programa que solicite ao usuário a quantidade de elementos de um array 
e depois leia esses elementos. Use alocação dinâmica de memória (ponteiros) 
para armazenar os elementos e, em seguida, exiba-os na ordem inversa.
*/


#include <stdio.h>
#include <stdlib.h>

int main(void){
    int tamanho;

    system("cls");

    printf("DIGITE A QUANTIDADE DE ELEMNTOS DO ARRAY:\n => ");
    scanf("%d", &tamanho);

    system("cls");

    int *array = (int *)malloc(tamanho * sizeof(int)); //armazenar memória suficiente para alocar os elementos do vetor

    for(int i = 0; i < tamanho; i++){
        printf("DIGITE O VALOR DO ELEMENTO [%d]:\n => ", i);
        scanf("%d", &array[i]);
    }

    printf("VETOR NA ORDEM INVERSA:\n");

    for(int i = tamanho - 1; i >= 0; i--){
        printf("VETOR[%d] = %d\n", i, array[i]);
    }

    free(array);

    return 0;
}