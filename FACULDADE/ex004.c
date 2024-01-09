//IGOR DE SOUZA MONTEIRO RA 168783 NOTURNO

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct LetraInfo {
    char letra;
    int frequencia;
};

typedef struct LetraInfo LetraInfo;

#define alfabeto 26

void ordenador(LetraInfo array[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - (i + 1); j++){
            if(array[j].letra > array[j+1].letra){
                LetraInfo temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}


int main(){
    char string[256];

    printf("DIGITE UMA STRING:\n => ");
    fgets(string, sizeof(string), stdin);
    string[strlen(string) - 1] = '\0'; //REMOVE O ULTIMO CHAR DE ESPAÇO

    int frequencias[alfabeto] = {0};
    bool presencas[alfabeto] = {false};


    for(int i = 0; string[i] != '\0'; i++){
        if(isalpha(string[i])){
            char letraFormatada = tolower(string[i]);
            int index = letraFormatada - 'a';
            frequencias[index]++;
            presencas[index] = true;
        }
    }

    LetraInfo letras[alfabeto];
    int count = 0;

    for(int i = 0; i < alfabeto; i++){
        if(presencas[i]){
            letras[count].letra = 'a' + i;
            letras[count].frequencia = frequencias[i];
            count++;
        }
    }

    ordenador(letras, count);

    printf("CARACTER E FREQUENCIAS:\n");

    for(int i = 0; i < count;i++){
        printf("%c          %d\n", letras[i].letra, letras[i].frequencia);
    }

    return 0;
}