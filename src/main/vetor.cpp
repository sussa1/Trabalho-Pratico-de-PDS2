#include "vetor.h"
#include <vector>
#include <algorithm>
#include <cmath>

Vetor::Vetor(int dimensao) {
    _valoresVetor.resize(dimensao);
}

double& Vetor::operator[](int coord) {
    return _valoresVetor[coord];
}

Vetor Vetor::operator*(const Vetor& v2) {
    Vetor novoVetor(this->_valoresVetor.size());
    for(int I=0; I<std::min(this->_valoresVetor.size(), v2._valoresVetor.size()); I++) {
        novoVetor[I] = this->_valoresVetor[I] * v2._valoresVetor[I];
    }
    return novoVetor;
}

double Vetor::norma() const {
    double soma = 0;
    for(double val : _valoresVetor) {
        soma+=val*val;
    }
    return std::sqrt(soma);
}