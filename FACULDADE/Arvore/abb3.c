//IGOR DE SOUZA MONTEIRO - RA: 168783 - NOTURNO

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

//DEFININDO ESTRUTURA DOS NÓS
typedef struct Nodo {
    float info;
    char figura;
    struct Nodo *esq, *dir;
}TNodo;

typedef TNodo *PNodo;

//INICIAR MINHA ARVORE COMO NULL
PNodo start(){
    return NULL;
}

//FUNÇÃO PARA LIBERAR UMA SUBARVORE
PNodo liberar(PNodo a){
    if(a == NULL)
        return NULL;

    liberar(a->esq);
    liberar(a->dir);
    free(a);
}

//CRIAR UM NOVO NODO
PNodo criarNodo(char c, float area){
    PNodo novo;

    novo = (PNodo)malloc(sizeof(TNodo));

    if(novo != NULL){
        novo->info = area;
        novo->figura = toupper(c);//CONVERTE A LETRA PARA MAIUCULA(PADRONIZAÇÃO)
        novo->dir = NULL;
        novo->esq = NULL;
    }

    return novo;
}

//ADICIONAR NODO NA ARVORE

PNodo adicionar(PNodo a, char c, float area){
    if(a == NULL)
        return a = criarNodo(c, area);

    if(area < a->info)
        a->esq = adicionar(a->esq, c, area);
    else if(area > a->info)
        a->dir = adicionar(a->dir, c, area);
    
    return a; //RETORNA A ARVORE ATUALIZADA
}


PNodo deletar(PNodo a, char chave, float area){
    PNodo pai, filho;
 
    if(a == NULL)
        return NULL;

    if(a->info < area && a->figura == chave){
        if(a->dir == NULL && a->esq == NULL){
            free(a);
            return NULL;
        }
 
        if(a->dir == NULL){
            filho = a->esq;
            free(a);
            return filho;
        }
 
        if(a->esq == NULL){
            filho = a->dir;
            free(a);
            return filho;
        }
 
        for(pai = a, filho = a->esq; filho->dir != NULL; pai = filho, filho = filho->dir);
        a->info = filho->info;
        a->figura = filho->figura;
 
        if(pai == a)
            pai->esq = filho->esq;
        else
            pai->dir = filho->dir;
 
        free(filho);
 
        return a;
    }

    a->esq = deletar(a->esq, chave, area);
    a->dir = deletar(a->dir, chave, area);
 
    return a;
}

//IMPRIMIR AS ÁREAS DOS CIRCULOS
void imprimirCirc(PNodo a){
    if(a == NULL)
        return;

    imprimirCirc(a->esq);
    if(a->figura == 'C')
        printf("%.1f ", a->info);
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
    PNodo raiz;
    char op, chave;
    float base, altura, raio, area, num, pi = 3.1416;
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
            scanf("%f", &raio);
            area = round((pi*raio*raio) * 10.0) / 10.0; //ARREDONDAMENTO

            raiz = adicionar(raiz, op, area);
        } else if(toupper(op) == 'R'){
            //Add r
            //printf("DIGITE A BASE E A ALTURA:\n");
            scanf("%f %f", &base, &altura);
            area = round((base * altura) * 10.0) / 10.0; //ARREDONDAMENTO

            raiz = adicionar(raiz, op, area);
        } else if(toupper(op) == 'T'){
            //add t
            //printf("DIGITE A BASE E A ALTURA:\n");
            scanf("%f %f", &base, &altura);
             area = round(((base * altura)/ 2) * 10.0) / 10.0; //ARREDONDAMENTO

            raiz = adicionar(raiz, op, area);
        } else if(toupper(op) == 'I'){
            //IMPRIMIR
            temCirculo = 0, temRetangulo = 0, temTriangulo = 0; //REINICIA OS CONTADORES
            verificar(raiz, &temCirculo, &temRetangulo, &temTriangulo);
            imprimir(raiz, temCirculo, temRetangulo, temTriangulo );
        } else if(toupper(op) == 'E'){
            //ELIMINAR
            scanf("%c %f", &chave, &num);

            if(toupper(chave) == 'R' || toupper(chave) == 'C' || toupper(chave) == 'T')
                raiz = deletar(raiz, toupper(chave), num);

        }

    } while(toupper(op) != 'F');

    //LIBERA TODA A RAIZ AO FINAL DO PROGRAMA
    raiz = liberar(raiz);
    return 0;
}