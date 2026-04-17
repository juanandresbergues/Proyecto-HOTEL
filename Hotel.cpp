#include "Hotel.hpp"
#include <fstream>
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
void Hotel::agregarReserva(Reserva* reserva)  
{
	reservas.push_back(reserva);
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
void Hotel::buscarReservaPorID(int IDreserva)const
{
	for (int i = 0; i < reservas.size(); i++)
	{
		if (reservas[i]->getIDreserva == IDreserva) {
			return reservas[i];
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
void Hotel::cancelarReserva(int IDreserva) {
	for (int i = 0; i < reservas.size(); i++) {
		if (reservas[i]->getIDreserva() == IDreserva) {

			delete reservas[i];
			reservas.erase(reservas.begin() + i);

			cout << "Reserva cancelada correctamente" << endl;
			return;
		}
	}
}
void Hotel::guardarClientesEnArchivo(string nombreArchivo) const
{
	ofstream fichero(nombreArchivo);

	if (!fichero) {
		cout << "Error al abrir el archivo" << endl;
		return;
	}else{
		for (int i = 0; i < clientes.size(); i++) {
			fichero << clientes[i]->getDni() << ";"
				<< clientes[i]->getNombre() << ";"
				<< clientes[i]->getApellido() << ";"
				<< clientes[i]->getEmail() << ";"
				<< clientes[i]->getTelefono() << endl;
		}
	}

	fichero.close();
}

}