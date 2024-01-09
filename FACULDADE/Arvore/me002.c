#include <stdio.h>
#include <stdlib.h>
#define MAX_LINHAS 100

typedef struct Nodo {
    int valor, coluna;
    struct Nodo * prox;
}TNodo;

typedef TNodo *PNodo;
typedef PNodo matriz[MAX_LINHAS];

void inicializar(matriz m, int l){
    int i;

    for(i = 0; i < l; i++){
        m[i] = NULL;
    }
}

void inserir(matriz m, int l, int c, int v){
    PNodo novo, p;
    novo = (PNodo)malloc(sizeof(TNodo));
    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->valor = v;
    novo->coluna = c;
    novo->prox = NULL;

    if(m[l] == NULL){
        m[l] = novo;
    } else {
        for(p = m[l]; p->prox != NULL; p = p->prox);
        p->prox = novo;
    }
}

void imprimir(matriz m, int l, int c){
    PNodo p;
    int i, j;

    for(i = 0; i < l; i++){
        p = m[i];
        for(j = 0; j < c; j++){
            if(p == NULL || p->coluna != j){
                printf("0\t");
            } else {
                printf("%d\t", p->valor);
            }
        }

        printf("\n");
    }
}

void liberar(matriz m, int l){
    PNodo p;
    int i;

    for(i = 0; i < l; i++){
        for(p = m[i]; p != NULL; p = m[i]){
            m[i] = p->prox;
            free(p);
        }
    }
}


int main(){
    int linhas, colunas, valor, i, j;
    matriz m;
    PNodo *mt;

    system("cls");

    do {
        printf("DIGITE O NUMERO DE LINHAS DA MATRIZ: ");
        scanf("%d", &linhas);
    } while (linhas < 0 || linhas > MAX_LINHAS);

    system("cls");

    do {
        printf("DIGITE O NUMERO DE COLUNAS DA MATRIZ: ");
        scanf("%d", &colunas);
    } while (colunas < 0);

    system("cls");

    //INICIAR OS VETORES

    inicializar(m, linhas);

    //RECEBER OS VALORES
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("m[%d][%d] = ", i, j);
            scanf("%d", &valor);

            if (valor != 0) {
                inserir(m, i, j, valor);
            }
        }
    }

    system("cls");

    //IMPRIMIR
    printf("MATRIZ ORIGINAL\n");
    imprimir(m, linhas, colunas);
    
    //mt = transposta(m, linhas, colunas);

   // printf("\nMATRIZ TRANSPOSTA\n");
    imprimir(mt, linhas, colunas);
    

    liberar(m, linhas);
    liberar(mt, linhas);
    
}