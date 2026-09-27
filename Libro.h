//
// Created by igara on 27/09/2026.
//

#ifndef M21GRUPOSEGUNDOINTENTO_AC1_LIBRO_H
#define M21GRUPOSEGUNDOINTENTO_AC1_LIBRO_H

#include <string>
class Libro {
private:
    std::string titulo;
    std::string autor;
    std::string categoria;
    std::string dni;
    int rentado;
public:
    Libro();
    Libro(std::string titulo, std::string autor, std::string categoria) {
        this->titulo = titulo;
        this->autor = autor;
        this->categoria = categoria;
        this->dni = "";
        this->rentado = 0;
    }
    std::string getTitulo() {
        return titulo;
    }
    std::string getCategoria() {
        return categoria;
    }
    std::string getDni() {
        return dni;
    }
    int getRentado() {
        return rentado;
    }

    void rentar(std::string dni) ;
    void devolver();
    void mostrar();

};


#endif //M21GRUPOSEGUNDOINTENTO_AC1_LIBRO_H
