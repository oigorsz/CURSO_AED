#include <stdio.h>
#include <stdlib.h>

void MaxMin(int v[], int *maior, int *menor, int tamanho){
    *maior = v[0], *menor = v[0];

    for(int i = 1; i < tamanho; i++){
        if(v[i] > *maior){
            *maior = v[i];
            continue;
        }

        if(v[i] < *menor){
            *menor = v[i];
        }
    }
}

int main(){
    int tamanho = -1;

    system("cls");

    while (tamanho < 1)
    {
        printf("QUANTOS NUMEROS HAVERÁ NO VETOR:\n => ");
        scanf("%d", &tamanho);
        system("cls");
    }

    int vetor[tamanho];
    int maior, menor;

    for(int i = 0; i < tamanho; i++){
        printf("DIGITE O VALOR DE V[%d]:\n => ", i);
        scanf("%d", &vetor[i]);
        system("cls");
    }

    MaxMin(vetor, &maior, &menor, tamanho);

    printf("MAIOR: %d.\nMENOR: %d.\n", maior, menor);
    
}