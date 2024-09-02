#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
    int matricula;
    char nome[100];
    float media;
} Aluno;

// Função para criar um aluno
Aluno criar_aluno(int matricula, char nome[], float media);

// Função para salvar um aluno no arquivo
void salvar_aluno_em_arquivo(const char *nome_arquivo, Aluno aluno);

// Função para exibir todos os alunos cadastrados no arquivo
void exibir_alunos(const char *nome_arquivo);

#endif
