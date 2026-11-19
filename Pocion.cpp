//
// Created by isabe on 18/11/2026.
//

#include "Pocion.h"
#include <iostream>

Pocion::Pocion(const std::string& nombre, float peso, int curacion)
    : Objeto(nombre, peso) {
    if (curacion < 0) {
        this->curacion = 0;
    } else {
        this->curacion = curacion;
    }
}

void Pocion::usar(Jugador* jugador) {
    if (jugador != nullptr) {
        std::cout << "Se bebe la pocion " << this->nombre
                  << " (+" << this->curacion << " de vida)." << std::endl;
    }
}

int Pocion::getCuracion() const {
    return this->curacion;
}
