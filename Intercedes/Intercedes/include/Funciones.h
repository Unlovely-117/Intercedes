#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <vector>
#include "Futbolista.h"
#include "Basquetbolista.h"
#include "Nadador.h"

// Declaraci�n de funciones para ingreso de deportistas
void ingresarFutbolista(std::vector<Futbolista>&);
void ingresarBasquetbolista(std::vector<Basquetbolista>&);
void ingresarNadador(std::vector<Nadador>&);

// Declaraci�n de funciones para cargar desde archivo
void cargarFutbolistas(std::vector<Futbolista>&);
void cargarBasquetbolistas(std::vector<Basquetbolista>&);
void cargarNadadores(std::vector<Nadador>&);

// Declaraci�n de funciones de an�lisis
void mostrarMejorJugador(const std::vector<Futbolista>&, const std::vector<Basquetbolista>&, const std::vector<Nadador>&);
void mostrarMaximoGoleador(const std::vector<Futbolista>&);
void mostrarMasFaltas(const std::vector<Futbolista>&, const std::vector<Basquetbolista>&);

#endif
