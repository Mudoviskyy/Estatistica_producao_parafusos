#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "entrada_dados.h"


double gerarNumeroReal(double media, double desvio){
    //método de Box-Muller para geração dos numeros proximo da realidade
    double u1 = (rand() + 1.00) / (RAND_MAX + 2.00);
    double u2 = (rand() + 1.00) / (RAND_MAX + 2.00);

    double z = sqrt(-2.0 * log (u1)) * cos(2.0 * M_PI * u2);

    return media + z * desvio;
}


void gerarDados(double dados[], int tamanho) {
    // simulação da produção dos parafusos
    double media = 5;
    double desvio = 0.50;

    srand(time (NULL));
    printf("\nLendo a produção dos parafusos no sensor\n");
    Sleep(3000);

    //gera comprimento aleatório entre desvio -max e +max
    for (int i = 0; i < tamanho; i++) {

            dados[i] = gerarNumeroReal(media, desvio);

        printf("Parafuso %d: %.2lf cm \n ", i + 1, dados[i]);

    }
}
