#include <stdio.h>
#include <string.h>
#include "funcoes.h"

int main() {
    Usuario usuarios[10];
    int totalUsuarios = 0;
    carregarUsuarios(usuarios, &totalUsuarios);

    int opcao, usuarioLogado = -1;
    char cpf[12], senha[20];
