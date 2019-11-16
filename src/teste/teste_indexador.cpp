#include "doctest.h"
#include "indexador.h"
#include "documento.h"
#include "vetor.h"
#include <vector>

class Teste {
    public:
        static std::map<int, Vetor> VetoresDocumentos(Indexador& i) {
            return i._vetoresDocumentos;
        }

        static std::map<std::string, int> CoordPalavra(Indexador& i) {
            return i._coordPalavra;
        }

        static IndiceInvertido AtributoIndiceInvertido(Indexador& i) {
            return i._indiceInvertido;
        }

        static int NumeroDocumentos(Indexador& i) {
            return i._numeroDocumentos;
        }

        static int NumeroTotalPalavras(Indexador& i) {
            return i._numeroTotalPalavras;
        }
        
        static std::vector<double> DadosVetor(const Vetor& v) {
            return v._valoresVetor;
        }
};

bool operator==(const Vetor& x, const Vetor& y) {
  return Teste::DadosVetor(x) == Teste::DadosVetor(y);
}

double converterParaDuasCasasDecimais(double n) {
    long long i = n*100;
    return (double)i/100;
}

//Teste de classe dependente das classes 'IndiceInvertido', 'Documento' e 'Vetor'
TEST_SUITE("Indexador") {
    TEST_CASE("Indexador()") {
        SUBCASE("Indice vazio") {
            std::vector<Documento> documentos;
            IndiceInvertido indiceInvertido = IndiceInvertido(documentos);
            Indexador indexador = Indexador(indiceInvertido);
            CHECK(Teste::VetoresDocumentos(indexador).size() == 0);
            CHECK(Teste::NumeroDocumentos(indexador) == 0);
            CHECK(Teste::NumeroTotalPalavras(indexador) == 0);
            CHECK(Teste::CoordPalavra(indexador).size() == 0);
        }

        SUBCASE("Indice preenchido") {
            std::vector<Documento> documentos;
            Documento d1(1, "D1", std::vector<std::string>{"a", "a", "a", "b"});
            Documento d2(2, "D2", std::vector<std::string>{"a", "a", "c"});
            Documento d3(3, "D3", std::vector<std::string>{"a", "a"});
            Documento d4(4, "D4", std::vector<std::string>{"b", "b"});
            documentos.push_back(d1);
            documentos.push_back(d2);
            documentos.push_back(d3);
            documentos.push_back(d4);
            IndiceInvertido indiceInvertido = IndiceInvertido(documentos);
            Indexador indexador = Indexador(indiceInvertido);
            Vetor vetorD1 = Teste::VetoresDocumentos(indexador).at(1);
            double A1 = vetorD1[Teste::CoordPalavra(indexador)["a"]];
            double B1 = vetorD1[Teste::CoordPalavra(indexador)["b"]];
            double C1 = vetorD1[Teste::CoordPalavra(indexador)["c"]];
            CHECK(converterParaDuasCasasDecimais(A1) == 0.86);
            CHECK(converterParaDuasCasasDecimais(B1) == 0.69);
            CHECK(converterParaDuasCasasDecimais(C1) == 0);

            Vetor vetorD2 = Teste::VetoresDocumentos(indexador).at(2);
            double A2 = vetorD2[Teste::CoordPalavra(indexador)["a"]];
            double B2 = vetorD2[Teste::CoordPalavra(indexador)["b"]];
            double C2 = vetorD2[Teste::CoordPalavra(indexador)["c"]];
            CHECK(converterParaDuasCasasDecimais(A2) == 0.57);
            CHECK(converterParaDuasCasasDecimais(B2) == 0);
            CHECK(converterParaDuasCasasDecimais(C2) == 1.38);

            Vetor vetorD3 = Teste::VetoresDocumentos(indexador).at(3);
            double A3 = vetorD3[Teste::CoordPalavra(indexador)["a"]];
            double B3 = vetorD3[Teste::CoordPalavra(indexador)["b"]];
            double C3 = vetorD3[Teste::CoordPalavra(indexador)["c"]];
            CHECK(converterParaDuasCasasDecimais(A3) == 0.57);
            CHECK(converterParaDuasCasasDecimais(B3) == 0);
            CHECK(converterParaDuasCasasDecimais(C3) == 0);

            Vetor vetorD4 = Teste::VetoresDocumentos(indexador).at(4);
            double A4 = vetorD4[Teste::CoordPalavra(indexador)["a"]];
            double B4 = vetorD4[Teste::CoordPalavra(indexador)["b"]];
            double C4 = vetorD4[Teste::CoordPalavra(indexador)["c"]];
            CHECK(converterParaDuasCasasDecimais(A4) == 0);
            CHECK(converterParaDuasCasasDecimais(B4) == 1.38);
            CHECK(converterParaDuasCasasDecimais(C4) == 0);
        }
    }

    TEST_CASE("obterVetorDocumento") {
        std::vector<Documento> documentos;
        Documento d1(1, "D1", std::vector<std::string>{"a", "a", "a", "b"});
        Documento d2(2, "D2", std::vector<std::string>{"a", "a", "c"});
        Documento d3(3, "D3", std::vector<std::string>{"a", "a"});
        Documento d4(4, "D4", std::vector<std::string>{"b", "b"});
        documentos.push_back(d1);
        documentos.push_back(d2);
        documentos.push_back(d3);
        documentos.push_back(d4);
        IndiceInvertido indiceInvertido = IndiceInvertido(documentos);
        Indexador indexador = Indexador(indiceInvertido);
        Vetor vetorD1 = indexador.obterVetorDocumento(d1);
        Vetor vetorD2 = indexador.obterVetorDocumento(d2);
        Vetor vetorD3 = indexador.obterVetorDocumento(d3);
        Vetor vetorD4 = indexador.obterVetorDocumento(d4);
        CHECK(vetorD1 == Teste::VetoresDocumentos(indexador).at(1));
        CHECK(vetorD2 == Teste::VetoresDocumentos(indexador).at(2));
        CHECK(vetorD3 == Teste::VetoresDocumentos(indexador).at(3));
        CHECK(vetorD4 == Teste::VetoresDocumentos(indexador).at(4));
    }

    TEST_CASE("construirVetorQuery") {
        SUBCASE("Query sem palavras indexadas") {
            std::vector<Documento> documentos;
            Documento d1(1, "D1", std::vector<std::string>{"a", "a", "a", "b"});
            Documento d2(2, "D2", std::vector<std::string>{"a", "a", "c"});
            Documento d3(3, "D3", std::vector<std::string>{"a", "a"});
            Documento d4(4, "D4", std::vector<std::string>{"b", "b"});
            documentos.push_back(d1);
            documentos.push_back(d2);
            documentos.push_back(d3);
            documentos.push_back(d4);
            IndiceInvertido indiceInvertido = IndiceInvertido(documentos);
            Indexador indexador = Indexador(indiceInvertido);
            Vetor vetorQuery = indexador.construirVetorQuery("D E");
            REQUIRE(Teste::DadosVetor(vetorQuery).size() == 3);
            CHECK(vetorQuery[0] == 0);
            CHECK(vetorQuery[1] == 0);
            CHECK(vetorQuery[2] == 0);
        }

        SUBCASE("Query com palavras indexadas") {
            std::vector<Documento> documentos;
            Documento d1(1, "D1", std::vector<std::string>{"a", "a", "a", "b"});
            Documento d2(2, "D2", std::vector<std::string>{"a", "a", "c"});
            Documento d3(3, "D3", std::vector<std::string>{"a", "a"});
            Documento d4(4, "D4", std::vector<std::string>{"b", "b"});
            documentos.push_back(d1);
            documentos.push_back(d2);
            documentos.push_back(d3);
            documentos.push_back(d4);
            IndiceInvertido indiceInvertido = IndiceInvertido(documentos);
            Indexador indexador = Indexador(indiceInvertido);
            Vetor vetorQuery = indexador.construirVetorQuery("A B");
            REQUIRE(Teste::DadosVetor(vetorQuery).size() == 3);
            CHECK(converterParaDuasCasasDecimais(vetorQuery[0]) == 0.28);
            CHECK(converterParaDuasCasasDecimais(vetorQuery[1]) == 0.69);
            CHECK(converterParaDuasCasasDecimais(vetorQuery[2]) == 0);
        }
    }
}