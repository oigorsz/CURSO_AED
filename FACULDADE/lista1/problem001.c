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
            printf("DIGITE O NUMERO E O NOME DO CORREDOR:\n ");
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
        } while (encontrado == 1 || num <= 0);
    }
}

void ordenar(Corredor *p[], int Np){
    int i, j, encontrado, aux[Np];
    Corredor *newp[Np];

    for(i = 0; i < Np; i++){
        encontrado = 0;
        do {
            scanf("%d", &aux[Np]);

            for(j = 0; j < Np; j++){
                if(p[j]->numero == aux[i]){
                    encontrado = 1;
                } else {
                    encontrado = 0;
                }
            }
        } while(encontrado == 0 || aux[i] <= 0);
    }

    for(i = 0; i < Np; i++){
        for(j = 0; j < Np; j++){
            if(aux[i] == p[j]->numero){
                strcpy(newp[i]->nome, p[j]->nome);
                newp[i]->numero = p[j]->numero;
                newp[i]->pos = i;
            }
        }
    }

    p = newp;
}

void resultado (Corredor *p[], int Np){
    int i;

    for(i = 0; i < Np; i++){
        printf("%d- %d %s\n", i, p[i]->numero, p[i]->nome);
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
    int Np;

    do {
        printf("DIGITE O NUMERO DE PARTICIPANTES:\n => ");
        scanf("%d", &Np);
    } while(!(3 <= Np && Np <= 1000));

    Corredor **registro = (Corredor **)malloc(sizeof(Corredor *) * Np);

    if(registro == NULL){
        printf("ERRO DE MEMORIA");
        exit(1);
    }

    registrar(registro, Np);
    ordenar(registro, Np);
    resultado(registro, Np);
    limpar(registro, Np);
    
}