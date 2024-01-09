#include <stdio.h>
#include <stdlib.h>

void insert(float *v, int *t, int valor, int pos){
    int newT = *t + 1, i, j;
    float *newV;

    newV = (float *)realloc(v, sizeof(float) * (newT));

    if(newV == NULL){
        printf("[ERRO]");
        exit(1);
    }

    v = newV;
    *t = newT;

    for(i = 0; i < *t ; i++){
        if(i == pos){
            for(j = i; j < *t; j++){
                v[j + 1] = v[j];
            }
            
            v[pos] = valor;
             
        } 
    }


}

int main(){
    int tamanho, i, pos;
    float *vetor, valor;

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

    printf("\nDIGITE O NOVO VALOR QUE DESEJA INSERIR:\n => ");
    scanf("%f", &valor);

    do {
        printf("DIGITE A POSICAO QUE ELE IRA OCUPAR:\n => ");
        scanf("%d", &pos);
    } while(!(0 <= pos && pos <= tamanho));

    insert(vetor, &tamanho, valor, pos);

    for(i = 0; i < tamanho; i++){
        printf("VETOR[%d] = %.2f\n", i, vetor[i]);
    }

    free(vetor);
    

    return 0;
}