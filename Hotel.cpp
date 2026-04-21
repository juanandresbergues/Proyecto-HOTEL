#include "Hotel.hpp"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <sstream>
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
Cliente* Hotel::buscarClientePorDNI(string dni) const {
	for (int i = 0; i < clientes.size(); i++) {
		if (clientes[i]->getDni() == dni) {
			return clientes[i];
		}

	}
	return nullptr;
}

Reserva* Hotel::buscarReservaPorID(int IDreserva) const {
	for (int i = 0; i < reservas.size(); i++)
	{
		if (reservas[i]->getIDreserva() == IDreserva) {
			return reservas[i];
		}
	}
	return nullptr;
}

Habitacion* Hotel::buscarHabitacionPorNumero(int numero) const {
	for (int i = 0; i < habitaciones.size(); i++)
	{
		if (habitaciones[i]->getNumero() == numero) {
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
void Hotel::guardarClientesEnArchivo(string& nombreArchivo) const
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
void Hotel::guardarHabitacionesEnArchivo(string& nombreArchivo) const {
	ofstream archivo(nombreArchivo);

	if (!archivo) {
		cout << "Error al abrir el archivo" << endl;
		return;
	}

	for (int i = 0; i < habitaciones.size(); i++) {
		archivo << habitaciones[i]->getNumero() << ";"
			<< static_cast<int>(habitaciones[i]->getTipo()) << ";"
			<< habitaciones[i]->getPrecioPorNoche() << endl;
	}

	archivo.close();
}
void Hotel::guardarReservasEnArchivo(string& nombreArchivo) const
{
	ofstream fichero(nombreArchivo);

	if (!fichero) {
		cout << "Error al abrir el archivo" << endl;
		return;
	}

	for (int i = 0; i < reservas.size(); i++) {

		fichero << reservas[i]->getIDreserva() << ";"
			<< reservas[i]->getFechaInicio().getDia() << "-"
			<< reservas[i]->getFechaInicio().getMes() << "-"
			<< reservas[i]->getFechaInicio().getAnno() << ";"
			<< reservas[i]->getNumeroNoches() << ";"
			<< reservas[i]->getCliente()->getDni() << ";"
			<< reservas[i]->getHabitacion()->getNumero() << ";"
			<< reservas[i]->getPrecioTotal()
			<< endl;
	}

	fichero.close();
}

void Hotel::cargarClientesDesdeArchivo(string nombreArchivo) {
		ifstream archivo(nombreArchivo);

		if (!archivo.is_open()) {
			cout << "Error al abrir el archivo de clientes\n";
			return;
		}

		clientes.clear();

		string linea;

		while (getline(archivo, linea)) {
			stringstream ss(linea);

			Cliente c; 

			string dni;
			string nombre;
			string apellido;
			string email;
			string telefono;

			getline(ss, dni, ';');
			getline(ss, nombre, ';');
			getline(ss, apellido, ';');
			getline(ss, email, ';');
			getline(ss, telefono, ';');

			if (dni != "") {
				Cliente* c = new Cliente(dni, nombre, apellido, email, telefono);
				clientes.push_back(c);
			}
		}

		archivo.close();
	
}

void Hotel::cargarHabitacionesDesdeArchivo(string nombreArchivo) {
	ifstream archivo(nombreArchivo);

	if (!archivo.is_open()) {
		cout << "Error al abrir el archivo de habitaciones" << endl;
		return;
	}

	habitaciones.clear();

	string linea;

	while (getline(archivo, linea)) {
		stringstream ss(linea);

		string token;
		int numero;
		int tipoEntero;
		double precioPorNoche;
		
		getline(ss, token, ',');
		numero = stoi(token);

		
		getline(ss, token, ',');
		tipoEntero = stoi(token);

		
		getline(ss, token, ',');
		precioPorNoche = stod(token);

		TipoHabitacion tipo = static_cast<TipoHabitacion>(tipoEntero);

		Habitacion* h = new Habitacion(numero, tipo, precioPorNoche);
		habitaciones.push_back(h);
	}

	archivo.close();

}

void Hotel::cargarReservasDesdeArchivo(string nombreArchivo) {
	ifstream archivo(nombreArchivo);

	if (!archivo.is_open()) {
		cout << "Error al abrir el archivo de reservas" << endl;
		return;
	}

	reservas.clear();

	string linea;

	while (getline(archivo, linea)) {
		stringstream ss(linea);

		string idTexto;
		string fechaTexto;
		string nochesTexto;
		string dniCliente;
		string numeroHabitacionTexto;
		string precioTexto;

		getline(ss, idTexto, ';');
		getline(ss, fechaTexto, ';');
		getline(ss, nochesTexto, ';');
		getline(ss, dniCliente, ';');
		getline(ss, numeroHabitacionTexto, ';');
		getline(ss, precioTexto, ';');

		int dia = 1, mes = 1, anno = 2000;
		char separador1, separador2;
		stringstream fechaSS(fechaTexto);
		fechaSS >> dia >> separador1 >> mes >> separador2 >> anno;

		Fecha fecha(dia, mes, anno);
		int numeroNoches = stoi(nochesTexto);
		double precioTotal = stod(precioTexto);

		Cliente* cliente = nullptr;
		if (dniCliente != "NULL") {
			cliente = buscarClientePorDNI(dniCliente);
		}

		Habitacion* habitacion = nullptr;
		if (numeroHabitacionTexto != "-1") {
			int numeroHabitacion = stoi(numeroHabitacionTexto);
			habitacion = buscarHabitacionPorNumero(numeroHabitacion);
		}

		Reserva* r = new Reserva(fecha, numeroNoches, cliente, habitacion);
		r->setPrecioTotal(precioTotal);
		reservas.push_back(r);
	}

	archivo.close();
}