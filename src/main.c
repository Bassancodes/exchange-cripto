#include <stdio.h>
#include "../include/login.h"
#include "../include/carteira.h"
#include "../include/extrato.h"
#include "../include/compra.h"
#include "../include/deposito.h"
#include "../include/venda.h"
#include "../include/saque.h"
#include "../include/cotacao.h"

int main() {
    Usuario usuarioLogado;
    int opcaoInicial;

    printf("====== EXCHANGE DE CRIPTOMOEDAS ======\n");
    printf("1. Login\n");
    printf("2. Cadastrar novo usuario\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcaoInicial);

    if (opcaoInicial == 2) {
        cadastrarUsuario();
        return 0;
    }

    if (autenticarUsuario(&usuarioLogado)) {
        int opcao;
        do {
            printf("\n====== MENU PRINCIPAL ======\n");
            printf("1. Ver saldos da carteira\n");
            printf("2. Depositar reais\n");
            printf("3. Comprar criptomoedas\n");
            printf("4. Vender criptomoedas\n");
            printf("5. Sacar reais\n");
            printf("6. Gerar extrato\n");
            printf("7. Atualizar cotacoes\n");
            printf("8. Sair\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    exibirSaldos(&usuarioLogado);
                    break;
                case 2:
                    realizarDeposito(&usuarioLogado);
                    break;
                case 3:
                    realizarCompra(&usuarioLogado);
                    break;
                case 4:
                    realizarVenda(&usuarioLogado);
                    break;
                case 5:
                    realizarSaque(&usuarioLogado);
                    break;
                case 6:
                    gerarExtrato(&usuarioLogado);
                    break;
                case 7:
                    atualizarCotacoes();
                    break;
                case 8:
                    printf("Saindo...\n");
                    break;
                default:
                    printf("Opcao invalida.\n");
            }

            salvarDadosCompra(&usuarioLogado); 

        } while (opcao != 8);
    } else {
        printf("CPF ou senha invalidos.\n");
    }

    return 0;
}

