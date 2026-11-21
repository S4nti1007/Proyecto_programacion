//
// Created by isabe on 21/11/2026.
//

#include "Habitacion.h"
#include <iostream>

Habitacion::Habitacion(const std::string& nombre, const std::string& descripcion) {
    this->nombre = nombre;
    this->descripcion = descripcion;
}

Habitacion::~Habitacion() {
    // Agregacion: la Habitacion no destruye los enemigos ni las otras habitaciones (no se hace delete)
    this->enemigos.clear();
    this->salidas.clear();
}

void Habitacion::agregarEnemigo(Enemigo* enemigo) {
    if (enemigo != nullptr) {
        this->enemigos.push_back(enemigo);
    }
}

void Habitacion::eliminarEnemigoDerrotado() {
    std::vector<Enemigo*> enemigosVivos;
    for (int i = 0; i < this->enemigos.size(); i++) {
        if (this->enemigos[i] != nullptr && this->enemigos[i]->estaVivo()) {
            enemigosVivos.push_back(this->enemigos[i]);
        }
    }
    this->enemigos = enemigosVivos;
}

bool Habitacion::estaDespejada() const {
    for (int i = 0; i < this->enemigos.size(); i++) {
        if (this->enemigos[i] != nullptr && this->enemigos[i]->estaVivo()) {
            return false;
        }
    }
    return true;
}

Enemigo* Habitacion::getEnemigoActual() const {
    for (int i = 0; i < this->enemigos.size(); i++) {
        if (this->enemigos[i] != nullptr && this->enemigos[i]->estaVivo()) {
            return this->enemigos[i];
        }
    }
    return nullptr;
}

void Habitacion::agregarSalida(Habitacion* destino) {
    if (destino != nullptr) {
        this->salidas.push_back(destino);
    }
}

void Habitacion::mostrarSalidas() const {
    if (this->salidas.empty()) {
        std::cout << "No hay salidas disponibles desde esta habitacion." << std::endl;
        return;
    }
    std::cout << "--- Salidas desde " << this->nombre << " ---" << std::endl;
    for (int i = 0; i < this->salidas.size(); i++) {
        std::cout << i << ". " << this->salidas[i]->getNombre() << std::endl;
    }
}

Habitacion* Habitacion::getSalida(int indice) const {
    if (indice >= 0 && indice < this->salidas.size()) {
        return this->salidas[indice];
    }
    return nullptr;
}

int Habitacion::getCantidadSalidas() const {
    return this->salidas.size();
}

std::string Habitacion::getNombre() const {
    return this->nombre;
}

std::string Habitacion::getDescripcion() const {
    return this->descripcion;
}