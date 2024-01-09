/*
Faça um programa que peça para o usuário entrar com os seguintes itens n vezes:
nome do produto
quantidade vendida
mês da venda
quem comprou

Estes dados devem ser armazenados em um vetor de estruturas (vetor de struct). A seguir,
apresente o seguinte Menu de opções para o usuário:
• Total de vendas num dado mês (de todos os produtos)
• Total de vendas de um determinado produto num dado mês para um determinado cliente
(qual produto, para quem e em que mês)
• Total de vendas de cada produto (em todos os meses)
• Total vendido para cada cliente
• 5) Fim
Para cada opção que o usuário escolher, faça os cálculos necessários. Os cálculos devem ser
repetidos até que o usuário escolha a opção 5. Não esqueça de verificar que o usuário digitou
uma opção válida.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Venda {
    char nomeProduto[50];
    int quantidade;
    int mes;
    char comprador[50];
};

typedef struct Venda Venda;

int vendasMes (Venda *vendas, int mes, int registros){
    int i, totalVendas = 0;

    for(i = 0; i < registros; i++){
        if(vendas[i].mes == mes){
            totalVendas += vendas[i].quantidade;
        }
    }

    return totalVendas;
}


int produtosCliente(Venda *vendas, char np[], char nc[], int mes, int registros){
    system("cls");
    int i, soma = 0;

    for(i = 0; i < registros; i++){
        if(strcmp(vendas[i].nomeProduto, np) == 0 && strcmp(vendas[i].comprador, nc) == 0 && vendas[i].mes == mes){
            soma += vendas[i].quantidade;
        }
    }

    return soma;
}

int totalVendidos(Venda *vendas, char np[], int registros){
    int i, soma = 0;

    for(i = 0; i < registros; i++){
        if(strcmp(vendas[i].nomeProduto, np) == 0){
            soma += vendas[i].quantidade;
        }
    }

    return soma;
}

int totalCliente(Venda *vendas, char nc[], int registros){
    int i, soma = 0;

    for(i = 0; i < registros; i++){
        if(strcmp(vendas[i].comprador, nc) == 0){
            soma += vendas[i].quantidade;
        }
    }

    return soma;
}

int main(){
    int registros, i, j, choice, mes, res;
    char np[50], nc[50];
    Venda *vendas;

    system("cls");

    do {
        printf("DIGITE O NUMERO DE REGISTROS:\n => ");
        scanf("%d", &registros);
    } while(registros <= 0);

    vendas = (Venda *)malloc(sizeof(Venda) * registros);

    if(vendas == NULL){
        printf("[ERRO]");
        exit(1);
    }

    for(i = 0; i < registros; i++){
        system("cls");

        printf("DIGITE O NOME DO PRODUTO %d:\n => ", i + 1);
        scanf("%s", &np);


        for(j = 0; j < strlen(np); j++){
            np[j] = toupper(np[j]);
        }

        strcpy(vendas[i].nomeProduto, np);

        printf("DIGITE O NOME DO COMPRADOR :\n => ");
        scanf("%s", &nc);


        for(j = 0; j < strlen(nc); j++){
            nc[j] = toupper(nc[j]);
        }

        strcpy(vendas[i].comprador, nc);


        do {
            printf("QUANTIDADE DE PRODUTOS VENDIDOS:\n => ");
            scanf("%d", &vendas[i].quantidade);
        } while(vendas[i].quantidade < 0);

        do {
            printf("MES DE COMPRA DO PRODUTO:\n => ");
            scanf("%d", &vendas[i].mes);
        } while(!(1 <= vendas[i].mes && vendas[i].mes <= 12));
        
    }

    system("cls");

    while (1){
        printf("DIGITE 1 PARA VERIFICAR O TOTAL DE VENDAS DE UM MES.\n");
        printf("DIGITE 2 PARA VERIFICAR AS VENDAS DE UM PRODUTO PARA UM DADO CLIENTE.\n");
        printf("DIGITE 3 PARA VERIFICAR O TOTAL DE VENDAS DE CADA PRODUTO.\n");
        printf("DIGITE 4 PARA VERIFICAR O TOTAL VENDIDO PARA CADA CLIENTE.\n");
        printf("DIGITE 5 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice == 1){
            system("cls");
            printf("DIGITE O MES QUE DESEJA VERIFICAR:\n => ");
            scanf("%d", &mes);
            printf("TOTAL DE VENDAS:%d\n\n\n", vendasMes(vendas, mes, registros));
        } else if(choice == 2) {

            system("cls");
            printf("DIGITE O NOME DO PRODUTO:\n => ");
            scanf("%s", &np);

            for(j = 0; j < strlen(np); j++){
                np[j] = toupper(np[j]);
            }

            printf("DIGITE O NOME DO COMPRADOR:\n => ");

            scanf("%s", &nc);

            for(j = 0; j < strlen(nc); j++){
                nc[j] = toupper(nc[j]);
            }

            printf("DIGITE O MES:\n => ");
            scanf("%d", &mes);

            res = produtosCliente(vendas, np, nc, mes, registros);

            printf("TOTAL DE VENDAS DE %s PARA %s : %d\n\n", np, nc, res);

        } else if(choice == 3) {
            system("cls");

            printf("DIGITE O NOME DO PRODUTO:\n");
            scanf("%s", &np);

            for(j = 0; j < strlen(np); j++){
                np[j] = toupper(np[j]);
            }

            printf("TOTAL DE %s VENDIDOS: %d\n\n", np, totalVendidos(vendas, np, registros));
        } else if(choice == 4) {
            system("cls");

            printf("DIGITE O NOME DO CLIENTE:\n => ");
            scanf("%s", &nc);

            for(j = 0; j < strlen(nc); j++){
                nc[j] = toupper(nc[j]);
            }


            printf("TOTAL DE VENDAS PARA O CLIENTE %s: %d\n\n", nc, totalCliente(vendas, nc, registros));

        } else if(choice == 5){
            printf("[PROGRAMA FINALIZADO]\n");
            free(vendas);
            return 0;
        } else {
            system("cls");
            printf("VALOR INVALIDO.\n");
            continue;
        }

    }

    return 0;
}