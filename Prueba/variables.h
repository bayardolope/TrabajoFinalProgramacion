#define MAX_REG 1000

struct FACTURA {
    int id;
    char cliente[30];
    double cantidad;
    double precio;
    char fecha[20];
};

FACTURA facturas[MAX_REG];
int pos = 0;
