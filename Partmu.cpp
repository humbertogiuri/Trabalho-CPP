//
// Created by humberto on 04/07/19.
//

#include "Partmu.h"

Partmu::Partmu(const string &string1, string &string2, const string &natureza, const string &editora,
               const string &formacaoInstrumental) : Producao(string1, string2), natureza(natureza), editora(editora),
                                                     formacaoInstrumental(formacaoInstrumental) {}


void Partmu::print(ostream &os) {
    os << "miro";
}

Partmu::~Partmu() {

}
