#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int info;
    struct Nodo *dir;
    struct Nodo *esq;
}TNodo;

typedef TNodo *PNodo;

PNodo start(){
    return NULL;
}

//IMPRIMI OS NODOS DE FORMA ORDENADA (PRE FIXA)
void imprimir(PNodo r){
    if(r == NULL)
        return;
    
    imprimir(r->esq);
    printf("%d ", r->info);
    imprimir(r->dir);
}

//LIBERAR O NODO E TODOS OS SEUS DECENDENTES POSFIXA
void liberar(PNodo r){
    if(r == NULL)
        return;

    liberar(r->esq);
    liberar(r->dir);
    free(r);
}

PNodo criarNodo(int val){
    PNodo novo;

    novo = (PNodo)malloc(sizeof(TNodo));

    if(novo != NULL){
        novo->info = val;
        novo->dir = NULL;
        novo->esq = NULL;
    }

    return novo;
}

PNodo inserir(PNodo r, int val){
    if(r == NULL)
        return r = criarNodo(val);

    if(val < r->info)
        r->esq = inserir(r->esq, val);
    else if(val > r->info)
        r->dir = inserir(r->dir, val);

    return r;
}

int busca(PNodo r, int chave){
    if(r == NULL)
        return 0;
    if(r->info == chave)
        return 1;
    
    return busca(r->dir, chave) + busca(r->esq, chave);
}

PNodo buscaGen(PNodo r, int chave){
    if(r == NULL || r->info == chave)
        return r;

    if(chave < r->info)
        r->esq = buscaGen(r->esq, chave);
    else
        r->dir = buscaGen(r->dir, chave);

    return NULL;
}

PNodo remover(PNodo r, int val){
    PNodo pai, filho;

    if(r == NULL)
        return NULL;

    if(r->info == val){
        //NO FOLHA
        if(r->dir == NULL && r->esq == NULL){
            free(r); 
            return NULL;
        }

        //NO COM FILHO A ESQUERDA
        if(r->dir == NULL){
            filho = r->esq;
            free(r);
            return filho;
        }

        //NO COM FILHO A DIREITA
        if(r->esq == NULL){
            filho = r->dir;
            free(r);
            return filho;
        }

        //BUSCA O NO MAIS A DIREITA DA SUBARVORE A ESQUERDA
        for(pai = r, filho = r->esq; filho->dir != NULL; pai = filho, filho = filho->dir);
        r->info = filho->info;

        if(pai == r)
            pai->esq = remover(pai->esq, val);
        else
            pai->dir = remover(pai->dir, val);

        free(filho);
        return r;
    } else if(val < r->info)
        r->esq = remover(r->esq, val);
    else 
        r->dir = remover(r->dir, val);
    
    return r;
}


int somar(PNodo r){
    if(r == NULL)
        return 0;
    
    return r->info + somar(r->dir) + somar(r->esq);
}

int numero(PNodo r){
    if(r == NULL)
        return 0;
    
    return 1 + numero(r->esq) + numero(r->dir);
}

int buscaMaior(PNodo r){
    PNodo aux;

    for(aux = r; aux->dir != NULL; aux = aux->dir);

    return aux->info;
}

int buscaMenor(PNodo r){
    PNodo aux;

    for(aux = r; aux->esq != NULL; aux = aux->esq);

    return aux->info;
}

int altura(PNodo r){
    int esq, dir;

    if(r == NULL)
        return -1;

    esq = altura(r->esq);
    dir = altura(r->dir);

    if(esq > dir)
        return esq + 1;
    else
        return dir + 1;
}

int numAcestrais(PNodo r, int v){
    if(r == NULL || r->info == v)
        return 0;
    
    if(v < r->info)
        return 1 + numAcestrais(r->esq, v);
    else
        return 1 + numAcestrais(r->dir, v);
}

int numFolhas(PNodo r){
    if(r == NULL)
        return 0;

    if(r->dir == NULL && r->esq == NULL)
        return 1;

    return numFolhas(r->esq) + numFolhas(r->dir);
}

int maiorQ(PNodo r, int v){
    if(r == NULL)
        return 0;

    if(v < r->info)
        return 1 + maiorQ(r->esq, v) + maiorQ(r->dir, v);
    else if(v == r->info)
        return  maiorQ(r->dir, v);

    return 0;
}


int main(){
    PNodo raiz;
    int op, valor, soma, maior, menor, nodos, alturaArvore, ancestrais, folhas;
    float media = 0.0;

    raiz = start();

    system("cls");

     do {
        printf("1) ADICIONAR\n");
        printf("2) REMOVER\n");
        printf("3) IMPRIMIR\n");
        printf("4) ANALISE\n");
        printf("5) ANCESTRAIS\n");
        printf("0) ENCERRAR\n");
        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 1:
            //ADICIONAR
            printf("DIGITE O VALOR: ");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
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
            imprimir(raiz);
            printf("\n");
            break;
        
        case 4:
            //ANALISE
            printf("ANALISE:\n");

            if(raiz != NULL){
                soma = somar(raiz);
                nodos = numero(raiz);
                maior = buscaMaior(raiz);
                menor = buscaMenor(raiz);
                media = (float)soma/nodos;
                alturaArvore = altura(raiz);

                
                printf("NUMERO DE NODOS: %d\n", nodos);
                printf("MAIOR NODO: %d\n", maior);
                printf("MENOR NODO: %d\n", menor);
                printf("SOMA: %d\n", soma);
                printf("MEDIA: %.2f\n", media);
                printf("ALTURA: %d\n", altura);
            } else {
                printf("NENHUM VALOR INSERIDO.\n");
            }

             break;

        case 5:
            printf("DIGITE O VALOR DO NODO:");
            scanf("%d", &valor);

            if(busca(raiz, valor) == 1){
                 ancestrais = numAcestrais(raiz, valor);
            } else {
                ancestrais = 0;
            }

           
            printf("NUMERO DE ANCESTRAIS: %d\n\n", ancestrais);
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