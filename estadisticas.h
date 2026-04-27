#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H

class Estadisticas {
private:
    static long bytesReservados;
    static long totalIteraciones;
    static int objetosCreados;

public:
    // Métodos para registrar datos
    static void registrarMemoria(int bytes);
    static void registrarIteracion(int n = 1);
    static void nuevoObjeto();

    // Métodos para mostrar resultados
    static void mostrarReporteEficiencia();

    // Resetear para cada fase si es necesario
    static void reiniciar();
};

#endif
