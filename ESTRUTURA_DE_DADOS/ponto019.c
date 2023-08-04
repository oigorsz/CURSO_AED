/*
Escreva um programa que receba uma string do usuário 
e conte o número de vogais (a, e, i, o, u) presentes nela.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int numVogais(char *string, int tamanho){
    int numVogais = 0;

    for(int i = 0; i < tamanho; i++){
        *string = toupper(*string);

        if(*string == 'A' ||
           *string == 'E' ||
           *string == 'I' ||
           *string == 'O' ||
           *string == 'U'){
            
            numVogais += 1;
        }

        *string++;
    }

    return numVogais;
}

int main(){
    char string[100];
    int tamanho;

    system("cls");

    printf("DIGITE UMA STRING QUALQUER:\n => ");
    fgets(string, sizeof(string), stdin);
    tamanho = strlen(string);
    string[tamanho - 1] = '\0';

    printf("NUMERO DE VOGAIS %d.\n", numVogais(string, tamanho));

    return 0;
}