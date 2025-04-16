#include <stdio.h>
#include "../include/deposito.h"
#include "../include/login.h"

void realizarDeposito(Usuario *usuario) {
    double valor;


    printf("\n--- DEPOSITO ---\n");
    printf("Digite o valor a ser depositado (R$): ");
    scanf("%lf", &valor);

    if (valor <= 0) {
        printf("Valor invalido.\n");
        return;
    }

    usuario->saldoReais += valor;
    printf("Deposito realizado com sucesso! Novo saldo: R$ %.2f\n", usuario->saldoReais);

    atualizarUsuario(*usuario); 
}


