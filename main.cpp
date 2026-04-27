#include <iostream>
#include <ctime>
#include "Torneo.h"
#include "Estadisticas.h"

int main() {

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "============================================" << std::endl;
    std::cout << "      SIMULADOR UdeA WORLD CUP 2026        " << std::endl;
    std::cout << "============================================" << std::endl;

    try {


        Torneo mundial;



        mundial.ejecutarMundial();

        std::cout << "\nSimulacion finalizada con exito." << std::endl;

    } catch (...) {
        // Manejo de errores genérico por si falla la lectura de archivos
        std::cerr << "Error critico durante la simulacion del torneo." << std::endl;
    }


    Estadisticas::mostrarReporteEficiencia();

    std::cout << "Presione ENTER para cerrar el simulador..." << std::endl;
    std::cin.get();

    return 0;
}
