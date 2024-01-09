//IGOR DE SOUZA MONTEIRO - RA: 168783 - NOTURNO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX 100

//STRCUT QUE IRÁ ARMAZENAR A DATA DE CONTRATAÇÃO DOS FUNCIONÁRIOS
typedef struct Data {
    int dia, mes, ano;
}TData;

//ESTRUTURA DO NODO 
typedef struct Nodo {
    char nome[TAM_MAX];
    TData *data;
    struct Nodo *prim;
    struct Nodo *prox;
}TNodo;

typedef TNodo *PNodo;

PNodo start(){
    return NULL;
}

void liberarTudo(PNodo raiz){
    if(raiz == NULL)
        return;
    
    liberarTudo(raiz->prim);
    liberarTudo(raiz->prox);
    free(raiz);
}

void imprimirPre(PNodo raiz){
    if(raiz == NULL)
        return;

    printf("%s %d\n ", raiz->nome, raiz->data->ano);
    imprimirPre(raiz->prim);
    imprimirPre(raiz->prox);
}

/*PNodo liberarSub(PNodo raiz){
    if(raiz == NULL)
        return NULL;
    
    raiz->prim = liberarSub(raiz->prim->prox);
    raiz->prox = liberarSub(raiz->prim);
    free(raiz->data);
    free(raiz);

    return NULL;
}*/

PNodo criarNodo(char *string, int dia, int mes, int ano){
    PNodo novo;

    novo = (PNodo)malloc(sizeof(TNodo));
    if(novo == NULL)
        exit(1); //ERRO DE ALOCAÇÃO

    novo->prim = NULL;
    novo->prox = NULL;
    strcpy(novo->nome, string); //RECEBE O NOME

    novo->data = (TData *)malloc(sizeof(TData));
    if (novo->data == NULL)
        exit(1); // ERRO DE ALOCAÇÃO
    novo->data->dia = dia;
    novo->data->mes = mes;
    novo->data->ano = ano;

    return novo;
}

PNodo buscarGen(PNodo raiz, char *chave){
    PNodo p;

    if(raiz == NULL || strcmp(raiz->nome, chave) == 0)
        return raiz;
    
    p = buscarGen(raiz->prim, chave);

    if(p != NULL)
        return p;
    return buscarGen(p->prox, chave);
}


int busca(PNodo raiz, char *chave){
    if(raiz == NULL)
        return 0;
    if(strcmp(chave, raiz->nome) == 0) //SE UM NO TIVER O MESMO VALOR DE CHAVE
        return 1;

    return busca(raiz->prim, chave) || busca(raiz->prox, chave);
}

int compData(TData *d1, TData *d2){
    //COMPARAR OS ANOS
    if(d1->ano < d2->ano)
        return -1;
    else if(d1->ano > d2->ano)
        return 1;
    else {
        //COMPARAR OS MESES
        if(d1->mes < d2->mes)
            return -1;
        else if(d1->mes > d1->mes)
            return 1;
        else {
            //COMPARAR DIAS
            if(d1->dia < d2->dia)
                return -1;
            else if(d1->dia > d2->dia)
                return 1;
            else {
                return 0; //TODAS AS DATAS SÃO IGUAIS
            }
        }
        
    }
    
}

void inserir(PNodo raiz, char *p, char *f, int dia, int mes, int ano){
    PNodo pai, filho, antecessor;
    
    pai = buscarGen(raiz, p); //BUSCAR O ENDEREÇO DE MEMORIA DO NO ANTECESSOR A PARTIR DA SUA STRING
    //IF RAIZ == NULL (NODO RAIZ AINDA NÃO CRIADO) IF PAI == NULL (NODO ANTECESSOR NÃO ENCONTRADO OU NÃO VALIDO)

    if(raiz != NULL && pai != NULL){
        filho = criarNodo(f, dia, mes, ano);
        //ORDENAR OS NODOS FILHOS A PARTIR DA DATA

        if(pai->prim == NULL || compData(filho->data, pai->prim->data) < 0){
            filho->prox = pai->prim;
            pai->prim = filho;
        } else {

            for(antecessor = pai->prim; antecessor->prox != NULL && 
            compData(antecessor->data, filho->data) >= 0; antecessor = antecessor->prox);

            filho->prox = antecessor->prox;
            antecessor->prox = filho;
        }
    }
}


int main(){
    PNodo raiz, filho;
    int op, dia, mes, ano, verificarNome;
    char strNome[TAM_MAX], strPai[TAM_MAX];

    system("cls");

    raiz = start(); //INICIA O NO RAIZ COM VALOR DE NULL
    
    do {
        printf("1) CONTRATAR\n");
        printf("2) DEMITIR\n");
        printf("3) IMPRIMIR\n");
        printf("4) SAIR\n");

        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 1:
            //CONTRATAR
            //VERIFICAR OS LIMITES DE DIA, MES, ANO
            printf("DIGITE O NOME DO FUNCIONARIO, O DIA, MES E ANO DE CONTRATO\n");
            scanf("%s %d %d %d %s", strNome, &dia, &mes, &ano, strPai);

            //VERIFICAR SE A RAIZ JÁ POSSUI UM NODO

            if(strcmp(strNome, "fundador") != 0){
                if(raiz == NULL && strcmp(strPai, "fundador") == 0){
                    //CRIAR O PRIMEIRO NO RAIZ QUE TEM ORIGEM NO FUNDADOR
                    raiz = criarNodo(strNome, dia, mes, ano);
                    printf("\nRAIZ CRIADA - %s\n", raiz->nome);
                } else if(raiz != NULL && strcmp(strPai, "fundador") != 0) {
                    verificarNome = busca(raiz, strNome); //SE 0 NOME LIBERADO

                    if(verificarNome == 0) {
                        inserir(raiz, strPai, strNome, dia, mes, ano);
                    }
                }
            }

            break;
        case 2:
            //DEMITIR
            break;

        case 3:
            //IMPRIMIR
            imprimirPre(raiz);
            printf("\n");
            break;
        
        default:
            if(op != 4){
                printf("VALOR INVALIDO.\n");
            }
            break;
        }

    } while(op != 4);


    liberarTudo(raiz);
    //raiz = liberarSub(raiz); //LIBERA MINHA ARVORE BINÁRIA
    return 0;
}