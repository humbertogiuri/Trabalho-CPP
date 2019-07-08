//
// Created by humberto on 04/07/19.
//

#ifndef TRABALHOC___LIVRO_H
#define TRABALHOC___LIVRO_H


#include "Producao.h"

class Livro : public Producao{
    string natureza;
    string idioma;
    string titulo;
    string ISBN;
    string editora;

public:
    Livro(const string &string1, string &string2, const string &natureza, const string &idioma, const string &titulo,
          const string &isbn, const string &editora);
    void print(ostream& os);
    virtual ~Livro();
};


#endif //TRABALHOC___LIVRO_H
