#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 100

struct dados {
    char nome[TAM];
    float nota1, nota2, nota3, media;
};

typedef struct dados dados;

int main(void){
    system("cls");

    int registros = -1;

    while(registros < 0 || registros > 100){
        printf("DIGITE O NUMERO DE REGISTROS:\n => ");
        scanf("%d", &registros);
        getchar();
    }

    dados aluno[registros];

    for(int i = 0; i < registros; i++){
        printf("DIGITE O NOME DO ALUNO %d:\n => ", i + 1);
        fgets(aluno[i].nome, TAM, stdin);
        aluno[i].nome[strlen(aluno[i].nome) - 1] = '\0';
        for(int j = 0; j < strlen(aluno[i].nome); j++){
            aluno[i].nome[j] = toupper(aluno[i].nome[j]);
        }

        aluno[i].nota1 = -1;
        aluno[i].nota2 = -1;
        aluno[i].nota3 = -1;

        while(aluno[i].nota1 < 0 || aluno[i].nota1 > 10){
            printf("DIGITE A NOTA 1 DO ALUNO %d:\n=> ", i + 1);
            scanf("%f", &aluno[i].nota1);
        }

        while(aluno[i].nota2 < 0 || aluno[i].nota2 > 10){
            printf("DIGITE A NOTA 2 DO ALUNO %d:\n=> ", i + 1);
            scanf("%f", &aluno[i].nota2);
        }

        while(aluno[i].nota3 < 0 || aluno[i].nota3 > 10){
            printf("DIGITE A NOTA 3 DO ALUNO %d:\n=> ", i + 1);
            scanf("%f", &aluno[i].nota3);
            getchar();
        }

        system("cls");

        aluno[i].media = (aluno[i].nota1*2 + aluno[i].nota2*3 + aluno[i].nota3*4)/9;
    }


    for(int i = 0; i < registros; i++){
        printf("ALUNO %d\nNOME: %s\nMEDIA: %.2f\n\n", i + 1, aluno[i].nome, aluno[i].media);
    }



    return 0;
}