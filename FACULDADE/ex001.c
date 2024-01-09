#include <stdio.h>
#include <stdlib.h>

void MaxMin(int v[], int *maior, int *menor){
    *maior = v[0], *menor = v[0];
    for(int i = 1; i < 5; i++){
        if(v[i] > *maior){
            *maior = v[i];
        }

        if(v[i] < *menor){
            *menor = v[i];
        }
    }
}

int main(){
    int v[] = {7,2,3,4,28};
    int maior, menor;

    system("cls");

    MaxMin(v, &maior, &menor);

    printf("O MAIOR NUMERO É %d.\n O MENOR NUMERO É %d.\n", maior, menor);


    return 0;
}