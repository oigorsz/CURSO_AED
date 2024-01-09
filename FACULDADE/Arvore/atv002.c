#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int val, col;
    struct Nodo *prox;
}TNodo;

void start(TNodo **m, int l){
    int i;

    for(i = 0; i < l; i++){
        m[i] = NULL;
    }
}

void liberar(TNodo **m, int l){
    TNodo *p;
    int i;

    for(i = 0; i < l; i++){
        for(p = m[i]; p != NULL; p = m[i]){
            m[i] = p->prox;
            free(p);
        }
    }
}

void imprimir(TNodo **m, int l, int c){
    TNodo *p;
    int i, j;

    for(i = 0; i < l; i++){
        p = m[i];

        for(j = 0; j < c; j++){
            if(p != NULL && p->col == j){
                printf("%d\t", p->val);
                p = p->prox;
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }

    printf("\n");
}

void inserir(TNodo **m, int cl, int cc, int val){
    TNodo *novo, *p, *q;

    novo = (TNodo*)malloc(sizeof(TNodo));
    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->col = cc;
    novo->val = val;
    p = m[cl];
    q = NULL;

    if(p == NULL || cc < p->col){
        novo->prox = p;
        m[cl] = novo;
    } else {
        for(;p->prox != NULL && p->prox->col < cc; p = p->prox);
        q = p->prox;
        p->prox = novo;
        novo->prox = q;
    }
}

int verificar(TNodo **m, int l, int c, int cl, int cc){
    TNodo *p;

    if(!(0 <= cl && cl < l && 0 <= cc && cc < c)){
        return 0; //CORDENADAS FORA DO INTERVALO
    }

    for(p = m[cl]; p != NULL; p = p->prox){
        if(p->col == cc){
            return 0; //CORDENADA JÁ OCUPADA
        }
    }

    return 1;
}

int identidade(TNodo **m, int l, int c){
    TNodo *p;
    int i;

    if(l != c)
        return 0; //A MATRIZ PRECISA SER QUADRADA

    for(i = 0; i < l; i++){
        for(p = m[i]; p != NULL; p = p->prox){
            if(p->col != i){
                return 0;
            }
        }
    }

    return 1;
}

int iguais(TNodo **m1, TNodo **m2, int l1, int l2, int c1, int c2){
    if (l1 != l2 || c1 != c2)
        return 0; // Se o tamanho não for igual, as matrizes são diferentes

    for (int i = 0; i < l1; i++) {
        TNodo *p = m1[i];
        TNodo *q = m2[i];

        while (p != NULL && q != NULL) {
            if (p->col != q->col || p->val != q->val)
                return 0; // Se uma coluna ou valor for diferente, as matrizes são diferentes

            p = p->prox;
            q = q->prox;
        }

        // Se uma matriz tem mais elementos do que a outra, elas são diferentes
        if (p != NULL || q != NULL)
            return 0;
    }

    return 1; // Se nenhuma diferença foi encontrada, as matrizes são iguais
}



TNodo **somar(TNodo **m1, TNodo **m2, int l1, int c1, int l2, int c2){
    TNodo **novo, *p, *q;
    int i, j, soma;

    if(l1 != l2 || c1 != c2){
        return NULL;
    }

    novo = (TNodo **)malloc(sizeof(TNodo *) * l1);
    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    start(novo, l1);

    for(i = 0; i < l1; i++){
        p = m1[i];
        q = m2[i];

        for(j = 0; j < c1; j++){
            soma = 0;
           // Verifica se p e q não são nulos e têm a mesma coluna
            if (p != NULL && p->col == j) {
                soma += p->val;
                p = p->prox;
            }
            if (q != NULL && q->col == j) {
                soma += q->val;
                q = q->prox;
            }

            if(soma != 0){
                inserir(novo, i, j, soma);
            }
        }
    }

    return novo;
}


TNodo **transposta(TNodo **m, int l, int c){
    TNodo **novo, *p;
    int i;

    novo = (TNodo **)malloc(sizeof(TNodo *) * c);
    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    start(novo, c);

    for(i = 0; i < l; i++){
        for(p = m[i]; p != NULL; p = p->prox){
            inserir(novo, p->col, i, p->val);
        }
    }

    return novo; //RETORNA A MATRIZ ESPARSA COMO UMA TRANSPOSTA
}

/*void somarLinha(TNodo **m, int cl, int c, int val){
    TNodo *p;
    int j;

    p = m[cl];

    for(j = 0; j < c; j++){
        if(p != NULL && p->col == j){
            p->val = p->val + val;
            p = p->prox;
        } else {
            inserir(&m, cl, j, val);
        }
    }
}*/


/*void somarLinha(TNodo **m, int cl, int val){
    TNodo *p;

    for(p = m[cl]; p != NULL; p = p->prox){
        p->val = p->val + val;
    }
}*/

/*void somarColuna(TNodo **m, int l, int cc, int val){
    TNodo *p;
    int i;

    for(i = 0; i < l; i++){
        for(p = m[l]; p != NULL && p->col != cc; p = p->prox);
        p->val = p->val + val;
    }

}*/

int main(){
    TNodo **m1, **m2, **m1t, **m2t, **ms;
    int l1, c1, l2, c2, cl, cc, val = 1, op, livre;

    system("cls");

    do {
        printf("DIGITE A QUANTIDADE DE LINHAS E COLUNAS DA MATRIZ 1\n => ");
        scanf("%d %d", &l1, &c1);
    } while (!(0 <= l1 && l1 <= 100 && 0 <= c1 && c1 <= 100));

    system("cls");

    do {
        printf("DIGITE A QUANTIDADE DE LINHAS E COLUNAS DA MATRIZ 2\n => ");
        scanf("%d %d", &l2, &c2);
    } while (!(0 <= l2 && l2 <= 100 && 0 <= c2 && c2 <= 100));

    m1 = (TNodo **)malloc(sizeof(TNodo *) * l1);
    m2 = (TNodo **)malloc(sizeof(TNodo *) * l2);
    
    if(m1 == NULL || m2 == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    start(m1, l1);
    start(m2, l2);
    
    system("cls");

    do {
        printf("MATRIZ 1\n");
        printf("1) ADICIONAR NODO\n");
        printf("0) FINALIZAR\n");
        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 1:
            printf("DIGITE AS CORDENADAS: ");
            scanf("%d %d", &cl, &cc);
            livre = verificar(m1, l1, c1, cl, cc);

            if(livre == 1){
                inserir(m1, cl, cc, val);
                printf("VALOR INSERIDO\n");
            }
            break;
        
        default:
            if(op != 0)
                printf("VALOR INVALIDO.\n");
            break;
        }
    } while (op != 0);

    system("cls");

    do {
        printf("MATRIZ 2\n");
        printf("1) ADICIONAR NODO\n");
        printf("0) FINALIZAR\n");
        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 1:
            printf("DIGITE AS CORDENADAS: ");
            scanf("%d %d", &cl, &cc);
            livre = verificar(m2, l2, c2, cl, cc);

            if(livre == 1){
                inserir(m2, cl, cc, val);
                printf("VALOR INSERIDO\n");
            }
            break;
        
        default:
            if(op != 0)
                printf("VALOR INVALIDO.\n");
            break;
        }
    } while (op != 0);

    system("cls");

    m1t = transposta(m1, l1, c1);
    m2t = transposta(m2, l2, c2);
    ms = somar(m1, m2, l1, c1, l2, c2);

    printf("MATRIZ 1 \n");
    if(identidade(m1, l1, c1) == 1)
        printf("IDENTIDADE\n");
    imprimir(m1, l1, c1);
    

    printf("MATRIZ 1 TRANSPOSTA\n");
    if(identidade(m1t, c1, l1) == 1)
        printf("IDENTIDADE\n");
    imprimir(m1t, c1, l1);

    printf("MATRIZ 2\n");
    if(identidade(m2, l2, c2) == 1)
        printf("IDENTIDADE\n");
    imprimir(m2, l2, c2);

    printf("MATRIZ 2 TRANSPOSTA\n");
    if(identidade(m2t, c2, l2) == 1)
        printf("IDENTIDADE\n");
    imprimir(m2t, c2, l2);

    printf("SOMA M1 + M2\n");
    if(ms == NULL){
        printf("SOMA IMPOSSIVEL");
    } else {
        imprimir(ms, l1, c1);
    }


    liberar(m1, l1);
    liberar(m2, l2);
    liberar(m1t, c1);
    liberar(m2t, c2);
    liberar(ms, l1);
    return 0;
}

