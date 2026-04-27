#include "Torneo.h"
#include "Archivos.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Torneo::Torneo() {
    const char* nombres[] = {"A","B","C","D","E","F","G","H","I","J","K","L"};
    for (int i = 0; i < 12; i++) {
        grupos[i] = new Grupo(nombres[i]);
    }
}

Torneo::~Torneo() {
    for (int i = 0; i < 12; i++) delete grupos[i];
}

void Torneo::cargarEquipos() {
    Archivos lector;
    lector.cargarSelecciones("selecciones_clasificadas_mundial.csv", listaEquipos);
}

void Torneo::sortearGrupos() {
    std::srand(std::time(0));
    bool usado[48] = {false};
    for (int i = 0; i < 12; i++) {
        for (int b = 0; b < 4; b++) {
            int indiceElegido;
            if (i == 0 && b == 0) indiceElegido = 0; // USA forzado en A1
            else {
                int inicio = b * 12;
                do { indiceElegido = inicio + (std::rand() % 12); }
                while (usado[indiceElegido] || indiceElegido == 0);
            }
            usado[indiceElegido] = true;
            grupos[i]->agregarEquipo(listaEquipos.obtener(indiceElegido));
        }
    }
}

void Torneo::seleccionarClasificados() {
    std::cout << "\n--- SELECCIONANDO CLASIFICADOS (32 EQUIPOS) ---\n";
    for(int i = 0; i < 12; i++) {
        if(grupos[i]->getPrimero()) clasificados.insertarAlFinal(grupos[i]->getPrimero());
        if(grupos[i]->getSegundo()) clasificados.insertarAlFinal(grupos[i]->getSegundo());
    }
    // Tomamos los 8 mejores terceros (para simplificar, de los primeros 8 grupos)
    for(int i = 0; i < 8; i++) {
        if(grupos[i]->getTercero()) clasificados.insertarAlFinal(grupos[i]->getTercero());
    }
}

void Torneo::simularEliminatoria(Lista<Equipo*>& equiposRonda, const char* nombreFase) {
    std::cout << "\n========================================\n";
    std::cout << "       " << nombreFase << "\n";
    std::cout << "========================================\n";

    Lista<Equipo*> ganadores;
    for (int i = 0; i < equiposRonda.getTamano(); i += 2) {
        Equipo* e1 = equiposRonda.obtener(i);
        Equipo* e2 = equiposRonda.obtener(i + 1);

        if (e1 && e2) {
            int g1 = std::rand() % 4;
            int g2 = std::rand() % 4;
            if (g1 == g2) (std::rand() % 2 == 0) ? g1++ : g2++; // Desempate

            Equipo* ganador = (g1 > g2) ? e1 : e2;

            std::cout << e1->getNombre().getTexto() << " [" << g1 << "] - ["
                      << g2 << "] " << e2->getNombre().getTexto()
                      << "  => PASA: " << ganador->getNombre().getTexto() << "\n";

            ganadores.insertarAlFinal(ganador);
        }
    }

    equiposRonda = ganadores;
}

void Torneo::ejecutarMundial() {
    cargarEquipos();
    sortearGrupos();

    std::cout << "SIMULANDO FASE DE GRUPOS...\n";
    for(int i = 0; i < 12; i++) {
        grupos[i]->simularPartidos();
        grupos[i]->mostrarTabla();
    }

    seleccionarClasificados();

    // Flujo de Playoffs
    simularEliminatoria(clasificados, "DIECISEISAVOS DE FINAL");
    simularEliminatoria(clasificados, "OCTAVOS DE FINAL");
    simularEliminatoria(clasificados, "CUARTOS DE FINAL");
    simularEliminatoria(clasificados, "SEMIFINALES");

    std::cout << "\n*** LA GRAN FINAL ***\n";
    simularEliminatoria(clasificados, "FINAL");

    if (clasificados.getTamano() > 0) {
        std::cout << "\nEL CAMPEON DEL MUNDO ES: "
                  << clasificados.obtener(0)->getNombre().getTexto();
    }
}
