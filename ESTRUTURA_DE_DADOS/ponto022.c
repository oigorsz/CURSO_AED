#include <stdio.h>

struct lista {
    int valor;
    struct lista *proximo;
};

typedef struct lista lista;

int main(){
    lista l1, l2, l3;
    lista *gancho = &l1;

    l1.valor = 10;
    l2.valor = 20;
    l3.valor = 30;

    l1.proximo = &l2;
    l2.proximo = &l3;
    l3.proximo = NULL;

    while (gancho != NULL)
    {
        printf("%d", gancho->valor);
        gancho = gancho ->proximo;
    }
    

    return 0;
}