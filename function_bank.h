#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include <stdint.h>
#include "appconst_bank.h"

typedef struct _slist_ Slist;
struct _slist_{
    int32_t count;
    Slist *head;
    Slist *tail;
    char* name;
};

typedef struct _node_ Node;
struct _node_{
    char* name;
    char* branch;
    char* acc_type;
    int32_t balance;
    int32_t acc_number;
    Node *next;
};

typedef struct _customer_ Customer;
struct _customer_{
    int32_t countc;
    Node *rear;
    Node *front;
    Customer* next;
};



typedef struct _queue_result_ QueueResult;
struct _queue_result_{
    int32_t acc_number;
    uint8_t status;
};

typedef struct _transaction_ Transaction;
struct _transaction_{
    int* branch;
    int* acc_type;
    int32_t acc_number;
    int32_t balance;
    uint32_t t_status;
};

Customer queue_new();
Slist Slist_new();
Customer* new(Slist* s,Customer *c,char* name,int* acc_type,int32_t balance,int32_t acc_number,int* branch,QueueResult *res, Transaction *t);
Customer* debit(Slist* s,Customer *c,QueueResult *res,Transaction *t,char* name,int32_t balance);
Customer* credit(Slist* s,Customer *c,char* name,int32_t balance,int* branch,QueueResult *res,Transaction *t);
int32_t list(const Slist *s,const Customer* c,char *name);
int8_t minimum_balance(int32_t balance);









#endif // TRADINGQ_H_INCLUDED
