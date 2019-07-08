//
// Created by humberto on 04/07/19.
//

#ifndef TRABALHOC___TRADU_H
#define TRABALHOC___TRADU_H


#include "Producao.h"
#include <string>

using namespace std;

class Tradu : public Producao{
    string titulo;
    string idioma;
    string natureza;
    string editora;
    string idiomaTraducao;

public:
    Tradu(const string &string1, string &string2, const string &titulo, const string &idioma,
          const string &natureza, const string &editora, const string &idiomaTraducao);
    void print(ostream& os);
    virtual ~Tradu();
};


#endif //TRABALHOC___TRADU_H
