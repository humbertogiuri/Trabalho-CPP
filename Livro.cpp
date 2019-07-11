//
// Created by humberto on 04/07/19.
//

#include "Livro.h"

Livro::Livro(const string &string1, string &string2, int const& subTipo, const string &natureza, const string &idioma, const string &titulo,
             const string &isbn, const string &editora) : Producao(string1, string2, subTipo), natureza(natureza), idioma(idioma),
                                                          titulo(titulo), ISBN(isbn), editora(editora){}

Livro::~Livro() {

}

void Livro::print(ostream &os) {
    os << this -> natureza << ";" << this -> titulo << ";" << this -> idioma << ";";
    os << this -> editora << ";" << this -> getCidade() << ";" << this -> ISBN << ";";
    if(this -> getQuantidadeDePaginas() != 0) {
        os << this -> getQuantidadeDePaginas();
    }
    os << endl;
}

bool Livro::operator<(Producao &auxiliar) {
    Livro& o = (Livro&) auxiliar;
    int cmp = this -> natureza.compare(o.natureza);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> titulo.compare(o.titulo);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> idioma.compare(o.idioma);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> editora.compare(o.editora);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> getCidade().compare(o.getCidade());
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> ISBN.compare(o.ISBN);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> getQuantidadeDePaginas() - o.getQuantidadeDePaginas();
    if(cmp<0) return true; else return false;
}
