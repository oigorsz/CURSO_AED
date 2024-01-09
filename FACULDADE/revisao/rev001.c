#include <stdio.h>
#include <stdlib.h>


int verificar(int matriz[][], int ordem){

}


int main(){
    int matriz[3][3]= {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int ordem = 3;

    system("cls");

    int resultado = verificar(matriz, ordem);

    if(resultado == 0){
        printf("MATRIZ NORMAL.\n");
    } else {
        if(resultado == 1){
            printf("MATRIZ IDENTIDADE.\n");
        } else if(resultado == 2) {
            printf("MATRIZ TRIANGULAR SUPERIOR");
        } else {
            printf("MATRIZ IDENTIDADE INFERIOR.\n");
        }
    }


    return 0;
}