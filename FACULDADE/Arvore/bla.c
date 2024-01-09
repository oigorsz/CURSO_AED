//IGOR DE SOUZA MONTEIRO - RA: 168783 - NOTURNO

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
 
typedef struct Nodo {
    char tipo;
    double info;
    struct Nodo *dir, *esq;
} TNodo;

typedef TNodo *PNodo;

// INICIA A ARVORE COMO NULL
PNodo start() { 
    return NULL;
}

PNodo retira (PNodo r, float area, char forma){ // retira da arvore o nó com a area que foi entrada como parametro
    PNodo f, p;
    if(r==NULL)return NULL;
 
    if (area < r->info){
        r->esq = retira (r->esq, area, forma);
        return r;
    } else if (area > r->info){
        r->dir = retira (r->dir, area, forma);
        return r;
    } else {
        if (r->dir == NULL && r->esq == NULL){
            free(r);
            return NULL;
 
        }
 
        if (r->dir == NULL){
            f = r->esq;
            free(r);
            return f;
        }
 
        if (r->esq == NULL){
            f = r->dir;
            free(r);
            return f;
        } else {
            for (p = r, f = r->esq; f->dir != NULL; p = f, f = f->dir);
            if (r == p){
                p->esq = f->esq;
            } else {
                p->dir = f->esq;
            }
            r->info = f->info;
            r->tipo = f->tipo;
            free(f);
            return r;
        }
    } 
}
 
PNodo insere(PNodo arvore, double area, char forma) {  // insere ordenadamente os elementos na arvore conforme a area
    if (arvore == NULL) {
        PNodo novo = (PNodo)malloc(sizeof(TNodo));
        novo->info = area;
        novo->info = forma;
        novo->dir = NULL;
        novo->esq = NULL;
        return novo;
    } else {
        if (arvore->info > area) {
            arvore->esq = insere(arvore->esq, area, forma);
        } else if (arvore->info < area){
            arvore->dir = insere(arvore->dir, area, forma);
        }
        return arvore;
    }
}
 
void libera(PNodo a){  // libera a arvore de forma pós-ordem
    if (a == NULL) return;
        libera (a->esq);
        libera (a->dir);
        free(a);
    
}

PNodo buscaMenor(PNodo arvore, char forma) { // busca o menor valor de area da arvore com a forma que for entrada como parametro
    

    if (arvore == NULL) {
        return NULL;
    }

    PNodo menor_esq = buscaMenor(arvore->esq, forma);
    PNodo menor_dir = buscaMenor(arvore->dir, forma);
    PNodo menor = NULL;
 

    if (arvore->tipo == forma) {
        menor = arvore;
    }
 
    if (menor_esq != NULL && (menor == NULL || menor_esq->info < menor->info)) {
        menor = menor_esq;
    }
 
    if (menor_dir != NULL && (menor == NULL || menor_dir->info < menor->info)) {
        menor = menor_dir;
    }
 
    return menor;
}
 
 
void imprimir(PNodo arvore, char forma) { //imprime a arvore na forma in-ordem, apenas se o nó tiver a a forma que for entrada como parametro
    if (arvore != NULL) {
        imprimir(arvore->esq, forma);
        
        if (arvore->tipo == forma) {
            printf("%.1lf ", arvore->info);
        }
        
        imprimir(arvore->dir, forma);
    }
}
 
int main() {
    PNodo raiz, aux;
    char tipo, chave;
    double area, raio, base, altura;

    raiz = start();
 
    while (tipo != 'f' && tipo != 'F') {
        scanf(" %c", &tipo);
        tipo = toupper(tipo);
 
        switch (tipo) {
            case 'C':
                scanf("%lf", &raio);
                area = M_PI * raio * raio;
                raiz = insere(raiz, area, 'C');
                break;
 
            case 'T':
                scanf("%lf %lf", &base, &altura);
                area = (base * altura) / 2.0;
                raiz = insere(raiz, area, 'T');
                break;
 
            case 'R':
                scanf("%f %f", &base, &altura);
                area = base * altura;
                raiz = insere(raiz, area, 'R');
                break;
 
            case 'I':
                if (buscaMenor(raiz, 'C') != NULL){ // verifica se existe algum nó com essa forma para nao imprimir o nome da forma se nao tiver essa forma na arvore
                    printf("circulo\n");
                    imprimir(raiz, 'C');
                }
 
                if (buscaMenor(raiz, 'R') != NULL){
                    printf("\nretangulo\n");
                    imprimir(raiz, 'R');
                }
 
                if (buscaMenor(raiz, 'T') != NULL){
                    printf("\ntriangulo\n");
                    imprimir(raiz, 'T');
                    printf("\n");
                }
                break;
           
            case 'E':
                      scanf(" %c", &chave);
                      scanf("%lf", &area);
                      chave = toupper(chave);
                        do {
                            aux = buscaMenor(raiz, chave);
                            if (aux != NULL && aux->info < area && aux->tipo == chave) { //apenas ira remover se o nó buscado for da forma desejada e tiver area menor que a area entrada
                            raiz = retira(raiz, aux->info, chave);
                        } 
                            } while (aux != NULL && aux->info < area);
 
 
                      break;
        
 
            case 'f':
                break;
                break;
         
 
            default:
                break;
        }
    }
   
    libera(raiz);
 
    return 0;
}