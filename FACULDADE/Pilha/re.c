//IGOR DE SOUZA MONTEIRO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM_MAX 1024

struct Nodo {
    int info;
    struct Nodo *next;
};

typedef struct Nodo Nodo;

Nodo *iniciar(){
    return NULL;
}

int estaVazia(Nodo *p) {
    return p == NULL;
}

Nodo *push (Nodo *p, int valor){
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    
    if(novo == NULL){
        //ERRO DE ALOCAÇÃO
        exit(1);
    }

    novo->info = valor;
    novo->next = p;
    return novo;
}

Nodo *pop(Nodo *p, int *valor){
    Nodo *temp;

    if(estaVazia(p)){
        printf("Invalid Expression\n");
        exit(1);
    }

    temp = p;
    *valor = p->info;
    p = p->next;
    free(temp);
    return p;
}

int calcular(char string[]){
    int i, temp, num1, num2, resFinal;
    Nodo *p = iniciar();

    for(i = 0; string[i] != '\0'; i++){
        if(isdigit(string[i])){
            temp = string[i] - '0';
            p = push(p, temp);
        } else if (string[i] == '+' || string[i] == '-' || string[i] == '*' || string[i] == '/') {
            if (estaVazia(p)){
                printf("Invalid Expression\n");
                exit(1);
            }

            p = pop(p, &num2);

            if (estaVazia(p)){
                printf("Invalid Expression\n");
                exit(1);
            }

            p = pop(p, &num1);

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

    if (estaVazia(p)) {
        //PILHA VAZIA
        printf("Invalid Expression\n");
        exit(1);
    }

    int resultado = p->info;
    free(p);
    return resultado;
}


int main(){
    int tamanho, valido = 0, i, resultado;
    char string[TAM_MAX + 1];

    fgets(string, sizeof(string), stdin);
    tamanho = strlen(string);
    string[tamanho - 1] = '\0';

    for(i = 0; string[i] != '\0'; i++){
        if(isdigit(string[i]) || string[i] == '+' || string[i] == '-' || string[i] == '*' || string[i] == '/'){
            valido = 1;
        } 
    }

    if(valido == 1 && (1 <= tamanho && tamanho <= 1024)){
        resultado = calcular(string);
        printf("%d\n", resultado);
    } else {
        printf("Invalid Expression\n");
        exit(1);
    }


    return 0;
}