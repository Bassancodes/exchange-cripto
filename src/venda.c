#include <stdio.h>
#include "../include/venda.h"
#include <string.h>



#define TAXA_BTC 0.03
#define TAXA_ETH 0.02
#define TAXA_XRP 0.01

void realizarVenda(Usuario *usuario) {
    int opcao;
    double valorCripto = 0.0, valorRecebido = 0.0;

    printf("\n--- VENDA DE CRIPTOMOEDAS ---\n");
    printf("1. Bitcoin (BTC)\n");
    printf("2. Ethereum (ETH)\n");
    printf("3. Ripple (XRP)\n");
    printf("Escolha a criptomoeda para vender: ");
    scanf("%d", &opcao);

    printf("Digite a quantidade a ser vendida: ");
    scanf("%lf", &valorCripto);

    switch (opcao) {
        case 1:
            if (valorCripto <= usuario->saldoBTC) {
                valorRecebido = valorCripto * (1 - TAXA_BTC) * 300000.00;
                usuario->saldoBTC -= valorCripto;
                usuario->saldoReais += valorRecebido;
                printf("Venda de BTC realizada com sucesso! Reais recebidos: R$ %.2f\n", valorRecebido);
            } else {
                printf("Saldo de BTC insuficiente.\n");
            }
            break;
        case 2:
            if (valorCripto <= usuario->saldoETH) {
                valorRecebido = valorCripto * (1 - TAXA_ETH) * 10000.00;
                usuario->saldoETH -= valorCripto;
                usuario->saldoReais += valorRecebido;
                printf("Venda de ETH realizada com sucesso! Reais recebidos: R$ %.2f\n", valorRecebido);
            } else {
                printf("Saldo de ETH insuficiente.\n");
            }
            break;
        case 3:
            if (valorCripto <= usuario->saldoXRP) {
                valorRecebido = valorCripto * (1 - TAXA_XRP) * 2.00;
                usuario->saldoXRP -= valorCripto;
                usuario->saldoReais += valorRecebido;
                printf("Venda de XRP realizada com sucesso! Reais recebidos: R$ %.2f\n", valorRecebido);
            } else {
                printf("Saldo de XRP insuficiente.\n");
            }
            break;
        default:
            printf("Opcao invalida.\n");
    }
}
void salvarDadosCompra(Usuario *usuario) {
    FILE *arquivo = fopen("data/users.dat", "rb+");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo de usuários.\n");
        return;
    }

    Usuario temp;
    while (fread(&temp, sizeof(Usuario), 1, arquivo)) {
        if (strcmp(temp.cpf, usuario->cpf) == 0) {
            fseek(arquivo, -sizeof(Usuario), SEEK_CUR);
            fwrite(usuario, sizeof(Usuario), 1, arquivo);
            break;
        }
    }

    fclose(arquivo);
}
