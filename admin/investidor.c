#include <stdio.h>
#include <string.h>
#include "admin.h"

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
