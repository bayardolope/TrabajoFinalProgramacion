#include <iostream>
#include <string.h>
#include "variablesExpenses.h"
#include <fstream>
#include <cstdlib>

using namespace std;

EXPENSE expenses[MAX_EXPENSES];
int expenseCount = 0;

// Declaración de funciones
void addExpense(EXPENSE *expense);
void showExpenses();
void showExpenseSummary();
void loadExpenses();
void saveExpense(const EXPENSE &expense);
void searchExpense(int id);
void editExpense(int id);
void saveExpensesToFile();  

void addExpense(EXPENSE *expense) {
    if (expenseCount < MAX_EXPENSES) {
        expenses[expenseCount] = *expense;
        expenseCount++;
        saveExpense(*expense);
    } else {
        cout << "Maximo de egresos alcanzado" << endl;
    }
}

void showExpenses() {
    for (int i = 0; i < expenseCount; i++) {
        cout << "ID: " << expenses[i].id << endl;
        cout << "Descripción: " << expenses[i].description << endl;
        cout << "Monto: " << expenses[i].amount << endl;
        cout << "-----------------------------" << endl;
    }
}

void showExpenseSummary() {
    float totalExpenses = 0.0;

    for (int i = 0; i < expenseCount; i++) {
        totalExpenses += expenses[i].amount;
    }

    cout << "Total de egresos del dia: $" << totalExpenses << endl;
}

void loadExpenses() {
    ifstream archivo("expenses.txt");
    if (archivo.fail()) {
        return;
    }

    expenseCount = 0;
    while (archivo >> expenses[expenseCount].id) {
        archivo.ignore();
        archivo.getline(expenses[expenseCount].description, 50);
        archivo >> expenses[expenseCount].amount;
        expenseCount++;
    }
    archivo.close();
}

void saveExpense(const EXPENSE &expense) {
    ofstream archivo;

    archivo.open("expenses.txt", ios::app);
    if (archivo.fail()) {
        cout << "No se puede abrir archivo" << endl;
        exit(1);
    }

    archivo << expense.id << endl;
    archivo << expense.description << endl;
    archivo << expense.amount << endl;
    archivo.close();
}

void searchExpense(int id) {
    bool found = false;
    for (int i = 0; i < expenseCount; i++) {
        if (expenses[i].id == id) {
            cout << "ID: " << expenses[i].id << endl;
            cout << "Descripción: " << expenses[i].description << endl;
            cout << "Monto: " << expenses[i].amount << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Egreso con ID " << id << " no encontrado." << endl;
    }
}

void editExpense(int id) {
    bool found = false;
    for (int i = 0; i < expenseCount; i++) {
        if (expenses[i].id == id) {
            cout << "Egreso encontrado: " << endl;
            cout << "ID: " << expenses[i].id << endl;
            cout << "Descripción actual: " << expenses[i].description << endl;
            cout << "Monto actual: " << expenses[i].amount << endl;

            cout << "Nueva descripción: ";
            cin.ignore();
            cin.getline(expenses[i].description, 50);

            cout << "Nuevo monto: ";
            cin >> expenses[i].amount;

            saveExpensesToFile();
            cout << "Egreso actualizado exitosamente." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Egreso con ID " << id << " no encontrado." << endl;
    }
}

void saveExpensesToFile() {
    ofstream archivo("expenses.txt");
    if (archivo.fail()) {
        cout << "No se puede abrir archivo" << endl;
        exit(1);
    }

    for (int i = 0; i < expenseCount; i++) {
        archivo << expenses[i].id << endl;
        archivo << expenses[i].description << endl;
        archivo << expenses[i].amount << endl;
    }
    archivo.close();
}

// Menú principal de egresos

int expenseMenu() {
    int op;
    cout << "Menu de Egresos\n";
    cout << "1. Agregar Egreso\n";
    cout << "2. Mostrar Egresos\n";
    cout << "3. Mostrar Resumen de Egresos\n";
    cout << "4. Buscar Egreso\n";
    cout << "5. Editar Egreso\n";
    cout << "6. Salir\n";
    cout << "Opci0n: ";
    cin >> op;
    return op;
}

void principalExpenses() {
    loadExpenses();
    int op;
    do {
        op = expenseMenu();
        switch (op) {
            case 1: {
                EXPENSE expense;
                cout << "ID: ";
                cin >> expense.id;
                cout << "Descripcion: ";
                cin.ignore();
                cin.getline(expense.description, 50);
                cout << "Monto: ";
                cin >> expense.amount;
                addExpense(&expense);
                break;
            }
            case 2:
                showExpenses();
                break;
            case 3:
                showExpenseSummary();
                break;
            case 4: {
                int id;
                cout << "ID del egreso a buscar: ";
                cin >> id;
                searchExpense(id);
                break;
            }
            case 5: {
                int id;
                cout << "ID del egreso a editar: ";
                cin >> id;
                editExpense(id);
                break;
            }
            case 6:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while (op != 6);
}
