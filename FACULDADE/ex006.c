#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

int main() {
    char string[256];
    int frequencias[ALPHABET_SIZE] = {0};

    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    for (int i = 0; string[i] != '\0'; i++) {
        if (isalpha(string[i])) {
            char letraFormatada = tolower(string[i]);
            int index = letraFormatada - 'a';
            frequencias[index]++;
        }
    }

    printf("CARACTERES E FREQUENCIAS:\n");

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (frequencias[i] > 0) {
            printf("%c      %d\n", 'a' + i, frequencias[i]);
        }
    }

    return 0;
}