//
// Created by igara on 27/09/2026.
//

#ifndef M21GRUPOSEGUNDOINTENTO_AC1_LISTA_H
#define M21GRUPOSEGUNDOINTENTO_AC1_LISTA_H

#include <stdexcept>


template <typename T>
class Lista {
private:
    static const int CAPACIDAD = 50;
    T almacen[CAPACIDAD];
    int count;
    void comprobarPosicion(int position) const;

public:
    Lista();
    bool add(const T& nuevo);
    T remove();
    T removeAt(int position);
    T& at(int position);
    const T& at(int position) const;

    int length() const;
};

template <typename T>
Lista<T>::Lista() {
    count = 0;
}

template <typename T>
void Lista<T>::comprobarPosicion(int position) const {
    if (position < 0 || position >= count) {
        throw std::out_of_range("Lista: posicion fuera de rango");
    }
}

template <typename T>
bool Lista<T>::add(const T& nuevo) {
    if (count >= CAPACIDAD) {
        return false;
    }
    almacen[count] = nuevo;
    count++;
    return true;
}

template <typename T>
T Lista<T>::remove() {
    if (count == 0) {
        throw std::out_of_range("Lista: la lista esta vacia");
    }
    count--;
    return almacen[count];
}

template <typename T>
T Lista<T>::removeAt(int position) {
    comprobarPosicion(position);
    T quitado = almacen[position];
    for (int i = position; i < count - 1; i++) {
        almacen[i] = almacen[i + 1];
    }
    count--;
    return quitado;
}

template <typename T>
T& Lista<T>::at(int position) {
    comprobarPosicion(position);
    return almacen[position];
}

template <typename T>
const T& Lista<T>::at(int position) const {
    comprobarPosicion(position);
    return almacen[position];
}

template <typename T>
int Lista<T>::length() const {
    return count;
}

#endif