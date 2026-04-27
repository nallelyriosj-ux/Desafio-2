#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "Lista.h"
#include "Equipo.h"

class Archivos {
public:
    // Método estático para cargar los equipos desde el CSV a la lista
    static void cargarSelecciones(const char* nombreArchivo, Lista<Equipo*>& lista);
};

#endif
