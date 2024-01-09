#include <stdio.h>
#include <stdlib.h>

struct pessoa {
    int senha;
    struct pessoa * next;
};

typedef struct pessoa pessoa;

pessoa *fila = NULL;

void adicionar(int senha){
    pessoa *p = (pessoa*)malloc(sizeof(pessoa));
    p->senha = senha;
    p->next = NULL;

    if(fila == NULL){
        fila = p;
    } else {
        pessoa *auxFila = fila;
        while(auxFila->next != NULL){
            auxFila = auxFila->next;
        }

        auxFila->next = p;
    }
}

void imprimir(pessoa * fila){
    if(fila != NULL){
        printf("SENHA DA PESSOA: %d.\n", fila->senha);
        imprimir(fila->next);
    }
}

void rem(){
    if(fila == NULL){
        printf("FILA VAZIA.\n");
    } else {
        fila = fila->next;
    }
}

int main(){
    system("cls");


    adicionar(1);
    adicionar(2);
    adicionar(3);
    adicionar(4);

    printf("FILA:\n");
    imprimir(fila);

    printf("\n");
    rem();
    
    printf("FILA:\n");
    imprimir(fila);

    printf("\n");
    rem();
    
  
    printf("FILA:\n");
    imprimir(fila);

    printf("\n");
    rem();
    

    printf("FILA:\n");
    imprimir(fila);


    return 0;
}