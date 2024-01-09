//IGOR DE SOUZA MONTEIRO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 1024

struct Nodo {
    int info;
    struct Nodo *next;
};

typedef struct Nodo Nodo;

int validar(char string[]){
    int i;

    for(i = 0; string[i] != '\0'; i++){
        if(isdigit(string[i]) || string[i] == '+' || string == '-' || string[i] == '/' || string[i] == '*'){
            continue;
        } else {
            return 0;
        }
    }

    return 1;
}

Nodo *iniciar(){
    return NULL;
}

int estaVazia(Nodo *p){
    return p == NULL;
}

Nodo *push(Nodo *p, int valor){
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    if(novo == NULL){
        //ERRO DE ALOCAÇÃO
        exit(1);
    }

    novo->info = valor;
    novo->next = p;
    return novo;
}

int pop(Nodo *p){
    Nodo *aux;
    int valor;

    if(estaVazia(p)){
        printf("Invalid Expression\n");
        exit(1);
    }

    valor = p->info;
    aux = p;
    p = p->next;
    free(aux);
    return valor;
}


int calcular(char string[]){
    int i, temp, num1, num2, resFinal;
    Nodo *p = iniciar();

    for(i = 0; string[i] != '\0'; i++){
        if(isdigit(string[i])){
            temp = string[i] - '0';
            p = push(p, temp);
        } else {
            if(estaVazia(p)){
                printf("Invalid Expression\n");
                exit(1);
            }

            num2 = pop(p);

            if(estaVazia(p)){
                printf("Invalid Expression\n");
                exit(1);
            }

            num1 = pop(p);

            switch (string[i]) {
                case '+':
                    p = push(p, num1 + num2);
                    break;
                case '-':
                    p = push(p, num1 - num2);
                    break;
                case '*':
                    p = push(p, num1 * num2);
                    break;
                case '/':
                    if (num2 == 0) {
                        printf("Invalid Expression\n");
                        exit(1);
                    }
                    p = push(p, num1 / num2);
                    break;
                default:
                    printf("Invalid Expression\n");
                    exit(1);
                    break;
            } 
        }
    }

    if (estaVazia(p) || p->next != NULL) {
        printf("Invalid Expression");
        exit(1);
    }

    resFinal = p->info;
    free(p);
    return resFinal;
}


int main(){
    int resultado, i, tamanho, ehvalido;
    char string[MAX + 1];

    fgets(string, sizeof(string), stdin);
    tamanho = strlen(string);
    string[tamanho - 1] = '\0';

    ehvalido = validar(string);

    if(ehvalido == 1 && (1 <= tamanho && tamanho <= 1024)){
        resultado = calcular(string);
        printf("%d", resultado);
    } else {
        printf("Invalid Expression");
        exit(1);
    }

    return 0;
}