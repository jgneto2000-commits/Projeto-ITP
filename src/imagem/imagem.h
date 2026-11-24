#pragma once

#include "../paleta/paleta.h"
#include <string>

using Pixel = Cor;

class Imagem {
 private:
  int largura;
  int altura;
  Pixel* pixels;
 public:
  Imagem(); // Construtor padrão
  Imagem(int largura, int altura); // Construtor com parâmetros
  ~Imagem(); // Destrutor
  void definePixel(int x, int y, const Pixel& pixel); // Define o pixel na posição (x, y) com a cor especificada
  Pixel obterPixel(int x, int y) const; // Retorna o pixel na posição (x, y)
  int obterLargura() const; // Retorna a largura da imagem
  int obterAltura() const; // Retorna a altura da imagem
  bool lerPPM(const std::string& nomeArquivo); // Lê uma imagem no formato PPM a partir do arquivo especificado
  bool salvarPPM(const std::string& nomeArquivo) const; // Salva a imagem no formato PPM no arquivo especificado
};
