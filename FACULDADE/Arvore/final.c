//IGOR DE SOUZA MONTEIRO - RA: 168783 - NOTURNO

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//ESTRUTURA DE NODOS
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

//FUNÇÃO PARA CRIAR UM NODO COM SUAS INFORMAÇÕES
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

//FUNÇÃO PARA ADICIONAR OS NODOS CONFORME A AREA
PNodo adicionar(PNodo a, double area, char tipo) {
    if (a == NULL)
        return a = criarNodo(area, tipo);

    if(area < a->info)
        a->esq = adicionar(a->esq, area, tipo);
    else if(area > a->info)
        a->dir = adicionar(a->dir, area, tipo);

    return a;
}

//RETIRA O NÓ DA ARVORE QUE POSSUAM A AREA PASSADA COMO PARAMETRO
PNodo remover (PNodo a, double area, char tipo){ 
    PNodo filho, pai;

    if(a==NULL)
        return NULL;
 
    if (area < a->info)
        a->esq = remover (a->esq, area, tipo);
    else if (area > a->info)
        a->dir = remover (a->dir, area, tipo);
    else {
        //ENCONTROU O NODO
        //REMOVER NODO FOLHA
        if (a->dir == NULL && a->esq == NULL){
            free(a);
            return NULL;
        }

        //REMOVER NODO COM FILHO A ESQUERDA
        if (a->dir == NULL){
            filho = a->esq;
            free(a);
            return filho;
        }

        //REMOVER NODO COM FILHO A DIREITA
        if (a->esq == NULL){
            filho = a->dir;
            free(a);
            return filho;
        }
        
        //REMOVER NODO COM DOIS FILHOS
        for (pai = a, filho = a->esq; filho->dir != NULL; pai = filho, filho = filho->dir);
        a->info = filho->info;
        a->tipo = filho->tipo;

        if (a == pai)
            pai->esq = filho->esq;
        else 
            pai->dir = filho->esq;

        free(filho);
        return a;
    }

    return a; //RETORNA A ARVORE ATUALIZADA
}
 
//FUNÇÃO PARA LIBERAR MEMORIA DA ARVORE
PNodo liberar(PNodo a){
    if(a == NULL)
        return NULL;

    liberar(a->esq);
    liberar(a->dir);
    free(a);
    return NULL;
}
 
//FUNÇÃO QUE BUSCA A MENOR AREA NA ARVORE DE UM DADO TIPO
PNodo buscarMenor(PNodo a, char tipo) { 
    PNodo menorEsq, menorDir, menor;

    if (a == NULL) {
        return NULL;
    }
    
    menorEsq = buscarMenor(a->esq, tipo);
    menorDir = buscarMenor(a->dir, tipo);
    menor = NULL;

    //GRAVA A PRIMEIRA APARIÇÃO DO TIPO
    if (a->tipo == tipo) {
        menor = a;
    }

    // VERIFICA SE A MENOR ÁREA ESTÁ NO RAMO ESQUERDO E ATUALIZA
    if (menorEsq != NULL && (menor == NULL || menorEsq->info < menor->info)) {
        menor = menorEsq;
    }

    // VERIFICA SE A MENOR ÁREA ESTÁ NO RAMO DIREITO E ATUALIZA
    if (menorDir != NULL && (menor == NULL || menorDir->info < menor->info)) {
        menor = menorDir;
    }

    // RETORNA O NÓ COM A MENOR ÁREA DO TIPO ESPECIFICADO
    return menor;
}
 

//FUNÇÃO PARA IMPRIMIR EM ORDEM INFIXA(CRESCENTE EM AREA DE CADA TIPO ESPECIFICO)
void imprimir(PNodo a, char tipo) {
    if (a != NULL) {
        imprimir(a->esq, tipo);

        //VERIFICA SE O NODO É DO TIPO REQUERIDO
        if (a->tipo == tipo) {
            printf("%.1lf ", a->info);
        }
        
        imprimir(a->dir, tipo);
    }
}
 
int main() {
    PNodo raiz, aux;
    double area, altura, base, raio, PI = M_PI;
    char figura, chave;

    raiz = start(); //INICIA A RAIZ COMO NULL
    
    do {
        scanf(" %c", &figura);
        figura = toupper(figura); //CONVERTE O CARACTER EM CAPS

        if(figura == 'C'){
            //CRIAR CIRCULO
            scanf("%lf", &raio);
            area = (raio*raio)*PI;
            raiz = adicionar(raiz, area, figura);
        } else if(figura == 'R'){
            //CRIAR RETANGULO
            scanf("%lf %lf", &base, &altura);
            area = base * altura;
            raiz = adicionar(raiz, area, figura);
        } else if(figura == 'T'){
            //CRIAR TRIANGULO
            scanf("%lf %lf", &base, &altura);
            area = (base * altura)/2;
            raiz = adicionar(raiz, area, figura);
        } else if(figura == 'I'){
            //IMPRIMIR
            //VERIFICA SE EXISTE CIRCULO NA ARVORE
            if (buscarMenor(raiz, 'C') != NULL){ 
                printf("circulo\n");
                imprimir(raiz, 'C');
            }

            //VERIFICA SE EXISTE RETANGULO NA AROVRE
            if (buscarMenor(raiz, 'R') != NULL){
                printf("\nretangulo\n");
                imprimir(raiz, 'R');
            }

            //VERIFICA SE EXISTE TRIANGULO NA AROVRE
            if (buscarMenor(raiz, 'T') != NULL){
                printf("\ntriangulo\n");
                imprimir(raiz, 'T');
                printf("\n");
            }
        } else if(figura == 'E'){
            //ELIMINAR
            scanf(" %c %lf", &chave, &area);
            chave = toupper(chave); //CONVERTE A CHAVE PARA CAPS
            aux = buscarMenor(raiz, chave); //COMEÇA A REMOÇÃO PELO MENOR NÓ QUE PERTENÇA AO TIPO

            while (aux != NULL && aux->info < area) {
                if (aux->tipo == chave) {
                    raiz = remover(raiz, aux->info, chave);
                }
                aux = buscarMenor(raiz, chave);
            }
        }
    }while(figura != 'F');

    raiz = liberar(raiz); //LIBERAR TODA ARVORE
 
    return 0;
}