#include <stdio.h>
#include <stdlib.h>

int remove_dup (float *v, int *t){
    int i, j, k, aux;

    aux = *t;

    for(i = 0; i < *t; i++){
        for(j = i + 1; j < *t; j++){
            if(v[i] == v[j]){
                for(k = j; k < (*t) - 1; k++){
                    v[k] = v[k + 1];
                    (*t)--;
                }
            }
        }
    }

    if(aux == *t){
        return 0;
    } else {
        return aux - *t;
    }
}

int main(){
    int tamanho, i, resultado;
    float *vetor;

    system("cls");

    printf("DIGITE O NUMERO DE ELEMENTOS DO VETOR:\n => ");
    scanf("%d", &tamanho);

    vetor = (float*)malloc(sizeof(float) * tamanho);

    if(vetor == NULL){
        printf("[ERRO]");
        exit(1);
    }

    for(i = 0; i < tamanho; i++){
        printf("DIGITE O VALOR DO VETOR[%d]: => ", i);
        scanf("%f", &vetor[i]);
    }

    system("cls");

    printf("VETOR ORIGINAL:\n");
    for(i = 0; i < tamanho; i++){
        printf("VETOR[%d] = %.2f\n", i, vetor[i]);
    }

    resultado = remove_dup (vetor, &tamanho);

    printf("VETOR MODIFICADO (%d NUMEROS DUPLICADOS)\n", resultado);

    for(i = 0; i < tamanho; i++){
        printf("VETOR[%d] = %.2f\n", i, vetor[i]);
    }

    free(vetor);

    return 0;
}