// IGOR DE SOUZA MONTEIRO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 21

struct Corredor {
    char nome[TAM_NOME];
    int numero;
};

typedef struct Corredor Corredor;

void limpar(Corredor *p[], int Np){
    int i;

    for(i = 0; i < Np; i++){
        free(p[i]);
    }

    free(p);
}

void registrar(Corredor *p[], int Np){
    int i, j, encontrado;

    for(i = 0; i < Np; i++){
        p[i] = (Corredor *)malloc(sizeof(Corredor));

        if(p[i] == NULL){
            exit(1);
        }

        encontrado = 0;

        do {
            scanf("%d %s", &p[i]->numero, &p[i]->nome);

            encontrado = 0;

            for(j = 0; j < i; j++){
                if(p[i]->numero == p[j]->numero || strcmp(p[i]->nome, p[j]->nome) == 0){
                    encontrado = 1;
                }
            }

        } while(p[i]->numero <= 0 || strlen(p[i]->nome) > 20 || encontrado == 1);
        
    }
}

void ordenar(Corredor *p[], int Np){
   int i, j, valido, numero;
   Corredor **newP;

   newP = (Corredor**)malloc(Np * sizeof(Corredor*));
   if(newP == NULL){
        printf("[ERRO]");
        exit(1);
    }

   for(i = 0; i < Np; i++){
        newP[i] = (Corredor*)malloc(sizeof(Corredor));
        valido = 1;
        
        if(newP[i] == NULL){
            printf("[ERRO]");
            exit(1);
        }

        for(i = 0; i < Np; i++){
            newP[i] = (Corredor*)malloc(sizeof(Corredor));
            
            if(newP[i] == NULL){
                exit(1);
            }

            scanf("%d", &newP[i]->numero);
            //VERIFICAR
        }

        for(i = 0; i < Np; i++){
            for(j = 0; j < Np; j++){
                if(p[j]->numero == newP[i]->numero){
                    strcpy(newP[i]->nome, p[j]->nome);
                }
            }
        }

        for(i = 0; i < Np; i++){
            p[i]->numero = newP[i]->numero;
            strcpy(p[i]->nome, newP[i]->nome);
        }

        limpar(newP, Np);
   }
}

void ultrapassagem(Corredor *p[], int i) {
    Corredor *aux = p[i];
    p[i] = p[i - 1];
    p[i - 1] = aux;
}

void reorndenar(Corredor *p[], int Np){
    int i, numCorredor;

    do {
        scanf("%d", &numCorredor);

        for(i = 0; i < Np; i++){
            if(p[i]->numero == numCorredor && i != 0){
                ultrapassagem(p, i);
            }
        }
    } while(numCorredor != - 1);
}


void resultado(Corredor *p[], int Np){
    int i;

    for(i = 0; i < 3; i++){
        printf("%d %s\n", p[i]->numero, p[i]->nome);
    }
}


int main(){
    int Np;
    Corredor **registro;

    //SOLICITAR O NUMERO DE COMPETIDORES (ENTRE 3 E 1000)

    do {
        scanf("%d", &Np);
    } while(!(3 <= Np && Np <= 1000));

    //FAZER ALOCAÇÃO DINAMICA DO VETOR DE STRUCT

    registro = (Corredor**)malloc(Np * sizeof(Corredor*));
    if(registro == NULL){
        exit(1);
    }

    //REGISTRAR COMPETIDORES
    registrar(registro, Np);
    //ORDENAR COMPETIDORES
    ordenar(registro, Np);
    //REORDENAR COMPETIDORES
    reorndenar(registro, Np);
    //RESULTADO FINAL
    resultado(registro, Np);
    //LIMPAR VETOR DE STRUCT
    limpar(registro, Np);

    return 0;
}