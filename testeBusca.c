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
