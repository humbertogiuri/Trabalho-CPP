//
// Created by humberto on 04/07/19.
//

#include "Outro.h"

Outro::Outro(const string &string1, string &string2, int const& subTipo, const string &natureza, const string &idioma, const string &editora)
        : Producao(string1, string2, subTipo), natureza(natureza), idioma(idioma), editora(editora) {}

Outro::~Outro() {

}

void Outro::print(ostream &os) {
    os << this -> natureza << ";" << this -> idioma << ";" << this -> editora << ";" << this -> getCidade() << ";";
    if(this -> getQuantidadeDePaginas() != 0) {
        os << this -> getQuantidadeDePaginas();
    }
    os << endl;
}

bool Outro::operator<(Producao &auxiliar) {
    Outro& o = (Outro&) auxiliar;
    int cmp = this -> natureza.compare(o.natureza);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> idioma.compare(o.idioma);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> editora.compare(o.editora);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> getCidade().compare(o.getCidade());
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> getQuantidadeDePaginas() - o.getQuantidadeDePaginas();
    if(cmp<0) return true; else return false;
}

