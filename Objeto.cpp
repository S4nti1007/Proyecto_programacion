//
// Created by santi on 18/11/2026.
//

#include "Objeto.h"

Objeto::Objeto(const std::string& nombre, float peso) {
    this->nombre = nombre;
    if (peso < 0) {
        this->peso = 0;
    } else {
        this->peso = peso;
    }
}

Objeto::~Objeto() {}

std::string Objeto::getNombre() const {
    return this->nombre;
}

float Objeto::getPeso() const {
    return this->peso;
}
