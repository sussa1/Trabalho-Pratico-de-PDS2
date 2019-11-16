#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "indice_invertido.h"
#include "documento.h"

IndiceInvertido::IndiceInvertido(std::vector<Documento>& documentos) {
    _numDocumentos = 0;
    for(Documento documento : documentos) {
        for(std::string palavra : documento.obterPalavras()) {
            _relacaoPalavraDocumento[palavra].insert(documento);
        }
        _numDocumentos++;
    }
}

std::vector<Documento> IndiceInvertido::obterDocumentosPalavra(std::string palavra) const {
    return std::vector<Documento>(_relacaoPalavraDocumento.at(palavra).begin(), _relacaoPalavraDocumento.at(palavra).end());
}

std::set<std::string> IndiceInvertido::obterTodasPalavras() const {
    std::set<std::string> palavras;
    for(std::pair<std::string, std::set<Documento> > palavraDocumentos : _relacaoPalavraDocumento) {
        palavras.insert(palavraDocumentos.first);
    }
    return palavras;
}

int IndiceInvertido::obterNumeroDocumentosRegistrados() const {
    return _numDocumentos;
}
