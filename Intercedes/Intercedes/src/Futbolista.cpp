#include "Futbolista.h"
#include <iostream>
#include <fstream>
#include <sstream>

Futbolista::Futbolista(string n, int e, string c, string cod, int g, int a, int f, string p)
    : Deportista(n, e, c, cod), goles(g), asistencias(a), faltas(f), posicion(p) {}

void Futbolista::mostrarDatos() const {
    cout << "Futbolista - " << nombre << ", Goles: " << goles << ", Asistencias: " << asistencias
         << ", Faltas: " << faltas << ", Posicion: " << posicion << endl;
}

int Futbolista::calcularRendimiento() const {
    return goles * 2 + asistencias;
}

int Futbolista::obtenerFaltas() const {
    return faltas;
}

int Futbolista::getGoles() const {
    return goles;
}

string Futbolista::getNombre() const {
    return nombre;
}

string Futbolista::serializar() const {
    return nombre + "," + to_string(edad) + "," + cedula + "," + codigo + "," +
           to_string(goles) + "," + to_string(asistencias) + "," + to_string(faltas) + "," + posicion + "\n";
}

void Futbolista::ingresar(vector<Futbolista>& lista) {
    string nombre, cedula, codigo, posicion;
    int edad, goles, asistencias, faltas;

    cout << "Nombre: "; cin >> nombre;
    cout << "Edad: "; cin >> edad;
    cout << "Cedula: "; cin >> cedula;
    cout << "Codigo: "; cin >> codigo;
    cout << "Goles: "; cin >> goles;
    cout << "Asistencias: "; cin >> asistencias;
    cout << "Faltas: "; cin >> faltas;
    cout << "Seleccione posicion (1. Portero, 2. Defensa, 3. Mediocampo, 4. Delantero): ";
    int op; cin >> op;
    switch(op) {
        case 1: posicion = "Portero"; break;
        case 2: posicion = "Defensa"; break;
        case 3: posicion = "Mediocampo"; break;
        case 4: posicion = "Delantero"; break;
        default: posicion = "Desconocida";
    }

    Futbolista f(nombre, edad, cedula, codigo, goles, asistencias, faltas, posicion);
    lista.push_back(f);

    ofstream archivo("futbolistas.txt", ios::app);
    archivo << f.serializar();
}

void Futbolista::cargar(vector<Futbolista>& lista) {
    ifstream archivo("futbolistas.txt");
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string n, e, ci, co, g, a, f, p;
        getline(ss, n, ','); getline(ss, e, ','); getline(ss, ci, ','); getline(ss, co, ',');
        getline(ss, g, ','); getline(ss, a, ','); getline(ss, f, ','); getline(ss, p);
        lista.emplace_back(n, stoi(e), ci, co, stoi(g), stoi(a), stoi(f), p);
    }
}
