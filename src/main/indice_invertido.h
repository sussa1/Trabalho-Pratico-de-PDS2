#ifndef TRABALHO_PRATICO_PDS_2_SRC_INDICE_INVERTIDO_H
#define TRABALHO_PRATICO_PDS_2_SRC_INDICE_INVERTIDO_H

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include "documento.h"

class IndiceInvertido {
    public:
        //Constroi o indice invertido com base nos documentos e suas palavras
        IndiceInvertido(std::vector<Documento> documentos);

        //Retorna os documentos em que 'palavra' aparece
        std::vector<Documento> obterDocumentosPalavra(std::string palavra) const;

        //Retorna a lista de todas as palavras diferentes indexadas
        std::set<std::string> obterTodasPalavras() const;

        //Retorna o numero de documentos diferentes registrados no indice
        int obterNumeroDocumentosRegistrados() const;

    private:
        std::map<std::string, std::set<Documento> > _relacaoPalavraDocumento;
        int _numDocumentos;
        friend class Teste;
};

#endif //TRABALHO_PRATICO_PDS_2_SRC_INDICE_INVERTIDO_H