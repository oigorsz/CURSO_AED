#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;

    system("cls");

    printf("DIGITE UM NUMERO INTEIRO:\n => ");
    scanf("%d", &num);

    system("cls");

    int *ptr = &num;

    printf("VALOR DE NUM: %d.\n", num);
    printf("O ENDERECO DE NUM: %p.\n", (void*)&num);
    printf("O VALOR DO PONTEIRO: %p.\n", (void*)ptr);
    printf("O VALOR APONTADO PELO PONTEIRO: %d.\n", *ptr);

    return 0;
}
