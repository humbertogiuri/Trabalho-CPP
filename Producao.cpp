//
// Created by humberto on 04/07/19.
//

#include "Producao.h"

Producao::Producao(const string &cidade, string& inicial, string& final, int const& subTipo) {
    this -> cidade = cidade;
    if (validaPagina(inicial) && validaPagina(final)) {
        long total = stol(final) - stol(inicial) + 1;
        if (total > 2000 || total < 0) {
            this->quantidaDePaginas = 0;
        }
        else {
            this->quantidaDePaginas = total;
        }
    }
    else this -> quantidaDePaginas = 0;
    this -> subTipo = subTipo;
}

Producao::Producao(const string &cidade, string & paginas, int const& subTipo) {
    this -> cidade = cidade;
    this -> subTipo = subTipo;
    if (validaPagina(paginas)) {
        long total = stol(paginas);
        if (total > 2000 || total < 0) {
            this->quantidaDePaginas = 0;
        }
        else {
            this->quantidaDePaginas = total;
        }
    }
    else this -> quantidaDePaginas = 0;
}

int Producao::getQuantidadeDePaginas() {
    return this -> quantidaDePaginas;
}

bool Producao::validaPagina(string &paginaRequerida) {
    if(isNumber(paginaRequerida)) {
        long paginas = stol(paginaRequerida);
        if(paginas < 0) {
            return false;
        }
        return true;
    }
    return false;
}

Producao::~Producao() {}

int Producao::getSubTipo() {
    return this -> subTipo;
}

string Producao::getCidade() {
    return this -> cidade;
}

string Producao::toString() {
    stringstream texto;
    print(texto);
    return texto.str();
};

