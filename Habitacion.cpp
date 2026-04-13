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

int Habitacion::getNumero() const {
	return numero;
}

TipoHabitacion Habitacion::getTipo() const {
	return tipo;
}

double Habitacion::getPrecioPorNoche() const {
	return precioPorNoche;
}

void Habitacion::setNumero(int numero) {
	this->numero = numero;
}

void Habitacion::setTipo(TipoHabitacion tipo) {
	this->tipo = tipo;
}

void Habitacion::setPrecioPorNoche(double precioPorNoche) {
	this->precioPorNoche = precioPorNoche;
}

void Habitacion::mostrarInfoHabitacion() const {
	cout << "Número de habitación: " << numero << endl;
	cout << "Tipo de habitación: ";
	switch (tipo) {
	case TipoHabitacion::INDIVIDUAL:
		cout << "Individual" << endl;
		break;
	case TipoHabitacion::DOBLE:
		cout << "Doble" << endl;
		break;
	case TipoHabitacion::SUITE:
		cout << "Suite" << endl;
		break;
	default:
		cout << "Desconocido" << endl;
		break;
	}
	cout << "Precio por noche: $" << precioPorNoche << endl;
}