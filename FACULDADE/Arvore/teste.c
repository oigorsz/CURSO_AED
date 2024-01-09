//CAMPO MINADO- IGOR DE SOUZA MONTEIRO - NOTURNO RA: 168783
//EXEMPLO DE MATRIZES ESPARSAS

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int val, col;
    struct Nodo* prox;
}TNodo; //ESTRUTURA QUE ARMAZENA O VALOR E A COLUNA 

void iniciar(TNodo **m, int L){
    int i;

    for(i = 0; i < L; i++){
        m[i] = NULL;
    }
} //FAZ MEUS VETORES DE PONTEIROS RECEBEREM NULL, INICIALMENTE

void liberar(TNodo **m, int L){
    TNodo *p;
    int i;

    for(i = 0; i < L; i++){
        for(p = m[i]; p != NULL; p = m[i]){
            m[i] = p->prox;
            free(p);
        }
    }
} //FUNÇÃO QUE LIBERA MEU VETOR DE PONTEIROS E OS NODOS

void imprimir(TNodo** m, int L, int C){
    TNodo *p;
    int i, j;

    for(i = 0; i < L; i++){
        p = m[i];

        for(j = 0; j < C; j++){
            if (p != NULL && p->col == j) {
                if(p->val == -1)
                    printf("X ");
                else 
                    printf("%d ", p->val);
                p = p->prox;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int verificar(TNodo **m, int L, int C, int cl, int cc){
    TNodo *p;

    if(cl < 0 || cl >= L || cc < 0 || cc >= C){
        return 0; //CORDENDAS FORA DO ESTIUPULADO
    } else {
        for(p = m[cl]; p != NULL; p = p->prox){
            if(p->col == cc && p->val == - 1){
                return 0; //CORDENDAS DE BOMBA
            }
        }
    }

    return 1;//PASSOU NO TESTE
}

void inserir(TNodo **m, int L, int C, int v) {
    //CRIANDO O NODO 
    TNodo *novo, *p, *q;
    novo = (TNodo*)malloc(sizeof(TNodo));

    if (novo == NULL) {
        //printf("[ERRO DE ALOCAÇÃO].\n");
        //exit(1);
    }

    novo->val = v;
    novo->col = C;

    p = m[L];
    q = NULL;

    //ORGANIZANDO O NODO NA MINHA MATRIZ ESPARSA

    if (p == NULL || C < p->col) {
        novo->prox = p;
        m[L] = novo;
    } else {
        while (p->prox != NULL && C > p->prox->col) {
            p = p->prox;
        }

        q = p->prox;
        p->prox = novo;
        novo->prox = q;
    }
}

void inserirAdj(TNodo **m, int L, int C, int cl, int cc) {
    TNodo *novo, *aux, *p;
    int i, j, achouNodo;

    //MAPEAR AS CORDENADAS ADJACENTES À BOMBA E CRIAR NODOS CASO NECESSÁRIO
    for (i = cl - 1; i <= cl + 1; i++) {
        for (j = cc - 1; j <= cc + 1; j++) {
            if (i >= 0 && i < L && j >= 0 && j < C && (i != cl || j != cc)) {
                p = m[i];
                achouNodo = 0;

                while (p != NULL && !achouNodo) {
                    if (p->col == j) {
                        if (p->val != -1) {
                            p->val++;
                        }
                        achouNodo = 1;  // SAI DO LOOP
                    }
                    p = p->prox;
                }


                if (achouNodo == 0) {
                    //CRIA O NOVO NODO
                    novo = (TNodo*)malloc(sizeof(TNodo));
                    if (novo == NULL) {
                        printf("[ERRO DE ALOCAÇÃO].\n");
                        exit(1);
                    }
                    novo->val = 1;
                    novo->col = j;
                    p = m[i];
                    aux = NULL;

                    // ORGANIZA O NODO EM ORDEM CRESCENTE DE COLUNAS

                    while (p != NULL && j > p->col) {
                        aux = p;
                        p = p->prox;
                    }

                    if (aux == NULL) {
                        novo->prox = p;
                        m[i] = novo;
                    } else {
                        aux->prox = novo;
                        novo->prox = p;
                    }
                }
            }
        }
    }
}

int main(){
    int L, C, Nb, i, j, cl, cc, livre, bomba = -1;
    TNodo **matriz, *p;

    do {
        //printf("DIGITE O NUMERO DE MAXLINHAS E MAXCOLUNAS:\n");
        scanf("%d %d", &L, &C);
    } while(!(0 <= L && L <= 100 && 0 <= C && C <= 100)); //VERIFICAÇÃO DO NUMERO DE MAXLINHAS E MAXCOLUNAS

    //ALOCAR DINAMICAMENTE A QUANTIDADE DE LINHAS QUE SERÃO UTILIZADAS NO PROGRAMA
    matriz = (TNodo**)malloc(sizeof(TNodo) * L);

    if(matriz == NULL){
        //printf("[ERRO DE ALOCAÇÃO].\n");
        return 0;
    } //VERIFICA SE ALOCOU O VETOR DE PONTEIROS DE TAMANHO L

    iniciar(matriz, L);

    do {
        //printf("DIGITE O NUMERO DE BOMBAS:\n");
        scanf("%d", &Nb);
    } while(!(0 <= Nb && Nb <= 100));

    //REGISTRA AS BOMBAS NAS SUAS RESPECTIVAS CORDENADAS
    for(i = 0; i < Nb; i++){
        //printf("DIGITE A CORDENADA DAS BOMBAS\n");
        //printf("m[i][j]: ");
        scanf("%d %d", &cl, &cc); //RECEBE AS CORDENADAS
        livre = verificar(matriz, L, C, cl, cc);

        if(livre == 1){
            inserir(matriz, cl, cc, bomba);
            //printf("\nBOMBA ADD\n");
        };
    }

    //VARRER CADA UMA DAS BOMBAS QUE FORAM INSERIDAS E ADICIONAR OS NODOS ADJACENTES
    for (int i = 0; i < L; i++) {
        p = matriz[i];
        cl = i;

        while (p != NULL) {
            if (p->val == bomba) {
                cc = p->col;
                inserirAdj(matriz, L, C, cl, cc);
            }
            p = p->prox;
        }
    }

    imprimir(matriz, L, C);
    liberar(matriz, L);
    return 0;
}