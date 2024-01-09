#include <stdio.h>
#include <stdlib.h>

double expo (int x){
    double resultado = 1, frac = 1;
    int cont = 0;

    do {
        cont++;
        frac *= x/(double)cont;
        resultado += frac;
    } while(frac > 0.001);

    return resultado;

}

int main(){
    int x;

    system("cls");

    do {
        printf("DIGITE O VALOR DO EXPOENTE DE e:\n => ");
        scanf("%d", &x);
        system("cls");
    } while(x < 0);


    printf("O VALOR DE e ELEVADO A %d É:\n %lf.\n", x, expo(x));

    
    return 0;
}