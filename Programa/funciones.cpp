#include <iostream>
#include <string>
#include <iomanip>
#include "funciones.h"

using namespace std;

void mostrarMenu()
{
    cout << "Menú Principal" << endl;
    cout << "1. Gestión de facturación a clientes" << endl;
    cout << "2. Registrar ventas diarias" << endl;
    cout << "3. Consultar inventario" << endl;
    cout << "4. Generar reporte diario" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opción: ";
}

char realizarOperacion()
{
    int opcion;
    double inventarioPollos = 100; // Este es nuestro inventario inicial de pollos al dia.
    cin >> opcion;

    switch (opcion)
    {
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
        cout << "Saliendo del programa..." << endl;
        return 'N';
    default:
        cout << "Opción no válida, por favor intente de nuevo." << endl;
    }

    char continuar;
    cout << "¿Desea realizar otra operación? (S/N): ";
    cin >> continuar;
    return continuar;
}

void gestionarFacturacion(double &inventarioPollos)
{
    string nombreCliente, direccionCliente;
    double cantidadPollos, precioPollo, totalFactura, descuento;
    char aplicarDescuento;

    cout << "Ingresar datos del cliente" << endl;
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nombreCliente);
    cout << "Dirección: ";
    getline(cin, direccionCliente);

    cout << "Ingresar cantidad de pollos comprados: ";
    cin >> cantidadPollos;
    while (cantidadPollos <= 0 || cantidadPollos > inventarioPollos)
    {
        cout << "Cantidad inválida. Ingrese una cantidad positiva y no mayor al inventario disponible (" << inventarioPollos << ")." << endl;
        cin >> cantidadPollos;
    }

    cout << "Ingresar precio por pollo: ";
    cin >> precioPollo;
    while (precioPollo <= 0)
    {
        cout << "Precio inválido. Ingrese un precio positivo." << endl;
        cin >> precioPollo;
    }

    cout << "¿Desea aplicar un descuento? (S/N): ";
    cin >> aplicarDescuento;
    if (aplicarDescuento == 'S' || aplicarDescuento == 's')
    {
        cout << "Ingrese el porcentaje de descuento: ";
        cin >> descuento;
        while (descuento < 0 || descuento > 100)
        {
            cout << "Descuento inválido. Ingrese un porcentaje entre 0 y 100." << endl;
            cin >> descuento;
        }
    }
    else
    {
        descuento = 0;
    }

    totalFactura = cantidadPollos * precioPollo * (1 - descuento / 100);
    cout << fixed << setprecision(2) << "Total de la factura: $" << totalFactura << endl;

    inventarioPollos -= cantidadPollos;
    cout << "Factura guardada correctamente." << endl;
}

void registrarVentas(double &inventarioPollos)
{
    double cantidadVendida, precioPollo, totalVentasDiarias;

    cout << "Ingresar cantidad de pollos vendidos hoy: ";
    cin >> cantidadVendida;
    while (cantidadVendida <= 0 || cantidadVendida > inventarioPollos)
    {
        cout << "Cantidad inválida. Ingrese una cantidad positiva y no mayor al inventario disponible (" << inventarioPollos << ")." << endl;
        cin >> cantidadVendida;
    }

    cout << "Ingresar precio por pollo: ";
    cin >> precioPollo;
    while (precioPollo <= 0)
    {
        cout << "Precio inválido. Ingrese un precio positivo." << endl;
        cin >> precioPollo;
    }

    totalVentasDiarias = cantidadVendida * precioPollo;
    cout << fixed << setprecision(2) << "Total de ventas diarias: $" << totalVentasDiarias << endl;

    inventarioPollos -= cantidadVendida;
    cout << "Registro de ventas diarias guardado correctamente." << endl;
}

void consultarInventario(double inventarioPollos)
{
    cout << "Inventario actual de pollos: " << inventarioPollos << endl;
}

void generarReporteDiario()
{
    cout << "Generando reporte diario..." << endl;
    cout << "------------------------------------" << endl;
    cout <<"Reporte diario... aun no terminado..." << endl;
}
