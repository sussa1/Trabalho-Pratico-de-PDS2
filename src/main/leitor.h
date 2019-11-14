#ifndef TRABALHO_PRATICO_PDS_2_SRC_LEITOR_H
#define TRABALHO_PRATICO_PDS_2_SRC_LEITOR_H

#include <iostream>
#include <vector>
#include <map>

class Leitor {
    public:
        //Lê os arquivos do diretório indicado por 'dir'
        Leitor(std::string dir);

        // Retorna o frequencia das palavras nos arquivos lidos
        std::vector<std::map<std::string, int> > obterFrequenciaPalavras() const;
    private:
};

#endif //TRABALHO_PRATICO_PDS_2_SRC_LEITOR_H