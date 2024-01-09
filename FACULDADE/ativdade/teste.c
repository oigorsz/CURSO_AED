//IGOR DE SOUZA MONTEIRO

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

PNodo addFim(PNodo l, int v, char letra){
    PNodo novo, aux;
    novo = (PNodo)malloc(sizeof(TNodo));

    if(novo == NULL){
        exit(1);
    }

    novo->num = v;
    novo->caracter = letra;
    novo->prox = NULL;

    if(l == NULL){
        //lista vazia
        novo->ant = NULL;
        return novo;
    } else {
        for(aux = l; aux->prox != NULL; aux = aux->prox);
        novo->ant = aux;
        aux->prox = novo;
    }

    return l;
}

PNodo removerNodo(PNodo l, PNodo no) {
    if (l == NULL || no == NULL) {
        //lista vazia ou nó inválido
        return l;
    }

    if (l == no) {
        l = no->prox;  // Atualiza o início da lista
        if (no->prox != NULL) {
            no->prox->ant = NULL; 
        }
        no->prox = NULL;  
    } else {
       
        if (no->prox != NULL) {
            no->prox->ant = no->ant;  // Atualize o nó anterior ao próximo nó
        }

        if (no->ant != NULL) {
            no->ant->prox = no->prox;  // Atualize o próximo nó do nó anterior
        }
        no->prox = no->ant = NULL;  // Aponta para NULL antes de liberar
    }

    free(no);  // Libere o nó removido da memória
    return l;  // Retorne a lista atualizada
}


PNodo removerRuido(PNodo l) {
    if (l == NULL) {
        return l;
    }

    PNodo aux = l;
    PNodo proximo;

    while (aux != NULL) {
        proximo = aux->prox;  
        if (aux->num == 1) {
            if (aux->ant != NULL && aux->prox != NULL) {
                if (aux->ant->num >= 2 && aux->prox->num >= 2) {
                    if (aux->ant->num >= aux->prox->num) {
                        aux->ant->num++;
                        l = removerNodo(l, aux);
                    } else {
                        aux->prox->num++;
                        l = removerNodo(l, aux);
                    }
                }
            } else if (aux->ant == NULL && aux->prox != NULL && aux->prox->num >= 2) {
                aux->prox->num++;
                l = removerNodo(l, aux);
            } else if (aux->ant != NULL && aux->prox == NULL && aux->ant->num >= 2) {
                aux->ant->num++;
                l = removerNodo(l, aux);
            }
        }

        aux = proximo;  // Atualize o aux para o próximo nó
    }

    return l;
}


void imprimir(PNodo l, int tamanho){
    PNodo aux;

    printf("%d\n", tamanho);

    for(aux = l; aux != NULL; aux = aux->prox){
        printf("%d%c", aux->num, aux->caracter);
    }
}

void liberar(PNodo l){
    PNodo aux;

    for(aux = l; aux != NULL; aux = l){
        l = l->prox;
        free(aux);
    }
}

int tamString(PNodo l){
    PNodo aux;
    int count = 0;

    for(aux = l; aux != NULL; aux = aux->prox){
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

int apenasCaps(char str[]) {
    int i;

    for ( i = 0; str[i] != '\0'; i++) {
        if (!isupper(str[i])) {
            return 0;  // Contém caracteres que não são maiúsculas
        }
    }
    return 1;  // Todas as letras são maiúsculas
}

int main(){
    char string[TAM_MAX], caracter;
    int N, i, numCaracter, valido = 0, tamanho = 0;
    PNodo lista = iniciarLista();

    do {
        scanf("%s", string);
        N = strlen(string);
        valido = apenasCaps(string);
    } while(!(2 <= N && N <= 1023) || valido == 0);

    //PROCEDIMENTO PARA A LISTA 1
    numCaracter = 1;
    caracter = string[0];


    for(i = 1; i < N; i++){
        if(string[i] == caracter){
            numCaracter++;
        } else {
            lista = addFim(lista, numCaracter, caracter);
            numCaracter = 1;
            caracter = string[i];
        }
    }
    
    lista = addFim(lista, numCaracter, caracter);
    tamanho = tamString(lista);
    imprimir(lista, tamanho);

    printf("\n");

    //SEGUNDA PARTE

    lista = removerRuido(lista);
    tamanho = tamString(lista);
    imprimir(lista, tamanho);


    liberar(lista);
    
    return 0;
}