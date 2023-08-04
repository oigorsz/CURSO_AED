/*Crie um programa em C que declare duas variáveis inteiras "x" e "y".
 Em seguida, crie uma função chamada "swap" que receba dois ponteiros para inteiros 
 e troque os valores apontados por eles. No programa principal, chame a função "swap" 
 passando os endereços das variáveis "x" e "y" e exiba os valores após a troca.*/

#include <stdio.h>


int main(void){

    int x = 10, y = 20;

    printf("ANTES DO SWAP: x = %d e y = %d.\n", x, y);
    swap(&x, &y);
    printf("DEPOIS DO SWAP: x = %d e y = %d.\n", x , y);

    return 0;
}

void swap(int *a, int *b){
    int i = *a;
    *a = *b;
    *b = i;

}