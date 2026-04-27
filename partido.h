#ifndef PARTIDO_H
#define PARTIDO_H

#include "Equipo.h"

class Partido {
private:
    Equipo* equipoA;
    Equipo* equipoB;
    int golesA;
    int golesB;

public:
    Partido(Equipo* a, Equipo* b);


    void jugar();

    void mostrarResultado();


    int getGolesA() const { return golesA; }
    int getGolesB() const { return golesB; }
};

#endif
