#include <iostream>
#include "variables.h"
#include <string.h>
#include <fstream>
#include <cstdlib>

using namespace std;

/* Funciones para hacer factura al cliente (Nombre del producto, cantidad, precio unitario, total), las funciones tienen que tener la capacidad de sumar el total de los productos
y multiplicar el precio unitario con la cantidad que se lleva */

// Funciones
int menu();
void principal();
void factura();
void registro();

VENTA ventas[MAX_REG];

// Menu
int menu()
{
    int op;
    cout << "Menu" << endl;
    cout << "1. Agregar" << endl;
    cout << "2. Factura" << endl;
    cout << "3. Salir" << endl;
    cout << "Opcion: ";
    cin >> op;
    return op;
}

void principal()
{
    int op;
    pos = 0;
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            registro();
            break;
        case 2:
            factura();
            break;
        case 3:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Deberias de leer mas solo hay seis opciones" << endl;
            break;
        }
    } while (op != 3);
}


//Funcion de registro, pide los datos al usuario y los guarda en el arreglo de ventas
void registro()
{
    cout << "Registro" << endl;
    cout << "Numero de factura: ";
    cin >> ventas[pos].numeroFactura;
    cout << "Nombre del cliente: ";
    cin >> ventas[pos].nombreCliente;
    cout << "Nombre del vendedor: ";
    cin >> ventas[pos].nombreVendedor;
    cout << "Dia: ";
    cin >> ventas[pos].dia;
    cout << "Mes: ";
    cin >> ventas[pos].mes;
    cout << "Cantidad de pollos: ";
    cin >> ventas[pos].cantidadProducto;
    cout << "Precio por pollo: ";
    cin >> ventas[pos].precioPorProducto;
    ventas[pos].total = ventas[pos].cantidadProducto * ventas[pos].precioPorProducto;
    pos++;
}

//Funcion de factura, busca la factura por el numero de factura y la imprime, basandose en el registro de ventas
void factura()
{
    int num;
    cout << "Numero de factura: ";
    cin >> num;
    for (int i = 0; i < pos; i++)
    {
        if (ventas[i].numeroFactura == num)
        {
            cout << "*********************************" << endl;
            cout << "Factura" << endl;
            cout << "Numero de factura: " << ventas[i].numeroFactura << endl;
            cout << "Nombre del cliente: " << ventas[i].nombreCliente << endl;
            cout << "Nombre del vendedor: " << ventas[i].nombreVendedor << endl;
            cout << "Dia: " << ventas[i].dia << endl;
            cout << "Mes: " << ventas[i].mes << endl;
            cout << "Cantidad de pollos: " << ventas[i].cantidadProducto << endl;
            cout << "Precio por pollo: " << ventas[i].precioPorProducto << endl;
            cout << "Total: " << ventas[i].total << endl;
            cout << "*********************************" << endl;
            return;
        }
    }
    cout << "No se encontro la factura" << endl;
}
