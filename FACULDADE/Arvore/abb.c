//EXEMPLO DE ARVORE BINÁRIA DE BUSCA
#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo {
    int info;
    struct Nodo* dir;
    struct Nodo* esq;
}TNodo;

TNodo* start(){
    return NULL;
}

TNodo*  criarNodo(int val){
    TNodo *novo;
    novo = (TNodo *)malloc(sizeof(TNodo));

    novo->info = val;
    novo->dir = NULL;
    novo->esq = NULL;

    return novo;
}

TNodo *livre(TNodo *raiz, int chave){
    if(raiz == NULL)
        return NULL;
    
    if(raiz->info == chave)
        return raiz;

    if(chave < raiz->info)
        raiz->esq = livre(raiz->esq, chave);
    else
        raiz->dir = livre(raiz->dir, chave);
}


TNodo* adicionar(TNodo *raiz, int val){

    if(raiz == NULL) {
        raiz = criarNodo(val);
        return raiz;
    }

    if(val < raiz->info)
        raiz->esq = adicionar(raiz->esq, val);
    else if(val > raiz->info)
        raiz->dir = adicionar(raiz->dir, val);
    return raiz;
}

TNodo *remover(TNodo *raiz, int valor){
    TNodo *pai, *filho;

    if(raiz == NULL)
        return NULL;
    
    if(raiz->info == valor){
        // NO FOLHA (NÃO POSSUI FILHOS)
        if(raiz->dir == NULL && raiz->esq == NULL){
            free(raiz);
            return NULL;
        }

        // NO POSSUI UM ÚNICO FILHO À ESQUERDA
        if(raiz->dir == NULL){
            filho = raiz->esq;
            free(raiz);
            return filho;
        } 

        // NO POSSUI UM ÚNICO FILHO À DIREITA
        if(raiz->esq == NULL){
            filho = raiz->dir;
            free(raiz);
            return filho;
        }

        // POSSUI DOIS FILHOS, ENTÃO BUSCAR O FILHO MAIS À DIREITA DO LADO ESQUERDO
        for(pai = raiz, filho = raiz->esq; filho->dir != NULL; pai = filho, filho = filho->dir);
        raiz->info = filho->info;

        if(pai == raiz)
            pai->esq = remover(pai->esq, filho->info);
        else 
            pai->dir = remover(pai->dir, filho->info);

        free(filho);
        return raiz;

    } else if(valor < raiz->info)
        raiz->esq = remover(raiz->esq, valor);
    else 
        raiz->dir = remover(raiz->dir, valor);

    return raiz;
    
}


int somar(TNodo *raiz){
    if(raiz == NULL)
        return 0;

    return raiz->info + somar(raiz->esq) + somar(raiz->dir);
}

void imprimirOrdem(TNodo *raiz){
    if(raiz == NULL)
        return;

    imprimirOrdem(raiz->esq);
    printf("%d ", raiz->info);
    imprimirOrdem(raiz->dir);
}

void liberar(TNodo *raiz){
    if(raiz == NULL)
        return;

    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

int main(){
    TNodo *raiz, *verificar;
    int op, valor, soma = 0;

    system("cls");

    raiz = start();

    do {
        printf("1) ADICIONAR\n");
        printf("2) REMOVER\n");
        printf("3) IMPRIMIR\n");
        printf("4) SOMA\n");
        printf("0) ENCERRAR\n");
        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 1:
            //ADICIONAR
            printf("DIGITE O VALOR: ");
            scanf("%d", &valor);
            raiz = adicionar(raiz, valor);
            break;

        case 2:
            //REMOVER
            printf("DIGITE O VALOR: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;

        case 3:
            //IMPRIMIR
            printf("ARVORE ORDENADA\n");
            imprimirOrdem(raiz);
            printf("\n");
            break;
        
        case 4:
            //SOMAR
            printf("SOMA:");
            soma = somar(raiz);
            printf("%d\n", soma);
            break;
        
        default:
            if(op != 0)
                printf("VALOR INVALIDO.\n");
            break;
        }
    } while (op != 0);

    //LIBERAR TUDO
    liberar(raiz);
    
    return 0;
}