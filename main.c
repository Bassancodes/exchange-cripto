#include <stdio.h>
#include <string.h>
#include "funcoes.h"

int main() {
    Usuario usuarios[10];
    int totalUsuarios = 0;
    carregarUsuarios(usuarios, &totalUsuarios);

    int opcao, usuarioLogado = -1;
    char cpf[12], senha[20];

 while (1) {
        printf("\nCriptomoedas do Bassan\n");

        if (usuarioLogado == -1) {
            printf("1. Login\n");
            printf("2. Criar novo usuario\n");
            printf("0. Sair\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);

if (opcao == 1) {
                printf("CPF: ");
                scanf("%s", cpf);
                printf("Senha: ");
                scanf("%s", senha);
                usuarioLogado = login(usuarios, totalUsuarios, cpf, senha);

                if (usuarioLogado == -1) {
                    printf("Login invalido.\n");
                }
            } else if (opcao == 2) {
                if (totalUsuarios < 10) {
                    criarUsuario(usuarios, &totalUsuarios);
                    salvarUsuarios(usuarios, totalUsuarios);
                } else {
                    printf("Limite de usuarios atingido.\n");
                }
            } else if (opcao == 0) {
                break;
            }
        }
