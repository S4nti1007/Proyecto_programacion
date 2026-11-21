//
// Created by isabe on 21/11/2026.
//

#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Entidad.h"

class Enemigo : public Entidad {
private:
    int nivelAgresividad;

public:
    Enemigo(const std::string& nombre, int vida, int ataqueBase, int agresividad);
    ~Enemigo() override;

    void atacar(Entidad* objetivo) override;
    void setNivelAgresividad(int nivel);
    int getNivelAgresividad() const;
};

#endif
