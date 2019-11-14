#ifndef TRABALHO_PRATICO_PDS_2_SRC_UTIL_H
#define TRABALHO_PRATICO_PDS_2_SRC_UTIL_H

#include <iostream>
#include <vector>

class Util {
    public:
        //Trata a string, removendo os caracteres especiais
        static std::string RemoverCaracteresEspeciaisString(std::string s);

        //Trata a string, a transformando apenas em caracteres minusculos
        static std::string TransformarEmMinusculo(std::string s);

        //Quebra a string s pelos ' ', separando cada palavra em uma string diferente
        static std::vector<std::string> SepararStringPorPalavra(std::string s);
};

#endif //TRABALHO_PRATICO_PDS_2_SRC_UTIL_H