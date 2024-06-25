//Variables globales y estructuras, 
typedef struct VENTA {
    int numeroFactura;
    char nombreCliente[50];
    char nombreVendedor[50];
    int dia;
    int mes;
    int cantidadProducto;
    float precioPorProducto;
    float total;
};

#define MAX_REG 1000

int pos = 0;
