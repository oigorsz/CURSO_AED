//IGOR DE SOUZA MONTEIRO RN168783
#include <stdio.h>
#include <stdlib.h>

void inverter(char *str1, char *str2, char *str3, int Xreal, int Yreal){
    char *p = str3;

    for(int i =  Xreal - 1; i >= 0; i--){
        *p = str1[i];
        p++;
    }

    for(int i = Yreal - 1; i >= 0; i--){
        *p = str2[i];
        p++;
    }

    *p = '\0';
}

int contagem(char *stringZ, char c){
    int contador = 0;
    while (*stringZ != '\0')
    {
        if(*stringZ == c){
            contador++;
        }
        stringZ++;
    }

    return contador;
}

int main(){
    int MaxX, MaxY;
    char c;

    system("cls");

    scanf("%d %d %c", &MaxX, &MaxY, &c);

    if(!((1 <= MaxX && MaxX <= 80) && (1 <= MaxY && MaxY <= 80))){
        return 0;
    }

    char *stringX = (char*)malloc((MaxX + 1) * sizeof(char));
    char *stringY = (char*)malloc((MaxY + 1) * sizeof(char));

    scanf("%s %s",stringX, stringY);


    int xReal = 0, yReal = 0;

    for(int i = 0; stringX[i] != '\0'; i++){
        xReal++;
    }

    for(int i = 0; stringY[i] != '\0'; i++){
        yReal++;
    }

    int zReal = xReal + yReal;


    char *stringZ = (char *)malloc((zReal + 1) * sizeof(char));

    inverter(stringX, stringY, stringZ, xReal, yReal);
    int ocorrenciasC = contagem(stringZ,c);

    printf("%s\n%d\n%d", stringZ, zReal, ocorrenciasC);


    free(stringX);
    free(stringY);
    free(stringZ);

    return 0;
}