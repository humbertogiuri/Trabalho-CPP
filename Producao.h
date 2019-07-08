//
// Created by humberto on 04/07/19.
//

#ifndef TRABALHOC___PRODUCAO_H
#define TRABALHOC___PRODUCAO_H

#include <string>
#include <regex>
#include <iostream>
#include "StringUtils.h"

using namespace std;
using namespace cpp_util;

class Producao {
    string cidade;
    int quantidaDePaginas;

public:
    Producao(const string&, string&);
    Producao(const string&, string&, string&);
    virtual ~Producao();
    virtual void print(ostream&) = 0;
    friend ostream&operator<<(ostream& ostream1, Producao& producao) {
        producao.print(ostream1);
        return ostream1;
    }
    int getQuantidadeDePaginas();

private:
    bool validaPagina(string&);
};


#endif //TRABALHOC___PRODUCAO_H
