#ifndef TRABALHO_PRATICO_PDS_2_SRC_LEITOR_H
#define TRABALHO_PRATICO_PDS_2_SRC_LEITOR_H

#include <iostream>
#include <vector>
#include <map>
#include "indice_invertido.h"

class Leitor {
    public:
        //Lê os arquivos do diretório indicado por 'dir'
        Leitor(std::string dir);

        // Retorna o indice invertido das palavras lidas dos documentos
        IndiceInvertido obterFrequenciaPalavras() const;


    private:
};

#endif //TRABALHO_PRATICO_PDS_2_SRC_LEITOR_H