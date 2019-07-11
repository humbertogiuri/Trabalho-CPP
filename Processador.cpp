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

            producaoAtual = new Anais(cidade, paginaInical, paginaFinal, 8, natureza, titulo, evento, idioma);
        }

        else if(idSubtipo == "9") { //caso seja artjr

            string titulo = linha[this -> retornaIndiceNoCabecalho("NM_TITULO")];
            string idioma = linha[this -> retornaIndiceNoCabecalho("DS_IDIOMA")];
            string dataDePublicacao = linha[this -> retornaIndiceNoCabecalho("DT_PUBLICACAO")];
            if(!validDate(dataDePublicacao, DATE_FORMAT_PT_BR_SHORT)) {
                dataDePublicacao = "0/00/0000";
            }
            time_t data = parseDate(dataDePublicacao, DATE_FORMAT_PT_BR_SHORT);
            string ISSN = linha[this -> retornaIndiceNoCabecalho("DS_ISSN")];
            string paginaInicial = linha[this -> retornaIndiceNoCabecalho("NR_PAGINA_INICIAL")];
            string paginaFinal = linha[this -> retornaIndiceNoCabecalho("NR_PAGINA_FINAL")];

            producaoAtual = new Artjr(cidade, paginaInicial, paginaFinal, 9, titulo, idioma, data, ISSN);
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

            producaoAtual = new Artpe(cidade, paginaInicial, paginaFinal, 25, natureza, idioma, editora, volume, fasciculo, serie, ISSN);
        }

        else if(idSubtipo == "26") { //caso seja Livro

            string natureza = linha[this -> retornaIndiceNoCabecalho("DS_NATUREZA")];
            string idioma = linha[this -> retornaIndiceNoCabecalho("DS_IDIOMA")];
            string editora = linha[this -> retornaIndiceNoCabecalho("NM_EDITORA")];
            string ISBN = linha[this -> retornaIndiceNoCabecalho("DS_ISBN")];
            string pagina = linha[this -> retornaIndiceNoCabecalho("NR_PAGINAS_CONTRIBUICAO")];
            string titulo = linha[this -> retornaIndiceNoCabecalho("NM_TITULO")];
            string cidadeLivro = linha[this -> retornaIndiceNoCabecalho("NM_CIDADE_PAIS")];

            producaoAtual = new Livro(cidadeLivro, pagina, 26, natureza, idioma, titulo, ISBN, editora);
        }

        else if(idSubtipo == "10") { //caso seja Outro

            string natureza = linha[this -> retornaIndiceNoCabecalho("DS_NATUREZA")];
            string idioma = linha[this -> retornaIndiceNoCabecalho("DS_IDIOMA")];
            string editora = linha[this -> retornaIndiceNoCabecalho("NM_EDITORA")];
            string pagina = linha[this -> retornaIndiceNoCabecalho("NR_PAGINAS")];

            producaoAtual = new Outro(cidade, pagina, 10, natureza, idioma, editora);
        }

        else if(idSubtipo == "28") { //caso seja Partmu

            string natureza = linha[this -> retornaIndiceNoCabecalho("DS_NATUREZA")];
            string formacaoInstrumental = linha[this -> retornaIndiceNoCabecalho("DS_FORMACAO_INSTRUMENTAL")];
            string editora = linha[this -> retornaIndiceNoCabecalho("NM_EDITORA")];
            string pagina = linha[this -> retornaIndiceNoCabecalho("NR_PAGINAS")];

            producaoAtual = new Partmu(cidade, pagina, 28, natureza, editora, formacaoInstrumental);
        }

        else if(idSubtipo == "21") { //caso seja Tradu

            string natureza = linha[this -> retornaIndiceNoCabecalho("DS_NATUREZA")];
            string idioma = linha[this -> retornaIndiceNoCabecalho("DS_IDIOMA")];
            string editora = linha[this -> retornaIndiceNoCabecalho("NM_EDITORA_TRADUCAO")];
            string titulo = linha[this -> retornaIndiceNoCabecalho("NM_TITULO")];
            string idiomaTraducao = linha[this -> retornaIndiceNoCabecalho("DS_IDIOMA_TRADUCAO")];
            string pagina = linha[this -> retornaIndiceNoCabecalho("NR_PAGINAS")];

            producaoAtual = new Tradu(cidade, pagina, 21, titulo, idioma, natureza, editora, idiomaTraducao);
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

        this -> instituicoes.find(nomeFaculdade + sigla) -> second -> adicionaPPG(ppgAtual);

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

Processador::~Processador() {
    delete(this -> leitor);
    for(auto& iterator : this -> PPGs) {
        delete(iterator.second);
    }

    for(auto& iterator : this -> instituicoes) {
        delete(iterator.second);
    }
}

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

void Processador::executaComandoPPG(const string &codigo) {
    if(this -> PPGs.find(codigo) == this -> PPGs.end()) {
        throw ("PPG nao encontrado.");
    }

    PPG* ppgRequerida = this -> PPGs . find(codigo) -> second;
    cout << ppgRequerida;
}

bool comparaInstituicaos(Instituicao *instituicao1, Instituicao *instituicao2) {
    int cmp = instituicao1 -> getSigla().compare(instituicao2 -> getSigla());
    if(cmp < 0) return true; else if(cmp > 0) return false;
    cmp = instituicao1 -> getNome().compare(instituicao2 -> getNome());
    if(cmp < 0) return true; else if(cmp > 0) return false;
    return false;
}

void Processador::executaComandoIES(const string &ies) {
    vector<Instituicao*> instituicoesRequeridas;

    for(auto& iterator : this -> instituicoes) {
        if(iterator.second -> getSigla() == ies) {
            instituicoesRequeridas.push_back((iterator.second));
        }
    }
    if(instituicoesRequeridas.size() == 0) {
        throw("IES nao encontrada.");
    }

    sort(instituicoesRequeridas.begin(), instituicoesRequeridas.end(), comparaInstituicaos);

    for(auto& iterator : instituicoesRequeridas) {
        iterator -> ordenaPPGs();
    }

    for(auto& iterator : instituicoesRequeridas) {
        cout << iterator -> getNome() << " (" << iterator -> getSigla() << "):" << endl;
        iterator -> imprimirPGGsFormatadas();
    }
}

void Processador::executaComandoCsv(const string &codigo, const string &tipoProducao) {
    if(this -> PPGs.find(codigo) == this -> PPGs.end()) {
        throw("PPG nao encontrado.");
    }

    else if(tipoProducao == "anais") {
        cout << "Natureza;Titulo;Idioma;Evento;Cidade;Paginas" << endl;
        this -> executaComandoCsvParticular(codigo, 8);
    }

    else if(tipoProducao == "artjr") {
        cout << "Titulo;Idioma;Cidade;Data;ISSN;Paginas" << endl;
        this -> executaComandoCsvParticular(codigo, 9);
    }
    else if(tipoProducao == "artpe") {
        cout << "Natureza;Idioma;Editora;Cidade;Volume;Fasciculo;Serie;ISSN;Paginas" << endl;
        this -> executaComandoCsvParticular(codigo, 25);
    }
    else if(tipoProducao == "livro") {
        cout << "Natureza;Titulo;Idioma;Editora;Cidade;ISBN;Paginas" << endl;
        this -> executaComandoCsvParticular(codigo, 26);
    }
    else if(tipoProducao == "outro") {
        cout << "Natureza;Idioma;Editora;Cidade;Paginas" << endl;
        this -> executaComandoCsvParticular(codigo, 10);
    }
    else if(tipoProducao == "partmu") {
        cout << "Natureza;Editora;Cidade;Formacao;Paginas" << endl;
        this->executaComandoCsvParticular(codigo, 28);
    }
    else if(tipoProducao == "tradu") {
        cout << "Natureza;Titulo;Idioma;Editora;Cidade;Traducao;Paginas" << endl;
        this->executaComandoCsvParticular(codigo, 21);
    }
    else {
        throw ("Tipo invalido.");
    }
}

void Processador::executaComandoCsvParticular(const string &codigoPPG, const int& id) {

    vector<Producao*> producoes;

    for(auto& iterator : this -> PPGs) {
        if(iterator.second -> getCodigo() == codigoPPG) {
            producoes = iterator.second -> retornaVectorProducaoRequerida(id);
        }
    }

    sort(producoes.begin(), producoes.end(), PPG::comparaProducaoSort);
    for(auto& iterator : producoes) {
        iterator -> print(cout);
    }
}


