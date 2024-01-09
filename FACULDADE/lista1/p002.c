#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 25

struct Prato {
    char cor[TAM];
    struct Prato * next;
};

typedef struct Prato Prato;

void formatar(char string[]){

    int i, tamanho = strlen(string);
    string[tamanho - 1] = '\0';

    for(i = 0; i < tamanho; i++){
        string[i] = toupper(string[i]);
    }
}

Prato *push(Prato *p, char string[]){
    Prato *novo;
    novo = (Prato *)malloc(sizeof(Prato));
    if(novo == NULL){
        printf("ERRO");
        exit(1);
    }


    strcpy(novo->cor, string);
    novo->next = p;
    return novo;
}

void encerrar(Prato *p){
    int i;
    Prato *auxRemove = p;

    while (auxRemove != NULL)
    {
        auxRemove = auxRemove->next;
        free(auxRemove);
    }


    
}

void exibir(Prato *p){
    Prato *aux = p;

    system("cls");

    while (aux != NULL)
    {
        printf("%s\n", aux->cor);
        aux = aux->next;
    }
    
}




int main(){
    int choice;
    char string[TAM];
    Prato *Plista = NULL;
   
    system("cls");

    while (1)
    {
        printf("EMPILHADOR DE PRATOS.\n");

        do {
            
            printf("DIGITE 1 PARA EMPILHAR UM PRATO.\n");
            printf("DIGITE 2 PARA DESEMPILHAR UM PRATO.\n");
            printf("DIGITE 3 PARA MOSTRAR OS PRATOS.\n");
            printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
            scanf("%d", &choice);

        } while (!(choice == 1 || choice == 2 || choice == 3 || choice == 0));

        switch (choice)
        {
        case 1:
            system("cls");
            getchar(); //REMOVER BUFFER DE CARACTER

            printf("DIGITE A COR DO PRATO A SER EMPILHADO:\n");
            fgets(string, sizeof(string), stdin);
            formatar(string);

            Plista = push(Plista, string);
            
            //EMPILHAR
            break;
        case 2:
            //DESEMPILHAR
            break;
        case 3:
            exibir(Plista);
            break;
        case 0:
            encerrar(Plista);
            return 0;
            break;
        default:
            system("cls");
            printf("\n VALOR INVALIDO.\n");
            break;
        }
    }

}