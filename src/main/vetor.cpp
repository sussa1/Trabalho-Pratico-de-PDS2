#include <vector>
#include <algorithm>
#include <cmath>
#include "vetor.h"

Vetor::Vetor(int dimensao) {
    _valoresVetor.resize(dimensao);
}

double& Vetor::operator[](int coord) {
    return _valoresVetor[coord];
}

double Vetor::operator*(const Vetor& v2) {
    double soma = 0;
    for (int i = 0; i < std::min(_valoresVetor.size(), v2._valoresVetor.size()); i++) {
        soma = soma + (_valoresVetor[i] * v2._valoresVetor[i]);
    }
    return soma;
}

double Vetor::norma() const {
    double soma = 0, valor;
    for (int i = 0; i < _valoresVetor.size(); i++) {
        soma = soma + (valor * valor);
    }
    return std::sqrt(soma);
}