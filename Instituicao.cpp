//
// Created by humberto on 04/07/19.
//

#include "Instituicao.h"

Instituicao::Instituicao(const string &nome, const string &sigla) : nome(nome), sigla(sigla) {
}

void Instituicao::adicionaPPG(PPG *ppg) {
    if(!verificaSeExistePPGnaLista(ppg)) {
        this -> vetorDePPGs.push_back(ppg);
    }
}

bool Instituicao::verificaSeExistePPGnaLista(PPG *ppg) {
    for(auto& iterador : this -> vetorDePPGs) {
        if(iterador -> getCodigo() == ppg -> getCodigo()) {
            return true;
        }
    }
    return false;
}

string Instituicao::getNome() {
    return this -> nome;
}

string Instituicao::getSigla() {
    return this -> sigla;
}

Instituicao::~Instituicao() {}

ostream &operator<<(ostream &os, const Instituicao* instituicao) {
    os << "\t- " << instituicao -> sigla << " (" << instituicao -> nome << ")" << endl;
}

bool comparaPPG(PPG* ppg1, PPG* ppg2) {
    return stringCompare(ppg1 -> getNome(), ppg2 -> getNome());
}

void Instituicao::ordenaPPGs() {
    sort(this -> vetorDePPGs.begin(), this -> vetorDePPGs.end(), comparaPPG);
}

void Instituicao::imprimirPGGsFormatadas() {
    for(auto& iterator : this -> vetorDePPGs) {
        cout << "\t- " << iterator -> getNome() << ": " << iterator -> retornaTamanhoDaListaDeProducoes() << " producoes" << endl;
    }
}


