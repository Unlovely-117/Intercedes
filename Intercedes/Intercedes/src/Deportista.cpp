#include "Deportista.h"

Deportista::Deportista(string n, int e, string ci, string cod)
    : nombre(n), edad(e), cedula(ci), codigo(cod) {}

string Deportista::getNombre() const {
    return nombre;
}
