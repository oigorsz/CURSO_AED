#include <stdio.h>
#include <stdlib.h>

void ordenar(float *v, int n){
    int i, j, temp;

    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i -1; j++){
            if(v[j] > v[j + 1]){
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}


int main(){
    int tamanho, i;
    float *vetor;

    system("cls");

    do {
        printf("DIGITE O NUMERO DE ELEMENTOS DO VETOR:\n => ");
        scanf("%d", &tamanho);
    } while(tamanho <= 0);

    vetor = (float *)malloc(sizeof(float) * tamanho);

    if(vetor == NULL){
        printf("[ERRO]");
        exit(1);
    }

    for(i = 0; i < tamanho; i++){
        printf("DIGITE O VALOR DO VEOTOR[%d]: => ", i);
        scanf("%f", &vetor[i]);
    }

    system("cls");

    printf("VETOR ORIGINAL:\n");

    for(i = 0; i < tamanho; i++){
        printf("VETOR [%d] = %.2f\n", i, vetor[i]);
    }

    ordenar(vetor, tamanho);

    printf("VETOR ORDENADO:\n");

    for(i = 0; i < tamanho; i++){
        printf("VETOR[%d] = %.2f\n", i, vetor[i]);
    }

    free(vetor);
    

    return 0;
}