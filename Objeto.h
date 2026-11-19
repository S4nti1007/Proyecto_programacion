//
// Created by santi on 18/11/2026.
//

#ifndef OBJETO_H
#define OBJETO_H

#include <string>

class Jugador;

class Objeto {
protected:
    std::string nombre;
    float peso;

public:
    Objeto(const std::string& nombre, float peso);
    virtual ~Objeto();

    virtual void usar(Jugador* jugador) = 0;

    std::string getNombre() const;
    float getPeso() const;
};

#endif
