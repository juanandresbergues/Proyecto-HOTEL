#inndef RESERVA_HPP
#define RESERVA_HPP

#include "Fecha.hpp"
#include "Cliente.hpp"
#include "Habitacion.hpp"
using namespace std;

class Reserva {
private:
	static int siguienteID;

	int IDreserva;
	Fecha fechaInicio;
	int numeroNoches;
	Cliente* cliente;
	Habitacion* habitacion;
	double precioTotal;

public:
	Reserva();
	Reserva(Fecha fechaInicio, int numeroNoches, Cliente* cliente, Habitacion* habitacion);
	~Reserva();
};

#endif