# Biblioteca

Sistema de gestión de una biblioteca pública hecho en C++ como aplicación de consola. Permite consultar el catálogo, prestar y devolver libros, saber quién tiene cada libro y ver el historial de cada usuario.

Proyecto de la **Actividad Colaborativa 1** de *Programación con estructuras lineales* (Grado en Ingeniería Informática, curso 2026-2027).

## Contexto

La biblioteca llevaba los préstamos en hojas de Excel, en un ordenador con Windows XP, así que era difícil saber qué libros estaban prestados, quién los tenía o qué había leído cada persona. Este programa sustituye ese sistema.

## Funcionalidades

El programa funciona con un menú:

| Opción | Qué hace |
|:---:|---|
| 1 | Ver los libros disponibles |
| 2 | Ver los libros de una categoría, indicando si están disponibles o prestados |
| 3 | Ver todos los libros y quién tiene cada uno |
| 4 | Sacar un libro (préstamo) |
| 5 | Devolver un libro |
| 6 | Comprobar si un usuario tiene un libro concreto |
| 7 | Ver los libros que tiene un usuario y su historial |
| 8 | Ver los usuarios registrados |
| 9 | Registrar un usuario nuevo |
| 0 | Salir |

El catálogo trae **25 libros** repartidos en cinco categorías (Acción, Aventuras, Drama, Comedia y Romanticismo) y **5 usuarios de prueba**. Los usuarios se identifican por su DNI. Los de prueba tienen DNI ficticios, por ejemplo `12345678A` (Ana García López).

## Estructura del proyecto

```
├── main.cpp             Menú principal
├── Biblioteca.h / .cpp  Catálogo, usuarios y operaciones del menú
├── Libro.h / .cpp       Datos de un libro y su estado de préstamo
├── Usuario.h / .cpp     Datos del usuario, libros que tiene e historial
├── Lista.h              Plantilla Lista<T> (lista secuencial)
└── CMakeLists.txt       Configuración de compilación
```

### Clases

- **`Libro`**: título, autor, categoría, si está prestado (`rentado`) y el DNI de quien lo tiene. Métodos `rentar()`, `devolver()` y `mostrar()`.
- **`Usuario`**: nombre, apellidos y DNI. Tiene dos listas: los libros que tiene ahora (`libros`) y todos los que ha sacado (`historial`).
- **`Biblioteca`**: guarda los libros y los usuarios en memoria dinámica (se crean con `new` y el destructor los libera). Contiene todas las operaciones del menú.
- **`Lista<T>`**: plantilla propia de lista secuencial sobre un array de capacidad fija (50 elementos), con `add`, `remove`, `removeAt`, `at` y `length`. Lanza `std::out_of_range` si se pide una posición que no existe. Se usa en lugar de los contenedores de la biblioteca estándar (`vector`, `list`…).

## Conceptos aplicados

Clases y encapsulación, constructores y destructores, punteros y memoria dinámica, plantillas, estructuras lineales (lista secuencial) y compilación separada.

## Requisitos

- Compilador de C++ compatible con **C++20** (por ejemplo, MinGW g++ 14, GCC o Clang).
- **CMake 4.0** o superior (el que trae CLion 2025.2).

## Compilar y ejecutar

**Con CLion:** abre la carpeta del proyecto (*File → Open*), espera a que cargue CMake y pulsa *Run*.

**Desde la terminal:**

```bash
cmake -S . -B build
cmake --build build
./build/M21GrupoSegundoIntento_AC1
```

En Windows con MinGW, añade `-G "MinGW Makefiles"` al primer comando. El ejecutable queda en `build\M21GrupoSegundoIntento_AC1.exe`.

## Ejemplo de uso

Préstamo de un libro a la usuaria de prueba con DNI `12345678A`:

```
========== BIBLIOTECA ==========
1. Ver libros disponibles
...
0. Salir
Opcion: 4
DNI del usuario: 12345678A

--- Libros disponibles ---
1. La identidad de Bourne - Robert Ludlum (Accion)
2. Casino Royale - Ian Fleming (Accion)
...
Numero del libro: 1
Se ha prestado La identidad de Bourne a Ana Garcia Lopez
```

## Documentación

La memoria del proyecto (análisis del enunciado, diseño, manual de uso y pruebas) se entrega aparte y no forma parte del repositorio.
