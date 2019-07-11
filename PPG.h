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
#include "Anais.h"

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
    friend ostream& operator<<(ostream& os, PPG* ppg);
    int retornaAnais();
    int retornaArtjr();
    int retornaArtpe();
    int retornaLivro();
    int retornaOutro();
    int retornaPartmu();
    int retornaTradu();
    vector<Producao*> retornaVectorProducaoRequerida(const int& id);
    static bool comparaProducao(Producao* p1, Producao* p2);
    static bool comparaProducaoSort(Producao *p1, Producao *p2);
};


#endif //TRABALHOC___PPG_H
