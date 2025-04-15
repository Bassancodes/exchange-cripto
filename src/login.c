#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/login.h"

bool autenticarUsuario(Usuario* usuarioLogado) {
    FILE *arquivo = fopen("data/users.dat", "rb");
    if (!arquivo) {
        printf("Arquivo de usuários não encontrado.\n");
        return false;
    }

    char cpf[12], senha[20];
    printf("Digite o CPF: ");
    scanf("%s", cpf);
    printf("Digite a senha: ");
    scanf("%s", senha);

    Usuario temp;
    while (fread(&temp, sizeof(Usuario), 1, arquivo)) {
        if (strcmp(temp.cpf, cpf) == 0 && strcmp(temp.senha, senha) == 0) {
            *usuarioLogado = temp;
            fclose(arquivo);
            return true;
        }
    }

    fclose(arquivo);
    return false;
}

void criarUsuarioTeste() {
    FILE *arquivo = fopen("data/users.dat", "wb");
    Usuario u = {
        .cpf = "12345678901",
        .senha = "senha123",
        .saldoReais = 1000.0,
        .saldoBTC = 0.0,
        .saldoETH = 0.0,
        .saldoXRP = 0.0
    };
    fwrite(&u, sizeof(Usuario), 1, arquivo);
    fclose(arquivo);
}
