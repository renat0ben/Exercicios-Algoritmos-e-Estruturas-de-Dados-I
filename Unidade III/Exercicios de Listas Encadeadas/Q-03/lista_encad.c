#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct No {
    int valor;
    struct No *proximo;
} No;

// Função para inserir no início da lista circular
void inserir_inicio(No **cabeca, int valor) {
    No *novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo_no->valor = valor;

    if (*cabeca == NULL) {
        // Se a lista estiver vazia, o novo nó aponta para ele mesmo
        novo_no->proximo = novo_no;
        *cabeca = novo_no;
    } else {
        No *temp = *cabeca;
        // Percorrer até o último nó da lista circular
        while (temp->proximo != *cabeca) {
            temp = temp->proximo;
        }
        // Novo nó aponta para o atual primeiro nó
        novo_no->proximo = *cabeca;
        // Último nó aponta para o novo nó
        temp->proximo = novo_no;
        // Atualizar a cabeça da lista
        *cabeca = novo_no;
    }
}

// Função para inserir no final da lista circular
void inserir_fim(No **cabeca, int valor) {
    No *novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo_no->valor = valor;

    if (*cabeca == NULL) {
        // Se a lista estiver vazia, o novo nó aponta para ele mesmo
        novo_no->proximo = novo_no;
        *cabeca = novo_no;
    } else {
        No *temp = *cabeca;
        // Percorrer até o último nó da lista circular
        while (temp->proximo != *cabeca) {
            temp = temp->proximo;
        }
        // Último nó aponta para o novo nó
        temp->proximo = novo_no;
        // Novo nó aponta para a cabeça, completando o ciclo
        novo_no->proximo = *cabeca;
    }
}

// Função para exibir todos os elementos da lista circular
void exibir_lista(No *cabeca) {
    if (cabeca == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    No *temp = cabeca;
    do {
        printf("%d -> ", temp->valor);
        temp = temp->proximo;
    } while (temp != cabeca);  // A condição de parada é quando chegamos de volta à cabeça
    printf("(volta ao início)\n");
}

// Função principal para testar as operações
int main() {
    No *lista = NULL;

    // Testando inserções
    inserir_inicio(&lista, 10);
    inserir_inicio(&lista, 20);
    inserir_fim(&lista, 30);
    inserir_fim(&lista, 40);

    printf("Lista circular após inserções: ");
    exibir_lista(lista);

    return 0;
}
