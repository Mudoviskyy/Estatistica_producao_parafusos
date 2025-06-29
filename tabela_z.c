#include <stdio.h>
#include <math.h>
#include "tabela_z.h"

// Carrega os dados da tabela Z de um arquivo txt
int carregarTabelaZ(const char *nomeArquivo, double z[], double prob[], int tamanhoMax) {
    FILE *file = fopen(nomeArquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo da tabela Z.\n");
        return -1;
    }

    int count = 0;
    while (count < tamanhoMax && fscanf(file, "%lf %lf", &z[count], &prob[count]) == 2) {
        count++;
    }

    fclose(file);
    return count;
}

// Busca a probabilidade mais próxima do valor Z informado
double buscarProbabilidade(double zBuscado, double z[], double prob[], int tamanho) {
    if (zBuscado < 0) zBuscado = -zBuscado;
    if (zBuscado > z[tamanho - 1]) zBuscado = z[tamanho - 1];

    double maisProximo = fabs(zBuscado - z[0]);
    double resultado = prob[0];

    for (int i = 1; i < tamanho; i++) {
        double distancia = fabs(zBuscado - z[i]);
        if (distancia < maisProximo) {
            maisProximo = distancia;
            resultado = prob[i];
        }
    }

    return resultado;
}
