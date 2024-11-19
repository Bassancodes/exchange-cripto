#include <stdio.h>
#include "admin.h"

int main() {
    int opcao;
    char cpf[12], senha[20];
    int login_sucesso = 0;

    printf("Bem-vindo ao Sistema de Administração da Exchange\n");

    // Tela inicial para login ou registro
    while (!login_sucesso) {
        printf("\nEscolha uma opção:\n");
        printf("1. Registrar Novo Investidor\n");
        printf("2. Efetuar Login\n");
        printf("3. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarInvestidor(); // Chama a função de cadastro
                break;
            case 2:
                printf("Digite o CPF: ");
                scanf("%s", cpf);
                printf("Digite a senha: ");
                scanf("%s", senha);
                login_sucesso = efetuarLogin(cpf, senha); // Tenta efetuar o login
                break;
            case 3:
                printf("Saindo do sistema.\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }

    // Menu principal aparece apenas após o login bem-sucedido
    printf("Login bem-sucedido! Acessando o menu principal...\n");

    // Menu principal do administrador
    do {
        printf("\nMenu Administrador\n");
        printf("1. Cadastrar Novo Investidor\n");
        printf("2. Excluir Investidor\n");
        printf("3. Cadastrar Criptomoeda\n");
        printf("4. Excluir Criptomoeda\n");
        printf("5. Consultar Saldo do Investidor\n");
        printf("6. Consultar Extrato do Investidor\n");
        printf("7. Atualizar Cotação de Criptomoedas\n");
        printf("8. Registrar Transação (Ajusta Saldo e Registra no Extrato)\n");
        printf("9. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarInvestidor();
                break;
            case 2:
                excluirInvestidor();
                break;
            case 3:
                cadastrarCriptomoeda();
                break;
            case 4:
                excluirCriptomoeda();
                break;
            case 5:
                consultarSaldoInvestidor();
                break;
            case 6:
                consultarExtratoInvestidor();
                break;
            case 7:
                atualizarCotacao();
                break;
            case 8: {
                // Registrar uma nova transação
                char cpf_transacao[12];
                char descricao[100];
                float valor;

                printf("Digite o CPF do investidor para registrar a transação: ");
                scanf("%s", cpf_transacao);
                printf("Descrição da transação: ");
                scanf("%s", descricao);
                printf("Valor da transação (use negativo para débitos): ");
                scanf("%f", &valor);

                // Atualiza o saldo e registra no extrato
                atualizarSaldo(cpf_transacao, valor);
                registrarExtrato(cpf_transacao, descricao, valor);
                break;
            }
            case 9:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 9);

    return 0;
}
