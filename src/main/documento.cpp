#include "documento.h"
#include <iostream>
#include <vector>
#include <algorithm>

Documento::Documento(int id, std::string nome, std::vector<std::string> palavras) {
    _nome = nome;
    _palavras = palavras;
    _id = id;
}

int Documento::obterFrequenciaPalavra(std::string palavra) const {
    return std::count(_palavras.begin(), _palavras.end(), palavra);
}

std::string Documento::obterNomeDocumento() const {
    return _nome;
}

std::vector<std::string> Documento::obterPalavras() const {
    return _palavras;
}

int Documento::obterIdDocumento() const {
    return _id;
}

bool Documento::operator< (const Documento& d) const{
    return _id < d.obterIdDocumento();
}