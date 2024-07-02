#include <iostream>
#include <string.h>
#include "variables.h"
#include <fstream>
#include <cstdlib>

using namespace std;

// Separar las funciones de las facturas

// Funciones para proceso de facturacion

void addFactura(FACTURA *factura);            // Funcion para agregar una factura
FACTURA findFactura(int id);                  // Funcion para buscar una factura
int findPos(int id);                          // Funcion para buscar la posicion de una factura
void updateFactura(FACTURA *factura, int id); // Funcion para actualizar una factura
void destroyFactura(int id);                  // Funcion para eliminar una factura
void buscarFactura();                         // Funcion para buscar una factura
void showData(FACTURA &factura);              // Funcion para mostrar los datos de una factura
void writeFile(const FACTURA &factura);       // Funcion para escribir en un archivo
void pedirDato();                             // Funcion para pedir datos
void mostrarTodo();                           // Funcion para mostrar todas las facturas
void editar();                                // Funcion para editar una factura
void eliminar();                              // Funcion para eliminar una factura
void saveAll();                               // Funcion para guardar todas las facturas

// En este apartado se implementan las funciones de facturas

void addFactura(FACTURA *factura) // Factura *factura es un puntero a una estructura FACTURA
{
    facturas[pos] = *factura; // Se asigna la estructura FACTURA a la posicion pos del arreglo facturas
    pos++;                    // Cada que finaliza una factura se incrementa la variable
}

FACTURA findFactura(int id)
{
    FACTURA factura = {}; // Initialize the factura variable with default values
    for (int i = 0; i < pos; i++)
    {
        if (facturas[i].id == id) // Si el id de la factura es igual al id que se busca retorna la factura
        {
            return facturas[i];
        }
    }
    return factura;
}

int findPos(int id)
{
    for (int i = 0; i < pos; i++)
    {
        if (facturas[i].id == id) // Lo mismo que el anterior pero en ves de retorna la factura retorna la posicion
            return i;
    }
    return -1;
}

void updateFactura(FACTURA *factura, int id)
{
    int position = findPos(id);
    strcpy(facturas[position].cliente, factura->cliente); // Se copia el cliente de la factura a la posicion de la factura
    facturas[position].cantidad = factura->cantidad;
    facturas[position].precio = factura->precio;
    strcpy(facturas[position].fecha, factura->fecha);
}

void destroyFactura(int id)
{
    int position = findPos(id);
    for (int i = position; i < pos - 1; i++) // Aqui se recorre el arreglo de facturas
    {
        facturas[i] = facturas[i + 1]; // Se asigna la factura siguiente a la factura actual
    }
    FACTURA f;             // Se crea una factura vacia
    facturas[pos - 1] = f; // Se asigna la factura vacia a la ultima posicion
    pos--;                 // Dando como resultado que la factura se elimina
}

void pedirDato()
{
    FACTURA factura;
    cout << "ID: "; // Se piden los datos de la factura
    cin >> factura.id;
    cout << "Cliente: ";
    cin.ignore();                     // Se ignora el salto de linea
    cin.getline(factura.cliente, 30); // Se pide el nombre del cliente
    cout << "Cantidad: ";
    cin >> factura.cantidad;
    cout << "Precio: ";
    cin >> factura.precio;
    cout << "Fecha: ";
    cin.ignore();
    cin.getline(factura.fecha, 20);
    addFactura(&factura);
    writeFile(factura);
}

void mostrarTodo()
{
    for (int i = 0; i < pos; i++)
    {
        showData(facturas[i]);
    }
}

void editar()
{
    FACTURA factura;
    int id;
    cout << "ID de la factura a editar: ";
    cin >> id;
    if (findPos(id) == -1) // Se busxa en base al id de la factura
    {
        cout << "Factura no encontrada..." << endl;
        return;
    }
    factura = findFactura(id);
    cout << "Nuevo Cliente: ";
    cin.ignore();
    cin.getline(factura.cliente, 30);
    cout << "Nueva Cantidad: ";
    cin >> factura.cantidad;
    cout << "Nuevo Precio: ";
    cin >> factura.precio;
    cout << "Nueva Fecha: ";
    cin.ignore();
    cin.getline(factura.fecha, 20);

    updateFactura(&factura, id); // Se actualiza la factura
    cout << "Factura actualizada correctamente." << endl;
    saveAll(); // Guardando todo lo editado
}

void eliminar()
{
    int id;
    cout << "ID de la factura a eliminar: ";
    cin >> id;
    destroyFactura(id); // Se llama a la funcion destroyFactura para eliminar la factura
}

void buscarFactura()
{
    int id;
    cout << "ID de la factura a buscar: ";
    cin >> id;
    FACTURA factura = findFactura(id); // Se utiliza el puntero para buscar la factura usando al id de la factura
    if (factura.id != 0)               // Si la factura es diferente de 0 se muestra
    {
        showData(factura);
    }
    else
    {
        cout << "Factura no encontrada." << endl; // De lo contrario la factura no se encontro
    }
}

void showData(FACTURA &factura)
{
    cout << "ID: " << factura.id << endl;
    cout << "Cliente: " << factura.cliente << endl;
    cout << "Cantidad: " << factura.cantidad << endl;
    cout << "Precio: " << factura.precio << endl;
    cout << "Fecha: " << factura.fecha << endl;
}
void saveAll()
{
    ofstream file("facturas.txt"); // Se abre el archivo facturas.txt
    for (int i = 0; i < pos; i++)
    {
        file << facturas[i].id << " "
             << facturas[i].cliente << " "
             << facturas[i].cantidad << " "
             << facturas[i].precio << " "
             << facturas[i].fecha << endl;
    }
    file.close();
}

// Apartado de menu
int menu();
void principal();

int menu()
{
    int op;
    cout << "Menu\n";
    cout << "1. Agregar Factura\n";
    cout << "2. Mostrar Facturas\n";
    cout << "3. Buscar Factura\n";
    cout << "4. Editar Factura\n";
    cout << "5. Eliminar Factura\n";
    cin >> op;
    return op;
}

void principal()
{
    int op;
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            pedirDato();
            break;
        case 2:
            mostrarTodo();
            break;
        case 3:
            buscarFactura();
            break;
        case 4:
            editar();
            break;
        case 5:
            eliminar();
            break;
        }
    } while (op != 6);
}