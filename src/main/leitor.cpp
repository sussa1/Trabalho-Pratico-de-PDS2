#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include "filesystem.hpp"
#include "leitor.h"
#include "documento.h"
#include "util.h"

using namespace ghc;

Leitor::Leitor(std::string dir) {
    _id = 0;
    _documento.clear();
    for(const auto& entrada : filesystem::directory_iterator(dir)) {
        if(filesystem::is_directory(entrada.status())) {
            _documento.push_back(lerDocumento(entrada.path(), entrada.path().filename()));
        }
    }
}

IndiceInvertido& Leitor::obterIndiceInvertido() const {
    IndiceInvertido indiceInvertido = IndiceInvertido(_documento);
    return indiceInvertido;
}

Documento Leitor::lerDocumento(std::string caminho, std::string nomeArquivo) {
    std::ifstream arqDocumento(caminho);
    std::stringstream stream;
    //Converte arquivo para string
    stream << arqDocumento.rdbuf();
    std::string conteudoArquivo = stream.str();
    conteudoArquivo = Util::RemoverCaracteresEspeciaisString(conteudoArquivo);
    conteudoArquivo = Util::TransformarEmMinusculo(conteudoArquivo);
    Documento documento(_id, nomeArquivo, Util::SepararStringPorPalavra(conteudoArquivo));
    _id++;
    return documento;
}
