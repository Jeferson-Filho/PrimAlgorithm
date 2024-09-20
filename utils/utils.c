#include "utils/utils.h"
#include <math.h>

// Cálculo da média
double calcularMedia(float *custos, int n) {
    double soma = 0;
    for (int i = 0; i < n; i++) {
        soma += custos[i];
    }
    return soma / n;
}

// Cálculo do desvio padrão
double calcularDesvioPadrao(float *custos, int n) {
    double media = calcularMedia(custos, n);
    double soma_variancia = 0;
    for (int i = 0; i < n; i++) {
        soma_variancia += (custos[i] - media) * (custos[i] - media);
    }
    return sqrt(soma_variancia / n);
}