//
// Created by igara on 27/09/2026.
//

#ifndef M21GRUPOSEGUNDOINTENTO_AC1_BIBLIOTECA_H
#define M21GRUPOSEGUNDOINTENTO_AC1_BIBLIOTECA_H
#include "Libro.h"
#include "Usuario.h"
#include "Lista.h"


class Biblioteca {
private:
    Lista<Usuario*> usuarios;
    Lista<Libro*> libros;
    Usuario *buscarUsuario(std::string dni);
    Usuario *pedirUsuario();
    Libro *pedirLibro();
    int pedirNumero();
public:
    Biblioteca();
    ~Biblioteca();
    void mostrarDisponibles();
    void mostrarPorCategoria();
    void mostrarTodos();
    void mostrarUsuarios();
    void registrarUsuario();
    void verHistorial();
    void comprobarLibro();
    void prestar();
    void devolver();

};


#endif //M21GRUPOSEGUNDOINTENTO_AC1_BIBLIOTECA_H
