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

// Função para buscar um valor na lista e retornar a posição
int buscar(No *cabeca, int valor) {
    No *temp = cabeca;
    int posicao = 0;
    while (temp != NULL) {
        if (temp->valor == valor) {
            return posicao;
        }
        temp = temp->proximo;
        posicao++;
    }
    return -1; // Retorna -1 se o valor não for encontrado
}

// Função para remover um nó com um valor específico da lista
void remover_valor(No **cabeca, int valor) {
    if (*cabeca == NULL) {
        printf("A lista está vazia, nada a remover.\n");
        return;
    }
    No *temp = *cabeca;
    No *anterior = NULL;

    // Procurando o nó a ser removido
    while (temp != NULL && temp->valor != valor) {
        anterior = temp;
        temp = temp->proximo;
    }

    if (temp == NULL) {
        printf("Valor %d não encontrado na lista.\n", valor);
        return;
    }

    // Remover o nó
    if (anterior == NULL) {
        *cabeca = temp->proximo; // O nó a ser removido é o primeiro
    } else {
        anterior->proximo = temp->proximo;
    }
    free(temp);
}

// Função para inserir um novo valor após um valor existente na lista
void inserir_apos(No *cabeca, int valor_existente, int novo_valor) {
    No *temp = cabeca;

    // Procurando o valor existente
    while (temp != NULL && temp->valor != valor_existente) {
        temp = temp->proximo;
    }

    if (temp == NULL) {
        printf("Valor %d não encontrado na lista.\n", valor_existente);
        return;
    }

    // Inserir o novo valor após o valor existente
    No *novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo_no->valor = novo_valor;
    novo_no->proximo = temp->proximo;
    temp->proximo = novo_no;
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

    // Testando busca
    int posicao = buscar(lista, 30);
    if (posicao != -1) {
        printf("Valor 30 encontrado na posição %d.\n", posicao);
    } else {
        printf("Valor 30 não encontrado.\n");
    }

    // Testando inserção após um valor existente
    inserir_apos(lista, 30, 35);
    printf("Lista após inserir 35 após 30: ");
    exibir_lista(lista);

    // Testando remoção de um valor específico
    remover_valor(&lista, 20);
    printf("Lista após remover o valor 20: ");
    exibir_lista(lista);

    return 0;
}
