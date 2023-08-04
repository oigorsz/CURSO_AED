/*
Escreva uma função que receba duas strings (arrays de caracteres) como argumentos
e use ponteiros para copiar a segunda string para a primeira.
*/


#include <stdio.h>

void copiarString(char *destino, const char *origem){
    while (*origem != '\0')
    {
        *destino = *origem;
        *destino++;
        *origem++;
    }
    
    *destino = '\0';
}

int main(void){
    char destino [50];
    char origem[] = "Igor Monteiro";

    copiarString(destino, origem);

    printf("STRING 1: %s.\n", destino);

    return 0;
}