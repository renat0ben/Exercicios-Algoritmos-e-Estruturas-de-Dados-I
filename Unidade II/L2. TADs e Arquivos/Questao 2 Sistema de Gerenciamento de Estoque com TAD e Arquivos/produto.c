#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

Produto criar_produto(int codigo, char descricao[], int quantidade) {
    Produto produto;
    produto.codigo = codigo;
    strcpy(produto.descricao, descricao);
    produto.quantidade = quantidade;
    return produto;
}

void adicionar_produto_ao_estoque(const char *nome_arquivo, Produto produto) {
    FILE *arquivo = fopen(nome_arquivo, "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fwrite(&produto, sizeof(Produto), 1, arquivo);
    fclose(arquivo);
}

void remover_produto_do_estoque(const char *nome_arquivo, int codigo) {
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    FILE *temp = fopen("temp.bin", "wb");
    if (temp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    Produto produto;
    int encontrado = 0;
    while (fread(&produto, sizeof(Produto), 1, arquivo)) {
        if (produto.codigo == codigo) {
            encontrado = 1;
        } else {
            fwrite(&produto, sizeof(Produto), 1, temp);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove(nome_arquivo);
    rename("temp.bin", nome_arquivo);

    if (encontrado) {
        printf("Produto removido com sucesso.\n");
    } else {
        printf("Produto não encontrado.\n");
    }
}

void atualizar_quantidade_estoque(const char *nome_arquivo, int codigo, int nova_quantidade) {
    FILE *arquivo = fopen(nome_arquivo, "rb+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Produto produto;
    int encontrado = 0;
    while (fread(&produto, sizeof(Produto), 1, arquivo)) {
        if (produto.codigo == codigo) {
            produto.quantidade = nova_quantidade;
            fseek(arquivo, -sizeof(Produto), SEEK_CUR);
            fwrite(&produto, sizeof(Produto), 1, arquivo);
            encontrado = 1;
            break;
        }
    }

    fclose(arquivo);

    if (encontrado) {
        printf("Quantidade atualizada com sucesso.\n");
    } else {
        printf("Produto não encontrado.\n");
    }
}

void exibir_estoque(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Produto produto;
    while (fread(&produto, sizeof(Produto), 1, arquivo)) {
        printf("Código: %d\n", produto.codigo);
        printf("Descrição: %s\n", produto.descricao);
        printf("Quantidade: %d\n", produto.quantidade);
        printf("\n");
    }

    fclose(arquivo);
}
