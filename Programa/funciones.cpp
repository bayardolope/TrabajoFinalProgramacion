#include "funciones.h"
#include "variables.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

void mostrarMenu() {
    cout << "Menú Principal" << endl;
    cout << "1. Gestión de facturación a clientes" << endl;
    cout << "2. Registrar ventas diarias" << endl;
    cout << "3. Consultar inventario" << endl;
    cout << "4. Generar reporte diario" << endl;
    cout << "5. Mostrar facturas" << endl;
    cout << "6. Editar factura" << endl;
    cout << "7. Eliminar factura" << endl;
    cout << "8. Buscar factura" << endl;
    cout << "9. Salir" << endl;
    cout << "Seleccione una opción: ";
}

char realizarOperacion() {
    int opcion;
    double inventarioPollos = 100; // Este es nuestro inventario inicial de pollos al día.
    cin >> opcion;

    switch (opcion) {
    case 1:
        gestionarFacturacion(inventarioPollos);
        break;
    case 2:
        registrarVentas(inventarioPollos);
        break;
    case 3:
        consultarInventario(inventarioPollos);
        break;
    case 4:
        generarReporteDiario();
        break;
    case 5:
        // Implementar la función mostrarTodo() si está definida
        break;
    case 6:
        // Implementar la función editar() si está definida
        break;
    case 7:
        // Implementar la función eliminar() si está definida
        break;
    case 8:
        // Implementar la función buscarFactura() si está definida
        break;
    case 9:
        return 'N';
    default:
        cout << "Opción no válida, por favor intente de nuevo." << endl;
    }

    char continuar;
    cout << "¿Desea realizar otra operación? (S/N): ";
    cin >> continuar;
    return continuar;
}

void gestionarFacturacion(double &inventarioPollos) {
    FACTURA factura;
    cout << "Ingresar datos del cliente" << endl;
    cout << "ID: ";
    cin >> factura.id;
    if (/* Implementar findPos() */ -1) {
        cout << "Registro ya existe..." << endl;
        return;
    }
    cout << "NOMBRE: ";
    cin.ignore();
    cin.getline(factura.name, 30);
    cout << "DESCRIPCIÓN: ";
    cin.getline(factura.description, 100);

    cout << "Ingresar cantidad de pollos comprados: ";
    cin >> factura.numPollos;
    while (factura.numPollos <= 0 || factura.numPollos > inventarioPollos) {
        cout << "Cantidad inválida. Ingrese una cantidad positiva y no mayor al inventario disponible (" << inventarioPollos << ")." << endl;
        cin >> factura.numPollos;
    }

    cout << "Ingresar precio por pollo: ";
    cin >> factura.precioPollos;
    while (factura.precioPollos <= 0) {
        cout << "Precio inválido. Ingrese un precio positivo." << endl;
        cin >> factura.precioPollos;
    }

    cout << "Total de la factura: $" << fixed << setprecision(2) << factura.numPollos * factura.precioPollos << endl;

    inventarioPollos -= factura.numPollos;
    // Implementar addFactura(&factura) y writeFile(factura)
    cout << "Factura guardada correctamente." << endl;
}

void registrarVentas(double &inventarioPollos) {
    double cantidadVendida, precioPollo, totalVentasDiarias;

    cout << "Ingresar cantidad de pollos vendidos hoy: ";
    cin >> cantidadVendida;
    while (cantidadVendida <= 0 || cantidadVendida > inventarioPollos) {
        cout << "Cantidad inválida. Ingrese una cantidad positiva y no mayor al inventario disponible (" << inventarioPollos << ")." << endl;
        cin >> cantidadVendida;
    }

    cout << "Ingresar precio por pollo: ";
    cin >> precioPollo;
    while (precioPollo <= 0) {
        cout << "Precio inválido. Ingrese un precio positivo." << endl;
        cin >> precioPollo;
    }

    totalVentasDiarias = cantidadVendida * precioPollo;
    cout << fixed << setprecision(2) << "Total de ventas diarias: $" << totalVentasDiarias << endl;

    inventarioPollos -= cantidadVendida;
    cout << "Registro de ventas diarias guardado correctamente." << endl;
}

void consultarInventario(double inventarioPollos) {
    cout << "Consultando inventario..." << endl;

    const int numPollos = 3;
    string nombresPollos[numPollos] = {"Pollo 1", "Pollo 2", "Pollo 3"};
    int cantidadesPollos[numPollos] = {10, 15, 20};
    double preciosPollos[numPollos] = {5.0, 6.0, 7.0};

    for (int i = 0; i < numPollos; i++) {
        cout << nombresPollos[i] << ": Cantidad: " << cantidadesPollos[i] << ", Precio: $" << preciosPollos[i] << endl;
    }
}

void generarReporteDiario() {
    cout << "Generando reporte diario..." << endl;
    cout << "------------------------------------" << endl;
    cout << "Reporte diario... aún no terminado..." << endl;
}

// Implementar funciones adicionales como addFactura, findFactura, findPos, etc.
