//
// Created by humberto on 04/07/19.
//

#ifndef TRABALHOC___ANAIS_H
#define TRABALHOC___ANAIS_H


#include "Producao.h"
#include <string>

using namespace std;

class Anais : public Producao{
    string natureza;
    string titulo;
    string evento;
    string idioma;

public:
    Anais(const string &string1, string &string2, string &string3, int const& subTipo, const string &natureza,
          const string &titulo, const string &evento, const string &idioma);
    virtual ~Anais();
    virtual void print(ostream&);
    virtual bool operator<(Producao& auxiliar);
};


#endif //TRABALHOC___ANAIS_H
