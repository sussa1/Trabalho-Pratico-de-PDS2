#ifndef TRABALHO_PRATICO_PDS_2_SRC_BUSCA_H
#define TRABALHO_PRATICO_PDS_2_SRC_BUSCA_H

#include <iostream>
#include <vector>

class Documento {
    public:
        //Constrói o documento a partir do id, nome e suas palavras
        Documento(int id, std::string nome, std::vector<std::string> palavras);

        //Retorna a frequencia de 'palavra' no documento
        int obterFrequenciaPalavra(std::string palavra) const;

        //Retorna o id do documento
        int obterIdDocumento() const;

        //Retorna o nome do documento
        std::string obterNomeDocumento() const;

        //Retorna as palavras do documento
        std::vector<std::string> obterPalavras() const;

        //Para definir a ordenacao de documentos, ordena os documentos pelo id
        bool operator < (Documento& d) const;

    private:
        int _id;
        std::string _nome;
        std::vector<std::string> _palavras;
};

#endif //TRABALHO_PRATICO_PDS_2_SRC_BUSCA_H