//IGOR DE SOUZA MONTEIRO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 21


struct Corredor {
    int numero;
    char nome[TAM_NOME];
    int pos;
};

typedef struct Corredor Corredor;

void registrar(Corredor *p[], int Np){
    int i, j, num, encontrado;
    char nome[TAM_NOME];

    for(i = 0; i < Np; i++){
        p[i] = (Corredor *)malloc(sizeof(Corredor));
        encontrado = 0;

        do {
            printf("DIGITE O NUMERO E O NOME DO PARTICIPANTE:\n");
            scanf("%d %s", &num, nome);

            encontrado = 0;

            if(i > 0){
                for(j = 0; j < i; j++){
                    if(p[j]->numero == num){
                        encontrado = 1;
                    }
                }
            } else {
                encontrado = 0;
            }

            if(!encontrado){
                    p[i]->numero = num;
                    strcpy(p[i]->nome, nome);
            }

        } while(encontrado == 1 || num < 0);
    }
}

void ordenar(Corredor *p[], int Np){
    int i, j, encontrado, aux[Np];
    Corredor *newP[Np];

    printf("DIGITE A ORDEM DESEJADA:\n => ");

    for(i = 0; i < Np; i++){
        scanf("%d", &aux[i]);
    }

    for(i = 0; i < Np; i++){
        for(j = 0; j < Np; j++){
            if(aux[i] == p[j]->numero){
                strcpy(newP[i]->nome, p[j]->nome);
                newP[i]->pos = i;
                newP[i]->numero = p[j]->numero;
            }
        }
    }

    for(i = 0; i < Np; i++){
        strcpy(p[i]->nome, newP[i]->nome);
        p[i]->pos = newP[i]->pos;
        p[i]->numero = newP[i]->numero;
    }
}


void ultrapassagem(Corredor *p[],int  Np, int i){
    int j, temp;
    for(j = 0; j < Np; j++){
        if(p[i]->pos == p[j]->pos + 1){
            temp = p[i]->pos;
            p[i]->pos =  p[j]->pos;
            p[j]->pos = temp;
        }
    }
}


void reordenar(Corredor *p[], int Np){
    int i, j, numero, temp;

    do {
        printf("DIGITE O NUMERO DO CARRO QUE FARÁ UMA ULTRAPASSAGEM.\n");
        printf("DIGITE -1 PARA ENCERRAR A CORRIDA:\n");
        scanf("%d", &numero);

        for(i = 0; i < Np; i++){
            if(p[i]->numero == numero && p[i]->pos != 0){
                ultrapassagem(p, Np, i);
            }
        }

    } while (!(numero == -1));

}

void resultado(Corredor *p[], int Np){
    int i, posicao = 1;
    
    for(i = 0; i < Np; i++){
        printf("%d %d %s\n", posicao, p[i]->numero, p[i]->nome);
        posicao++;
    }
}


void limpar(Corredor *p[], int Np){
    int i;

    for(i = 0; i < Np; i++){
        free(p[i]);
    }

    free(p);
}

int main(){
    int Np, op;

    system("cls");

    do {
        printf("DIGITE O NUMERO DE PARTICIPANTES:\n => ");
        scanf("%d", &Np);
    } while(!(3 <= Np && Np <= 1000));

    Corredor **registro = (Corredor **)malloc(sizeof(Corredor *) * Np);

    if(registro == NULL){
        printf("[ERRO]");
        exit(1);
    }

    registrar(registro, Np);

    ordenar(registro, Np);

    //reordenar(registro, Np);

    resultado(registro, Np);

    limpar(registro, Np);

    return 0;
}
