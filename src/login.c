#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/login.h"

bool autenticarUsuario(Usuario* usuarioLogado) {
    FILE *arquivo = fopen("data/users.dat", "rb");
    if (!arquivo) {
        printf("Arquivo de usuarios nao encontrado.\n");
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

bool cadastrarUsuario() {
    FILE *arquivo = fopen("data/users.dat", "ab+");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo de usuarios.\n");
        return false;
    }

    Usuario novo;
    printf("Digite o CPF: ");
    scanf("%s", novo.cpf);

    
    Usuario temp;
    while (fread(&temp, sizeof(Usuario), 1, arquivo)) {
        if (strcmp(temp.cpf, novo.cpf) == 0) {
            printf("Usuario com esse CPF ja existe.\n");
            fclose(arquivo);
            return false;
        }
    }

    printf("Digite a senha: ");
    scanf("%s", novo.senha);

    // Saldos iniciais
    novo.saldoReais = 0.0;
    novo.saldoBTC = 0.0;
    novo.saldoETH = 0.0;
    novo.saldoXRP = 0.0;

    fseek(arquivo, 0, SEEK_END);
    fwrite(&novo, sizeof(Usuario), 1, arquivo);
    fclose(arquivo);

    printf("Usuario cadastrado com sucesso!\n");
    return true;
}


void atualizarUsuario(Usuario usuarioAtualizado) {
    FILE *arquivo = fopen("data/users.dat", "rb+");
    if (!arquivo) {
        printf("Erro ao abrir arquivo para atualização.\n");
        return;
    }

    Usuario temp;
    while (fread(&temp, sizeof(Usuario), 1, arquivo)) {
        if (strcmp(temp.cpf, usuarioAtualizado.cpf) == 0) {
            fseek(arquivo, -sizeof(Usuario), SEEK_CUR);
            fwrite(&usuarioAtualizado, sizeof(Usuario), 1, arquivo);
            fclose(arquivo);
            return;
        }
    }

    fclose(arquivo);
    printf("Usuário não encontrado para atualização.\n");
}

