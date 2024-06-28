#include <iostream>
#include <string.h>
#include "variables.h"
#include <fstream>
#include <cstdlib>
using namespace std;

FACTURA facturas[MAX_REG];
int pos = 0;

// Funciones

void generarReporteDiario();
void addFactura(FACTURA *factura);
FACTURA findFactura(int id);
int findPos(int id);
void updateFactura(FACTURA *factura, int id);
void destroyFactura(int id);
void pedirDato();
void mostrarTodo();
void editar();
void eliminar();
void buscarFactura();
void showData(FACTURA &factura);
int menu();
void principal();
void saveAll();
int loadPollos();
void writeFile(const FACTURA &factura);
void totalgananciasventas();

// Implementación de funciones
void addFactura(FACTURA *factura) {
    facturas[pos] = *factura;
    pos++;
}

FACTURA findFactura(int id) {
    FACTURA factura;
    for (int i = 0; i < pos; i++) {
        if (facturas[i].id == id) {
            return facturas[i];
        }
    }
    return factura;
}

int findPos(int id) {
    for (int i = 0; i < pos; i++) {
        if (facturas[i].id == id) return i;
    }
    return -1;
}

void updateFactura(FACTURA *factura, int id) {
    int position = findPos(id);
    strcpy(facturas[position].cliente, factura->cliente);
    facturas[position].cantidad = factura->cantidad;
    facturas[position].precio = factura->precio;
    strcpy(facturas[position].fecha, factura->fecha);
}

void destroyFactura(int id) {
    int position = findPos(id);
    for (int i = position; i < pos - 1; i++) {
        facturas[i] = facturas[i + 1];
    }
    FACTURA f;
    facturas[pos - 1] = f;
    pos--;
}

void pedirDato() {
    FACTURA factura;
    cout << "ID: ";
    cin >> factura.id;
    cout << "Cliente: ";
    cin.ignore();
    cin.getline(factura.cliente, 30);
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

void mostrarTodo() {
    for (int i = 0; i < pos; i++) {
        showData(facturas[i]);
    }
}

void editar() {
    FACTURA factura;
    int id;
    cout << "ID de la factura a editar: ";
    cin >> id;
    if (findPos(id) == -1) {
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
    
    updateFactura(&factura, id);
    cout << "Factura actualizada correctamente." << endl;
    saveAll(); 
}




void eliminar() {
    int id;
    cout << "ID de la factura a eliminar: ";
    cin >> id;
    destroyFactura(id);
}

void buscarFactura() {
    int id;
    cout << "ID de la factura a buscar: ";
    cin >> id;
    FACTURA factura = findFactura(id);
    if (factura.id != 0) {
        showData(factura);
    } else {
        cout << "Factura no encontrada." << endl;
    }
}

void showData(FACTURA &factura) {
    cout << "ID: " << factura.id << endl;
    cout << "Cliente: " << factura.cliente << endl;
    cout << "Cantidad: " << factura.cantidad << endl;
    cout << "Precio: " << factura.precio << endl;
    cout << "Fecha: " << factura.fecha << endl;
}


 int menu() {
    int op;
    cout << "Menu\n";
    cout << "1. Agregar Factura\n"; 
    cout << "2. Buscar Factura\n";   
    cout << "3. Editar Factura\n";
    cout << "4. Eliminar Factura\n";
    cout << "5. Generar Reporte Diario\n";
    cout << "6. Mostrar Todo\n";
    cout << "7. Guardar Todo\n";
    cout << "8. Cargar Pollos\n";
    cout << "9. Salir\n";
    cout << "Opcion: ";
    cin >> op;
    return op;
}




void generarReporteDiario() {
     int totalVentas = 0;
    double totalGanancias = 0.0;

    for (int i = 0; i < pos; i++) {
        totalVentas++;
        totalGanancias += facturas[i].cantidad * facturas[i].precio;
    }

    cout << "Reporte Diario de Ventas\n";
    cout << "Total de Ventas Realizadas: " << totalVentas << endl;
    cout << "Total de Ganancias: C$" << totalGanancias << endl;
    cout << "Reporte diario generado." << endl;
}

void saveAll() {
    ofstream file("facturas.txt");
    for (int i = 0; i < pos; i++) {
        file << facturas[i].id << " "
             << facturas[i].cliente << " "
             << facturas[i].cantidad << " "
             << facturas[i].precio << " "
             << facturas[i].fecha << endl;
    }
    file.close();
}

int loadPollos() {
    ifstream file("facturas.txt");
    if (!file) {
        return 100; 
    }
    while (!file.eof()) {
        FACTURA factura;
        file >> factura.id >> factura.cliente >> factura.cantidad >> factura.precio >> factura.fecha;
        if (!file.eof()) {
            facturas[pos] = factura;
            pos++;
        }
    }
    file.close();
    return 100; 
}

void writeFile(const FACTURA &factura) {
    ofstream file("facturas.txt", ios::app);
    file << factura.id << " "
         << factura.cliente << " "
         << factura.cantidad << " "
         << factura.precio << " "
         << factura.fecha << endl;
    file.close();
}

void principal() {
    int op;
    double inventarioPollos = loadPollos();
    do {
        op = menu();
        switch (op) {
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
               generarReporteDiario();
                break;
            case 6:
               mostrarTodo();
                break;
            case 7:
                saveAll();
                break;
            case 8:
                inventarioPollos = loadPollos();
                break;
        }
    } while (op != 9);
    saveAll();
}