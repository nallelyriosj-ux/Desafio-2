#ifndef JUGADOR_H
#define JUGADOR_H

#include "Cadena.h"

class Jugador {
private:
    Cadena nombre;
    Cadena apellido;
    int numeroCamiseta;

    // Estadísticas de torneo
    int goles;
    int asistencias;
    int amarillas;
    int rojas;
    int faltas;
    int minutosJugados;
    int partidosJugados;

public:
    // Constructor
    Jugador(Cadena nom, Cadena ape, int num);


    ~Jugador();


    void registrarGol();
    void registrarAsistencia();
    void recibirAmarilla();
    void recibirRoja();
    void cometerFalta();
    void sumarMinutos(int min);
    void incrementarPartido();

    // Getters
    const char* getNombreCompleto() const;
    int getGoles() const { return goles; }
    int getNumero() const { return numeroCamiseta; }


    bool operator>(const Jugador& otro) const;
};

#endif
