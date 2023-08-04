#include <stdio.h>
#include <stdlib.h>

struct Pontos {
    float x;
    float y;
    struct Pontos * next;
};

typedef struct Pontos Pontos;

Pontos *listaPontos;

void adicionar(float valueX, float valueY){
    Pontos *p = (Pontos*)malloc(sizeof(Pontos));
    p->x = valueX;
    p->y = valueY;
    p->next = listaPontos;
    listaPontos = p;
}

void imprimir(Pontos *listaPontos){
    
    if(listaPontos != NULL){
        printf("(%.1f, %.1f)\n", listaPontos->x, listaPontos->y);
        imprimir(listaPontos->next);
    }
}

void limpar(Pontos * listaPontos){
    Pontos * aux = listaPontos;
    while (aux != NULL)
    {
        Pontos * proximo = aux->next;
        free(aux);
        aux = proximo;
    }
    
}

int main(){
    int choice;
    float valueX, valueY;

    system("cls");

    while(1){
        printf("DIGITE 1 PARA ADICIONAR UM PONTO A LISTA\n");
        printf("DIGITE 2 PARA IMPRIMIR A LISTA\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA\n");
        scanf("%d", &choice);

        system("cls");

        if(choice == 0){
            printf("PROGRAMA FINALIZADO.\n");
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
            printf("\n");
            imprimir(listaPontos);
        }

        if(choice != 0 && choice != 1 && choice != 2){
            system("cls");
            printf("VALOR INVALIDO.\n");
        }
    }

    return 0;
}