#include <iostream>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    // Ejemplo de uso de gotoxy
    system("cls");  // Limpiar pantalla
    gotoxy(10, 5);
    cout << "Texto en la posición (10, 5)";
    gotoxy(20, 10);
    cout << "Texto en la posición (20, 10)";

    return 0;
}
