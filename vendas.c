#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void vendeVeiculo(char *veiculos_estoque, char *historico_vendas, char veiculoComprado)
{

    // abre os arquivos
    FILE *arquivoEstoque = fopen("veiculos_estoque", "r+");
    FILE *arquivoVendas = fopen("historico_vendas.csv", "a");

    // verifica se os arquivos abriram corretamente
    if (arquivoEstoque == NULL || arquivoVendas == NULL)
    {
        printf("Erro ao abrir arquivos\n");
        return;
    }

    // cria um arquivo temporário em memória, para passaar as linhas que nao
    FILE *temporarioFile = tmpfile(); // tmpfile() cria um arquivo temporário na memória RAM

    char linha[TMP_MAX]; // para ler cada linha do documento de estoque
    int encontrado = 0;  // usar para controlar se o veículo foi encontrado

    // lê todas as linhas do arquivo estoque
    while (fgets(linha, sizeof(linha), arquivoEstoque) != NULL)
    {
        if (strcmp(linha, veiculoComprado) != 0) // compara o veículo desejado e a informação do arquivo oferta
        {
            fprintf(temporarioFile, "%s", linha); // Escreve no arquivo temporário
        }
        else
        {
            encontrado = 1;                    // veiculo encontrado
            fprintf(arquivoEstoque, "%s", ""); // apaga veiculo encontrado do estoque
            // também precisa adicionar ao historico de vendas
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            fprintf(arquivoVendas, "%s,%d-%02d-%02d %02d:%02d:%02d\n", linha, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        }
    }
}
int main()
{
    vendeVeiculo("veiculos_estoque.csv", "historico_vendas.csv", veiculoComprado);
}