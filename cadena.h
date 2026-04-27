#ifndef CADENA_H
#define CADENA_H
#include <iostream>

class Cadena {
private:
    char* buffer; // Nombre unificado
    int tam;

public:
    Cadena();
    Cadena(const char* s);
    Cadena(const Cadena& otra);
    ~Cadena();

    int calcularLongitud(const char* s);
    const char* getTexto() const { return buffer; }

    Cadena& operator=(const Cadena& otra);
    Cadena& operator=(const char* s);
    bool operator==(const Cadena& otra) const;
    bool operator==(const char* s) const;

    friend std::ostream& operator<<(std::ostream& os, const Cadena& c);
};

#endif
