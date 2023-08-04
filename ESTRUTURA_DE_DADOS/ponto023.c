#include <stdio.h>
#include <stdlib.h>

struct lista {
    int valor;
    struct lista *proximo;
};

struct lista *procurarValor(struct lista *pLista, int valorDigitado){
    while(pLista != NULL){
        if (pLista->valor == valorDigitado){
            return pLista;
        } else {
            pLista = pLista->proximo;
        }
    }

    return  NULL;
}

int main(){
    system("cls");

    int valorDigitado;

    printf("DIGITE UM VALOR:\n => ");
    scanf("%d", &valorDigitado);

    struct lista m1, m2, m3;
    struct lista *resultado, *gancho = &m1;

    m1.valor = 10;
    m2.valor = 15;
    m3.valor = 18;

    m1.proximo = &m2;
    m2.proximo = &m3;
    m3.proximo = NULL;

    resultado = procurarValor(gancho, valorDigitado);


    if(resultado != NULL){
        printf("VALOR ENCONTRADO %d\n", *resultado);
    } else {
        printf("VALOR NÃO ENCONTRADO.\n");
    }

    return 0;
}