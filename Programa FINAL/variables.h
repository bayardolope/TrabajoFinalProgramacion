#ifndef VARIABLES_H
#define VARIABLES_H

#define MAX_REG 1000

typedef struct FACTURA {
    int id;
    char cliente[30];
    double cantidad;
    double precio;
    char fecha[20];
};

// Si pos es global, declararla como extern aquí


#endif // VARIABLES_H
