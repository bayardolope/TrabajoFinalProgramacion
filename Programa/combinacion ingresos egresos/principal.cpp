#include <iostream>
#include "funcionesExpenses.cpp"
#include "funcionesIngresos.cpp"
void principalExpenses();

int accountingMenu() {
    int op;
    cout << "B. Contabilidad\n";
    cout << "\n";
    cout << "1. Ingresos\n";
    cout << "2. Egresos\n";
    cout << "3. Salir\n";
    cout << "Opcion: ";
    cin >> op;
    return op;
}
int main(){
     int op;
    do {
        op = accountingMenu();
        switch (op) {
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
    } while (op != 3);

    return 0;
}
