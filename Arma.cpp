//
// Created by isabella 18/11/2026.
//

#include "Arma.h"
#include "Jugador.h"
#include <iostream>

Arma::Arma(const std::string& nombre, float peso, int bono)
    : Objeto(nombre, peso) {
    if (bono < 0) {
        this->bonificacionAtaque = 0;
    } else {
        this->bonificacionAtaque = bono;
    }
}

Arma::~Arma() {}

void Arma::usar(Jugador* jugador) {
    if (jugador != nullptr) {
        jugador->aumentarAtaque(this->bonificacionAtaque);
        std::cout << "Se equipa el arma " << this->nombre<< " (+" << this->bonificacionAtaque << " de ataque)." << std::endl;
    }
}

int Arma::getBonificacionAtaque() const {
    return this->bonificacionAtaque;
}
