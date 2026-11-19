//
// Created by santi on 18/11/2026.
//

#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <string>

class Entidad {
protected:
    std::string nombre;
    int vida;
    int ataqueBase;

public:
    Entidad(const std::string& nombre, int vida, int ataqueBase);
    virtual ~Entidad();

    virtual void atacar(Entidad* objetivo) = 0;
    virtual void recibirDano(int cantidad);

    bool estaVivo() const;
    std::string getNombre() const;
    int getVida() const;
    int getAtaqueBase() const;
};

#endif
