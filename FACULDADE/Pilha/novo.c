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

Nodo *pop(Nodo *p, int *valor){
    Nodo *aux = p;

    *valor = p->info;
    p = p->next;
    free(aux);
    return p;
}

int calcular(char string[], int *resultado){
    int i, temp, num1, num2, operadores = 0, operandos = 0;
    Nodo *pilha = iniciar();

    for(i = 0; string[i] != '\0'; i++){
        if(isdigit(string[i])){
            temp = string[i] - '0'; //CONVERTE O CARACTER EM INTEIRO
            pilha = push(pilha, temp);
            operadores++;
        } else {
            if(pilha == NULL) return 0;
            pilha = pop(pilha, &num2);
          
            if(pilha == NULL) return 0;
            pilha = pop(pilha, &num1);
 
            operandos++;
 
            switch (string[i])
            {
            case '+':
                pilha = push(pilha, num1 + num2);
                break;
            case '-':
                pilha = push(pilha, num1 - num2); 
                break;
            case '*':
                pilha = push(pilha, num1 * num2);
                break;
            case '/':
                if(num2 == 0) return 0;

                pilha = push(pilha, num1/num2);
                break;
            
            default:
                return 0;
                break;
            }
        }
 
        if(operadores == operandos - 1){
            return 0;
        }
    }
 
 
    if(pilha == NULL || pilha->next != NULL){
        return 0;
    }
 
    *resultado = pilha->info;
    free(pilha);
    return 1;
}


int main(){
    int tamanho, i, resultado, valido;
    char string[TAM_MAX + 1]; //1024 CARACTERES + \0
 
    scanf("%s", string);
    tamanho = strlen(string);
    if(1 <= tamanho && tamanho <= 1024){
        for(i = 0; string[i] != '\0'; i++){
            if((isdigit(string[i])) || (string[i] == '+' || string[i] == '-' || string[i] == '*' || string[i] == '/')){
                continue; //CONDIÇÕES PARA QUE A STRING SEJA VALIDA
            } else {
                printf("Invalid Expression"); //ENCERRA O PROGRAMA
                return 0;
            }
        }
    }

    valido = calcular(string, &resultado);

    if(valido == 1){
        printf("%d", resultado);
    }
    else {
        printf("Invalid Expression"); //ENCERRA O PROGRAMA
    }
 
    return 0;
}
    

