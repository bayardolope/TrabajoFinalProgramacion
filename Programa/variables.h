#ifndef VARIABLES_H
#define VARIABLES_H

struct FACTURA
{
    int id;
    char name[30];
    char description[100];
    int numPollos;
    double precioPollos;
    double total;
};

extern FACTURA facturas[100];
extern int pos;

#endif
