//
// Created by igara on 27/09/2026.
//

#ifndef M21GRUPOSEGUNDOINTENTO_AC1_USUARIO_H
#define M21GRUPOSEGUNDOINTENTO_AC1_USUARIO_H
#include <string>
#include "Libro.h"
#include "Lista.h"

class Usuario {
private:
    std::string nombre;
    std::string apellido;
    std::string dni;
    Lista<Libro*> libros;
    Lista<Libro*> historial;
public:
    Usuario();
    Usuario(std::string nombre, std::string apellido,std::string dni):nombre(nombre),apellido(apellido),dni(dni) {}
    std::string getNombre() {
        return nombre;
    }
    std::string getApellido() {
        return apellido;
    }
    std::string getDni() {
        return dni;
    }
    void rentarLibro(Libro *libro);
    void devolverLibro(Libro *libro);
    bool tieneLibro(Libro *libro);
    void mostrar();
    void mostrarLibros();
    void mostrarHistorial();

};


#endif //M21GRUPOSEGUNDOINTENTO_AC1_USUARIO_H
