//
// Created by igara on 27/09/2026.
//

#include "Usuario.h"
#include <iostream>

Usuario::Usuario() {
    nombre="vacio";
    apellido="vacio";
    dni="vacio";
}

void Usuario::rentarLibro(Libro *libro) {
    libro->rentar(dni);
    libros.add(libro);
    historial.add(libro);
}

void Usuario::devolverLibro(Libro *libro) {
    for (int i = 0; i < libros.length(); i++) {
        if (libros.at(i) == libro) {
            libros.removeAt(i);
            libro->devolver();
            return;
        }
    }
}

bool Usuario::tieneLibro(Libro *libro) {
    for (int i = 0; i < libros.length(); i++) {
        if (libros.at(i) == libro) {
            return true;
        }
    }
    return false;
}

void Usuario::mostrar() {
    std::cout << nombre << " " << apellido << " - DNI: " << dni << " - Libros prestados: " << libros.length() << std::endl;
}

void Usuario::mostrarLibros() {
    std::cout << "\nLibros que tiene ahora " << nombre << " " << apellido << ":" << std::endl;
    if (libros.length() == 0) {
        std::cout << "Ninguno" << std::endl;
    }
    for (int i = 0; i < libros.length(); i++) {
        std::cout << "- ";
        libros.at(i)->mostrar();
        std::cout << std::endl;
    }
}

void Usuario::mostrarHistorial() {
    std::cout << "\nHistorial de " << nombre << " " << apellido << ":" << std::endl;
    if (historial.length() == 0) {
        std::cout << "Todavia no ha sacado ningun libro" << std::endl;
    }
    for (int i = 0; i < historial.length(); i++) {
        std::cout << "- ";
        historial.at(i)->mostrar();
        std::cout << std::endl;
    }
}
