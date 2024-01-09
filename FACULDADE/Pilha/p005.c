#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_MAX 1024

struct Nodo {
    int valor;
    struct Nodo *next;
};

typedef struct Nodo Nodo;

Nodo *start(){
    return NULL; //INICIALIZA A PILHA VAZIA
}

int vazia(Nodo *topo){
    return topo == NULL;
}

Nodo *push (Nodo *p, int numero){
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    if(novo == NULL){
        printf("[ERRO DE ALOCAÇÃO].\n");
        exit(1);
    }

    novo->valor = numero;
    novo->next = p;
    return novo;
}

Nodo *pop(Nodo **topo, int *numero){

    if (vazia(*topo)) {
        printf("Erro: Pilha vazia.\n");
        exit(1);
    }

    Nodo *temp = *topo;
    *numero = temp->valor;
    *topo = temp->next;
    free(temp);
    return *topo;
}



int calcular (char string[]){
    int i, numTemp, num1, num2, res, resFinal = 0;
    Nodo *pilha = start();

    for(i = 0; string[i] != '\0'; i++){
        if(isdigit(string[i])){
            int numTemp = string[i] - '0'; //CONVERTE A STRING EM NUMERO INTEIRO
            pilha = push(pilha, numTemp);
        } else if(string[i] == '+' || string[i] == '-' || string[i] == '/' || string[i] == '*'){
            if (vazia(pilha)){
                printf("Erro: Pilha vazia.\n");
                exit(1);
            }

            pilha = pop(&pilha, &num2);
            pilha = pop(&pilha, &num1);
            
            switch (string[i])
            {
            case '+':
                res = num1 + num2;
                break;
            case '-':
                res = num1 - num2;
                break;
            case '/':
                if(num2 == 0){
                    printf("[ERRO]");
                    exit(1);
                }
                res = num1 / num2;
                break;
            case '*':
                res = num1 * num2;
                break;
            
            default:
                printf("OPERADOR INVÁLIDO.\n");
                exit(1);
                break;
            }

            pilha = push(pilha, res);
        }
    }

    pilha = pop(&pilha, &resFinal);

    if (vazia(pilha) || !vazia(pilha->next)) {
        printf("Erro: Operandos restantes na pilha.\n");
        exit(1);
    }

    return resFinal;
}


int main(){
    char string[TAM_MAX + 2]; //MAXIMO DE 1024 CARACTERES + CARACTER NULO + ENTER
    int space, tamanho, resultado, i;

    system("cls");

    do {
        printf("DIGITE A EXPRESSAO NA FORMA POS FIXADA:\n => ");
        fgets(string, sizeof(string), stdin);
        tamanho = strlen(string);
        string[tamanho - 1] = '\0';
        space = 0;

        for(i = 0; string[i] != '\0'; i++){
            if(string[i] == ' '){
                space = 1;
                break;
            }
        }

        ///VERIFICAR SE HÁ ESPAÇO E SE O LIMITE DE CARACTERES ESTÁ CORRETO
    } while(!(1 <= tamanho && tamanho <= 1024) || space == 1);

    resultado = calcular(string);

    printf("%d", resultado);
    
    return 0;
}
