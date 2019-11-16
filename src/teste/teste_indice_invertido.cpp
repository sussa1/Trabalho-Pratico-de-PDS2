#include "doctest.h"
#include "indice_invertido.h"
#include "documento.h"
#include <iostream>
#include <vector>
#include <map>

class Teste {
    public:
        static std::map<std::string, std::set<Documento> > RelacaoPalavraDocumento(IndiceInvertido& i) {
            return i._relacaoPalavraDocumento;
        }
        static int NumDocumentos(IndiceInvertido& i) {
            return i._numDocumentos;
        }
};

//Teste de classe dependente da classe 'Documento'
TEST_SUITE("IndiceInvertido") {
    TEST_CASE("IndiceInvertido()") {
        SUBCASE("Indice sem documentos") {
            std::vector<Documento> documentos;
            IndiceInvertido indiceInvertido = IndiceInvertido(documentos);
            CHECK(Teste::NumDocumentos(indiceInvertido) == 0);
            CHECK(Teste::RelacaoPalavraDocumento(indiceInvertido).empty());
        }

        SUBCASE("Indice com documentos") {
            std::vector<Documento> documentos;
            Documento d1 = Documento(1, "Teste 1", std::vector<std::string>{"A", "B", "C"});;
            Documento d2 = Documento(2, "Teste 2", std::vector<std::string>{"A", "C"});
            Documento d3 = Documento(3, "Teste 3", std::vector<std::string>{"B", "C"});
            documentos.push_back(d1);
            documentos.push_back(d2);
            documentos.push_back(d3);
            IndiceInvertido indiceInvertido = IndiceInvertido(documentos);
            CHECK(Teste::NumDocumentos(indiceInvertido) == 3);
            std::map<std::string, std::set<Documento> > relacaoPalavraDocumento = Teste::RelacaoPalavraDocumento(indiceInvertido);
            CHECK(relacaoPalavraDocumento.size() == 3);
            CHECK(relacaoPalavraDocumento["A"].size() == 2);
            CHECK(relacaoPalavraDocumento["A"].count(d1) == 1);
            CHECK(relacaoPalavraDocumento["A"].count(d2) == 1);
            CHECK(relacaoPalavraDocumento["A"].count(d3) == 0);
            CHECK(relacaoPalavraDocumento["B"].size() == 2);
            CHECK(relacaoPalavraDocumento["B"].count(d1) == 1);
            CHECK(relacaoPalavraDocumento["B"].count(d2) == 0);
            CHECK(relacaoPalavraDocumento["B"].count(d3) == 1);
            CHECK(relacaoPalavraDocumento["C"].size() == 3);
            CHECK(relacaoPalavraDocumento["C"].count(d1) == 1);
            CHECK(relacaoPalavraDocumento["C"].count(d2) == 1);
            CHECK(relacaoPalavraDocumento["C"].count(d3) == 1);
        }
    }

    TEST_CASE("obterDocumentosPalavra") {
        std::vector<Documento> documentos;
        Documento d1 = Documento(1, "Teste 1", std::vector<std::string>{"A", "B", "C"});;
        Documento d2 = Documento(2, "Teste 2", std::vector<std::string>{"A", "C"});
        Documento d3 = Documento(3, "Teste 3", std::vector<std::string>{"B", "C"});
        documentos.push_back(d1);
        documentos.push_back(d2);
        documentos.push_back(d3);
        IndiceInvertido indiceInvertido = IndiceInvertido(documentos);
        std::vector<Documento> docA = indiceInvertido.obterDocumentosPalavra("A");
        CHECK(docA.size() == 2);
        CHECK((docA[0].obterIdDocumento() == d1.obterIdDocumento() || docA[0].obterIdDocumento() == d2.obterIdDocumento()));
        CHECK((docA[1].obterIdDocumento() == d1.obterIdDocumento() || docA[1].obterIdDocumento() == d2.obterIdDocumento()));
        std::vector<Documento> docB = indiceInvertido.obterDocumentosPalavra("B");
        CHECK(docB.size() == 2);
        CHECK((docB[0].obterIdDocumento() == d1.obterIdDocumento() || docB[0].obterIdDocumento() == d3.obterIdDocumento()));
        CHECK((docB[1].obterIdDocumento() == d1.obterIdDocumento() || docB[1].obterIdDocumento() == d3.obterIdDocumento()));
        std::vector<Documento> docC = indiceInvertido.obterDocumentosPalavra("C");
        CHECK(docC.size() == 3);
        CHECK((docC[0].obterIdDocumento() == d1.obterIdDocumento() || docC[0].obterIdDocumento() == d2.obterIdDocumento() || docC[0].obterIdDocumento() == d3.obterIdDocumento()));
        CHECK((docC[1].obterIdDocumento() == d1.obterIdDocumento() || docC[1].obterIdDocumento() == d2.obterIdDocumento() || docC[1].obterIdDocumento() == d3.obterIdDocumento()));
        CHECK((docC[2].obterIdDocumento() == d1.obterIdDocumento() || docC[2].obterIdDocumento() == d2.obterIdDocumento() || docC[2].obterIdDocumento() == d3.obterIdDocumento()));
    }

    TEST_CASE("obterTodasPalavras") {
        std::vector<Documento> documentos;
        Documento d1 = Documento(1, "Teste 1", std::vector<std::string>{"A", "B", "C"});;
        Documento d2 = Documento(2, "Teste 2", std::vector<std::string>{"A", "C"});
        Documento d3 = Documento(3, "Teste 3", std::vector<std::string>{"B", "C"});
        documentos.push_back(d1);
        documentos.push_back(d2);
        documentos.push_back(d3);
        IndiceInvertido indiceInvertido = IndiceInvertido(documentos);
        std::set<std::string> todasPalavras = indiceInvertido.obterTodasPalavras();
        CHECK(todasPalavras.size() == 3);
        CHECK(todasPalavras.count("A") == 1);
        CHECK(todasPalavras.count("B") == 1);
        CHECK(todasPalavras.count("C") == 1);
    }

    TEST_CASE("obterNumeroDocumentosRegistrados") {
        SUBCASE("Multiplos documentos registrados") {
            std::vector<Documento> documentos;
            Documento d1 = Documento(1, "Teste 1", std::vector<std::string>{"A", "B", "C"});;
            Documento d2 = Documento(2, "Teste 2", std::vector<std::string>{"A", "C"});
            Documento d3 = Documento(3, "Teste 3", std::vector<std::string>{"B", "C"});
            documentos.push_back(d1);
            documentos.push_back(d2);
            documentos.push_back(d3);
            IndiceInvertido indiceInvertido = IndiceInvertido(documentos);
            int numDocumentos = indiceInvertido.obterNumeroDocumentosRegistrados();
            CHECK(numDocumentos == 3);
        }

        SUBCASE("Nenhum documento registrado") {
            std::vector<Documento> documentos;
            IndiceInvertido indiceInvertido = IndiceInvertido(documentos);
            int numDocumentos = indiceInvertido.obterNumeroDocumentosRegistrados();
            CHECK(numDocumentos == 0);
        }
    }
}