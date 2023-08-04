#include <stdio.h>
#include <stdlib.h>

struct ponto {
    float x;
    float y;
    struct ponto *next;
};

typedef struct ponto Ponto;

Ponto *listaPontos;

void add(float x, float y){
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    p->next = listaPontos;
    listaPontos = p;
}

void imprimir(){
    Ponto *auxiliar = listaPontos;
    while (auxiliar != NULL)
    {
        printf("\n%.1f e %.1f", auxiliar->x, auxiliar->y);
        auxiliar = auxiliar->next;
    }
    
}


int main(){
    add(1,5);
    add(3,4);

    imprimir();

    return 0;
}