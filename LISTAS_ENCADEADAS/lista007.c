//LISTA ENCADEADA COM ELEMENTOS SENDO ADICIONADOS NO COMEÇO DA LISTA
#include <stdio.h>
#include <stdlib.h>

struct Ponto {
    float x;
    float y;
    struct Ponto * next;
};

typedef struct Ponto Ponto;

Ponto *listaPontos;

void adicionar(float x, float y){
    Ponto *p = (Ponto*)malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    p->next = listaPontos;
    listaPontos = p;
}

void imprimir(Ponto * listaPontos){
    system("cls");
    Ponto * auxiliar = listaPontos;

    while(auxiliar != NULL){
        printf("(%.1f, %.1f)\n", auxiliar->x, auxiliar->y);
        auxiliar = auxiliar->next;
    }

    printf("\n");
    
}


int main(){
    int choice;
    float valueX, valueY;
    
    while(1){
        printf("DIGITE 1 PARA IMPRIMIR A LISTA.\n");
        printf("DIGITE 2 PARA ADICIONAR UM NOVO VALOR.\n");
        printf("DIGITE 0 PARA ENCERRAR.\n");
        scanf("%d", &choice);


        if(choice == 2){
            system("cls");
            printf("CRIANDO NOVO PONTO\n");
            printf("DIGITE O VALOR DE X:\n");
            scanf("%f", &valueX);
            printf("DIGITE O VALOR DE Y:\n");
            scanf("%f", &valueY);

            adicionar(valueX, valueY);
        }

        if(choice == 1){
            imprimir(listaPontos);
        }

        if(choice == 0){
            printf("ENCERRANDO PROGRAMA.\n");
            break;
        } else {
            printf("VALOR INVALIDO.\n");
        }
    }
    

    return 0;
}