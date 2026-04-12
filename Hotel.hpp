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
};

#endif