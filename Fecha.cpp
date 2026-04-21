#include "Fecha.hpp"
#include <iostream>
#include <string>
using namespace std;

Fecha::Fecha() {
	dia = 1;
	mes = 1;
	anno = 2000;
}

Fecha::Fecha(int dia, int mes, int anio) {
	this->dia = dia;
	this->mes = mes;
	this->anno = anno;
}

Fecha::~Fecha() {
}

int Fecha::getDia() const {
	return dia;
}

int Fecha::getMes() const {
	return mes;
}

int Fecha::getAnno() const {
	return anno;
}

void Fecha::setDia(int dia) {
	this->dia = dia;
}

void Fecha::setMes(int mes) {
	this->mes = mes;
}

void Fecha::setAnno(int anno) {
	this->anno = anno;
}

string Fecha::toString() const {
	return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anno);
}

bool Fecha::esBisiesto() const {
	return (anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0);
}

bool Fecha::esValida() const {
	if (anno <= 0) {
		return false;
	}

	if (mes < 1 || mes > 12) {
		return false;
	}

	int diasEnMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (esBisiesto() && mes == 2) {
		diasEnMes[1] = 29;
	}

	return dia >= 1 && dia <= diasEnMes[mes - 1];
}

bool Fecha::operator==(const Fecha& otra) const {
	return dia == otra.dia && mes == otra.mes && anno == otra.anno;
}

bool Fecha::operator<(const Fecha& otra) const {
	if (anno != otra.anno) {
		return anno < otra.anno;
	}
	if (mes != otra.mes) {
		return mes < otra.mes;
	}
	return dia < otra.dia;
}