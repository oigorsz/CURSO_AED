#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 150

struct aluno {
    char nome[MAX_SIZE];
    int idade;
    float peso;
    float altura;
    struct aluno * next;
};

typedef struct aluno aluno;

aluno *listaAlunos = NULL;

void limpar(aluno *listaAlunos){
    system("cls");

    printf("PROGRAMA ENCERRADO.\n");

    aluno *auxClean = listaAlunos;
    while (auxClean != NULL)
    {
        aluno * proximo = auxClean->next;
        free(auxClean);
        auxClean = proximo;
    }
    
}

void adicionar(char string[], int idade, float altura, float peso){
    aluno *p = (aluno*)malloc(sizeof(aluno));
    strcpy(p->nome, string);
    p->idade = idade;
    p->altura = altura;
    p->peso = peso;
    p->next = NULL;

    if(listaAlunos == NULL){
        listaAlunos = p;
    } else {
        aluno *auxAdd = listaAlunos;
        while (auxAdd->next != NULL)
        {
            auxAdd = auxAdd->next;
        }

        auxAdd->next = p;
    }
}

void remover(){
    if(listaAlunos == NULL){
        system("cls");
        printf("LISTA DE ALUNOS VAZIA.\n");
    } else {
        system("cls");
        listaAlunos = listaAlunos->next;
    }
}

void imprimir(aluno *listaAlunos){
    system("cls");

    printf("LISTA DE ALUNOS:\n");

    aluno *auxPrint = listaAlunos;
    while(auxPrint != NULL){
        printf("NOME: %s || IDADE: %d || MASSA: %.2fKg || ALTURA: %.2fm\n",
        auxPrint->nome, auxPrint->idade, auxPrint->peso, auxPrint->altura);
        auxPrint = auxPrint->next;
    }

}

int main(){
    int choice, idade;
    float peso, altura;
    char string[MAX_SIZE];

    system("cls");

    while(1)
    {
        printf("DIGITE 1 PARA REGISTRAR UM NOVO ALUNO.\n");
        printf("DIGITE 2 PARA REMOVER O ALUNO ADICIONADO.\n");
        printf("DIGITE 3 PARA IMPRIMIR A LISTA DE ALUNOS.\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice != 0 && choice != 1 && choice != 2 && choice != 3){
            system("cls");
            printf("VALOR INVALIDO.\n");
        } else {
            if(choice == 0){
                limpar(listaAlunos);
                break;
            }

            if(choice == 1){
                system("cls");
                getchar();

                printf("DIGITE O NOME DO ALUNO:\n => ");
                fgets(string, MAX_SIZE, stdin);
                string[strlen(string) - 1] = '\0';
                for(int i = 0; i < strlen(string); i++){
                    string[i] = toupper(string[i]);
                }

                printf("DIGITE A IDADE DO ALUNO:\n => ");
                scanf("%d", &idade);

                printf("DIGITE O ALTURA, EM METROS, DO ALUNO:\n => ");
                scanf("%f", &altura);

                printf("DIGITE O PESO, EM Kg, DO ALUNO:\n => ");
                scanf("%f", &peso);

                adicionar(string, idade,altura, peso);

                getchar();

                system("cls");

            }

            if(choice == 2){
                remover();
            }

            if(choice == 3){
                imprimir(listaAlunos);
            }
        }
    }
    return 0;
}