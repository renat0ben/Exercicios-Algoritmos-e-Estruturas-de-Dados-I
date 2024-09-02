#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

typedef struct ContaBancaria ContaBancaria;

// Cria uma nova conta bancária
ContaBancaria* cria_conta(char* titular, int numero, double saldo_inicial);

// Deposita um valor na conta
void deposita(ContaBancaria* conta, double valor);

// Saca um valor da conta
int saca(ContaBancaria* conta, double valor);

// Transfere um valor de uma conta para outra
int transfere(ContaBancaria* origem, ContaBancaria* destino, double valor);

// Retorna o saldo da conta
double saldo(const ContaBancaria* conta);

// Exclui a conta, liberando a memória alocada
void exclui_conta(ContaBancaria* conta);

#endif
