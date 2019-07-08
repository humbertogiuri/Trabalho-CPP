//
// Created by humberto on 04/07/19.
//

#ifndef TRABALHOC___ARTJR_H
#define TRABALHOC___ARTJR_H

#include <string>
#include "Producao.h"

using namespace std;

class Artjr : public Producao{
    string titulo;
    string idioma;
    string dataDePublicacao;
    string ISSN;

public:
    Artjr(const string &string1, string &string2, string &string3, const string &titulo, const string &idioma,
          const string &dataDePublicacao, const string &issn);
    void print(ostream& os);
    virtual ~Artjr();
};


#endif //TRABALHOC___ARTJR_H
