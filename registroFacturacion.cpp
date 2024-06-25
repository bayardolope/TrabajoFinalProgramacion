#include <iostream>
#include <fstream>
#include <cstring>
#include "variables.h" 

using namespace std;

void mostrarVenta(const Venta& venta);
void mostrarVentas(Venta ventas[], int numVentas);
void escribirVentasEnArchivo(Venta ventas[], int numVentas);
int leerVentasDesdeArchivo(Venta ventas[]);
void editarVenta(Venta &venta);
void eliminarVenta(Venta ventas[], int &numVentas);
void registrarVentas(Venta ventas[], int &numVentas);
void editarVentaSeleccionada(Venta ventas[], int numVentas);
void menuPrincipal(Venta ventas[], int &numVentas);


void mostrarVenta(const Venta& venta) {
    cout << "Numero de Factura: " << venta.numeroFactura << endl;
    cout << "Nombre del Cliente: " << venta.nombreCliente << endl;
    cout << "Nombre del Vendedor: " << venta.nombreVendedor << endl;
    cout << "Fecha: " << venta.dia << "/" << venta.mes << endl;
    cout << "Cantidad de pollos: " << venta.cantidadPollos << endl;
    cout << "Precio por pollo: " << venta.precioPorPollo << endl;
    cout << "Total: " << venta.total << endl;
    cout << "--------------------------" << endl;
}

void mostrarVentas(Venta ventas[], int numVentas) {
    for (int i = 0; i < numVentas; i++) {
        cout << "Venta " << i + 1 << ":\n";
        mostrarVenta(ventas[i]);
    }
}

void escribirVentasEnArchivo(Venta ventas[], int numVentas) {
    ofstream archivo("ventas.txt");

    for (int i = 0; i < numVentas; i++) {
        archivo << ventas[i].numeroFactura << '\n';
        archivo << ventas[i].nombreCliente << '\n';
        archivo << ventas[i].nombreVendedor << '\n';
        archivo << ventas[i].dia << ' ' << ventas[i].mes << '\n';
        archivo << ventas[i].cantidadPollos << '\n';
        archivo << ventas[i].precioPorPollo << '\n';
        archivo << ventas[i].total << '\n';
    }

    archivo.close();
}

int leerVentasDesdeArchivo(Venta ventas[]) {
    ifstream archivo("ventas.txt");
    int numVentas = 0;

    while (archivo >> ventas[numVentas].numeroFactura) {
        archivo.ignore();  
        archivo.getline(ventas[numVentas].nombreCliente, 50);
        archivo.getline(ventas[numVentas].nombreVendedor, 50);
        archivo >> ventas[numVentas].dia >> ventas[numVentas].mes;
        archivo >> ventas[numVentas].cantidadPollos;
        archivo >> ventas[numVentas].precioPorPollo;
        archivo >> ventas[numVentas].total;
        archivo.ignore(); 
        numVentas++;
    }

    archivo.close();
    return numVentas;
}

void editarVenta(Venta &venta) {
    cout << "Editar Venta " << endl;
    cout << "Número de Factura (actual: " << venta.numeroFactura << "): ";
    cin >> venta.numeroFactura;
    cout << "Nombre del Cliente (actual: " << venta.nombreCliente << "): ";
    cin.ignore();
    cin.getline(venta.nombreCliente, 50);
    cout << "Nombre del Vendedor (actual: " << venta.nombreVendedor << "): ";
    cin.getline(venta.nombreVendedor, 50);
    cout << "Día (actual: " << venta.dia << "): ";
    cin >> venta.dia;
    cout << "Mes (actual: " << venta.mes << "): ";
    cin >> venta.mes;
    cout << "Cantidad de pollos (actual: " << venta.cantidadPollos << "): ";
    cin >> venta.cantidadPollos;
    cout << "Precio por pollo (actual: " << venta.precioPorPollo << "): ";
    cin >> venta.precioPorPollo;
    venta.total = venta.cantidadPollos * venta.precioPorPollo;
}

void eliminarVenta(Venta ventas[], int &numVentas) {
    int indice;
    cout << "Ingrese el numero de la venta a eliminar (1-" << numVentas << "): ";
    cin >> indice;
    if (indice >= 1 && indice <= numVentas) {
        for (int i = indice - 1; i < numVentas - 1; i++) {
            ventas[i] = ventas[i + 1];
        }
        numVentas--;
        escribirVentasEnArchivo(ventas, numVentas);
        cout << "Venta eliminada y actualizada en el archivo." << endl;
    } else {
        cout << "Número de venta inválido.\n";
    }
}

void registrarVentas(Venta ventas[], int &numVentas) {
    int dia, mes;
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el mes: ";
    cin >> mes;

    int nuevasVentas;
    cout << "Ingrese el numero de ventas del dia: ";
    cin >> nuevasVentas;

    for (int i = numVentas; i < numVentas + nuevasVentas; i++) {
        cout << "Venta " << i + 1 << ":\n";
        cout << "Numero de Factura: ";
        cin >> ventas[i].numeroFactura;
        cout << "Nombre del Cliente: ";
        cin.ignore();
        cin.getline(ventas[i].nombreCliente, 50);
        cout << "Nombre del Vendedor: ";
        cin.getline(ventas[i].nombreVendedor, 50);
        ventas[i].dia = dia;
        ventas[i].mes = mes;
        cout << "Cantidad de pollos: ";
        cin >> ventas[i].cantidadPollos;
        cout << "Precio por pollo: ";
        cin >> ventas[i].precioPorPollo;
        ventas[i].total = ventas[i].cantidadPollos * ventas[i].precioPorPollo;
    }

    numVentas += nuevasVentas;
    escribirVentasEnArchivo(ventas, numVentas);
    cout << "Las ventas han sido registradas" << endl;
}

void editarVentaSeleccionada(Venta ventas[], int numVentas) {
    int indice;
    cout << "Ingrese el numero de la venta a editar (1-" << numVentas << "): ";
    cin >> indice;
    if (indice >= 1 && indice <= numVentas) {
        editarVenta(ventas[indice - 1]);
        escribirVentasEnArchivo(ventas, numVentas);
        cout << "Venta editada y guardada en el archivo." << endl;
    } else {
        cout << "Numero de venta inválido.\n";
    }
}

void menuPrincipal(Venta ventas[], int &numVentas) {
    int opcion;
    do {
        cout << "\nOpciones:\n";
        cout << "1. Registrar ventas\n";
        cout << "2. Editar una venta\n";
        cout << "3. Eliminar una venta\n";
        cout << "4. Mostrar ventas\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarVentas(ventas, numVentas);
                break;
            case 2:
                editarVentaSeleccionada(ventas, numVentas);
                break;
            case 3:
                eliminarVenta(ventas, numVentas);
                break;
            case 4:
                mostrarVentas(ventas, numVentas);
                break;
            case 5:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 5);
}

int main() {
    Venta ventas[100];
    int numVentas = leerVentasDesdeArchivo(ventas);

    menuPrincipal(ventas, numVentas);

    return 0;
}

