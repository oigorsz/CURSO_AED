/*
Escreva uma função que receba uma string e retorne 
a quantidade de vogais encontradas nessa string.
*/

#include <stdio.h>
#include <stdlib.h>

int numVogais(char *string){
    int numVogais = 0;
    int isVogal = *string == 'A' ||
            *string == 'E' ||
            *string == 'I' ||
            *string == 'O' ||
            *string =='U'  ||
            *string == 'a' ||
            *string == 'e' ||
            *string == 'i' ||
            *string == 'o' ||
            *string =='u';


    while (*string != '\0')
    {
        if (isVogal){
                numVogais += 1;
            }

        *string++;
    }

    return numVogais;
}

int main(void){

    char string[] = "aeiou";

    printf("O NUMERO DE VOGAIS DA STRING É %d.\n", numVogais(string));

    return 0;
}