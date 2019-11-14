#ifndef TRABALHO_PRATICO_PDS_2_SRC_BUSCA_H
#define TRABALHO_PRATICO_PDS_2_SRC_BUSCA_H

#include <iostream>
#include <vector>
#include "indice.h"

class Busca {
    public:
        //Constrói a estrutura de busca com base na relação documento -> {palavra -> frequencia}
        Busca(std::map<std::string, std::map<std::string, int> > documentos);

        //Retorna os documentos ordenados por relevancia para a busca 'query'
        /*
            A formula no final é 
            (VetorD_j . VetorQuery)/(||VetorD_j||*||VetorQuery||)
            Ou seja o produto interno entre cada vetor de documento e o vetor da query dividido pela norma dos dois vetores multiplicadas

            Depois de calcular todas relevancias basta ordenar elas e retornar a lista por ordem decrescente de nomes de documentos
        */
        std::vector<std::string> obterRelevanciaQuery(std::string query);

    private:
        Indice _indice;
};

#endif //TRABALHO_PRATICO_PDS_2_SRC_BUSCA_H