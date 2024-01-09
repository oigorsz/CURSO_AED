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

void add(Node *n,int valor){
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

void imprimir(Node * n){
    if(n == NULL){
        return;
    }

    imprimir(n->left);
    printf("%d\n", n->value);
    imprimir(n->rigth);
}

int main(){

    Node *root = createNode(5);

    add(root, 4);

    imprimir(root);
}