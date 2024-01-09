#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h> // Para INT_MAX

typedef struct Cliente {
    int id;
    int tempoA;
    struct Cliente* prox;
} TCliente;

typedef TCliente* PCliente;

typedef struct Caixas {
    int num;
    PCliente fila;
    int tempoLivre;
} TCaixas;

typedef TCaixas* PCaixas;

// Função para inicializar uma fila vazia
PCliente inicializarFila() {
    return NULL;
}

// Função para inserir um cliente no final da fila
PCliente inserirCliente(PCliente fila, int id, int tempoA) {
    PCliente novo_cliente = (PCliente)malloc(sizeof(TCliente));
    novo_cliente->id = id;
    novo_cliente->tempoA = tempoA;
    novo_cliente->prox = NULL;

    if (fila == NULL) {
        return novo_cliente;
    }

    PCliente temp = fila;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = novo_cliente;
    return fila;
}

// Função para remover o cliente da frente da fila
PCliente removerCliente(PCliente fila) {
    if (fila == NULL) {
        return NULL; // Fila vazia, não há nada para remover
    }
    PCliente temp = fila->prox;
    free(fila);
    return temp;
}

// Função para buscar um cliente pelo ID na fila
PCliente buscarCliente(PCliente fila, int id) {
    PCliente temp = fila;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp; // Encontrou o cliente com o ID especificado
        }
        temp = temp->prox;
    }
    return NULL; // Cliente não encontrado na fila
}

int main() {
    int i, j, tempo_Atend, num_clientes, num_caixas;
    PCaixas caixas;

    system("cls");

    // RECEBER O NÚMERO DE CLIENTES E CAIXAS

    do {
        scanf("%d %d", &num_clientes, &num_caixas);
    } while (!(1 <= num_clientes && num_clientes <= 1023 && 1 <= num_caixas && num_caixas <= 25));

    // CRIAR A ESTRUTURA DE CAIXAS

    caixas = (PCaixas)malloc(sizeof(TCaixas) * num_caixas);

    for (i = 0; i < num_caixas; i++) {
        caixas[i].num = i + 1;
        caixas[i].fila = inicializarFila();
        caixas[i].tempoLivre = 0; // Tempo livre inicial é zero
    }

    // INSERIR OS CLIENTES NOS CAIXAS

    for (i = 0; i < num_clientes; i++) {
        do {
            scanf("%d", &tempo_Atend);
        } while (!(0 <= tempo_Atend && tempo_Atend <= 1000));

        // Encontrar o caixa com o tempo livre mais cedo
        int caixa_menor_tempo = 0;
        int menor_tempo_livre = caixas[0].tempoLivre;

        for (j = 1; j < num_caixas; j++) {
            if (caixas[j].tempoLivre < menor_tempo_livre) {
                caixa_menor_tempo = j;
                menor_tempo_livre = caixas[j].tempoLivre;
            }
        }

        // Inserir o cliente na fila do caixa selecionado
        caixas[caixa_menor_tempo].fila = inserirCliente(caixas[caixa_menor_tempo].fila, i + 1, tempo_Atend);

        // Atualizar o tempo livre do caixa
        caixas[caixa_menor_tempo].tempoLivre += tempo_Atend;
    }

    // Imprimir as filas de clientes atendidos por cada caixa no formato especificado
    for (i = 0; i < num_caixas; i++) {
        printf("%d: ", caixas[i].num);
        PCliente temp = caixas[i].fila;
        while (temp != NULL) {
            printf("%d", temp->id);
            temp = temp->prox;
            if (temp != NULL) {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Continue com o restante da lógica do seu programa

    return 0;
}
