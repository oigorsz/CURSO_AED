#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Aluno {
    char nome[100];
    float n1;
    float n2;
    float n3;
    float n4;
    float media;
};

typedef struct Aluno *Aluno;

struct Turma {
    Aluno alunos[5];
};

typedef struct Turma *Turma;

void atualizar(Turma *turmas){
    int i, j, k;
    char string[100];

    system("cls");
    printf("TURMAS 1\n2\n3\n");
    printf("ESCOLHA A TURMA QUE DESEJA ATUALIZAR:\n => ");
    scanf("%d", &i);

    turmas[i] = malloc(sizeof(Turma));

    if(turmas[i] == NULL){
        printf("ERRO.\n");
        exit(1);
    }

    for(j = 0; j < 5;j++){
        system("cls");

        printf("DIGITE O NOME DO ALUNO DA TURMA %d.\n", i);

        getchar();
        fgets(string, sizeof(string), stdin);

        string[strlen(string) - 1] = '\0';

        for(k = 0; k < strlen(string); k++){
            string[k] = toupper(string[k]);
        }

        strcpy(turmas[i]->alunos[j]->nome, string);


        printf("DIGITE A NOTA DO BIMESTRE 1:\n => ");
        scanf("%f", &turmas[i]->alunos[j]->n1);
        printf("DIGITE A NOTA DO BIMESTRE 2:\n => ");
        scanf("%f", &turmas[i]->alunos[j]->n2);
        printf("DIGITE A NOTA DO BIMESTRE 3:\n => ");
        scanf("%f", &turmas[i]->alunos[j]->n3);
        printf("DIGITE A NOTA DO BIMESTRE 4:\n => ");
        scanf("%f", &turmas[i]->alunos[j]->n4);

        turmas[i]->alunos[j]->media = (turmas[i]->alunos[j]->n1 + turmas[i]->alunos[j]->n2 + 
        turmas[i]->alunos[j]->n3 + turmas[i]->alunos[j]->n4) / 4;
        
    }

}

void imprimir(Turma *turmas){
    system("cls");

    int i, j;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 5; j++){
            printf("NOME: %s || MEDIA: %.2f ||\n", turmas[i]->alunos[j]->nome, turmas[i]->alunos[j]->media);
        }
    }
}

void encerrar(Turma *turma){
    system("cls");

    int i;

    for(i = 0; i < 3; i++){
        free(turma[i]);
    }

    printf("PROGRAMA FINALIZADO.\n");
}

int main(){
    int choice;
    Turma turmas[3];

    system("cls");

    while (1)
    {
        printf("SISTEMA ESCOLAR\n");
        printf("DIGITE 1 PARA ATUALIZAR NOTAS.\n");
        printf("DIGITE 2 PARA IMPRIMIR A LISTA DE ALUNOS.\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        if(choice == 1){
            atualizar(turmas);
        } else if(choice == 2){
            imprimir(turmas);
        } else if(choice == 0){
            encerrar(turmas);
            return 0;
        } else {
            system("cls");
            printf("[ERRO] DIGITE UM VALOR VÁLIDO.\n");
            continue;
        }
    }
    
    return 0;
}