//
// Created by humberto on 04/07/19.
//

#include "Producao.h"

Producao::Producao(const string &cidade, string& inicial, string& final) {
    this -> cidade = cidade;
    if (validaPagina(inicial) && validaPagina(final)) {
        int total = stol(final) - stol(inicial) + 1;
        if (total > 2000 || total < 0) {
            this->quantidaDePaginas = 0;
        }
        else {
            this->quantidaDePaginas = total;
        }
    }
    else this -> quantidaDePaginas = 0;
}

Producao::Producao(const string &cidade, string & paginas) {
    this -> cidade = cidade;
    if (validaPagina(paginas)) {
        int total = stol(paginas);
        if (total > 2000 || total < 0) {
            this->quantidaDePaginas = -1;
        }
        else {
            this->quantidaDePaginas = total;
        }
    }
    else this -> quantidaDePaginas = -1;
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


