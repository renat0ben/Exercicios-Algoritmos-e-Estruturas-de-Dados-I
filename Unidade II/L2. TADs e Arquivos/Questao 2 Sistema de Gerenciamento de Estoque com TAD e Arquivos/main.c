#include <stdio.h>
#include "produto.h"

int main() {
    // Criação de um arquivo binário vazio
    FILE *arquivo = fopen("estoque.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }
    fclose(arquivo);

    // Adicionar produtos ao estoque
    Produto produto1 = criar_produto(101, "Cadeira", 15);
    adicionar_produto_ao_estoque("estoque.bin", produto1);

    Produto produto2 = criar_produto(102, "Mesa", 8);
    adicionar_produto_ao_estoque("estoque.bin", produto2);

    // Exibir todos os produtos no estoque
    exibir_estoque("estoque.bin");

    // Atualizar a quantidade em estoque de um produto
    atualizar_quantidade_estoque("estoque.bin", 101, 20);

    // Remover um produto do estoque
    remover_produto_do_estoque("estoque.bin", 102);

    // Exibir o estoque após atualizações
    exibir_estoque("estoque.bin");

    return 0;
}
