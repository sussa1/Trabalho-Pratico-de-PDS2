#include "util.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

std::string Util::RemoverCaracteresEspeciaisString(std::string s) {
    s.erase(std::remove_if(s.begin(), s.end(),
        [](char c) {
            int cod = (int)c;
            return !(c == ' ' || (cod >= 48 && cod <= 57) || (cod >= 97 && cod <= 122) || (cod >= 65 && cod <= 90));
        }), s.end());
    return s;
}

std::string Util::TransformarEmMinusculo(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

std::vector<std::string> Util::SepararStringPorPalavra(std::string s) {
    std::stringstream stream(s);
    std::vector<std::string> palavras;
    //Enquanto existe algo a ser lido
    while(stream) {
        std::string palavra;
        stream >> palavra;
        palavras.push_back(palavra);
    }
    return palavras;
}