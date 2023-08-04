#include <stdio.h>
#include <stdlib.h>

struct Coordenadas {
    float x;
    float y;
    struct Coordenadas * proximo;
};

typedef struct Coordenadas Ponto;

Ponto * listaPontos;

void add(float x, float y){
    Ponto *novoPonto = (Ponto*)malloc(sizeof(Ponto));
    novoPonto -> x = x;
    novoPonto -> y = y;
    novoPonto -> proximo = NULL;
    listaPontos = novoPonto;
}

void imprimir()
{
    Ponto *auxLista = listaPontos;
    while(auxLista != NULL)
    {
        printf("Ponto(%.1f, %.1f)", auxLista->x, auxLista->y);
        auxLista = auxLista-> proximo;
    }
}

int main(){
    add(10, 5);
    add(15,20);
    
    imprimir();
    
    return 0;
}