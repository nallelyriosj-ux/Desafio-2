#include "Estadisticas.h"
#include <iostream>

// Inicialización de miembros estáticos
long Estadisticas::bytesReservados = 0;
long Estadisticas::totalIteraciones = 0;
int Estadisticas::objetosCreados = 0;

void Estadisticas::registrarMemoria(int bytes) {
    bytesReservados += bytes;
}

void Estadisticas::registrarIteracion(int n) {
    totalIteraciones += n;
}

void Estadisticas::nuevoObjeto() {
    objetosCreados++;
}

void Estadisticas::mostrarReporteEficiencia() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "       Eficiencia del codigo       " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << " Memoria Dinamica Estimada: " << bytesReservados << " bytes" << std::endl;
    std::cout << " Total de Iteraciones/Pasos: " << totalIteraciones << std::endl;
    std::cout << " Total de Objetos en Memoria: " << objetosCreados << std::endl;
    std::cout << "========================================\n" << std::endl;
}

void Estadisticas::reiniciar() {
    bytesReservados = 0;
    totalIteraciones = 0;
}
