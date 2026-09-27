//
// Created by igara on 27/09/2026.
//

#include "Libro.h"
#include <iostream>

Libro::Libro() {
    titulo = "vacio";
    autor="vacio";
    categoria = "vacio";
    dni="vacio";
    rentado=0;
}


void Libro::rentar(std::string dni) {
    this->dni = dni;
    rentado=1;
}

void Libro::devolver() {
    dni = "";
    rentado = 0;
}

void Libro::mostrar() {
    std::cout << titulo << " - " << autor << " (" << categoria << ")";
}
