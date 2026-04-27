#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

template <class T>
class Lista {
private:
    Nodo<T>* primero;
    Nodo<T>* ultimo;
    int tamano;

public:
    Lista() : primero(nullptr), ultimo(nullptr), tamano(0) {}

    // Para forzar a United States al inicio
    void insertarAlInicio(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (!primero) {
            primero = ultimo = nuevo;
        } else {
            nuevo->setSiguiente(primero);
            primero = nuevo;
        }
        tamano++;
    }

    void insertarAlFinal(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (!primero) {
            primero = ultimo = nuevo;
        } else {
            ultimo->setSiguiente(nuevo);
            ultimo = nuevo;
        }
        tamano++;
    }

    // Para el sorteo aleatorio
    T obtener(int indice) {
        if (indice < 0 || indice >= tamano) return nullptr;
        Nodo<T>* actual = primero;
        for (int i = 0; i < indice; i++) actual = actual->getSiguiente();
        return actual->getDato();
    }

    int getTamano() const { return tamano; }
    ~Lista() { /* Código para liberar memoria */ }
};

#endif
