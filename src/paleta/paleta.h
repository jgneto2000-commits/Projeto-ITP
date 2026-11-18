#pragma once
#include<string>

struct Cor {
  int r;
  int g;
  int b;
};

class Paleta {
private:

  Cor* cores;
  int tamanho;
  int quantidade;

public:

  Paleta(int tamanho = 30);
  Paleta(const std::string& nomeArquivo);
  ~Paleta();
  int obterTamanho() const;
  int obterQuantidade() const;
  void adicionarCor(const Cor& cor);
  Cor obterCor(int indice);

};

