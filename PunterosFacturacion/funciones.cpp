#include <iostream>
#include <string.h>
#include "variables.h"
#include <fstream>
#include <cstdlib>
#include "funciones.h"

using namespace std;

FACTURA facturas[100];
int pos = 0;

// funciones

void addFactura(FACTURA *factura);
FACTURA findFactura(int id);
int findPos(int id);
void updateFactura(FACTURA *factura, int id);
void destroyFactura(int id);

void pedirDato();
void mostrarTodo();
void editar();
void eliminar();
void buscarPollo();
void showData(FACTURA &factura);
int menu();
void principal();
void saveAll();




// manejo de archivos
int loadPollos();
void writeFile(const FACTURA &factura);


void addFactura(FACTURA *factura)
{
    facturas[pos] = *factura;
    pos++;
}

FACTURA findFactura(int id)
{
    FACTURA factura;
    for (int i = 0; i < pos; i++)
    {
        if (facturas[i].id == id)
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
        if (facturas[i].id == id)
            return i;
    }
    return -1;
}

void updateFactura(FACTURA *factura, int id)
{
    int position = findPos(id);
    strcpy(facturas[position].name, factura->name);
    strcpy(facturas[position].description, factura->description);
    facturas[position].numPollos = factura->numPollos;
    facturas[position].precioPollos = factura->precioPollos;
    facturas[position].total = factura->total;
}

void destroyFactura(int id)
{
    int position = findPos(id);
    for (int i = position; i < pos - 1; i++)
    {
        facturas[i] = facturas[i + 1];
    }
    FACTURA f;
    facturas[pos - 1] = f;
    pos--;
}

// Menu de opciones
int menu(){
    int op;
    cout << "Menú Principal" << endl;
    cout << "1. Gestionar facturación" << endl;
    cout << "2. Mostrar facturas" << endl;
    cout << "3. Editar factura" << endl;
    cout << "4. Eliminar factura" << endl;
    cout << "5. Buscar factura" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opción: ";
    cin >> op;
    return op;

}
void principal(){
    int op;
    pos = loadPollos();
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
            editar();
            break;
        case 4:
            eliminar();
            break;
        case 5:
            buscarPollo();
            break;
        default:
            cout << "Opción no válida, por favor intente de nuevo." << endl;
            break;
        }
    } while (op != 6);
    
}


// Aqui se trabajan las funciones referentes a la gestion de facturacion

void pedirDato()
{
    FACTURA factura;
    cout << "Datos de la Factura" << endl;
    cout << "ID: ";
    cin >> factura.id;
    if (findPos(factura.id) != -1)
    {
        cout << "Registro ya existe..." << endl;
        return;
    }
    cout << "NOMBRE: ";
    scanf(" %[^\n]", factura.name);
    cout << "DESCRIPCION: ";
    scanf(" %[^\n]", factura.description);
    cout << "NUMERO DE POLLOS: ";
    cin >> factura.numPollos;
    cout << "PRECIO DE POLLOS: ";
    cin >> factura.precioPollos;
    cout << "TOTAL: ";
    cin >> factura.total;
    addFactura(&factura);
    writeFile(factura);
}

void mostrarTodo()
{
    cout << "Mostrar Registros\n";
    for (int i = 0; i < pos; i++)
    {
        showData(facturas[i]);
    }
}

void editar()
{
    FACTURA factura;
    int id;
    cout << "ID: ";
    cin >> id;
    if (findPos(id) == -1)
    {
        cout << "Registro no existe..." << endl;
        return;
    }
    factura = findFactura(id);
    cout << "NOMBRE: ";
    scanf(" %[^\n]", factura.name);
    cout << "DESCRIPCION: ";
    scanf(" %[^\n]", factura.description);
    cout << "NUMERO DE POLLOS: ";
    cin >> factura.numPollos;
    cout << "PRECIO DE POLLOS: ";
    cin >> factura.precioPollos;
    cout << "TOTAL: ";
    cin >> factura.total;
    updateFactura(&factura, id);
    saveAll();
    cout << "Registro actualizado...\n";
}

void eliminar()
{
    int id = 0;
    if (pos == 0)
    {
        cout << "No hay nada que eliminar\n";
        return;
    }
    cout << "ID de la factura a eliminar: ";
    cin >> id;
    if (findPos(id) == -1)
    {
        cout << "Registro no existe..." << endl;
        return;
    }
    destroyFactura(id);
    saveAll();
    cout << "Factura eliminada\n";
}

void buscarFactura()
{
    int id = 0;
    cout << "ID de la factura a buscar: ";
    cin >> id;
    if (findPos(id) == -1)
    {
        cout << "Registro no existe..." << endl;
        return;
    }

    FACTURA factura = findFactura(id);
    int x = findPos(id);

    cout << "\nFactura #" << x + 1 << ":\n";
    showData(factura);
}

void showData(FACTURA &factura)
{
    cout << "ID: " << factura.id << endl;
    cout << "Nombre: " << factura.name << endl;
    cout << "Descripcion: " << factura.description << endl;
    cout << "Numero de pollos: " << factura.numPollos << endl;
    cout << "Precio de pollos: " << factura.precioPollos << endl;
    cout << "Total: " << factura.total << endl;
}


int loadPollo(){
    ifstream archivo("facturas.txt");
    if (archivo.fail())
    {
        return 0;
    }
    int i = 0;
    while (archivo >> facturas[i].id)
    {
        archivo.ignore();
        archivo.getline(facturas[i].name, 30);
        archivo.getline(facturas[i].description, 100);
        archivo >> facturas[i].numPollos;
        archivo >> facturas[i].precioPollos;
        archivo >> facturas[i].total;
        i++;
    }
    archivo.close();
    return 1;
}

void writeFile(const FACTURA &factura)
{
    ofstream archivo;

    archivo.open("facturas.txt", ios::app);

    if (archivo.fail())
    {
        cout << "No se puede abrir archivo" << endl;
        exit(1);
    }

    archivo << factura.id << endl;
    archivo << factura.name << endl;
    archivo << factura.description << endl;
    archivo << factura.numPollos << endl;
    archivo << factura.precioPollos << endl;
    archivo << factura.total << endl;
    archivo.close();
}

void saveAll(){
    ofstream archivo;
    archivo.open("facturas.txt", ios::trunc | ios::out);
    for (int i = 0; i < pos; i++)
    {
        archivo << facturas[i].id << endl;
        archivo << facturas[i].name << endl;
        archivo << facturas[i].description << endl;
        archivo << facturas[i].numPollos << endl;
        archivo << facturas[i].precioPollos << endl;
        archivo << facturas[i].total << endl;
    }
    archivo.close();
}