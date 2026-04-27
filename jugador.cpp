#include "Jugador.h"
#include <iostream>

Jugador::Jugador(Cadena nom, Cadena ape, int num)
    : nombre(nom), apellido(ape), numeroCamiseta(num) {

    goles = 0;
    asistencias = 0;
    amarillas = 0;
    rojas = 0;
    faltas = 0;
    minutosJugados = 0;
    partidosJugados = 0;
}

Jugador::~Jugador() {

}

void Jugador::registrarGol() { goles++; }

void Jugador::registrarAsistencia() { asistencias++; }

void Jugador::recibirAmarilla() { amarillas++; }

void Jugador::recibirRoja() { rojas++; }

void Jugador::cometerFalta() { faltas++; }

void Jugador::sumarMinutos(int min) { minutosJugados += min; }

void Jugador::incrementarPartido() { partidosJugados++; }

bool Jugador::operator>(const Jugador& otro) const {

    return this->goles > otro.goles;
}
