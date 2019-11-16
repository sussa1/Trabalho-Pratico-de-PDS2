#include "doctest.h"
#include "documento.h"
#include <vector>

class Teste {
    public:
        static int IdDocumento(Documento& d) {
            return d._id;
        }

        static std::string Nome(Documento& d) {
            return d._nome;
        }

        static std::vector<std::string> Palavras(Documento& d) {
            return d._palavras;
        }
};

TEST_SUITE("Documento") {
    TEST_CASE("Documento()") {
        std::vector<std::string> palavras;
        palavras.push_back("String");
        palavras.push_back("para");
        palavras.push_back("Teste");
        Documento d(1, "Documento Teste", palavras);
        CHECK(Teste::IdDocumento(d) == 1);
        CHECK(Teste::Nome(d) == "Documento Teste");
        CHECK(Teste::Palavras(d) == palavras);
    }

    TEST_CASE("obterFrequenciaPalavra") {
        SUBCASE("Frequencia em lista vazia") {
            std::vector<std::string> palavras;
            Documento d(1, "Documento Teste", palavras);
            CHECK(d.obterFrequenciaPalavra("Teste") == 0);
        }
        
        SUBCASE("Frequencia em lista sem a palavrasavra") {
            std::vector<std::string> palavras;
            palavras.push_back("String");
            palavras.push_back("para");
            palavras.push_back("Teste");
            Documento d(1, "Documento Teste", palavras);
            CHECK(d.obterFrequenciaPalavra("Lista") == 0);
        }

        SUBCASE("Frequencia em lista com uma ocorrencia") {
            std::vector<std::string> palavras;
            palavras.push_back("String");
            palavras.push_back("para");
            palavras.push_back("Teste");
            Documento d(1, "Documento Teste", palavras);
            CHECK(d.obterFrequenciaPalavra("Teste") == 1);
        }

        SUBCASE("Frequencia em string com multiplas ocorrencias") {
            std::vector<std::string> palavras;
            palavras.push_back("String");
            palavras.push_back("Teste");
            palavras.push_back("para");
            palavras.push_back("Teste");
            palavras.push_back("Teste");
            Documento d(1, "Documento Teste", palavras);
            CHECK(d.obterFrequenciaPalavra("Teste") == 3);
        }
    }

    TEST_CASE("obterIdDocumento") {
        Documento d(1, "Documento Teste", std::vector<std::string>());
        CHECK(d.obterIdDocumento() == 1);
    }

    TEST_CASE("obterNomeDocumento") {
        Documento d(1, "Documento Teste", std::vector<std::string>());
        CHECK(d.obterNomeDocumento() == "Documento Teste");
    }

    TEST_CASE("obterPalavras") {
        std::vector<std::string> palavras;
        palavras.push_back("String");
        palavras.push_back("para");
        palavras.push_back("Teste");
        Documento d(1, "Documento Teste", palavras);
        CHECK(d.obterPalavras() == palavras);
    }

    TEST_CASE("operator <") {
        SUBCASE("Primeira menor") {
            std::vector<std::string> palavras1;
            palavras1.push_back("String");
            palavras1.push_back("para");
            palavras1.push_back("Teste");
            Documento d1(1, "Documento Teste 1", palavras1);
            std::vector<std::string> palavras2;
            palavras2.push_back("String");
            palavras2.push_back("Diferente");
            palavras2.push_back("para");
            palavras2.push_back("Teste");
            Documento d2(2, "Documento Teste 2", palavras2);
            CHECK((d1 < d2));
        }

        SUBCASE("Segunda menor") {
            std::vector<std::string> palavras1;
            palavras1.push_back("String");
            palavras1.push_back("para");
            palavras1.push_back("Teste");
            Documento d1(2, "Documento Teste 1", palavras1);
            std::vector<std::string> palavras2;
            palavras2.push_back("String");
            palavras2.push_back("Diferente");
            palavras2.push_back("para");
            palavras2.push_back("Teste");
            Documento d2(1, "Documento Teste 2", palavras2);
            CHECK(!(d1 < d2));
        }
    }
}