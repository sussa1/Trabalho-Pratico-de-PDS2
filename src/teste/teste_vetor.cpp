#include "doctest.h"
#include "vetor.h"
#include <vector>


class Teste {
    public:
        static std::vector<double>& valoresVetor(Vetor& v) {
            return v._valoresVetor;
        }
};

TEST_SUITE("Vetor") {
    TEST_CASE("Vetor(int dimensao)") {
        SUBCASE("Vetor com dimensao zero") {
            Vetor v(0);
            CHECK(Teste::valoresVetor(v).capacity() == 0);
        }
        SUBCASE("Vetor com dimensao diferente de zero") {
            Vetor v(30);
            CHECK(Teste::valoresVetor(v).capacity() == 30);
        }
    }

    TEST_CASE("double& operator[](int coord)") {
        Vetor v(3);
        Teste::valoresVetor(v)[0] = 1;
        Teste::valoresVetor(v)[1] = 3;
        Teste::valoresVetor(v)[2] = 0;
        CHECK(v[0] == 1);
        v[0] = 2;
        CHECK(v[0] == 2);
        CHECK(v[1] == 3);
        v[1] = 6;
        CHECK(v[1] == 6);
        CHECK(v[2] == 0);
        v[2] = 1850;
        CHECK(v[2] == 1850);
    }

    TEST_CASE("double operator*(const Vetor& v2)") {

        SUBCASE("vetores de dimensão 1") {
            Vetor v1(1);
            Teste::valoresVetor(v1)[0] = 1;
            Vetor v2(1);
            Teste::valoresVetor(v2)[0] = 1;
            double vr = v1 * v2;
            CHECK(vr == 1);
        }

        SUBCASE("vetores com dimensao 3") {
            Vetor v1(3);
            Teste::valoresVetor(v1)[0] = 2;
            Teste::valoresVetor(v1)[1] = 6;
            Teste::valoresVetor(v1)[2] = 7;
            Vetor v2(3);
            Teste::valoresVetor(v2)[0] = 3;
            Teste::valoresVetor(v2)[1] = 8;
            Teste::valoresVetor(v2)[2] = 9;
            double vr = v1 * v2;
            CHECK(vr == 117);
        }

        SUBCASE("vetores com um valor zero") {
            Vetor v1(2);
            Teste::valoresVetor(v1)[0] = 8;
            Teste::valoresVetor(v1)[1] = 0;
            Vetor v2(2);
            Teste::valoresVetor(v2)[0] = 0;
            Teste::valoresVetor(v2)[1] = 1;
            double vr = v1 * v2;
            CHECK(vr == 0);
        }

        SUBCASE("vetores com todos os valores iguais a zero") {
            Vetor v1(2);
            Teste::valoresVetor(v1)[0] = 0;
            Teste::valoresVetor(v1)[1] = 0;
            Vetor v2(2);
            Teste::valoresVetor(v2)[0] = 0;
            Teste::valoresVetor(v2)[1] = 0;
            double vr = v1 * v2;
            CHECK(vr == 0);
        }
    }

    TEST_CASE("double norma()") {
        SUBCASE("vetores com dimensao 3 com valores iguais a zero") {
            Vetor v1(3);
            Teste::valoresVetor(v1)[0] = 0;
            Teste::valoresVetor(v1)[1] = 0;
            Teste::valoresVetor(v1)[2] = 0;
            CHECK(v1.norma() == 0);
        }

        SUBCASE("vetor com dimensao zero") {
            Vetor v1(0);
            CHECK(v1.norma() == 0);
        }

        SUBCASE("vetor com dimensao 3 e valores diferentes de zero") {
            Vetor v1(3);
            Teste::valoresVetor(v1)[0] = 1;
            Teste::valoresVetor(v1)[1] = 2;
            Teste::valoresVetor(v1)[2] = 2;
            CHECK(v1.norma() == 3);
        }
    }
}








            




