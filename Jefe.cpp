//
// Created by isabe on 21/11/2026.
//

#include "Jefe.h"
#include <iostream>

Jefe::Jefe(const std::string& nombre, int vida, int ataqueBase, int agresividad, Arma* arma)
    : Enemigo(nombre, vida, ataqueBase, agresividad) {
    this->armaDivina = arma;
}

Jefe::~Jefe() {
    this->armaDivina = nullptr;
}

void Jefe::atacar(Entidad* objetivo) {
    if (objetivo != nullptr) {
        int dano = this->ataqueBase + this->getNivelAgresividad();

        if (this->armaDivina != nullptr) {
            dano += this->armaDivina->getBonificacionAtaque();
            std::cout << this->nombre << " desata un ataque con "
                      << this->armaDivina->getNombre() << " contra "
                      << objetivo->getNombre() << " causando " << dano
                      << " de dano." << std::endl;
        } else {
            std::cout << this->nombre << " ataca a " << objetivo->getNombre()
                      << " causando " << dano << " de dano." << std::endl;
        }

        objetivo->recibirDano(dano);
    }
}

Arma* Jefe::soltarArma() {
    Arma* armaEntregada = this->armaDivina;
    this->armaDivina = nullptr;
    return armaEntregada;
}