#include <stdio.h>
#include <stdlib.h>

int fatorial(int number){

    if(number == 0 || number == 1){
        return 1;
    }

    int res = 1;

    for(int i = number; i > 1; i--){
        res *= i;
    }

    return res;

    
}


int main(void){
    int number;

    system("cls");

    printf("DIGITE UM NUMERO INTEIRO POSITIVO:\n => ");
    scanf("%d", &number);

    system("cls");

    printf("%d.\n", fatorial(number));


    return 0;
}