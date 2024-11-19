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
