#include <stdio.h>
#include <stdlib.h>

struct prato {
    char cor;
    struct prato * next;
};

typedef struct prato prato;

prato * pilha = NULL;

void limpar(prato * p){
    system("cls");
    printf("PROGRAMA ENCERRADO.\n");

    prato * auxClean = pilha;
    while(pilha != NULL){
        prato * proximo = auxClean->next;
        free(auxClean);
        auxClean = proximo;
    } 
}

void empilhar(char cor){
    prato * p = (prato*)malloc(sizeof(prato));
    p->cor = cor;
    p->next = pilha;
    pilha = p;
}

void rem(){
    system("cls");

    if(pilha == NULL){
        printf("PILHA VAIZA.\n");
    } else {
        pilha = pilha->next;
    }
}

void imprimir(prato * p){
    system("cls");

    printf("LISTA DE PRATOS.\n");
    prato * auxPrint = pilha;

    while(auxPrint != NULL)
    {
        printf("COR DO PRATP %c.\n", auxPrint->cor);
        auxPrint = auxPrint->next;
    }
}

int main(){
    int choice;
    char cor;

    system("cls");

    while (1)
    {
        printf("DIGITE 1 PARA EMPILHAR UM PRATO.\n");
        printf("DIGITE 2 PARA DESEMPILHAR UM PRATO.\n");
        printf("DIGITE 3 PARA MOSTRAR A PILHA DE PRATOS.\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice != 0 && choice != 1 && choice != 2 && choice != 3){
            system("cls");
            printf("[ERRO] VALOR INVALIDO.\n\n");
        } else {
            if(choice == 0){
                limpar(pilha);
                break;
            }

            if(choice == 1){
                system("cls");

                getchar();

                printf("DIGITE A INICIAL DA COR DO PRATO:\n => ");
                scanf("%c", &cor);

                empilhar(cor);

                getchar();
                system("cls");

                printf("PRATO DO TIPO %c EMPILHADO.\n\n", cor);
            }

            if(choice == 2){
                rem();
            }

            if(choice == 3){
                imprimir(pilha);
            }
        }
    }
    
    return 0;
}