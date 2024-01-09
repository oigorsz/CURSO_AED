#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM_MAX 1023

typedef struct Nodo {
    char caracter;
    int num;
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


int main(){
    char string[TAM_MAX], caracter;
    int i, NumAux, tamanho = 0,  N = 0, valido = 0; //TAMANHO DA STRING ORIGINAL
    PNodo lista1 = iniciarLista(); //LISTA DE SUBTRINGS COM RUIDOS


    //RECEBER A STRING ORIGINAL
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
    liberar(lista1);

    return 0;
}