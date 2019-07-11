#include <iostream>
#include "LeitorCsv.h"
#include "Tokenizer.h"
#include <regex>
#include <stdexcept>
#include "Processador.h"
#include "NumberUtils.h"


using namespace std;
using namespace cpp_util;


int main() {

        ///home/humberto/Área de Trabalho/DADOS DO TRABALHO/

    try {
        string caminho;
        string nome;
        string arquivoCompleto;
        getline(cin, caminho);
        getline(cin, nome);
        arquivoCompleto = caminho + nome;
        Processador* processador = new Processador(arquivoCompleto);
        for(int i = 0; i < 7; i++) {
            processador -> PreencheListaDePPGs();
            if(i < 6) {
                getline(cin, nome);
                arquivoCompleto = caminho + nome;
                processador -> mudaCaminhoDoArquivo(arquivoCompleto);
            }
        }
        string comando;
        cin >> comando;
        if(comando == "rede") {
           processador -> executaComandoRede();
        }
        else if(comando == "ppg") {
            string codigo;
            cin >> codigo;
            processador -> executaComandoPPG(codigo);
        }

        else if(comando == "ies") {
            string sigla;
            cin >> sigla;
            processador -> executaComandoIES(sigla);
        }

        else if(comando == "csv") {
            string codigo;
            string tipoProducao;
            cin >> codigo;
            cin >> tipoProducao;
            processador -> executaComandoCsv(codigo, tipoProducao);
        }
        else {
            throw("Comando desconhecido.");
        }

        delete(processador);

    }
    catch(const char* msg) {
        cout << msg << endl;
    }
    return 0;

}
