#ifndef TORNEO_H
#define TORNEO_H

#include "Lista.h"
#include "Equipo.h"
#include "Grupo.h"

class Torneo {
private:
    Lista<Equipo*> listaEquipos;
    Grupo* grupos[12];
    Lista<Equipo*> clasificados; // Lista para los 32 que pasan de ronda

    void seleccionarClasificados();
    void simularEliminatoria(Lista<Equipo*>& equiposRonda, const char* nombreFase);

public:
    Torneo();
    ~Torneo();
    void cargarEquipos();
    void sortearGrupos();
    void ejecutarMundial();
    void mostrarResultados();
};

#endif
