#ifndef ALUNO_H
#define ALUNO_H

#include "disciplina.h"

typedef struct {
    char nome[100];
    int matricula;
    Disciplina* disciplinas[10];
    int num_disciplinas;
} Aluno;

// Função para criar um aluno
Aluno* cria_aluno(char nome[], int matricula);

// Função para matricular o aluno em uma disciplina
void matricula_disciplina(Aluno* aluno, Disciplina* disciplina);

// Função para liberar a memória de um aluno
void exclui_aluno(Aluno* aluno);

// Função para exibir as informações do aluno
void exibe_aluno(Aluno* aluno);

#endif
