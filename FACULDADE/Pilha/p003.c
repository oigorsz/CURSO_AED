#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_LIVRO 25

struct Livro {
    char nome[TAM_LIVRO];
    int codigo;
    struct Livro * next;
};

typedef struct Livro Livro;

void formatar(char string[]){
    int i;
    string[strlen(string) - 1] = '\0';
    for(i = 0; i < strlen(string); i++){
        string[i] = toupper(string[i]);
    }
    
}



Livro *push (Livro *p, int *codigo){
    Livro *novo = (Livro *)malloc(sizeof(Livro));
    char string [TAM_LIVRO];
    if(novo == NULL){
        printf("[ERRO DE MEMORIA].\n");
        exit(1);
    }

    system("cls");

    getchar();
    printf("DIGITE O NOME DO LIVRO:\n => ");
    fgets(string, sizeof(string), stdin);
    formatar(string);

    strcpy(novo->nome, string);
    novo->codigo = *codigo;
    novo->next = p;
    (*codigo)++;

    return novo;
}

Livro *pop(Livro *p, int *codigo){
    Livro *aux = p;

    system("cls");

    if(p == NULL){
        system("cls");
        printf("PILHA VAZIA.\n");
        exit(1);
    }

    (*codigo)--;
    p = p->next;
    free(aux);
    
    return p;
}

void exibir(Livro *p){
    Livro * aux;

    system("cls");

    for(aux = p; aux != NULL; aux = aux->next){
        printf("COD: %d || NOME: %s\n", aux->codigo, aux->nome);
    }

    printf("\n\n");
}

void encerrar(Livro *p){
    Livro *aux;

    system("cls");

    while (p != NULL)
    {
        aux = p;
        free(aux);
        p = p->next;
    }

    printf("PROGRAMA ENCERRADO.\n");
}



int main(){
    int choice, codigo = 1;
    Livro *pilha = NULL;

    system("cls");

    while(1){
        do {
            printf("DIGITE 1 PARA ADICIONAR UM LIVRO.\n");
            printf("DIGITE 2 PARA REMOVER UM LIVRO.\n");
            printf("DIGITE 3 PARA EXIBIR A PILHA DE LIVROS.\n");
            printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
            scanf("%d", &choice);
        } while (!(choice == 1 || choice == 2 || choice == 3 || choice == 0));

        switch (choice)
        {
        case 1:
            pilha = push(pilha, &codigo);
            break;
        case 2:
            pilha = pop(pilha, &codigo);
            break;
        case 3:
            exibir(pilha);
            break;
        case 0:
            encerrar(pilha);
            return 1;
            break;
        
        default:
            break;
        }
        
    }
    return 0;
}