#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct Carro {
    char marca[15];
    char cor[10];
    int ano;
    float preco;
};

typedef struct Carro Carro;

void formatarString(char string[]){
    int j;
    string[strlen(string) - 1] = '\0';

    for(j = 0; j < strlen(string); j++){
        string[j] = toupper(string[j]);
    }
}

void requerimento(Carro *registro, int registros){
    int i;
    char string[15];

    for(i = 0; i < registros; i++){
        getchar();
        system("cls");

        printf("DIGITE O MODELO DO CARRO %d:\n => ", i + 1);
        fgets(string, sizeof(string), stdin);
        formatarString(string);
        strcpy(registro[i].marca, string);

        printf("DIGITE A COR DO CARRO %d:\n => ", i + 1);
        fgets(string, sizeof(string), stdin); 
        formatarString(string);
        strcpy(registro[i].cor, string);

        do {
            printf("DIGITE O ANO DO CARRO %d:\n => ", i + 1);
            scanf("%d", &registro[i].ano);
        } while(registro[i].ano <= 0);

        do {
            printf("DIGITE O VALOR DO CARRO %d:\n => ", i + 1);
            scanf("%f", &registro[i].preco);
        } while(registro[i].preco <= 0);
    }

    system("cls");
}

void exibir(Carro *registro, int i){

    printf("MODELO: %s\n", registro[i].marca);
    printf("COR: %s\n", registro[i].cor);
    printf("ANO: %d\n", registro[i].ano);
    printf("VALOR: R$%.2f\n\n", registro[i].preco);
}

void funcao1(Carro *registro, int registros){
    int i;
    float valor;

    system("cls");

    printf("DIGITE O VALOR DESEJADO EM R$:\n => ");
    scanf("%f", &valor);

    for(i = 0; i < registros; i++){
        if(registro[i].preco <= valor){
            exibir(registro, i);
        }
    }
}

void funcao2(Carro *registro, int registros){
    int i, achou = 0;
    char string[15];

    getchar();

    system("cls");

    printf("DIGITE O MODELO DO CARRO:\n => ", i + 1);
    fgets(string, sizeof(string), stdin);
    formatarString(string);

    system("cls");

    for(i = 0; i < registros; i++){
        if(strcmp(registro[i].marca, string) == 0){
            exibir(registro, i);
            achou++;
        }
    }
}

void funcao3 (Carro *registro, int registros){
    int i, ano, achou = 0;
    char marca[15], cor[10];

    getchar();
    system("cls");

    printf("DIGITE O MODELO DO CARRO :\n => ");
    fgets(marca, sizeof(marca), stdin);
    formatarString(marca);

    printf("DIGITE A COR DO CARRO :\n => ");
    fgets(cor, sizeof(cor), stdin); 
    formatarString(cor);


    do {
        printf("DIGITE O ANO DO CARRO :\n => ");
        scanf("%d", &ano);
    } while(ano <= 0);

    system("cls");


    for(i = 0; i < registros; i++){
        if(strcmp(registro[i].marca, marca) == 0 && strcmp(registro[i].cor, cor) == 0 && registro[i].ano == ano){
            exibir(registro, i);
            achou++;
        }
    }

    if(achou == 0){
        printf("VALOR NAO ENCONTADO.\n");
    }

}


int main(){
    int registros, choice;
    Carro *registro;

    printf("DIGITE O NUMERO DE CARROS:\n => ");
    scanf("%d", &registros);

    if(registro == NULL){
        printf("[ERRO]");
        exit(1);
    }

    registro = (Carro *)malloc(sizeof(Carro) * registros);

    requerimento(registro, registros);

    while(1){
        printf("DIGITE 1 PARA VER CARROS DE UM DETERMINADO VALOR.\n");
        printf("DIGITE 2 PARA VERIFICAR AS MARCAS DE CARRO.\n");
        printf("DIGITE 3 PARA PROCURAR UM TIPO ESPECIFICO.\n");
        printf("DIGITE 0 PARA ENCERRAR O PROGRAMA.\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            funcao1(registro, registros);
            break;
        case 2:
            funcao2(registro, registros);
            break;
        case 3:
            funcao3(registro, registros);
            break;
        case 0:
            system("cls");
            free(registro);
            printf("PROGRAMA ENCERRADO.\n");
            return 0;
            break;
        
        default:
            printf("VALOR INVALIDO.\n");
            break;
        }
    }

    return 0;
}