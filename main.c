#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_LINHA 200 // Tamanho máximo da linha do arquivo

// Função para remover um veículo do arquivo de ofertas
void comprarVeiculo(const char *ofertasFilename, const char *estoqueFilename, const char *historicoFilename, const char *veiculoComprado)
{
    // abre os arquivos
    FILE *fileOfertas = fopen(ofertasFilename, "r");
    FILE *fileEstoque = fopen(estoqueFilename, "a");
    FILE *fileHistorico = fopen(historicoFilename, "a");

    // verifica se os arquivos abriram corretamente
    if (fileOfertas == NULL || fileEstoque == NULL || fileHistorico == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Cria um arquivo temporário em memória, para passar as linhas que não correspondem ao veículo comprado
    FILE *temporarioFile = tmpfile(); //tmpfile() cria um arquivo temporário na memória RAM

    char linha[TAM_LINHA]; // para ler cada linha do documento de ofertas
    int encontrado = 0;    // usar para controlar se o veículo foi encontrado

    // lê todas as linhas do arquivo ofertas
    while (fgets(linha, TAM_LINHA, fileOfertas) != NULL)
    { 
        if (strcmp(linha, veiculoComprado) != 0) // compara o veículo desejado e a informação do arquivo oferta
        {
            fprintf(temporarioFile, "%s", linha); // Escreve no arquivo temporário
        }
        else
        {
            encontrado = 1; // veiculo encontrado
            fprintf(fileEstoque, "%s", linha); // Adiciona ao estoque
            // também precisa adicionar ao historico de compras
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            fprintf(fileHistorico, "%s,%d-%02d-%02d %02d:%02d:%02d\n", linha, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        }
    }

    fclose(fileOfertas);
    fclose(fileEstoque);
    fclose(fileHistorico);

    // Reescreve o arquivo de ofertas com as informações atualizadas, excluindo o veículo comprado
    freopen(ofertasFilename, "w", fileOfertas);
    rewind(temporarioFile);  // move o indicador de posição no arquivo para o início

    while (fgets(linha, TAM_LINHA, temporarioFile) != NULL)
    {
        fprintf(fileOfertas, "%s", linha);
    }

    fclose(fileOfertas);
    fclose(temporarioFile);

    if (!encontrado)
    {
        printf("Veículo não encontrado na oferta.\n");
    }
    else
    {
        printf("Veículo removido da oferta e adicionado ao estoque. Registro de compra adicionado ao histórico.\n");
    }
}

int main()
{

    char veiculoComprado[TAM_LINHA]; // declarando vetor com as informações do carro desejado

    printf("Veículo que foi comprado: ");
    fgets(veiculoComprado, TAM_LINHA, stdin);

    veiculoComprado[strcspn(veiculoComprado, "\n")] = '\0'; // Remover a quebra de linha

    comprarVeiculo("veiculos_oferta.csv", "veiculos_estoque.csv", "historico_compras.csv", veiculoComprado);

    return 0;
}
