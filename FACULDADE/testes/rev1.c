#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
    int info;
    struct Pilha *prox;
}TPilha;

typedef TPilha *PPilha;

PPilha iniciarPilha(){
    return NULL;
}

void liberar(PPilha p){
    PPilha aux;

    for(aux = p; aux != NULL; aux = p){
        p = p->prox;
        free(aux);
    }
}

PPilha push(PPilha p, int v){
    PPilha novo = (PPilha)malloc(sizeof(TPilha));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        liberar(p);
        exit(1);
    }

    novo->info = v;
    novo->prox = p;
    return novo;
}

PPilha pop(PPilha p){
    PPilha aux;

    if(p == NULL){
        printf("PILHA VAZIA.\n");
        return p;
    }

    aux = p;
    p = p->prox;
    free(aux);

    return p;
}

void imprimir(PPilha p){
    PPilha aux;

    for(aux = p; aux != NULL; aux = aux->prox){
        printf("%d ", aux->info);
    }

    printf("\n");
}

int main(){
    int N, op;
    PPilha pilha = iniciarPilha();

    system("cls");

    do {
        printf("DIGITE 1 PARA ADICIONAR UM ELEMENTO DA PILHA.\n");
        printf("DIGITE 2 PARA REMOVER UM ELEMENTO DA PILHA.\n");
        printf("DIGITE 3 PARA IMPRIMIR A PILHA.\n");
        printf("DIGITE 0 PARA FINALIZAR.\n");

        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 1:
            printf("DIGITE O VALOR A SER ADICIONADO.\n");
            scanf("%d", &N);
            pilha = push(pilha, N);
            break;
        case 2:
            pilha = pop(pilha);
            break;
        case 3:
            imprimir(pilha);
            break;
        
        default:
            if(op != 0){
                printf("VALOR INVALIDO.\n");
            }
            break;
        }

    } while(op != 0);

    liberar(pilha);
    return 0;
}