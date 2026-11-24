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

  Paleta(int tamanho = 30); // Construtor com tamanho padrão de 30 cores
  Paleta(const std::string& nomeArquivo); // Construtor que lê a paleta de um arquivo
  ~Paleta(); // Destrutor
  int obterTamanho() const; // Retorna o tamanho da paleta
  int obterQuantidade() const; // Retorna a quantidade de cores na paleta
  void adicionarCor(const Cor& cor); // Adiciona uma cor à paleta
  Cor obterCor(int indice); // Retorna a cor na posição especificada

};

