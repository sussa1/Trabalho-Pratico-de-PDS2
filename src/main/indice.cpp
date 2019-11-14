#include "indice.h"
#include "vetor.h"
#include "util.h"
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <cmath>

Indice::Indice(std::map<std::string, std::map<std::string, int> > documentos) {
    int contCoord = 0;
    _numeroDocumentos = documentos.size();
    for(std::pair<std::string, std::map<std::string, int> > documento : documentos) {
        for(std::pair<std::string, int> palavra : documento.second) {
            if(_coordPalavra.find(palavra.first) == _coordPalavra.end()) {
                _coordPalavra[palavra.first] = contCoord;
                contCoord++;
            }
            _numDocsPalavra[palavra.first]++;
        }
    }
    _numeroTotalPalavras = contCoord;
    for(std::pair<std::string, std::map<std::string, int> > documento : documentos) {
        _vetores[documento.first] = Vetor(contCoord);
        for(std::pair<std::string, int> palavra : documento.second) {
            Vetor& doc = _vetores[documento.first];
            //W(d_j, P_x) = tf(d_j, P_x) × idf(P_x)
            doc[_coordPalavra[palavra.first]] = palavra.second * std::log(((double)_numeroDocumentos)/_numDocsPalavra[palavra.first]);
        }
    }
}

Vetor Indice::obterVetorDocumento(std::string documento) const {
    return _vetores.at(documento);
}

Vetor Indice::construirVetorQuery(std::string query) {
    query = Util::TransformarEmMinusculo(query);
    query = Util::RemoverCaracteresEspeciaisString(query);
    std::vector<std::string> palavrasQuery = Util::SepararStringPorPalavra(query);
    std::map<std::string, int> frequenciaPalavras;
    Vetor vetorQuery(_numeroTotalPalavras);
    for(std::string palavra: palavrasQuery) {
        //Se é uma palavra pertencente a algum documento
        if(_numDocsPalavra.find(palavra) != _numDocsPalavra.end()) {
            frequenciaPalavras[palavra]++;   
        }
    }
    for(std::pair<std::string, int> palavra : frequenciaPalavras) {
        //W(d_j, P_x) = tf(d_j, P_x) × idf(P_x)
        vetorQuery[_coordPalavra[palavra.first]] = palavra.second * std::log(((double)_numeroDocumentos)/_numDocsPalavra[palavra.first]);
    }
    return vetorQuery;
}