#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <cstdlib>
using namespace std;

// Definiciones de estructuras y variables globales
struct FACTURA {
    int id;
    char name[30];
    char description[100];
    int numPollos;
    double precioPollos;
    double total;
};

FACTURA facturas[100];
int pos = 0;

// Declaración de funciones
void mostrarMenu();
char realizarOperacion();
void gestionarFacturacion(double &inventarioPollos);
void registrarVentas(double &inventarioPollos);
void consultarInventario(double inventarioPollos);
void generarReporteDiario();
void addFactura(FACTURA *factura);
FACTURA findFactura(int id);
int findPos(int id);
void updateFactura(FACTURA *factura, int id);
void destroyFactura(int id);
void pedirDato();
void mostrarTodo();
void editar();
void eliminar();
void buscarFactura();
void showData(FACTURA &factura);
int menu();
void principal();
void saveAll();
int loadPollos();
void writeFile(const FACTURA &factura);

void mostrarMenu()
{
    cout << "Menú Principal" << endl;
    cout << "1. Gestión de facturación a clientes" << endl;
    cout << "2. Registrar ventas diarias" << endl;
    cout << "3. Consultar inventario" << endl;
    cout << "4. Generar reporte diario" << endl;
    cout << "5. Mostrar facturas" << endl;
    cout << "6. Editar factura" << endl;
    cout << "7. Eliminar factura" << endl;
    cout << "8. Buscar factura" << endl;
    cout << "9. Salir" << endl;
    cout << "Seleccione una opción: ";
}

char realizarOperacion()
{
    int opcion;
    double inventarioPollos = 100; // Este es nuestro inventario inicial de pollos al día.
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        gestionarFacturacion(inventarioPollos);
        break;
    case 2:
        registrarVentas(inventarioPollos);
        break;
    case 3:
        consultarInventario(inventarioPollos);
        break;
    case 4:
        generarReporteDiario();
        break;
    case 5:
        mostrarTodo();
        break;
    case 6:
        editar();
        break;
    case 7:
        eliminar();
        break;
    case 8:
        buscarFactura();
        break;
    case 9:
        return 'N';
    default:
        cout << "Opción no válida, por favor intente de nuevo." << endl;
    }

    char continuar;
    cout << "¿Desea realizar otra operación? (S/N): ";
    cin >> continuar;
    return continuar;
}

void gestionarFacturacion(double &inventarioPollos)
{
    FACTURA factura;
    cout << "Ingresar datos del cliente" << endl;
    cout << "ID: ";
    cin >> factura.id;
    if (findPos(factura.id) != -1)
    {
        cout << "Registro ya existe..." << endl;
        return;
    }
    cout << "NOMBRE: ";
    cin.ignore();
    cin.getline(factura.name, 30);
    cout << "DESCRIPCIÓN: ";
    cin.getline(factura.description, 100);

    cout << "Ingresar cantidad de pollos comprados: ";
    cin >> factura.numPollos;
    while (factura.numPollos <= 0 || factura.numPollos > inventarioPollos)
    {
        cout << "Cantidad inválida. Ingrese una cantidad positiva y no mayor al inventario disponible (" << inventarioPollos << ")." << endl;
        cin >> factura.numPollos;
    }

    cout << "Ingresar precio por pollo: ";
    cin >> factura.precioPollos;
    while (factura.precioPollos <= 0)
    {
        cout << "Precio inválido. Ingrese un precio positivo." << endl;
        cin >> factura.precioPollos;
    }

    cout << "Total de la factura: $" << fixed << setprecision(2) << factura.numPollos * factura.precioPollos << endl;

    inventarioPollos -= factura.numPollos;
    addFactura(&factura);
    writeFile(factura);
    cout << "Factura guardada correctamente." << endl;
}

void registrarVentas(double &inventarioPollos)
{
    double cantidadVendida, precioPollo, totalVentasDiarias;

    cout << "Ingresar cantidad de pollos vendidos hoy: ";
    cin >> cantidadVendida;
    while (cantidadVendida <= 0 || cantidadVendida > inventarioPollos)
    {
        cout << "Cantidad inválida. Ingrese una cantidad positiva y no mayor al inventario disponible (" << inventarioPollos << ")." << endl;
        cin >> cantidadVendida;
    }

    cout << "Ingresar precio por pollo: ";
    cin >> precioPollo;
    while (precioPollo <= 0)
    {
        cout << "Precio inválido. Ingrese un precio positivo." << endl;
        cin >> precioPollo;
    }

    totalVentasDiarias = cantidadVendida * precioPollo;
    cout << fixed << setprecision(2) << "Total de ventas diarias: $" << totalVentasDiarias << endl;

    inventarioPollos -= cantidadVendida;
    cout << "Registro de ventas diarias guardado correctamente." << endl;
}

void consultarInventario(double inventarioPollos)
{
    cout << "Consultando inventario..." << endl;

    const int numPollos = 3;
    string nombresPollos[numPollos] = {"Pollo 1", "Pollo 2", "Pollo 3"};
    int cantidadesPollos[numPollos] = {10, 15, 20};
    double preciosPollos[numPollos] = {5.0, 6.0, 7.0};

    for (int i = 0; i < numPollos; i++)
    {
        cout << nombresPollos[i] << ": Cantidad: " << cantidadesPollos[i] << ", Precio: $" << preciosPollos[i] << endl;
    }
}

void generarReporteDiario()
{
    cout << "Generando reporte diario..." << endl;
    cout << "------------------------------------" << endl;
    cout << "Reporte diario... aún no terminado..." << endl;
}

void addFactura(FACTURA *factura)
{
    facturas[pos] = *factura;
    pos++;
}

FACTURA findFactura(int id)
{
    FACTURA factura;
    for (int i = 0; i < pos; i++)
    {
        if (facturas[i].id == id)
        {
            return facturas[i];
        }
    }
    return factura;
}

int findPos(int id)
{
    for (int i = 0; i < pos; i++)
    {
        if (facturas[i].id == id)
            return i;
    }
    return -1;
}

void updateFactura(FACTURA *factura, int id)
{
    int position = findPos(id);
    strcpy(facturas[position].name, factura->name);
    strcpy(facturas[position].description, factura->description);
    facturas[position].numPollos = factura->numPollos;
    facturas[position].precioPollos = factura->precioPollos;
    facturas[position].total = factura->total;
}

void destroyFactura(int id)
{
    int position = findPos(id);
    for (int i = position; i < pos - 1; i++)
    {
        facturas[i] = facturas[i + 1];
    }
    FACTURA f;
    facturas[pos - 1] = f;
    pos--;
}

void pedirDato()
{
    FACTURA factura;
    cout << "Datos de la Factura" << endl;
    cout << "ID: ";
    cin >> factura.id;
    if (findPos(factura.id) != -1)
    {
        cout << "Registro ya existe..." << endl;
        return;
    }
    cout << "NOMBRE: ";
    cin.ignore();
    cin.getline(factura.name, 30);
    cout << "DESCRIPCIÓN: ";
    cin.getline(factura.description, 100);
    cout << "NUMERO DE POLLOS: ";
    cin >> factura.numPollos;
    cout << "PRECIO DE POLLOS: ";
    cin >> factura.precioPollos;
    cout << "TOTAL: ";
    cin >> factura.total;
    addFactura(&factura);
    writeFile(factura);
}

void editar()
{
    FACTURA factura;
    int id;
    cout << "ID: ";
    cin >> id;
    if (findPos(id) == -1)
    {
        cout << "Registro no existe..." << endl;
        return;
    }
    factura = findFactura(id);
    cout << "NOMBRE: ";
    cin.ignore();
    cin.getline(factura.name, 30);
    cout << "DESCRIPCIÓN: ";
    cin.getline(factura.description, 100);
    cout << "NUMERO DE POLLOS: ";
    cin >> factura.numPollos;
    cout << "PRECIO DE POLLOS: ";
    cin >> factura.precioPollos;
    cout << "TOTAL: ";
    cin >> factura.total;
    updateFactura(&factura, id);
    saveAll();
    cout << "Registro actualizado...\n";
}

void eliminar()
{
    int id = 0;
    if (pos == 0)
    {
        cout << "No hay nada que eliminar\n";
        return;
    }
    cout << "ID de la factura a eliminar: ";
    cin >> id;
    if (findPos(id) == -1)
    {
        cout << "Registro no existe..." << endl;
        return;
    }
    destroyFactura(id);
    saveAll();
    cout << "Factura eliminada\n";
}

void buscarFactura()
{
    int id = 0;
    cout << "ID de la factura a buscar: ";
    cin >> id;
    if (findPos(id) == -1)
    {
        cout << "Registro no existe..." << endl;
        return;
    }

    FACTURA factura = findFactura(id);
    int x = findPos(id);

    cout << "\nFactura #" << x + 1 << ":\n";
    showData(factura);
}

void showData(FACTURA &factura)
{
    cout << "ID: " << factura.id << endl;
    cout << "Nombre: " << factura.name << endl;
    cout << "Descripcion: " << factura.description << endl;
    cout << "Numero de pollos: " << factura.numPollos << endl;
    cout << "Precio de pollos: " << factura.precioPollos << endl;
    cout << "Total: " << factura.total << endl;
}

int loadPollos()
{
    ifstream archivo("facturas.txt");
    if (archivo.fail())
    {
        return 0;
    }
    int i = 0;
    while (archivo >> facturas[i].id)
    {
        archivo.ignore();
        archivo.getline(facturas[i].name, 30);
        archivo.getline(facturas[i].description, 100);
        archivo >> facturas[i].numPollos;
        archivo >> facturas[i].precioPollos;
        archivo >> facturas[i].total;
        i++;
    }
    archivo.close();
    return i;
}

void writeFile(const FACTURA &factura)
{
    ofstream archivo;

    archivo.open("facturas.txt", ios::app);

    if (archivo.fail())
    {
        cout << "No se puede abrir archivo" << endl;
        exit(1);
    }

    archivo << factura.id << endl;
    archivo << factura.name << endl;
    archivo << factura.description << endl;
    archivo << factura.numPollos << endl;
    archivo << factura.precioPollos << endl;
    archivo << factura.total << endl;
    archivo.close();
}

void saveAll()
{
    ofstream archivo;
    archivo.open("facturas.txt", ios::trunc | ios::out);
    for (int i = 0; i < pos; i++)
    {
        archivo << facturas[i].id << endl;
        archivo << facturas[i].name << endl;
        archivo << facturas[i].description << endl;
        archivo << facturas[i].numPollos << endl;
        archivo << facturas[i].precioPollos << endl;
        archivo << facturas[i].total << endl;
    }
    archivo.close();
}

int main()
{
    char continuar;
    pos = loadPollos();
    do
    {
        mostrarMenu();
        continuar = realizarOperacion();
    } while (continuar == 'S' || continuar == 's');

    return 0;
}