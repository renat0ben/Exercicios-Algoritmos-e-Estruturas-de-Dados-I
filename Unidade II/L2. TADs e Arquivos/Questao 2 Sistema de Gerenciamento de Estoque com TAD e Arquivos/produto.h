#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {
    int codigo;
    char descricao[100];
    int quantidade;
} Produto;

// Função para criar um produto
Produto criar_produto(int codigo, char descricao[], int quantidade);

// Função para adicionar um produto ao estoque
void adicionar_produto_ao_estoque(const char *nome_arquivo, Produto produto);

// Função para remover um produto do estoque com base no código
void remover_produto_do_estoque(const char *nome_arquivo, int codigo);

// Função para atualizar a quantidade de um produto no estoque
void atualizar_quantidade_estoque(const char *nome_arquivo, int codigo, int nova_quantidade);

// Função para exibir todos os produtos no estoque
void exibir_estoque(const char *nome_arquivo);

#endif
