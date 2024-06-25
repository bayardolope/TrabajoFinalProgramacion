#define MAX_REG 1000

struct Venta {
    int numeroFactura;
    char nombreCliente[50];
    char nombreVendedor[50];
    int dia;
    int mes;
    int cantidadPollos;
    float precioPorPollo;
    float total;
};