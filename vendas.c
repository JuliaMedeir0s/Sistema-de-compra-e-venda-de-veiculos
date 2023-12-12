#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_LINHA 200 // Tamanho máximo da linha do arquivo

//---------------------------------------------------------------
// struct marca e veiculo
// função preenche veiculo
typedef struct{
    char marc[20];
    float taxa;
} marca;

typedef struct{
    float preco, odometro;
    int ano;
    char modelo[20], condicao[20], combustivel[20], status[20], cambio[20], tamanho[20], tipo[20], cor[20];
    marca marcVeic;
} veiculo;

veiculo preencheVeiculo(){

    veiculo carro;
    int op;

    carro.preco = 10500;
    carro.odometro = 129035;
    carro.ano = 2010;
    strcpy(carro.modelo, "g37");
    strcpy(carro.condicao, "desconhecido");
    strcpy(carro.combustivel, "gasolina");
    strcpy(carro.status, "alienado");
    strcpy(carro.cambio, "automatico");
    strcpy(carro.tamanho, "medio");
    strcpy(carro.tipo, "sedan");
    strcpy(carro.cor, "fantasia");
    strcpy(carro.marcVeic.marc, "infiniti");
    return carro;
}
//---------------------------------------------------------------
//---------------------------------------------------------------


void vendeVeiculo(char *veiculos_estoque, char *historico_vendas, veiculo *veiculoEncontrado)
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
        if (strcmp(linha, veiculosEncontrados) != 0) // compara o veículo desejado e a informação do arquivo oferta
        {
            fprintf(temporarioFile, "%s", linha); // Escreve no arquivo temporário
        }
        else
        {
            encontrado = 1;              // veiculo encontrado
            fprintf(arquivoEstoque, "%s", ""); // apaga veiculo encontrado do estoque
            // também precisa adicionar ao historico de vendas
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            fprintf(arquivoVendas, "%s,%d-%02d-%02d %02d:%02d:%02d\n", linha, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        }
    }

    int main()
    {
        struct veiculo veiculosEncontrados; // declarado vetor com as informações do carro desejado
        veiculosEncontrados = preencheVeiculo();

        vendeVeiculo("veiculos_estoque.csv", "historico_vendas.csv", veiculosEncontrados);
    }
}