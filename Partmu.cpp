//
// Created by humberto on 04/07/19.
//

#include "Partmu.h"

Partmu::Partmu(const string &string1, string &string2, int const& subTipo, const string &natureza, const string &editora,
               const string &formacaoInstrumental) : Producao(string1, string2, subTipo), natureza(natureza), editora(editora),
                                                     formacaoInstrumental(formacaoInstrumental){}


void Partmu::print(ostream &os) {
    os << this -> natureza << ";" << this -> editora << ";" << this -> getCidade() << ";" << this -> formacaoInstrumental << ";";
    if(this -> getQuantidadeDePaginas() != 0) {
        os << this -> getQuantidadeDePaginas();
    }
    os << endl;
}

Partmu::~Partmu() {

}

bool Partmu::operator<(Producao &auxiliar) {
    Partmu& o = (Partmu&) auxiliar;
    int cmp = this -> natureza.compare(o.natureza);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> editora.compare(o.editora);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> getCidade().compare(o.getCidade());
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> formacaoInstrumental.compare(o.formacaoInstrumental);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> getQuantidadeDePaginas() - o.getQuantidadeDePaginas();
    if(cmp<0) return true; else return false;
}

