#include <stdio.h>
#include "aluno.h"

int main() {
    // Criação de um arquivo vazio
    FILE *arquivo = fopen("alunos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }
    fclose(arquivo);

    // Adicionar alunos ao arquivo
    Aluno aluno1 = criar_aluno(123, "Maria", 8.5);
    salvar_aluno_em_arquivo("alunos.txt", aluno1);

    Aluno aluno2 = criar_aluno(456, "João", 7.8);
    salvar_aluno_em_arquivo("alunos.txt", aluno2);

    // Exibir todos os alunos cadastrados
    exibir_alunos("alunos.txt");

    return 0;
}
