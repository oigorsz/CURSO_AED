#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_MAX 1024


struct Nodo {
    int topo;
    struct Nodo *next;
};

typedef struct Nodo Nodo;

Nodo *inicializar(){
    return NULL;
}

Nodo *push(Nodo *p, int v){
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));

    if(novo == NULL){
        printf("[ERRO]");
        exit(1);
    }

    novo->topo = v;
    novo->next = p;
    return novo;
}

int pop(Nodo *p){

    if(p == NULL){
        printf("PILHA VAZIA.\n");
        exit(1);
    }

    Nodo *temp = p;
    int valor;

    valor = temp->topo;
    p = temp->next;
    free(temp);

    return valor;
}


int calcular(char string[]){
    //INICIALIZAR A PILHA
    Nodo* pilha = inicializar();

    int i, numero, op1, op2, res;

    for(i = 0; string[i] != '\0'; i++){
        if(isdigit(string[i])){
            numero = string[i] - '0';
            push(pilha, numero);
        } else {
            op2 = pop(pilha);
            op1 = pop(pilha);

            switch (string[i])
            {
            case '+':
                res = op2 + op1;
                break;
            case '-':
                res = op2 - op1;
                break;
            case '/':
                res = op2/op1;
                break;
            case '*':
                res = op1*op2;
                break;
            
            default:
                printf("OPERADOR INVÁLIDO.\n");
                exit(1);
                break;
            }

            pilha = push(pilha, res);
        }
    }

    return pop(pilha);
}

void desalocar(Nodo *p){
    Nodo * aux;


    for(aux = p; p != NULL; p = p->next){
        free(aux);
    }

    printf("PROGRAMA FINALIZADO.\n");
   
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

    printf("%d\n", resultado);
    
    return 0;
}

