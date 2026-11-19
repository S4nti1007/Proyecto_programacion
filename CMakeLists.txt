cmake_minimum_required(VERSION 4.3)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled1 main.cpp
        Entidad.cpp
        Entidad.h
        Objeto.cpp
        Objeto.h
        Arma.cpp
        Arma.h
        Pocion.cpp
        Pocion.h)
