#include "Nadador.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Nadador::Nadador(string n, int e, string c, string cod, string est, vector<float> t, float ps)
    : Deportista(n, e, c, cod), estilo(est), tiempos(t), peso(ps) {}

void Nadador::mostrarDatos() const {
    cout << "Nadador - " << nombre << ", Estilo: " << estilo << ", Peso: " << peso << "kg" << endl;
}

int Nadador::calcularRendimiento() const {
    float suma = 0;
    for (size_t i = 0; i < tiempos.size(); i++)
        suma += tiempos[i];
    float promedio = suma / tiempos.size();
    return 1000 - static_cast<int>(promedio * 10);
}

int Nadador::obtenerFaltas() const {
    return 0;
}

string Nadador::getNombre() const {
    return nombre;
}

string Nadador::serializar() const {
    string t = "";
    for (size_t i = 0; i < tiempos.size(); ++i)
        t += to_string(tiempos[i]) + "-";
    return nombre + "," + to_string(edad) + "," + cedula + "," + codigo + "," + estilo + "," + t + to_string(peso) + "\n";
}

void Nadador::ingresar(vector<Nadador>& lista) {
    string nombre, cedula, codigo, estilo;
    int edad, nTiempos;
    float peso;
    vector<float> tiempos;

    cin.ignore();
    cout << "Nombre: "; getline(cin, nombre);
    cout << "Edad: "; cin >> edad;
    cin.ignore();
    cout << "Cedula: "; getline(cin, cedula);
    cout << "Codigo: "; getline(cin, codigo);
    cout << "Estilo: "; getline(cin, estilo);
    cout << "Peso: "; cin >> peso;
    cout << "Cantidad de tiempos: "; cin >> nTiempos;

    for (int i = 0; i < nTiempos; ++i) {
        float t;
        cout << "Tiempo " << (i + 1) << ": ";
        cin >> t;
        tiempos.push_back(t);
    }

    Nadador n(nombre, edad, cedula, codigo, estilo, tiempos, peso);
    lista.push_back(n);

    ofstream archivo("nadadores.txt", ios::app);
    if (archivo.is_open()) {
        archivo << n.serializar();
        archivo.close();
    } else {
        cout << "Error al abrir o crear el archivo nadadores.txt.\n";
    }
}

void Nadador::cargar(vector<Nadador>& lista) {
    ifstream archivo("nadadores.txt");
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string n, e, ci, co, est, tStr, ps;
        getline(ss, n, ','); getline(ss, e, ','); getline(ss, ci, ','); getline(ss, co, ',');
        getline(ss, est, ','); getline(ss, tStr, ','); getline(ss, ps);
        vector<float> tiempos;
        stringstream ts(tStr); string temp;
        while (getline(ts, temp, '-')) if (!temp.empty()) tiempos.push_back(stof(temp));
        lista.emplace_back(n, stoi(e), ci, co, est, tiempos, stof(ps));
    }
}
