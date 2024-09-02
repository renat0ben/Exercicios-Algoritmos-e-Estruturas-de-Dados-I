#include <stdio.h>
#include <stdlib.h>

FILE *abreArquivo(char *nome, char *modo);
int comparaDecrescente(const void *a, const void *b);

typedef struct aluno
{
    int idade;
    char nome[20];
    double nota1, nota2, nota3, media;
} Aluno;

int main()
{
    Aluno vet[20];
    int i = 0;
    FILE *arquivoEntrada, *arquivoSaida;
    arquivoEntrada = abreArquivo("entrada.txt", "r");
    arquivoSaida = abreArquivo("resultados.txt","w");

    while (fscanf(arquivoEntrada, "%[^,],%d,%lf,%lf,%lf", vet[i].nome, &vet[i].idade, &vet[i].nota1, &vet[i].nota2, &vet[i].nota3) != EOF)
    {
        i++;
    }

    for (i = 0; i < 20; i++)
    {
        vet[i].media = (vet[i].nota1 + vet[i].nota2 + vet[i].nota3) / 3;
    }
    qsort(vet, 20, sizeof(Aluno), comparaDecrescente);
    for (i = 0; i < 20; i++)
    {
        printf("%s: %.1lf", vet[i].nome, vet[i].media);
        fprintf(arquivoSaida,"%s: %.1lf", vet[i].nome, vet[i].media);
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    return 0;
}

FILE *abreArquivo(char *nome, char *modo)
{
    FILE *arquivo = fopen(nome, modo);
    if (arquivo == NULL)
    {
        printf("Erro ao abrir");
        exit(1);
    }
    return arquivo;
}

int comparaDecrescente(const void *a, const void *b)
{
    if ((*(Aluno *)a).media == (*(Aluno *)b).media)
    {
        return 0; // são iguais
    }
    else if ((*(Aluno *)a).media < (*(Aluno *)b).media)
    {
        return 1; // vem depois
    }
    else
    {
        return -1; // vem antes
    }
}