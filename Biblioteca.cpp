//
// Created by igara on 27/09/2026.
//

#include "Biblioteca.h"
#include <iostream>

Biblioteca::Biblioteca() {
    libros.add(new Libro("La identidad de Bourne", "Robert Ludlum", "Accion"));
    libros.add(new Libro("Casino Royale", "Ian Fleming", "Accion"));
    libros.add(new Libro("Los juegos del hambre", "Suzanne Collins", "Accion"));
    libros.add(new Libro("El codigo Da Vinci", "Dan Brown", "Accion"));
    libros.add(new Libro("Jurassic Park", "Michael Crichton", "Accion"));
    libros.add(new Libro("La isla del tesoro", "Robert Louis Stevenson", "Aventuras"));
    libros.add(new Libro("Viaje al centro de la Tierra", "Julio Verne", "Aventuras"));
    libros.add(new Libro("La vuelta al mundo en 80 dias", "Julio Verne", "Aventuras"));
    libros.add(new Libro("Robinson Crusoe", "Daniel Defoe", "Aventuras"));
    libros.add(new Libro("El Hobbit", "J.R.R. Tolkien", "Aventuras"));
    libros.add(new Libro("La casa de Bernarda Alba", "Federico Garcia Lorca", "Drama"));
    libros.add(new Libro("Bodas de sangre", "Federico Garcia Lorca", "Drama"));
    libros.add(new Libro("Hamlet", "William Shakespeare", "Drama"));
    libros.add(new Libro("Muerte de un viajante", "Arthur Miller", "Drama"));
    libros.add(new Libro("Los miserables", "Victor Hugo", "Drama"));
    libros.add(new Libro("Don Quijote de la Mancha", "Miguel de Cervantes", "Comedia"));
    libros.add(new Libro("La conjura de los necios", "John Kennedy Toole", "Comedia"));
    libros.add(new Libro("Sin noticias de Gurb", "Eduardo Mendoza", "Comedia"));
    libros.add(new Libro("Guia del autoestopista galactico", "Douglas Adams", "Comedia"));
    libros.add(new Libro("La importancia de llamarse Ernesto", "Oscar Wilde", "Comedia"));
    libros.add(new Libro("Orgullo y prejuicio", "Jane Austen", "Romanticismo"));
    libros.add(new Libro("Romeo y Julieta", "William Shakespeare", "Romanticismo"));
    libros.add(new Libro("Cumbres borrascosas", "Emily Bronte", "Romanticismo"));
    libros.add(new Libro("Rimas y leyendas", "Gustavo Adolfo Becquer", "Romanticismo"));
    libros.add(new Libro("Don Juan Tenorio", "Jose Zorrilla", "Romanticismo"));

    usuarios.add(new Usuario("Ana", "Garcia Lopez", "12345678A"));
    usuarios.add(new Usuario("Carlos", "Martinez Ruiz", "23456789B"));
    usuarios.add(new Usuario("Lucia", "Fernandez Gomez", "34567890C"));
    usuarios.add(new Usuario("Javier", "Sanchez Diaz", "45678901D"));
    usuarios.add(new Usuario("Marta", "Romero Navarro", "56789012E"));
}

Biblioteca::~Biblioteca() {
    for (int i = 0; i < libros.length(); i++) {
        delete libros.at(i);
    }
    for (int i = 0; i < usuarios.length(); i++) {
        delete usuarios.at(i);
    }
}

Usuario *Biblioteca::buscarUsuario(std::string dni) {
    for (int i = 0; i < usuarios.length(); i++) {
        if (usuarios.at(i)->getDni() == dni) {
            return usuarios.at(i);
        }
    }
    return nullptr;
}

Usuario *Biblioteca::pedirUsuario() {
    std::string dni;
    std::cout << "DNI del usuario: ";
    std::cin >> dni;
    Usuario *usuario = buscarUsuario(dni);
    if (usuario == nullptr) {
        std::cout << "No hay ningun usuario con ese DNI" << std::endl;
    }
    return usuario;
}

int Biblioteca::pedirNumero() {
    int numero;
    std::cin >> numero;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return -1;
    }
    return numero;
}

Libro *Biblioteca::pedirLibro() {
    std::cout << "Numero del libro: ";
    int numero = pedirNumero();
    if (numero < 1 || numero > libros.length()) {
        std::cout << "No existe ningun libro con ese numero" << std::endl;
        return nullptr;
    }
    return libros.at(numero - 1);
}

void Biblioteca::mostrarDisponibles() {
    std::cout << "\n--- Libros disponibles ---" << std::endl;
    int cuantos = 0;
    for (int i = 0; i < libros.length(); i++) {
        if (libros.at(i)->getRentado() == 0) {
            std::cout << i + 1 << ". ";
            libros.at(i)->mostrar();
            std::cout << std::endl;
            cuantos++;
        }
    }
    if (cuantos == 0) {
        std::cout << "No hay libros disponibles" << std::endl;
    }
}

void Biblioteca::mostrarPorCategoria() {
    Lista<std::string> categorias;
    for (int i = 0; i < libros.length(); i++) {
        bool repetida = false;
        for (int j = 0; j < categorias.length(); j++) {
            if (categorias.at(j) == libros.at(i)->getCategoria()) {
                repetida = true;
            }
        }
        if (!repetida) {
            categorias.add(libros.at(i)->getCategoria());
        }
    }
    std::cout << "\n--- Categorias ---" << std::endl;
    for (int i = 0; i < categorias.length(); i++) {
        std::cout << i + 1 << ". " << categorias.at(i) << std::endl;
    }
    std::cout << "Elige una categoria: ";
    int opcion = pedirNumero();
    if (opcion < 1 || opcion > categorias.length()) {
        std::cout << "Categoria no valida" << std::endl;
        return;
    }
    std::string categoria = categorias.at(opcion - 1);
    std::cout << "\n--- " << categoria << " ---" << std::endl;
    for (int i = 0; i < libros.length(); i++) {
        if (libros.at(i)->getCategoria() == categoria) {
            std::cout << i + 1 << ". ";
            libros.at(i)->mostrar();
            if (libros.at(i)->getRentado() == 0) {
                std::cout << " -> Disponible" << std::endl;
            } else {
                std::cout << " -> Prestado" << std::endl;
            }
        }
    }
}

void Biblioteca::mostrarTodos() {
    std::cout << "\n--- Todos los libros ---" << std::endl;
    for (int i = 0; i < libros.length(); i++) {
        std::cout << i + 1 << ". ";
        libros.at(i)->mostrar();
        if (libros.at(i)->getRentado() == 0) {
            std::cout << " -> Disponible" << std::endl;
        } else {
            Usuario *usuario = buscarUsuario(libros.at(i)->getDni());
            std::cout << " -> Lo tiene " << usuario->getNombre() << " " << usuario->getApellido() << std::endl;
        }
    }
}

void Biblioteca::mostrarUsuarios() {
    std::cout << "\n--- Usuarios ---" << std::endl;
    for (int i = 0; i < usuarios.length(); i++) {
        usuarios.at(i)->mostrar();
    }
}

void Biblioteca::registrarUsuario() {
    std::string nombre;
    std::string apellido;
    std::string dni;
    std::cout << "DNI: ";
    std::cin >> dni;
    if (buscarUsuario(dni) != nullptr) {
        std::cout << "Ya existe un usuario con ese DNI" << std::endl;
        return;
    }
    std::cin.ignore(1000, '\n');
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Apellidos: ";
    std::getline(std::cin, apellido);
    Usuario *usuario = new Usuario(nombre, apellido, dni);
    if (!usuarios.add(usuario)) {
        delete usuario;
        std::cout << "No caben mas usuarios" << std::endl;
        return;
    }
    std::cout << "Usuario registrado correctamente" << std::endl;
}

void Biblioteca::verHistorial() {
    Usuario *usuario = pedirUsuario();
    if (usuario == nullptr) {
        return;
    }
    usuario->mostrarLibros();
    usuario->mostrarHistorial();
}

void Biblioteca::comprobarLibro() {
    Usuario *usuario = pedirUsuario();
    if (usuario == nullptr) {
        return;
    }
    mostrarTodos();
    Libro *libro = pedirLibro();
    if (libro == nullptr) {
        return;
    }
    if (usuario->tieneLibro(libro)) {
        std::cout << usuario->getNombre() << " SI tiene " << libro->getTitulo() << std::endl;
    } else {
        std::cout << usuario->getNombre() << " NO tiene " << libro->getTitulo() << std::endl;
    }
}

void Biblioteca::prestar() {
    Usuario *usuario = pedirUsuario();
    if (usuario == nullptr) {
        return;
    }
    mostrarDisponibles();
    Libro *libro = pedirLibro();
    if (libro == nullptr) {
        return;
    }
    if (libro->getRentado() == 1) {
        std::cout << "Ese libro no esta disponible" << std::endl;
        return;
    }
    usuario->rentarLibro(libro);
    std::cout << "Se ha prestado " << libro->getTitulo() << " a " << usuario->getNombre() << " " << usuario->getApellido() << std::endl;
}

void Biblioteca::devolver() {
    Usuario *usuario = pedirUsuario();
    if (usuario == nullptr) {
        return;
    }
    std::cout << "\n--- Libros de " << usuario->getNombre() << " ---" << std::endl;
    int cuantos = 0;
    for (int i = 0; i < libros.length(); i++) {
        if (usuario->tieneLibro(libros.at(i))) {
            std::cout << i + 1 << ". ";
            libros.at(i)->mostrar();
            std::cout << std::endl;
            cuantos++;
        }
    }
    if (cuantos == 0) {
        std::cout << "No tiene ningun libro para devolver" << std::endl;
        return;
    }
    Libro *libro = pedirLibro();
    if (libro == nullptr) {
        return;
    }
    if (!usuario->tieneLibro(libro)) {
        std::cout << usuario->getNombre() << " no tiene ese libro" << std::endl;
        return;
    }
    usuario->devolverLibro(libro);
    std::cout << "Se ha devuelto " << libro->getTitulo() << std::endl;
}
