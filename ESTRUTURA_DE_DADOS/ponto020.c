#include <stdio.h>

struct horario{
    int horas;
    int minutos;
    int segundos;
};

typedef struct horario horario;



int main(void){

    horario agora, *depois;
    depois = &agora;

    depois -> horas = 20;
    depois -> minutos = 15;
    depois -> segundos = 18;

    int soma = 100;

    horario antes;

    antes.segundos = soma + depois -> segundos;
    antes.minutos = soma + depois -> minutos;
    antes.horas = soma + depois -> horas;

    printf("%d:%d:%d\n", agora.horas, agora.minutos, agora.segundos);
    printf("%d:%d:%d\n", antes.horas, antes.minutos, antes.segundos);


    return 0;
}