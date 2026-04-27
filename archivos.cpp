#include "Archivos.h"
#include <fstream>
#include <cstring>
#include <iostream>

void Archivos::cargarSelecciones(const char* nombreArchivo, Lista<Equipo*>& lista) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cout << "ERROR: No se encontro el archivo " << nombreArchivo << std::endl;
        return;
    }

    char linea[500];
    archivo.getline(linea, 500); // Saltar cabecera

    while (archivo.getline(linea, 500)) {
        char nombrePais[100];
        int i = 0;


        while (linea[i] != ',' && linea[i] != '\0' && i < 99) {
            nombrePais[i] = linea[i];
            i++;
        }
        nombrePais[i] = '\0';


        int len = std::strlen(nombrePais);
        while(len > 0 && (nombrePais[len-1] == ' ' || nombrePais[len-1] == '\r' || nombrePais[len-1] == '\n')) {
            nombrePais[len-1] = '\0';
            len--;
        }

        Equipo* nuevo = new Equipo(Cadena(nombrePais));


        if (std::strcmp(nombrePais, "United States") == 0) {
            lista.insertarAlInicio(nuevo);
            std::cout << "[SISTEMA] Anfitrion detectado: " << nombrePais << " asignado al Grupo A." << std::endl;
        } else {
            lista.insertarAlFinal(nuevo);
        }
    }
    archivo.close();
}
