#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define alfabeto 26

void ordenador(int frequencias[], char letrasPresentes[]){
    for(int i = 0; i < alfabeto - 1; i++){
        for(int j = 0; j < alfabeto - i -1 ; j++){
            if(letrasPresentes[j] > letrasPresentes[j + 1]){
                char auxLp = letrasPresentes[j];
                letrasPresentes[j] = letrasPresentes[j + 1];
                letrasPresentes [j + 1] = auxLp;

                int auxF = frequencias[j];
                frequencias[j] = frequencias[j + 1];
                frequencias[j + 1] = auxF;
            }
        }
    }
}

int main(){
    char string[256];
    int frequencias[alfabeto] = {0};
    char letrasPresentes[alfabeto];
    int contadorLetrasPresentes = 0;

    printf("DIGITE UMA STRING:\n => ");
    fgets(string, sizeof(string), stdin);

    for(int i = 0; string[i] != '\0'; i++){
        if(isalpha(string[i])){
            char letraFormatada = tolower(string[i]);
            int index = letraFormatada - 'a';
            frequencias[index]++;

            bool encontrado = false;

            for(int j = 0; j < contadorLetrasPresentes;j++){
                if(letrasPresentes[j] == letraFormatada){
                    encontrado = true;
                    break;
                }
            }

            if(!encontrado){
                letrasPresentes[contadorLetrasPresentes] = letraFormatada;
                contadorLetrasPresentes++;
            }
        }
    }

    ordenador(frequencias, letrasPresentes);

    printf("CARACTERES E FREQUENCIAS:\n");

    for(int i = 0; i < contadorLetrasPresentes; i++){
        int index = letrasPresentes[i] - 'a';
        printf("%c      %d\n", letrasPresentes[i], frequencias[index]);
    }

    return 0;
}