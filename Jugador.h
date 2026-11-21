//
// Created by santi on 21/11/2026.
//

#ifndef JUGADOR_H
#define JUGADOR_H

#include "Entidad.h"
#include "Objeto.h"
#include <vector>

class Habitacion;

class Jugador : public Entidad {
private:
    int experiencia;
    int danoTotalInfligido;
    int enemigosDerrotados;
    std::vector<Objeto*> inventario;
    Habitacion* habitacionActual;

public:
    Jugador(const std::string& nombre);
    ~Jugador() override;

    void atacar(Entidad* objetivo) override;
    bool agregarObjeto(Objeto* objeto);
    void usarObjeto(int indice);
    void subirNivel();
    void mostrarResumen() const;

    void curar(int cantidad);
    void aumentarAtaque(int cantidad);
    void setHabitacionActual(Habitacion* habitacion);
    Habitacion* getHabitacionActual() const;
    void mostrarInventario() const;
    int getCantidadObjetos() const;

    int getExperiencia() const;
    int getDanoTotalInfligido() const;
    int getEnemigosDerrotados() const;
};

#endif
