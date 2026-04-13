#ifndef HOTEL_HPP
#define HOTEL_HPP

#include <vector>
#include "Cliente.hpp"
#include "Habitacion.hpp"
#include "Reserva.hpp"
using namespace std;

class Hotel {
private:
	vector<Cliente*> clientes;
	vector<Habitacion*> habitaciones;
	vector<Reserva*> reservas;

public:
	Hotel();
	~Hotel();

	void agregarCliente(Cliente* cliente);
	void agregarHabitacion(Habitacion* habitacion);
	void agregarReserva(Reserva* reserva);

	Cliente* buscarClientePorDNI(string dni) const;
	Habitacion* buscarHabitacionPorNumero(int numero) const;
	Reserva* buscarReservaPorID(int IDreserva) const;

	void mostrarClientes() const;
	void mostrarHabitaciones() const;
	void mostrarReservas() const;

	void cancelarReserva(int IDreserva);

	void guardarClientesEnArchivo(string nombreArchivo) const;
	void guardarHabitacionesEnArchivo(string nombreArchivo) const;
	void guardarReservasEnArchivo(string nombreArchivo) const;

	void cargarClientesDesdeArchivo(string nombreArchivo);
	void cargarHabitacionesDesdeArchivo(string nombreArchivo);
	void cargarReservasDesdeArchivo(string nombreArchivo);
};

#endif