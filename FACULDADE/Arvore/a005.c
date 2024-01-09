#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int info;
    struct Nodo *right;
    struct Nodo *left;
}Nodo;

typedef struct ArvB {
    Nodo *raiz;
    int tam;
}ArvB;

Nodo* iniciarRaiz(){
    return NULL;
}

Nodo* createNodo(int valor){
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->info = valor;
    novo->left = NULL;
    novo->right = NULL;

    return novo;
}

int contarNodos(Nodo* raiz){
    if(raiz == NULL)
        return 0;
    else 
        return 1 + contarNodos(raiz->left) + contarNodos(raiz->right);
}

int buscar(Nodo* raiz, int chave){
    if(raiz == NULL){
        return -1;
    } else {
        if(chave == raiz->info){
            return raiz->info;
        } else {
            if(chave < raiz->info)
                return buscar(raiz->left, chave);
            else 
                return buscar(raiz->right, chave);
        }
    }
}

Nodo* adicionar(Nodo *no, int valor){
    if(no == NULL){
        return createNodo(valor);
    } else if(valor == no->info){
        printf("VALOR JÁ EXISTENTE.\n");
        return no;
    } else if(valor < no->info){
        no->left = adicionar(no->left, valor);
    } else {
        no->right = adicionar(no->right, valor);
    }

    return no;
}

void imprimir(Nodo *no){
    if(no == NULL){
        return;
    }

    imprimir(no->left);
    printf("%d ", no->info);
    imprimir(no->right);
}

void liberar(Nodo* no){
    if(no == NULL){
        return;
    }

    liberar(no->left);
    liberar(no->right);
    free(no);
}

int main(){
    ArvB arv;
    arv.raiz = iniciarRaiz();
    arv.tam;
    int op = 1, num;

    system("cls");

    while (op != 0)
    {
        printf("DIGITE 1 PARA ADICIONAR.\n");
        printf("DIGITE 2 PARA IMPRIMIR.\n");
        printf("DIGITE 3 PARA BUSCAR UM ELEMENTO.\n");
        printf("DIGITE 0 PARA ENCERRAR.\n");
        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 1:
            do {
                printf("DIGITE UM INTEIRO POSITIVO PARA ADICIONAR:\n => ");
                scanf("%d", &num);
            } while (num < 0);
        
            arv.raiz = adicionar(arv.raiz, num); //ATUALIZA TODA A ARVORE BINÁRIA SEM PERDER A REFERENCIA DA Raiz
            system("cls");
            break;
        case 2:
            printf("\nLISTA ORDENADA\n");
            imprimir(arv.raiz);
            arv.tam = contarNodos(arv.raiz);
            printf("\nNUMERO DE NODOS: %d", arv.tam);
            printf("\n");
            break;
        case 3:
            do {
                printf("DIGITE O NUMERO DE BUSCA:\n => ");
                scanf("%d", &num);
            } while (num < 0);
            system("cls");

            printf("\n%d\n", buscar(arv.raiz, num));
            break;
        case 0:
            printf("PROGRAMA ENCERRADO.\n");
            liberar(arv.raiz);
            break;
        
        default:
            printf("VALOR INVÁLIDO.\n");
            break;
        }
    }
    
    return 0;
}