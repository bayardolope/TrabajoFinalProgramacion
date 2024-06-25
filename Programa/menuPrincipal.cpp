#include <iostream>
#include "funciones.h"

using namespace std;

int main()
{
    char continuar = 'S';
    while (continuar == 'S' || continuar == 's')
    {
        mostrarMenu();
        continuar = realizarOperacion();
    }
    return 0;
}