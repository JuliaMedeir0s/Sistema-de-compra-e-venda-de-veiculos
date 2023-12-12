
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

void procurarVeiculo(char *parametro, char *nomeArquivo) {
    FILE *arquivo;
    char linha[100]; // Tamanho arbitrário para armazenar cada linha do arquivo

    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Verifica se o parâmetro está presente na linha
        if (strstr(linha, parametro) != NULL) {
            printf("%s", linha); // Imprime a linha se o parâmetro for encontrado
        }
    }

    fclose(arquivo);
}

veiculo* buscarVeiculo(char *nomeArquivo,char *param) {
    FILE *arquivo;
    char linha[250];
    int cont = 0, i = 0;
  
    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return NULL;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Verifica se o parâmetro está presente na linha
        if (strstr(linha, param) != NULL) {
           cont++;
        }
    }
      fseek(arquivo, 0, SEEK_SET);
    veiculo *veiculos = (veiculo *)malloc(cont * sizeof(veiculo));

  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
      // Verifica se o parâmetro está presente na linha
      if (strstr(linha, param) != NULL) {
          printf("%s", linha);
          // Extrai os dados do veículo
          char *token;
          veiculo tempVeiculo;
          token = strtok(linha, ",");
          sscanf(token, "%f", &tempVeiculo.preco);
          token = strtok(NULL, ",");
          sscanf(token, "%d", &tempVeiculo.ano);
          token = strtok(NULL, ",");
          strcpy(tempVeiculo.marcVeic.marc, token);
          token = strtok(NULL, ",");
          strcpy(tempVeiculo.modelo, token);
          token = strtok(NULL, ",");
          strcpy(tempVeiculo.condicao, token);
          token = strtok(NULL, ",");
          strcpy(tempVeiculo.combustivel, token);
          token = strtok(NULL, ",");
          sscanf(token, "%f", &tempVeiculo.odometro);
          token = strtok(NULL, ",");
          strcpy(tempVeiculo.status, token);
          token = strtok(NULL, ",");
          strcpy(tempVeiculo.cambio, token);
          token = strtok(NULL, ",");
          strcpy(tempVeiculo.tamanho, token);
          token = strtok(NULL, ",");
          strcpy(tempVeiculo.tipo, token);
          token = strtok(NULL, ",");
          strcpy(tempVeiculo.cor, token);

          veiculos[i] = tempVeiculo;
        i++;
      }
  }


    fclose(arquivo);
  return veiculos;
}

int main() {
    char *parametroDeBusca = "Ford"; // Substitua pelo parâmetro desejado
    veiculo *vetVeiculo = buscarVeiculo("veiculos_ofertas.csv", parametroDeBusca);
  procurarVeiculo(parametroDeBusca, "veiculos_ofertas.csv");
    return 0;
}
