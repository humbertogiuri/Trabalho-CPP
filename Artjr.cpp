//
// Created by humberto on 04/07/19.
//

#include "Artjr.h"

Artjr::Artjr(const string &string1, string &string2, string &string3, int const& subTipo, const string &titulo, const string &idioma,
             const time_t &dataDePublicacao, const string &issn) : Producao(string1, string2, string3, subTipo), titulo(titulo),
                                                                   idioma(idioma), dataDePublicacao(dataDePublicacao),
                                                                   ISSN(issn){}

Artjr::~Artjr() {

}

void Artjr::print(ostream &os) {
    os << this -> titulo << ";" << this -> idioma << ";" << this -> getCidade() << ";";
    os << formatDate(this -> dataDePublicacao, DATE_FORMAT_PT_BR_SHORT) << ";" << this -> ISSN << ";";
    if(this -> getQuantidadeDePaginas() != 0) {
        os << this -> getQuantidadeDePaginas();
    }
    os << endl;
}

int Artjr::getSubTipo() {
    return this -> subTipo;
}

bool Artjr::operator<(Producao &auxiliar) {
    Artjr& o = (Artjr&) auxiliar;
    //Compara os dados individualmente
    int cmp = this -> titulo.compare(o.titulo);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> idioma.compare(o.idioma);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> getCidade().compare(o.getCidade());
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> dataDePublicacao - o.dataDePublicacao;
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> ISSN.compare(o.ISSN);
    if(cmp<0) return true; else if(cmp>0) return false;
    cmp = this -> getQuantidadeDePaginas() - o.getQuantidadeDePaginas();
    if(cmp<0) return true; else return false;
}
