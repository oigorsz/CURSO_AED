#include <stdio.h>
#include <stdlib.h>

int removeDup(float *v3, int n){
    int i, j, k, aux;
    aux = n;

    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(v3[i] == v3[j]){
                for(k = j; k < n - 1; k++){
                    v3[k] = v3[k + 1];
                }
                n--;
            }
        }
    }

    if(aux == n){
        return 0;
    } else {
        return aux - n;
    }
}

int merge(float *v1, float *v2, float *v3, int tam1, int tam2){
    int i, tamF, tam3 = tam1 + tam2;

    for(i = 0; i < tam1; i++){
        v3[i] = v1[i];
    }

    for(i = 0; i < tam2; i++){
        v3[tam1 + i] = v2[i];
    }

    tamF = removeDup(v3, tam3);

    return tamF;
}



int main(){
    int tam1, tam2, tam3, i;
    float *v1, *v2, *v3;

    system("cls");

    do {
        printf("DIGITE O TAMANHO DO VETOR 1:\n => ");
        scanf("%d", &tam1);
    } while(!(0 < tam1));

    do {
        printf("DIGITE O TAMANHO DO VETOR 2:\n => ");
        scanf("%d", &tam2);
    } while(!(0 < tam2));

    system("cls");

    v1 = (float *)malloc(sizeof(float) * tam1);
    v2 = (float *)malloc(sizeof(float) * tam2);
    v3 = (float *)malloc(sizeof(float) *(tam1 + tam2));

    if(v1 == NULL || v2 == NULL){
        printf("[ERRO]");
        exit(1);
    }

    for(i = 0; i < tam1; i++){
        printf("DIGITE O VALOR DE VETOR1[%d] \n=> ", i);
        scanf("%f", &v1[i]);
    }

    system("cls");

    for(i = 0; i < tam2; i++){
        printf("DIGITE O VALOR DE VETOR2[%d] \n=> ", i);
        scanf("%f", &v2[i]);
    }

    system("cls");


    tam3 = merge(v1, v2, v3, tam1, tam2);

    printf("O TAMANHO DO VETOR3 = %d\n", tam3);



    free(v1);
    free(v2);
    free(v3);


    return 0;
}