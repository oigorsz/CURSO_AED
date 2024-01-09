#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Aluno {
    char nome[100];
    int codigo;
    char sexo;
    int idade;
};

typedef struct Aluno Aluno;

struct Nodo {
    Aluno aluno;
    struct Nodo *next;
};

typedef struct Nodo Nodo;

Nodo *adicionar(Aluno *listaAlunos){
    char string[100];
    int i;
    Nodo *novoALuno = (Nodo*)malloc(sizeof(Nodo));

    system("cls");

    getchar();

    if(novoALuno == NULL){
        system("cls");
        printf("[ERRO] FALHA NO ARMAZENAMENTO");
        exit(1);
    }

    printf("DIGITE O NOME DO ALUNO:\n => ");
    fgets(string, sizeof(string), stdin);
    string[strlen(string) - 1] = '\0';

    for(i = 0; i < strlen(string); i++){
        string[i] = toupper(string[i]);
    }

    strcpy(novoALuno->aluno.nome, string);

    printf("DIGITE A IDADE DO ALUNO:\n => ");
    scanf("%d", &novoALuno->aluno.idade);

    printf("DIGITE O CODIGO DO ALUNO:\n => ");
    scanf("%d", &novoALuno->aluno.codigo);


    novoALuno->next = listaAlunos;

    system("cls");

    printf("ALUNO ADICIONADO COM SUCESSO.\n");

    return novoALuno;
}

int main(){
    int choice;
    Nodo *listaAlunos = NULL;

    while (1)
    {
        printf("SISTEMA DE ALUNOS.\n");
        printf("DIGITE 1 PARA ADICIONAR UM ALUNO.\n");
        printf("DIGITE 2 PARA IMPRIMIR A LISTA DE ALUNOS.\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice == 0){
            //ENCERRAR
        } else if (choice == 1){
            adicionar(listaAlunos);
        } else if (choice == 2){
            //IMPRIMIR
        } else {
            //ERRO
        }


    }
    
}