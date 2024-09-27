#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

float cotacaoBitcoin = 100000.0;
float cotacaoEthereum = 5000.0;
float cotacaoRipple = 1.0;

int login(Usuario usuarios[], int totalUsuarios, char cpf[], char senha[]) {
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].cpf, cpf) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            return i;
        }
    }
    return -1;
}


void criarUsuario(Usuario usuarios[], int *totalUsuarios) {
    Usuario novoUsuario;

    printf("Digite o CPF (11 digitos): ");
    scanf("%s", novoUsuario.cpf);

    for (int i = 0; i < *totalUsuarios; i++) {
        if (strcmp(usuarios[i].cpf, novoUsuario.cpf) == 0) {
            printf("Erro: Usuario com este CPF ja existe.\n");
            return;
        }
    }

    printf("Digite a senha: ");
    scanf("%s", novoUsuario.senha);

    novoUsuario.saldoReais = 0.0;
    novoUsuario.saldoBitcoin = 0.0;
    novoUsuario.saldoEthereum = 0.0;
    novoUsuario.saldoRipple = 0.0;
    novoUsuario.totalTransacoes = 0;

    usuarios[*totalUsuarios] = novoUsuario;
    (*totalUsuarios)++;

    printf("Usuario criado com sucesso!\n");
}
void consultarSaldo(Usuario *usuario) {
    printf("Saldo em Reais: %.2f\n", usuario->saldoReais);
    printf("Saldo em Bitcoin: %.6f\n", usuario->saldoBitcoin);
    printf("Saldo em Ethereum: %.6f\n", usuario->saldoEthereum);
    printf("Saldo em Ripple: %.6f\n", usuario->saldoRipple);
}

void consultarExtrato(Usuario *usuario) {
    printf("Historico de transacoes:\n");
    for (int i = 0; i < usuario->totalTransacoes; i++) {
        printf("%s\n", usuario->historicoTransacoes[i]);
    }
}
void depositarReais(Usuario *usuario, float valor) {
    usuario->saldoReais += valor;
    printf("Deposito realizado com sucesso!\n");
}

int sacarReais(Usuario *usuario, float valor, char senha[]) {
    if (strcmp(usuario->senha, senha) == 0 && usuario->saldoReais >= valor) {
        usuario->saldoReais -= valor;
        printf("Saque realizado com sucesso!\n");
        return 1;
    }
    printf("Erro no saque: senha incorreta ou saldo insuficiente.\n");
    return 0;
}
