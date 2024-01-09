#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo *right;
    struct Nodo *left;
}TNodo;

TNodo* iniciar(){
    return NULL;
}

void imprimir(TNodo *raiz){
    if(raiz == NULL){
        return;
    }

    imprimir(raiz->left);
    printf("%d ", raiz->valor);
    imprimir(raiz->right);
}

//FORMA CONVENCIONAL
void liberar(TNodo *raiz){
    if(raiz == NULL){
        return;
    }

    liberar(raiz->left);
    liberar(raiz->right);
    free(raiz);
}

//FORMA ALTERNATIVA
TNodo* liberar2(TNodo *raiz){
    if(raiz == NULL){
        return NULL;
    }

    liberar2(raiz->left);
    liberar2(raiz->right);
    free(raiz);

    return NULL;
}

int quantNodos(TNodo *raiz){
    if(raiz == NULL){
        return 0;
    }

    return 1 + quantNodos(raiz->left) + quantNodos(raiz->right);
}

int altura(TNodo *raiz){
    int right, left;

    if(raiz == NULL){
        return -1;
    }

    left = altura(raiz->left);
    right = altura(raiz->right);

    if(left > right)
        return left + 1;
    else 
        return right + 1;
}

int busca(TNodo *raiz, int v){
    if(raiz == NULL){
        return 0;
    }

    if(raiz->valor == v){
        return 1;
    }

    if(busca(raiz->left, v) == 1){
        return 1;
    }

    return busca(raiz->right, v);
}

TNodo* criarNodo(int v){
    TNodo *novo;
    novo = (TNodo*)malloc(sizeof(TNodo));

    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->left = NULL;
    novo->right = NULL;
    novo->valor = v;

    return novo;
}


TNodo* inserir(TNodo *raiz, int v){
    if(raiz == NULL){
        return criarNodo(v);
    }

    if(v < raiz->valor){
        raiz->left = inserir(raiz->left, v);
    } else if(v > raiz->valor) {
        raiz->right = inserir(raiz->right, v);
    }

    return raiz;
}


TNodo* remover(TNodo *raiz, int chave){
    TNodo *aux;

    if(raiz == NULL){
        return NULL; //NODO NULO
    } else {
        if(raiz->valor == chave){
            //NODO FOLHA
            if(raiz->left == NULL && raiz->right == NULL){
                free(raiz);
                return NULL;
            } 
            //NODO COM 2 FILHOS 
            else if(raiz->left != NULL && raiz->right != NULL){
                aux = raiz->left;
                while (aux != NULL)
                {
                    aux = aux->right;
                }

                raiz->valor = aux->valor;
                aux->valor = chave;
                raiz->left = remover(raiz->left, chave);
                return raiz;  
            } 
            //NODO COM UM FILHO
            else {
                if(raiz->left != NULL){
                    aux = raiz->left;
                } else {
                    aux = raiz->right;
                }

                free(raiz);
                return aux;
            }
        } else if(chave < raiz->valor){
            raiz->left = remover(raiz->left, chave);
        } else {
            raiz->right = remover(raiz->right, chave);
        }

        return raiz;
    }
}

int main(){
    int op, valor;
    //CRIA O PONTEIRO PARA MINHA RAIZ
    TNodo *raiz;
    //INICIALIZA MINHA RAIZ APONTANDO PARA NULL
    raiz = iniciar();

    system("cls");

    do {
        printf("1) INSERIR NODO\n");
        printf("2) REMOVER UM NODO\n");
        printf("3) IMPRIMIR EM ORDEM.\n");
        printf("4) BUSCAR VALOR.\n");
        printf("0) ENCERRAR.\n");
        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 1:
            //INSERIR
            printf("DIGITE O VALOR QUE DESEJA INSERIR: ");
            scanf("%d", &valor);
            system("cls");

            raiz = inserir(raiz, valor);
            break;
        case 2:
            //REMOVER
            printf("DIGITE O VALOR QUE DESEJA REMOVER: ");
            scanf("%d", &valor);
            system("cls");

            raiz = remover(raiz, valor);
            break;
        case 3:
            //IMPRIMIR
            imprimir(raiz);
            printf("\nNUMERO DE NODOS: %d", quantNodos(raiz));
            printf("\nALTURA DA ARVORE: %d\n\n", altura(raiz));
            break;
        case 4:
            //BUSCAR
            printf("DIGITE O VALOR QUE DESEJA BUSCAR: ");
            scanf("%d", &valor);

            if(busca(raiz, valor) == 1){
                printf("%d ENCONTRADO.\n\n", valor);
            } else {
                printf("%d NÃO ENCONTADO.\n\n", valor);
            }
            break;
        
        default:
            if(op != 0){
                printf("VALOR INVALIDO.\n\n");
            }
            break;
        }
        
    } while (op != 0);
   

    liberar(raiz);
    return 0;
}