#include <stdio.h>
#include <stdlib.h>

struct Produto {
    int codigo;
    struct Produto *next;
};

typedef struct Produto Produto;

Produto * empilhar(Produto *p, int valor){
    Produto *novo = (Produto *)malloc(sizeof(Produto));

    if(novo == NULL){
        printf("[ERRO]");
        exit(1);
    }

    novo->codigo = valor;
    novo->next = p;

    return novo;
}

void exibir(Produto *p){
    Produto *aux;

    for(aux = p; aux != NULL; aux = aux->next){
        printf("CODIGO- %d\n", aux->codigo);
    }
}

void limpar(Produto *p){
    Produto *aux;

    while (p != NULL)
    {
        aux = p;
        p = p->next;
        free(aux);
    }
    
}


int main(){
    Produto *pilha = NULL;

    system("cls");

    pilha = empilhar(pilha, 10);
    pilha = empilhar(pilha, 20);
    pilha = empilhar(pilha, 30);

    exibir(pilha);
    limpar(pilha);


    return 0;
}