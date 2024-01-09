#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int info;
    struct Nodo *right;
    struct Nodo *left;
}Nodo;

typedef struct ArvB {
    Nodo *raiz;
}ArvB;

Nodo* criarNo(int v){
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        return 0;
    }

    novo->info = v;
    novo->left = NULL;
    novo->right = NULL;

    return novo;
}

void setLeft(Nodo *no, int v);
void setRight(Nodo *no, int v);

void setLeft(Nodo *no, int v){
    Nodo* novo;
    if(no->left == NULL){
        novo = criarNo(v);
        no->left = novo;
    } else {
        if(v < no->left->info){
            setLeft(no->left, v);
        } else {
            setRight(no->right, v);
        }
    }
}

void setRight(Nodo *no, int v){
    Nodo* novo;

    if(no->right == NULL){
        novo = criarNo(v);
        no->right = novo;
    } else {
       if(v > no->right->info){
            setRight(no->right, v);
       } else {
            setLeft(no->left, v);
       }
    }
}

void inserir(ArvB *arv, int v){
    if(arv->raiz == NULL){
        //CRIA O PRIMEIRO NODO
        arv->raiz = criarNo(v);
    } else{
        if(v < arv->raiz->info){
            setLeft(arv->raiz, v);
        } else {
            setRight(arv->raiz, v);
        }
    }
}

void imprimir(Nodo* raiz){
    if(raiz == NULL){
        return;
    }

    imprimir(raiz->left);
    printf("%d ", raiz->info);
    imprimir(raiz->right);
}

void liberar(Nodo *raiz){
    if(raiz == NULL){
        return;
    }

    liberar(raiz->left);
    liberar(raiz->right);

    free(raiz);
}



int main(){
    int num, choice = 1;
    ArvB arv;

    arv.raiz = NULL;

    system("cls");

    while (choice == 1)
    {
        printf("DIGITE 1 PARA ADICIONAR UM NO.\n");
        printf("DIGITE 2 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            printf("DIGITE O NUMERO QUE DESEJA ADICIONAR:\n=>");
            scanf("%d", &num);
            inserir(arv.raiz, num);
            break;
        case 2:
            imprimir(arv.raiz);
            liberar(arv.raiz);
            printf("PROGRAMA ENCERRADO.\n");
            break;
        
        default:
            printf("DIGITE UM VALOR VÁLIDO.\n\n");
            break;
        }
    }


    return 0;
}