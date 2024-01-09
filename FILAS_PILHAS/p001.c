#include <stdio.h>
#include <stdlib.h>

struct prato {
    char cor;
    struct prato * next;
};

typedef struct prato prato;

prato * pilha = NULL;

void add(char cor){
    prato *p = (prato*)malloc(sizeof(prato));
    p->cor = cor;
    p->next = pilha;
    pilha = p;
}

void imprimir(prato *pilha){
    printf("LISTA DE PRATOS.\n");

    prato * auxPrint = pilha;
    while(auxPrint != NULL)
    {
        printf("COR DO PRATO %c.\n", auxPrint->cor);
        auxPrint = auxPrint->next;
    }
}

void rem(){
    if(pilha == NULL){
        printf("PILHA VAZIA.\n");
    }else {
        pilha = pilha->next;
    }
}

int main(){
    system("cls");

    add('R');
    add('G');
    add('B');
    add('R');

    prato * auxPilha = pilha;

    imprimir(auxPilha);

    printf("\n");

    rem();

    auxPilha = pilha;

    imprimir(auxPilha);

    printf("\n");

    rem();

    auxPilha = pilha;

    imprimir(auxPilha);

    printf("\n");

    rem();

    auxPilha = pilha;

    imprimir(auxPilha);

    printf("\n");

    rem();

    auxPilha = pilha;

    imprimir(auxPilha);

    printf("\n");

    rem();

    auxPilha = pilha;

    imprimir(auxPilha);


    return 0;
}