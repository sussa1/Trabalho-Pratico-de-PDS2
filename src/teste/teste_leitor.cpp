#include "doctest.h"
#include <iostream>
#include <vector>
#include <map>
#include "indice_invertido.h"
#include "documento.h"
#include "leitor.h"

class Teste {
    public:
        static Documento lerDocumento(Leitor& l, std::string caminho, std::string nomeArquivo) {
            return l.lerDocumento(caminho, nomeArquivo);
        }

        static int proximoId(const Leitor& l) {
            return l._proximoId;
        }

        static std::vector<Documento> documentos(const Leitor& l) {
            return l._documentos;
        }
};

TEST_SUITE("Leitor") {
    TEST_CASE("Leitor(std::string dir)") {
        Leitor leitor("dados_teste");
        CHECK(Teste::proximoId(leitor) == 3);
        std::vector<Documento> documentos = Teste::documentos(leitor);
        
        CHECK(documentos.size() == 4);
        CHECK(documentos[0].obterNomeDocumento() == "d1");
        CHECK(documentos[0].obterPalavras()[0] == "trabalho");
        CHECK(documentos[0].obterPalavras()[1] == "pratico");
        CHECK(documentos[0].obterPalavras()[2] == "de");
        CHECK(documentos[0].obterPalavras()[3] == "pds");

        CHECK(documentos.size() == 5);
        CHECK(documentos[1].obterNomeDocumento() == "d2");
        CHECK(documentos[1].obterPalavras()[0] == "trabalho");
        CHECK(documentos[1].obterPalavras()[1] == "pratico");
        CHECK(documentos[1].obterPalavras()[2] == "e");
        CHECK(documentos[1].obterPalavras()[3] == "bom");
        CHECK(documentos[1].obterPalavras()[4] == "demais");

        CHECK(documentos.size() == 7);        
        CHECK(documentos[2].obterNomeDocumento() == "d3");
        CHECK(documentos[2].obterPalavras()[0] == "disciplina");
        CHECK(documentos[2].obterPalavras()[1] == "de");
        CHECK(documentos[2].obterPalavras()[2] == "programacao");
        CHECK(documentos[2].obterPalavras()[3] == "e");
        CHECK(documentos[2].obterPalavras()[4] == "desenvolvimento");
        CHECK(documentos[2].obterPalavras()[5] == "de");
        CHECK(documentos[2].obterPalavras()[6] == "software");
    }

    TEST_CASE("obterIndiceInvertido()") {
        Leitor leitor("dados_teste");
    }

    TEST_CASE("lerDocumento(std::string caminho, std::string nomeArquivo)") {
        Leitor leitor("dados_teste");
        Teste::lerDocumento(leitor, "dados_teste/d1.txt", "d4");
        std::vector<Documento> documentos = Teste::documentos(leitor);
        CHECK(documentos.size() == 4);
        CHECK(documentos[3].obterNomeDocumento() == "d4");
        CHECK(documentos[3].obterPalavras()[0] == "trabalho");
        CHECK(documentos[3].obterPalavras()[1] == "pratico");
        CHECK(documentos[3].obterPalavras()[2] == "de");
        CHECK(documentos[3].obterPalavras()[3] == "pds");
    }
}