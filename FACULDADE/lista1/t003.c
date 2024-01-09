#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Cliente
typedef struct Cliente {
    int id;
    int tempo_atendimento;
    struct Cliente* proximo;
} Cliente;

// Definição da estrutura Caixa
typedef struct Caixa {
    int numero;
    Cliente* fila;
} Caixa;

// Função para criar um novo cliente
Cliente* criarCliente(int id, int tempo) {
    Cliente* novoCliente = (Cliente*)malloc(sizeof(Cliente));
    if (novoCliente == NULL) {
        perror("Erro ao alocar memória para o cliente");
        exit(1);
    }
    novoCliente->id = id;
    novoCliente->tempo_atendimento = tempo;
    novoCliente->proximo = NULL;
    return novoCliente;
}

// Função para adicionar um cliente à fila de um caixa
void adicionarCliente(Caixa* caixa, Cliente* cliente) {
    if (caixa->fila == NULL) {
        caixa->fila = cliente;
    } else {
        Cliente* atual = caixa->fila;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = cliente;
    }
}

// Função para remover e atender um cliente de um caixa
void atenderCliente(Caixa* caixa) {
    if (caixa->fila != NULL) {
        Cliente* cliente_atendido = caixa->fila;
        caixa->fila = cliente_atendido->proximo;
        free(cliente_atendido);
    }
}

int main() {
    int num_clientes, num_caixas;
    
    printf("Digite o número de clientes: ");
    scanf("%d", &num_clientes);
    
    printf("Digite o número de caixas: ");
    scanf("%d", &num_caixas);
    
    Caixa caixas[num_caixas];
    
    for (int i = 0; i < num_caixas; i++) {
        caixas[i].numero = i + 1;
        caixas[i].fila = NULL;
    }
    
    for (int i = 0; i < num_clientes; i++) {
        int tempo;
        printf("Digite o tempo de atendimento do cliente %d: ", i + 1);
        scanf("%d", &tempo);
        
        // Encontre o caixa disponível com o menor número
        Caixa* caixa_disponivel = &caixas[0];
        for (int j = 1; j < num_caixas; j++) {
            if (caixas[j].fila == NULL || (caixas[j].fila->tempo_atendimento > caixa_disponivel->fila->tempo_atendimento)) {
                caixa_disponivel = &caixas[j];
            }
        }
        
        // Adicione o cliente ao caixa disponível
        Cliente* novoCliente = criarCliente(i + 1, tempo);
        adicionarCliente(caixa_disponivel, novoCliente);
    }
    
    // Atenda os clientes e exiba a ordem de atendimento
    for (int i = 0; i < num_clientes; i++) {
        for (int j = 0; j < num_caixas; j++) {
            if (caixas[j].fila != NULL) {
                printf("%d: %d ", caixas[j].numero, caixas[j].fila->id);
                atenderCliente(&caixas[j]);
            }
        }
        printf("\n");
    }
    
    return 0;
}
