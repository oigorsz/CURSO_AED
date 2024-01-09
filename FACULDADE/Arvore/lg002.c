#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BALEIA 0
#define ELEFANTE 1
#define TIGRE 2
#define URSO 3
#define TAM 50


typedef struct Listagen {
    int tipo;
    void *info;
    struct Listagen * prox;
}Tlista;

typedef struct Baleia {
    float peso;
    char especie[TAM];
}Tbaleia;

typedef struct Elefante {
    float peso;
    char alimentos[TAM];
}Telefante;

typedef struct Urso {
    char local[TAM];
    char especie[TAM];
}Turso;

typedef struct Tigre {
    char local[TAM];
    int dentes;
    int ninhada;
}Ttigre;

Tlista *criarBaleia(float peso, char *especie){
    Tlista *p;
    Tbaleia *b;

    //CRIA A ESTRUTURA BALEIA
    b = (Tbaleia *)malloc(sizeof(Tbaleia));
    b->peso = peso;
    strcpy(b->especie, especie);

    //CRIAR O NODO QUE APONTA PARA A ESTRUTURA
    p = (Tlista *)malloc(sizeof(Tlista));
    p->tipo = BALEIA;
    p->info = b;
    p->prox = NULL;

    return p;
}

Tlista *criarElefante(float peso, char *alimentos){
    Telefante *e;
    Tlista *p;

    //CRIAR ESTRUTURA ELEFANTE
    e = (Telefante *)malloc(sizeof(Telefante));
    e->peso = peso;
    strcpy(e->alimentos, alimentos);

    //CRIAR O NODO QUE APONTA PARA A ESTRUTURA
    p = (Tlista *)malloc(sizeof(Tlista));
    p->tipo = ELEFANTE;
    p->info = e;
    p->prox = NULL;

    return p;
}

Tlista *criarTigre(char *local, int dentes, int ninhada){
    Ttigre *t;
    Tlista *p;

    t = (Ttigre *)malloc(sizeof(Ttigre));
    strcpy(t->local, local);
    t->dentes = dentes;
    t->ninhada = ninhada;

    p = (Tlista *)malloc(sizeof(Tlista));
    p->tipo = TIGRE;
    p->info = t;
    p->prox = NULL;

    return p;
}

Tlista *criarUrso(char *local, char *especie){
    Turso *u;
    Tlista *p;

    u = (Turso *)malloc(sizeof(Turso));
    strcpy(u->local, local);
    strcpy(u->especie, especie);

    p = (Tlista *)malloc(sizeof(Tlista));
    p->tipo = URSO;
    p->info = u;
    p->prox = NULL;

    return p;
}


Tlista *iniciarLista(){
    return NULL;
}

void liberar(Tlista *l){
    Tlista *p;

    while (l != NULL)
    {
        p = l;
        l = l->prox;
        free(p->info);
        free(p);
    }
    
}

void imprimir(Tlista *l){
    Tlista *p,*q;

    printf("\n");

    for(p = l; p != NULL; p = p->prox){

        //EXIBIR O TIPO
        if(p->tipo == BALEIA){
            Tbaleia *q = p->info;
            printf("\nBALEIA- PESO: %5.2f, ESPECIE: %s", q->peso, q->especie);
        } else if(p->tipo == ELEFANTE){
            Telefante *q = p->info;
            printf("\nELEFANTE- PESO: %5.2f, ALIMENTOS: %s", q->peso, q->alimentos);
        } else if(p->tipo == TIGRE){
            Ttigre *q = p->info;
            printf("\nTIGRE- LOCAL: %s, DENTES: %d, NINHADA: %d", q->local, q->dentes, q->ninhada);
        } else {
            Turso *q = p->info;
            printf("\nURSO- LOCAL: %s, ESPECIE: %s", q->local, q->especie);
        }
    }

    printf("\n\n");
}

int main(){
    int op, tipo, dentes, ninhada;
    char especie[TAM], alimentos[TAM], local[TAM];
    float peso;
    Tlista *lista, *p, *q;
    lista = iniciarLista();

    system("cls");

    do {
        printf("1) ADICIONAR\n");
        printf("2) REMOVER\n");
        printf("3) IMPRIMIR\n");
        printf("0) SAIR.\n");
        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 1:
            //ADICIONAR
            do {
                printf("DIGITE O TIPO DO ANIMAL\n0-BALEIA\n1-ELEFANTE\n2-TIGRE\n 3-URSO");
                printf("\nOPCAO: ");
                scanf("%d", &tipo);
            } while (tipo < 0 || tipo > 3);

            system("cls");

            if(tipo == 0){
                //ADD BALEIA
                do {
                    printf("DIGITE O PESO E A ESPECIE: ");
                    scanf("%f %s", &peso, especie);
                } while(peso < 0);

                p = criarBaleia(peso, especie);

            } else if(tipo == 1){
                //ADD ELEFANTE

                do {
                    printf("DIGITE O PESO E ALIMENTO: ");
                    scanf("%f %s", &peso, alimentos);
                } while(peso < 0);

                p = criarElefante(peso, alimentos);

            } else if(tipo == 2){
                //ADD TIGRE
                do {
                    printf("DIGITE O LOCAL, NUMERO DE DENTES E NINHADA: ");
                    scanf("%s %d %d", local, &dentes, &ninhada);
                } while(dentes < 0 || dentes > 100 || ninhada < 0 || ninhada > 100);

                p = criarTigre(local, dentes, ninhada);
            } else {
                //ADD URSO
                printf("DIGITE O LOCAL E A ESPECIE: ");
                scanf("%s %s", local, especie);
                
                p = criarUrso(local, especie);

            }

            //ADICIONAR A LISTA

            p->prox = lista;
            lista = p;
            break;
        case 2:
            //REMOVER

            if(lista == NULL){
                printf("LISTA VAZIA.\n");
                break;
            }

            q = lista;
            lista = lista->prox;
            free(q);
            break;
        case 3:
            //IMPRIMIR
            imprimir(lista);
            break;
        default:
            if(op != 0){
                printf("OPÇÃO INVALIDA.\n");
            }
            break;
        }
    } while(op != 0);


    liberar(lista);
    return 0;
}