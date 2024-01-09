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

int length = 0;


void adicionar(float valueX, float valueY, int index){
    Pontos *p = (Pontos*)malloc(sizeof(Pontos));
    p->x = valueX;
    p->y = valueY;
    p->next = NULL;

    if(index > length){
        printf("[ERRO]\n");
    } else {
        if(index == 0){
            p->next = listaPontos;
            listaPontos = p;
        } else {
            Pontos *aux3 = listaPontos;
            for(int i = 0; i != index - 1;i++){
                aux3 = aux3->next;
            }

            p->next = aux3->next;
            aux3->next = p;
        }
    }

    length ++;
}


void remover(int index){
    if(index > length || index < 0){
        printf("[ERRO] VALOR INVALIDO.\n");
    } else {
        if(index == 0){
            listaPontos = listaPontos->next;
        } else {
            Pontos *aux4 = listaPontos;
            for(int i = 0; i < index - 1; i++){
                aux4 = aux4->next;
            }

            aux4->next = aux4->next->next;
        }

        length--;
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

    int choice, index;
    float valueX, valueY;

    system("cls");

    while (1)
    {
        printf("DIGITE 1 PARA INSERIR UM PONTO.\n");
        printf("DIGITE 2 PARA REMOVER UM PONTO.\n");
        printf("DIGITE 3 PARA IMPRIMIR A LISTA DE PONTOS.\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice != 0 && choice != 1 && choice != 2 && choice != 3){
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
                printf("DIGITE O INDEX:\n => ");
                scanf("%d", &index);

                adicionar(valueX, valueY, index);

                system("cls");
            }

            if(choice == 2){
                system("cls");

                printf("DIGITE O INDEX QUE SERA REMOVIDO:\n => ");
                scanf("%d", &index);

                remover(index);

                system("cls");
            }
            if(choice == 3){
                imprimir(listaPontos);
            }
        }
    }
    
    return 0;
}