#include <stdio.h>
#include <stdlib.h>

struct Pontos {
    float x;
    float y;
    struct Pontos * next;
};

typedef struct Pontos Pontos;

Pontos * listaPontos;

void adicionar(float valueX, float valueY){
    Pontos * p = (Pontos*)malloc(sizeof(Pontos));
    p->x = valueX;
    p->y = valueY;
    p->next = NULL;

    if(listaPontos == NULL){
        listaPontos = p;
    } else {
        Pontos * aux1 = listaPontos;
        while (aux1->next != NULL)
        {
            aux1 = aux1->next;
        }

        aux1->next = p;
    }
}

void imprimir(Pontos * listaPontos){
    system("cls");

    printf("LISTA DE PONTOS:\n");

    Pontos * aux1 = listaPontos;

    while (aux1 != NULL)
    {
        printf("(%.1f, %.1f)\n", aux1->x, aux1->y);
        aux1 = aux1->next;
    }
    
    printf("\n");
}

void limpar(Pontos * listaPontos){
    Pontos * aux2 = listaPontos;
    while (aux2 != NULL)
    {
        Pontos * proximo = aux2->next;
        free(aux2);
        aux2 = proximo;
    }
    
}

int main(){
    int choice;
    float valueX, valueY;

    system("cls");

    while(1){
        printf("DIGITE 1 PARA ADICIONAR UM PONTO A LISTA.\n");
        printf("DIGITE 2 PARA IMPRIMIR A LISTA DE PONTOS.\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice == 0){
            system("cls");
            printf("PROGRAMA ENCERRADO.\n");
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

            
        }

        if(choice == 2){
            imprimir(listaPontos);
        }

        if(choice != 0 && choice != 1 && choice != 2){
            system("cls");
            printf("[ERRO] DIGITE UMA ALTERNATIVA VALIDA.\n");
        }
    }

    return 0;
}