#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int info;
    struct Nodo *right;
    struct Nodo *lelft;
}Nodo;

Nodo *getnode(){
    Nodo *p = (Nodo *)malloc(sizeof(Nodo));
    
    if(p == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    return p;
}

Nodo * makeNode(int x){
    Nodo *p;
    p = getnode(); //ALOCAÇÃO DINÂMICA
    p->info = x;
    p->lelft = NULL;
    p->right = NULL;
    return p;
}

void setLeft(Nodo *p, int x){

    if(p == NULL){
        printf("NODO INEXISTENTE.\n");
    } else if(p->lelft != NULL){
        printf("POSIÇÃO OCUPADA.\n");
    } else {
        p->lelft = makeNode(x);
    }

}

void setRight(Nodo *p, int x){

    if(p == NULL){
        printf("NODO INEXISTENTE.\n");
    } else if(p->right != NULL){
        printf("POSIÇÃO OCUPADA.\n");
    } else {
        p->right = makeNode(x);
    }
}

void imprimir(Nodo *p){
    if(p == NULL){
        return;
    }

    imprimir(p->lelft);
    printf("%d ", p->info);
    imprimir(p->right);
}

void liberar(Nodo *p){
    if(p == NULL){
        return;
    }

    liberar(p->lelft);
    liberar(p->right);

    free(p);
}

int main(){
    Nodo *root, *p, *q;
    int choice = 1, num;

    system("cls");

    do {
        printf("DIGITE O VALOR DA RAIZ DA ARVORE:\n");
        scanf("%d", &num);
    } while(num < 0);

    root = makeNode(num);

    while (choice == 1)
    {
        system("cls");
        printf("DIGITE 1 PARA CONTINUAR.\n");
        printf("DIGITE 0 PARA FINALIZAR.\n");
        scanf("%d", &choice);

        if(choice == 0){
            break;
        }

        printf("DIGITE O NUMERO QUE DESEJA ADICIONAR.\n");
        scanf("%d", &num);

        p = q = root;

        while (num != p->info && q != NULL)
        {
            p = q;

            if(num < p->info){
                q = p->lelft;
            } else {
                q = p->right;
            }
        }

        if(num == p->info){
            printf("ELEMENTO REPETIDO.\n");
        } else if(num < p->info){
            setLeft(p, num);
        } else {
            setRight(p, num);
        }
    }

    imprimir(root);
    liberar(root);
    return 0;
}