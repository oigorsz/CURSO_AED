//IGOR DE SOUZA MONTEIRO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_MAX 1023

typedef struct Nodo{
    int num;
    char caracter;
    struct Nodo *prox;
    struct Nodo *ant;
}TNodo;

typedef TNodo *PNodo;

PNodo iniciarLista(){
    return NULL;
}

PNodo addFim(PNodo l, int num, char letra){
    PNodo novo, aux;
    novo = (PNodo)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->num = num;
    novo->caracter = letra;
    novo->prox = NULL;

    if(l == NULL){
        novo->ant = NULL;
        l = novo;
    } else {
        for(aux = l; aux->prox != NULL; aux = aux->prox);
        novo->ant = aux;
        aux->prox = novo;
    }

    return l;
}

void imprimir(PNodo l, int N){
    PNodo aux;

    printf("%d\n", N);

    for(aux = l; aux != NULL; aux = aux->prox){
        printf("%d%c", aux->num, aux->caracter);
    }

    printf("\n");
}

void liberar(PNodo l){
    PNodo aux;

    for(aux = l; aux != NULL; aux = l){
        l = l->prox;
        free(aux);
    }
}

int apenasMaiusculos(char str[]){
    int i;
    for(i = 0; i < strlen(str); i++){
        if(isalpha(str[i]) == 0 || isupper(str[i]) == 0){
            return 0;
        }
    }

    return 1;
}

PNodo removerNodo(PNodo l, PNodo no) {

    if (l == no) {
        l = no->prox;
        if (no->prox != NULL) {
            no->prox->ant = NULL;
        }
    } else {
        if (no->prox != NULL) {
            no->prox->ant = no->ant;
        }

        if (no->ant != NULL) {
            no->ant->prox = no->prox;
        }
    }

    free(no);
    return l;
}

PNodo removerRuido(PNodo l){
    PNodo aux;

    if(l == NULL){
        printf("LISTA VAZIA.\n");
        return l;
    }


    for(aux = l; aux != NULL; aux = aux->prox){
        if(aux->num == 1){
            if(aux->ant != NULL && aux->prox != NULL && aux->prox->num >= 2 && aux->ant->num >= 2){
                if(aux->ant->num > aux->prox->num){
                    aux->ant->num++;
                } else if(aux->ant->num < aux->prox->num){
                    aux->prox->ant++;
                } else {
                    aux->ant->num++;
                }

                l = removerNodo(l, aux);
            } else if(aux->ant == NULL && aux->prox != NULL && aux->prox->num >= 2){
                aux->prox->num++;
                l = removerNodo(l, aux);
            } else if(aux->ant != NULL && aux->prox == NULL && aux->ant->num >= 2){
                aux->ant->num++;
                l = removerNodo(l, aux);
            }
        }
    }
    
    
    return l;
}


int tamString(PNodo l) {
    PNodo aux;
    int count = 0;

    for (aux = l; aux != NULL; aux = aux->prox) {
        if(aux->num < 10){
            count += 2;
        } else if(aux->num < 100){
            count += 3;
        } else if(aux->num < 1000){
            count += 4;
        } else {
            count += 5;
        }
    }

    return count;
}



int main(){
    char string[TAM_MAX], caracter;
    int i, NumAux, tamanho = 0,  N = 0, valido = 0; //TAMANHO DA STRING ORIGINAL
    PNodo lista1 = iniciarLista(); //LISTA DE SUBTRINGS COM RUIDOS

    do {
        scanf("%s", string);
        N = strlen(string);
        valido = apenasMaiusculos(string);
    } while(!(2 <= N && N <= 1023) || valido == 0);

    //PROCEDIMENTO PARA A LISTA 1
    NumAux = 1;
    caracter = string[0];


    for(i = 1; i < N; i++){
        if(string[i] == caracter){
            NumAux++;
        } else {
            lista1 = addFim(lista1, NumAux, caracter);
            NumAux = 1;
            caracter = string[i];
        }
    }

   
    lista1 = addFim(lista1, NumAux, caracter);
    tamanho = tamString(lista1);
    imprimir(lista1, tamanho);

    //TUDO ACIMA TRABALHA COM A LISTA COM RUIDOS

    lista1 = removerRuido(lista1);
    tamanho = tamString(lista1);
    imprimir(lista1, tamanho);

    liberar(lista1);
    
    return 0;
}