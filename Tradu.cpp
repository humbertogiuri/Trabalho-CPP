//
// Created by humberto on 04/07/19.
//

#include "Tradu.h"

Tradu::Tradu(const string &string1, string &string2, int const& subTipo, const string &titulo, const string &idioma,
             const string &natureza, const string &editora, const string &idiomaTraducao) : Producao(string1, string2, subTipo),
                                                                                            titulo(titulo),
                                                                                            idioma(idioma),
                                                                                            natureza(natureza),
                                                                                            editora(editora),
                                                                                            idiomaTraducao(
                                                                                                    idiomaTraducao){}

Tradu::~Tradu() {

}

void Tradu::print(ostream &os) {
    os << this -> natureza << ";" << this -> titulo << ";" << this -> idioma << ";";
    os << this -> editora << ";" << this -> getCidade() << ";" << this -> idiomaTraducao << ";";
    if(this -> getQuantidadeDePaginas() != 0) {
        os << this -> getQuantidadeDePaginas();
    }
    os << endl;
}

bool Tradu::operator<(Producao &auxiliar) {
    Tradu& o = (Tradu&) auxiliar;
    //Compara os dados individualmente
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
    cmp = this -> idiomaTraducao.compare(o.idiomaTraducao);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> getQuantidadeDePaginas() - o.getQuantidadeDePaginas();
    if(cmp<0) return true; else return false;

}

