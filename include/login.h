#ifndef LOGIN_H
#define LOGIN_H

#include <stdbool.h>

typedef struct {
    char cpf[12];
    char senha[20];
    double saldoReais;
    double saldoBTC;
    double saldoETH;
    double saldoXRP;
} Usuario;


void atualizarUsuario(Usuario usuarioAtualizado);

bool cadastrarUsuario();
bool autenticarUsuario(Usuario* usuarioLogado);
void criarUsuarioTeste();

#endif
