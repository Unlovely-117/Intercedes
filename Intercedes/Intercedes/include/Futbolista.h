// Futbolista.h
#ifndef FUTBOLISTA_H
#define FUTBOLISTA_H
#include "Deportista.h"
#include <string>
#include <vector>
using namespace std;

class Futbolista : public Deportista {
private:
    int goles, asistencias, faltas;
    string posicion;

public:
    Futbolista(string, int, string, string, int, int, int, string);
    void mostrarDatos() const override;
    int calcularRendimiento() const override;
    int obtenerFaltas() const override;
    int getGoles() const;
    string getNombre() const;
    string serializar() const;
    static void ingresar(vector<Futbolista>& lista);
    static void cargar(vector<Futbolista>& lista);
};

#endif
