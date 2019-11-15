#ifndef TRABALHO_PRATICO_PDS_2_SRC_INDEXADOR_H
#define TRABALHO_PRATICO_PDS_2_SRC_INDEXADOR_H

#include <iostream>
#include <vector>
#include <map>
#include "vetor.h"
#include "indice_invertido.h"

class Indexador {
    public:
        //Constrói o índice com base no indice invertido
        Indexador(IndiceInvertido& indiceInvertido);

        //Obtem o vetor 'palavra' no documento 'documento'
        Vetor obterVetorDocumento(Documento documento) const;

        //Cria o vetor da query, adicionando suas palavras aos vetores do documento
        Vetor construirVetorQuery(std::string query);
    private:
        std::map<int, Vetor> _vetoresDocumentos;
        std::map<std::string, int> _coordPalavra;
        IndiceInvertido& _indiceInvertido;
        int _numeroDocumentos;
        int _numeroTotalPalavras;
};

#endif //TRABALHO_PRATICO_PDS_2_SRC_INDEXADOR_H