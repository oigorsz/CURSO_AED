#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 100

struct Pessoa {
    char nome[TAM];
    int idade;
    float peso;
    struct Pessoa * next;
};

typedef struct Pessoa Pessoa;

Pessoa *listaPessoa = NULL;

void adicionar(char string[], int idade, float peso){
    Pessoa * p = (Pessoa*)malloc(sizeof(Pessoa));
    strcpy(p->nome, string);
    p->idade = idade;
    p->peso = peso;
    p->next = NULL;

    if(listaPessoa == NULL){
        listaPessoa = p;
    } else {
        Pessoa * aux1 = listaPessoa;
        while (aux1->next != NULL)
        {
            aux1 = aux1->next;
        }
        
        aux1->next = p;
    }
}

int length = 0;

void addIndex(char string[], int idade, float peso, int index){
    length++;
    Pessoa * p = (Pessoa *)malloc(sizeof(Pessoa));
    strcpy(p->nome, string);
    p->idade = idade;
    p->peso = peso;
    
    if(index > length){
        printf("POSICAO INVÁLIDA\n");
    } else {
        if(index == 0 || index < 0){
            p->next = listaPessoa;
            listaPessoa = p;
        } else {
            Pessoa * aux = listaPessoa;
            for(int i = 0; i != index - 1; i++){
                aux = aux->next;
            }
            p->next = aux->next;
            aux->next = p;
        }
    }
}


void imprimir(Pessoa * listaPessoa){
    if(listaPessoa != NULL){
        printf("NOME: %s || IDADE: %d || PESO(kg): %.2f\n", listaPessoa->nome, listaPessoa->idade, listaPessoa->peso);
        imprimir(listaPessoa->next);
    }
}

void limpar(Pessoa * listaPessoa){
    Pessoa * aux2 = listaPessoa;
    while (aux2 != NULL)
    {
        Pessoa * proximo = aux2->next;
        free(aux2);
        aux2 = proximo;
    }
    
}

int main(){
    int choice, idade, index;
    char string[TAM];
    float peso;

    system("cls");

    while(1){
        printf("SISTEMA DE REGISTROS\n\n");
        printf("DIGITE 1 PARA REGISTRAR UM NOVO ALUNO.\n");
        printf("DIGITE 2 PARA MOSTRAR A LISTA DE ALUNOS.\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice == 0){
            system("cls");
            printf("PROGRAMA ENCERRADO.\n");
            limpar(listaPessoa);
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

            printf("DIGITE O PESO DO ALUNO(Kg):\n => ");
            scanf("%f", &peso);

            printf("DIGITE A POSICAO:\n =>");
            scanf("%d", &index);

            addIndex(string, idade, peso, index);

            getchar();

            system("cls");
        }

        if(choice == 2){
            system("cls");
            printf("LISTA DE ALUNOS:\n");
            imprimir(listaPessoa);
        }

        if(choice != 0 && choice != 1 && choice != 2){
            system("cls");
            printf("[ERRO] VALOR INVALIDO.\n");
        }
    }

    return 0;
}