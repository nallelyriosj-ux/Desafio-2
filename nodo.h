#ifndef NODO_H
#define NODO_H

template <class T>
class Nodo {
private:
    T dato;
    Nodo<T>* siguiente;

public:
    Nodo(T d) : dato(d), siguiente(nullptr) {}
    T getDato() { return dato; }
    Nodo<T>* getSiguiente() { return siguiente; }
    void setSiguiente(Nodo<T>* n) { siguiente = n; }
};

#endif
