//
// Created by isabe on 18/11/2026.
//

#ifndef POCION_H
#define POCION_H

#include "Objeto.h"

class Pocion : public Objeto {
private:
    int curacion;

public:
    Pocion(const std::string& nombre, float peso, int curacion);
    ~Pocion() override;

    void usar(Jugador* jugador) override;
    int getCuracion() const;
};

#endif