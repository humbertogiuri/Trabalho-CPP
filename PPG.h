//
// Created by humberto on 04/07/19.
//

#ifndef TRABALHOC___PPG_H
#define TRABALHOC___PPG_H

#include <string>
#include <vector>
#include "Producao.h"
#include "Instituicao.h"
#include "StringUtils.h"

using namespace std;
using namespace cpp_util;

class Instituicao;
class PPG {
    string nome;
    string codigo;
    vector<Producao*> vetorDeProducoes;
    vector<Instituicao*> vetorDeInstituicao;

public:
    PPG(const string &nome, const string &sigla);
    void adicionaProducao(Producao*);
    void adicionaInstituicao(Instituicao *);
    string getCodigo();
    bool verificaSeExisteInstituicaoNaLista(Instituicao*);
    int retornaTamanhoDaListaDeProducoes();
    int retornaQuantidadeDePaginasTotalDaListaDeProducoes();
    int retornaQuntidadeDeProducoesComPaginasValidas();
    virtual ~PPG();
    bool verificaPPGemRede();
    void ordenaInstituicoes();
    string getNome();
    void imprimirVetorDInstituicoes();

};


#endif //TRABALHOC___PPG_H
