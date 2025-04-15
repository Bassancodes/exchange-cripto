
#include <stdio.h>
#include "../include/login.h"
#include "../include/carteira.h"

int main() {
    Usuario usuarioLogado;
    criarUsuarioTeste(); // Só para testes

    if (autenticarUsuario(&usuarioLogado)) {
        printf("Login bem-sucedido!\n");
        exibirSaldos(usuarioLogado);
    } else {
        printf("CPF ou senha inválidos.\n");
    }

    return 0;
}

