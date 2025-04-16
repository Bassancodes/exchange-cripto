#include <stdio.h>
#include <string.h>
#include "../include/saque.h"

void realizarSaque(Usuario *usuario) {
    char senha[20];
    double valor;

    printf("\n=== SAQUE DE REAIS ===\n");
    printf("Digite sua senha: ");
    scanf("%s", senha);

    if (strcmp(senha, usuario->senha) != 0) {
        printf("Senha incorreta. Saque cancelado.\n");
        return;
    }

    printf("Digite o valor a ser sacado (R$): ");
    scanf("%lf", &valor);

    if (valor <= 0 || valor > usuario->saldoReais) {
        printf("Valor inválido ou saldo insuficiente.\n");
        return;
    }

    usuario->saldoReais -= valor;
    printf("Saque realizado com sucesso! Novo saldo: R$ %.2f\n", usuario->saldoReais);
}
