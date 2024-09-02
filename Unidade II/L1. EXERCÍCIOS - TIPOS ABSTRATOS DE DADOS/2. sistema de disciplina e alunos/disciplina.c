#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"

Disciplina* cria_disciplina(char nome[], int codigo) {
    Disciplina* disciplina = (Disciplina*) malloc(sizeof(Disciplina));
    if (disciplina != NULL) {
        strcpy(disciplina->nome, nome);
        disciplina->codigo = codigo;
    }
    return disciplina;
}

void exclui_disciplina(Disciplina* disciplina) {
    if (disciplina != NULL) {
        free(disciplina);
    }
}
