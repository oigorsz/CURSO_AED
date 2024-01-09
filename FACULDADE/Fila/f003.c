#include <stdio.h>
#include <stdlib.h>

int main(){
    int cliente, caixa;

    system("cls");

   

    do {
        printf("DIGITE O NUMERO DE CLIENTES E DEPOIS O DE CAIXAS.\n");
        scanf("%d %d", &cliente, &caixa);
    } while (!(1 <= cliente && cliente <= 1023 && 1 <= caixa && caixa <= 25));

    
    
    
}