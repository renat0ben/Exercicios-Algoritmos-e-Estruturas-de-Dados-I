#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TAMANHO_VETOR 10

void processar_vetor(const int vetor[], int tamanho, int *menor, int *maior, float *media) {
    *menor = INT_MAX;
    *maior = INT_MIN;
    int soma = 0;

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] < *menor) {
            *menor = vetor[i];
        }
        if (vetor[i] > *maior) {
            *maior = vetor[i];
        }
        soma += vetor[i];
    }

    *media = soma / (float)tamanho;
}

void ler_vetor_do_arquivo(const char *nome_arquivo, int vetor[], int tamanho) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        exit(1);
    }

    for (int i = 0; i < tamanho; i++) {
        fscanf(arquivo, "%d", &vetor[i]);
    }

    fclose(arquivo);
}

void escrever_resultado_no_arquivo(const char *nome_arquivo, int menor, int maior, float media) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        exit(1);
    }

    fprintf(arquivo, "Menor elemento: %d\n", menor);
    fprintf(arquivo, "Maior elemento: %d\n", maior);
    fprintf(arquivo, "Média dos elementos: %.2f\n", media);

    fclose(arquivo);
}

int main() {
    int vetor[TAMANHO_VETOR];
    int menor, maior;
    float media;

    const char *arquivo_entrada = "entrada_q4.txt";
    const char *arquivo_saida = "saida_q4.txt";

    // Ler os valores do vetor a partir do arquivo de entrada
    ler_vetor_do_arquivo(arquivo_entrada, vetor, TAMANHO_VETOR);

    // Processar os valores do vetor para encontrar menor, maior e média
    processar_vetor(vetor, TAMANHO_VETOR, &menor, &maior, &media);

    // Escrever os resultados no arquivo de saída
    escrever_resultado_no_arquivo(arquivo_saida, menor, maior, media);

    printf("Processamento concluído. Verifique o arquivo %s.\n", arquivo_saida);

    return 0;
}
