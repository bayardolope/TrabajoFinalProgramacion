#include <iostream>
#include <string.h>
#include "variablesIngresos.h"
#include <fstream>
#include <cstdlib>

using namespace std;

FACTURA facturas[MAX_REG];
int pos = 0;

// Funcion

void generarReporteDiario();

void generarReporteDiario() {
    int totalVentas = 0;    
    double totalGanancias = 0.0;

    for (int i = 0; i < pos; i++) {
        totalVentas++;
        totalGanancias += facturas[i].cantidad * facturas[i].precio;
    }
    cout << "Reporte de Ventas\n";
    cout << "Total de Ventas Realizadas: " << totalVentas << endl;
    cout << "Total de Ganancias: C$" << totalGanancias << endl;
    cout << "Reporte de ganancias generales." << endl;

    // .txt
    ofstream archivoGanancias("ganancias.txt");
    if (archivoGanancias.is_open()) {
        archivoGanancias << "Reporte de Ventas\n";
        archivoGanancias << "Total de Ventas Realizadas: " << totalVentas << endl;
        archivoGanancias << "Total de Ganancias: C$" << totalGanancias << endl;
        archivoGanancias << "Reporte de ganancias generales." << endl;
        archivoGanancias << "--------------------------" << endl; // Separador para cada reporte
        archivoGanancias.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}