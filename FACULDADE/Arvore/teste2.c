#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int val, col;
    struct Nodo *prox;
}TNodo;

//INICIALIZAR A MATRIZ ESPARSA
void start(TNodo **m, int L){
    int i;

    for(i = 0; i < L; i++){
        m[L] = NULL;
    }
}

//LIBERA A MATRIZ ESPARSA
void liberar(TNodo **m, int L){
    TNodo *p;
    int i;

    for(i = 0; i < L; i++){
        for(p = m[L]; p != NULL; p = m[L]){
            m[L] = p->prox;
            free(p);
        }
    }
}

void imprimir(TNodo **m, int L, int C){
    TNodo *p;
    int i, j;

    for(i = 0; i < L; i++){
        p = m[L];

        for(j = 0; j < C; j++){
            if(p != NULL && p->col == j){
                if(p->val == -1){
                    printf("X "); //BOMBA
                } else {
                    printf("%d ", p->val);
                }
            }

            else
                printf("0 ");
        }
    }
}

void inserir(TNodo **m, int L, int C, int V){
    TNodo *novo, *p, *q;
    
    novo = (TNodo*)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->val = V;
    novo->col = C;
    p = m[L];
    q = NULL;

    if(p == NULL || C < p->col){
        novo->prox = p;
        m[L] = novo;
    } else {
        for(;p->prox->col < C && p->prox != NULL; p = p->prox);
        q = p->prox;
        p->prox = novo;
        novo->prox = q;
    }
}

void inserirAdj(TNodo **m, int L, int C, int cl, int cc){
    TNodo *novo, *p, *q;
    int i, j, achouNodo;

    for(i = cl - 1; i <= cl + 1; i++){
        for(j = cc - 1; j <= cc + 1; j++){
            if(0 <= i && i < L && 0 <= j && j < C && (i != cl || j != cc)){
                p = m[i];
                achouNodo = 0;

                while (p != NULL && achouNodo != 1)
                {
                    if(p->col == j){
                        if(p->val != -1){
                            p->val++;
                        }

                        achouNodo = 1;
                    }
                    p = p->prox;
                }

                if(achouNodo == 0){
                    novo = (TNodo *)malloc(sizeof(TNodo));

                    if(novo == NULL){
                        printf("ERRO DE ALOCAÇÃO.\n");
                        exit(1);
                    }

                    novo->val = 1;
                    novo->col = j;

                    p = m[i];
                    q = NULL;

                    if(p == NULL || j < p->col){
                        novo->prox = p;
                        m[i] = novo;
                    } else {
                        q = p->prox;
                        p->prox = novo;
                        novo->prox = q;
                    }
                }
                
            }
        }
    }
}

TNodo** transposta(TNodo **m, int L, int C){
    TNodo **novo, *p;
    int i;

    novo = (TNodo**)malloc(sizeof(TNodo) * C);

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    start(novo, C);

    for(i = 0; i < L; i++){
        for(p = m[i]; p != NULL; p = p->prox){
            inserir(novo, p->col, i, p->val);
        }
    }

    return novo;
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


int main(){
    int L, C, Nb, i, j, cl, cc, livre, bomba = -1;
    TNodo **matriz, **mt, *p;

    do {
        printf("DIGITE O NUMERO DE MAXLINHAS E MAXCOLUNAS:\n");
        scanf("%d %d", &L, &C);
    } while(!(0 <= L && L <= 100 && 0 <= C && C <= 100)); //VERIFICAÇÃO DO NUMERO DE MAXLINHAS E MAXCOLUNAS

    //ALOCAR DINAMICAMENTE A QUANTIDADE DE LINHAS QUE SERÃO UTILIZADAS NO PROGRAMA
    matriz = (TNodo**)malloc(sizeof(TNodo*) * L);

    if(matriz == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        return 0;
    } //VERIFICA SE ALOCOU O VETOR DE PONTEIROS DE TAMANHO L

    start(matriz, L);

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

        if(livre == 1){
            inserir(matriz, cl, cc, bomba);
            printf("\nBOMBA ADD\n");
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

    //mt = transposta(matriz, L, C);

    system("cls");

    printf("MATRIZ PADRAO.\n");
    imprimir(matriz, L, C);

    //printf("MATRIZ TRANSPOSTA.\n");
    //imprimir(mt, C, L);



    liberar(matriz, L);
    liberar(mt, C);
    return 0;
}