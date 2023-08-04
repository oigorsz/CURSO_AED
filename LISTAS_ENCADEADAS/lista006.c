#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

typedef struct Node Node;

void printList(Node * head){
    Node * auxiliar = head;
    while(auxiliar != NULL){
        printf("%d\n", head->data);
        head = head->next;
    }

    printf("\n");
}


int main(){
    Node * head = NULL;
    int choice, value;

    while (1)
    {
        system("cls");
        printf("ESCOLHAS AS OPÇÕES ABAIXO:\n");
        printf("DIGITE 1 PARA IMPRIMIR A LISTA.\n");
        printf("DIGITE 2 PARA ADICIONAR UM ELEMENTO NOVO.\n");
        printf("DIGITE 0 PARA FINALIZAR.\n");
        scanf("%d", &choice);
        printf("\n");

        if(choice == 1){
            printf("LISTA:\n");
            printList(head);
        }

        if(choice == 2){
            printf("DIGITE O VALOR DO NOVO ELEMENTO:\n => ");
            scanf("%d", &value);

            Node *newNode = (Node*)malloc(sizeof(Node));
            newNode->data = value;
            newNode->next = NULL;

            if(head == NULL){
                head = newNode;
            } else {
                Node *aux = head;
                while(aux->next != NULL){
                    aux = aux->next;
                }

                aux->next = newNode;
            }

            printf("NOVO ELEMENTO INSERIDO COM SUCESSO.\n");
        }

        if(choice == 0){
            printf("SAINDO DO PROGRAMA.\n");
            break;
        } else {
            printf("OPÇAO INVALIDA. TENTE NOVAMENTE.\n");
        }
    }

    // Liberando a memória alocada para os nós da lista antes de sair
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    
    return 0;
}