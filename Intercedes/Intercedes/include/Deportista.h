#ifndef DEPORTISTA_H
#define DEPORTISTA_H

#include <string>
using namespace std;

class Deportista {
protected:
    string nombre;
    int edad;
    string cedula;
    string codigo;

public:
    Deportista(string, int, string, string);
    virtual void mostrarDatos() const = 0;
    virtual int calcularRendimiento() const = 0;
    virtual int obtenerFaltas() const = 0;
    string getNombre() const;
};

#endif
