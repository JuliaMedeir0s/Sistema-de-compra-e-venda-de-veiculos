
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

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

    carro.preco = 0;
    carro.odometro = 0;
    carro.ano = 0;
    strcpy(carro.modelo, "");
    strcpy(carro.condicao, "");
    strcpy(carro.combustivel, "");
    strcpy(carro.status, "");
    strcpy(carro.cambio, "");
    strcpy(carro.tamanho, "");
    strcpy(carro.tipo, "");
    strcpy(carro.cor, "");
    strcpy(carro.marcVeic.marc, "");

    do
    {
        printf("Digite a opção desejada para atualizar o carro:\n"
        " 1 - preço\n 2 - Odometro\n 3 - Ano\n 4 - Modelo\n 5 - Condiçao\n"
        " 6 - Combustivel\n 7 - Status\n 8 - Cambio\n 9 - Tamanho\n"
        " 10 - Tipo\n 11 - Cor\n 12 - Marca\n 13 - Sair\n");
        scanf("%d", &op);
        
        if(op < 1 ||  op > 13)
        {
            printf("Operação inválida\n");
            continue;
        }

        switch(op)
        {
            case 1:
            printf("Digite o preço: \n");
            scanf("%f", &carro.preco);
            break;

            case 2:
            printf("Digite o odometro: \n");
            scanf("%f", &carro.odometro);
            break;

            case 3:
            printf("Digite o ano: \n");
            scanf("%d", &carro.ano);
            break;

            case 4:
            printf("Digite o modelo: \n");
            scanf(" %20[^\n]", carro.modelo);
            break;

            case 5:
            printf("Digite a condição: \n");
            scanf(" %20[^\n]", carro.condicao);
            break;

            case 6:
            printf("Digite o combustivel: \n");
            scanf(" %20[^\n]", carro.combustivel);
            break;

            case 7:
            printf("Digite o Status: \n");
            scanf(" %20[^\n]", carro.status);
            break;

            case 8:
            printf("Digite o cambio: \n");
            scanf(" %20[^\n]", carro.cambio);
            break;

            case 9:
            printf("Digite o tamanho: \n");
            scanf(" %20[^\n]", carro.tamanho);
            break;

            case 10:
            printf("Digite o tipo: \n");
            scanf(" %20[^\n]", carro.tipo);
            break;

            case 11:
            printf("Digite o modelo: \n");
            scanf(" %20[^\n]", carro.cor);
            break;

            case 12:
            printf("Digite o modelo: \n");
            scanf(" %20[^\n]", &carro.marcVeic.marc);
            break;

            case 13:
            printf("Finalizado \n");
            return carro;
            break;
            
            default: 
            printf("Opçao inválida!\n");
            break;
                        
        }

    }while( op < 1 ||  op > 13);

}

veiculo* encontrarVeiculos(const char *nomeArquivo, veiculo v1, int *numVeiculosEncontrados) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    veiculo *veiculosEncontrados = NULL;
    char linha[256]; // Tamanho máximo da linha no arquivo
    int capacidade = 10; // Capacidade inicial do vetor
    *numVeiculosEncontrados = 0;

    veiculosEncontrados = (veiculo*)malloc(capacidade * sizeof(veiculo));

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Extrai os campos da linha
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

        // Comparação dos campos
        if ((v1.preco == 0 || v1.preco == tempVeiculo.preco) &&
            (v1.ano == 0 || v1.ano == tempVeiculo.ano) &&
            (strcmp(v1.marcVeic.marc, "") == 0 || strcmp(v1.marcVeic.marc, tempVeiculo.marcVeic.marc) == 0) &&
            (strcmp(v1.modelo, "") == 0 || strcmp(v1.modelo, tempVeiculo.modelo) == 0) &&
            (strcmp(v1.condicao, "") == 0 || strcmp(v1.condicao, tempVeiculo.condicao) == 0) &&
            (strcmp(v1.combustivel, "") == 0 || strcmp(v1.combustivel, tempVeiculo.combustivel) == 0) &&
            (v1.odometro == 0 || v1.odometro == tempVeiculo.preco) &&
            (strcmp(v1.condicao, "") == 0 || strcmp(v1.condicao, tempVeiculo.condicao) == 0) &&
            (strcmp(v1.status, "") == 0 || strcmp(v1.status, tempVeiculo.status) == 0) &&
            (strcmp(v1.cambio, "") == 0 || strcmp(v1.cambio, tempVeiculo.cambio) == 0) &&
            (strcmp(v1.tamanho, "") == 0 || strcmp(v1.tamanho, tempVeiculo.tamanho) == 0) &&
            (strcmp(v1.tipo, "") == 0 || strcmp(v1.tipo, tempVeiculo.tipo) == 0) &&
            (strcmp(v1.cor, "") == 0 || strcmp(v1.cor, tempVeiculo.cor) == 0))
            {
                if (*numVeiculosEncontrados >= capacidade)
                {
                    capacidade *= 2;
                    veiculosEncontrados = realloc(veiculosEncontrados, capacidade * sizeof(veiculo));
                }
                veiculosEncontrados[*numVeiculosEncontrados] = tempVeiculo;
                (*numVeiculosEncontrados)++;
            }
    }

    fclose(arquivo);
    return veiculosEncontrados;
}

int main() {
    veiculo meuVeiculo = {0}; // Preencha os campos que deseja buscar

    int numEncontrados;
    veiculo *encontrados = encontrarVeiculos("nome_do_arquivo.txt", meuVeiculo, &numEncontrados);

    // Faça o uso dos veículos encontrados aqui
    if (encontrados != NULL) {
        for (int i = 0; i < numEncontrados; i++) {
            // Faça o que desejar com os veículos encontrados
            printf("Veículo %d:\n", i + 1);
            printf("Preço: %.2f\n", encontrados[i].preco);
            printf("Ano: %d\n", encontrados[i].ano);
            // Imprima os demais campos do veículo aqui
        }
        free(encontrados); // Não esqueça de liberar a memória alocada
    }

    return 0;
}
