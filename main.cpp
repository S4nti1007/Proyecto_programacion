#include <iostream>
#include <string>
#include "Jugador.h"
#include "Habitacion.h"
#include "Enemigo.h"
#include "Jefe.h"
#include "Arma.h"
#include "Pocion.h"

int main() {
    std::string nombreJugador;
    std::cout << "=== ASCENSO AL OLIMPO ===" << std::endl;
    std::cout << "Ingresa el nombre de tu guerrero: ";
    std::getline(std::cin, nombreJugador);

    if (nombreJugador.empty()) {
        nombreJugador = "Draco";
    }

    Jugador jugador(nombreJugador);

    Habitacion* entrada = new Habitacion(
        "Puertas del Olimpo",
        "Un porton de piedra lleno de niebla donde inicia el ascenso."
    );
    Habitacion* templo = new Habitacion(
        "Templo de la Guerra",
        "Un salon en ruinas custodiado por guerreros caidos."
    );
    Habitacion* cima = new Habitacion(
        "Cima del Olimpo",
        "El trono entre tormentas donde espera el guardian divino."
    );

    entrada->agregarSalida(templo);
    templo->agregarSalida(entrada);
    templo->agregarSalida(cima);
    cima->agregarSalida(templo);

    Enemigo* guardia = new Enemigo("Esqueleto Espartano", 40, 8, 2);
    Enemigo* minotauro = new Enemigo("Minotauro del Templo", 65, 10, 4);
    Arma* espadaOlimpo = new Arma("Espada del Olimpo", 5.5f, 15);
    Jefe* jefeFinal = new Jefe("Ares", 110, 14, 5, espadaOlimpo);

    entrada->agregarEnemigo(guardia);
    templo->agregarEnemigo(minotauro);
    cima->agregarEnemigo(jefeFinal);

    Arma* hachaInicial = new Arma("Hacha de Bronce", 3.5f, 6);
    Pocion* pocion1 = new Pocion("Ambrosia Menor", 1.0f, 35);
    Pocion* pocion2 = new Pocion("Elixir Divino", 1.5f, 50);

    jugador.agregarObjeto(hachaInicial);
    jugador.agregarObjeto(pocion1);
    jugador.agregarObjeto(pocion2);

    jugador.setHabitacionActual(entrada);

    bool jugando = true;
    bool victoria = false;

    while (jugando && jugador.estaVivo()) {
        Habitacion* actual = jugador.getHabitacionActual();
        Enemigo* enemigoActual = actual->getEnemigoActual();

        std::cout << "\n======================================" << std::endl;
        std::cout << "Ubicacion: " << actual->getNombre() << std::endl;
        std::cout << actual->getDescripcion() << std::endl;
        std::cout << "Guerrero: " << jugador.getNombre()
                  << " | Vida: " << jugador.getVida()
                  << " | Ataque: " << jugador.getAtaqueBase() << std::endl;

        if (enemigoActual != nullptr) {
            std::cout << "Enemigo presente: " << enemigoActual->getNombre()
                      << " (Vida: " << enemigoActual->getVida() << ")" << std::endl;
        } else {
            std::cout << "La habitacion esta despejada." << std::endl;
        }

        std::cout << "\n--- ELIGE UNA OPCIoN PARA CONTROLAR ---" << std::endl;
        std::cout << "1. Atacar al enemigo" << std::endl;
        std::cout << "2. Usar objeto del inventario" << std::endl;
        std::cout << "3. Moverse a otra habitacion" << std::endl;
        std::cout << "4. Ver resumen del guerrero" << std::endl;
        std::cout << "5. Salir del juego" << std::endl;
        std::cout << "Elige una opcion: ";

        int opcion= 0;
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                if (enemigoActual == nullptr) {
                    std::cout << "No hay enemigos en esta habitacion." << std::endl;
                } else {
                    jugador.atacar(enemigoActual);

                    if (enemigoActual->estaVivo()) {
                        enemigoActual->atacar(&jugador);
                    } else {
                        actual->eliminarEnemigoDerrotado();

                        if (enemigoActual == jefeFinal) {
                            Arma* botin = jefeFinal->soltarArma();
                            if (botin != nullptr) {
                                if (jugador.agregarObjeto(botin)) {
                                    espadaOlimpo = nullptr;
                                }
                            }
                            victoria = true;
                            jugando = false;
                        }
                    }
                }
                break;
            }

            case 2: {
                if (jugador.getCantidadObjetos() == 0) {
                    std::cout << "Tu inventario esta vacio." << std::endl;
                } else {
                    jugador.mostrarInventario();
                    std::cout << "Elige el numero del objeto a usar: ";
                    int indiceObjeto = -1;
                    std::cin >> indiceObjeto;
                    jugador.usarObjeto(indiceObjeto);
                }
                break;
            }

            case 3: {
                if (!actual->estaDespejada()) {
                    std::cout << "No puedes avanzar mientras haya un enemigo vivo en la habitacion." << std::endl;
                } else {
                    actual->mostrarSalidas();
                    std::cout << "Elige el numero de la salida: ";
                    int indiceSalida = -1;
                    std::cin >> indiceSalida;
                    Habitacion* destino = actual->getSalida(indiceSalida);
                    if (destino != nullptr) {
                        jugador.setHabitacionActual(destino);
                        std::cout << "Te moviste hacia " << destino->getNombre() << "." << std::endl;
                    } else {
                        std::cout << "Salida no valida." << std::endl;
                    }
                }
                break;
            }

            case 4:
                jugador.mostrarResumen();
                break;

            case 5: {
                int confirmar = 0;
                std::cout << "Seguro que deseas salir del juego? (1. Si / 2. No): ";
                std::cin >> confirmar;
                if (confirmar == 1) {
                    jugando = false;
                } else {
                    std::cout << "Continuas tu ascenso al Olimpo." << std::endl;
                }
                break;
            }

            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
        }
    }

    std::cout << "\n======================================" << std::endl;
    if (victoria) {
        std::cout << "VICTORIA! Has conquistado la Cima del Olimpo." << std::endl;
    } else if (!jugador.estaVivo()) {
        std::cout << "DERROTA... no fuiste digno del ascenso al olimpo." << std::endl;
    } else {
        std::cout << "Adios guerrero, el ascenso al olimpo te esperara." << std::endl;
    }

    jugador.mostrarResumen();

    delete guardia;
    delete minotauro;
    delete jefeFinal;

    if (espadaOlimpo != nullptr) {
        delete espadaOlimpo;
    }

    delete entrada;
    delete templo;
    delete cima;

    return 0;
}