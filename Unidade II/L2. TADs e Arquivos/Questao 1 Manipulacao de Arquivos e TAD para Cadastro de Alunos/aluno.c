#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

Aluno criar_aluno(int matricula, char nome[], float media) {
    Aluno aluno;
    aluno.matricula = matricula;
    strcpy(aluno.nome, nome);
    aluno.media = media;
    return aluno;
}

void salvar_aluno_em_arquivo(const char *nome_arquivo, Aluno aluno) {
    FILE *arquivo = fopen(nome_arquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fprintf(arquivo, "%d,%s,%.2f\n", aluno.matricula, aluno.nome, aluno.media);
    fclose(arquivo);
}

void exibir_alunos(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    Aluno aluno;
    while (fscanf(arquivo, "%d,%[^,],%f\n", &aluno.matricula, aluno.nome, &aluno.media) != EOF) {
        printf("Matrícula: %d\n", aluno.matricula);
        printf("Nome: %s\n", aluno.nome);
        printf("Média: %.2f\n", aluno.media);
        printf("\n");
    }

    fclose(arquivo);
}
