#include "doctest.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
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

bool ordem(Documento d1, Documento d2) {
    return d1.obterNomeDocumento() < d2.obterNomeDocumento();
}

TEST_SUITE("Leitor") {
    TEST_CASE("Leitor(std::string dir)") {
        Leitor leitor("src/teste/dados_teste");
        CHECK(Teste::proximoId(leitor) == 3);
        std::vector<Documento> documentos = Teste::documentos(leitor);
        
        //Ordena os documentos por ordem alfabetica dos nomes
        std::sort(documentos.begin(), documentos.end(), ordem);
        
        CHECK(documentos[0].obterPalavras().size() == 4);
        CHECK(documentos[0].obterNomeDocumento() == "d1.txt");
        CHECK(documentos[0].obterPalavras()[0] == "trabalho");
        CHECK(documentos[0].obterPalavras()[1] == "pratico");
        CHECK(documentos[0].obterPalavras()[2] == "de");
        CHECK(documentos[0].obterPalavras()[3] == "pds");

        CHECK(documentos[1].obterPalavras().size() == 5);
        CHECK(documentos[1].obterNomeDocumento() == "d2.txt");
        CHECK(documentos[1].obterPalavras()[0] == "trabalho");
        CHECK(documentos[1].obterPalavras()[1] == "pratico");
        CHECK(documentos[1].obterPalavras()[2] == "e");
        CHECK(documentos[1].obterPalavras()[3] == "bom");
        CHECK(documentos[1].obterPalavras()[4] == "demais");

        CHECK(documentos[2].obterPalavras().size() == 7);        
        CHECK(documentos[2].obterNomeDocumento() == "d3.txt");
        CHECK(documentos[2].obterPalavras()[0] == "disciplina");
        CHECK(documentos[2].obterPalavras()[1] == "de");
        CHECK(documentos[2].obterPalavras()[2] == "programacao");
        CHECK(documentos[2].obterPalavras()[3] == "e");
        CHECK(documentos[2].obterPalavras()[4] == "desenvolvimento");
        CHECK(documentos[2].obterPalavras()[5] == "de");
        CHECK(documentos[2].obterPalavras()[6] == "software");
    }

    TEST_CASE("obterIndiceInvertido()") {
        Leitor leitor("src/teste/dados_teste");
        IndiceInvertido indice = leitor.obterIndiceInvertido();
        CHECK(indice.obterNumeroDocumentosRegistrados() == 3);
    }

    TEST_CASE("obterDocumentosLidos()") {
        Leitor leitor("src/teste/dados_teste");
        std::vector<Documento> documentos = leitor.obterDocumentosLidos();
        REQUIRE(documentos.size() == 3);
        CHECK(documentos[0].obterIdDocumento() == 0);
        CHECK(documentos[1].obterIdDocumento() == 1);
        CHECK(documentos[2].obterIdDocumento() == 2);
    }

    TEST_CASE("lerDocumento(std::string caminho, std::string nomeArquivo)") {
        Leitor leitor("src/teste/dados_teste");
        Documento documento = Teste::lerDocumento(leitor, "src/teste/dados_teste/d1.txt", "d4");

        CHECK(Teste::proximoId(leitor) == 4);

        CHECK(documento.obterNomeDocumento() == "d4");
        CHECK(documento.obterPalavras()[0] == "trabalho");
        CHECK(documento.obterPalavras()[1] == "pratico");
        CHECK(documento.obterPalavras()[2] == "de");
        CHECK(documento.obterPalavras()[3] == "pds");
    }
}