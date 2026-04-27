#include "Grupo.h"
#include "Partido.h"
#include <iostream>
#include <iomanip>

Grupo::Grupo() : contadorEquipos(0) {
    for (int i = 0; i < 4; i++) equipos[i] = nullptr;
}

Grupo::Grupo(Cadena nom) : nombre(nom), contadorEquipos(0) {
    for (int i = 0; i < 4; i++) equipos[i] = nullptr;
}

void Grupo::agregarEquipo(Equipo* e) {
    if (contadorEquipos < 4) {
        equipos[contadorEquipos] = e;
        contadorEquipos++;
    }
}

void Grupo::simularPartidos() {
    std::cout << "\n====================================================" << std::endl;
    std::cout << "   SIMULANDO PARTIDOS DEL GRUPO: " << nombre.getTexto() << std::endl;
    std::cout << "====================================================" << std::endl;


    for (int i = 0; i < contadorEquipos; i++) {
        for (int j = i + 1; j < contadorEquipos; j++) {
            if (equipos[i] && equipos[j]) {
                Partido p(equipos[i], equipos[j]);
                p.jugar();
                p.mostrarResultado();
            }
        }
    }
}

void Grupo::ordenarEquipos() {

    for (int i = 0; i < contadorEquipos - 1; i++) {
        for (int j = 0; j < contadorEquipos - i - 1; j++) {
            bool intercambiar = false;


            if (equipos[j]->getPuntos() < equipos[j + 1]->getPuntos()) {
                intercambiar = true;
            }

            else if (equipos[j]->getPuntos() == equipos[j + 1]->getPuntos()) {
                if (equipos[j]->getDG() < equipos[j + 1]->getDG()) {
                    intercambiar = true;
                }
            }

            if (intercambiar) {
                Equipo* temp = equipos[j];
                equipos[j] = equipos[j + 1];
                equipos[j + 1] = temp;
            }
        }
    }
}

void Grupo::mostrarTabla() {
    ordenarEquipos();

    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << " POS | " << std::left << std::setw(18) << "EQUIPO"
              << " | PTS | PJ | DG" << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;

    for (int i = 0; i < contadorEquipos; i++) {
        if (equipos[i]) {
            // Marcamos con '*' a los que pasarían de ronda (1ero y 2do)
            std::string prefijo = (i < 2) ? "* " : "  ";

            std::cout << (i + 1) << "   | "
                      << std::left << std::setw(18) << equipos[i]->getNombre().getTexto()
                      << " | " << std::right << std::setw(3) << equipos[i]->getPuntos()
                      << " | " << std::setw(2) << 3 // 3 partidos en fase de grupos
                      << " | " << std::setw(2) << equipos[i]->getDG()
                      << std::endl;
        }
    }
    std::cout << "------------------------------------------------------------" << std::endl;
}
