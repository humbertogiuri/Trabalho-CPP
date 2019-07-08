//
// Created by humberto on 04/07/19.
//

#include "LeitorCsv.h"

LeitorCsv::LeitorCsv(const string &arquivoCsv) {
    this -> arquivoCsv.open(arquivoCsv);

    if(!this -> arquivoCsv.good()) {
        this -> arquivoCsv.close();
        throw ("Erro de I/O");
    }
    this -> linhaAtual = new vector<string>();
}

vector<string> LeitorCsv::proximaLinhaDoArquivo() {
    string linhaAuxiliar;
    getline(this -> arquivoCsv, linhaAuxiliar);
    Tokenizer toc(linhaAuxiliar, ';');
    return toc.remaining();
}

bool LeitorCsv::haProximaLinha() {
    if(this -> arquivoCsv.eof()) {
        return false;
    }
    return true;
}

LeitorCsv::~LeitorCsv() {
    this -> arquivoCsv.close();
    delete(this -> linhaAtual);
}

void LeitorCsv::setArquivoCsv(const string& novoArquivo) {
    this -> arquivoCsv.close();
    this -> arquivoCsv.open(novoArquivo);
    if(!this -> arquivoCsv.good()) {
        this -> arquivoCsv.close();
        throw ("Erro de I/O");
    }
}

