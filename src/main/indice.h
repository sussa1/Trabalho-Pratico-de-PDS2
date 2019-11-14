#ifndef TRABALHO_PRATICO_PDS_2_SRC_INDICE_H
#define TRABALHO_PRATICO_PDS_2_SRC_INDICE_H

#include <iostream>
#include <vector>
#include <map>
#include "vetor.h"

class Indice {
    public:
        //Constrói o índice com base nos arquivos do diretório indicado por 'dir'
        Indice(std::map<std::string, std::map<std::string, int> > documentos);

        //Obtem a importância de 'palavra' no documento 'documento'
        Vetor obterVetorDocumento(std::string documento) const;

        //Cria o vetor da query, adicionando suas palavras aos vetores do documento
        Vetor construirVetorQuery(std::string query);
    private:
        std::map<std::string, Vetor> _vetores;
        std::map<std::string, int> _coordPalavra;
        std::map<std::string, int> _numDocsPalavra;
        int _numeroDocumentos;
        int _numeroTotalPalavras;
};

#endif //TRABALHO_PRATICO_PDS_2_SRC_INDICE_H