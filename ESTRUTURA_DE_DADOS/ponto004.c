#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main(void){
    int x, y;

    system("cls");

    printf("DIGITE UM NUMERO INTEIRO PARA X:\n => ");
    scanf("%d", &x);
    printf("DIGITE UM NUMERO INTEIRO PARA Y:\n => ");
    scanf("%d", &y);

    system("cls");

    printf("ANTES DA TROCA:\nX = %d Y = %d\n", x, y);
    swap(&x, &y);
    printf("DEPOIS DA TROCA:\nX = %d Y = %d\n", x, y);

    return 0;
}