#include <stdio.h>

struct horario {
    int horas;
    int minutos;
    int segundos;
};


int main(){
    struct horario agora, *depois;
    depois = &agora;

    depois -> horas = 18;
    depois -> minutos = 37;
    depois -> segundos = 14;
    
    printf("%d:%d:%d", agora.horas, agora.minutos, agora.segundos);
    return 0;
}