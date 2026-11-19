//
// Created by santi on 18/11/2026.
//

#include "Entidad.h"

Entidad::Entidad(const std::string& nombre, int vida, int ataqueBase) {
    this->nombre = nombre;
    if (vida < 0) {
        this->vida = 0;
    } else {
        this->vida = vida;
    }
    if (ataqueBase < 0) {
        this->ataqueBase = 0;
    } else {
        this->ataqueBase = ataqueBase;
    }
}

Entidad::~Entidad() {}

void Entidad::recibirDano(int cantidad) {
    if (cantidad > 0) {
        this->vida -= cantidad;
        if (this->vida < 0) {
            this->vida = 0;
        }
    }
}

bool Entidad::estaVivo() const {
    return this->vida > 0;
}

std::string Entidad::getNombre() const {
    return this->nombre;
}

int Entidad::getVida() const {
    return this->vida;
}

int Entidad::getAtaqueBase() const {
    return this->ataqueBase;
}
