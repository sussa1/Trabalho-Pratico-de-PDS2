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
    Vetor VetorQuery = _indexador.construirVetorQuery(query);
    Vetor VetorD_j(_indiceInvertido.obterTodasPalavras().size());
    std::vector<std::tuple<double,Documento>> VetorSimilaridade;

    for(Documento documento : _documentos){
        VetorD_j = _indexador.obterVetorDocumento(documento);
        double similaridade = (VetorD_j*VetorQuery) / (VetorD_j.norma()*VetorQuery.norma());
        VetorSimilaridade.push_back(std::make_tuple(similaridade, documento));
    }

    std::sort(VetorSimilaridade.begin(),VetorSimilaridade.end());

    std::vector<Documento> RelevanciaQuery(_documentos.size());

    int i = 0;
    for(auto rit=VetorSimilaridade.rbegin(); rit!=VetorSimilaridade.rend(); ++rit){
        RelevanciaQuery[i] = std::get<1>(*rit);
        ++i;
    }

    return RelevanciaQuery;
}