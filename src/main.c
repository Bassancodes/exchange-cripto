
#include <stdio.h>
#include "../include/login.h"    
#include "../include/carteira.h"
#include "../include/extrato.h"
#include "../include/compra.h"
#include "../include/deposito.h"


int main() {
    Usuario usuarioLogado;
    criarUsuarioTeste(); // Apenas para testes

    if (autenticarUsuario(&usuarioLogado)) {
        int opcao;

        do {
            printf("\n====== MENU PRINCIPAL ======\n");
            printf("1. Ver saldos da carteira\n");
            printf("2. Depositar reais\n");
            printf("3. Comprar criptomoedas\n");
            printf("4. Gerar extrato\n");
            printf("5. Sair\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    exibirSaldos(usuarioLogado);
                    break;
                case 2:
                    realizarDeposito(&usuarioLogado);
                    break;
                case 3:
                    realizarCompra(&usuarioLogado);
                    break;
                case 4:
                    gerarExtrato(usuarioLogado);
                    break;
                case 5:
                    printf("Saindo\n");
                    break;
                default:
                    printf("Opcao invalida.\n");
            }

        } while (opcao != 5);

    } else {
        printf("CPF ou senha invalidos.\n");
    }

    return 0;
}

