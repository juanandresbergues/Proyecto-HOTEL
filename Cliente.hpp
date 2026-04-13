#infndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
using namespace std;

class Cliente {
private:
	string dni;
	string nombre;
	string apellido;
	string email;
	string telefono;

public:
	Cliente();
	Cliente(string dni, string nombre, string apellido, string email, string telefono);
	~Cliente();

	string getDni() const;
	string getNombre() const;
	string getApellido() const;
	string getEmail() const;
	string getTelefono() const;

	void setDni(string dni);
	void setNombre(string nombre);
	void setApellido(string apellido);
	void setEmail(string email);
	void setTelefono(string telefono);

	void mostrarInfoCliente() const;
};

#endif