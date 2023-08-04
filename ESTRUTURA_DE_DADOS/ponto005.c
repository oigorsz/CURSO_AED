/*Escreva uma função que receba um array de inteiros e seu tamanho como argumentos,
e use ponteiros para calcular a soma de todos os elementos do array.*/

#include <stdio.h>
#include <stdlib.h>

int somaVetor(int *array, int tamanho){
    int soma = 0;

    for(int i = 0; i < tamanho; i++){
        soma += array[i];
    }

    return soma;
}

int main(void){

    int array [] = {1, 2, 3, 4, 5, 6};
    int tamanho = sizeof(array)/ sizeof(array[0]); //mensura o tamanho do array

    printf("SOMA DO VETOR: %d", somaVetor(array, tamanho));

    return 0;
}