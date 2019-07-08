//
// Created by humberto on 04/07/19.
//

#include "Tradu.h"

Tradu::Tradu(const string &string1, string &string2, const string &titulo, const string &idioma,
             const string &natureza, const string &editora, const string &idiomaTraducao) : Producao(string1, string2),
                                                                                            titulo(titulo),
                                                                                            idioma(idioma),
                                                                                            natureza(natureza),
                                                                                            editora(editora),
                                                                                            idiomaTraducao(
                                                                                                    idiomaTraducao) {}

Tradu::~Tradu() {

}

void Tradu::print(ostream &os) {
    os << "miro";
}
