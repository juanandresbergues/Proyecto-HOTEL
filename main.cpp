#include <iostream>
#include <string>
#include "Hotel.hpp"
using namespace std;

int menu();
int menuCarga();
void ejecutarMenuCarga(Hotel& hotel);

int main() {
    Hotel hotel;
    int opcion;
    Reserva* reserva = nullptr;

    do {
        opcion = menu();

        switch (opcion) {
        case 1:
            hotel.mostrarClientes();
            break;

        case 2:
            hotel.mostrarHabitaciones();
            break;

        case 3:
            hotel.mostrarReservas();
            break;

        case 4: {
            int idReserva;
            cout << "Introduce el ID de la reserva: ";
            cin >> idReserva;

            reserva = hotel.buscarReservaPorID(idReserva);

            if (reserva != nullptr) {
                reserva->calcularPrecioTotal();
                cout << "El precio total de la reserva es: "
                    << reserva->getPrecioTotal() << endl;
            }
            else {
                cout << "No se encontro ninguna reserva con ese ID." << endl;
            }
            break;
        }

        case 5:
            ejecutarMenuCarga(hotel);
            break;

        case 6:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion invalida" << endl;
        }

    } while (opcion != 6);

    return 0;
}

int menu() {
    int opcion;

    cout << "1. Mostrar informacion de clientes" << endl;
    cout << "2. Mostrar informacion de habitaciones" << endl;
    cout << "3. Mostrar informacion de reservas" << endl;
    cout << "4. Calcular precio total de una reserva" << endl;
    cout << "5. Carga/guardado de archivos" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    while (opcion < 1 || opcion > 6) {
        cout << "Error, elige otro numero: ";
        cin >> opcion;
    }

    return opcion;
}

int menuCarga() {
    int opcion;

    cout << "Menu carga de archivos" << endl;
    cout << "1. Guardar clientes en archivo" << endl;
    cout << "2. Guardar reservas en archivo" << endl;
    cout << "3. Guardar habitaciones en archivo" << endl;
    cout << "4. Cargar clientes desde archivo" << endl;
    cout << "5. Cargar reservas desde archivo" << endl;
    cout << "6. Cargar habitaciones desde archivo" << endl;
    cout << "7. Volver" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    while (opcion < 1 || opcion > 7) {
        cout << "Opcion incorrecta, elige de nuevo: ";
        cin >> opcion;
    }

    return opcion;
}

void ejecutarMenuCarga(Hotel& hotel) {
    int opcion = menuCarga();
    string nombreArchivo;

    switch (opcion) {
    case 1:
        cout << "Introduce el nombre del archivo de clientes: ";
        cin >> nombreArchivo;
        hotel.guardarClientesEnArchivo(nombreArchivo);
        break;

    case 2:
        cout << "Introduce el nombre del archivo de reservas: ";
        cin >> nombreArchivo;
        hotel.guardarReservasEnArchivo(nombreArchivo);
        break;

    case 3:
        cout << "Introduce el nombre del archivo de habitaciones: ";
        cin >> nombreArchivo;
        hotel.guardarHabitacionesEnArchivo(nombreArchivo);
        break;

    case 4:
        cout << "Introduce el nombre del archivo de clientes: ";
        cin >> nombreArchivo;
        hotel.cargarClientesDesdeArchivo(nombreArchivo);
        break;

    case 5:
        cout << "Introduce el nombre del archivo de reservas: ";
        cin >> nombreArchivo;
        hotel.cargarReservasDesdeArchivo(nombreArchivo);
        break;

    case 6:
        cout << "Introduce el nombre del archivo de habitaciones: ";
        cin >> nombreArchivo;
        hotel.cargarHabitacionesDesdeArchivo(nombreArchivo);
        break;

    case 7:
        break;

    default:
        cout << "Opcion invalida" << endl;
    }
}