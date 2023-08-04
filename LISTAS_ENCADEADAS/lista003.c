#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

//1-Crie uma função para criar um novo nó:

Node *createNode (int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode != NULL){
        newNode->data = value;
        newNode->next;
    }

    return newNode;
}

int main(){
    return 0;
}