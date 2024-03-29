//
// Created by humberto on 04/07/19.
//

#ifndef TRABALHOC___PARTMU_H
#define TRABALHOC___PARTMU_H


#include "Producao.h"

class Partmu : public Producao{
    string natureza;
    string editora;
    string formacaoInstrumental;
public:
    Partmu(const string &string1, string &string2, int const& subTipo, const string &natureza, const string &editora,
           const string &formacaoInstrumental);
    void print(ostream& os);
    virtual ~Partmu();
    virtual bool operator<(Producao& auxiliar);
};



#endif //TRABALHOC___PARTMU_H
