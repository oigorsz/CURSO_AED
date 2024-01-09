#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct Data {
    int dia;
    int mes;
    int ano;
};

typedef struct Data Data;

struct Banda {
    char nome[50];
    float valor;
    int membros;
    char produtora[50];
    Data lancamento;
    Data contrato;
};

typedef struct Banda Banda;


int main(){
    Banda bandas[3];
    int i, j;

    system("cls");

    for(i = 0; i < 3;i++){
        printf("DIGITE O NOME DA BANDA %d:\n => ", i + 1);


        getchar();
        fgets(bandas[i].nome, sizeof(bandas[i].nome), stdin);
        bandas[i].nome[strlen(bandas[i].nome) - 1] = '\0';
        

        for(j = 0; j < strlen(bandas[i].nome);j++){
            bandas[i].nome[j] = toupper(bandas[i].nome[j]);
        }

        printf("DIGITE O NOME DA PRODUTORA %d:\n => ", i + 1);

        getchar();
        fgets(bandas[i].produtora, sizeof(bandas[i].produtora), stdin);
        bandas[i].produtora[strlen(bandas[i].produtora) - 1] = '\0';
        

        for(j = 0; j < strlen(bandas[i].nome);j++){
            bandas[i].produtora[j] = toupper(bandas[i].produtora[j]);
        }

        printf("DIGITE O NUMERO DE MEMBROS DA BANDA %d:\n => ", i + 1);
        scanf("%d", &bandas[i].membros);

        printf("DIGITE O VALOR DO CD %d", i + 1);
        scanf("%f", &bandas[i].valor);

        printf("DIGITE O DIA DE LANÇAMENTO:\n => ");
        scanf("%d", &bandas[i].lancamento.dia);

        printf("DIGITE O MES DE LANÇAMENTO:\n => ");
        scanf("%d", &bandas[i].lancamento.mes);

        printf("DIGITE O ANO DE LANÇAMENTO:\n => ");
        scanf("%d", &bandas[i].lancamento.ano);

        printf("DIGITE O DIA DE CONTRATO:\n => ");
        scanf("%d", &bandas[i].contrato.dia);

        printf("DIGITE O MES DE CONTRATO:\n => ");
        scanf("%d", &bandas[i].contrato.mes);

        printf("DIGITE O ANO DE CONTRATO:\n => ");
        scanf("%d", &bandas[i].contrato.ano);

        system("cls");
    }

    printf("DADOS\n");

    for(i = 0; i < 3; i++){
        printf("BANDA %d\n", i + 1);
        printf("NOME: %s\n", bandas[i].nome);
        printf("PRODUTORA: %s\n", bandas[i].produtora);
        printf("MEMBROS: %d\n", bandas[i].membros);
        printf("DATA LANCAMENTO: %d/%d/%d", bandas[i].lancamento.dia,bandas[i].lancamento.mes, bandas[i].lancamento.ano);
        printf("DATA CONTRATO: %d/%d/%d", bandas[i].contrato.dia,bandas[i].contrato.mes, bandas[i].contrato.ano);
        printf("PRECO: %.2f\n", bandas[i].valor);
    }
}

