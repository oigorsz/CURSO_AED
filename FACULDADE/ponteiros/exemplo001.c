#include <stdio.h>
#include <stdlib.h>


int main(){
    float vetor [] = {1.1, 2.1, 3.1, 4.1};
    float *f;
    int i;
    f = vetor;

    for(i = 0; i < 4; i++){
        printf("%d VET[%d] = %.2f ", i, i, vetor[i]);
        printf("*(f + %d) = %.2f ", i, *(f + i));
        printf("&vet[%d] = %x ", i, &vetor[i]);
        printf("(f + %d) = %x ", i, (f + i));
        printf("\n");
    }
}