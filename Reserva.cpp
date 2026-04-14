#include "Reserva.hpp"
#include <iostream>
using namespace std;

int Reserva::siguienteID = 1;

Reserva::Reserva() {
	IDreserva = siguienteID++;

	fechaInicio = fecha();
	numeroNoches = 0;
	cliente = nullptr;
	habitacion = nullptr;
	precioTotal = 0.0;
}

Reserva::Reserva(Fecha fechaInicio, int numeroNoches, Cliente* cliente, Habitacion* habitacion) {
	idReserva = siguienteID++;

	this->fechaInicio = fechaInicio;
	this->numeroNoches = numeroNoches;
	this->cliente = cliente;
	this->habitacion = habitacion;
	precioTotal = 0.0;
}

Reserva::~Reserva() {
}

int Reserva::getIDreserva() const {
	return idReserva;
}

fecha Reserva::getFechaInicio() const {
	return fechaInicio;
}

int Reserva::getNumeroNoches() const {
	return numeroNoches;
}

Cliente* Reserva::getCliente() const {
	return cliente;
}

Habitacion* Reserva::getHabitacion() const {
	return habitacion;
}

double Reserva::getPrecioTotal() const {
	return precioTotal;
}

void Reserva::setFechaInicio(Fecha fechaInicio) {
	this->fechaInicio = fechaInicio;
}

void Reserva::setNumeroNoches(int numeroNoches) {
	this->numeroNoches = numeroNoches;
}

void Reserva::setCliente(Cliente* cliente) {
	this->cliente = cliente;
}

void Reserva::setHabitacion(Habitacion* habitacion) {
	this->habitacion = habitacion;
}

void Reserva::setPrecioTotal(double precioTotal) {
	this->precioTotal = precioTotal;
}

void Reserva::calcularPrecioTotal() {
	if (habitacion != nullptr) {
		precioTotal = habitacion->getPrecioPorNoche() * numeroNoches;
	}
	else {
		precioTotal = 0.0;
	}
}

void Reserva::mostrarInfoReserva() const {
	cout << "ID de reserva: " << idReserva << endl;
	cout << "Fecha de inicio: " << fechaInicio.toString() << endl;
	cout << "Número de noches: " << numeroNoches << endl;
	if (cliente != nullptr) {
		cout << "Cliente: " << cliente->getNombre() << " " << cliente->getApellido() << endl;
	}
	else {
		cout << "Cliente: No asignado" << endl;
	}
	if (habitacion != nullptr) {
		cout << "Habitación número: " << habitacion->getNumero() << endl;
	}
	else {
		cout << "Habitación: No asignada" << endl;
	}
	cout << "Precio total: " << precioTotal << endl;
}