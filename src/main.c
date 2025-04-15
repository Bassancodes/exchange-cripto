
#include <stdio.h>
#include "../include/login.h"
#include "../include/carteira.h"
#include "../include/extrato.h"
#include "../include/compra.h" 



int main() {
    Usuario usuarioLogado;
    criarUsuarioTeste(); // só para testes

    if (autenticarUsuario(&usuarioLogado)) {
        printf("Login bem-sucedido!\n");
        exibirSaldos(usuarioLogado);

	realizarCompra(&usuarioLogado);
	exibirSaldos(usuarioLogado); 

        gerarExtrato(usuarioLogado);  // Chamada do extrato
    } else {
        printf("CPF ou senha inválidos.\n");
    }

    return 0;
}


