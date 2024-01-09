#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int info;
    struct Nodo *right;
    struct Nodo *left;
}Nodo;

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

Nodo* adicionar(Nodo* no, int valor){

    if(no == NULL){
        //CRIA A RAIZ DA ARVORE
        Nodo* novo;
        novo = createNodo(valor);
        return novo;
    } else if(valor == no->info){
        //VALOR JÁ EXISTENTE
        printf("[VALOR JÁ EXISTENTE].\n");
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
    Nodo* raiz = iniciarRaiz();
    int op = 1, num;

    system("cls");

    while (op != 0)
    {
        printf("DIGITE 1 PARA ADICIONAR.\n");
        printf("DIGITE 2 PARA IMPRIMIR.\n");
        printf("DIGITE 0 PARA ENCERRAR.\n");
        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 1:
            printf("DIGITE O NUMERO PARA ADICIONAR:\n => ");
            scanf("%d", &num);
            raiz = adicionar(raiz, num); //ATUALIZA TODA A ARVORE BINÁRIA SEM PERDER A REFERENCIA DA Raiz
            system("cls");
            break;
        case 2:
            printf("\nLISTA ORDENADA\n");
            imprimir(raiz);
            printf("\n");
            break;
        case 0:
            printf("PROGRAMA ENCERRADO.\n");
            liberar(raiz);
            break;
        
        default:
            printf("VALOR INVÁLIDO.\n");
            break;
        }
    }
    
    return 0;
}