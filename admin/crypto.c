#include <stdio.h>
#include <string.h>
#include "admin.h"

void cadastrarCriptomoeda() {
    char nome[50];
    float cotacao_inicial, taxa_compra, taxa_venda;

    printf("Digite o nome da criptomoeda: ");
    scanf("%s", nome);
    printf("Digite a cotação inicial: ");
    scanf("%f", &cotacao_inicial);
    printf("Digite a taxa de compra: ");
    scanf("%f", &taxa_compra);
    printf("Digite a taxa de venda: ");
    scanf("%f", &taxa_venda);

    FILE *file = fopen("criptomoedas.dat", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de criptomoedas.\n");
        return;
    }

    fprintf(file, "%s %.2f %.2f %.2f\n", nome, cotacao_inicial, taxa_compra, taxa_venda);
    fclose(file);

    printf("Criptomoeda cadastrada com sucesso!\n");
}

