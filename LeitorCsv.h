//
// Created by humberto on 04/07/19.
//

#ifndef TRABALHOC___LEITORCSV_H
#define TRABALHOC___LEITORCSV_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Tokenizer.h"


using namespace std;
using namespace cpp_util;

class LeitorCsv {

    ifstream arquivoCsv;
    vector<string>* linhaAtual;

public:
    LeitorCsv(const string&);
    vector<string> proximaLinhaDoArquivo();
    bool haProximaLinha();
    virtual ~LeitorCsv();
    void setArquivoCsv(const string&);
};


#endif //TRABALHOC___LEITORCSV_H
