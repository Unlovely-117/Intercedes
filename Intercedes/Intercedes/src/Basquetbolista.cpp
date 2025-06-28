#include "Basquetbolista.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Basquetbolista::Basquetbolista(string n, int e, string c, string cod, int pt, int a, int r, int f, string p)
    : Deportista(n, e, c, cod), puntos(pt), asistencias(a), rebotes(r), faltas(f), posicion(p) {}

void Basquetbolista::mostrarDatos() const {
    cout << "Basquetbolista - " << nombre << ", Puntos: " << puntos
         << ", Asistencias: " << asistencias << ", Rebotes: " << rebotes
         << ", Faltas: " << faltas << ", Posicion: " << posicion << endl;
}

int Basquetbolista::calcularRendimiento() const {
    return puntos + asistencias + rebotes;
}

int Basquetbolista::obtenerFaltas() const {
    return faltas;
}

string Basquetbolista::getNombre() const {
    return nombre;
}

string Basquetbolista::serializar() const {
    return nombre + "," + to_string(edad) + "," + cedula + "," + codigo + "," +
           to_string(puntos) + "," + to_string(asistencias) + "," + to_string(rebotes) +
           "," + to_string(faltas) + "," + posicion + "\n";
}

void Basquetbolista::ingresar(vector<Basquetbolista>& lista) {
    string nombre, cedula, codigo, posicion;
    int edad, puntos, asistencias, rebotes, faltas;

    cin.ignore();
    cout << "Nombre: "; getline(cin, nombre);
    cout << "Edad: "; cin >> edad;
    cin.ignore();
    cout << "Cedula: "; getline(cin, cedula);
    cout << "Codigo: "; getline(cin, codigo);
    cout << "Puntos: "; cin >> puntos;
    cout << "Asistencias: "; cin >> asistencias;
    cout << "Rebotes: "; cin >> rebotes;
    cout << "Faltas: "; cin >> faltas;

    cout << "Seleccione posicion (1. Base, 2. Escolta, 3. Alero, 4. Pivot): ";
    int op; cin >> op;
    switch(op) {
        case 1: posicion = "Base"; break;
        case 2: posicion = "Escolta"; break;
        case 3: posicion = "Alero"; break;
        case 4: posicion = "Pivot"; break;
        default: posicion = "Desconocida";
    }

    Basquetbolista b(nombre, edad, cedula, codigo, puntos, asistencias, rebotes, faltas, posicion);
    lista.push_back(b);

    ofstream archivo("basquetbolistas.txt", ios::app);
    if (archivo.is_open()) {
        archivo << b.serializar();
        archivo.close();
    } else {
        cout << "Error al abrir o crear el archivo basquetbolistas.txt.\n";
    }
}

void Basquetbolista::cargar(vector<Basquetbolista>& lista) {
    ifstream archivo("basquetbolistas.txt");
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string n, e, ci, co, pt, a, r, f, p;
        getline(ss, n, ','); getline(ss, e, ','); getline(ss, ci, ','); getline(ss, co, ',');
        getline(ss, pt, ','); getline(ss, a, ','); getline(ss, r, ','); getline(ss, f, ','); getline(ss, p);
        lista.emplace_back(n, stoi(e), ci, co, stoi(pt), stoi(a), stoi(r), stoi(f), p);
    }
}
