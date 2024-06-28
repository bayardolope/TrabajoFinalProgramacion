#define MAX_SALES 1000

typedef struct SALE {
    int id;
    char product[30];
    int quantity;
    float price;
};

extern SALE sales[MAX_SALES];
extern int saleCount;
