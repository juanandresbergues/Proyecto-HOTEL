#include <iostream>
using namespace std;
int menu();
int menuCarga();
int main() {
	int opcion;
	do {
		opcion = menu();
		switch (opcion) {
		case 1:
			mostrarInfoCliente();
			break;
		case 2:
			mostrarInfoHabitacion();
			break;
		case 3:
			mostrarInfoReserva();
			break;
		case 4:
			calcularPrecioTotal();
			break;
		case 5:
			menuCarga();
			break;
		default:
			cout << "opcion invalida" << endl;
		}
	} while (opcion != 5);
	
	return 0;
}
int menu() {
	
		cout << "1.Mostrar informacion Cliente" << endl;
		cout << "2.Mostrar info habitacion" << endl;
		cout << "3.Mostrar informacion de la reserva" endl;
		cout << "4.Calcular precio total" << endl;
		COUT << "5.Carga de archivos" << endl;
		cout << "seleccione una opcion" << endl;
		int opcion;
		cin >> opcion;
		while (opcion != 7) {
			cout << "error elige otro numero" << endl;
			cin >> opcion;
		}
		return opcion;

	
}
int menu carga() {
	cout << "Menu carga de archivos" << endl;
	cout << "1.Guardar clientes en archivo" << endl;
	cout << "2.Guardar Reservas en archivo" << endl;
	cout << "3.Guardar habitaciones en archivo" << endl;
	cout << "seleccione el archivo que quieras guardar" << endl;
	int opcion;
	cin >> opcion;
	do {
		switch (opcion) {
		case 1:
			guardarClientesEnArchivo(string& nombreArchivo);
			break;
		case 2:
			guardarHabitacionesEnArchivo(string& nombreArchivo);
			break;
		case 3:
			guardarReservasEnArchivo(string& nombreArchivo);
			break;
		default:
			cout << "opcion invalida" << endl;


		}
		
	} while (opcion != 3) {
		cout << "opcion incorrecta, elige de nuevo" << endl;
	}
	return opcion;
}