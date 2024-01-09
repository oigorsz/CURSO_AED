//EXEMPLO PILHA - INVERTER UMA FRASE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_FRASE 100



struct Tpilha {
    char vet[TAM_FRASE];
    int topo;
};

typedef struct Tpilha Tpilha;

Tpilha *novaPilha (){
    Tpilha *np = (Tpilha *)malloc(sizeof(Tpilha));
    if(np == NULL){
        printf("ERRO");
        exit(1);
    }
    np->topo = -1;
    return np;
}

int push(Tpilha *p, char c){
    if(p->topo >= TAM_FRASE - 1){
        return -1;
    }

    p->topo++;
    p->vet[p->topo] = c;
    return 0;
}

int pop(Tpilha *p, char *c){
    if(p->topo < 0){
        return -1;
    }

    *c = p->vet[p->topo];
    p->topo--;
    return 0;
}


int main(){
    int i, certo = 1;
    char frase[TAM_FRASE], c;
    Tpilha *pilha = novaPilha();

    system("cls");
    //PEDIR PARA O USUÁRIO DIGITAR UMA FRASE
    printf("DIGITE UMA FRASE:\n => ");
    fgets(frase, sizeof(frase), stdin);
    frase[strlen(frase) - 1] = '\0';

    //EMPILHAR OS CARACTERES DA FRASE
    for(i = 0; i < strlen(frase) && certo; i++){
        if(push(pilha, frase[i]) < 0){
            printf("ERRO PARA EMPILHAR.\n");
            certo = 0;
        }
    }
    //PRINTAR OS CARACTERES EM ORDEM INVERSA DA QUE FOI ESCRITA

    for(i = pilha->topo; i >= 0; i--){
        pop(pilha, &c);
        printf("%c", c);
    }

    free(pilha);
    return 0;
}