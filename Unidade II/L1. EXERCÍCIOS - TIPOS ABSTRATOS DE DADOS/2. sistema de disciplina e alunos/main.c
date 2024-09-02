#include <stdio.h>
#include <stdlib.h>
#include "disciplina.h"
#include "aluno.h"

int main() {
    // Criação de disciplinas
    Disciplina* disciplina1 = cria_disciplina("Matemática", 101);
    Disciplina* disciplina2 = cria_disciplina("História", 102);

    // Criação de alunos
    Aluno* aluno1 = cria_aluno("João", 2023001);
    Aluno* aluno2 = cria_aluno("Maria", 2023002);

    // Matrícula de alunos em disciplinas
    matricula_disciplina(aluno1, disciplina1);
    matricula_disciplina(aluno1, disciplina2);
    matricula_disciplina(aluno2, disciplina1);

    // Exibição das informações dos alunos
    exibe_aluno(aluno1);
    exibe_aluno(aluno2);

    // Liberação de memória
    exclui_aluno(aluno1);
    exclui_aluno(aluno2);
    exclui_disciplina(disciplina1);
    exclui_disciplina(disciplina2);

    return 0;
}
