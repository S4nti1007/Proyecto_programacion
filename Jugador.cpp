//
// Created by santi on 21/11/2026.
//

#include "Jugador.h"
#include <iostream>

Jugador::Jugador(const std::string& nombre) : Entidad(nombre, 100, 15) {
    this->experiencia = 0;
    this->danoTotalInfligido = 0;
    this->enemigosDerrotados = 0;
    this->habitacionActual = nullptr;
}

Jugador::~Jugador() {
    for (int i = 0; i < this->inventario.size(); i++) {
        delete this->inventario[i];
    }
    this->inventario.clear();
}

void Jugador::atacar(Entidad* objetivo) {
    if (objetivo != nullptr && objetivo->estaVivo()) {
        objetivo->recibirDano(this->ataqueBase);
        this->danoTotalInfligido += this->ataqueBase;
        std::cout << this->nombre << " ataca a " << objetivo->getNombre() << " causando " << this->ataqueBase << " de dano." << std::endl;

        if (!objetivo->estaVivo()) {
            this->enemigosDerrotados++;
            this->experiencia += 50;
            std::cout << objetivo->getNombre() << " Ha sido derrotado! Ganas 50 de experiencia." << std::endl;
            if (this->experiencia % 100 == 0) {
                this->subirNivel();
            }
        }
    }
}

bool Jugador::agregarObjeto(Objeto* objeto) {
    if (objeto == nullptr) {
        return false;
    }
    if (this->inventario.size() >= 4) {
        std::cout << "Inventario lleno (maximo 4 objetos). No se pudo agregar " << objeto->getNombre() << "." << std::endl;
        return false;
    }
    this->inventario.push_back(objeto);
    std::cout << "Se agrego " << objeto->getNombre() << " al inventario." << std::endl;
    return true;
}

void Jugador::usarObjeto(int indice) {
    if (indice < 0 || indice >= this->inventario.size()) {
        std::cout << "Indice de objeto invalido." << std::endl;
        return;
    }
    Objeto* objeto = this->inventario[indice];
    objeto->usar(this);
    delete objeto;
    this->inventario.erase(this->inventario.begin() + indice);
}

void Jugador::subirNivel() {
    this->vida += 20;
    this->ataqueBase += 5;
    std::cout << this->nombre << " ha subido de nivel! (+20 de vida, +5 de ataque base)." << std::endl;
}

void Jugador::mostrarResumen() const {
    std::cout << "=== RESUMEN FINAL DE " << this->nombre << " ===" << std::endl;
    std::cout << "Vida restante: " << this->vida << std::endl;
    std::cout << "Ataque base final: " << this->ataqueBase << std::endl;
    std::cout << "Experiencia total ganada: " << this->experiencia << std::endl;
    std::cout << "Enemigos derrotados: " << this->enemigosDerrotados << std::endl;
    std::cout << "Dano total infligido: " << this->danoTotalInfligido << std::endl;
}

void Jugador::curar(int cantidad) {
    if (cantidad > 0) {
        this->vida += cantidad;
    }
}

void Jugador::aumentarAtaque(int cantidad) {
    if (cantidad > 0) {
        this->ataqueBase += cantidad;
    }
}

void Jugador::setHabitacionActual(Habitacion* habitacion) {
    this->habitacionActual = habitacion;
}

Habitacion* Jugador::getHabitacionActual() const {
    return this->habitacionActual;
}

void Jugador::mostrarInventario() const {
    if (this->inventario.empty()) {
        std::cout << "El inventario esta vacio." << std::endl;
        return;
    }
    std::cout << "--- Inventario (" << this->inventario.size() << "/4) ---" << std::endl;
    for (int i = 0; i < this->inventario.size(); i++) {
        std::cout << i << ". " << this->inventario[i]->getNombre() << " (Peso: " << this->inventario[i]->getPeso() << ")" << std::endl;
    }
}

int Jugador::getCantidadObjetos() const {
    return this->inventario.size();
}

int Jugador::getExperiencia() const {
    return this->experiencia;
}

int Jugador::getDanoTotalInfligido() const {
    return this->danoTotalInfligido;
}

int Jugador::getEnemigosDerrotados() const {
    return this->enemigosDerrotados;
}
