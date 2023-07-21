#include <stdio.h>
#include <stdlib.h>

#define TAM 3


int main(void){
    double notas[TAM], soma = 0, media;

    system("cls");

    for(int i = 0; i < TAM; i++){
        printf("DIGITE A NOTA DA PROVA %d:\n=> ", i + 1);
        scanf("%lf", &notas[i]);
        soma += notas[i];

        if(notas[i] < 0 || notas[i] > 10 ){
            system("cls");
            printf("DIGITE UM VALOR VALIDO.\n");
            i--;
            soma -= notas[i];
        }
    }

    system("cls");

    printf("NOTAS\n");
    for(int i = 0; i < TAM; i++){
        printf("PROVA %d: %.2lf.\n", i + 1, notas[i]);
    }

    media = soma/TAM;

    printf("MEDIA: %.2lf.\n", media);

    return 0;
}