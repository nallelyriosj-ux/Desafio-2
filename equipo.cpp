#include "Equipo.h"


Equipo::Equipo() : nombre(""), puntos(0), partidosJugados(0), golesFavor(0), golesContra(0) {}


Equipo::Equipo(Cadena nom) : nombre(nom), puntos(0), partidosJugados(0), golesFavor(0), golesContra(0) {}


void Equipo::registrarPartido(int misGoles, int golesRival) {
    partidosJugados++;
    golesFavor += misGoles;
    golesContra += golesRival;

    if (misGoles > golesRival) {
        puntos += 3;
    }
    else if (misGoles == golesRival) {
        puntos += 1;
    }
}

