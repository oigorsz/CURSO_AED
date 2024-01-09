#include <stdio.h>
#include <stdlib.h>
#define MAX_LINHA 150

typedef struct Nodo {
    int valor, coluna;
    struct Nodo* prox;
}TNodo;

typedef TNodo *PNodo;

void inicializar(PNodo *m, int l){
    int i;

    for(i = 0; i < l; i++){
        m[i] = NULL;
    }
}

void inserir(PNodo* m, int l, int c, int v){
    //CRIANDO UM NOVO NODO
    PNodo novo, p;
    novo = (PNodo)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->valor = v;
    novo->coluna = c;
    novo->prox = NULL;

    //ALOCA O NODO NA SUA RESPECTIVA LINHAS

    if(m[l] == NULL){
        m[l] = novo;
    } else {
        for(p = m[l]; p->prox != NULL; p = p->prox);
        p->prox = novo;
    }
}

void imprimir(PNodo* m, int l, int c){
    int i, j;
    PNodo p;

    for(i = 0; i < l; i++){
        p = m[i];
        for(j = 0; j < c; j++){
            if(p == NULL || p->coluna != j){
                printf("0\t");
            } else {
                printf("%d\t", p->valor);
                p = p->prox;
            }
        }

        printf("\n");
    }
}

void liberar(PNodo* m, int l) {
    int i;
    PNodo p, temp;

    for (i = 0; i < l; i++) {
        p = m[i];
        while (p != NULL) {
            temp = p;
            p = p->prox;
            free(temp);
        }
        m[i] = NULL;
    }
}


PNodo* transposta(PNodo* m, int l, int c){
    PNodo *novo, p;
    novo = (PNodo*)malloc(sizeof(PNodo * c));
    int i;

    inicializar(novo, c);

    for(i = 0; i < l; i++){
        for(p = m[i]; p != NULL; p = p->prox){
            inserir(novo, p->coluna, i, p->valor);
        }
    }

    return novo;
}

int main() {
    int linhas, colunas, valor, i, j;

    system("cls");

    do {
        printf("DIGITE O NUMERO DE LINHAS DA MATRIZ: ");
        scanf("%d", &linhas);
    } while (linhas < 0 || linhas > MAX_LINHA);

    system("cls");

    do {
        printf("DIGITE O NUMERO DE COLUNAS DA MATRIZ: ");
        scanf("%d", &colunas);
    } while (colunas < 0);

    system("cls");

    PNodo matriz[linhas], *mt; //CRIA UM VETOR DE PONTEIROS PARA ESTRUTURA DE NODOS

    inicializar(matriz, linhas); // FAZENDO TODOS OS ENDEREÇOS RECEBEREM NULL

    // RECEBER OS VALORES

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("m[%d][%d] = ", i, j);
            scanf("%d", &valor);

            if (valor != 0) {
                inserir(matriz, i, j, valor);
            }
        }
    }

    system("cls");

    // IMPRIMIR VALORES
    printf("MATRIZ ORIGINAL\n");
    imprimir(matriz, linhas, colunas);
    
    printf("\nMATRIZ TRANSPOSTA\n");

    mt = transposta(matriz, linhas, colunas);

    imprimir(mt, linhas, colunas);
    liberar(matriz, linhas);

    return 0;
}
