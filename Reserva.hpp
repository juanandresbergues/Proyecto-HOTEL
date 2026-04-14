#ifndef RESERVA_HPP
#define RESERVA_HPP

#include "Fecha.hpp"
#include "Cliente.hpp"
#include "Habitacion.hpp"
using namespace std;

class Reserva {
private:
	static int siguienteID;

	int IDreserva;
	Fecha fechaInicio;
	int numeroNoches;
	Cliente* cliente;
	Habitacion* habitacion;
	double precioTotal;

public:
	Reserva();
	Reserva(Fecha fechaInicio, int numeroNoches, Cliente* cliente, Habitacion* habitacion);
	~Reserva();

	int getIDreserva() const;
	Fecha getFechaInicio() const;
	int getNumeroNoches() const;
	Cliente* getCliente() const;
	Habitacion* getHabitacion() const;
	double getPrecioTotal() const;

	void setFechaInicio(Fecha fechaInicio);
	void setNumeroNoches(int numeroNoches);
	void setCliente(Cliente* cliente);
	void setHabitacion(Habitacion* habitacion);
	void setPrecioTotal(double precioTotal);

	void calcularPrecioTotal();
	void mostrarInfoReserva() const;
};

#endif