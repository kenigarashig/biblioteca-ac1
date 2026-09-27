#include <iostream>
#include "Biblioteca.h"

int main() {
    Biblioteca biblioteca;
    int opcion;
    do {
        std::cout << "\n========== BIBLIOTECA ==========" << std::endl;
        std::cout << "1. Ver libros disponibles" << std::endl;
        std::cout << "2. Ver libros por categoria" << std::endl;
        std::cout << "3. Ver todos los libros y quien los tiene" << std::endl;
        std::cout << "4. Sacar un libro" << std::endl;
        std::cout << "5. Devolver un libro" << std::endl;
        std::cout << "6. Ver si un usuario tiene un libro" << std::endl;
        std::cout << "7. Ver historial de un usuario" << std::endl;
        std::cout << "8. Ver usuarios" << std::endl;
        std::cout << "9. Registrar usuario" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            opcion = -1;
        }
        switch (opcion) {
            case 1:
                biblioteca.mostrarDisponibles();
                break;
            case 2:
                biblioteca.mostrarPorCategoria();
                break;
            case 3:
                biblioteca.mostrarTodos();
                break;
            case 4:
                biblioteca.prestar();
                break;
            case 5:
                biblioteca.devolver();
                break;
            case 6:
                biblioteca.comprobarLibro();
                break;
            case 7:
                biblioteca.verHistorial();
                break;
            case 8:
                biblioteca.mostrarUsuarios();
                break;
            case 9:
                biblioteca.registrarUsuario();
                break;
            case 0:
                std::cout << "Hasta luego" << std::endl;
                break;
            default:
                std::cout << "Opcion no valida" << std::endl;
        }
    } while (opcion != 0);
    return 0;
}
