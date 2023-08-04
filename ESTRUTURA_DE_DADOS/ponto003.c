#include <stdio.h>

int main(void){
    int x = 50, y = 100;

    printf("ANTES DO SWAP: x = %d e y = %d.\n", x, y);
    printf("ENDERECO ANTES DO SWAP: x = %p e y = %p.\n", (void*)&x, (void*)&y);
    swap(&x, &y);
    printf("DEPOIS DO SWAP: x = %d e y = %d.\n", x, y);
    printf("ENDERECO DEPOIS DO SWAP: x = %p e y = %p.\n", (void*)&x, (void*)&y);

    return 0;
}

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}