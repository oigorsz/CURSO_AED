#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Cliente {
    int id;
    int tempoA;
    struct Cliente *prox;
} TCliente;

typedef TCliente *PCliente;

typedef struct Caixas {
    int num;
    int tempoLivre;
    PCliente fila;
}TCaixas;

typedef TCaixas *PCaixas;

PCliente inicializarFila(){
    return NULL;
}

PCliente inserirCliente(PCliente fila, int id, int tempo){
    PCliente novo = (PCliente)malloc(sizeof(TCliente));
    PCliente temp;

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        return 0;
    }

    novo->id = id;
    novo->tempoA = tempo;
    novo->prox = NULL;

    if(fila == NULL){
        return novo;
    }

    temp = fila;

    for(;temp->prox != NULL; temp = temp->prox);
    temp->prox = novo;
    return novo;

}

void imprimir(PCaixas caixas, int A){
    int i;

    for(i = 0; i < A; i++){
        printf("%d: ", caixas[i].num);

        PCliente temp = caixas[i].fila;
        for(;temp != NULL; temp = temp->prox){
            printf("%d ", temp->id);
        }

        printf("\n");
    }
}

void liberar(PCaixas caixa, int A){
    int i;

    for(i = 0; i < A; i++){
        PCliente temp = caixa[i].fila;

        while (temp != NULL)
        {
            PCliente prox = temp->prox;
            free(temp);
            temp = prox;
        }
    }

    free(caixa);
}

int main(){
    int i, j, N, A, T, CMT, MTL;
    //N- NUMERO DE CLIENTES A-NUMERO DE ATENDENTES T- TEMPO DE ATENDIMENTO DO CLIENTE
    //CMT - CAIXA COM MENOR TEMPO MTL - MENOR TEMPO LIVRE

    PCaixas caixa;

    system("cls");

    //RECEBER O NUMERO DE CLIENTES E CAIXAS

    do {
        scanf("%d %d", &N, &A);
    } while(!(1 <= N && N <= 1023 && 1 <= A && A <= 25));


    //CRIAR A ESTRUTURA DE CAIXAS

    caixa = (PCaixas)malloc(sizeof(TCaixas) * A);

    if(caixa == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        return 0;
    }

    for(i = 0; i < A; i++){
        caixa[i].num = i + 1;
        caixa[i].fila = inicializarFila();
        caixa[i].tempoLivre = 0;
    }

    //INSERIR OS CLIENTES NOS CAIXAS

    for(i = 0; i < A; i++){

        do {
            scanf("%d", &T);
        } while (!(0 <= T && T <= 1000));

        // Encontrar o caixa com o tempo livre mais cedo
        CMT = 0;
        MTL = caixa[0].tempoLivre;

        for(j = 1; j < A; j++){
            if(caixa[j].tempoLivre < MTL){
                CMT = j;
                MTL = caixa[j].tempoLivre;
            }
        }

        // Inserir o cliente na fila do caixa selecionado

        caixa[CMT].fila = inserirCliente(caixa[CMT].fila, i + 1, T);

        // Atualizar o tempo livre do caixa

        caixa[CMT].tempoLivre += T;
        
    }

    imprimir(caixa, N);
    liberar(caixa, N);

    return 0;
}