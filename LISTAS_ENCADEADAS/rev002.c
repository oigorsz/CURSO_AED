#include <stdio.h>
#include <stdlib.h>

struct Pontos {
    float x;
    float y;
    struct Pontos * next;
};

typedef struct Pontos Pontos;

Pontos *listaPontos = NULL;

void limpar(Pontos * listaPontos){
    system("cls");

    Pontos *aux = listaPontos;
    while (aux != NULL)
    {
        Pontos *proximo = aux->next;
        free(aux);
        aux = proximo;
    }
    
    printf("PROGRAMA ENCERRADO.\n");
}

void adicionar(float valueX, float valueY){
    Pontos *p = (Pontos*)malloc(sizeof(Pontos));
    p->x = valueX;
    p->y = valueY;
    p->next = NULL;

    if(listaPontos == NULL){
        listaPontos = p;
    } else {
        Pontos * aux3 = listaPontos;
        while (aux3->next != NULL)
        {
            aux3 = aux3->next;
        }
        
        aux3->next = p;
    }
}

void imprimir(Pontos *listaPontos){
    system("cls");

    printf("LISTA DE PONTOS:\n");

    Pontos *aux2 = listaPontos;

    while (aux2 != NULL)
    {
        printf("(%.1f, %.1f)\n", aux2->x, aux2->y);
        aux2 = aux2->next;
    }

    printf("\n");
    
}

int main(){
    int choice;
    float valueX, valueY;

    system("cls");

    while (1)
    {
        printf("DIGITE 1 PARA INSERIR UM PONTO.\n");
        printf("DIGITE 2 PARA IMPRIMIR A LISTA DE PONTOS.\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice != 0 && choice != 1 && choice != 2){
            system("cls");
            printf("[ERRO] VALOR INVALIDO.\n");
        } else {
            if(choice == 0){
                limpar(listaPontos);
                break;
            }
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
        }
    }
    
    return 0;
}