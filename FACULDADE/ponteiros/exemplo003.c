#include <stdio.h>
#include <stdlib.h>

int filtro(float v[], int *n){
    int i, j, k, aux;
    aux = *n;

    for(i = 0; i < *n; i++){
        for(j = i + 1; j < *n; j++){
            if(v[i] == v[j]){
                for(k = j; k < (*n) - 1; k++){
                    v[k] = v[k + 1];
                    (*n)--;
                }
            }
        }
    }

    if(aux == *n){
        return 0;
    } else {
        return aux - *n;
    }
}

int main(){
    int tamanho, i, analise;
    float *v;

    system("cls");

    do {
        printf("QUAL O TAMANHO DO VETOR:\n => ");
        scanf("%d", &tamanho);
    } while(tamanho <= 0);

    
    v = (float *)malloc(sizeof(float) * tamanho);

    if(v == NULL){
        printf("[ERRO] PROBLEMAS COM A MEMORIA.\n");
        exit(0);
    }

    for(i = 0; i < tamanho; i++){
        printf("DIGITE O VALOR DO VETOR[%d]: ", i);
        scanf("%f", &v[i]);
    }

    system("cls");

    printf("VETOR ORIGINAL\n");

    for(i = 0; i < tamanho; i++){
        printf("v[%d] = %.2f\n",i,  v[i]);
    }

    analise = filtro(v, &tamanho);

    printf("VETOR NOVO (%d ELEMENTOS REMOVIDOS)\n", analise);

    for(i = 0; i < tamanho; i++){
        printf("v[%d] = %.2f\n", i, v[i]);
    }

    free(v);
}