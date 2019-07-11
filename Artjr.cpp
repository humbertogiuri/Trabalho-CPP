//
// Created by humberto on 04/07/19.
//

#include "Artjr.h"

Artjr::Artjr(const string &string1, string &string2, string &string3, int const& subTipo, const string &titulo, const string &idioma,
             const string &dataDePublicacao, const string &issn) : Producao(string1, string2, string3, subTipo), titulo(titulo),
                                                                   idioma(idioma), dataDePublicacao(dataDePublicacao),
                                                                   ISSN(issn){}

Artjr::~Artjr() {

}

void Artjr::print(ostream &os) {
    os << this -> titulo << ";" << this -> idioma << ";" << ";" << this -> getCidade() << ";";
    os << this -> dataDePublicacao << ";" << this -> ISSN << ";";
    if(this -> getQuantidadeDePaginas() != 0) {
        os << this -> getQuantidadeDePaginas();
    }
    os << endl;
}

int Artjr::getSubTipo() {
    return this -> subTipo;
}

bool Artjr::operator<(Producao &auxiliar) {

}
