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
