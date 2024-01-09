//IGOR DE SOUZA MONTEIRO - RA: 168783 - NOTURNO
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX 100
 
//STRCUT QUE IRÁ ARMAZENAR A DATA DE CONTRATAÇÃO DOS FUNCIONÁRIOS
typedef struct Data {
    int dia, ano, mes;
}TData;
 
//ESTRUTURA DO NODO 
typedef struct Nodo {
    char info[TAM_MAX];
    struct Nodo *prox;
    struct Nodo *prim;
    TData *data;
}TNodo;
 
typedef TNodo *PNodo;
 
//INICIALIZA A RAIZ COMO NULL
PNodo start(){
    return NULL;
}
 
//IMPRIME NA FORMA PRE FIXA A ARVORE
void imprimirPre(PNodo raiz){
    if(raiz == NULL)
        return;
    
    printf("%s\n", raiz->info);
    imprimirPre(raiz->prim);
    imprimirPre(raiz->prox);
}
 
//LIBERA EM ORDEM POS FIXA A ARVORE
PNodo liberar(PNodo raiz){
    if(raiz == NULL)
        return NULL;
    
    raiz->prim = liberar(raiz->prim);
    raiz->prox = liberar(raiz->prox);
    free(raiz->data);
    free(raiz);
 
    return NULL;
}
 
//BUSCA O ENDEREÇO DE MEMORIA DE UM DETERMINADO VALOR NA MINHA AB
PNodo buscaGen(PNodo raiz, char *strPai){
    PNodo p;
 
    if(raiz == NULL || strcmp(raiz->info, strPai) == 0)
        return raiz;
    p = buscaGen(raiz->prim, strPai);
 
    if(p != NULL)
        return p;
    else 
        return buscaGen(raiz->prox, strPai);
}
 
PNodo criarNodo(char *string, int dia, int mes, int ano){
    PNodo novo;
 
    novo = (PNodo)malloc(sizeof(TNodo));
    if(novo == NULL)
        exit(1); //ERRO DE ALOCAÇÃO
 
    novo->prim = NULL;
    novo->prox = NULL;
    strcpy(novo->info, string); //RECEBE O NOME
 
    novo->data = (TData *)malloc(sizeof(TData));
    if (novo->data == NULL)
        exit(1); // ERRO DE ALOCAÇÃO
    novo->data->dia = dia;
    novo->data->mes = mes;
    novo->data->ano = ano;
 
    return novo;
}
 
//BUSCAR O PAI DE UM NODO 
 
PNodo buscarPai(PNodo raiz, PNodo filho) {
    PNodo pai;
    if (raiz == NULL || filho == NULL) {
        return NULL;
    }
 
    if (raiz->prim == filho || raiz->prox == filho) {
        return raiz;  // O pai foi encontrado
    }
 
    // Buscar nos filhos
    pai = buscarPai(raiz->prim, filho);
 
    // Se não encontrou o pai nos filhos, buscar nos irmãos
    if (pai == NULL) {
        pai = buscarPai(raiz->prox, filho);
    }
 
    return pai;
}
 
 
//VERIFICA SE UM VALOR EXISTE NA MINHA ARVORE (0 NÃO EXISTE 1 EXISTE)
int buscarNome(PNodo raiz, char *string){
    if(raiz == NULL)
        return 0;
    if(strcmp(raiz->info, string) == 0)
        return 1;
    
    return buscarNome(raiz->prim, string) || buscarNome(raiz->prox, string);
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
        else if(d1->mes > d2->mes)
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
 
PNodo inserir(PNodo raiz, char *strPai, char *strNome, int dia, int mes, int ano){
    PNodo pai, filho, p = NULL, q = NULL;
    
    if(raiz == NULL && strcmp(strPai, "fundador") == 0){
        //CRIAR O PRIMEIRO NODO
        //printf("PRIMEIRO NODO CRIADO");
        raiz = criarNodo(strNome, dia, mes, ano);
    } else if(raiz != NULL && strcmp(strPai, "fundador") != 0){
        pai = buscaGen(raiz, strPai); //buscar o endereço de memoria do pai
 
        //CASO O ENDEREÇO SEJA VALIDO, O PROGRAMA IRÁ ORGANIZAR OS NODOS
        if(pai != NULL){
            filho = criarNodo(strNome, dia, mes, ano);
 
            if(pai->prim == NULL || compData(filho->data, pai->prim->data) == -1){
                filho->prox = pai->prim;
                pai->prim = filho;
            } else {
                for(p = pai->prim; p->prox != NULL && (compData(filho->data, p->prox->data) >= 0);
                 p = p->prox);
 
                 q = p->prox;
                 p->prox = filho;
                 filho->prox = q;
            }
 
            //printf("NODO ADICIONADO.\n");
        }
 
    }
 
    return raiz;
}
 
int main(){
    PNodo raiz, p, q, r;
    int op, dia, mes, ano, verificarNome;
    char strNome[TAM_MAX], strPai[TAM_MAX];
 
    //system("cls");
 
    raiz = start(); //INICIA O NO RAIZ COM VALOR DE NULL
    
    do {
        //printf("1) CONTRATAR\n");
        //printf("2) DEMITIR\n");
        //printf("3) IMPRIMIR\n");
        //printf("4) SAIR\n");
 
        scanf("%d", &op);
 
        //system("cls");
 
        switch (op)
        {
        case 1:
            //CONTRATAR 
            //printf("DIGITE O NOME DO FUNCIONARIO A DATA DE CONTRATO E CONTRATANTE\n");
            scanf("%s %d %d %d %s", strNome, &dia, &mes, &ano, strPai);
            verificarNome = buscarNome(raiz, strNome); //VERIFICAR SE O NOME JÁ ESTÁ NA ARVORE
 
            if(verificarNome == 0){
                //printf("NOME APROVADO.\n");
                raiz = inserir(raiz, strPai, strNome, dia, mes, ano);
            }
 
            break;
        case 2:
            //DEMITIR
            //printf("NOME DO FUNCIONARIO A SER DEMITIDO.\n");
            scanf("%s", strNome);
            //verificarNome = buscarNome(raiz, strNome); //VERIFICA SE DIGITOU UM NOME VALIDO
            p = buscaGen(raiz, strNome); // busca o endereço (NODO) que será removido
 
            if(p != NULL){
                q = buscarPai(raiz, p); //BUSCAR O ENDEREÇO DO NODO QUE DÁ ORIGEM AO NO P
                //Q PODE DAR ORIGEM EM P COMO PRIM OU PROX
 
                if(q == NULL){
                    //O NODO NÃO POSSUI PAI, LOGO ELE É A RAIZ DA ARVORE
                    raiz = liberar(raiz);
                    //printf("REMOVEU O NO RAIZ\n");
                } else if(q->prim == p){
                    //FILHO (PRIM) DIRETO
                    q->prim = p->prox; //CONECTA O PAI COM O PROXIMO IRMÃO, CASO ELE EXISTA
                    p->prim = liberar(p->prim); //LIBERA TODOS OS DECENDENTES DE P(SEM CONSIDERAR SEUS PRIMEIROS IRMÃOS)
                    free(p->data);
                    free(p);
                } else if(q->prox == p){
                    //FILHO (IRMÃO)
                    q->prox = p->prox; //RECEBE O IRMÃO DE P, CASO ELE EXISTA
                    p->prim = liberar(p->prim);
                    free(p->data);
                    free(p);
                }
            }
            break;
 
        case 3:
            //IMPRIMIR
            imprimirPre(raiz);
            //printf("\n");
            break;
        
        default:
            if(op != 4){
                //printf("VALOR INVALIDO.\n");
            }
            break;
        }
 
    } while(op != 4);
 
 
    raiz = liberar(raiz); //LIBERA O RESTANTE DA ARVORE
 
    return 0;
}