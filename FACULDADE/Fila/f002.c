#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM_MAX 50

typedef struct Nodo {
    int info;
    char nome[TAM_MAX];
    struct Nodo *next;
}TNodo;

typedef TNodo *PNodo;

typedef struct Fila {
    PNodo ini;
    PNodo fim;
} TFila;

typedef TFila *PFila;

PFila iniciar(){
    PFila fila = (PFila)malloc(sizeof(TFila));

    if(fila == NULL){
        printf("[ERRO DE ALOCAÇÃO]");
        exit(1);
    }

    fila->ini = fila->fim = NULL;
    return fila;
}

PFila adicionar(PFila fila, int valor, char nome[]){
    PNodo novo = (PNodo)malloc(sizeof(TNodo));

    if(novo == NULL){
        system("cls");
        printf("[ERRO DE ALOCAÇÃO]");
        exit(1);
    }

    novo->info = valor;
    strcpy(novo->nome, nome);
    novo->next = NULL;

    if(fila->ini == NULL){
        fila->ini = fila->fim = novo;
    } else {
        fila->fim->next = novo;
        fila->fim = novo;
    }

    return fila;
}

int remover(PFila fila, int valor){
    PNodo aux;

    if(fila->ini == NULL){
        return -1;
    }

    valor = fila->ini->info;
    aux = fila->ini;
    fila->ini = aux->next;
    free(aux);

    if(fila->ini == NULL){
        fila->fim = NULL;
    }

    return valor;
}

void imprimir(PFila fila){

    if(fila == NULL || fila->ini == NULL){
        printf("FILA VAZIA.\n");
        return;
    }
    
    PNodo aux;


    for(aux = fila->ini; aux != NULL; aux = aux->next){
        printf("SENHA: %d, NOME: %s\n", aux->info, aux->nome);
    }

    printf("\n");
}

void liberar(PFila fila){
    PNodo aux;

    for(aux = fila->ini; aux != NULL;){
        fila->ini = fila->ini->next;
        free(aux);
    }

    free(fila);
}

void formatar(char string[]){
    int i, tamanho;
    tamanho = strlen(string);
    string[tamanho - 1] = '\0';


    for(i = 0; i < tamanho; i++){
        string[i] = toupper(string[i]);
    }
}

void registrar(PFila fila, int *senha){
    char nome[TAM_MAX];
    system("cls");

    getchar();
    printf("DIGITE O NOME DA PESSOA:\n => ");
    fgets(nome, sizeof(nome), stdin);
    formatar(nome);

    fila = adicionar(fila, *senha, nome);
    (*senha)++;
    system("cls");
    printf("NOVA SENHA ADICIONADA.\n");
}

void excluir(PFila fila){
    int removido;
    system("cls");

    removido = remover(fila, removido);

    if(removido == -1){
        printf("FILA VAZIA.\n");
        return;
    } else {
        printf("SENHA SOLICITADA: %d.\n", removido);
    }
}

void encerrar(PFila fila){
    system("cls");

    liberar(fila);

    printf("PROGRAMA ENCERRADO.\n");
}


int main(){
    int choice, i = 1;
    PFila fila = iniciar();

    system("cls");

    while (1)
    {
        printf("FILA DE CAIXA.\n");
        imprimir(fila);
        printf("DIGITE 1 PARA ADICIONAR ALGUEM A LISTA.\n");
        printf("DIGITE 2 PARA REMOVER ALGUEM DA LISTA.\n");
        printf("DIGITE 0 PARA ENCERRAR A FILA.\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            registrar(fila, &i);
            break;
        case 2:
            excluir(fila);
            break;
        case 0:
            encerrar(fila);
            return 0;
            break;
        
        default:
            system("cls");
            printf("[VALOR INVALIDO]");
            break;
        }
    }
    
}


