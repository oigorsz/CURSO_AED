#include <stdio.h>
#include <stdlib.h>

struct Pontos {
    float x;
    float y;
    struct Pontos * next;
};

typedef struct Pontos Pontos;

Pontos * listaPontos;

void addFirst(float x, float y){
    Pontos * p = (Pontos*)malloc(sizeof(Pontos));
    p->x = x;
    p->y = y;
    p->next = listaPontos;
    listaPontos = p;
}

void addLast(float x, float y){
    Pontos * p = (Pontos*)malloc(sizeof(Pontos));
    p->x = x;
    p->y = y;
    p->next = NULL;

    if(listaPontos == NULL){
        listaPontos = p;
    } else {
        Pontos * aux2 = listaPontos;
        while (aux2->next != NULL)
        {
            aux2 = aux2->next;
        }
        
        aux2->next = p;
    }
}

void imprimir(Pontos * listaPontos){
    system("cls");

    printf("LISTA PONTOS:\n");

    Pontos * aux1 = listaPontos;
    while (aux1 != NULL)
    {
        printf("(%.1f, %.1f)\n", aux1->x, aux1->y);
        aux1 = aux1->next;
    }
    
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
        printf("DIGITE 1 PARA ADICIONAR UM PONTO NO INICIO DA LISTA.\n");
        printf("DIGITE 2 PARA ADICIONAR UM PONTO NO FINAL DA LISTA.\n");
        printf("DIGITE 3 PARA IMPRIMIR A LISTA DE PONTOS.\n");
        printf("DIGITE 0 PARA FINALIZAR O PROGRAMA.\n");

        scanf("%d", &choice);

        if(choice != 0 && choice != 1 && choice != 2 && choice != 3){
            system("cls");
            printf("[ERRO] VALOR INVALIDO.\n");
        } else {
            if(choice == 0){
            system("cls");
            printf("PROGRAMA ENCERRADO:\n");
            limpar(listaPontos);
            break;
            }

            if(choice == 3){
                imprimir(listaPontos);
                continue;
            }

            system("cls");

            printf("DIGITE O VALOR DE X:\n => ");
            scanf("%f", &valueX);
            printf("DIGITE O VALOR DE Y:\n => ");
            scanf("%f", &valueY);

            if(choice == 1){
                addFirst(valueX, valueY);
                system("cls");
            }

            if(choice == 2){
                addLast(valueX, valueY);
                system("cls");
            }

            
        }
        
    }

    return 0;
}