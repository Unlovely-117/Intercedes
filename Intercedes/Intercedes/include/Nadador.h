#ifndef NADADOR_H
#define NADADOR_H
#include "Deportista.h"
#include <vector>

class Nadador : public Deportista {
private:
    string estilo;
    vector<float> tiempos;
    float peso;

public:
    Nadador(string, int, string, string, string, vector<float>, float);
    void mostrarDatos() const override;
    int calcularRendimiento() const override;
    int obtenerFaltas() const override;
    string getNombre() const;
    string serializar() const;
    static void ingresar(vector<Nadador>&);
    static void cargar(vector<Nadador>&);
};

#endif
