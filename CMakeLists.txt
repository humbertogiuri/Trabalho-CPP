cmake_minimum_required(VERSION 3.14)
project(TrabalhoC__)

set(CMAKE_CXX_STANDARD 14)

add_executable(TrabalhoC__ main.cpp LeitorCsv.cpp LeitorCsv.h Tokenizer.h Tokenizer.cpp Processador.cpp Processador.h Instituicao.cpp Instituicao.h PPG.cpp PPG.h Producao.cpp Producao.h Anais.cpp Anais.h Artjr.cpp Artjr.h Artpe.cpp Artpe.h Livro.cpp Livro.h Outro.cpp Outro.h Partmu.cpp Partmu.h Tradu.cpp Tradu.h NumberUtils.cpp NumberUtils.h NumPunctPTBR.cpp NumPunctPTBR.h StringUtils.cpp StringUtils.h DateUtils.cpp DateUtils.cpp)