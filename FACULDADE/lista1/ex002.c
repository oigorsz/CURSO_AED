#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct Alunos {
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
    float media;
    char resultado[15];
};

typedef struct Alunos Alunos;

void formatarString(char string[]){
    int j;
    string[strlen(string) - 1] = '\0';

    for(j = 0; j < strlen(string); j++){
        string[j] = toupper(string[j]);
    }
}

int aprovados(Alunos *registro, int registros){
    int i, aprovados = 0;
    char stringA[] = "APROVADO", stringR[] = "REPROVADO";

    for(i = 0; i < registros; i++){
        if(registro[i].media >= 5) {
            strcpy(registro[i].resultado, stringA);
            aprovados++;
        } else {
            strcpy(registro[i].resultado, stringR);
        }
    }

    return aprovados;
}

void requerimento (Alunos *registro, int registros, int i) {
    char string[50];

    system("cls");

    getchar();

    printf("DIGITE O NOME DO ALUNO %d:\n => ", i + 1);
    fgets(string, sizeof(string), stdin);
    formatarString(string);

    strcpy(registro[i].nome, string);

    do {
        printf("DIGITE A NOTA 1 DO ALUNO %d :\n => ", i + 1);
        scanf("%f", &registro[i].nota1);
    } while(!(0 <= registro[i].nota1 && registro[i].nota1 <= 10));

    do {
        printf("DIGITE A NOTA 2 DO ALUNO %d:\n => ", i + 1);
        scanf("%f", &registro[i].nota2);
    } while(!(0 <= registro[i].nota2 && registro[i].nota2 <= 10));

    do {
        printf("DIGITE A NOTA 3 DO ALUNO %d:\n => ", i + 1);
        scanf("%f", &registro[i].nota3);
    } while(!(0 <= registro[i].nota3 && registro[i].nota3 <= 10));


    registro[i].media = (registro[i].nota1 + registro[i].nota2 + registro[i].nota3) / 3;
}

void printar(Alunos *registro, int registros){
    int i, aprov, reprov;

    aprov = aprovados(registro, registros);
    reprov = registros - aprov;

    system("cls");
    printf("REGISTROS\n");

    for(i = 0; i < registros; i++){
        printf("NOME %d: %s\n", i + 1, registro[i].nome);
        printf("NOTAS : %.2f %.2f %.2f\n", registro[i].nota1, registro[i].nota2, registro[i].nota3);
        printf("MEDIA: %.2f\n", registro[i].media);
        printf("RESULTADO: %s\n\n", registro[i].resultado);
    }

    printf("TOTAL DE ALUNOS: %d\n", registros);
    printf("APROVADOS: %d\n", aprov);
    printf("REPROVADOS: %d\n", reprov);

}


int main(){
    int registros, i;
    Alunos *registro;

    system("cls");

    printf("DIGITE O NUMERO DE REGISTROS:\n => ");
    scanf("%d", &registros);

    registro = (Alunos *)malloc(sizeof(Alunos) * registros);

    if(registro == NULL){
        printf("[ERRO]");
        exit(1);
    }

    for(i = 0; i < registros; i++){
        requerimento(registro, registros, i);
    }

    printar(registro, registros);

    

    return 0;
}