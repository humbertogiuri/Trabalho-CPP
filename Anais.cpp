//
// Created by humberto on 04/07/19.
//

#include "Anais.h"

Anais::Anais(const string &string1, string &string2, string &string3, int const& subTipo, const string &natureza,
             const string &titulo, const string &evento, const string &idioma) : Producao(string1, string2, string3, subTipo),
                                                                                 natureza(natureza), titulo(titulo),
                                                                                 evento(evento), idioma(idioma) {}

void Anais::print(ostream &ostream1) {
    ostream1 << this -> natureza << ";" << this -> titulo << ";" << this -> idioma << ";";
    ostream1 << this -> evento << ";" << this -> getCidade() << ";";
    if(!this -> getQuantidadeDePaginas() == 0) {
        ostream1 << this -> getQuantidadeDePaginas();
    }

    ostream1 << endl;
}

Anais::~Anais() {}

bool Anais::operator<(Producao& auxiliar) {
    Anais& auxiliar1 = (Anais&) auxiliar;
    int cmp = this -> natureza.compare(auxiliar1.natureza);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> titulo.compare(auxiliar1.titulo);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> idioma.compare(auxiliar1.idioma);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> evento.compare(auxiliar1.evento);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> getCidade().compare(auxiliar1.getCidade());
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> getQuantidadeDePaginas() - auxiliar1.getQuantidadeDePaginas();
    if(cmp<0) return true; else return false;
}
