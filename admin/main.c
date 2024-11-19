#include <stdio.h>
#include "admin.h"

int main() {
    char cpf[12], senha[20];

    printf("Login Administrador\n");
    printf("CPF: ");
    scanf("%s", cpf);
    printf("Senha: ");
    scanf("%s", senha);

    if (!efetuarLogin(cpf, senha)) {
        printf("Login falhou!\n");
        return 1;
    }

    int opcao;
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

