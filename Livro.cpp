//
// Created by humberto on 04/07/19.
//

#include "Livro.h"

Livro::Livro(const string &string1, string &string2, const string &natureza, const string &idioma, const string &titulo,
             const string &isbn, const string &editora) : Producao(string1, string2), natureza(natureza), idioma(idioma),
                                                          titulo(titulo), ISBN(isbn), editora(editora) {}

Livro::~Livro() {

}

void Livro::print(ostream &os) {
    os << "miro";
}
