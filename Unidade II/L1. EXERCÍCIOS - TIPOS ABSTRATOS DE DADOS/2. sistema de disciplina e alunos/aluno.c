#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

Aluno* cria_aluno(char nome[], int matricula) {
    Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));
    if (aluno != NULL) {
        strcpy(aluno->nome, nome);
        aluno->matricula = matricula;
        aluno->num_disciplinas = 0;
    }
    return aluno;
}

void matricula_disciplina(Aluno* aluno, Disciplina* disciplina) {
    if (aluno->num_disciplinas < 10) {
        for (int i = 0; i < aluno->num_disciplinas; i++) {
            if (aluno->disciplinas[i]->codigo == disciplina->codigo) {
                printf("Aluno já está matriculado nesta disciplina.\n");
                return;
            }
        }
        aluno->disciplinas[aluno->num_disciplinas] = disciplina;
        aluno->num_disciplinas++;
    } else {
        printf("Limite de disciplinas atingido.\n");
    }
}

void exclui_aluno(Aluno* aluno) {
    if (aluno != NULL) {
        free(aluno);
    }
}

void exibe_aluno(Aluno* aluno) {
    if (aluno != NULL) {
        printf("Nome: %s\n", aluno->nome);
        printf("Matrícula: %d\n", aluno->matricula);
        printf("Disciplinas:\n");
        for (int i = 0; i < aluno->num_disciplinas; i++) {
            printf("  %s (Código: %d)\n", aluno->disciplinas[i]->nome, aluno->disciplinas[i]->codigo);
        }
    }
}
