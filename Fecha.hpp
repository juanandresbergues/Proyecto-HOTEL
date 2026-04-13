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

	int getDia() const;
	int getMes() const;
	int getAnno() const;

	void setDia(int dia);
	void setMes(int mes);
	void setAnno(int anno);

	string toString() const;

	bool esValida() const;

	bool operator==(const Fecha& otra) const;
	bool operator<(const Fecha& otra) const;
};

#endif