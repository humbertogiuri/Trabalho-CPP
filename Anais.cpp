//
// Created by humberto on 04/07/19.
//

#include "Anais.h"

Anais::Anais(const string &string1, string &string2, string &string3, const string &natureza,
             const string &titulo, const string &evento, const string &idioma) : Producao(string1, string2, string3),
                                                                                 natureza(natureza), titulo(titulo),
                                                                                 evento(evento), idioma(idioma) {}

void Anais::print(ostream &ostream1) {
    ostream1 << "miro";
}

Anais::~Anais() {}
