//
// Created by humberto on 04/07/19.
//

#include "Outro.h"

Outro::Outro(const string &string1, string &string2, const string &natureza, const string &idioma, const string &editora)
        : Producao(string1, string2), natureza(natureza), idioma(idioma), editora(editora) {}

Outro::~Outro() {

}

void Outro::print(ostream &os) {
    os << "miro";
}
