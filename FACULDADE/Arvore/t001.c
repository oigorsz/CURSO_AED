//CAMPO MINADO- IGOR DE SOUZA MONTEIRO - NOTURNO RA: 168783
//EXEMPLO DE MATRIZES ESPARSAS

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int val, col;
    struct Nodo* prox;
}TNodo; //ESTRUTURA QUE ARMAZENA O VALOR E A COLUNA 

typedef TNodo *PNodo; 

void iniciar(PNodo *m, int l){
    int i;

    for(i = 0; i < l; i++){
        m[i] = NULL;
    }
} //FAZ MEUS VETORES DE PONTEIROS RECEBEREM NULL, INICIALMENTE

void liberar(PNodo *m, int l){
    PNodo p;
    int i;

    for(i = 0; i < l; i++){
        for(p = m[i]; p != NULL; p = m[i]){
            m[i] = p->prox;
            free(p);
        }
    }
} //FUNÇÃO QUE LIBERA MEU VETOR DE PONTEIROS E OS NODOS

void imprimir(PNodo* m, int l, int c){
    int i, j;
    for(i = 0; i < l; i++){
        PNodo p = m[i];
        for(j = 0; j < c; j++){
            if (p != NULL && p->col == j) {
                if(p->val == -1){
                    printf("X\t");
                } else {
                    printf("%d\t", p->val);
                }
                p = p->prox;
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

void inserir(PNodo *m, int l, int c, int v) {
    PNodo novo, p, q;
    novo = (PNodo)malloc(sizeof(TNodo));

    if (novo == NULL) {
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->val = v;
    novo->col = c;

    p = m[l];

    if (m[l] == NULL || c < p->col) {
        novo->prox = p;
        m[l] = novo;
    } else {
        while (p->prox != NULL && c > p->prox->col) {
            p = p->prox;
        }
        q = p->prox;
        p->prox = novo;
        novo->prox = q;
    }
}


int verificar(PNodo *m, int L, int C, int cl, int cc){
    PNodo p;
    //VERIFICA SE AS CORDENADAS ESTÃO OK E SE AQUELA CORDENADA NÃO É OCUPADA POR UMA BOMBA

    if(cl < 0 || cl >= L || cc < 0 || cc >= C){
        return -1; //CORDENDAS FORA DO ESTIUPULADO
    } else {
        for(p = m[cl]; p != NULL; p = p->prox){
            if(p->col == cc && p->val == -1){
                return 0; //CORDENDAS NÃO COUPADAS
            }
        }
    }

    return 1;
}


int main(){
    int L, C, Nb, i, cl, cc, livre, bomba = -1;
    PNodo *matriz, aux;

    system("cls");

    do {
        printf("DIGITE O NUMERO DE MAXLINHAS E MAXCOLUNAS:\n");
        scanf("%d %d", &L, &C);
    } while(!(0 <= L && 0 <= C && C <= 100)); //VERIFICAÇÃO DO NUMERO DE MAXLINHAS E MAXCOLUNAS

    //ALOCAR DINAMICAMENTE A QUANTIDADE DE LINHAS QUE SERÃO UTILIZADAS NO PROGRAMA
    matriz = (PNodo*)malloc(sizeof(PNodo) * L);

    if(matriz == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        return 0;
    } //VERIFICA SE ALOCOU O VETOR DE PONTEIROS DE TAMANHO L

    iniciar(matriz, L);

    do {
        printf("DIGITE O NUMERO DE BOMBAS:\n");
        scanf("%d", &Nb);
    } while(!(0 <= Nb && Nb <= 100));

    //REGISTRA AS BOMBAS NAS SUAS RESPECTIVAS CORDENADAS
    for(i = 0; i < Nb; i++){
        printf("DIGITE A CORDENADA DAS BOMBAS\n");
        printf("m[i][j]: ");
        scanf("%d %d", &cl, &cc); //RECEBE AS CORDENADAS
        livre = verificar(matriz, L, C, cl, cc);

        //LIVRE == 0 CORDENADA DISPONIVEL PARA CRIAR BOMBA
        if(livre == 1){
            inserir(matriz, cl, cc, bomba);
            printf("\nBOMBA ADD\n");
        };
    }

    imprimir(matriz, L, C);
    liberar(matriz, L);
    return 0;
}