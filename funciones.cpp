#include <iostream>
#include <string.h>
#include "variables.h"
#include <fstream>
#include <cstdlib>

using namespace std;

SALE sales[MAX_SALES];
int saleCount = 0;

// Funciones
void addSale(SALE *sale);
void showSales();
void showSummary();
void loadSales();
void saveSale(const SALE &sale);
void totalventasdiarias();

void addSale(SALE *sale) {
    if (saleCount < MAX_SALES) {
        sales[saleCount] = *sale;
        saleCount++;
        saveSale(*sale);
    } else {
        cout << "Maximo de ventas alcanzado" << endl;
    }
}

void showSales() {
    for (int i = 0; i < saleCount; i++) {
        cout << "ID: " << sales[i].id << endl;
        cout << "Producto: " << sales[i].product << endl;
        cout << "Cantidad: " << sales[i].quantity << endl;
        cout << "Precio: " << sales[i].price << endl;
        cout << "-----------------------------" << endl;
    }
}

void showSummary() {
    int totalProducts = 0;
    float totalRevenue = 0.0;

    for (int i = 0; i < saleCount; i++) {
        totalProducts += sales[i].quantity;
        totalRevenue += (sales[i].quantity * sales[i].price);
    }

    cout << "Total de productos vendidos: " << totalProducts << endl;
    cout << "Total de ingresos del dia: C$" << totalRevenue << endl;
}

void loadSales() {
    ifstream archivo("sales.txt");
    if (archivo.fail()) {
        return;
    }

    saleCount = 0;
    while (archivo >> sales[saleCount].id) {
        archivo.ignore();
        archivo.getline(sales[saleCount].product, 30);
        archivo >> sales[saleCount].quantity;
        archivo >> sales[saleCount].price;
        saleCount++;
    }
    archivo.close();
}

void saveSale(const SALE &sale) {
    ofstream archivo;

    archivo.open("sales.txt", ios::app);
    if (archivo.fail()) {
        cout << "No se puede abrir archivo" << endl;
        exit(1);
    }

    archivo << sale.id << endl;
    archivo << sale.product << endl;
    archivo << sale.quantity << endl;
    archivo << sale.price << endl;
    archivo.close();
}

int menu() {
    int op;
    cout << "Menu\n";
    cout << "1. Agregar Venta\n";
    cout << "2. Mostrar Ventas\n";
    cout << "3. Mostrar Resumen\n";
    cout << "4. Salir\n";
    cout << "Opcion: ";
    cin >> op;
    return op;
}

void principal() {
    loadSales();
    int op;
    do {
        op = menu();
        switch (op) {
            case 1: {
                SALE sale;
                cout << "ID: ";
                cin >> sale.id;
                cout << "Producto: ";
                cin.ignore();
                cin.getline(sale.product, 30);
                cout << "Cantidad: ";
                cin >> sale.quantity;
                cout << "Precio: ";
                cin >> sale.price;
                addSale(&sale);
                break;
            }
            case 2:
                showSales();
                break;
            case 3:
                showSummary();
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
        }
    } while (op != 4);
}
