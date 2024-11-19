#include <stdio.h>
#include <string.h>
#include "admin.h"

#include <stdio.h>
#include <string.h>
#include "admin.h"

// Função para inicializar dados de exemplo nos arquivos .dat
void inicializarDados() {
    // Cria e inicializa o arquivo de saldos
    FILE *saldos_file = fopen("saldos.dat", "w");
    if (saldos_file == NULL) {
        printf("Erro ao criar o arquivo saldos.dat\n");
        return;
    }
    fprintf(saldos_file, "12345678901 1500.00\n");
    fprintf(saldos_file, "98765432100 2500.75\n");
    fprintf(saldos_file, "55555555555 750.25\n");
    fclose(saldos_file);

    // Cria e inicializa o arquivo de extratos
    FILE *extratos_file = fopen("extratos.dat", "w");
    if (extratos_file == NULL) {
        printf("Erro ao criar o arquivo extratos.dat\n");
        return;
    }
    fprintf(extratos_file, "12345678901 CompraBTC 500.00\n");
    fprintf(extratos_file, "12345678901 VendaETH 300.00\n");
    fprintf(extratos_file, "98765432100 CompraBTC 1200.50\n");
    fprintf(extratos_file, "55555555555 CompraETH 350.75\n");
    fclose(extratos_file);

    printf("Arquivos saldos.dat e extratos.dat foram inicializados com dados de exemplo.\n");
}


// Função para efetuar o login do administrador
int efetuarLogin(char *cpf, char *senha) {
    const char admin_cpf[] = "12345678901";
    const char admin_senha[] = "admin123";

    if (strcmp(cpf, admin_cpf) == 0 && strcmp(senha, admin_senha) == 0) {
        return 1; // Login bem-sucedido
    }
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

    FILE *file = fopen("investidores.dat", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de investidores.\n");
        return;
    }

    fprintf(file, "%s %s %s\n", nome, cpf, senha);
    fclose(file);

    printf("Investidor cadastrado com sucesso!\n");
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
