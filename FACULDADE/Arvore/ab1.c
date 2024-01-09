//ARVORE BINÁRIA 1

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    char info;
    struct Nodo *prim, *prox;
}TNodo;

TNodo *start(){
    return NULL;
}

void imprimirPre(TNodo *r){
    if(r == NULL){
        return;
    }

    printf("%c ", r->info);
    imprimirPre(r->prim);
    imprimirPre(r->prox);
}

void imprimirIn(TNodo *r){
    if(r == NULL){
        return;
    }

    imprimirIn(r->prim);
    printf("%c ", r->info);
    imprimirIn(r->prox);
}

void imprimirPos(TNodo *r){
    if(r == NULL){
        return;
    }

    imprimirPos(r->prim);
    imprimirPos(r->prox);
    printf("%c", r->info);
}

void liberarPos(TNodo *r){
    if (r == NULL){
        return;
    }

    liberarPos(r->prim);
    liberarPos(r->prox);
    free(r);
}

void filhosDoNodo(TNodo *p){
    TNodo *f;

    if(p != NULL){
        for(f = p->prim; p != NULL; f = p->prox){
            printf("%c ", p->info);
        }
    }
}

//INSERÇÃO DO TIPO PILHA
void inserir(TNodo *p, TNodo *f){
    f->prox = p->prim;
    p->prim = f;
}

TNodo *buscaGen(TNodo *r, char c){
    TNodo *p;

    if(r == NULL || r->info == c) 
        return r;
    p = buscaGen(r->prox, c);

    if(p != NULL) 
        return p;
    else
        return buscaGen(r->prim, c);
}

int iguais(TNodo *a, TNodo *b){
    if(a == NULL && b == NULL)
        return 1;
    if(a->info != b->info)
        return 0;
    

    //SE ELES FOREM DIFERENTE O RETORNO SERA DO TIPO FALSO, OU SEJA, ZERO
    //CASO FOREM IGUAIS O RETOR SERA DO TIPO VERDADEIRO, OU SEJA, 1
    return iguais(a->prox, b->prox) && iguais(a->prim, b->prim);
}


void inserirArv(TNodo *a, char p, char f){
    TNodo *pai, *filho;

    //SE A RAIZ FOR NULA O CODIGO RETORNA NULL
    if(a == NULL){
        a = (TNodo *)malloc(sizeof(TNodo));
        if(a == NULL) 
            exit(1); // ERRO DE ALOCAÇÃO
        a->info = p;
        a->prim = NULL;
        a->prox = NULL;
    }
    //BUSCA O ENDEREÇO DE MEMORIA DO NO PAI
    pai = buscaGen(a, p);

    //CASO O NO PAI NÃO SEJA ENCONTRADO O FILHO NÃ0 SERA ADICIONADO
    if(pai == NULL)
        return;

    //CRIANDO O NO FILHO
    filho = (TNodo *)malloc(sizeof(TNodo));

    if(filho == NULL) exit(1); //ERRO DE ALOCAÇÃO

    //ORGANIZNADO OS PONTEIROS
    filho->info = f;
    filho->prim = NULL;
    filho->prox = pai->prim;
    pai->prim = filho;

}

int busca(TNodo *a, char c){
    if(a == NULL)
        return 0;
    if(a->info == c)
        return 1;

    if(busca(a->prim,c) == 1)
        return 1;
    return busca(a->prox, c == 1);
}

int main(){
    //RAIZ DA ARVORE BINÁRIA
    TNodo *raiz = start();

    // INSERÇÃO DE NÓS NA ÁRVORE GENÉRICA
    inserirArv(raiz, 'A', 'B');
    inserirArv(raiz, 'A', 'C');
    inserirArv(raiz, 'B', 'D');
    inserirArv(raiz, 'B', 'E');
    inserirArv(raiz, 'C', 'F');


    imprimirIn(raiz);
    liberarPos(raiz);

    return 0;
}