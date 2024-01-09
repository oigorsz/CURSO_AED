#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void inverter(char *strx, char *stry, char *strz, int tamX, int tamY){
    char *p = strz;
    for(int i =  tamX - 1; i >= 0; i--){
        if(strx[i] == ' '){
            continue;
        }
        *p = strx[i];
        p++;
    }

    for(int i = tamY - 1; i >= 0; i--){
        if(stry[i] == ' '){
            continue;
        }
        *p = stry[i];
        p++;
    }

    *p = '\0';
}

int contar(char *strz, char c){
    int contador = 0;
    while (*strz != '\0')
    {
        if(*strz == c){
            contador++;
        }
        strz++;
    }

    return contador;
}

int main(){
    int tamX, tamY;
    char c;

    do {
        scanf("%d %d %c", &tamX, &tamY, &c);
    } while(!(0<= tamX && tamX <= 80 && 0<= tamX && tamX <= 80 && isalpha(c)));

    getchar();

    int tamZ = tamX + tamY;
    char input[tamX + tamY + 2];


    char *stringX = (char *)malloc((tamX + 1) *sizeof(char));
    char *stringY = (char *)malloc((tamY + 1) *sizeof(char));
    char *stringZ = (char *)malloc((tamZ + 1) *sizeof(char));

    fgets(input, sizeof(input), stdin);

    sscanf(input, "%s %s", stringX, stringY);
    inverter(stringX, stringY, stringZ, tamX, tamY);

    printf("%s\n%d\n%d", stringZ, tamZ, contar(stringZ, c));

    
    return 0;
}