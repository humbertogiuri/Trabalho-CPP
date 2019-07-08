//
// Created by humberto on 04/07/19.
//

#ifndef TRABALHOC___OUTRO_H
#define TRABALHOC___OUTRO_H


#include "Producao.h"

class Outro : public Producao{
    string natureza;
    string idioma;
    string editora;

public:
    Outro(const string &string1, string &string2, const string &natureza, const string &idioma, const string &editora);
    void print(ostream& os);
    virtual ~Outro();
};


#endif //TRABALHOC___OUTRO_H
