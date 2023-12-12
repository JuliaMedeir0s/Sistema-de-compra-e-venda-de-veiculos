#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

veiculo procurarVeiculo(char *parametro, char *nomeArquivo) {
    FILE *arquivo;
    char linha[100]; // Tamanho arbitrário para armazenar cada linha do arquivo
    veiculo Vbusca;

    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Verifica se o parâmetro está presente na linha
        if (strstr(linha, parametro) != NULL) {
            printf("%s", linha); // Imprime a linha se o parâmetro for encontrado
            Vbusca.preco = atoi(strtok(linha,","));
            Vbusca.ano = atoi(strtok(NULL,","));
            strcpy(Vbusca.marcVeic.marc, strtok(NULL,","));
            strcpy(Vbusca.modelo, strtok(NULL,","));
            strcpy(Vbusca.condicao, strtok(NULL,","));
            strcpy(Vbusca.combustivel, strtok(NULL,","));
            Vbusca.odometro = atoi(strtok(NULL,","));
            strcpy(Vbusca.status, strtok(NULL,","));
            strcpy(Vbusca.cambio, strtok(NULL,","));
            strcpy(Vbusca.tamanho, strtok(NULL,","));
            strcpy(Vbusca.tipo, strtok(NULL,","));
            strcpy(Vbusca.cor, strtok(NULL,","));
            break;
        }
    }

    fclose(arquivo);
    return Vbusca;
}


int main() {
    char *parametroDeBusca = "ford"; // Substitua pelo parâmetro desejado

   veiculo carro = procurarVeiculo(parametroDeBusca, "veiculos_ofertas.csv");

            printf("Veiculo %d:\n", 1);
            printf("Preço: %.2f\n", carro.preco);
            printf("Ano: %d\n", carro.ano);
            printf("Modelo: %s\n", carro.modelo);
            printf("Condição: %s\n", carro.condicao);
            printf("Combustível: %s\n", carro.combustivel);
            printf("Odometro: %.2f\n", carro.odometro);
            printf("Status: %s\n", carro.status);
            printf("Câmbio: %s\n", carro.cambio);
            printf("Tamanho: %s\n", carro.tamanho);
            printf("Tipo: %s\n", carro.tipo);
            printf("Cor: %s\n", carro.cor);
            printf("Marca: %s\n", carro.marcVeic.marc);
            printf("\n");


    return 0;
}
