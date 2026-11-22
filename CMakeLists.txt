cmake_minimum_required(VERSION 4.3)
project(Ascenso_al_oLimpo)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ascenso_al_olimpo main.cpp
        Entidad.cpp
        Entidad.h
        Objeto.cpp
        Objeto.h
        Arma.cpp
        Arma.h
        Pocion.cpp
        Pocion.h
        Jugador.cpp
        Jugador.h
        Enemigo.cpp
        Enemigo.h
        Jefe.cpp
        Jefe.h
        Habitacion.cpp
        Habitacion.h)
