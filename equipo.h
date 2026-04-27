#ifndef EQUIPO_H
#define EQUIPO_H

#include "Cadena.h"

class Equipo {
private:
    Cadena nombre;
    int puntos;
    int partidosJugados;
    int golesFavor;
    int golesContra;

public:
    Equipo();
    Equipo(Cadena nom);

    void registrarPartido(int misGoles, int golesRival);


    Cadena getNombre() const { return nombre; }
    int getPuntos() const { return puntos; }
    int getDG() const { return golesFavor - golesContra; }
};

#endif
