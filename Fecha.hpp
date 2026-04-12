#ifndef FECHA_HPP
#define FECHA_HPP

using namespace std;

class Fecha {
private:
	int dia;
	int mes;
	int anno;

public:
	Fecha()
	Fecha(int dia, int mes, int anno);
	~Fecha();
};

#endif