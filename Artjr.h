//
// Created by humberto on 04/07/19.
//

#ifndef TRABALHOC___ARTJR_H
#define TRABALHOC___ARTJR_H

#include <string>
#include "Producao.h"
#include "DateUtils.h"
#include <ctime>

using namespace std;

class Artjr : public Producao{
    string titulo;
    string idioma;
    time_t dataDePublicacao;
    string ISSN;
    int subTipo;
public:
    Artjr(const string &string1, string &string2, string &string3, int const& subTipo,  const string &titulo, const string &idioma,
          const time_t& dataDePublicacao, const string &issn);
    void print(ostream& os);
    virtual ~Artjr();
    int getSubTipo();
    virtual bool operator<(Producao& auxiliar);
};


#endif //TRABALHOC___ARTJR_H
