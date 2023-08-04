#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 150

struct Pessoa {
    char nome [TAM];
    int idade;
    struct Pessoa * next;
};

typedef struct Pessoa Pessoa;

Pessoa * listaPessoas;

void adicionar(char string[], int idade){
    Pessoa *p = (Pessoa*)malloc(sizeof(Pessoa));
    strcpy(p->nome, string);
    p->idade = idade;
    p->next = listaPessoas;
    listaPessoas = p;
}


void imprimir(char string[], int idade){
    system("cls");
    Pessoa *auxiliar = listaPessoas;
    printf("LISTA DE PESSOAS.\n");
    while(auxiliar != NULL){
        printf("%s || %d\n", auxiliar->nome, auxiliar->idade);
        auxiliar = auxiliar->next;
    }

    printf("\n\n");
}


void limpar(){
    Pessoa * auxiliar2 = listaPessoas;
    while(auxiliar2 != NULL){
        Pessoa * proximo = auxiliar2->next;
        free(auxiliar2);
        auxiliar2 = proximo;
    }
}


int main(){
    int choice, idade;
    char string[TAM];

    system("cls");

    while(1){
        printf("DIGITE 1 PARA FAZER UM REGISTRO.\n");
        printf("DIGITE 2 PARA IMPRIMIR A LISTA DE REGISTROS.\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice == 0){
            printf("PROGRAMA ENCERRADO.\n");
            limpar(listaPessoas);
            break;
        } 

        if(choice == 1){
            getchar();
            system("cls");
            printf("DIGITE O NOME DO USUARIO:\n=> ");
            fgets(string, TAM, stdin);
            string[strlen(string) - 1] = '\0';
            

            for(int i = 0; i < strlen(string); i++){
                string[i] = toupper(string[i]);
            }

            printf("DIGITE A IDADE D USUARIO:\n => ");
            scanf("%d", &idade);

            adicionar(string, idade);
            system("cls");
        }

        if(choice == 2){
            imprimir(string, idade);
        }

        
        if(choice != 0 && choice != 1 && choice != 2){
            printf("VALOR INVÁLIDO.\n");
        }
    }

    return 0;
}