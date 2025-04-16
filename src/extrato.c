#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/extrato.h"

void gerarExtrato(Usuario *usuario) {
    char nomeArquivo[50];
    sprintf(nomeArquivo, "data/extrato_%s.txt", usuario->cpf);

    FILE *f = fopen(nomeArquivo, "a");
    if (!f) {
        printf("Erro ao criar o arquivo de extrato.\n");
        return;
    }

    time_t agora = time(NULL);
    struct tm *tm_info = localtime(&agora);

    fprintf(f, "\n========== Extrato ==========\n");
    fprintf(f, "Data e hora: %s", asctime(tm_info));
    fprintf(f, "Extrato de operacoes - %s\n", usuario->cpf);
    fprintf(f, "Saldo em Reais: R$ %.2f\n", usuario->saldoReais);
    fprintf(f, "Saldo em BTC: %.6f\n", usuario->saldoBTC);
    fprintf(f, "Saldo em ETH: %.6f\n", usuario->saldoETH);
    fprintf(f, "Saldo em XRP: %.6f\n", usuario->saldoXRP);
    fprintf(f, "=============================\n");

    fclose(f);
    printf("Extrato gerado com sucesso!\n");
}

