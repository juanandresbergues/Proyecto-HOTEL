#infndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
using namespace std;

class Cliente {
private:
	string nombre;
	string apellido;
	string email;
	string telefono;

public:
	Cliente();
	Cliente(string nombre, string apellido, string email, string telefono);
	~Cliente();
};

#endif