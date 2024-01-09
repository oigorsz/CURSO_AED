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
 
Nodo *inicializar(){
    return NULL;
}
 
int estaVazia(Nodo *p) {
    return p == NULL;
}
 
 
Nodo *push (Nodo *p, int valor){
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    if(novo == NULL){
        printf("Invalid Expression");
        exit(1);
    }
 
    novo->info = valor;
    novo->next = p;
    return novo;
}
 
Nodo *pop(Nodo *p,int *valor) {
    Nodo *aux;
 
    if (p == NULL) {
        printf("Invalid Expression");
        exit(1);
    }
 
    aux = p;
    *valor = p->info;
    p = p->next;
    free(aux);
    return p; 
}
 
 
int calcular(char string[]){
    Nodo *p = inicializar();
    int i, numTemp, num1, num2, resultado;
 
    for(i = 0; string[i] != '\0'; i++){
        if(isdigit(string[i])){
            numTemp = string[i] - '0';
            p = push(p, numTemp);
        } else if(string[i] == '+' || string[i] == '-' || string[i] == '/' || string[i] == '*'){
            if(p == NULL){
                printf("Invalid Expression");
                exit(1);
            }
 
            p = pop(p, &num2);
 
            if(p == NULL){
                printf("Invalid Expression");
                exit(1);
            }
 
            p = pop(p, &num1);
            
            switch (string[i])
            {
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
                if(num2 == 0){
                    exit(1);
                }
                p = push(p, num1 / num2);
                break;
            default:
                exit(1);
                break;
            }
        }
    }
 
    if (p == NULL || p->next != NULL) {
        printf("Invalid Expression");
        exit(1);
    }
 
    resultado = p->info;
    free(p);
    return resultado;
}
 
 
int main(){
    char string[TAM_MAX + 1]; //NUMERO MAXIMO DE CARACRERES + \0
    int tamanho, resultado, i, space = 0;
 
    do {
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