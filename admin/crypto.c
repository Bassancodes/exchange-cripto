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

void excluirCriptomoeda() {
    char nome[50];
    printf("Digite o nome da criptomoeda a ser excluída: ");
    scanf("%s", nome);

    FILE *file = fopen("criptomoedas.dat", "r");
    FILE *temp = fopen("temp.dat", "w");
    if (file == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    char nome_lido[50];
    float cotacao, taxa_compra, taxa_venda;
    int encontrado = 0;

    while (fscanf(file, "%s %f %f %f\n", nome_lido, &cotacao, &taxa_compra, &taxa_venda) != EOF) {
        if (strcmp(nome, nome_lido) == 0) {
            encontrado = 1;
            printf("Criptomoeda %s excluída.\n", nome);
            continue;
        }
        fprintf(temp, "%s %.2f %.2f %.2f\n", nome_lido, cotacao, taxa_compra, taxa_venda);
    }

    fclose(file);
    fclose(temp);

    remove("criptomoedas.dat");
    rename("temp.dat", "criptomoedas.dat");

    if (!encontrado) {
        printf("Criptomoeda %s não encontrada.\n", nome);
    }
}

