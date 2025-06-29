#ifndef TABELA_Z_H
#define TABELA_Z_H

int carregarTabelaZ(const char *nomeArquivo, double z[], double prob[], int tamanhoMax);
double buscarProbabilidade(double zBuscado, double z[], double prob[], int tamanho);

#endif
