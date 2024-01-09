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

void rem(Node *n, int value){
    Node *filho = n;
    Node *pai;

    do {
        pai = filho;
        if(value < filho->value){
            filho = filho->left;
        }

        if(value > filho->value){
            filho = filho->rigth;
        }

    } while(filho != NULL && filho->value != value);

    //CASO 1
    if(filho != NULL){
        if(filho->left == NULL && filho->rigth == NULL){
            if(pai->rigth == filho){
                pai->rigth = NULL;
            }
            if(pai->left == filho){
                pai->left == NULL;
            }
        }
    }

    //CASO 2
    if(filho->left != NULL && filho->rigth == NULL){
        if(pai->rigth == filho){
            pai->rigth = filho->left;
        }
        if(pai->left == filho){
            pai->left = filho->left;
        }
    }

    if(filho->left == NULL && filho->rigth != NULL){
        if(pai->left == filho){
            pai->left = filho->rigth;
        }
        if(pai->rigth == filho){
            pai->rigth = filho->rigth;
        }
    }

    //CASO 3

    if(filho->rigth != NULL && filho->left != NULL){
        if(filho->left->rigth == NULL){
            filho->value = filho->left->value;
        } else {
            Node *p = filho->left;
            Node *aux = p;

            while (p->rigth != NULL)
            {
                aux = p;
                p = p->rigth;
            }

            aux->rigth = NULL;
            filho->value = p->value;
        }
    }
}

int main(){
    int choice, value;
    Node *root = createNode(6);

    system("cls");

    while (1)
    {
        printf("DIGITE 1 PARA ADICIONAR UM ELEMENTO.\n");
        printf("DIGITE 2 PARA IMPRIMIR A LISTA DE ELEMENTOS.\n");
        printf("DIGITE 3 PARA REMOVER UM ELEMENTO.\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");

        scanf("%d", &choice);

        if(choice != 0 && choice != 1 && choice != 2 && choice != 3){
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

            if(choice == 3){
                system("cls");

                imprimir(root);

                printf("\n QUAL VALOR DESEJA REMOVER?\n");
                scanf("%d", &value);

                rem(root, value);
            }
        }
    }

    return 0;
}