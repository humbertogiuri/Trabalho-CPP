//
// Created by humberto on 04/07/19.
//

#ifndef TRABALHOC___ARTPE_H
#define TRABALHOC___ARTPE_H

#include "Producao.h"

class Artpe : public Producao{
    string natureza;
    string idioma;
    string editora;
    int volume;
    int fasciculo;
    int serie;
    string ISSN;

public:
    Artpe(const string &string1, string &string2, string &string3, const string &natureza, const string &idioma,
          const string &editora, string& volume, string& fasciculo, string& serie, const string &issn);
    void print(ostream& os);
    virtual ~Artpe();
};


#endif //TRABALHOC___ARTPE_H
