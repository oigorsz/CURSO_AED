#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node * rigth;
    struct Node * left;
};

typedef struct Node Node;

Node *createNode(int valor){
    Node *n = (Node*)malloc(sizeof(Node));
    n->value = valor;
    n->rigth = NULL;
    n->left = NULL;
    return n;
}

void add(Node *n, int valor){
    if(valor < n->value){
        if(n->left == NULL){
            n->left = createNode(valor);
        } else {
            add(n->left, valor);
        }
    } else {
        if(n->rigth == NULL){
            n->rigth = createNode(valor);
        } else {
            add(n->rigth, valor);
        }
    }
}

void imprimir(Node *n){
    if(n == NULL){
        return;
    }

    imprimir(n->left);
    printf("\n%d", n->value);
    imprimir(n->rigth);
}

int main(){
    int choice, valor;
    Node *root = createNode(5);

    system("cls");

    while (1)
    {
        printf("DIGITE 1 PARA ADICIONAR UM NOVO ELEMENTO PARA ARVORE.\n");
        printf("DIGITE 2 PARA IMPRIMIR A SEQUENCIA DE NUMEROS.\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice != 0 && choice != 1 && choice != 2){
            system("cls");
            printf("[ERRO] VALOR INVALIDO.\n");
        } else {
            if(choice == 0){
            system("cls");
            printf("PROGRAMA FINALIZADO.\n");
            break;
            }

            if(choice == 1){
                system("cls");

                printf("DIGITE O VALOR A SER ADICIONADO:\n => ");
                scanf("%d", &valor);

                add(root, valor);

                system("cls");
                printf("VALOR ADICIONADO.\n\n");
            }

            if(choice == 2){
                system("cls");
                printf("LISTA:\n");
                imprimir(root);
                printf("\n");
            }
        }
    }
}