#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    int cod;
};

typedef struct Aluno *Aluno;

void adicionar(Aluno lista[], int i){
    system("cls");
    lista[i] = (Aluno)malloc(sizeof(Aluno));

    printf("DIGITE O CODIGO DO ALUNO:\n => ");
    scanf("%d", &lista[i]->cod);

    system("cls");

}

void imprimir(Aluno lista[], int i){
    system("cls");
    for(int j = 0; j < i; j++){
        printf("COD: %d.\n", lista[j]->cod);
    }
}

void desalocar(Aluno lista[], int i){
    system("cls");

    for(int j = 0; j < i; j++){
        free(lista[i]);
    }

    printf("PROGRAMA ENCERRADO.\n");
}


int main(){
    int choice;
    Aluno lista[100];
    int i = 0;

    system("cls");

    while (1)
    {
        printf("DIGITE 1 PARA REGISTRAR O ALUNO.\n");
        printf("DIGITE 2 PARA VERIFICAR A LISTA DE ALUNOS.\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice == 1){
            adicionar(lista, i);
            i++;
        } else if(choice == 2){
            imprimir(lista, i);
        } else if(choice == 0){
            desalocar(lista, i);
            return 0;
        } else {
            system("cls");
            printf("[ERRO] DIGITE UM COMANDO VALIDO.\n");
            continue;
        }
    }
    
    return 0;
}