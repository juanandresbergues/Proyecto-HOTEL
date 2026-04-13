#include "Cliente.hpp"
#include <iostream>
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

string Cliente::getDni() const {
	return dni;
}

string Cliente::getNombre() const {
	return nombre;
}

string Cliente::getApellido() const {
	return apellido;
}

string Cliente::getEmail() const {
	return email;
}

string Cliente::getTelefono() const {
	return telefono;
}

void Cliente::setDni(string dni) {
	this->dni = dni;
}

void Cliente::setNombre(string nombre) {
	this->nombre = nombre;
}

void Cliente::setApellido(string apellido) {
	this->apellido = apellido;
}

void Cliente::setEmail(string email) {
	this->email = email;
}

void Cliente::setTelefono(string telefono) {
	this->telefono = telefono;
}

void Cliente::mostrarInfoCliente() const {
	cout << "DNI: " << dni << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Apellido: " << apellido << endl;
	cout << "Email: " << email << endl;
	cout << "Telefono: " << telefono << endl;
}