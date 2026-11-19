//
// Created by isabe on 18/11/2026.
//

#include "Arma.h"
#include <iostream>

Arma::Arma(const std::string& nombre, float peso, int bonoAtaque)
    : Objeto(nombre, peso) {
    if (bonoAtaque < 0) {
        this->bonoAtaque = 0;
    } else {
        this->bonoAtaque = bonoAtaque;
    }
}

void Arma::usar(Jugador* jugador) {
    if (jugador != nullptr) {
        std::cout << "Se equipa el arma " << this->nombre
                  << " (+" << this->bonoAtaque << " de ataque)." << std::endl;
    }
}

int Arma::getBonoAtaque() const {
    return this->bonoAtaque;
}
