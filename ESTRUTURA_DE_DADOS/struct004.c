#include <stdio.h>
#include <stdlib.h>


struct retangulo {
    float base;
    float altura;
};


typedef struct retangulo retangulo;

float areaRetangulo(struct retangulo retangulo){
    float area = retangulo.altura * retangulo.base;
    return area;
}

int main(void){

    system("cls");

    retangulo forma;

    printf("DIGITE O VALOR DA BASE DO RETANGULO:\n => ");
    scanf("%f", &forma.base);

    printf("DIGITE O VALOR DA ALTURA DO RETANGULO:\n => ");
    scanf("%f", &forma.altura);

    printf("AREA: %.2f\n", areaRetangulo(forma));


    return 0;
}