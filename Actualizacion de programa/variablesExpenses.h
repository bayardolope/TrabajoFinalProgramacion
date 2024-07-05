#ifndef VARIABLES_H
#define VARIABLES_H

#define MAX_EXPENSES 1000

typedef struct EXPENSE
{
    int id;
    char description[50];
    float amount;
};

extern EXPENSE expenses[MAX_EXPENSES];
extern int expenseCount;

#endif // VARIABLES_H