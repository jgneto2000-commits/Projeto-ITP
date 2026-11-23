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
  Imagem();
  Imagem(int largura, int altura);
  ~Imagem();
  void definePixel(int x, int y, const Pixel& pixel);
  Pixel obterPixel(int x, int y) const;
  int obterLargura() const;
  int obterAltura() const;
  bool lerPPM(const std::string& nomeArquivo);
  bool salvarPPM(const std::string& nomeArquivo) const;
};
