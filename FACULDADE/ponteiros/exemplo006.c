#include <stdio.h>
#include <stdlib.h>

int merge (float *v1, float *v2, float *v3, int tam1, int tam2){
    int i, size = 0;

    for(i = 0; i < tam1; i++){
        v3[size] = v1[i]; 
        size++;
    }

    for(i = 0; i < tam2; i++){
        v3[size] = v2[i]; 
        size++;
    }

    size = remove_dup(v3, size);

    ordenar(v3, size);


    return size;
}

int remove_dup (float *v, int size){
    int i, j, k;

    for(i = 0; i < size; i++){
        for(j = i + 1; j < size; j++){
            if(v[i] == v[j]){
                for(k = j; k < (size) - 1; k++){
                    v[k] = v[k + 1];
                    (size)--;
                }
            }
        }
    }

    return size;
    
}

void ordenar(float *v, int tam){
    int i, j, temp;

    for(i = 0; i < tam - 1; i++){
        for(j = 0; j < tam - i - 1; j++){
            if(v[j] > v[j + 1]){
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}


int main(){
    int tam1, tam2, tam3, i;
    float *v1, *v2, *v3;

    system("cls");

    do {
        printf("DIGITE O TAMANHO DO VETOR 1:\n => ");
        scanf("%d", &tam1);
        printf("DIGITE O TAMANHO DO VETOR 2:\n => ");
        scanf("%d", &tam2);
    } while( !(0 < tam1 && 0 < tam2));

    v1 = (float *)malloc(tam1 * sizeof(float));
    v2 = (float *)malloc(tam2 * sizeof(float));
    v3 = (float *)malloc((tam1 + tam2) * sizeof(float));

    if(v1 == NULL || v2 == NULL || v3 == NULL){
        printf("[ERRO]");
        exit(1);
    }

    system("cls");


    for(i = 0; i < tam1; i++){
        printf("DIGITE O VALOR DE VETOR1[%d]\n", i);
        scanf("%f", &v1[i]);
    }

    system("cls");

    for(i = 0; i < tam1; i++){
        printf("DIGITE O VALOR DE VETOR2[%d]: ", i);
        scanf("%f", &v2[i]);
    }

    system("cls");


    tam3 = merge(v1, v2, v3, tam1, tam2);

    v3 = (float *)realloc(v3, sizeof(float) * tam3);

    if(v3 == NULL){
        printf("[ERRO]");
        exit(1);
    }


    printf("TAMANHO DO VETOR: %d", tam3);
    printf("VETOR FINAL:\n");

    for(i = 0; i < tam3; i++){
        printf("VETOR[%d] = %.2f\n", i, v3[i]);
    }


    free(v1);
    free(v2);
    free(v3);


    return 0;
}