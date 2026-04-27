#include "Cadena.h"
#include <ostream>

int Cadena::calcularLongitud(const char* s) {
    if (!s) return 0;
    int l = 0;
    while (s[l] != '\0') l++;
    return l;
}

Cadena::Cadena() : buffer(nullptr), tam(0) {}

Cadena::Cadena(const char* s) {
    tam = calcularLongitud(s);
    if (tam > 0) {
        buffer = new char[tam + 1];
        for (int i = 0; i < tam; i++) buffer[i] = s[i];
        buffer[tam] = '\0';
    } else {
        buffer = nullptr;
    }
}

Cadena::Cadena(const Cadena& otra) {
    tam = otra.tam;
    if (tam > 0) {
        buffer = new char[tam + 1];
        for (int i = 0; i < tam; i++) buffer[i] = otra.buffer[i];
        buffer[tam] = '\0';
    } else {
        buffer = nullptr;
    }
}

Cadena::~Cadena() {
    delete[] buffer;
}

Cadena& Cadena::operator=(const Cadena& otra) {
    if (this != &otra) {
        delete[] buffer;
        tam = otra.tam;
        if (tam > 0) {
            buffer = new char[tam + 1];
            for (int i = 0; i < tam; i++) buffer[i] = otra.buffer[i];
            buffer[tam] = '\0';
        } else {
            buffer = nullptr;
        }
    }
    return *this;
}

Cadena& Cadena::operator=(const char* s) {
    delete[] buffer;
    tam = calcularLongitud(s);
    if (tam > 0) {
        buffer = new char[tam + 1];
        for (int i = 0; i < tam; i++) buffer[i] = s[i];
        buffer[tam] = '\0';
    } else {
        buffer = nullptr;
    }
    return *this;
}

bool Cadena::operator==(const Cadena& otra) const {
    if (tam != otra.tam) return false;
    for (int i = 0; i < tam; i++) {
        if (buffer[i] != otra.buffer[i]) return false;
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Cadena& c) {
    if (c.buffer) os << c.buffer;
    return os;
}
