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
void Hotel::guardarHabitacionesEnArchivo(string nombreArchivo) const
{
	ofstream fichero(nombreArchivo);

	if (!fichero) {
		cout << "Error al abrir el archivo" << endl;
		return;
	}

	for (int i = 0; i < habitaciones.size(); i++) {
		fichero << habitaciones[i]->getNumero() << ";"
			<< habitaciones[i]->getTipo() << ";"
			<< habitaciones[i]->getPrecio() << endl;
	}

	fichero.close();
}
void Hotel::guardarReservasEnArchivo(string nombreArchivo) const
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
			<< reservas[i]->getFechaInicio().getAnio() << ";"
			<< reservas[i]->getNumeroNoches() << ";"
			<< reservas[i]->getCliente()->getDni() << ";"
			<< reservas[i]->getHabitacion()->getNumero() << ";"
			<< reservas[i]->getPrecioTotal()
			<< endl;
	}

	fichero.close();
}

void Hotel::cargarClientesDesdeArchivo(string nombreArchivo) const
{
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

			getline(ss, c.dni, ', ');
			getline(ss, c.nombre, ', ');
			getline(ss, c.apellido, ', ');
			getline(ss, c.email, ', ');
			getline(ss, c.telefono, ', ');

			if (c.dni != "") {
				clientes.push_back(c);
			}
		}

		archivo.close();
	
}

void Hotel::cargarHabitacionesDesdeArchivo(string nombreArchivo) const {
	ifstream archivo(nombreArchivo);

	if (!archivo.is_open()) {
		cout << "Error al abrir el archivo de habitaciones\n";
		return;
	}

	habitaciones.clear();

	string linea;

	while (getline(archivo, linea)) {
		stringstream ss(linea);

		Habitacion h;

		string token;

		
		getline(ss, token, ',');
		h.numero = stoi(token);

		
		getline(ss, token, ',');
		if (token == "INDIVIDUAL") {
			h.tipo = TipoHabitacion::INDIVIDUAL;
		}
		else if (token == "DOBLE") {
			h.tipo = TipoHabitacion::DOBLE;
		}
		else if (token == "SUITE") {
			h.tipo = TipoHabitacion::SUITE;
		}
		else {
			h.tipo = TipoHabitacion::INDIVIDUAL; //x si es q no registra o esta null divagate
		}

		
		getline(ss, token, ',');
		h.precioPorNoche = stod(token);

		if (h.numero > 0) {
			habitaciones.push_back(h);
		}
	}

	archivo.close();

}

void Hotel::cargarReservasDesdeArchivo(string nombreArchivo) const {
	ifstream archivo(nombreArchivo);

	if (!archivo.is_open()) {
		cout << "Error al abrir el archivo de reservas\n";
		return;
	}

	reservas.clear();

	string linea;

	while (getline(archivo, linea)) {
		stringstream ss(linea);

		Reserva r;

		string token;
		string dniCliente;
		int numeroHabitacion;

		getline(ss, token, ', ');
		r.idReserva = stoi(token);

		getline(ss, dniCliente, ', ');

		getline(ss, token, ', ');
		numeroHabitacion = stoi(token);

		getline(ss, r.fechaInicio, ', ');

		getline(ss, token, ', ');
		r.numeroNoches = stoi(token);

		getline(ss, token, ',');
		r.precioTotal = stod(token);

		r.cliente = nullptr;
		for (auto& c : clientes) {
			if (c.dni == dniCliente) {
				r.cliente = &c;
				break;
			}
		}

		r.habitacion = nullptr;
		for (auto& h : habitaciones) {
			if (h.numero == numeroHabitacion) {
				r.habitacion = &h;
				break;
			}
		}

		if (r.cliente != nullptr && r.habitacion != nullptr) {
			reservas.push_back(r);
		}
	}

	archivo.close();
}

