#include <stdio.h>
#include "../include/login.h"

int main() {
    Usuario usuarioLogado;
    criarUsuarioTeste(); // Apenas para teste inicial

    if (autenticarUsuario(&usuarioLogado)) {
        printf("Login bem-sucedido! Saldo em reais: R$ %.2f\n", usuarioLogado.saldoReais);
    } else {
        printf("CPF ou senha inválidos.\n");
    }

    return 0;
}
