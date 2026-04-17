#include "Hotel.hpp"
using namespace std;

Hotel::Hotel() {
}

Hotel::~Hotel() {
	for (int i = 0; i < clientes.size(); i++) {
		delete clientes[i];
		clientes[i] = nullptr;
	}

	for (int i = 0; i < habitaciones.size(); i++) {
		delete habitaciones[i];
		habitaciones[i] = nullptr;
	}

	for (int i = 0; i < reservas.size(); i++) {
		delete reservas[i];
		reservas[i] = nullptr;
	}
}
void Hotel::agregarCliente(Cliente* cliente) {
	clientes.push_back(cliente); //como cliente es un vector el push back annade al cliente al final del vector 
}
void Hotel::agregarHabitacion(Habitacion* habitacion) {
	habitaciones.push_back(habitacion);
}
void Hotel::buscarClientePorDNI(string dni) const
{
	for (int i = 0; i < clientes.size(); i++)
	{
		if (clientes[i]->getDni == dni) {
			return clientes[i];
		}

	}
	return nullptr;
}
void Hotel::buscarHabitacionPorNumero(int numero) const
{
	for (int i = 0; i < habitaciones.size(); i++)
	{
		if (habitaciones[i]->getNumero == numero) {
			return habitaciones[i];
		}

	}
	return nullptr;
}
void Hotel::mostrarClientes() const //recorre y llama al vector para mostrar 
{
	for (int i = 0; i < clientes.size(); i++)
	{
		clientes[i]->mostrarInfoCliente();
		cout << "__________________" << endl;

	}
}
void Hotel::mostrarHabitaciones() const //el puntero apunta a la hab y ejecuta funcion
{
	for (int i = 0; i < habitaciones.size(); i++)
	{
		habitaciones[i]->mostrarInfoHabitacion();
		cout << "_______________________" << endl;
	}
	
}
void Hotel::mostrarReservas() const
{
	for (int i = 0; i < reservas.size(); i++)
	{
		reservas[i]->mostrarInfoReserva();
		cout << "______________" << endl;
	}
}
