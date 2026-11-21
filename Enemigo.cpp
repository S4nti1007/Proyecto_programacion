//
// Created by isabe on 21/11/2026.
//

#include "Enemigo.h"
#include <iostream>

Enemigo::Enemigo(const std::string& nombre, int vida, int ataqueBase, int agresividad)
    : Entidad(nombre, vida, ataqueBase) {
    this->setNivelAgresividad(agresividad);
}

Enemigo::~Enemigo() {}

void Enemigo::atacar(Entidad* objetivo) {
    if (objetivo != nullptr) {
        int dano = this->ataqueBase + this->nivelAgresividad;
        std::cout << this->nombre << " ataca a " << objetivo->getNombre()
                  << " causando " << dano << " de dano." << std::endl;
        objetivo->recibirDano(dano);
    }
}

void Enemigo::setNivelAgresividad(int nivel) {
    if (nivel < 1) {
        this->nivelAgresividad = 1;
    } else {
        this->nivelAgresividad = nivel;
    }
}

int Enemigo::getNivelAgresividad() const {
    return this->nivelAgresividad;
}