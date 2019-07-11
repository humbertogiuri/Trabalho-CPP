//
// Created by humberto on 04/07/19.
//

#include "Artpe.h"

Artpe::Artpe(const string &string1, string &string2, string &string3, int const& subTipo, const string &natureza, const string &idioma,
             const string &editora, string& volume, string& fasciculo, string& serie, const string &issn) : Producao(string1,
                                                                                                         string2,
                                                                                                         string3, subTipo){
    this -> natureza = natureza;
    this -> idioma = idioma;
    this -> editora = editora;
    this -> ISSN = issn;
    if(isNumber(volume)) {
        this -> volume = (int)stod(volume);
    }
    else {
        this -> volume = 0;
    }
    if(isNumber(fasciculo)) {
        this -> fasciculo = (int)stod(fasciculo);
    }
    else {
        this -> fasciculo = 0;
    }
    if(isNumber(serie)) {
        this -> serie = (int)stod(serie);
    }
    else {
        this -> serie = 0;
    }

}

Artpe::~Artpe() {

}

void Artpe::print(ostream &os) {
    os << this -> natureza << ";" << this -> idioma << ";" << this -> editora << ";" << this -> getCidade() << ";";
    if(this -> volume != 0) {
        os << this -> volume;
    }
    os << ";";
    if(this -> fasciculo != 0) {
        os << this -> fasciculo;
    }
    os << ";";
    if(this -> serie != 0) {
        os << this -> serie;
    }
    os << ";" << this -> ISSN << ";";
    if(this -> getQuantidadeDePaginas() != 0) {
        os << this -> getQuantidadeDePaginas();
    }
    os << endl;
}

bool Artpe::operator<(Producao &auxiliar) {
    Artpe& o = (Artpe&) auxiliar;
    //Compara os dados individualmente
    int cmp = this -> natureza.compare(o.natureza);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> idioma.compare(o.idioma);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> editora.compare(o.editora);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = getCidade().compare(o.getCidade());
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> volume - o.volume;
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> fasciculo - o.fasciculo;
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> serie - o.serie;
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> ISSN.compare(o.ISSN);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> getQuantidadeDePaginas() - o.getQuantidadeDePaginas();
    if(cmp<0) return true; else return false;

}
