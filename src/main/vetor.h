#ifndef TRABALHO_PRATICO_PDS_2_SRC_VETOR_H
#define TRABALHO_PRATICO_PDS_2_SRC_VETOR_H

#include <vector>

class Vetor {
    public:
        //Constrói o vetor com a dimensão dada e coordenadas 0
        Vetor(int dimensao);

        //Retorna uma referencia ao número de uma coordenada específica
        double& operator[](int coord);

        //Retorna o produto interno dos dois vetores
        Vetor operator*(const Vetor& v2);

        //Retorna a norma do vetor
        double norma() const;
    private:
        std::vector<double> _valoresVetor;
        friend class Teste;
};

#endif //TRABALHO_PRATICO_PDS_2_SRC_VETOR_H