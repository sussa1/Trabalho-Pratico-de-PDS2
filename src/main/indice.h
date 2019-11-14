#ifndef TRABALHO_PRATICO_PDS_2_SRC_INDICE_H
#define TRABALHO_PRATICO_PDS_2_SRC_INDICE_H

#include <iostream>

class Indice {
    public:
        //Constrói o índice com base nos arquivos do diretório indicado por 'dir'
        Indice(std::string dir);

        // Obtem a importância de 'palavra' no documento 'documento'
        double obterImportanciaPalavraDocumento(std::string palavra, std::string documento);
    private:
};

#endif //TRABALHO_PRATICO_PDS_2_SRC_INDICE_H