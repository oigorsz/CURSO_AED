#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define alfabeto 26
#define MAX 256


int main(){
    char string[MAX];
    int frequencias[alfabeto] = {0};

    fgets(string, sizeof(string), stdin);

    for(int i = 0; string[i] != '\0'; i++){
        if(isalpha(string[i])){
            char letraFormatada = tolower(string[i]);
            int index = letraFormatada - 'a';
            frequencias[index]++;
        }
    }

    for(int i = 0; i < alfabeto; i++){
        if(frequencias[i] > 0){
            printf("%c %d\n", 'A' + i, frequencias[i]);
        }
    }

    return 0;
}