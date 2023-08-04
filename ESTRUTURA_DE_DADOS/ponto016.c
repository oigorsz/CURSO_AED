#include <stdio.h>

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main() {
    int x = 10, y = 20;

    printf("X = %d e Y = %d\n", x, y);

    swap(&x, &y);

    printf("X = %d e Y = %d\n", x, y);

    return 0;
}