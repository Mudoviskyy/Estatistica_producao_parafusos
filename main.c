#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#include "entrada_dados.h"
#include "estatistica.h"
#include "tabela_z.h"


#define MAX_TABELA 100

int main() {
    double tabelaZ[MAX_TABELA];
    double tabelaProb[MAX_TABELA];

    int tamanhoTabela = carregarTabelaZ("tabela_z.txt", tabelaZ, tabelaProb, MAX_TABELA);
    if (tamanhoTabela <= 0) {
        printf("Erro na leitura da tabela Z.\n");
        return 1;
    }
    setlocale(LC_ALL, "");
    system("color 0A");

    printf("                      ***** Trabalho de Estat�stisca - Unifacvest *****\n");
    printf("                         ***** Programa Analisador de Produ��o *****\n");
    printf("                       ***** Parafusos Defeituosos ou fora do padr�o *****\n");
    printf("***** Descubra a M�dia - Desvio Padr�o - Limite de controle - Verifica��o de qualidade *****\n");
    int tamanho;
    printf("\n Informe a quantidade de parafusos na amostra? ");
    scanf("%d", &tamanho);

    double dados[tamanho];
    gerarDados(dados, tamanho);

    printf("\nCalculando a m�dia\n");
    Sleep(2000);
    double media = calcularMedia(dados, tamanho);

    printf("\nCalculando o desvio\n");
    double desvio = calcularDesvioPadrao(dados, tamanho, media);
    Sleep(2000);

    printf("\nCalculando a mediana\n");
    double mediana = calcularMediana(dados, tamanho);
    Sleep(2000);

    printf("\nCalculando o coeficiante de varia��o\n");
    double cv = calcularCoeficienteVariacao(media, desvio);
    Sleep(2000);

    printf("\nM�dia: %.2lf\n", media);
    printf("\nDesvio Padr�o: %.2lf\n", desvio);
    printf("\nMediana: %.2lf\n", mediana);
    printf("\nCoeficiente de Varia��o: %.2lf\n", cv);

    //valor de refer�ncia para o n�vel de confian�a de 95%
    double limite_inferior = media - 2 * desvio;
    double limite_superior = media + 2 * desvio;

    printf("\nLimites de controle: [%.2lf , %.2lf]\n", limite_inferior, limite_superior);

    printf("\nVerificando a qualidade\n");
    Sleep(5000);
    verificarQualidade(dados, tamanho, limite_inferior, limite_superior);

    //probabilidade de encontrar um valor menor ou igual a 2 desvios acima da m�dia
    double z = 2.00;
    double prob = buscarProbabilidade(z, tabelaZ, tabelaProb, tamanhoTabela);
    printf("\nPara Z = %.2lf, a probabilidade acumulada � %.4lf\n", z, prob);

    return 0;
}
