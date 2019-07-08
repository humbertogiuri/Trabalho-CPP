//
// Created by humberto on 04/07/19.
//

#ifndef TRABALHOC___PROCESSADOR_H
#define TRABALHOC___PROCESSADOR_H

#include "PPG.h"
#include "Instituicao.h"
#include "LeitorCsv.h"
#include "Anais.h"
#include "Artjr.h"
#include "Artpe.h"
#include "Partmu.h"
#include "Tradu.h"
#include "Outro.h"
#include "Livro.h"
#include <unordered_map>
#include "StringUtils.h"

using namespace std;
using namespace cpp_util;

class Processador {
    LeitorCsv* leitor;
    vector<string> cabecalho;
    unordered_map <string, PPG*> PPGs;
    unordered_map <string, Instituicao*> instituicoes;

public:
    Processador(const string&);
    void PreencheListaDePPGs();
    int getQuantidadeDeProducoes();
    int retornaQuantidadeDeInstituicoes();
    int retornaQuantidadeDePPGs();
    int retornaQuantidadeDePaginasDeTodasAsPPGs();
    double retornaMediaDePaginasPorPublicacao();
    void mudaCaminhoDoArquivo(const string&);
    void executaComandoRede();
    virtual ~Processador();
    void teste();
private:
    int retornaIndiceNoCabecalho(const string&);
    int retornaQuantdadeDproducoesValidasDeTodasAsPPGs();
};


#endif //TRABALHOC___PROCESSADOR_H
