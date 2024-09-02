#ifndef DISCIPLINA_H
#define DISCIPLINA_H

typedef struct {
    char nome[100];
    int codigo;
} Disciplina;

// Função para criar uma disciplina
Disciplina* cria_disciplina(char nome[], int codigo);

// Função para liberar a memória de uma disciplina
void exclui_disciplina(Disciplina* disciplina);

#endif
