#include <iostream>
using namespace std;

#include "funcionesExpenses.cpp"
#include "funcionesIngresos.cpp"
#include "funciones_Facturas.cpp"

void principalExpenses();
void principalFactura();
void generarReporteDiario();

int mainmenu()
{
    int opcion;
cout << "  ____            _          ____  _                           "<< endl;
cout << " / ___|___  _ __ | |_ __ _  |  _ \\| |_   _ _ __ ___   __ _ ___ "<< endl;
cout << "| |   / _ \\| '_ \\| __/ _` | | |_) | | | | | '_ ` _ \\ / _` / __|"<< endl;
cout << "| |__| (_) | | | | || (_| | |  __/| | |_| | | | | | | (_| \\__ \\ "<< endl;
cout << " \\____\\___/|_| |_|\\__\\__,_| |_|   |_|\\__,_|_| |_| |_|\\__,_|___/ " << endl;
cout << "\n";


    cout << "1. Facturacion\n";
    cout << "2. Contabilidad\n";
    cout << "3. Salir\n";
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}

int accountingMenu()
{
    int opcion;
    cout << "Contabilidad\n";
    cout << "1. Ingresos\n";
    cout << "2. Egresos\n";
    cout << "3. Salir\n";
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}

void accountingProcess()
{
    int opcion;
    do
    {
        opcion = accountingMenu();
        switch (opcion)
        {
        case 1:
            generarReporteDiario();
            break;
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

int main()
{
    int op;
    do
    {
        op = mainmenu();
        switch (op)
        {
        case 1:
            principalFactura();
            break;
        case 2:
            accountingProcess();
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