#include <stdio.h>

int potencia (int base, int ep){
    if(ep == 1){
        return base;
    }

    return base*potencia(base, ep-1);
}

int fatorial(int k){

    if(k == 1 || k == 0){
        return 1;
    } else {
        return k*fatorial(k-1);
    }

}

int main(){
    int v = potencia(2, 2);
    int k = 5;

    printf("%d", v);
    printf("FATORIAL DE K: %d", fatorial(k));

    return 0;
}