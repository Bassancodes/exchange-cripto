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

