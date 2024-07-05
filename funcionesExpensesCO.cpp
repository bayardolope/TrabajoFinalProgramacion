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
float calculateTotalExpenses();
bool expenseExists(int id);

void addExpense(EXPENSE *expense) {
    if (expense->amount < 0) {
        cout << "El monto del egreso no puede ser negativo." << endl;
        return;
    }

    if (expenseExists(expense->id)) {
        cout << "Ya existe un egreso con el ID " << expense->id << "." << endl;
        return;
    }

    if (expenseCount < MAX_EXPENSES) {
        expenses[expenseCount] = *expense;
        expenseCount++;
        saveExpense(*expense);
    } else {
        cout << "Máximo de egresos alcanzado" << endl;
    }
}

bool expenseExists(int id) {
    for (int i = 0; i < expenseCount; i++) {
        if (expenses[i].id == id) {
            return true;
        }
    }
    return false;
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
    float totalExpenses = calculateTotalExpenses();
    cout << "Total de egresos del día: $" << totalExpenses << endl;
}

float calculateTotalExpenses() {
    float totalExpenses = 0.0;
    for (int i = 0; i < expenseCount; i++) {
        totalExpenses += expenses[i].amount;
    }
    return totalExpenses;
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
    for (int i = 0; i < expenseCount; i++) {
        if (expenses[i].id == id) {
            cout << "Egreso encontrado:" << endl;
            cout << "ID: " << expenses[i].id << endl;
            cout << "Descripción: " << expenses[i].description << endl;
            cout << "Monto: " << expenses[i].amount << endl;
            return;
        }
    }
    cout << "Egreso no encontrado" << endl;
}

void editExpense(int id) {
    for (int i = 0; i < expenseCount; i++) {
        if (expenses[i].id == id) {
            cout << "Editar egreso:" << endl;
            cout << "Nueva descripción: ";
            cin.ignore();
            cin.getline(expenses[i].description, 50);
            cout << "Nuevo monto: ";
            cin >> expenses[i].amount;
            if (expenses[i].amount < 0) {
                cout << "El monto del egreso no puede ser negativo." << endl;
                return;
            }
            saveExpensesToFile();
            return;
        }
    }
    cout << "Egreso no encontrado" << endl;
}

void saveExpensesToFile() {
    ofstream archivo;

    archivo.open("expenses.txt");
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
    cout << "Menú de Egresos\n";
    cout << "1. Agregar Egreso\n";
    cout << "2. Mostrar Egresos\n";
    cout << "3. Mostrar Resumen de Egresos\n";
    cout << "4. Buscar Egreso\n";
    cout << "5. Editar Egreso\n";
    cout << "6. Calcular Egresos Totales\n";
    cout << "7. Salir\n";
    cout << "Opción: ";
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
                if (expenseExists(expense.id)) {
                    cout << "Ya existe un egreso con el ID " << expense.id << "." << endl;
                    break;
                }
                cout << "Descripción: ";
                cin.ignore();
                cin.getline(expense.description, 50);
                cout << "Monto: ";
                cin >> expense.amount;
                if (expense.amount < 0) {
                    cout << "El monto del egreso no puede ser negativo." << endl;
                    break;
                }
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
            case 6: {
                float totalExpenses = calculateTotalExpenses();
                cout << "Total de egresos: $" << totalExpenses << endl;
                break;
            }
            case 7:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
        }
    } while (op != 7);
}
