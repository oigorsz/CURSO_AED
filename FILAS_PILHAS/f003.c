#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 100

struct pessoa {
    int senha;
    char nome[TAM];
    struct pessoa *next;
};

typedef struct pessoa pessoa;

pessoa *fila = NULL;

void limpar(pessoa * fila){
    pessoa *auxClean = fila;

    while (auxClean != NULL)
    {
        pessoa *proximo = auxClean->next;
        free(auxClean);
        auxClean = proximo;
    }

    printf("PROGRAMA ENCERRADO.\n");
}


void adicionar(int senha, char string[]){
    pessoa *p = (pessoa*)malloc(sizeof(pessoa));
    p->senha = senha;
    strcpy(p->nome, string);
    p->next = NULL;

    if(fila == NULL){
        fila = p;
    } else {
        pessoa *auxAdd = fila;

        while (auxAdd->next != NULL)
        {
            auxAdd = auxAdd->next;
        }
        
        auxAdd->next = p;
    }
}

void remover(){
    if(fila == NULL){
        printf("FILA VAZIA.\n");
    } else {
        fila = fila->next;
    }
}

void imprimir(){
    system("cls");
    printf("LISTA DE SENHAS:\n");

    pessoa * auxPrint = fila;
    while (auxPrint != NULL)
    {
        printf("NOME: %s || SENHA: %d.\n",auxPrint->nome, auxPrint->senha);
        auxPrint = auxPrint->next;
    }

    printf("\n");

}

int main(){
    int choice, senha = 0;
    char string[TAM];

    system("cls");

    while (1)
    {
        printf("DIGITE 1 PARA ADICIONAR UMA NOVA SENHA.\n");
        printf("DIGITE 2 PARA REMOVER UMA SENHA.\n");
        printf("DIGITE 3 PARA IMPRIMIR A FILA.\n");
        printf("DIGITE 0 PARA FINALIZAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice != 0 && choice != 1 && choice != 2 && choice != 3){
            system("cls");
            printf("[ERRO VALOR INVALIDO]\n");
        } else {
            if(choice == 0){
                system("cls");
                limpar(fila);
                break;
            }
            
            if(choice == 1){
                system("cls");
                getchar();

                printf("QUAL O SEU NOME:\n => ");
                fgets(string, TAM, stdin);
                string[strlen(string) - 1] = '\0';
                for(int i = 0; i < strlen(string); i++){
                    string[i] = toupper(string[i]);
                }

                adicionar(senha, string);

                printf("SENHA %d ADICIONADA.\n\n", senha);
                senha++;
                continue;
            }

            if(choice == 2){
                system("cls");
                remover();
            }

            if(choice == 3){
                imprimir(fila);
            }
        }
    }
    
    return 0;
}