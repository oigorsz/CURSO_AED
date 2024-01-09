#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node * rigth;
    struct Node * left;
};

typedef struct Node Node;

Node * createNode(int value) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->value = value;
    p->rigth = NULL;
    p->left = NULL;
    return p;
}

void adicionar(Node *n, int value){
    if(value < n->value){
        if(n->left == NULL){
            n->left = createNode(value);
        } else {
            adicionar(n->left, value);
        }
    } else {
        if(n->rigth == NULL){
            n->rigth = createNode(value);
        } else {
            adicionar(n->rigth, value);
        }
    }
}

void imprimir(Node *n){
    if(n == NULL){
        return;
    }

    imprimir(n->left);
    printf("%d\n", n->value);
    imprimir(n->rigth);
}

int main(){
    int choice, value;
    Node *root = createNode(6);

    system("cls");

    while (1)
    {
        printf("DIGITE 1 PARA ADICIONAR UM ELEMENTO.\n");
        printf("DIGITE 2 PARA IMPRIMIR A LISTA DE ELEMENTOS.\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice != 0 && choice != 1 && choice != 2){
            system("cls");
            printf("[ERRO] VALOR INVALIDO.\n");
        } else {
            if(choice == 0){
                system("cls");
                printf("PROGRAMA ENCERRADO.\n");
                break;
            }

            if(choice == 1){
                system("cls");

                printf("DIGITE UM NUMERO INTEIRO:\n => ");
                scanf("%d", &value);

                adicionar(root, value);

                system("cls");

                printf("%d ADICIONADO.\n\n", value);
            }

            if(choice == 2){
                system("cls");

                printf("\nLISTA DE ELEMENTOS\n");

                imprimir(root);
            }
        }
    }

    return 0;
}