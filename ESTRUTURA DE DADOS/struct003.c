#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 100


struct dados {
    char nome[TAM];
    float p1;
    float p2;
    float media;
};

typedef struct dados dados;

int main(void) {
    int registro = -1;

    system("cls");

    while (registro < 0 || registro > 100){
        printf("QUANTOS REGISTROS QUE SERAO FEITOS:\n => ");
        scanf("%d", &registro);
        getchar();
    }

    system("cls");

    dados aluno[registro];

    for(int i = 0; i < registro; i++){
        printf("DIGITE O NOME DO ALUNO %d:\n => ", i + 1);
        fgets(aluno[i].nome, TAM, stdin);
        aluno[i].nome[strlen(aluno[i].nome) - 1] = '\0';
        for(int j = 0; j < strlen(aluno[i].nome); j++){
            aluno[i].nome[j] = toupper(aluno[i].nome[j]);
        }

        aluno[i].p1 = -1;
        aluno[i].p2 = -1;

        while (aluno[i].p1 < 0 || aluno[i].p1 > 10){
            printf("NOTA PROVA 1(ALUNO %d):\n => ", i +1);
            scanf("%f", &aluno[i].p1);
            getchar();
        }

        while (aluno[i].p2 < 0 || aluno[i].p2 > 10){
            printf("NOTA PROVA 2(ALUNO %d):\n => ", i + 1);
            scanf("%f", &aluno[i].p2);
            getchar();
        }

        aluno[i].media = (aluno[i].p1 + aluno[i].p2)/2;

        system("cls");
    }

    for(int i = 0; i < registro; i++){
        printf("ALUNO %d\nNOME: %s\nMEDIA: %.2f\n", i + 1, aluno[i].nome, aluno[i].media);
        if(aluno[i].media >= 7){
            printf("APROVADO.\n\n");
        }
        if(aluno[i].media >= 4.5 && aluno[i].media < 7){
            printf("EXAME.\n\n");
        }
        if(aluno[i].media < 4.5){
            printf("REPROVADO.\n\n");
        }
    }
}