#include <stdio.h>
#include "../include/carteira.h"

void exibirSaldos(Usuario usuario) {
    printf("\n--- SALDOS DA CARTEIRA ---\n");
    printf("Reais (R$): %.2f\n", usuario.saldoReais);
    printf("Bitcoin (BTC): %.6f\n", usuario.saldoBTC);
    printf("Ethereum (ETH): %.6f\n", usuario.saldoETH);
    printf("Ripple (XRP): %.6f\n", usuario.saldoXRP);
}
