#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverterEconcatenar(char *str1, char *str2, char *str3, int Xreal, int Yreal){
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
    int Xmax, Ymax, inputMax;
    char c;

    scanf("%d %d %c", &Xmax, &Ymax, &c);

    if(!((1 <= Xmax && Xmax <= 80) && (1 <= Ymax && Ymax <= 80))){
        return 0;
    }

    getchar();


    inputMax = Xmax + Ymax + 3; 
    char input[inputMax];

    fgets(input, sizeof(input), stdin);

    int Xreal = 0, Yreal = 0, i = 0;

    while(input[i] != ' '){
        i++;
        Xreal++;
    }

    i = i + 2;

    while(input[i] != '\0'){
        if(input[i] == ' '){
            Yreal--;
        }
        Yreal++;
        i++;
    }

    int Zreal = Xreal + Yreal;

    char *stringX = (char *)malloc((Xreal + 1) * sizeof(char));
    char *stringY = (char *)malloc((Yreal + 1) * sizeof(char));
    char *stringZ = (char *)malloc((Zreal + 1) * sizeof(char));

    sscanf(input, "%s %s", stringX, stringY);

    inverterEconcatenar(stringX, stringY, stringZ, Xreal, Yreal);

    int ocorrenciasC = contagem(stringZ, c);

    printf("%s \n%d \n%d ", stringZ, Zreal, ocorrenciasC);

    free(stringX);
    free(stringY);
    free(stringZ);

    return 0;
}