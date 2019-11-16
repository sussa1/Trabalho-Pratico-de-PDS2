#include "indexador.h"
#include "vetor.h"
#include "util.h"
#include "indice_invertido.h"
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>

Indexador::Indexador(IndiceInvertido& indiceInvertido) : _indiceInvertido(indiceInvertido){
    int contCoord = 0;
    _numeroDocumentos = indiceInvertido.obterNumeroDocumentosRegistrados();
    
    std::set<std::string> todasPalavras = indiceInvertido.obterTodasPalavras();

    _numeroTotalPalavras = todasPalavras.size();

    //Registra qual coordenada cada palavra representa
    for(std::string palavra : todasPalavras) {
        std::vector<Documento> documentosPalavra = indiceInvertido.obterDocumentosPalavra(palavra);
        for(Documento documento : documentosPalavra) {
            //Se é a primeira vez computando esse documento, inicializa seu vetor
            if(_vetoresDocumentos.find(documento.obterIdDocumento()) == _vetoresDocumentos.end()) {
                _vetoresDocumentos.insert({documento.obterIdDocumento(), Vetor(_numeroTotalPalavras)});
            }

            Vetor& vetorDocumento = _vetoresDocumentos.at(documento.obterIdDocumento());
            
            //Realiza a formula para a coordenada da palavra nesse documento
            //W(d_j, P_x) = tf(d_j, P_x) × idf(P_x)
            vetorDocumento[contCoord] = documento.obterFrequenciaPalavra(palavra) * std::log(((double)_numeroDocumentos)/documentosPalavra.size());
        }
        _coordPalavra[palavra] = contCoord;
        contCoord++;
    }
}

Vetor Indexador::obterVetorDocumento(Documento documento) const {
    return _vetoresDocumentos.at(documento.obterIdDocumento());
}

Vetor Indexador::construirVetorQuery(std::string query) {
    query = Util::TransformarEmMinusculo(query);
    query = Util::RemoverCaracteresEspeciaisString(query);
    std::vector<std::string> palavrasQuery = Util::SepararStringPorPalavra(query);
    std::map<std::string, int> frequenciaPalavras;
    Vetor vetorQuery(_numeroTotalPalavras);
    std::set<std::string> todasPalavras = _indiceInvertido.obterTodasPalavras();
    for(std::string palavra: palavrasQuery) {
        //Se é uma palavra pertencente a algum documento
        if(todasPalavras.find(palavra) != todasPalavras.end()) {
            frequenciaPalavras[palavra]++;   
        }
    }
    for(std::pair<std::string, int> frequenciaPalavra : frequenciaPalavras) {
        std::string palavra = frequenciaPalavra.first;
        int frequencia = frequenciaPalavra.second;
        int numeroDeDocumentosDaPalavra = _indiceInvertido.obterDocumentosPalavra(palavra).size();
        //W(d_j, P_x) = tf(d_j, P_x) × idf(P_x)
        vetorQuery[_coordPalavra[palavra]] = frequencia * std::log(((double)_numeroDocumentos)/numeroDeDocumentosDaPalavra);
    }
    return vetorQuery;
}