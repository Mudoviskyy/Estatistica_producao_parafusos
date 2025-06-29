#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "estatistica.h"

double calcularMedia(double dados[], int tamanho) {
    double soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += dados[i];
    }
    return soma / tamanho;
}

double calcularDesvioPadrao(double dados[], int tamanho, double media) {
    double soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += pow(dados[i] - media, 2);
    }
    return sqrt(soma / (tamanho - 1));
}

double calcularCoeficienteVariacao(double media, double desvioPadrao) {
    if (media == 0) return 0;
    return (desvioPadrao/media) * 100;

}

//função de copmparação de uma array para o qsort
int comparar (const void *a, const void *b){
    double diff = *(double*)a - *(double*)b;
    return (diff > 0) - (diff < 0 );
}
double calcularMediana(double dados[], int tamanho) {
    qsort(dados, tamanho, sizeof(double), comparar);// ordenação dos dados

    //para itens pares = media dos 2 do meio
    if (tamanho % 2 == 0){
        return (dados[tamanho/2-1] + dados[tamanho/2]) / 2.0;
    }else{
        //para dados impares
        return  dados[tamanho/2];
    }

}

void verificarQualidade(double dados[], int tamanho, double limite_inf, double limite_sup) {
    int defeituosos = 0;
    for (int i = 0; i < tamanho; i++) {
        if (dados[i] < limite_inf || dados[i] > limite_sup) {
            printf("\nParafuso %d FORA do padrão/defeituoso (%.2lf)\n", i + 1, dados[i]);
            defeituosos++;
        }
    }
    if (defeituosos == 0) {
        printf("\n Todos os parafusos estão dentro do padrão exigido!\n");
    } else {
        printf("\n %d Parafuso(s) fora do padrão.\n", defeituosos);
    }
}
