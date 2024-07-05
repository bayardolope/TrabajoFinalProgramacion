#include <iostream>
#include <string.h>
#include "variables.h"
#include <fstream>
#include <cstdlib>

using namespace std;

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
int menuFactura();
void principalFactura();
int loadFile();

// Implementacion de las funciones
void addFactura(FACTURA *factura) // Factura *factura es un puntero a una estructura FACTURA
{
    facturas[pos] = *factura; // Se asigna la estructura FACTURA a la posicion pos del arreglo facturas
    pos++;                    // Cada que finaliza una factura se incrementa la variable
}

FACTURA findFactura(int id)
{
    FACTURA factura = {}; 
    int i = findPos(id);  
    if (i != -1)
    {
        factura = facturas[i]; 
    }
    else
    {
        cout << "Factura no encontrada." << endl;
    }
    return factura;
}

int findPos(int id)
{
    for (int i = 0; i < pos; i++)
    {
        if (facturas[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void updateFactura(FACTURA *factura, int id)
{
    int i = findPos(id);
    if (i != -1)
    {
        facturas[i] = *factura;
    }
    else
    {
        cout << "Factura no encontrada." << endl;
    }
}

void destroyFactura(int id)
{
    int i = findPos(id);
    if (i != -1)
    {
        for (int j = i; j < pos - 1; j++)
        {
            facturas[j] = facturas[j + 1];
        }
        pos--;
    }
    else
    {
        cout << "Factura no encontrada." << endl;
    }
}

void buscarFactura()
{
    int id;
    cout << "Ingrese el ID de la factura a buscar: ";
    cin >> id;
    FACTURA factura = findFactura(id);
    if (factura.id != 0) 
    {
        showData(factura);
    }
}

void showData(FACTURA &factura)
{
    double total = factura.cantidad * factura.precio;
    cout << "ID: " << factura.id << endl;
    cout << "Cliente: " << factura.cliente << endl;
    cout << "Cantidad: " << factura.cantidad << endl;
    cout << "Precio: $" << factura.precio << endl;
    cout << "Fecha: " << factura.fecha << endl;
    cout << "Total: $" << total << endl; 
}

void writeFile(const FACTURA &factura)
{
    ofstream file("facturas.txt", ios::app);
    file << factura.id << " "
         << factura.cliente << " "
         << factura.cantidad << " "
         << factura.precio << " "
         << factura.fecha << endl;
    file.close();
}

void pedirDato()
{
    FACTURA factura;
    do 
    {
        cout << "El ID no puede ser negativo o repetido." << endl;
        cout << "Ingrese ID: ";
        cin >> factura.id;
    } while (findPos(factura.id) != -1 || factura.id < 0);
    cout << "Ingrese cliente: ";
    cin >> factura.cliente;
    do
    {
        cout << "Ingrese cantidad: ";
        cin >> factura.cantidad;
        if (factura.cantidad < 0) {
            cout << "La cantidad no puede ser menor que 0. Intentelo de nuevo." << endl;
        }
    } while (factura.cantidad < 0);
    do
    {
        cout << "Ingrese precio: ";
        cin >> factura.precio;
        if (factura.precio < 0) {
            cout << "El precio no puede ser menor que 0. Intentelo de nuevo." << endl;
        }
    } while (factura.precio < 0);
    cout << "Ingrese fecha (XX/XX): ";
    cin >> factura.fecha;
    addFactura(&factura);
    writeFile(factura);
}

void mostrarTodo()
{
    if (pos == 0)
    {
        cout << "No hay facturas que mostrar." << endl;
    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            showData(facturas[i]);
        }
    }
}

void editar()
{
    int id;
    cout << "Ingrese el ID de la factura a editar: ";
    cin >> id;
    int i = findPos(id);
    if (i != -1)
    {
        FACTURA factura;
        cout << "Ingrese nuevo cliente: ";
        cin >> factura.cliente;
        do
        {
            cout << "Ingrese nueva cantidad: ";
            cin >> factura.cantidad;
            if (factura.cantidad < 0) {
                cout << "La cantidad no puede ser menor que 0. Intentelo de nuevo." << endl;
            }
        } while (factura.cantidad < 0);
        do
        {
            cout << "Ingrese nuevo precio: ";
            cin >> factura.precio;
            if (factura.precio < 0) {
                cout << "El precio no puede ser menor que 0. Intentelo de nuevo." << endl;
            }
        } while (factura.precio < 0);
        cout << "Ingrese nueva fecha: ";
        cin >> factura.fecha;
        factura.id = id;
        updateFactura(&factura, id);
    }
    else
    {
        cout << "Factura no encontrada." << endl;
    }
    saveAll();
}

void eliminar()
{
    int id;
    cout << "Ingrese el ID de la factura a eliminar: ";
    cin >> id;
    destroyFactura(id);
    saveAll();
}

void saveAll()
{
    ofstream file("facturas.txt");
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

int loadFile()
{
    ifstream file("facturas.txt");
    if(file.fail()){
        return 0;
    }
    int i = 0;
    while (file >> facturas[i].id)
    {
        file.ignore();
        file >> facturas[i].cliente;
        file >> facturas[i].cantidad;
        file >> facturas[i].precio;
        file >> facturas[i].fecha;
        i++;
    }
    file.close();
    return i;
}

int menuFactura()
{
    int op;
    cout << "Menu\n";
    cout << "1. Agregar Factura\n";
    cout << "2. Buscar Factura\n";
    cout << "3. Editar Factura\n";
    cout << "4. Eliminar Factura\n";
    cout << "5. Mostrar Todo\n";
    cout << "6. Salir\n";
    cout << "Opcion: ";
    cin >> op;
    return op;
}

void principalFactura()
{
    int op;
    pos = loadFile();
    do
    {
        op = menuFactura();
        switch (op)
        {
        case 1:
            pedirDato();
            break;
        case 2:
            buscarFactura();
            break;
        case 3:
            editar();
            break;
        case 4:
            eliminar();
            break;
        case 5:
            mostrarTodo();
            break;
        }
    } while (op != 6);
    saveAll();
}