//funcoes.h 
#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct {
    char cpf[12];
    char senha[20];
    float saldoReais;
    float saldoBitcoin;
    float saldoEthereum;
    float saldoRipple;
    int totalTransacoes;
    char historicoTransacoes[100][100];
} Usuario;

int login(Usuario usuarios[], int totalUsuarios, char cpf[], char senha[]);
void criarUsuario(Usuario usuarios[], int *totalUsuarios);
void consultarSaldo(Usuario *usuario);
void consultarExtrato(Usuario *usuario);
void depositarReais(Usuario *usuario, float valor);
int sacarReais(Usuario *usuario, float valor, char senha[]);

