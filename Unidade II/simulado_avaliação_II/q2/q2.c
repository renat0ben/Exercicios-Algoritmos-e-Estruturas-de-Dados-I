#include "q2.h"

Funcionario **alocaFuncionario()
{
    Funcionario **novo = (Funcionario **)malloc(sizeof(Funcionario *) * MAX);
    if (novo == NULL)
    {
        printf("erro");
        exit(1);
    }

    return novo;
}

Funcionario **adicionaFuncionario(Funcionario **funcionario, char *nome, int id, float salario, int *qnt)
{
    funcionario[(*qnt)] = (Funcionario *)malloc(sizeof(Funcionario));
    if (funcionario[(*qnt)] == NULL)
    {
        printf("Erro ao alocar memoria!");
        exit(1);
    }

    strcpy(funcionario[(*qnt)]->nome, nome);
    funcionario[(*qnt)]->id = id;
    funcionario[(*qnt)]->salario = salario;
    (*qnt)++;

    return funcionario;
}

Funcionario **removeFuncionario(Funcionario **funcionario, int id, int *qnt)
{
    int i;
    for (i = 0; i < (*qnt); i++)
    {
        if (funcionario[i]->id == id)
        {
            break;
        }
    }
    free(funcionario);
    for (int j = i; j < (*qnt); j++)
    {
        funcionario[j] = funcionario[j + 1];
    }
    funcionario[(*qnt)] == NULL;
    (*qnt)--;

    return funcionario;
}

Funcionario *buscaFuncionario(Funcionario **funcionario, int id, int qnt)
{
    for (int i = 0; i < qnt; i++)
    {
        if (funcionario[i]->id == id)
        {
            return funcionario[i];
        }
    }
    return NULL;
}

void listarFuncionarios(Funcionario **funcionario, int qnt)
{
    for (int i = 0; i < qnt; i++)
    {
        printf("Nome: %s\nId: %i\nsalario: %f", funcionario[i]->nome, funcionario[i]->id, funcionario[i]->salario);
    }
}

void libera_funcionario(Funcionario **funcionario, int qnt)
{
    for (int i = 0; i < qnt; i++)
    {
        free(funcionario[i]);
    }
    free(funcionario);
}
