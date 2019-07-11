//
// Created by humberto on 04/07/19.
//

#include "PPG.h"

PPG::PPG(const string &nome, const string &codigo) : nome(nome), codigo(codigo) {}

void PPG::adicionaInstituicao(Instituicao *instituicao) {
    if(!this -> verificaSeExisteInstituicaoNaLista(instituicao)) {
        this -> vetorDeInstituicao.push_back(instituicao);
    }

}

void PPG::adicionaProducao(Producao *producao) {
    this -> vetorDeProducoes.push_back(producao);
}

string PPG::getCodigo() {
    return this -> codigo;
}

bool PPG::verificaSeExisteInstituicaoNaLista(Instituicao *instituicao) {
    for(auto& iterador : this -> vetorDeInstituicao) {
        if(iterador -> getNome() + iterador -> getSigla()  == instituicao -> getNome() + iterador -> getSigla())
            return true;
    }
    return false;
}

int PPG::retornaTamanhoDaListaDeProducoes() {
    return this -> vetorDeProducoes.size();
}

int PPG::retornaQuantidadeDePaginasTotalDaListaDeProducoes() {
    int paginasTotal = 0;
    for(auto& iterador : this -> vetorDeProducoes) {
        if(!iterador -> getQuantidadeDePaginas() == 0) {
            paginasTotal += iterador -> getQuantidadeDePaginas();
        }
    }
    return paginasTotal;
}

int PPG::retornaQuntidadeDeProducoesComPaginasValidas() {
    int producoesValidas = 0;
    for(auto& iterador : this -> vetorDeProducoes) {
        if(!iterador -> getQuantidadeDePaginas() == 0) {
            producoesValidas++ ;
        }
    }
    return producoesValidas;
}

PPG::~PPG() {
    for(auto& iterator : this -> vetorDeProducoes) {
        delete(iterator);
    }
}


bool PPG::verificaPPGemRede() {
    if(this -> vetorDeInstituicao.size() > 1) {
        return true;
    }
    return false;
}


bool comparaInstituicao(Instituicao *instituicao1, Instituicao *instituicao2) {
    int cmp = instituicao1 -> getSigla().compare(instituicao2 -> getSigla());
    if(cmp < 0) return true; else if(cmp > 0) return false;
    cmp = instituicao1 -> getNome().compare(instituicao2 -> getNome());
    if(cmp < 0) return true; else if(cmp > 0) return false;
    return false;
}

void PPG::ordenaInstituicoes() {
    sort(this->vetorDeInstituicao.begin(), this->vetorDeInstituicao.end(), comparaInstituicao);
}



string PPG::getNome() {
    return this -> nome;
}

void PPG::imprimirVetorDInstituicoes() {
    for(auto& iterator : this -> vetorDeInstituicao) {
        cout << iterator;
    }
}


ostream &operator<<(ostream &os, PPG *ppg) {
    os << "Programa: " << ppg -> getNome() << endl;
    os << "Instituicoes:" << endl;
    ppg -> ordenaInstituicoes();
    ppg -> imprimirVetorDInstituicoes();
    os << endl;
    os << "Quantidade de producoes por tipo:" << endl;
    os << "\t- Artigos em anais de eventos: " << ppg -> retornaAnais() << endl;
    os << "\t- Artigos em jornais e revistas: " << ppg -> retornaArtjr() << endl;
    os << "\t- Artigos em periodicos cientificos: " << ppg -> retornaArtpe() << endl;
    os << "\t- Livros: "  << ppg -> retornaLivro() << endl;
    os << "\t- Partituras musicais: " << ppg -> retornaPartmu() << endl;
    os << "\t- Traducoes: " << ppg -> retornaTradu() << endl;
    os << "\t- Outros: " << ppg -> retornaOutro() << endl;
    os << endl;
    os << "Total de paginas produzidas pelo PPG: " << ppg -> retornaQuantidadeDePaginasTotalDaListaDeProducoes() << endl;
}

int PPG::retornaAnais() {
    int contador = 0;
    for(auto& iterator : this -> vetorDeProducoes) {
        if(iterator -> getSubTipo() == 8) {
            contador++;
        }
    }
    return contador;
}

int PPG::retornaArtjr() {
    int contador = 0;
    for(auto& iterator : this -> vetorDeProducoes) {
        if(iterator -> getSubTipo() == 9) {
            contador++;
        }
    }
    return contador;
}

int PPG::retornaArtpe()  {
    int contador = 0;
    for(auto& iterator : this -> vetorDeProducoes) {
        if(iterator -> getSubTipo() == 25) {
            contador++;
        }
    }
    return contador;
}

int PPG::retornaLivro()  {
    int contador = 0;
    for(auto& iterator : this -> vetorDeProducoes) {
        if(iterator -> getSubTipo() == 26) {
            contador++;
        }
    }
    return contador;
}

int PPG::retornaOutro()  {
    int contador = 0;
    for(auto& iterator : this -> vetorDeProducoes) {
        if(iterator -> getSubTipo() == 10) {
            contador++;
        }
    }
    return contador;
}

int PPG::retornaPartmu()  {
    int contador = 0;
    for(auto& iterator : this -> vetorDeProducoes) {
        if(iterator -> getSubTipo() == 28) {
            contador++;
        }
    }
    return contador;
}

int PPG::retornaTradu() {
    int contador = 0;
    for(auto& iterator : this -> vetorDeProducoes) {
        if(iterator -> getSubTipo() == 21) {
            contador++;
        }
    }
    return contador;
}


vector<Producao*> PPG::retornaVectorProducaoRequerida(const int &id) {
    vector<Producao*> producao;

    for(int i = 0; i < this -> vetorDeProducoes.size(); i++) {

        if(this -> vetorDeProducoes[i] -> getSubTipo() == id) {

            if (producao.size() == 0) {
                producao.push_back(this -> vetorDeProducoes[i]);
            }
            else {
                int contador = 0;

                for (int j = 0; j < producao.size(); j++) {
                    Producao* auxiliar = this -> vetorDeProducoes[i];

                    if (comparaProducao(auxiliar, producao[j])) {
                        contador++;
                    }
                }

                if (contador == 0) {
                    producao.push_back(this -> vetorDeProducoes[i]);
                }
            }
        }
    }
    return producao;
}

bool PPG::comparaProducao(Producao *p1, Producao *p2) {
    if(p1 -> toString() == p2 -> toString()) {
        return true;
    }
    return false;
}

bool PPG::comparaProducaoSort(Producao *p1, Producao *p2) {
    return *p1 < *p2;
}

