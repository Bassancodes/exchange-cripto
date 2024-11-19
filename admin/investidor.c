#include <stdio.h>
#include <string.h>
#include "admin.h"

#include <stdio.h>
#include <string.h>
#include "admin.h"


int efetuarLogin(char *cpf, char *senha) {
    FILE *file = fopen("investidores.dat", "r");
    if (file == NULL) {
        printf("Nenhum investidor cadastrado. Registre um investidor primeiro.\n");
        return 0;
    }

    char nome[100];
    char cpf_lido[12];
    char senha_lida[20];

    // Percorre cada linha do arquivo para verificar o CPF e a senha
    while (fscanf(file, "%s %s %s\n", nome, cpf_lido, senha_lida) != EOF) {
        if (strcmp(cpf, cpf_lido) == 0 && strcmp(senha, senha_lida) == 0) {
            fclose(file);
            printf("Login bem-sucedido! Bem-vindo, %s.\n", nome);
            return 1; // Login válido
        }
    }

    fclose(file);
    printf("CPF ou senha incorretos.\n");
    return 0; // Falha no login
}


void cadastrarInvestidor() {
    char nome[100];
    char cpf[12];
    char senha[20];

    printf("Digite o nome do investidor: ");
    scanf("%s", nome);
    printf("Digite o CPF do investidor: ");
    scanf("%s", cpf);
    printf("Digite a senha do investidor: ");
    scanf("%s", senha);

    // Grava o investidor no arquivo de investidores
    FILE *file = fopen("investidores.dat", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de investidores.\n");
        return;
    }
    fprintf(file, "%s %s %s\n", nome, cpf, senha);
    fclose(file);

    // Adiciona um saldo inicial de 0.00 no arquivo de saldos
    FILE *saldos_file = fopen("saldos.dat", "a");
    if (saldos_file == NULL) {
        printf("Erro ao abrir o arquivo de saldos.\n");
        return;
    }
    fprintf(saldos_file, "%s %.2f\n", cpf, 0.00);
    fclose(saldos_file);

    printf("Investidor cadastrado com sucesso! Saldo inicial: R$0.00\n");
}



void excluirInvestidor() {
    char cpf[12];
    printf("Digite o CPF do investidor a ser excluído: ");
    scanf("%s", cpf);

    FILE *file = fopen("investidores.dat", "r");
    FILE *temp = fopen("temp.dat", "w");
    if (file == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    char nome[100], cpf_lido[12], senha[20];
    int encontrado = 0;

    while (fscanf(file, "%s %s %s\n", nome, cpf_lido, senha) != EOF) {
        if (strcmp(cpf, cpf_lido) == 0) {
            encontrado = 1;
            printf("Investidor %s com CPF %s excluído.\n", nome, cpf);
            continue;
        }
        fprintf(temp, "%s %s %s\n", nome, cpf_lido, senha);
    }

    fclose(file);
    fclose(temp);

    remove("investidores.dat");
    rename("temp.dat", "investidores.dat");

    if (!encontrado) {
        printf("Investidor com CPF %s não encontrado.\n", cpf);
    }
}

#include <stdio.h>
#include <string.h>
#include "admin.h"

void consultarSaldoInvestidor() {
    char cpf[12];
    float saldo;
    int encontrado = 0;

    printf("Digite o CPF do investidor para consulta de saldo: ");
    scanf("%s", cpf);

    // Abre o arquivo de saldos em modo leitura
    FILE *file = fopen("saldos.dat", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de saldos.\n");
        return;
    }

    // Busca o saldo pelo CPF no arquivo
    char cpf_lido[12];
    while (fscanf(file, "%s %f\n", cpf_lido, &saldo) != EOF) {
        if (strcmp(cpf, cpf_lido) == 0) {
            printf("Saldo do investidor com CPF %s: R$%.2f\n", cpf, saldo);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Investidor com CPF %s não encontrado.\n", cpf);
    }

    fclose(file);
}

void consultarExtratoInvestidor() {
    char cpf[12];
    int encontrado = 0;

    printf("Digite o CPF do investidor para consulta de extrato: ");
    scanf("%s", cpf);

    // Abre o arquivo de extratos em modo leitura
    FILE *file = fopen("extratos.dat", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de extratos.\n");
        return;
    }

    // Busca as transações pelo CPF no arquivo
    char cpf_lido[12], descricao[100];
    float valor;
    printf("Extrato do investidor com CPF %s:\n", cpf);
    printf("----------------------------------------\n");

    while (fscanf(file, "%s %s %f\n", cpf_lido, descricao, &valor) != EOF) {
        if (strcmp(cpf, cpf_lido) == 0) {
            printf("Transação: %s | Valor: R$%.2f\n", descricao, valor);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum extrato encontrado para o CPF %s.\n", cpf);
    }

    printf("----------------------------------------\n");
    fclose(file);
}
