#include "../paleta/paleta.h"
#include "imagem.h"
#include <fstream>
#include <string>

using namespace std;

Imagem::Imagem() : largura(0), altura(0), pixels(nullptr) {}

Imagem::Imagem(int largura, int altura) : largura(largura), altura(altura), pixels(nullptr) {
    if (largura > 0 && altura > 0) {
        this->largura = largura;
        this->altura = altura;
        pixels = new Pixel[this->largura * this->altura];

        for (int i = 0; i < this->largura * this->altura; ++i) {
            pixels[i] = {0, 0, 0};
        }
    }
}

Imagem::~Imagem() {
    delete[] pixels;
}

int Imagem::obterLargura() const {
    return largura;
}

int Imagem::obterAltura() const {
    return altura;
}

Pixel Imagem::obterPixel(int x, int y) const {
    if (pixels == nullptr || x < 0 || x >= largura || y < 0 || y >= altura) {
        return {0, 0, 0};
    }
    return pixels[y * largura + x];
}

void Imagem::definePixel(int x, int y, const Pixel& pixel) {
    if (pixels == nullptr || x < 0 || x >= largura || y < 0 || y >= altura) {
        return;
    }
    pixels[y * largura + x] = pixel;
}

bool Imagem::lerPPM(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        return false;
    }

    string formato;
    int novaLargura = 0;
    int novaAltura = 0;
    int valorMaximo = 0;

    if (!(arquivo >> formato) || formato != "P3") {
        return false;
    }

    if (!(arquivo >> novaLargura >> novaAltura >> valorMaximo)){
        return false;
    }

    if (novaLargura <= 0 || novaAltura <= 0 || valorMaximo <= 0) {
        return false;
    }

    if (novaLargura != largura || novaAltura != altura || pixels == nullptr) {
        delete[] pixels;
        largura = novaLargura;
        altura = novaAltura;
        pixels = new Pixel[largura * altura];
    }

    for (int y = 0; y < altura; y++) {
        for (int x = 0; x < largura; x++) {
            int r, g, b;
            if (!(arquivo >> r >> g >> b)) {
                return false;
            }

            if (valorMaximo != 255) {
                r = (r * 255) / valorMaximo;
                g = (g * 255) / valorMaximo;
                b = (b * 255) / valorMaximo;
            }

            pixels[y * largura + x] = {r, g, b};
        }
    }
    
    return true;
}

bool Imagem::salvarPPM(const string& nomeArquivo) const {
    if (pixels == nullptr || largura <= 0 || altura <= 0) {
        return false;
    }
    
    ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        return false;
    }

    arquivo << "P3\n";
    arquivo << largura << " " << altura << "\n";
    arquivo << "255\n";

    for (int y = 0; y < altura; y++) {
        for (int x = 0; x < largura; x++) {
            Pixel pixel = obterPixel(x, y);
            arquivo << pixel.r << " " << pixel.g << " " << pixel.b << "\n";
        }
    }

    arquivo.close();
    return true;
}