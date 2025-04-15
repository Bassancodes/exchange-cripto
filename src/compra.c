#include <stdio.h>
#include <stdlib.h>
#include "../include/compra.h"

#define COTACAO_BTC 300000.00
#define COTACAO_ETH 15000.00
#define COTACAO_XRP 2.00

void realizarCompra(Usuario *usuario) {
    int opcao;
    double valorReais, valorLiquido, taxa;

    printf("\n--- COMPRA DE CRIPTOMOEDAS ---\n");
    printf("1. Bitcoin (BTC)\n");
    printf("2. Ethereum (ETH)\n");
    printf("3. Ripple (XRP)\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    printf("Digite o valor em reais (R$) para usar na compra: ");
    scanf("%lf", &valorReais);

    if (valorReais > usuario->saldoReais) {
        printf("Saldo insuficiente.\n");
        return;
    }

    taxa = valorReais * 0.02;
    valorLiquido = valorReais - taxa;

    switch (opcao) {
        case 1:
            usuario->saldoBTC += valorLiquido / COTACAO_BTC;
            break;
        case 2:
            usuario->saldoETH += valorLiquido / COTACAO_ETH;
            break;
        case 3:
            usuario->saldoXRP += valorLiquido / COTACAO_XRP;
            break;
        default:
            printf("Opção inválida.\n");
            return;
    }

    usuario->saldoReais -= valorReais;

    printf("Compra realizada com sucesso!\n");
    printf("Taxa aplicada: R$ %.2f\n", taxa);
}
