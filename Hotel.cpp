#include "Hotel.hpp"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
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
	clientes.push_back(cliente);
}

void Hotel::agregarHabitacion(Habitacion* habitacion) {
	habitaciones.push_back(habitacion);
}

void Hotel::agregarReserva(Reserva* reserva) {
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

Habitacion* Hotel::buscarHabitacionPorNumero(int numero) const {
	for (int i = 0; i < habitaciones.size(); i++) {
		if (habitaciones[i]->getNumero() == numero) {
			return habitaciones[i];
		}
	}
	return nullptr;
}

Reserva* Hotel::buscarReservaPorID(int idReserva) const {
	for (int i = 0; i < reservas.size(); i++) {
		if (reservas[i]->getIdReserva() == idReserva) {
			return reservas[i];
		}
	}
	return nullptr;
}

void Hotel::mostrarClientes() const {
	cout << "Clientes registrados:" << endl;
	for (int i = 0; i < clientes.size(); i++) {
		clientes[i]->mostrarInfoCliente();
		cout << endl;
	}
}

void Hotel::mostrarHabitaciones() const {
	cout << "Habitaciones disponibles:" << endl;
	for (int i = 0; i < habitaciones.size(); i++) {
		habitaciones[i]->mostrarInfoHabitacion();
		cout << endl;
	}
}

void Hotel::mostrarReservas() const {
	cout << "Reservas realizadas:" << endl;
	for (int i = 0; i < reservas.size(); i++) {
		reservas[i]->mostrarInfoReserva();
		cout << endl;
	}
}

void Hotel::cancelarReserva(int idReserva) {
	for (int i = 0; i < reserva.size(); i++) {
		if (reservas[i]->getIdReserva() == idReserva) {
			delete reservas[i];
			reservas.erase(reservas.begin() + i);
			cout << "Reserva con ID " << idReserva << " cancelada." << endl;
			return;
		}
	}
}

void Hotel::guardarClientesEnArchivo(string nombreArchivo) const {
	ofstream archivo(nombreArchivo);
	if (archivo.is_open()) {
		for (int i = 0; i < clientes.size(); i++) {
			archivo << clientes[i]->getDni() << endl; 
			archivo << clientes[i]->getNombre() << endl; 
			archivo << clientes[i]->getApellido() << endl;
			archivo << clientes[i]->getEmail() << endl;
			archivo << clientes[i]->getTelefono() << endl;
		}
		archivo.close();
		cout << "Clientes guardados en el archivo " << nombreArchivo << endl;
	}
	else {
		cout << "No se pudo abrir el archivo " << nombreArchivo << " para guardar los clientes." << endl;
	}
}

void Hotel::guardarHabitacionesEnArchivo(string nombreArchivo) const {
	ofstream archivo(nombreArchivo);
	if (archivo.is_open()) {
		for (int i = 0; i < habitaciones.size(); i++) {
			archivo << habitaciones[i]->getNumero() << endl;
			archivo << static_cast<int>(habitaciones[i]->getTipo()) << endl;
			archivo << habitaciones[i]->getPrecioPorNoche() << endl;
		}
		archivo.close();
		cout << "Habitaciones guardadas en el archivo " << nombreArchivo << endl;
	}
	else {
		cout << "No se pudo abrir el archivo " << nombreArchivo << " para guardar las habitaciones." << endl;
	}
}

void Hotel::guardarReservasEnArchivo(string nombreArchivo) const {
	ofstream archivo(nombreArchivo);
	if (archivo.is_open()) {
		for (int i = 0; i < reservas.size(); i++) {
			archivo << reservas[i]->getIdReserva() << endl;
			archivo << reservas[i]->getFechaInicio().toString() << endl;
			archivo << reservas[i]->getNumeroNoches() << endl;
			if (reservas[i]->getCliente() != nullptr) {
				archivo << reservas[i]->getCliente()->getDni() << endl;
			}
			else {
				archivo << "No asignado" << endl;
			}
			if (reservas[i]->getHabitacion() != nullptr) {
				archivo << reservas[i]->getHabitacion()->getNumero() << endl;
			}
			else {
				archivo << "No asignado" << endl;
			}
			archivo << reservas[i]->getPrecioTotal() << endl;
		}
		archivo.close();
		cout << "Reservas guardadas en el archivo " << nombreArchivo << endl;
	}
	else {
		cout << "No se pudo abrir el archivo " << nombreArchivo << " para guardar las reservas." << endl;
	}
}

void Hotel::cargarClientesDesdeArchivo(string nombreArchivo) {
	ifstream archivo(nombreArchivo);

	if (archivo.is_open()) {
		string dni, nombre, apellido, email, telefono;

		while (getline(archivo, dni)) {
			getline(archivo, nombre);
			getline(archivo, apellido);
			getline(archivo, email);
			getline(archivo, telefono);

			Cliente* nuevoCliente = new Cliente(dni, nombre, apellido, email, telefono);
			agregarCliente(cliente);
		}

		archivo.close();
		cout << "Clientes cargados desde el archivo " << nombreArchivo << endl;
	}

	else {
		cout << "No se pudo abrir el archivo " << nombreArchivo << " para cargar los clientes." << endl;
	}
}

void Hotel::cargarHabitacionesDesdeArchivo(string nombreArchivo) {
	ifstream archivo(nombreArchivo);

	if (archivo.is_open()) {
		int numero, tipoInt;
		double precioPorNoche;

		while (archivo >> numero) {
			archivo >> tipoInt;
			archivo >> precioPorNoche;

			TipoHabitacion tipo = static_cast<TipoHabitacion>(tipoInt);
			Habitacion* nuevaHabitacion = new Habitacion(numero, tipo, precioPorNoche);
			habitaciones.push_back(nuevaHabitacion);
		}

		archivo.close();
		cout << "Habitaciones cargadas desde el archivo " << nombreArchivo << endl;
	}

	else {
		cout << "No se pudo abrir el archivo " << nombreArchivo << " para cargar las habitaciones." << endl;
	}
}

void Hotel::cargarReservasDesdeArchivo(string nombreArchivo) {
	ifstream archivo(nombreArchivo);

	if (archivo.is_open()) {
		int idReserva, numeroNoches;
		string fechaInicio, clienteDni, numHabitacion;

		while (archivo >> idReserva) {
			archivo.ignore();
			getline(archivo, fechaInicio);
			archivo >> numeroNoches;
			archivo.ignore();
			getline(archivo, clienteDni);
			getline(archivo, numHabitacion);
			archivo >> precioTotal;
			archivo.ignore();

			int dia, mes, anno;
			sscanf(fechaInicio.c_str(), "%d/%d/%d", &dia, &mes, &anno);
			Fecha fecha(dia, mes, anno);

			Cliente* cliente = nullptr;
			if (clienteDni != "No asignado") {
				cliente = buscarClientePorDni(clienteDni);
			}

			Habitacion* habitacion = nullptr;
			if (numHabitacion != "No asignado") {
				int numeroHabitacion = stoi(numHabitacion);
				habitacion = buscarHabitacionPorNumero(numeroHabitacion);
			}

			Reserva* nuevaReserva = new Reserva(idReserva, fecha, numeroNoches, cliente, habitacion);
			nuevaReserva->calcularPrecioTotal();
			reservas.push_back(nuevaReserva);
		}

		archivo.close();
		cout << "Reservas cargadas desde el archivo " << nombreArchivo << endl;
	}

	else {
		cout << "No se pudo abrir el archivo " << nombreArchivo << " para cargar las reservas." << endl;
	}