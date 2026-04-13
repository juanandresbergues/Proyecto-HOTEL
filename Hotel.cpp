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