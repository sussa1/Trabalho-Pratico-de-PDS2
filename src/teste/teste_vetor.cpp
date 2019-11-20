#include "doctest.h"
#include "vetor.h"
#include <vector>


class Teste {
    public:
        static std::vector<double> valoresVetor(const Vetor& v) {
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

