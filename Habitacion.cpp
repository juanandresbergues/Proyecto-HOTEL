#include <Habitacion.hpp>
using namespace std;

Habitacion::Habitacion() {
	numero = 0;
	tipo = TipoHabitacion::INDIVIDUAL;
	precioPorNoche = 0.0;
}

Habitacion::Habitacion(int numero, TipoHabitacion tipo, double precioPorNoche) {
	this->numero = numero;
	this->tipo = tipo;
	this->precioPorNoche = precioPorNoche;
}

Habitacion::~Habitacion() {
}