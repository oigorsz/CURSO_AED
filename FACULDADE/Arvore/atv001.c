//IMPLEMENTAÇÃO DE MATRIZ ESPARSA

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor, coluna;
    struct Nodo *prox;
}TNodo;

//INICIALIZAR MATRIZ ESPARSA
void start(TNodo **m, int L){
    int i;

    for(i = 0; i < L; i++){
        m[i] = NULL;
    }
}

void imprimir(TNodo **m, int L, int C){
    TNodo *p;
    int i, j;

    for(i = 0; i < L; i++){
        p = m[i];

        for(j = 0; j < C; j++){
            if(p != NULL && p->coluna == j){
                printf("%d\t", p->valor); 
                p = p->prox;
            }
            else {
                printf("0\t");
            } 
        }

        printf("\n");
    }

    printf("\n");
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


//FUNÇÃO DE INSERIR NODOS
void inserir(TNodo **m, int L, int C, int V){
    //CRIAR UM NOVO NODO
    TNodo *novo, *p, *q;

    novo = (TNodo *)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->coluna = C;
    novo->valor = V;

    p = m[L];
    q = NULL;

    //ALOCAR O NOVO NODO

    if(p == NULL || C < p->coluna){
        novo->prox = p;
        m[L] = novo;
    } else {
        for(;p->prox != NULL && p->prox->coluna < C; p = p->prox);
        q = p->prox;
        p->prox = novo;
        novo->prox = q;
    }
}

int verificar(TNodo **m, int L, int C, int cl, int cc){
    TNodo *p;

    if(!(0 <= cl && cl < L && 0 <= cc && cc < C)){
        return 0;
    }

    for(p = m[cl]; p != NULL; p = p->prox){
        if(p->coluna == cc && p->valor == 1){
            return 0;
        }
    }

    return 1;
}

TNodo ** tranposta(TNodo **mt, TNodo **m, int L, int C){
    TNodo *p;
    int i;

    for(i = 0; i < L; i++){
        for(p = m[i]; p != NULL; p = p->prox){
            inserir(mt, p->coluna, i, p->valor);
        }
    }

    return mt;
}

TNodo ** somar(TNodo **m, int l1, TNodo **mt, int l2){

}


int main(){
    TNodo **m, **mt, **ms;
    int op, valor, livre, L, C, cl, cc;

    system("cls");

    do {
        printf("DIGITE O NUM LINHAS E NUM COLUNAS DA MATRIZ.\n");
        scanf("%d %d", &L, &C);
    } while(!(0 <= L && L <= 100 && 0 <= C && C <= 100));

    //ALOCAR MEMORIA DA MATRIZ ESPARSA
    m = (TNodo **)malloc(sizeof(TNodo *) * L);

    if(m == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    start(m, L);

    mt = (TNodo **)malloc(sizeof(TNodo *) * C);

    if(mt == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    start(mt, C);

    ms = (TNodo **)malloc(sizeof(TNodo *) * L);

    if(ms == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    start(ms, L);
    system("cls");

    do {
        printf("1) ADICIONAR NODO\n");
        printf("2) IMPRIMIR MATRIZ\n");
        printf("3) TRANSPOSTA\n");
        printf("4) SOMAR\n")/
        printf("0) ENCERRAR\n");
        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 1:
            printf("CORDENADAS DE ADD: ");
            scanf("%d %d", &cl, &cc);
            livre = verificar(m, L, C, cl, cc);

            if (livre == 1){
                //CONDIÇÃO VALIDA
                printf("VALOR ADICIONADO.\n");
                inserir(m, cl, cc, 1);
            } else {
                printf("NAO ADD.\n\n");
            }

            break;
        case 2:
            printf("MATRIZ ESPARSA.\n");
            imprimir(m, L, C);
            break;
        case 3:
            printf("MATRIZ TRANSPOSTA.\n");
            mt = tranposta(mt, m, L, C);
            imprimir(mt, C, L);
            break;

        case 4:
            printf("M1 + M2.\n");
            ms = soma(mt, m, L, C);
            imprimir(ms, L, C);
            break;
        
        default:
            if(op != 0){
                printf("VALOR INVALIDO.\n");
            }
            break;
        }

        
    } while(op != 0);

    printf("PROGRAMA ENCERRADO.\n");
    liberar(m, L);
    liberar(mt, C);
    liberar(ms, L);
    return 0;
}