#include <stdio.h>
#include "admin.h"

int main() {
    int opcao;
    char cpf[12], senha[20];
    int login_sucesso = 0;

    printf("Bem-vindo ao Sistema de Administração da Exchange\n");

    // Laço para exibir a tela inicial até o login ser bem-sucedido
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

    // Menu principal aparece apenas após o login ser bem-sucedido
    printf("Login bem-sucedido! Acessando o menu principal...\n");

    // Menu principal do administrador
    do {
        printf("\nMenu Administrador\n");
        printf("1. Cadastrar Novo Investidor\n");
        printf("2. Excluir Investidor\n");
        printf("3. Cadastrar Criptomoeda\n");
        printf("4. Excluir Criptomoeda\n");
        printf("5. Consultar Saldo Investidor\n");
        printf("6. Consultar Extrato Investidor\n");
        printf("7. Atualizar Cotacao Criptomoedas\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: cadastrarInvestidor(); break;
            case 2: excluirInvestidor(); break;
            case 3: cadastrarCriptomoeda(); break;
            case 4: excluirCriptomoeda(); break;
            case 5: consultarSaldoInvestidor(); break;
            case 6: consultarExtratoInvestidor(); break;
            case 7: atualizarCotacao(); break;
            case 8: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while(opcao != 8);

    return 0;
}