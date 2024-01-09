#include <stdio.h>
#include <stdlib.h>
#define RET 1
#define TRI 2
#define CIR 3
#define PI 3.14

typedef struct Retangulo {
    float b;
    float h;
}Tret;

typedef struct Triangulo {
    float b;
    float h;
}Ttri;

typedef struct Circulo {
    float r;
}Tcir;

typedef struct Listagen {
    int tipo;
    void* info;
    struct Listagen *prox;
}TLista;

TLista *criaRet (float b, float h){
    Tret *r;
    TLista *p;

    //CRIA ESTRUTURA PARA O RETANGULO
    r = (Tret *)malloc(sizeof(Tret));
    r->b = b;
    r->h = h;

    //CRIA O NODO QUE APONTA PARA ESTRUTURA
    p = (TLista *)malloc(sizeof(TLista));
    p->tipo = RET;
    p->info = r;
    p->prox = NULL;

    return p;
}

TLista *criaTri (float b, float h){
    Ttri *t;
    TLista *p;

    //CRIA A ESTRUTURA TRIANGULO
    t = (Ttri*)malloc(sizeof(Ttri));
    t->b = b;
    t->h = h;

    //CRIA O NODO QUE APONTA PARA A ESTRUTURA TRIANGULO

    p = (TLista *)malloc(sizeof(TLista));
    p->tipo = TRI;
    p->info = t;
    p->prox = NULL;

    return p;
}

TLista *criaCir(float r){
    Tcir *c;
    TLista *p;

    //CRIA A ESTRUTURA CIRCULO
    c = (Tcir*)malloc(sizeof(Tcir));
    c->r = r;

    //CRIAR O NODO QUE ARMAZENA O PONTEIRO PARA ESTRUTURA

    p = (TLista *)malloc(sizeof(TLista));
    p->tipo = CIR;
    p->info = c;
    p->prox = NULL;

    return p;
}

TLista *iniciarLista(){
    return NULL;
}

float retArea(Tret *r){
    return r->b * r->h;
}

float triArea(Ttri *t){
    return t->b * t->h/2.0;
}

float cirArea(Tcir *c){
    return PI*c->r*c->r;
}

float area(TLista * l){
    float a;

    switch (l->tipo)
    {
    case RET:
        a = retArea(l->info);
        break;
    case TRI:
        a = triArea(l->info);     
        break;
    case CIR:
        a = cirArea(l->info);
        break;
    default:
        break;
    }

    return a;
}

TLista *MaxArea(TLista *l, float *maiorarea){
    float aMax = 0.0, a;
    TLista *p, *q; //AUXILIARES PARA FAZER AS BUSCAS
    q = NULL;

    for(p = l; p != NULL; p = p->prox){
        a = area(p);
        if(a > aMax){
            q = p;
            aMax = a;
        }
    }

    *maiorarea = aMax;
    return q;
}

void liberar(TLista *l){
    TLista *aux;

    while (l != NULL)
    {
        aux = l;
        l = l->prox;
        free(aux->info);
        free(aux);
    }
    
}

int main(){
    int op, tipo;
    float a, b, maiorarea;
    TLista *lista, *p;
    lista = iniciarLista();

    system("cls");

    do {
        printf("1) INSERIR\n");
        printf("2) CALCULAR MAIOR AREA\n");
        printf("3) SAIR\n");
        printf("OPCAO: ");
        scanf("%d", &op);

        system("cls");

        switch (op)
        {
        case 1:
            do {
                printf("TIPO DO OBJETO\n1-RETANGULO\n2-TRIANGULO\n3-CIRCULO.\n");
                scanf("%d", &tipo);
            } while (tipo > 3 || tipo < 1);

            system("cls");

            if(tipo == 1){
                //CRIAR RETANGULO
                do {
                    printf("DIGITE A BASE A ALTURA DO RETANGULO: ");
                    scanf("%f %f", &a, &b);
                } while (a < 0 || b < 0);

                p = criaRet(a, b);

            } else if(tipo == 2){
                //CRIAR TRIANGULO
                do {
                    printf("DIGITE A BASE A ALTURA DO TRIANGULO: ");
                    scanf("%f %f", &a, &b);
                } while (a < 0 || b < 0);

                p = criaTri(a, b);

            } else {
                //CRIAR CIRCULO
                do {
                    printf("DIGITE O RAIO DO CIRCULO: ");
                    scanf("%f", &a);
                } while (a < 0);

                p = criaCir(a);
            }

            //INSERIR P NA LISTA

            p->prox = lista;
            lista = p;
            break;
        case 2:
            //CALCULAR
            if(lista == NULL){
                printf("LISTA VAZIA.\n");
                break;
            }
            p = MaxArea(lista, &maiorarea);
            printf("A MAIOR ÁREA É DO: ");

            if(p->tipo == RET){
                Tret *q = p->info;
                printf("RETANGULO DE BASE %5.2f E ALTURA %5.2f.\n", q->b, q->h);
            } else if(p->tipo == TRI){
                Ttri *q = p->info;
                printf("TRIANGULO DE BASE %5.2f E ALTURA %5.2f.\n", q->b, q->h);
            } else {
                Tcir *q = p->info;
                printf("CIRCULO DE RAIO %5.2f.\n",q->r);
            }

            printf("\nAREA: %8.2f\n", maiorarea);

            break;
        default:
            if(op != 3)
                printf("OPÇÃO INVALIDA.\n");
            break;
        }


    } while (op != 3);

    liberar(lista);
    return 0;
}