#include <stdio.h>
#include <stdlib.h>

int soma(int n1, int n2){
    int soma = n1 + n2;
    return soma;
}

int sub(int n1, int n2){
    int sub = n1 - n2;
    return sub;
}

int mult(int n1, int n2){
    int mult = n1*n2;
    return mult;
}



int main(){
    int n1, n2, op = 0, res;
    
    system("cls");

    printf("DIGITE UM NUMERO INTEIRO:\n =>");
    scanf("%d", &n1);

    printf("DIGITE OUTRO NUMERO INTEIRO:\n =>");
    scanf("%d", &n2);

    system("cls");

    while(!(op == 1 || op == 2 || op == 3)){
        printf("\nDIGITE \n1-ADICAO\n2-SUBTRACAO\n3-MULTIPLICACAO\n\n");
        scanf("%d", &op);
    }
    
    system("cls");

    if(op == 1){
        res = soma(n1,n2);
        printf("SOMA: %d.\n", res);
    }
    if(op == 2){
        res = sub(n1, n2);
        printf("SUBTRACAO: %d.\n", res);
    }
    if(op == 3){
        res = mult(n1, n2);
        printf("MULTIPLICACAO: %d.\n", res);
    }
    

    return 0;
}