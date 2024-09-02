#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 1000000

int busca_sequencial(int *entrada, int tamanho);
int busca_binaria(int *entrada, int item, int tamanho);
int compare(const void *a, const void *b);

int main(void)
{
    int entrada[TAMANHO];
    for (int i = 0; i < TAMANHO; i++)
    {
        entrada[i] = rand(); // gera números aleatórios
    }

    clock_t t1;
    t1 = clock(); // armazena o tempo
    int maior1 = busca_sequencial(entrada, TAMANHO);
    t1 = clock() - t1;
    printf("Tempo da busca sequencial: %lf\n", ((double)t1) / ((CLOCKS_PER_SEC / 1000)));

    qsort(entrada, TAMANHO, sizeof(int), compare);

    clock_t t2;
    t2 = clock();
    int maior2 = busca_binaria(entrada, maior1, TAMANHO);
    t2 = clock() - t2;
    printf("Tempo da busca binária: %lf", ((double)t2) / ((CLOCKS_PER_SEC / 1000)));
}

int busca_sequencial(int *entrada, int tamanho)
{
    int maior = entrada[0];
    int index;
    for (index = 0; index < tamanho; index++)
    {
        if (maior < entrada[index])
        {
            maior = entrada[index];
        }
    }

    return maior;
}

int busca_binaria(int *entrada, int item, int tamanho)
{
    int baixo = 0;
    int alto = tamanho - 1;

    while (baixo <= alto)
    {
        int meio = (baixo + alto) / 2;
        int chute = entrada[meio];
        if (chute == item)
        {
            return meio;
        }
        else if (chute > item)
        {
            alto = meio - 1;
        }
        else
        {
            baixo = meio + 1;
        }
    }
    return -1;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a) - (*(int *)b);
}