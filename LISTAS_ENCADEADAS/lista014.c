#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 100

struct Pessoa {
    char nome[TAM];
    int idade;
    struct Pessoa * next;
};

typedef struct Pessoa Pessoa;

Pessoa *listaPessoas;

void adicionar(char string[], int idade){
    Pessoa *p = (Pessoa*)malloc(sizeof(Pessoa));
    strcpy(p->nome, string);
    p->idade = idade;
    p->next = listaPessoas;
    listaPessoas = p;
}

void imprimir(Pessoa *listaPessoas){
    if (listaPessoas != NULL){
        printf("%s || %d\n", listaPessoas->nome, listaPessoas->idade);
        imprimir(listaPessoas->next);
    }
}

void limpar(Pessoa * listaPessoas){
    Pessoa * aux2 = listaPessoas;
    while (aux2 != NULL)
    {
        Pessoa * proximo = aux2->next;
        free(aux2);
        aux2 = proximo;
    }
    
}

int main(){
    int choice;
    char string[TAM];
    int idade;

    system("cls");

    while(1){
        printf("DIGITE 1 PARA REGISTRAR UM ALUNO.\n");
        printf("DIGITE 2 PARA IMPRIMIR A LISTA DE ALUNOS.\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice == 0){
            system("cls");
            printf("PROGRAMA ENCERRADO.\n");
            limpar(listaPessoas);
            break;
        }

        if(choice == 1){
            system("cls");

            getchar();

            printf("DIGITE O NOME DO ALUNO:\n => ");
            fgets(string, TAM, stdin);
            string[strlen(string) - 1] = '\0';
            
            for(int i = 0; i < strlen(string); i++){
                string[i] = toupper(string[i]);
            }

            printf("DIGITE A IDADE DO ALUNO:\n => ");
            scanf("%d", &idade);

            adicionar(string, idade);

            getchar();
            system("cls");
        }

        if(choice == 2){
            system("cls");
            printf("LISTA ALUNOS\n");
            imprimir(listaPessoas);
        }

        if(choice != 0 && choice != 1 && choice != 2){
            printf("[ERRO] VALOR INVALIDO.\n");
        }
    }
    return 0;
}