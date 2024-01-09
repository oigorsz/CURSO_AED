#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

typedef struct Node Node;

Node * pilha = NULL;

void limpar(Node *p){
    system("cls");

    Node * auxClean = pilha;

    while (auxClean != NULL)
    {
        Node * proximo = auxClean->next;
        free(auxClean);
        auxClean = proximo;
    }
    

    printf("PROGRAMA ENCERRADO.\n");
}

void adicionar (int value){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = value;
    p->next = pilha;
    pilha = p;
}

void remover(){
    system("cls");
    if(pilha == NULL){
        system("cls");
        printf("PILHA VAZIA.\n");
    } else {
        pilha = pilha->next;
    }
}

void imprimir(Node * p){
    system("cls");

    printf("PILHA DE VALORES:\n");
    Node * auxPrint = p;
    while (auxPrint != NULL)
    {
        printf("%d\n", auxPrint->data);
        auxPrint = auxPrint->next;
    }
    
}

int main(){
    int choice, value;

    system("cls");

    while(1)
    {
        printf("DIGITE 1 PARA EMPILHAR UM VALOR.\n");
        printf("DIGITE 2 PARA DESEMPILHAR UM VALOR.\n");
        printf("DIGITE 3 PARA EXIBIR A PILHA.\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice != 0 && choice != 1 && choice != 2 && choice != 3){
            system("cls");
            printf("VALOR INVÁLIDO.\n");
        } else {
            if(choice == 0){
                limpar(pilha);
                break;
            }

            if(choice == 1){
                system("cls");

                printf("DIGITE UM VALOR INTEIRO:\n => ");
                scanf("%d", &value);
                adicionar(value);

                system("cls");

                printf("%d ADICIONADO A PILHA.\n\n", value);
            }

            if(choice == 2){
                remover();
            }

            if(choice == 3){
                imprimir(pilha);
            }
        }
    }
    return 0;
}