//
// Created by humberto on 04/07/19.
//

#include "Artjr.h"

Artjr::Artjr(const string &string1, string &string2, string &string3, const string &titulo, const string &idioma,
             const string &dataDePublicacao, const string &issn) : Producao(string1, string2, string3), titulo(titulo),
                                                                   idioma(idioma), dataDePublicacao(dataDePublicacao),
                                                                   ISSN(issn) {}

Artjr::~Artjr() {

}

void Artjr::print(ostream &os) {
    os << "miro";
}
