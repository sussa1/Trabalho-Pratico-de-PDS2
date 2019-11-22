#include <iostream>
#include <vector>
#include "documento.h"
#include "busca.h"
#include "indexador.h"
#include "leitor.h"

std::string lerDiretorio() {
    std::cout << "Deseja ler os documentos do diretório default (D) ou de um diretorio personalizado (P)?" << std::endl;
    char resp;
    std::cin >> resp;
    if(resp == 'D' || resp == 'd') {
        return "dados";
    } else {
        std::cout << "Digite o diretorio a ser lido e pressione enter: " << std::endl;
        std::string dir;
        std::cin.ignore();
        std::getline(std::cin, dir);
        return dir;
    }
}

int main() {
    std::string dir = lerDiretorio();
    Leitor leitor(dir);
    IndiceInvertido indiceInvertido = leitor.obterIndiceInvertido();
    Indexador indexador(indiceInvertido);
    Busca busca(.obterIndiceInvertido(), indexador, leitor.obterDocumentosLidos());
    int numeroDocumentosMostrados;
    std::cout << "Digite quantos documentos serao retornados por query: ";
    std::cin >> numeroDocumentosMostrados;
    system("cls||clear");
    std::string query;
    char continuar;
    do {
        std::cout << "Digite a query de busca e pressione enter: " << std::endl;
        std::cin.ignore();
        std::getline(std::cin, query);
        std::vector<Documento> resposta = busca.obterRelevanciaQuery(query);
        std::cout << "Resultados: " << std::endl << std::endl;
        for(int I=0; I<numeroDocumentosMostrados; I++) {
            std::cout << resposta[I].obterNomeDocumento() << std::endl;
        }
        std::cout << "Deseja realizar outra query(S/N)? ";
        std:: cin >> continuar;
    } while(continuar == 'S' || continuar == 's');
    return 0;
}