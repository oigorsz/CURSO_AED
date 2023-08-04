#include <stdio.h>
#include <stdlib.h>

struct Ponto {
    float x;
    float y;
    struct Ponto *next;
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
    printf("\nLISTA\n");
    while(auxiliar != NULL ){
        printf("(%.1f, %.1f)\n", auxiliar->x, auxiliar->y);
        auxiliar = auxiliar->next;
    }
}

void limpar(Ponto * listaPontos){
    Ponto * auxiliar = listaPontos;
    while (auxiliar->next != NULL)
    {
        Ponto* proximo = auxiliar->next;
        free(auxiliar);
        auxiliar = proximo;
    }
    
}

int main(){
    int choice;
    float valueX, valueY;

    system("cls");

    while(1){
        printf("ESCOLHA AS OPÇÕES ABAIXO\n");
        printf("DIGITE 1 PARA ADICIONAR UMA NOVA CELULA.\n");
        printf("DIGITE 2 PARA IMPRIMIR A LISTA.\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice == 1){
            system("cls");
            printf("DIGITE O VALOR DE X:\n => ");
            scanf("%f", &valueX);
            printf("DIGITE O VALOR DE Y:\n => ");
            scanf("%f", &valueY);
            adicionar(valueX, valueY);
            system("cls");
        }

        if(choice == 2){
            imprimir(listaPontos);
        }

        if(choice == 0){
            system("cls");
            printf("PROGRAMA FINALIZADO.\n");
            limpar(listaPontos);
            break;
        } else {
            printf("VALOR INVALIDO.\n");
        }
        
    }
    

    return 0;
}

