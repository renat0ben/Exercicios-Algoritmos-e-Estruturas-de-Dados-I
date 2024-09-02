#include <stdio.h>
#include <locale.h>
#include "contabancaria.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    // Criando contas
    ContaBancaria* conta1 = cria_conta("Mario Silva", 1234, 1000.0);
    ContaBancaria* conta2 = cria_conta("Maria Oliveira", 5678, 500.0);

    // Exibindo saldo inicial
    printf("Saldo de Mario: %.2f\n", saldo(conta1));
    printf("Saldo de Maria: %.2f\n", saldo(conta2));

    // Depósito
    deposita(conta1, 200.0);
    printf("Saldo de Mario apos deposito: %.2f\n", saldo(conta1));

    // Saque
    if (saca(conta2, 100.0)) {
        printf("Saque realizado com sucesso. Saldo de Maria: %.2f\n", saldo(conta2));
    } else {
        printf("Saldo insuficiente para saque.\n");
    }

    // Transferência
    if (transfere(conta1, conta2, 300.0)) {
        printf("Transferencia realizada com sucesso.\n");
        printf("Mario -> Maria\n");
        printf("Saldo de Mario: %.2f\n", saldo(conta1));
        printf("Saldo de Maria: %.2f\n", saldo(conta2));
    } else {
        printf("Saldo insuficiente para transferencia.\n");
    }

    // Excluindo contas
    exclui_conta(conta1);
    exclui_conta(conta2);

    return 0;
}
