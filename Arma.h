//
// Created by isabe on 18/11/2026.
//

#ifndef ARMA_H
#define ARMA_H

#include "Objeto.h"

class Arma : public Objeto {
private:
    int bonificacionAtaque;

public:
    Arma(const std::string& nombre, float peso, int bonoAtaque);
    ~Arma() override;

    void usar(Jugador* jugador) override;
    int getBonificacionAtaque() const;
};

#endif
