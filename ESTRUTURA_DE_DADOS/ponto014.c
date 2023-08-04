#include <stdio.h>

int main(){
    int x = 10;
    int *ponteiro;
    ponteiro = &x;

    printf("%d\n", x);//VALOR QUE A VARIÁVEL X ARMAZENA
    printf("%d\n", &x);//ENDEREÇO DE MEMÓRIA DA VARIÁVEL X
    printf("%d\n", ponteiro);//APONTA PARA O ENDEREÇO DE MEMORIA DE X
    printf("%d\n", *ponteiro);//APONTA PARA O VALOR


    return 0;
}