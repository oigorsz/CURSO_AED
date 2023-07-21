#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct pessoa {
    char nome[100];
    int idade;
    float altura;
};

typedef struct pessoa pessoa;


int main(void){
    pessoa pessoa;

    system("cls");

    printf("DIGITE O NOME COMPLETO:\n => ");
    fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
    pessoa.nome[strlen(pessoa.nome) - 1] = '\0';

    for(int i = 0; i < strlen(pessoa.nome); i++){
        pessoa.nome[i] = toupper(pessoa.nome[i]);
    }


    system("cls");

    printf("DIGITE A IDADE:\n => ");
    scanf("%d", &pessoa.idade);

    system("cls");

    printf("DIGITE A ALTURA, EM METROS:\n => ");
    scanf("%f", &pessoa.altura);

    system("cls");

    printf("NOME: %s\nIDADE: %d\nALTURA: %.2f\n", pessoa.nome, pessoa.idade,pessoa.altura);

    return 0;
}