#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define alfabeto 26
#define MAX 256


int main(){
    double tempoGasto = 0.0;
    clock_t start = clock();

    char string[MAX];
    int frequencias[alfabeto] = {0};

    printf("DIGITE UMA STRING QUALQUER:\n => ");
    fgets(string, sizeof(string), stdin);

    for(int i = 0; string[i] != '\0'; i++){
        if(isalpha(string[i])){
            char letraFormatada = tolower(string[i]);
            int index = letraFormatada - 'a';
            frequencias[index]++;
        }
    }

    printf("CARACTERES E FREQUENCIAS:\n");

    for(int i = 0; i < alfabeto; i++){
        if(frequencias[i] > 0){
            printf("%c          %d.\n", 'A' + i, frequencias[i]);
        }
    }

    clock_t end = clock();
    tempoGasto = (double)(end - start)/CLOCKS_PER_SEC;

    printf("TEMPO GASTO: %lf.\n", tempoGasto);

    return 0;
}