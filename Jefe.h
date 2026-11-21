//
// Created by isabe on 21/11/2026.
//

#ifndef JEFE_H
#define JEFE_H

#include "Enemigo.h"
#include "Arma.h"

class Jefe : public Enemigo {
private:
    Arma* armaDivina;

public:
    Jefe(const std::string& nombre, int vida, int ataqueBase, int agresividad, Arma* arma);
    ~Jefe() override;

    void atacar(Entidad* objetivo) override;
    Arma* soltarArma();
};

#endif
