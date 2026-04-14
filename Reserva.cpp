#include <Reserva.hpp>
using namespace std;

int Reserva::siguienteID = 1;

Reserva::Reserva() {
	idReserva = siguienteID++;

	fechaInicio = fecha();
	numeroNoches = 0;
	cliente = nullptr;
	habitacion = nullptr;
	precioTotal = 0.0;
}

Reserva::Reserva(fecha fechaInicio, int numeroNoches, Cliente* cliente, Habitacion* habitacion) {
	idReserva = siguienteID++;

	this->fechaInicio = fechaInicio;
	this->numeroNoches = numeroNoches;
	this->cliente = cliente;
	this->habitacion = habitacion;
	precioTotal = 0.0;
}

Reserva::~Reserva() {
}
void Reserva::calcularPrecioTotal() {
	if (habitacion != nullptr) {
		precioTotal = numeroNoches * habitacion->getPrecio();
	}
	else {
		precioTotal = 0.0;
	}
}
void Reserva::mostrarInfoReserva() const
{
	cout << "ID Reserva:" << idReserva << endl;
	cout << "fecha inicio:";
	fechaInicio.mostrar();
	cout << "numero noches:" << numeroNoches << endl;
	if (cliente != nullptr) {
		cliente->mostrarInfoCliente();
	}
	if (habitacion != nullptr) {
		habitacion->mostrarInfoHabitacion();

	}
	cout << "precio total:" << precioTotal << endl;

}