
#include <iostream>
#include "funcionesExpenses.cpp"
#include "funcionesIngresos.cpp"
#include "funciones_Facturas.cpp"

void principalExpenses();

int mainmenu(){
int opcion;
    cout << "1. Facturacion\n";
    cout << "2. Contabilidad";

}

int accountingMenu() {
    int opcion;
    cout << "Contabilidad\n";
    cout << "\n";
    cout << "1. Ingresos\n";
    cout << "2. Egresos\n";
    cout << "3. Salir\n";
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;

    int opcion;
    do {
        opcion = accountingMenu();
        switch (opcion) {
            case 1: {
                generarReporteDiario();
                break;
            }
            case 2:
                principalExpenses();
                break;
            case 3:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
        }
    } while (opcion != 3);
}

int main(){
     int op;
    do {
        op = mainmenu();
        switch (op) {
            case 1: {
                principalFactura();
                break;
            }
            case 2:
                accountingMenu();
                break;
            case 3:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
        }
    } while (op != 3);

    return 0;
}
