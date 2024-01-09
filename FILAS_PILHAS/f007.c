#include <stdio.h>
#include <stdlib.h>

struct Ponto {
    float x;
    float y;
    struct Ponto * next;
};

typedef struct Ponto Ponto;

int length = 0;
Ponto *listaPontos = NULL;

void limpar(Ponto *listaPontos){
    system("cls");

    printf("PROGRAMA ENCERRADO.\n");

    Ponto *auxClean = listaPontos;
    while (auxClean != NULL)
    {
        Ponto *proximo = auxClean->next;
        free(auxClean);
        auxClean = proximo;
    }
}

void adicionar(float valueX, float valueY){
    Ponto *p = (Ponto*)malloc(sizeof(Ponto));
    p->x = valueX;
    p->y = valueY;
    p->next = NULL;

    if(listaPontos == NULL){
        listaPontos = p;
    } else {
        Ponto *auxAdd = listaPontos;
        while (auxAdd->next != NULL)
        {
            auxAdd = auxAdd->next;
        }
        
        auxAdd->next = p;
        length++;
    }

}

void remover(int index){
    if (index > length || index < 0){
        system("cls");
        printf("[ERRO] VALOR INVALIDO.\n\n");
    } else {
        if(index == 0){
        listaPontos = listaPontos->next;
        } else {
            Ponto *auxRem = listaPontos;
            for(int i = 0; i < index - 1; i++){
                auxRem = auxRem->next;
            }
            auxRem->next = auxRem->next->next;
        }
        length--;
    }
}

void imprimir(Ponto * listaPontos){
    system("cls"); 
    printf("LISTA DE PONTOS.\n");
    int i = 0;
    Ponto *auxPrint = listaPontos;

    while(auxPrint != NULL)
    {
        printf("%d- (%.1f, %.1f)\n", i, auxPrint->x, auxPrint->y);
        auxPrint = auxPrint->next;
        i++;
    }
}

int main(){
    int choice, index;
    float valueX, valueY;

    system("cls");

    while (1)
    {
        printf("DIGITE 1 PARA ADICONAR UM PONTO.\n");
        printf("DIGITE 2 PARA REMOVER UM PONTO.\n");
        printf("DIGITE 3 PARA IMPRIMIR A LISTA DE PONTOS.\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice != 0 && choice != 1 && choice != 2 && choice != 3){
            system("cls");
            printf("[ERRO] VALOR INVALIDO.\n");
            continue;
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
                printf("PONTO ADICIONADO.\n\n");
            }

            if(choice == 2){
                system("cls");

                if(listaPontos == NULL){
                system("cls");
                printf("LISTA VAZIA.\n\n");
                continue;
               }

                imprimir(listaPontos);

                printf("DIGITE O INDEX DO PONTO A SER REMOVIDO:\n => ");
                scanf("%d", &index);

                remover(index);
            }

            if(choice == 3){
                imprimir(listaPontos);
            }
        }
    }
    
    return 0;
}