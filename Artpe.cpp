//
// Created by humberto on 04/07/19.
//

#include "Artpe.h"

Artpe::Artpe(const string &string1, string &string2, string &string3, const string &natureza, const string &idioma,
             const string &editora, string& volume, string& fasciculo, string& serie, const string &issn) : Producao(string1,
                                                                                                         string2,
                                                                                                         string3){
    this -> natureza = natureza;
    this -> idioma = idioma;
    this -> editora = editora;
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
    os << "miro";
}
