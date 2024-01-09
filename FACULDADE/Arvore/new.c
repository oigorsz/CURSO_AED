//IGOR DE SOUZA MONTEIRO - RA: 168783 - NOTURNO
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
 
typedef struct Nodo{
    double info;
    char tipo;
    struct Nodo *dir, *esq;
}TNodo;
 
typedef TNodo *PNodo;
 
//INICIALIZAR MINHA ARVORE
PNodo start(){
    return NULL;
}
 
PNodo criarNodo(double area, char tipo){
    PNodo novo;
    novo = (PNodo)malloc(sizeof(TNodo));
 
    if(novo != NULL){
        novo->info = area;
        novo->tipo = tipo;
        novo->dir = NULL;
        novo->esq = NULL;
    }
 
    return novo;
}
 
PNodo adicionar(PNodo arv, double area, char tipo){
    if(arv == NULL)
        return arv = criarNodo(area, tipo);
 
    if(area < arv->info)
        arv->esq = adicionar(arv->esq, area, tipo);
    else if(area > arv->info)
        arv->dir = adicionar(arv->dir, area, tipo);
 
    return arv;
}
 
 
PNodo remover (PNodo arv, double area, char tipo){ // retira da arvore o nó com a area que foi entrada como parametro
    PNodo filho, pai;
    if(arv == NULL)
        return NULL;
 
    if (area < arv->info){
        arv->esq = remover (arv->esq, area, tipo);
        return arv;
    } else if (area > arv->info){
        arv->dir = remover (arv->dir, area, tipo);
        return arv;
    } else {
        if (arv->dir == NULL && arv->esq == NULL){
            free(arv);
            return NULL;
        }
 
        if (arv->dir == NULL){
            filho = filho->esq;
            free(arv);
            return filho;
        }
 
        if (arv->esq == NULL){
            filho = filho->dir;
            free(arv);
            return filho;
        }
 
        for (pai = arv, filho = arv->esq; filho->dir != NULL; pai = filho, filho = filho->dir);
        if (arv == pai){
            pai->esq = filho->esq;
        } else {
            pai->dir = filho->esq;
        }
        arv->info = filho->info;
        arv->tipo = filho->tipo;
        free(filho);
        return arv;
    }
}
 
PNodo buscaMenor(PNodo arv, char tipo) {
    PNodo menorEsq, menorDir, menor;
 
    if (arv == NULL) {
        return NULL;
    }
 
    menorEsq = buscaMenor(arv->esq, tipo);
    menorDir = buscaMenor(arv->dir, tipo);
    menor = NULL;
 
 
    if (arv->tipo == tipo) {
        menor = arv;
    }
 
    if (menorEsq != NULL && (menor == NULL || menorEsq->info < menor->info)) {
        menor = menorEsq;
    }
 
    if (menorDir != NULL && (menor == NULL || menorDir->info < menor->info)) {
        menor = menorDir;
    }
 
    return menor;
}
 
PNodo liberar(PNodo arv){
    if(arv == NULL)
        return NULL;
 
    liberar(arv->esq);
    liberar(arv->dir);
    free(arv);
    return NULL;
}
 
//IMPRIMIR AS ÁREAS DOS CIRCULOS
void imprimirCirc(PNodo arv){
    if(arv == NULL)
        return;
 
    imprimirCirc(arv->esq);
    if(arv->tipo == 'C')
        printf("%.1lf ", arv->info);
    imprimirCirc(arv->dir);
}
 
//IMPRIMIR AS ÁREAS DOS TRIANGULOS
void imprimirTri(PNodo arv){
    if(arv == NULL)
        return;
 
    imprimirTri(arv->esq);
    if(arv->tipo == 'T')
        printf("%.1f ", arv->info);
    imprimirTri(arv->dir);
}
 
//IMPRIMIR AS AREAS DOS RETANGULO
void imprimirRet(PNodo arv){
    if(arv == NULL)
        return;
 
    imprimirRet(arv->esq);
    if(arv->tipo == 'R')
        printf("%.1f ", arv->info);
    imprimirRet(arv->dir);
}
 
//VERIFICA QUAIS CATEGORIAS ESTÃO PRESENTES
void verificar(PNodo arv, int *temCirc, int *temRet, int *temTri){
    if(arv == NULL)
        return;
 
    verificar(arv->esq, temCirc, temRet, temTri);
    verificar(arv->dir, temCirc, temRet, temTri);
 
    if(arv->tipo == 'C')
        *temCirc = 1;
    if(arv->tipo == 'R')
        *temRet = 1;
    if(arv->tipo == 'T')
        *temTri = 1;
}
 
//IMPRIME TUDO
void imprimir(PNodo arv, char tipo) { //imprime a arvore na forma in-ordem, apenas se o nó tiver a a forma que for entrada como parametro
    if (arv != NULL) {
        imprimir(arv->esq, tipo);
        
        if (arv->tipo == tipo) {
            printf("%.1lf ", arv->info);
        }
        
        imprimir(arv->dir, tipo);
    }
}
 
 
int main(){
    PNodo raiz, aux;
    char op, chave;
    double base, altura, raio, area, num;
 
    raiz = start(); //INICIAR A RAIZ COMO NULL
 
    do {
        scanf("%c", &op);
        op = toupper(op);
 
        if(op == 'C'){
            //CIRCULO
            scanf("%lf", &raio);
 
            area = (raio*raio*M_PI); //CALCULAR AREA DA CIRC
            raiz = adicionar(raiz, area, op);
 
        } else if(op == 'R'){
            //RETANGULO
            scanf("%lf %lf", &base, &altura);
            area = (base * altura); //AREA RETANGULO
            raiz = adicionar(raiz, area, op);
        } else if(op == 'T'){
            //TRIANGULO
            scanf("%lf %lf", &base, &altura);
            area = (base * altura)/2; //AREA TRIANGULO
            raiz = adicionar(raiz, area, op);
        } else if(op == 'I'){
            //IMPRESSÃO
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
        } else if(op == 'E'){
            //REMOÇÃO DE VALORES
            scanf("%c %lf", &chave, &num); //RECEBE O TIPO E A AREA DE REMOÇÃO
            chave = toupper(chave);
 
            if(chave == 'C' || chave == 'R' || chave == 'T'){
                //chamar função de remoção
                //raiz = retira(raiz, num, chave);
                do {
                    aux = buscaMenor(raiz, chave);
                    raiz = remover(raiz, num, chave);
                    if (aux != NULL && aux->info < num && raiz->tipo == chave)
                    { //apenas ira remover se o nó buscado for da forma desejada e tiver area menor que a area entrada
                            raiz = remover(raiz, aux->info, chave);
                        } 
                } while(aux != NULL && aux->info < num);
                
            }
        }
    } while(op != 'F');
 
    raiz = liberar(raiz); //LIBERAR TODA A ARVORE AO FINAL
    return 0;
}