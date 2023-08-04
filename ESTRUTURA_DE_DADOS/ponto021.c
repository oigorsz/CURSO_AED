#include <stdio.h>

struct horario {
    int *phoras;
    int *pminutos;
    int *psegundos;
};

typedef struct horario horario;

int main(){
    horario hoje;

    int hora = 200;
    int minuto = 300;
    int segundo = 400;

    hoje.phoras = &hora;
    hoje.pminutos = &minuto;
    hoje.psegundos = &segundo;

    return 0;
}