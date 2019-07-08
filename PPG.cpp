//
// Created by humberto on 04/07/19.
//

#include "PPG.h"

PPG::PPG(const string &nome, const string &codigo) : nome(nome), codigo(codigo) {}

void PPG::adicionaInstituicao(Instituicao *instituicao) {
    if(!this -> verificaSeExisteInstituicaoNaLista(instituicao)) {
        this -> vetorDeInstituicao.push_back(instituicao);
    }

}

void PPG::adicionaProducao(Producao *producao) {
    this -> vetorDeProducoes.push_back(producao);
}

string PPG::getCodigo() {
    return this -> codigo;
}

bool PPG::verificaSeExisteInstituicaoNaLista(Instituicao *instituicao) {
    for(auto& iterador : this -> vetorDeInstituicao) {
        if(iterador -> getNome() + iterador -> getSigla()  == instituicao -> getNome() + iterador -> getSigla())
            return true;
    }
    return false;
}

int PPG::retornaTamanhoDaListaDeProducoes() {
    return this -> vetorDeProducoes.size();
}

int PPG::retornaQuantidadeDePaginasTotalDaListaDeProducoes() {
    int paginasTotal = 0;
    for(auto& iterador : this -> vetorDeProducoes) {
        if(!iterador -> getQuantidadeDePaginas() == 0) {
            paginasTotal += iterador -> getQuantidadeDePaginas();
        }
    }
    return paginasTotal;
}

int PPG::retornaQuntidadeDeProducoesComPaginasValidas() {
    int producoesValidas = 0;
    for(auto& iterador : this -> vetorDeProducoes) {
        if(!iterador -> getQuantidadeDePaginas() == 0) {
            producoesValidas++ ;
        }
    }
    return producoesValidas;
}

PPG::~PPG() {
    for(auto& iterator : this -> vetorDeProducoes) {
        delete(iterator);
    }
    for(auto& iterator : this -> vetorDeInstituicao) {
        delete(iterator);
    }
}


bool PPG::verificaPPGemRede() {
    if(this -> vetorDeInstituicao.size() > 1) {
        return true;
    }
    return false;
}

bool comparaInstituicao(Instituicao *instituicao1, Instituicao *instituicao2) {
    int cmp = instituicao1 -> getSigla().compare(instituicao2 -> getSigla());
    if(cmp < 0) return true; else if(cmp > 0) return false;
    cmp = instituicao1 -> getNome().compare(instituicao2 -> getNome());
    if(cmp < 0) return true; else if(cmp > 0) return false;
    return false;
}

void PPG::ordenaInstituicoes() {
    sort(this->vetorDeInstituicao.begin(), this->vetorDeInstituicao.end(), comparaInstituicao);
}



string PPG::getNome() {
    return this -> nome;
}

void PPG::imprimirVetorDInstituicoes() {
    for(auto& iterator : this -> vetorDeInstituicao) {
        cout << iterator;
    }
}

