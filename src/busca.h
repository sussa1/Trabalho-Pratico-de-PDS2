#ifndef TRABALHO_PRATICO_PDS_2_SRC_BUSCA_H
#define TRABALHO_PRATICO_PDS_2_SRC_BUSCA_H

#include <iostream>
#include <vector>
#include "indice.h"

class Busca {
    public:
        //Constrói a estrutura de busca para os arquivos do diretório 'dir'
        Busca(std::string dir);

        //Retorna as palavras mais relevantes para a busca 'query'
        std::vector<std::string> obterRelevanciaPalavras(std::string query);

    private:
        Indice _indice;
};

#endif //TRABALHO_PRATICO_PDS_2_SRC_BUSCA_H