#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_LINHA 200 // Tamanho máximo da linha do arquivo

// -------------------------------------- Filtro de Busca --------------------------------------
typedef struct
{
    float preco, odometro;
    int ano;
    char marca[20], modelo[20], condicao[20], combustivel[20], status[20], cambio[20], tamanho[20], tipo[20], cor[20];
} veiculo;

// Função para transformar os dados do veículo em uma string formatada
char *veiculoToString(veiculo carro)
{
    static char veiculoString[TAM_LINHA]; // String para armazenar os dados do veículo

    // Formata os dados do veículo em uma string
    sprintf(veiculoString, "%.2f,%d,%s,%s,%s,%s,%.2f,%s,%s,%s,%s,%s",
            carro.preco, carro.ano, carro.marca, carro.modelo, carro.condicao,
            carro.combustivel, carro.odometro, carro.status, carro.cambio, carro.tamanho,
            carro.tipo, carro.cor);

    return veiculoString;
}

// Função para selecionar o parâmetro de filtro
void selecionarParametro(char **parametro, char **tipoParametro)
{
    int opcao;

    printf("Opção o parâmetro para filtrar:\n");
    printf("1. Marca\n");
    printf("2. Modelo\n");
    printf("3. Ano\n");
    printf("4. Cor\n");
    printf("5. Tipo\n");
    printf("6. Combustivel\n");
    printf("7. Status\n");
    printf("8. Condicao\n");
    printf("9. Tamanho\n");
    printf("10. Preco\n");
    printf("11. Odometro\n");
    printf("12. Cambio\n");
    printf("13. Sair\n");

    printf("Digite o número correspondente ao parâmetro desejado: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        *tipoParametro = "marca";
        printf("Digite a marca desejada: ");
        scanf("%s", *parametro);
        break;
    case 2:
        *tipoParametro = "modelo";
        printf("Digite o modelo desejado: ");
        scanf("%s", *parametro);
        break;
    case 3:
        *tipoParametro = "ano";
        printf("Digite o ano desejado: ");
        scanf("%s", *parametro);
        break;
    case 4:
        *tipoParametro = "cor";
        printf("Digite o cor desejada: ");
        scanf("%s", *parametro);
        break;
    case 5:
        *tipoParametro = "tipo";
        printf("Digite o tipo desejado: ");
        scanf("%s", *parametro);
        break;
    case 6:
        *tipoParametro = "combustivel";
        printf("Digite o combustivel desejado: ");
        scanf("%s", *parametro);
        break;
    case 7:
        *tipoParametro = "status";
        printf("Digite o status desejado: ");
        scanf("%s", *parametro);
        break;
    case 8:
        *tipoParametro = "condicao";
        printf("Digite o condicao desejado: ");
        scanf("%s", *parametro);
        break;
    case 9:
        *tipoParametro = "tamanho";
        printf("Digite o tamanho desejado: ");
        scanf("%s", *parametro);
        break;
    case 10:
        *tipoParametro = "preco";
        printf("Digite o preco desejado: ");
        scanf("%s", *parametro);
        break;
    case 11:
        *tipoParametro = "odometro";
        printf("Digite o odometro desejado: ");
        scanf("%s", *parametro);
        break;
    case 12:
        *tipoParametro = "cambio";
        printf("Digite o cambio desejado: ");
        scanf("%s", *parametro);
        break;
    case 13:
        printf("Saindo do filtro...");
        break;
    default:
        printf("Opção inválida.\n");
        break;
    }
}

veiculo *filtroDeBusca(const char *tipoParametro, const char *valorParametro, const char *nomeArquivo, int *numCarrosEncontrados) {
    FILE *arquivo;
    char linha[100];
    veiculo *vetVeiculo = malloc(350 * sizeof(veiculo));
    int carrosEncontrados = 0;

    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return NULL;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        veiculo Vbusca;
        sscanf(linha, "%f,%d,%[^,],%[^,],%[^,],%[^,],%f,%[^,],%[^,],%[^,],%[^,],%[^,],",
               &Vbusca.preco, &Vbusca.ano, Vbusca.marca, Vbusca.modelo, Vbusca.condicao,
               Vbusca.combustivel, &Vbusca.odometro, Vbusca.status, Vbusca.cambio,
               Vbusca.tamanho, Vbusca.tipo, Vbusca.cor);

        if (strcmp(tipoParametro, "preco") == 0 && Vbusca.preco == atof(valorParametro)) {
            vetVeiculo[carrosEncontrados] = Vbusca;
            carrosEncontrados++;
            // Exibir os demais campos necessários aqui
        } else if (strcmp(tipoParametro, "ano") == 0 && Vbusca.ano == atoi(valorParametro)) {
            vetVeiculo[carrosEncontrados] = Vbusca;
            carrosEncontrados++;
            
        } else if (strcmp(tipoParametro, "marca") == 0 && strcmp(Vbusca.marca, valorParametro) == 0) {
            vetVeiculo[carrosEncontrados] = Vbusca;
            carrosEncontrados++;
            
            // Exibir os demais campos necessários aqui
        }
        // Adicionar outras condições conforme necessário para outros tipos de parâmetro

    }

    (*numCarrosEncontrados) = carrosEncontrados;
    fclose(arquivo);
    return vetVeiculo;
}

// -------------------------------------- Taxas --------------------------------------

void adicionarMarca(const char *arquivoMarcas, const char *marca)
{
    float taxa;
    FILE *fileMarcas = fopen(arquivoMarcas, "r+");

    if (fileMarcas == NULL)
    {
        printf("Erro ao abrir o arquivo de marcas.\n");
        return;
    }

    char linha[100];
    int marcaExiste = 0;

    // Verifica se a marca já existe no arquivo
    while (fgets(linha, sizeof(linha), fileMarcas) != NULL)
    {
        char *token = strtok(linha, ",");
        token = strtok(NULL, ","); // Pula o primeiro token
        token = strtok(NULL, ","); // Terceiro token que deve ser a marca

        if (token != NULL && strcmp(token, marca) == 0)
        {
            marcaExiste = 1;
            break;
        }
    }

    // Se a marca não existe, adiciona ao arquivo
    if (!marcaExiste)
    {
        // pedir o valor da taxa para o usuário
        printf("Insira a taxa para a marca %s: ", marca);
        scanf("%f", &taxa);
        fseek(fileMarcas, 0, SEEK_END);
        if (ftell(fileMarcas) > 0)
        {
            fprintf(fileMarcas, "\n"); // Adiciona uma nova linha se o arquivo não estiver vazio
        }
        fprintf(fileMarcas, "%.2f,%s\n", taxa, marca);
        printf("Marca adicionada: %s com taxa de %.2f\n", marca, taxa);
    }
    else
    {
        printf("Marca ja existe: %s\n", marca);
    }

    fclose(fileMarcas);
}
// -------------------------------------- Compra de Veículos --------------------------------------

// Função para remover um veículo do arquivo de ofertas
void comprarVeiculo(const char *ofertas, const char *estoque, const char *historico, char *veiculoComprado, int novoPreco, const char *marcas)
{
    // abre os arquivos
    FILE *fileOfertas = fopen(ofertas, "r");
    FILE *fileEstoque = fopen(estoque, "a");
    FILE *fileHistorico = fopen(historico, "a");

    // verifica se os arquivos abriram corretamente
    if (fileOfertas == NULL || fileEstoque == NULL || fileHistorico == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Cria um arquivo temporário em memória, para passar as linhas que não correspondem ao veículo comprado
    FILE *temporarioFile = tmpfile(); // tmpfile() cria um arquivo temporário na memória RAM, essa função pertence a biblioteca stdio.h

    char linha[TAM_LINHA]; // para ler cada linha do documento de ofertas
    int encontrado = 0;    // usar para controlar se o veículo foi encontrado

    // lê todas as linhas do arquivo ofertas
    while (fgets(linha, TAM_LINHA, fileOfertas) != NULL)
    {

        if (strcmp(linha, veiculoComprado) != 0)
        {                                         // verifica se o veiculo foi encontrado, se não...
            fprintf(temporarioFile, "%s", linha); // Escreve as linhas não desejadas no arquivo temporário
        }
        else
        {
            encontrado = 1; // veículo encontrado

            // Separa a linha em tokens para obter o preço original
            char *token = strtok(linha, ",");
            int precoOriginal = atoi(token); // Converte o preço atual para int

            // Adiciona o novo preço à linha antes de escrever no arquivo de estoque
            // a função strchr() é responsável por buscar a primeira ocorrencia de um caracter em uma string
            fprintf(fileEstoque, "%d,%s", novoPreco, strchr(linha, ',')); // altera para o novo preço

            // também precisa adicionar ao historico de compras,
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            fprintf(fileHistorico, "%s,%d-%02d-%02d %02d:%02d:%02d\n", linha, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        }
    }

    fclose(fileOfertas);
    fclose(fileEstoque);
    fclose(fileHistorico);

    // Reescreve o arquivo de ofertas com as informações atualizadas, excluindo o veículo comprado
    freopen(ofertas, "w", fileOfertas);
    rewind(temporarioFile); // move o indicador de posição no arquivo para o início

    // vai repetir enquando o arquivo temporario não chegar ao final
    while (fgets(linha, TAM_LINHA, temporarioFile) != NULL)
    {
        fprintf(fileOfertas, "%s", linha);
    }
    // identificar a marca para saber se já existe taxa dela no arquivo de marcas
    char *token = strtok(veiculoComprado, ","); // primeiro informação da linha
    token = strtok(NULL, ",");                  // segunda informação da linha
    token = strtok(NULL, ",");                  // Terceira informação da linha

    if (token != NULL)
    {
        adicionarMarca(marcas, token); // chama a função que vai verificar a existencia e adicionar caso não exista
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

// -------------------------------------- Função para exibir o menu --------------------------------------
void exibirMenu()
{
    printf("\n===== MENU =====\n");
    printf("1. Comprar veículo\n");
    printf("2. Vender veículo\n");
    printf("3. Taxa de veículos\n");
    printf("4. Alterar dados\n");
    printf("5. Relatórios de compra e venda\n");
    printf("6. Backup\n");
    printf("7. Sair\n");
    printf("Escolha uma opção: ");
}

void exibirMenuBackup()
{
    printf("\nFazer backup do:\n");
    printf("1. Estoque\n");
    printf("2. Histórico de compras\n");
    printf("3. Histórico de vendas\n");
    printf("4. Cancelar\n");
    printf("Escolha uma opção: ");
}

int main()
{
    // lista de arquivos usados o programa
    char *ofertas = "veiculos_ofertas.csv";
    char *estoque = "veiculos_estoque.csv";
    char *taxas = "marcas.csv";
    char *historicoCompras = "historico_compras.csv";
    char *historicoVendas = "historico_vendas.csv";

    char *parametroDeBusca; // Substitua pelo parâmetro desejado
    char *tipoParametro;

    int opcao;
    char veiculoComprado[TAM_LINHA]; // armazena as informações do veículo comprado
    int novoPreco;
    int backup;

    // Exibir o menu até que o usuário selecione para sair
    do
    {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            selecionarParametro(&parametroDeBusca, &tipoParametro);
            printf("Parametro: %s\n", tipoParametro);
            printf("Valor de parametroDeBusca: %s\n", parametroDeBusca);
            veiculo *carro;
            int *numCarrosEncontrados = 0;

            carro = filtroDeBusca(tipoParametro, parametroDeBusca, ofertas, &numCarrosEncontrados);
            
            printf("%d carros encontrados.\n", numCarrosEncontrados); // Adicione essa linha
            if (numCarrosEncontrados > 0)
            {
                printf("Foram encontrados os seguintes carros:\n");
                for (int i = 0; i < numCarrosEncontrados; i++)
                {
                    printf("%d. %s - %s - %d - %.2f - %s - %s - %s - %s - %s - %s - %s - %.2f \n", i + 1, carro[i].marca, carro[i].modelo, carro[i].ano, carro[i].preco, carro[i].cor, carro[i].tipo, carro[i].combustivel, carro[i].condicao, carro[i].status, carro[i].tamanho, carro[i].cambio, carro[i].odometro);
                }

                int escolha;
                printf("Selecione o número correspondente ao carro desejado: ");
                scanf("%d", &escolha);

                if (escolha >= 1 && escolha <= numCarrosEncontrados)
                {
                    veiculo carroSelecionado = carro[escolha - 1];
                    char *stringCarro = veiculoToString(carroSelecionado);
                    printf("Qual o novo preço dele?");
                    scanf("%d", &novoPreco);
                    comprarVeiculo(ofertas, estoque, historicoCompras, stringCarro, novoPreco, taxas);
                }
                else
                {
                    printf("Escolha inválida.\n");
                }
            }
            else
            {
                printf("Nenhum carro encontrado.\n");
            }

            break;
        case 2:
            // filtroDeBusca();
            // venderVeiculo();
            break;
        case 3:
            // filtroDeBuscaTaxa();
            // exibeTaxa();
            break;
        case 4:
            // filtroDeBusca();
            // alterarDados();
            break;
        case 5:
            // relatorioDeCompraEVenda();
            break;
        case 6:
            // exibir opções de backup
            exibirMenuBackup();
            scanf("%d", &backup);
            if (backup == 1)
                break;
        case 7:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida! Escolha uma opção válida.\n");
        }
    } while (opcao != 7);

    return 0;
}
