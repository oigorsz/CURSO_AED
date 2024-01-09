#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_LIVRO 15
#define TAM_AUTOR 20
#define TAM_ESTILO 10

struct Livro {
    char nome[TAM_LIVRO + 1];
    char autor[TAM_AUTOR + 1];
    char estilo[TAM_ESTILO + 1];
    int codigo;
    float valor;
};

typedef struct Livro Livro;


void incluir(Livro *p[], int *nl){
    int i = *nl;
    system("cls");

    printf("ADICIONANDO LIVRO.\n");

    if(i != 0){
        p = (Livro **)realloc(p, (i + 1) * sizeof(Livro *));

        if(p == NULL){
            printf("ERRO");
            exit(1);
        }
    } else {
        p[i] = (Livro *)malloc(sizeof(Livro));

        if(p[i] == 0){
            printf("ERRO");
            exit(1);
        }
    }

    printf("DIGITE O PREÇO DO LIVRO %d:\n", i + 1);
    scanf("%f", &p[i]->valor);

    (*nl)++;

}

int exibir(Livro *p[], int nl){
    int i;

    system("cls");

    printf("LISTA DE LIVROS:\n");

    for(i = 0; i < nl; i++){
        printf("LIVRO %d: %.2f\n", i + 1, p[i]->valor);
    }

    printf("\n\n\n");
}

void encerrar(Livro *p[], int nl){
    int i;
    system("cls");

    printf("PROGRAMA ENCERRADO.\n");

    for(i = 0; i < nl; i++){
        free(p[i]);
    }

    free(p);
}


int main(){
    char choice;
    int nl = 0;
    Livro **registro;

    registro = (Livro **)malloc(sizeof(Livro*));
    if(registro == NULL){
        printf("ERRO");
        exit(1);
    }

    system("cls");

    while (1)
    {
        printf("DIGITE I PARA INCLUIR UM LIVRO.\n");
        printf("DIGITE L PARA LISTAR OS NOMES DE TODOS OS LIVROS.\n");
        printf("DIGITE A PARA PROCURAR POR AUTOR.\n");
        printf("DIGITE T PARA PROCURAR LIVRO POR TITULO.\n");
        printf("DIGITE E PARA PROCURAR LIVRO POR ESTILO.\n");
        printf("DIGITE M PARA CALCULAR A MEDIA DE PRECO DE TODOS OS LIVROS.\n");
        printf("DIGITE S PARA ENCERRAR O PROGRAMA.\n");
        scanf("%c", &choice);

        choice = toupper(choice);

        switch (choice)
        {
        case 'I':
            incluir(registro, &nl);
            break;
        case 'L':
            exibir(registro, nl);
            break;
        case 'A':
            //PROCURAR LIVRO POR AUTOR
            break;
        case 'T':
            //PROCURAR LIVRO POR TITULO
            break;
        case 'E':
            //PROCURAR LIVRO POR ESTILO
            break;
        case 'M':
            //MEDIA DE PRECOS DE TODOS OS LIVROS
            break;
        case 'S':
            encerrar(registro, nl);
            return 0;
        
        default:
            //VALOR INVALIDO
            break;
        }
    }
    
    return 0;
}