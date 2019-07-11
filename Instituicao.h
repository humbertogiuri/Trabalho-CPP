//
// Created by humberto on 04/07/19.
//

#ifndef TRABALHOC___INSTITUICAO_H
#define TRABALHOC___INSTITUICAO_H


#include "string"
#include <vector>
#include "PPG.h"
#include <iostream>

using namespace std;

class PPG;
class Instituicao {
    string nome;
    string sigla;
    vector<PPG*> vetorDePPGs;

public:
    Instituicao(const string &nome, const string &sigla);
    void adicionaPPG(PPG*);
    bool verificaSeExistePPGnaLista(PPG*);
    string getNome();
    virtual ~Instituicao();
    string getSigla();
    friend ostream& operator<<(ostream& os, const Instituicao* instituicao);
    void ordenaPPGs();
    void imprimirPGGsFormatadas();
};


#endif //TRABALHOC___INSTITUICAO_H
