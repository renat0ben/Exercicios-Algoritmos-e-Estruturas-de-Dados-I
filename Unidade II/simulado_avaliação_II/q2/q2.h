#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct funcionario
{
    char nome[20];
    int id;
    float salario;
}Funcionario;

Funcionario **alocaFuncionario();
Funcionario **adicionaFuncionario(Funcionario **funcionario, char *nome, int id, float salario, int *qnt);
Funcionario **removeFuncionario(Funcionario **funcionario, int id, int *qnt);
Funcionario *buscaFuncionario(Funcionario **funcionario, int id, int qnt);
void listarFuncionarios(Funcionario **funcionario, int qnt);
void libera_funcionario(Funcionario **funcionario, int qnt);