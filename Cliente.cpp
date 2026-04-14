#include <Cliente.hpp>
using namespace std;

Cliente::Cliente() {
	dni = "";
	nombre = "";
	apellido = "";
	email = "";
	telefono = "";
}

Cliente::Cliente(string dni, string nombre, string apellido, string email, string telefono) {
	this->dni = dni;
	this->nombre = nombre;
	this->apellido = apellido;
	this->email = email;
	this->telefono = telefono;
}

Cliente::~Cliente() {
}

void Cliente::mostrarInfoCliente() const
{
	cout << "DNI:" << dni << endl;
	cout << "Nombre:" << nombre << endl;
	cout << "Apellido:" << apellido << endl;
	cout << "Email:" << email << endl;
	cout << "Telefono:" << telefono << endl;
}
