//
// Created by isabe on 21/11/2026.
//

#ifndef HABITACION_H
#define HABITACION_H

#include <string>
#include <vector>
#include "Enemigo.h"

class Habitacion {
private:
    std::string nombre;
    std::string descripcion;
    std::vector<Enemigo*> enemigos;
    std::vector<Habitacion*> salidas;

public:
    Habitacion(const std::string& nombre, const std::string& descripcion);
    ~Habitacion();

    void agregarEnemigo(Enemigo* enemigo);
    void eliminarEnemigoDerrotado();
    bool estaDespejada() const;
    Enemigo* getEnemigoActual() const;

    void agregarSalida(Habitacion* destino);
    void mostrarSalidas() const;
    Habitacion* getSalida(int indice) const;
    int getCantidadSalidas() const;

    std::string getNombre() const;
    std::string getDescripcion() const;
};

#endif