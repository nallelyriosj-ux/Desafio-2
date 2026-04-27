#ifndef GRUPO_H
#define GRUPO_H
#include "Equipo.h"
#include "Cadena.h"

class Grupo {
private:
    Cadena nombre;
    Equipo* equipos[4];
    int contadorEquipos;

public:
    Grupo();
    Grupo(Cadena nom);
    void agregarEquipo(Equipo* e);
    void simularPartidos();
    void mostrarTabla();
    void ordenarEquipos(); // Necesario para saber quién quedó primero

    Cadena getNombre() const { return nombre; }


    Equipo* getPrimero() { return equipos[0]; }
    Equipo* getSegundo() { return equipos[1]; }
    Equipo* getTercero() { return equipos[2]; }
};

#endif
