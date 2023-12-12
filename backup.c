#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função que cria arquivo binario do arquivo veiculos_estoque
void criaArquivoBinarioEstoque(char *veiculos_estoque, char *veiculos_binario)
{
    FILE *arquivoEstoque, *arquivoBinario;
    char caractere;

    // Abre o arquivo de texto para leitura
    arquivoEstoque = fopen("veiculos_estoque.csv", "r+");

    if (arquivoEstoque == NULL)
    {
        perror("Erro ao abrir o arquivo de texto");
        exit(EXIT_FAILURE);
    }

    arquivoBinario = fopen("veiculos_binario.csv", "wb");

    if (arquivoEstoque == NULL)
    {
        perror("Erro ao abrir o arquivo de texto");
        exit(EXIT_FAILURE);
    }

    // Copia letra por letra para o arquivo binário
    while ((caractere = fgetc(arquivoEstoque)) != EOF)
    {
        fwrite(&caractere, sizeof(char), 1, arquivoBinario);
    }

    // Fecha o arquivo
    fclose(arquivoEstoque);
    fclose(arquivoBinario);

    printf("Arquivo binario de estoque criado com sucesso\n");
}

// -------------------------------------------------------------------------------------

// Função que cria arquivo binario do arquivo historico_compras
void criaArquivoBinarioCompras(char *historico_compras, char *historico_compras_binario)
{
    FILE *arqHistoricoCompras, *arqHistoricoComprasBinario;
    char caractere;

    // Abre o arquivo de texto para leitura
    arqHistoricoCompras = fopen("historico_compras.csv", "r+");

    if (arqHistoricoCompras == NULL)
    {
        perror("Erro ao abrir o arquivo de texto");
        exit(EXIT_FAILURE);
    }

    arqHistoricoComprasBinario = fopen("historico_compras_binario.csv", "wb");

    if (arqHistoricoComprasBinario == NULL)
    {
        perror("Erro ao abrir o arquivo de texto");
        exit(EXIT_FAILURE);
    }

    // Copia letra por letra para o arquivo binário
    while ((caractere = fgetc(arqHistoricoCompras)) != EOF)
    {
        fwrite(&caractere, sizeof(char), 1, arqHistoricoComprasBinario);
    }

    // Fecha o arquivo
    fclose(arqHistoricoCompras);
    fclose(arqHistoricoComprasBinario);

    printf("Arquivo binario de historico de compras criado com sucesso\n");
}

// -------------------------------------------------------------------------------------

// Função que cria arquivo binario do arquivo historico_compras
void criaArquivoBinarioVendas(char *historico_vendas, char *historico_vendas_binario)
{
    FILE *arqHistoricoVendas, *arqHistoricoVendasBinario;
    char caractere;

    // Abre o arquivo de texto para leitura
    arqHistoricoVendas = fopen("historico_vendas.csv", "r+");

    if (arqHistoricoVendas == NULL)
    {
        perror("Erro ao abrir o arquivo de texto");
        exit(EXIT_FAILURE);
    }

    arqHistoricoVendasBinario = fopen("historico_vendas_binario.csv", "wb");

    if (arqHistoricoVendasBinario == NULL)
    {
        perror("Erro ao abrir o arquivo de texto");
        exit(EXIT_FAILURE);
    }

    // Copia letra por letra para o arquivo binário
    while ((caractere = fgetc(arqHistoricoVendas)) != EOF)
    {
        fwrite(&caractere, sizeof(char), 1, arqHistoricoVendasBinario);
    }

    // Fecha o arquivo
    fclose(arqHistoricoVendas);
    fclose(arqHistoricoVendasBinario);

    printf("Arquivo binario de historico de vendas criado com sucesso\n");
}


int main()
{
    // variaveis de veiculo estoque
    char *veiculosEstoque = "veiculos_estoque.csv";
    char *veiculosBinario = "veiculos_binario.csv";
    // variaveis de historico de compras
    char *historicoCompras = "historico_compras.csv";
    char *historicoComprasBinario = "historico_compras_binario.csv";
    // variaveis de historico de vendas
    char *historicoVendas = "historico_vendas.csv";
    char *historicoVendasBinario = "historico_vendas_binario.csv";

    criaArquivoBinarioEstoque(veiculosEstoque, veiculosBinario);

    criaArquivoBinarioCompras(historicoCompras, historicoComprasBinario);

    criaArquivoBinarioVendas(historicoVendas, historicoVendasBinario);

    return 0;
}