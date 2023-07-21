#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 100

struct pessoa {
    char nome[TAM];
    int idade;
};

typedef struct pessoa pessoa;

int main(void){
    int registro = -1;

    system("cls");

    while(registro < 0 || registro > 100){
        printf("QUANTOS USUARIOS SERAO CADASTRADOS:\n => ");
        scanf("%d", &registro);
        getchar();
    }

    system("cls");

    pessoa aluno[registro];

    for(int i = 0; i < registro; i++){
        printf("DIGITE O NOME DA PESSOA %d:\n => ", i + 1);
        fgets(aluno[i].nome, TAM, stdin);
        aluno[i].nome[strlen(aluno[i].nome) - 1] = '\0';
        for(int j = 0; j < strlen(aluno[i].nome); j++){
            aluno[i].nome[j] = toupper(aluno[i].nome[j]); 
        }

        aluno[i].idade = -1;

        while(aluno[i].idade < 0 || aluno[i].idade > 100){
            printf("DIGITE A IDADE DA PESSOA %d:\n => ", i+ 1);
            scanf("%d", &aluno[i].idade);
            getchar();
        }
        
        system("cls");
    }

    for(int i = 0; i < registro; i++){
        printf("ALUNO %d - NOME: %s - IDADE: %d\n", i + 1, aluno[i].nome, aluno[i].idade);
    }

    return 0;
}