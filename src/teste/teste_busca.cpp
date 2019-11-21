#include "doctest.h"
#include "indexador.h"
#include "indice_invertido.h"
#include "documento.h"
#include "busca.h"
#include <vector>
#include <map>
#include <string>
#include <set>

class Teste {
    public:
        static Indexador Indexador_(const Busca& b) {
            return b._indexador;
        }

        static IndiceInvertido Indice_Invertido(const Busca& b) {
            return b._indiceInvertido;
        }

        static std::vector<Documento>& Documentos(const Busca& b) {
            return b._documentos;
        }

        static std::map<std::string,std::set<Documento>> RelacaoPalavraDocumento(const IndiceInvertido& i) {
            return i._relacaoPalavraDocumento;
        }

        static std::map<int, Vetor> VetoresDocumentos(const Indexador& i) {
            return i._vetoresDocumentos;
        }

        static std::map<std::string, int> CoordPalavra(const Indexador& i) {
            return i._coordPalavra;
        }

        static IndiceInvertido IndiceInvertido_(const Indexador& i) {
            return i._indiceInvertido;
        }

        static int NumeroDocumentos(const Indexador& i) {
            return i._numeroDocumentos;
        }

        static int NumeroTotalPalavras(const Indexador& i) {
            return i._numeroTotalPalavras;
        }
};

bool operator==(const Documento& x, const Documento& y) {
    if(x.obterIdDocumento() != y.obterIdDocumento()){
        return false;
    }
    return true;
}

bool operator==(const Busca& x, const Busca& y) {
    return (Teste::Documentos(x) == Teste::Documentos(y));
}

bool operator==(const IndiceInvertido& x, const IndiceInvertido& y) {
    if(x.obterNumeroDocumentosRegistrados() != y.obterNumeroDocumentosRegistrados()){
        return false;
    }
    if(Teste::RelacaoPalavraDocumento(x) != Teste::RelacaoPalavraDocumento(y)){
        return false;
    }
    return true;
}

bool operator==(const Busca& x, const Busca& y) {
    return (Teste::Indice_Invertido(x) == Teste::Indice_Invertido(y));
}

bool operator==(const Indexador& x,const Indexador& y) {
    if(Teste::VetoresDocumentos(x) != Teste::VetoresDocumentos(y)){
        return false;
    }
    if(Teste::CoordPalavra(x) != Teste::CoordPalavra(y)){
        return false;
    }
    if(!(Teste::IndiceInvertido_(x) == Teste::IndiceInvertido_(y))){
        return false;
    }
    if(Teste::NumeroDocumentos(x) != Teste::NumeroDocumentos(y)){
        return false;
    }
    if(Teste::NumeroTotalPalavras(x) != Teste::NumeroTotalPalavras(y)){
        return false;
    }
    return true;
}

bool operator==(const Busca& x, const Busca& y) {
    return Teste::Indexador_(x) == Teste::Indexador_(y);
}

double converterParaDuasCasasDecimais(double n) {
    long long i = n*100;
    return (double)i/100;
}

TEST_SUITE("Busca"){
    TEST_CASE("Busca()"){
        std::vector<Documento> documentos;
        IndiceInvertido indiceInvertido = IndiceInvertido(documentos);
        Indexador indexador = Indexador(indiceInvertido);
        Busca b(indiceInvertido, indexador, documentos);

        CHECK(documentos == Teste::Documentos(b));
        CHECK(indiceInvertido == Teste::Indice_Invertido(b));
        CHECK(indexador == Teste::Indexador_(b));
    }

    TEST_CASE("obterRelevanciaQuery()"){

        std::vector<Documento> documentos;
        IndiceInvertido indiceInvertido = IndiceInvertido(documentos);
        Indexador indexador = Indexador(indiceInvertido);
        CHECK(Teste::VetoresDocumentos(indexador).size() == 0);
        CHECK(Teste::NumeroDocumentos(indexador) == 0);
        CHECK(Teste::NumeroTotalPalavras(indexador) == 0);
        CHECK(Teste::CoordPalavra(indexador).size() == 0);

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

        Busca b(indiceInvertido, indexador, documentos);
        std::string query = "A B";
        CHECK(b.obterRelevanciaQuery(query)[0].obterNomeDocumento() == "D4");
        CHECK(b.obterRelevanciaQuery(query)[1].obterNomeDocumento() == "D1");
        CHECK(b.obterRelevanciaQuery(query)[2].obterNomeDocumento() == "D2");
        CHECK(b.obterRelevanciaQuery(query)[3].obterNomeDocumento() == "D3");
    }

}