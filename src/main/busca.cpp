#include "busca.h"
#include "indexador.h"
#include "vetor.h"
#include "util.h"
#include "indice_invertido.h"
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <tuple>

Busca::Busca(IndiceInvertido& indiceInvertido, Indexador& indexador, std::vector<Documento>& documentos):_indexador(indexador), 
    _indiceInvertido(indiceInvertido), _documentos(documentos){
    
}

std::vector<Documento> Busca::obterRelevanciaQuery(std::string query){
    Vetor vetorQuery = _indexador.construirVetorQuery(query);
    Vetor vetorD_j(_indiceInvertido.obterTodasPalavras().size());
    std::vector<std::pair<double, Documento>> vetorSimilaridade;

    for(Documento documento : _documentos){
        vetorD_j = _indexador.obterVetorDocumento(documento);
        double num = (vetorD_j*vetorQuery);
        double den = (vetorD_j.norma()*vetorQuery.norma());
        double similaridade = 0;
        if(den != 0) {
            similaridade = num / den;
        }
        vetorSimilaridade.push_back(std::make_pair(similaridade, documento));
    }

    std::sort(vetorSimilaridade.begin(),vetorSimilaridade.end());

    std::vector<Documento> relevanciaQuery;
    
    for(auto rit=vetorSimilaridade.rbegin(); rit!=vetorSimilaridade.rend(); ++rit){
        relevanciaQuery.push_back(rit -> second);
    }

    return relevanciaQuery;
}