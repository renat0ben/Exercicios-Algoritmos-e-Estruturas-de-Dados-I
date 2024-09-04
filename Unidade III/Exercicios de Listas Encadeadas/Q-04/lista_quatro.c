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
        novo_no->proximo = novo_no;  // Lista vazia, aponta para ele mesmo
        *cabeca = novo_no;
    } else {
        No *temp = *cabeca;
        while (temp->proximo != *cabeca) {
            temp = temp->proximo;
        }
        novo_no->proximo = *cabeca;
        temp->proximo = novo_no;
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
        novo_no->proximo = novo_no;  // Lista vazia, aponta para ele mesmo
        *cabeca = novo_no;
    } else {
        No *temp = *cabeca;
        while (temp->proximo != *cabeca) {
            temp = temp->proximo;
        }
        temp->proximo = novo_no;
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
    } while (temp != cabeca);
    printf("(volta ao início)\n");
}

// Função para buscar um valor na lista circular
int buscar(No *cabeca, int valor) {
    if (cabeca == NULL) {
        return -1;
    }

    No *temp = cabeca;
    int posicao = 0;
    do {
        if (temp->valor == valor) {
            return posicao;
        }
        temp = temp->proximo;
        posicao++;
    } while (temp != cabeca);

    return -1;  // Valor não encontrado
}

// Função para remover o primeiro elemento da lista circular
void remover_primeiro(No **cabeca) {
    if (*cabeca == NULL) {
        printf("A lista está vazia, nada a remover.\n");
        return;
    }

    No *temp = *cabeca;
    if (temp->proximo == *cabeca) {
        // Apenas um nó na lista
        free(temp);
        *cabeca = NULL;
    } else {
        No *ultimo = *cabeca;
        while (ultimo->proximo != *cabeca) {
            ultimo = ultimo->proximo;
        }
        *cabeca = (*cabeca)->proximo;
        ultimo->proximo = *cabeca;
        free(temp);
    }
}

// Função para remover o último elemento da lista circular
void remover_ultimo(No **cabeca) {
    if (*cabeca == NULL) {
        printf("A lista está vazia, nada a remover.\n");
        return;
    }

    No *temp = *cabeca;
    if (temp->proximo == *cabeca) {
        // Apenas um nó na lista
        free(temp);
        *cabeca = NULL;
    } else {
        No *anterior = NULL;
        while (temp->proximo != *cabeca) {
            anterior = temp;
            temp = temp->proximo;
        }
        anterior->proximo = *cabeca;
        free(temp);
    }
}

// Função para remover um nó com valor específico
void remover_valor(No **cabeca, int valor) {
    if (*cabeca == NULL) {
        printf("A lista está vazia, nada a remover.\n");
        return;
    }

    No *temp = *cabeca;
    No *anterior = NULL;

    // Procurar o nó com o valor
    do {
        if (temp->valor == valor) {
            if (anterior == NULL) {
                remover_primeiro(cabeca);  // Remover o primeiro nó se for o caso
            } else {
                anterior->proximo = temp->proximo;
                if (temp == *cabeca) {
                    *cabeca = anterior->proximo;
                }
                free(temp);
            }
            return;
        }
        anterior = temp;
        temp = temp->proximo;
    } while (temp != *cabeca);

    printf("Valor %d não encontrado na lista.\n", valor);
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

    // Testando busca
    int posicao = buscar(lista, 30);
    if (posicao != -1) {
        printf("Valor 30 encontrado na posição %d.\n", posicao);
    } else {
        printf("Valor 30 não encontrado.\n");
    }

    // Testando remoção do primeiro
    remover_primeiro(&lista);
    printf("Lista após remover o primeiro elemento: ");
    exibir_lista(lista);

    // Testando remoção do último
    remover_ultimo(&lista);
    printf("Lista após remover o último elemento: ");
    exibir_lista(lista);

    // Testando remoção de um valor específico
    remover_valor(&lista, 30);
    printf("Lista após remover o valor 30: ");
    exibir_lista(lista);

    return 0;
}
