#include <stdio.h>
#include <stdlib.h>


int fatorial(int number){
    if(number == 0 || number == 1){
        return 1;
    } else {
        return number * fatorial(number - 1);
    }
}


int main(void){
    int number = -1;

    system("cls");

    while (number < 0){
        printf("DIGITE UM NUMERO INTEIRO POSITIVO:\n => ");
        scanf("%d", &number);
    }

    system("cls");

    printf("RESULTADO: %d.\n", fatorial(number));

   
}