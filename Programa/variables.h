#define MAX_REG 1000
#define MAX_100

typedef struct FACTURA{
    int id;
    char name[30];
    char description[100];
    int numPollos;
    int precioPollos;
    int total;
};