#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 50

struct Produto {
    char nomeProduto[TAM];
    double preco;
    int codigo;
    struct Produto * next;
};

typedef struct Produto Produto;

Produto * listaProdutos;

void limpar(Produto * listaProdutos){
    Produto * aux1 = listaProdutos;
    while (aux1 != NULL)
    {
        Produto * proximo = aux1->next;
        free(aux1);
        aux1 = proximo;
    }
    
}

void adicionar(char string[], double preco, int codigo){
    Produto *p = (Produto*)malloc(sizeof(Produto));
    strcpy(p->nomeProduto, string);
    p->preco = preco;
    p->codigo = codigo;
    p->next = listaProdutos;
    listaProdutos = p;
}

void imprimir(char string[], double preco, int codigo){
    system("cls");

    Produto * aux2 = listaProdutos;
    printf("LISTA PRODUTOS.\n");
    while (aux2 != NULL)
    {
        printf("%d || %.2lf || %s\n", aux2->codigo, aux2->preco, aux2->nomeProduto);
        aux2 = aux2->next;
    }

    printf("\n\n");
}

int main(){
    int choice, codigo;
    char string[TAM];
    double preco;

    system("cls");

    while(1){
        printf("DIGITE 1 PARA CADASTRAR UM PRODUTO.\n");
        printf("DIGITE 2 PARA IMPRIMIR A LISTA DE PRODUTOS.\n");
        printf("DIGITE 0 PARA FINALIZAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice == 0){
            printf("PROGRAMA ENCERRADO.\n");
            limpar(listaProdutos);
            break;
        }

        if(choice == 1){
            system("cls");
            getchar();

            printf("DIGITE O NOME DO PRODUTO:\n => ");
            fgets(string, TAM, stdin);
            string[strlen(string) - 1] = '\0';

            for(int i = 0; i < strlen(string); i++){
                string[i] = toupper(string[i]);
            }

            printf("DIGITE O VALOR DO PRODUTO EM R$:\n => ");
            scanf("%lf", &preco);

            printf("DIGITE O CODIGO DO PRODUTO:\n => ");
            scanf("%d", &codigo);

            adicionar(string, preco, codigo);

            getchar();
            system("cls");
        }

        if(choice == 2){
            imprimir(string, preco, codigo);
        }

        if(choice != 0 && choice != 1 && choice != 2){
            printf("[ERRO] VALOR INVALIDO.\n");
        }
    }
    return 0;
}