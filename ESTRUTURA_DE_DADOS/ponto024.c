#include <stdio.h>
#include <stdlib.h>

struct lista {
    int valor;
    struct lista *proximo;
};

struct lista *buscarValor(struct lista *pLista, int valorInformado){
    while(pLista != NULL){
        if(pLista->valor == valorInformado){
            return pLista;
        } else {
            pLista = pLista->proximo;
        }
    }

    return NULL;
}

int main(){
    system("cls");

    int valorInformado;

    printf("DIGITE UM VALOR:\n => ");
    scanf("%d", &valorInformado);

    struct lista m1, m2, m3;
    struct lista *resultado, *gancho = &m1;

    m1.valor = 14;
    m2.valor = 18;
    m3.valor = 17;

    m1.proximo = &m2;
    m2.proximo = &m3;
    m3.proximo = NULL;

    resultado = buscarValor(gancho, valorInformado);

    if(resultado == NULL){
        printf("VALOR NÃO ENCONTRADO.\n");
    } else {
        printf("VALOR ENCONTRADO %d.\n", *resultado);
    }

    return 0;
}