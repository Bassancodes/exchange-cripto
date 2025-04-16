#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/cotacao.h"

double COTACAO_BTC = 300000.00;
double COTACAO_ETH = 10000.00;
double COTACAO_XRP = 2.00;

void atualizarCotacoes() {
    srand(time(NULL));

    double variacaoBTC = ((rand() % 101) - 50) / 1000.0;
    double variacaoETH = ((rand() % 101) - 50) / 1000.0;
    double variacaoXRP = ((rand() % 101) - 50) / 1000.0;

    COTACAO_BTC += COTACAO_BTC * variacaoBTC;
    COTACAO_ETH += COTACAO_ETH * variacaoETH;
    COTACAO_XRP += COTACAO_XRP * variacaoXRP;

    printf("\n=== COTAÇÕES ATUALIZADAS ===\n");
    printf("Bitcoin (BTC): R$ %.2f\n", COTACAO_BTC);
    printf("Ethereum (ETH): R$ %.2f\n", COTACAO_ETH);
    printf("Ripple (XRP): R$ %.2f\n", COTACAO_XRP);
}
