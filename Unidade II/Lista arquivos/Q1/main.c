#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 100
#define MAX_NOME 100
#define MAX_NOTAS 10

typedef struct {
    char nome[MAX_NOME];
    float notas[MAX_NOTAS];
    int num_notas;
    float media;
    char situacao[10];
} Aluno;

void calcular_media_e_situacao(Aluno *aluno) {
    float soma = 0.0;
    for (int i = 0; i < aluno->num_notas; i++) {
        soma += aluno->notas[i];
    }
    aluno->media = soma / aluno->num_notas;
    strcpy(aluno->situacao, (aluno->media >= 7.0) ? "aprovado" : "reprovado");
}

void processar_arquivo(const char *entrada, const char *saida) {
    FILE *arquivo_entrada = fopen(entrada, "r");
    FILE *arquivo_saida = fopen(saida, "w");

    if (arquivo_entrada == NULL || arquivo_saida == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    Aluno alunos[MAX_ALUNOS];
    int contador_alunos = 0;

    while (fscanf(arquivo_entrada, "%[^\t]\t", alunos[contador_alunos].nome) != EOF) {
        int i = 0;
        while (fscanf(arquivo_entrada, "%f", &alunos[contador_alunos].notas[i]) == 1) {
            i++;
            if (fgetc(arquivo_entrada) == '\n') {
                break;
            }
        }
        alunos[contador_alunos].num_notas = i;
        calcular_media_e_situacao(&alunos[contador_alunos]);
        contador_alunos++;
    }

    for (int i = 0; i < contador_alunos; i++) {
        fprintf(arquivo_saida, "%s\t%.2f\t%s\n", alunos[i].nome, alunos[i].media, alunos[i].situacao);
    }

    fclose(arquivo_entrada);
    fclose(arquivo_saida);
}

int main() {
    const char *arquivo_entrada = "entrada_q3.txt";
    const char *arquivo_saida = "saida_q3.txt";

    processar_arquivo(arquivo_entrada, arquivo_saida);

    printf("Processamento concluído. Verifique o arquivo %s.\n", arquivo_saida);

    return 0;
}
