#include "doctest.h"
#include "util.h"
#include <iostream>
#include <vector>

TEST_SUITE("Util") {  
  TEST_CASE("RemoverCaracteresEspeciaisString") {
    SUBCASE("Removendo caracteres de string com caracteres especiais") {
        std::string s = "Uma, string. Para; Testes? Unidade!";
        std::string resposta = Util::RemoverCaracteresEspeciaisString(s);
        CHECK(resposta == "Uma string Para Testes Unidade");
    }
    SUBCASE("Removendo caracteres de uma string vazia") {
        std::string s = "";
        std::string resposta = Util::RemoverCaracteresEspeciaisString(s);
        CHECK(resposta == "");
    }
    SUBCASE("Removendo caracteres de string com caracteres permitidos") {
        std::string s = "Essa string contem apenas caracteres PermItidos";
        std::string resposta = Util::RemoverCaracteresEspeciaisString(s);
        CHECK(resposta == s);
    }
    SUBCASE("Removendo caracteres de string com apenas espaços") {
        std::string s = "    ";
        std::string resposta = Util::RemoverCaracteresEspeciaisString(s);
        CHECK(resposta == s);
    }
  }

  TEST_CASE("TransformarEmMinusculo") {
    SUBCASE("Transformando string mista em minusculo") {
        std::string s = "Uma strING ParA Testes Unidade";
        std::string resposta = Util::TransformarEmMinusculo(s);
        CHECK(resposta == "uma string para testes unidade");
    }
    SUBCASE("Transformando string totalmente maiscula") {
        std::string s = "UMA STRING MAIUSCULA";
        std::string resposta = Util::TransformarEmMinusculo(s);
        CHECK(resposta == "uma string maiuscula");
    }
    SUBCASE("Transformando string totalmente minuscula") {
        std::string s = "essa string contem apenas caracteres minusculos";
        std::string resposta = Util::TransformarEmMinusculo(s);
        CHECK(resposta == s);
    }
    SUBCASE("Transformando string com caracteres especiais") {
        std::string s = "String Mista, Com Caracteres. Especiais?";
        std::string resposta = Util::TransformarEmMinusculo(s);
        CHECK(resposta == "string mista, com caracteres. especiais?");
    }
  }

  TEST_CASE("SepararStringPorPalavra") {
    SUBCASE("Separar string com multiplas palavras") {
        std::string s = "Uma string para testes de unidade";
        std::vector<std::string> resposta = Util::SepararStringPorPalavra(s);
        REQUIRE(resposta.size() == 6);
        CHECK(resposta[0] == "Uma");
        CHECK(resposta[1] == "string");
        CHECK(resposta[2] == "para");
        CHECK(resposta[3] == "testes");
        CHECK(resposta[4] == "de");
        CHECK(resposta[5] == "unidade");
    }
    SUBCASE("Separar string com espacos multiplos") {
        std::string s = "string    separada por    muitos    espacos";
        std::vector<std::string> resposta = Util::SepararStringPorPalavra(s);
        REQUIRE(resposta.size() == 5);
        CHECK(resposta[0] == "string");
        CHECK(resposta[1] == "separada");
        CHECK(resposta[2] == "por");
        CHECK(resposta[3] == "muitos");
        CHECK(resposta[4] == "espacos");
    }
    SUBCASE("Separar string de uma palavra") {
        std::string s = "palavra";
        std::vector<std::string> resposta = Util::SepararStringPorPalavra(s);
        REQUIRE(resposta.size() == 1);
        CHECK(resposta[0] == "palavra");
    }
    SUBCASE("Separar string com apenas espacos") {
        std::string s = "    ";
        std::vector<std::string> resposta = Util::SepararStringPorPalavra(s);
        CHECK(resposta.size() == 0);
    }
  }
}