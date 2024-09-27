//funcoes.h 
#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct {
    char cpf[12];
    char senha[20];
    float saldoReais;
    float saldoBitcoin;
    float saldoEthereum;
    float saldoRipple;
    int totalTransacoes;
    char historicoTransacoes[100][100];
}
