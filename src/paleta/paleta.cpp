#include "paleta.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int limitar(int val) {
    return max(0, min(255, val));
}

Paleta::Paleta(int tamanho) {
    this->tamanho = tamanho;
    quantidade = 0;
    cores = new Cor[this->tamanho];
}

Paleta::Paleta(const string& nomeArquivo) {
    tamanho = 30;
    quantidade = 0;
    cores = new Cor[tamanho];

    ifstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
    string linha;
    while (getline(arquivo, linha)) { 
        if (!linha.empty() && linha[0] == '#') {
            if (linha.length() >= 7) {
                int r = stoi(linha.substr(1, 2), nullptr, 16);
                int g = stoi(linha.substr(3, 2), nullptr, 16);
                int b = stoi(linha.substr(5, 2), nullptr, 16);

                adicionarCor(Cor{r, g, b});
            }
        }
    }
    arquivo.close();
}
    
}

Paleta::~Paleta() {
    delete[] cores;
}

int Paleta::obterTamanho() const {
    return tamanho;
}

int Paleta::obterQuantidade() const {
    return quantidade;
}

void Paleta::adicionarCor(const Cor& cor) {
    if (quantidade < tamanho) {
        cores[quantidade] = {
            limitar(cor.r),
            limitar(cor.g),
            limitar(cor.b)
        };
        quantidade++;
    }
}
Cor Paleta::obterCor(int indice) {
    if (indice < 0 || indice >= quantidade) {
        return {0, 0, 0}; 
    }
    return cores[indice];
}
//teste