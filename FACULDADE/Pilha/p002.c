#include <stdio.h>
#include <stdlib.h>

struct Produto {
    int codigo;
    struct Produto * next;
};

typedef struct Produto Produto;

Produto *push (Produto *p, int valor){
    Produto *novo = (Produto *)malloc(sizeof(Produto));
    if(novo == NULL){
        printf("[ERRO NA MEMORIA]\n");
        exit(1);
    }

    novo->codigo = valor;
    novo->next = p;

    return novo;
}

Produto *pop(Produto *p){
    Produto *aux = p;

    if(aux == NULL){
        exit(1);
    }

    aux = p->next;
    free(p);

    return aux;
}



void exibir(Produto *p){
    Produto *aux;

    printf("PRODUTOS EMPILHADOS.\n");

    for(aux = p; aux != NULL; aux = aux->next){
        printf("%d\n", aux->codigo);
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

    printf("PROGRAMA ENCERRADO.\n");

}

int main(){
    Produto *pilha = NULL;
    system("cls");

    printf("EMPILHANDO CODIGOS.\n");

    pilha = push(pilha, 10);
    pilha = push(pilha, 20);
    pilha = push(pilha, 30);

    exibir(pilha);

    pilha = pop(pilha);
    exibir(pilha);

    pilha = pop(pilha);
    exibir(pilha);

    pilha = pop(pilha);
    exibir(pilha);

    limpar(pilha);
    return 0;
}