#include <iostream>
#include "funciones.h"
#include "variables.h"

using namespace std;

int main() {
    double inventarioPollos = 100.0; 
  //como resolver ese problema de inventarioPollos ?

    char continuar = 'S';

    while (continuar == 'S' || continuar == 's') {
        mostrarMenu();
        continuar = realizarOperacion();
    }

    cout << "Gracias por usar el sistema de gestión de pollos. ¡Hasta luego!" << endl;

    return 0;
}
