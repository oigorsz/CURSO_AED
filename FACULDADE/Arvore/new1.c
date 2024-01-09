//IGOR DE SOUZA MONTEIRO - RA: 168783 - NOTURNO
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef struct Nodo{
double info;
char figura;
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
        novo->figura = toupper(fig);
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

PNodo retira(PNodo arv, double area, char figura) {
    if (arv == NULL) {
        return arv;
    }

    arv->esq = retira(arv->esq, area, figura); // percorre a subárvore esquerda
    arv->dir = retira(arv->dir, area, figura); // percorre a subárvore direita

    if (arv->info < area) {
        PNodo temp = arv;
        arv = arv->dir; 
        free(temp);
        arv = retira(arv, area, figura);
    }

    if (arv != NULL && arv->info == area && arv->figura == figura) {
        if (arv->esq == NULL && arv->dir == NULL) {
            free(arv);
            return NULL;
        } else if (arv->esq == NULL) {
            PNodo temp = arv;
            arv = arv->dir;
            free(temp);
        } else if (arv->dir == NULL) {
            PNodo temp = arv;
            arv = arv->esq;
            free(temp);
        } else {
            // nó possui dois filhos
            PNodo temp = arv->esq;
            while (temp->dir != NULL) {
                temp = temp->dir;
            }
            arv->info = temp->info;
            arv->figura = temp->figura;
            arv->esq = retira(arv->esq, temp->info, temp->figura);
        }
    }

    return arv;
}

PNodo remover(PNodo arv, double area, char fig){
    PNodo pai, filho;
    
    if(arv == NULL)
        return NULL;

    if(arv->info < area)
        arv->esq = remover(arv->esq, area, fig);
    else if(arv->info > area)
        arv->dir = remover(arv->dir, area, fig);
    else {
        //REMOVER NO FOLHA
        if(arv->dir == NULL && arv->esq == NULL){
            free(arv);
            return NULL;
        }

        if(arv->dir == NULL){
            filho = arv->esq;
            free(arv);
            return filho;
        }

        if(arv->esq == NULL){
            filho = arv->dir;
            free(arv);
            return filho;
        }

        for(pai = arv, filho = arv->esq; filho->dir != NULL; pai = filho, filho = filho->dir);
        arv->info = filho->info;
        arv->figura = filho->figura;

        if(pai == arv)
            pai->esq = filho->esq;
        else
            pai->dir = filho->esq;

        free(filho);
        return arv;
    }

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
void imprimirCirc(PNodo a){
    if(a == NULL)
        return;

    imprimirCirc(a->esq);
    if(a->figura == 'C')
        printf("%.1lf ", a->info);
    imprimirCirc(a->dir);
}

//IMPRIMIR AS ÁREAS DOS TRIANGULOS
void imprimirTri(PNodo a){
    if(a == NULL)
        return;

    imprimirTri(a->esq);
    if(a->figura == 'T')
        printf("%.1f ", a->info);
    imprimirTri(a->dir);
}

//IMPRIMIR AS AREAS DOS RETANGULO
void imprimirRet(PNodo a){
    if(a == NULL)
        return;

    imprimirRet(a->esq);
    if(a->figura == 'R')
        printf("%.1f ", a->info);
    imprimirRet(a->dir);
}

//VERIFICA QUAIS CATEGORIAS ESTÃO PRESENTES
void verificar(PNodo a, int *temCirc, int *temRet, int *temTri){
    if(a == NULL)
        return;

    verificar(a->esq, temCirc, temRet, temTri);
    verificar(a->dir, temCirc, temRet, temTri);

    if(a->figura == 'C')
        *temCirc = 1;
    if(a->figura == 'R')
        *temRet = 1;
    if(a->figura == 'T')
        *temTri = 1;
    
}


//IMPRIME TUDO
// Função para imprimir todas as áreas em ordem crescente
void imprimir(PNodo a, int temCir, int temRet, int temTri) {

    if (a == NULL)
        return;
    
    if(temCir){
        printf("circulo\n");
        imprimirCirc(a);
        printf("\n");
    }

    if(temRet){
        printf("retangulo\n");
        imprimirRet(a);
        printf("\n");
    }

    if(temTri){
        printf("triangulo\n");
        imprimirTri(a);
        printf("\n");
    }
   
}


int main(){
    PNodo raiz, aux;
    char op, chave;
    double base, altura, raio, area, num;
    int temCirculo, temRetangulo, temTriangulo;

    //INICIAR A RAIZ COMO NULL
    raiz = start();

    //system("cls");

    do{
        //SITUAÇÕES
        //printf("C ou c (circulo)\n");
        //printf("R ou r (retangulo)\n");
        //printf("T ou t (triangulo)\n");
        //printf("I ou i (imprimir)\n");
        //printf("E ou e(eliminar)\n");
        //printf("F ou f (finalizar)\n");
        //RECEBE A RESPOSTA
        scanf("%c", &op);

        //system("cls");

        if(toupper(op) == 'C'){
            //ADD c
            //printf("DIGITE O RAIO:\n");
            scanf("%lf", &raio);
            area = (M_PI*raio*raio);

            raiz = adicionar(raiz, area, op);
        } else if(toupper(op) == 'R'){
            //Add r
            //printf("DIGITE A BASE E A ALTURA:\n");
            scanf("%lf %lf", &base, &altura);
            area = base * altura; 

            raiz = adicionar(raiz, area, op);
        } else if(toupper(op) == 'T'){
            //add t
            //printf("DIGITE A BASE E A ALTURA:\n");
            scanf("%lf %lf", &base, &altura);
             area = ((base * altura)/ 2);

            raiz = adicionar(raiz, area, op);
        } else if(toupper(op) == 'I'){
            //IMPRIMIR
            temCirculo = 0, temRetangulo = 0, temTriangulo = 0; //REINICIA OS CONTADORES
            verificar(raiz, &temCirculo, &temRetangulo, &temTriangulo);
            imprimir(raiz, temCirculo, temRetangulo, temTriangulo );
        } else if(toupper(op) == 'E'){
            //ELIMINAR
            scanf("%c %lf", &chave, &num);

            if(toupper(chave) == 'R' || toupper(chave) == 'C' || toupper(chave) == 'T')
                do {
                    aux = buscaMenor(raiz, toupper(chave));
                    raiz = remover(raiz, num, toupper(chave));
                    if (aux != NULL && aux->info < num && toupper(raiz->figura) == toupper(chave))
                    { //apenas ira remover se o nó buscado for da forma desejada e tiver area menor que a area entrada
                            raiz = remover(raiz, aux->info, chave);
                        } 
                } while(aux != NULL && aux->info < num);

        }

    } while(toupper(op) != 'F');

    //LIBERA TODA A RAIZ AO FINAL DO PROGRAMA
    raiz = liberar(raiz);
    return 0;
}

