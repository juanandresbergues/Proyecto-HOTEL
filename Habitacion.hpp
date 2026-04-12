#ifndef HABITACION_HPP
#define HABITACION_HPP

#include "TipoHabitacion.hpp"
using namespace std;

class Habitacion {
private:
	int numero;
	TipoHabitacion tipo;
	double precioPorNoche;

public:
	Habitacion();
	Habitacion(int numero, TipoHabitacion tipo, double precioPorNoche);
	~Habitacion();
};

#endif