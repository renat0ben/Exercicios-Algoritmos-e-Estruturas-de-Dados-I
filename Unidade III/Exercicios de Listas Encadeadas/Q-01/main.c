#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct No {
    int valor;
    struct No *proximo;
} No;

// Função para inserir no início da lista
void inserir_inicio(No **cabeca, int valor) {
    No *novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo_no->valor = valor;
    novo_no->proximo = *cabeca;
    *cabeca = novo_no;
}

// Função para inserir no final da lista
void inserir_fim(No **cabeca, int valor) {
    No *novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    if (*cabeca == NULL) {
        *cabeca = novo_no;
    } else {
        No *temp = *cabeca;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novo_no;
    }
}

// Função para exibir todos os elementos da lista
void exibir_lista(No *cabeca) {
    if (cabeca == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    No *temp = cabeca;
    while (temp != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

// Função para remover o primeiro elemento da lista
void remover_primeiro(No **cabeca) {
    if (*cabeca == NULL) {
        printf("A lista está vazia, nada a remover.\n");
        return;
    }
    No *temp = *cabeca;
    *cabeca = (*cabeca)->proximo;
    free(temp);
}

// Função principal para testar as operações
int main() {
    No *lista = NULL;

    // Testando inserções
    inserir_inicio(&lista, 10);
    inserir_inicio(&lista, 20);
    inserir_fim(&lista, 30);
    inserir_fim(&lista, 40);

    printf("Lista após inserções: ");
    exibir_lista(lista);

    // Testando remoção
    remover_primeiro(&lista);
    printf("Lista após remover o primeiro elemento: ");
    exibir_lista(lista);

    return 0;
}
