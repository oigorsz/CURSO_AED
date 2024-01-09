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

PNodo criarNodo(double area, char fig){
    PNodo novo;
    novo = (PNodo)malloc(sizeof(TNodo));

    if(novo != NULL){
        novo->info = area;
        novo->figura = fig;
        novo->dir = NULL;
        novo->esq = NULL;
    }

    return novo;
}

PNodo adicionar(PNodo arv, double area, char fig){
    if(arv == NULL)
        return arv = criarNodo(area, fig);

    if(area < arv->info)
        arv->esq = adicionar(arv->esq, area, fig);
    else if(area > arv->info)
        arv->dir = adicionar(arv->dir, area, fig);

    return arv;
}



PNodo buscaMenor(PNodo arv, char fig) {
    PNodo menorEsq, menorDir, menor;

    if (arv == NULL) {
        return NULL;
    }

    menorEsq = buscaMenor(arv->esq, fig);
    menorDir = buscaMenor(arv->dir, fig);
    menor = NULL;
 

    if (toupper(arv->figura) == toupper(fig)) {
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
void imprimir(PNodo arv, int temCir, int temRet, int temTri) {

    if (arv == NULL)
        return;
    
    if(temCir){
        printf("circulo\n");
        imprimirCirc(arv);
        printf("\n");
    }

    if(temRet){
        printf("retangulo\n");
        imprimirRet(arv);
        printf("\n");
    }

    if(temTri){
        printf("triangulo\n");
        imprimirTri(arv);
        printf("\n");
    }
   
}


int main(){
    PNodo raiz, aux;
    char op, chave;
    double base, altura, raio, area, num;
    int temCirculo, temRetangulo, temTriangulo;

    raiz = start(); //INICIAR A RAIZ COMO NULL

    do {
        scanf("%c", &op);

        if(op == 'C' || op == 'c'){
            //CIRCULO
            scanf("%lf", &raio);

            area = (raio*raio*M_PI); //CALCULAR AREA DA CIRC
            raiz = adicionar(raiz, area, op);

        } else if(op == 'R' || op == 'r'){
            //RETANGULO

            scanf("%lf %lf", &base, &altura);
            area = (base * altura); //AREA RETANGULO
            raiz = adicionar(raiz, area, op);
        } else if(op == 'T' || op == 't'){
            //TRIANGULO

            scanf("%lf %lf", &base, &altura);
            area = (base * altura)/2; //AREA TRIANGULO
            raiz = adicionar(raiz, area, op);
        } else if(op == 'I' || op == 'i'){
            //IMPRESSÃO
            temCirculo = 0, temRetangulo = 0, temTriangulo = 0; //INICIAR A VERIFICAÇÃO
            verificar(raiz, &temCirculo, &temRetangulo, &temTriangulo);
            imprimir(raiz, temCirculo, temRetangulo, temTriangulo);
        } else if(op == 'E' || op == 'e'){
            //REMOÇÃO DE VALORES
            scanf("%c %lf", &chave, &num); //RECEBE O TIPO E A AREA DE REMOÇÃO

            if(chave == 'C' || chave == 'c' || chave == 'R' || chave == 'r' || chave == 'T' || chave == 't'){
                //chamar função de remoção
                //raiz = retira(raiz, num, chave);
                do {
                    aux = buscaMenor(raiz, chave);
                    raiz = remover(raiz, num, chave);
                    if (aux != NULL && aux->info < num && toupper(raiz->figura) == toupper(chave))
                    { //apenas ira remover se o nó buscado for da forma desejada e tiver area menor que a area entrada
                            raiz = remover(raiz, aux->info, chave);
                        } 
                } while(aux != NULL && aux->info < num);
                
            }
        }
    } while(op != 'F' && op != 'f');

    raiz = liberar(raiz); //LIBERAR TODA A ARVORE AO FINAL
    return 0;
}
