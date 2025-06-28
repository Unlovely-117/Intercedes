#ifndef BASQUETBOLISTA_H
#define BASQUETBOLISTA_H
#include "Deportista.h"
#include <vector>

class Basquetbolista : public Deportista {
private:
    int puntos, asistencias, rebotes, faltas;
    string posicion;

public:
    Basquetbolista(string, int, string, string, int, int, int, int, string);
    void mostrarDatos() const override;
    int calcularRendimiento() const override;
    int obtenerFaltas() const override;
    string getNombre() const;
    string serializar() const;
    static void ingresar(vector<Basquetbolista>&);
    static void cargar(vector<Basquetbolista>&);
};

#endif
