#ifndef ESTATISTICA_H
#define ESTATISTICA_H

double calcularMedia(double dados[], int tamanho);
double calcularDesvioPadrao(double dados[], int tamanho, double media);
double calcularCoeficienteVariacao(double media, double desvioPadrao);
double calcularMediana(double dados[], int tamanho);
void verificarQualidade(double dados[], int tamanho, double limite_inf, double limite_sup);

#endif
