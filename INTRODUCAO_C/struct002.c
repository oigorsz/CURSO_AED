#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Aluno {
    char nome[70];
    int cod;
    int idade;
};

typedef struct Aluno *Aluno;

void adicionar(Aluno *lista, int i){
    system("cls");
    char string[70];
    int j,k;
    lista[i] = (Aluno)malloc(sizeof(Aluno));

    if(lista[i] == NULL){
        printf("ERRO.\n");
        exit(1);
    }

    getchar();

    printf("DIGITE O NOME DO ALUNO:\n=>");
    fgets(string, sizeof(string), stdin);


    string[strlen(string) - 1] = '\0';

    for(k = 0; k < strlen(string); k++){
        string[k] = toupper(string[k]);
    }

    strcpy(lista[i]->nome, string);

    system("cls");

    printf("DIGITE A IDADE DO ALUNO:\n => ");
    scanf("%d", &lista[i]->idade);

    lista[i]->cod = i;

    system("cls");

}


void imprimir(Aluno *lista, int i){
    system("cls");
    int j;
    for(j = 0; j < i; j++){
        printf("NOME: %s || IDADE: %d || COD-%d\n", lista[j]->nome, lista[j]->idade, lista[j]->cod);
    }
}

void encerrar(Aluno *lista, int i){
    system("cls");
    int j;
    for(j = 0; j < i; j++){
        free(lista[j]);
    }

    printf("PROGRAMA FINALIZADO.\n");
}

void voltar () {
    system("cls");
    printf("[ERRO] DIGITE UM COMADNO VALIDO.\n");
}


int main(){
    int choice, i = 0;
    Aluno lista[100];

    while (1)
    {
        printf("DIGITE 1 PARA REGISTRAR UM ALUNO.\n");
        printf("DIGITE 2 PARA IMPRIMIR A LISTA DE ALUNOS.\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice == 1){
            adicionar(lista, i);
            i++;
        } else if (choice == 2){
            imprimir(lista, i);
        } else if(choice == 0){
           encerrar(lista, i);
           return 0;
        } else {
            voltar();
            continue;
        }
    }
    
    return 0;
}