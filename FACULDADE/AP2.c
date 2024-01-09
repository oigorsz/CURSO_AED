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
    int tamX, tamY, tamZ, realZ;
    char c;

    do {
        scanf("%d %d %c", &tamX, &tamY, &c);
    } while(!(1<= tamX&&tamX <= 80) || !(1<= tamY&&tamY <= 80) || !isalpha(c));

    getchar();

    tamZ = tamX + tamY + 2;
    realZ = tamX + tamY;


    char input[tamZ + 1];

    fgets(input, sizeof(input), stdin);


    char *stringX = (char *)malloc((tamX + 1) * sizeof(char));
    char *stringY = (char *)malloc((tamY + 1) * sizeof(char));
    char *stringZ = (char *)malloc((tamZ) * sizeof(char));

    sscanf(input, "%s %s", stringX, stringY);

    inverter(stringX, stringY, stringZ, tamX, tamY);

    printf("%s\n%d\n%d", stringZ, realZ, contar(stringZ, c));
    
}