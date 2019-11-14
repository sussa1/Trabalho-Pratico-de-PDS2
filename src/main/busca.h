#ifndef TRABALHO_PRATICO_PDS_2_SRC_BUSCA_H
#define TRABALHO_PRATICO_PDS_2_SRC_BUSCA_H

#include <iostream>
#include <vector>
#include "indice.h"

class Busca {
    public:
        //Constrói a estrutura de busca para os arquivos do diretório 'dir'
        Busca(std::map<std::string, std::map<std::string, int> > documentos);

        //Retorna os documentos mais relevantes para a busca 'query'
        std::vector<std::string> obterRelevanciaQuery(std::string query);

    private:
        Indice _indice;
};

#endif //TRABALHO_PRATICO_PDS_2_SRC_BUSCA_H