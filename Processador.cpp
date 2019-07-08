//
// Created by humberto on 04/07/19.
//

#include "Processador.h"

Processador::Processador(const string& caminho) {
    this -> leitor = new LeitorCsv(caminho);
}

void Processador::PreencheListaDePPGs() {
    this -> cabecalho = this -> leitor -> proximaLinhaDoArquivo();
    vector<string> linha = leitor -> proximaLinhaDoArquivo();
    while(leitor -> haProximaLinha()) {

        Producao* producaoAtual = nullptr;
        Instituicao* instituicaoAtual = nullptr;
        PPG* ppgAtual = nullptr;

        string codigoPPG = linha[this -> retornaIndiceNoCabecalho("CD_PROGRAMA_IES")];
        string sigla = linha[this -> retornaIndiceNoCabecalho("SG_ENTIDADE_ENSINO")];
        string nomeFaculdade = linha[this -> retornaIndiceNoCabecalho("NM_ENTIDADE_ENSINO")];
        string idSubtipo = linha[this -> retornaIndiceNoCabecalho("ID_SUBTIPO_PRODUCAO")];
        string cidade = linha[this -> retornaIndiceNoCabecalho("NM_CIDADE")];

        if(instituicoes.find(nomeFaculdade + sigla) == instituicoes.end()) {
            instituicaoAtual = new Instituicao(nomeFaculdade, sigla);
            instituicoes.insert({nomeFaculdade + sigla, instituicaoAtual});
        }

        else {
            instituicaoAtual = instituicoes.find(nomeFaculdade + sigla) -> second;
        }

        if(idSubtipo == "8") {//caso seja anais

            string titulo = linha[this -> retornaIndiceNoCabecalho("NM_TITULO")];
            string natureza = linha[this -> retornaIndiceNoCabecalho("DS_NATUREZA")];
            string idioma = linha[this -> retornaIndiceNoCabecalho("DS_IDIOMA")];
            string evento = linha[this -> retornaIndiceNoCabecalho("DS_EVENTO")];
            string paginaInical = linha[this -> retornaIndiceNoCabecalho("NR_PAGINA_INICIAL")];
            string paginaFinal = linha[this -> retornaIndiceNoCabecalho("NR_PAGINA_FINAL")];

            producaoAtual = new Anais(cidade, paginaInical, paginaFinal, natureza, titulo, evento, idioma);
        }

        else if(idSubtipo == "9") { //caso seja artjr

            string titulo = linha[this -> retornaIndiceNoCabecalho("NM_TITULO")];
            string idioma = linha[this -> retornaIndiceNoCabecalho("DS_IDIOMA")];
            string dataDePublicacao = linha[this -> retornaIndiceNoCabecalho("DT_PUBLICACAO")];
            string ISSN = linha[this -> retornaIndiceNoCabecalho("DS_ISSN")];
            string paginaInicial = linha[this -> retornaIndiceNoCabecalho("NR_PAGINA_INICIAL")];
            string paginaFinal = linha[this -> retornaIndiceNoCabecalho("NR_PAGINA_FINAL")];

            producaoAtual = new Artjr(cidade, paginaInicial, paginaFinal, titulo, idioma, dataDePublicacao, ISSN);
        }

        else if(idSubtipo == "25") { //caso seja artpe

            string natureza = linha[this -> retornaIndiceNoCabecalho("DS_NATUREZA")];
            string idioma = linha[this -> retornaIndiceNoCabecalho("DS_IDIOMA")];
            string editora = linha[this -> retornaIndiceNoCabecalho("NM_EDITORA")];
            string ISSN = linha[this -> retornaIndiceNoCabecalho("DS_ISSN")];
            string paginaInicial = linha[this -> retornaIndiceNoCabecalho("NR_PAGINA_INICIAL")];
            string paginaFinal = linha[this -> retornaIndiceNoCabecalho("NR_PAGINA_FINAL")];
            string fasciculo = linha[this -> retornaIndiceNoCabecalho("DS_FASCICULO")];
            string serie = linha[this -> retornaIndiceNoCabecalho("NR_SERIE")];
            string volume = linha[this -> retornaIndiceNoCabecalho("NR_VOLUME")];

            producaoAtual = new Artpe(cidade, paginaInicial, paginaFinal, natureza, idioma, editora, volume, fasciculo, serie, ISSN);
        }

        else if(idSubtipo == "26") { //caso seja Livro

            string natureza = linha[this -> retornaIndiceNoCabecalho("DS_NATUREZA")];
            string idioma = linha[this -> retornaIndiceNoCabecalho("DS_IDIOMA")];
            string editora = linha[this -> retornaIndiceNoCabecalho("NM_EDITORA")];
            string ISBN = linha[this -> retornaIndiceNoCabecalho("DS_ISBN")];
            string pagina = linha[this -> retornaIndiceNoCabecalho("NR_PAGINAS_CONTRIBUICAO")];
            string titulo = linha[this -> retornaIndiceNoCabecalho("NM_TITULO")];
            string cidadeLivro = linha[this -> retornaIndiceNoCabecalho("NM_CIDADE_PAIS")];

            producaoAtual = new Livro(cidade, pagina, natureza, idioma, titulo, ISBN, editora);
        }

        else if(idSubtipo == "10") { //caso seja Outro

            string natureza = linha[this -> retornaIndiceNoCabecalho("DS_NATUREZA")];
            string idioma = linha[this -> retornaIndiceNoCabecalho("DS_IDIOMA")];
            string editora = linha[this -> retornaIndiceNoCabecalho("NM_EDITORA")];
            string pagina = linha[this -> retornaIndiceNoCabecalho("NR_PAGINAS")];

            producaoAtual = new Outro(cidade, pagina, natureza, idioma, editora);
        }

        else if(idSubtipo == "28") { //caso seja Partmu

            string natureza = linha[this -> retornaIndiceNoCabecalho("DS_NATUREZA")];
            string formacaoInstrumental = linha[this -> retornaIndiceNoCabecalho("DS_FORMACAO_INSTRUMENTAL")];
            string editora = linha[this -> retornaIndiceNoCabecalho("NM_EDITORA")];
            string pagina = linha[this -> retornaIndiceNoCabecalho("NR_PAGINAS")];

            producaoAtual = new Partmu(cidade, pagina, natureza, editora, formacaoInstrumental);
        }

        else if(idSubtipo == "21") { //caso seja Tradu

            string natureza = linha[this -> retornaIndiceNoCabecalho("DS_NATUREZA")];
            string idioma = linha[this -> retornaIndiceNoCabecalho("DS_IDIOMA")];
            string editora = linha[this -> retornaIndiceNoCabecalho("NM_EDITORA_TRADUCAO")];
            string titulo = linha[this -> retornaIndiceNoCabecalho("NM_TITULO")];
            string idiomaTraducao = linha[this -> retornaIndiceNoCabecalho("DS_IDIOMA_TRADUCAO")];
            string pagina = linha[this -> retornaIndiceNoCabecalho("NR_PAGINAS")];

            producaoAtual = new Tradu(cidade, pagina, titulo, idioma, natureza, editora, idiomaTraducao);
        }

        if(PPGs.find(codigoPPG) == PPGs.end()) {
            ppgAtual = new PPG(linha[this -> retornaIndiceNoCabecalho("NM_PROGRAMA_IES")], codigoPPG);
            PPGs.insert({codigoPPG, ppgAtual});
        }

        else {
            ppgAtual = PPGs.find(codigoPPG) -> second;
        }

        this -> PPGs.find(codigoPPG) -> second -> adicionaInstituicao(instituicaoAtual);
        this -> PPGs.find(codigoPPG) -> second -> adicionaProducao(producaoAtual);

        linha = this -> leitor -> proximaLinhaDoArquivo();
    }

}


int Processador::retornaIndiceNoCabecalho(const string &chaveDeBusca) {
    int contador = 0;
    for(auto& iterador : this -> cabecalho) {
        if(iterador == chaveDeBusca) {
            return contador;
        }
        contador++;
    }
    return -1;
}

int Processador::getQuantidadeDeProducoes() {
    int contador = 0;
    for(auto& iterador : this -> PPGs) {
        contador += iterador.second -> retornaTamanhoDaListaDeProducoes();
    }
    return contador;
}

int Processador::retornaQuantidadeDeInstituicoes() {
    return this -> instituicoes.size();
}

int Processador::retornaQuantidadeDePPGs() {
    return this -> PPGs.size();
}

int Processador::retornaQuantidadeDePaginasDeTodasAsPPGs() {
    int paginasTotal = 0;

    for(auto& iterador : this -> PPGs) {
        paginasTotal += iterador.second -> retornaQuantidadeDePaginasTotalDaListaDeProducoes();
    }
    return paginasTotal;
}


int Processador::retornaQuantdadeDproducoesValidasDeTodasAsPPGs() {
    int producoesValidasTotal = 0;

    for(auto& iterador : this -> PPGs) {
        producoesValidasTotal += iterador.second -> retornaQuntidadeDeProducoesComPaginasValidas();
    }
    return producoesValidasTotal;
}

double Processador::retornaMediaDePaginasPorPublicacao() {
    return (double)this -> retornaQuantidadeDePaginasDeTodasAsPPGs() / (double)this -> retornaQuantdadeDproducoesValidasDeTodasAsPPGs();
}

void Processador::mudaCaminhoDoArquivo(const string &novoCaminho) {
    this -> leitor ->setArquivoCsv(novoCaminho);
}

Processador::~Processador() {}

bool comparaPPGs(PPG *ppg1, PPG *ppg2) {
    return stringCompare(ppg1 -> getCodigo(), ppg2 -> getCodigo());
}

void Processador::executaComandoRede() {
    cout << "Programas em rede:" << endl;

    vector<PPG*> ppgsEmRede;

    for(auto& iterator : this -> PPGs) {
        if(iterator.second -> verificaPPGemRede()) {
            iterator.second -> ordenaInstituicoes();
            ppgsEmRede.push_back(iterator.second);
        }
    }
    sort(ppgsEmRede.begin(), ppgsEmRede.end(), comparaPPGs);

    for(auto& iterator : ppgsEmRede) {
        cout << iterator -> getCodigo() << ": " << iterator -> getNome() << endl;
        iterator -> imprimirVetorDInstituicoes();
    }
}

void Processador::teste() {
    int contador = 0;
    for(auto& iterator : this -> PPGs) {
        iterator.second -> imprimirVetorDInstituicoes();
        contador++;
    }
    cout << contador;
}

