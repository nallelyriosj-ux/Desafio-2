#include "Partido.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

Partido::Partido(Equipo* a, Equipo* b) : equipoA(a), equipoB(b), golesA(0), golesB(0) {}

void Partido::jugar() {

    golesA = rand() % 6;
    golesB = rand() % 6;


    if (equipoA && equipoB) {
        equipoA->registrarPartido(golesA, golesB);
        equipoB->registrarPartido(golesB, golesA);
    }
}

void Partido::mostrarResultado() {

    std::cout << std::right << std::setw(15) << equipoA->getNombre().getTexto()
              << " " << golesA << " - " << golesB << " "
              << std::left << std::setw(15) << equipoB->getNombre().getTexto()
              << std::endl;
}
