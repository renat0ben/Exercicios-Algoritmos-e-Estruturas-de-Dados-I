#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contabancaria.h"

struct ContaBancaria {
    char titular[100];
    int numero;
    double saldo;
};

ContaBancaria* cria_conta(char* titular, int numero, double saldo_inicial) {
    ContaBancaria* conta = (ContaBancaria*)malloc(sizeof(ContaBancaria));
    if (conta != NULL) {
        strncpy(conta->titular, titular, sizeof(conta->titular) - 1);
        conta->titular[sizeof(conta->titular) - 1] = '\0';
        conta->numero = numero;
        conta->saldo = saldo_inicial;
    }
    return conta;
}

void deposita(ContaBancaria* conta, double valor) {
    if (conta != NULL) {
        conta->saldo += valor;
    }
}

int saca(ContaBancaria* conta, double valor) {
    if (conta != NULL && conta->saldo >= valor) {
        conta->saldo -= valor;
        return 1;  // Sucesso
    }
    return 0;  // Falha
}

int transfere(ContaBancaria* origem, ContaBancaria* destino, double valor) {
    if (origem != NULL && destino != NULL && saca(origem, valor)) {
        deposita(destino, valor);
        return 1;  // Sucesso
    }
    return 0;  // Falha
}

double saldo(const ContaBancaria* conta) {
    if (conta != NULL) {
        return conta->saldo;
    }
    return 0.0;
}

void exclui_conta(ContaBancaria* conta) {
    if (conta != NULL) {
        free(conta);
    }
}
