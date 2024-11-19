#ifndef ADMIN_H
#define ADMIN_H

int efetuarLogin(char *cpf, char *senha);
void cadastrarInvestidor();
void excluirInvestidor();
void consultarSaldoInvestidor();
void consultarExtratoInvestidor();

void cadastrarCriptomoeda();
void excluirCriptomoeda();
void atualizarCotacao();
void atualizarSaldo(char *cpf, float valor);
void registrarExtrato(char *cpf, char *descricao, float valor);

#endif

