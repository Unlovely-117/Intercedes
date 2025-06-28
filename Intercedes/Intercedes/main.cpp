#include <iostream>
#include <vector>
#include "Futbolista.h"
#include "Basquetbolista.h"
#include "Nadador.h"

using namespace std;

void mostrarMejorJugador(const vector<Futbolista>&, const vector<Basquetbolista>&, const vector<Nadador>&);
void mostrarMaximoGoleador(const vector<Futbolista>&);
void mostrarMasFaltas(const vector<Futbolista>&, const vector<Basquetbolista>&);

int main() {
    vector<Futbolista> futbolistas;
    vector<Basquetbolista> basquetbolistas;
    vector<Nadador> nadadores;

    Futbolista::cargar(futbolistas);
    Basquetbolista::cargar(basquetbolistas);
    Nadador::cargar(nadadores);

    int opcion;
    do {
        cout << "\n====== MENU SISTEMA INTERCEDES ======\n";
        cout << "1. Ingresar Futbolista\n";
        cout << "2. Ingresar Basquetbolista\n";
        cout << "3. Ingresar Nadador\n";
        cout << "4. Mostrar Mejor Jugador\n";
        cout << "5. Mostrar Maximo Goleador\n";
        cout << "6. Mostrar Jugador con Mas Faltas\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: Futbolista::ingresar(futbolistas); break;
            case 2: Basquetbolista::ingresar(basquetbolistas); break;
            case 3: Nadador::ingresar(nadadores); break;
            case 4: mostrarMejorJugador(futbolistas, basquetbolistas, nadadores); break;
            case 5: mostrarMaximoGoleador(futbolistas); break;
            case 6: mostrarMasFaltas(futbolistas, basquetbolistas); break;
            case 7: cout << "Gracias por usar el sistema intercedes.\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 7);

    return 0;
}

void mostrarMejorJugador(const vector<Futbolista>& f, const vector<Basquetbolista>& b, const vector<Nadador>& n) {
    if (f.empty() && b.empty() && n.empty()) {
        cout << "No hay jugadores registrados. Ingrese alguno primero.\n";
        return;
    }

    const Deportista* mejor = nullptr;
    int maxRendimiento = -1;

    for (size_t i = 0; i < f.size(); ++i) {
        int r = f[i].calcularRendimiento();
        if (r > maxRendimiento) {
            maxRendimiento = r;
            mejor = &f[i];
        }
    }

    for (size_t i = 0; i < b.size(); ++i) {
        int r = b[i].calcularRendimiento();
        if (r > maxRendimiento) {
            maxRendimiento = r;
            mejor = &b[i];
        }
    }

    for (size_t i = 0; i < n.size(); ++i) {
        int r = n[i].calcularRendimiento();
        if (r > maxRendimiento) {
            maxRendimiento = r;
            mejor = &n[i];
        }
    }

    cout << "\nMejor jugador:\n";
    mejor->mostrarDatos();
}

void mostrarMaximoGoleador(const vector<Futbolista>& f) {
    if (f.empty()) {
        cout << "No hay futbolistas registrados.\n";
        return;
    }

    const Futbolista* mejor = nullptr;
    int maxGoles = -1;
    for (size_t i = 0; i < f.size(); ++i) {
        int g = f[i].getGoles();
        if (g > maxGoles) {
            maxGoles = g;
            mejor = &f[i];
        }
    }

    cout << "\nMaximo goleador:\n";
    cout << "Nombre: " << mejor->getNombre() << ", Goles: " << mejor->getGoles() << "\n";
}

void mostrarMasFaltas(const vector<Futbolista>& f, const vector<Basquetbolista>& b) {
    if (f.empty() && b.empty()) {
        cout << "No hay futbolistas o basquetbolistas registrados.\n";
        return;
    }

    const Deportista* peor = nullptr;
    int maxFaltas = -1;

    for (size_t i = 0; i < f.size(); ++i) {
        int fts = f[i].obtenerFaltas();
        if (fts > maxFaltas) {
            maxFaltas = fts;
            peor = &f[i];
        }
    }

    for (size_t i = 0; i < b.size(); ++i) {
        int fts = b[i].obtenerFaltas();
        if (fts > maxFaltas) {
            maxFaltas = fts;
            peor = &b[i];
        }
    }

    cout << "\nJugador con mas faltas:\n";
    cout << "Nombre: " << peor->getNombre() << ", Faltas: " << peor->obtenerFaltas() << "\n";
}
