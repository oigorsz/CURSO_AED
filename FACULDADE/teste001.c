#include <stdio.h>
#include <stdlib.h>

// Função para contar a ocorrência do caractere c em uma string
int countCharOccurrences(const char *str, char c) {
    int count = 0;
    while (*str != '\0') {
        if (*str == c) {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    int tamanhoX, tamanhoY;
    char c;
    
    // Passo 1
    scanf("%d %d %c", &tamanhoX, &tamanhoY, &c);
    
    // Passo 2
    if (tamanhoX < 1 || tamanhoX > 80 || tamanhoY < 1 || tamanhoY > 80) {
        printf("Tamanhos fora do intervalo permitido.\n");
        return 1;
    }
    if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z')) {
        printf("Caractere inválido.\n");
        return 1;
    }
    
    // Passo 3
    char *stringX = (char *)malloc(tamanhoX + 1); // +1 para o caractere nulo
    char *stringY = (char *)malloc(tamanhoY + 1);
    
    // Passo 4
    char input[tamanhoX + tamanhoY + 2]; // +2 para o espaço e o caractere nulo
    fgets(input, sizeof(input), stdin);
    
    // Passo 5
    int i = 0;
    while (input[i] != ' ') {
        stringX[i] = input[i];
        i++;
    }
    stringX[i] = '\0';
    i++; // Avança para o próximo caractere após o espaço
    
    int j = 0;
    while (input[i] != '\0') {
        stringY[j] = input[i];
        i++;
        j++;
    }
    stringY[j] = '\0';
    
    // Passo 6
    int lenX = i - 1; // Tamanho da stringX
    int lenY = j;     // Tamanho da stringY
    char *stringZ = (char *)malloc(lenX + lenY + 1); // +1 para o caractere nulo
    
    for (int k = 0; k < lenX; k++) {
        stringZ[k] = stringX[lenX - 1 - k];
    }
    for (int k = 0; k < lenY; k++) {
        stringZ[lenX + k] = stringY[lenY - 1 - k];
    }
    stringZ[lenX + lenY] = '\0';
    
    // Passo 7
    int count = countCharOccurrences(stringZ, c);
    
    // Passo 8
    printf("StringZ: %s\n", stringZ);
    printf("Número de caracteres: %d\n", lenX + lenY);
    printf("Número de ocorrências de '%c': %d\n", c, count);
    
    // Libera a memória alocada
    free(stringX);
    free(stringY);
    free(stringZ);
    
    return 0;
}
