#include <iostream>
#include "funciones.h"
#include "variables.h"
#include "windows.h"
#include "auxiliar.h"

using namespace std;

int main()
{
    double inventarioPollos = 100.0;
    // hay un problema al ejecutarlo

    char continuar = 'S';

    while (continuar == 'S' || continuar == 's')
    {
        mostrarMenu();
        continuar = realizarOperacion();
    }

    cout << "Gracias por usar el sistema de gestión de pollos. ¡Hasta luego!" << endl;

    return 0;
}
