#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>
#include "function.h"
#include <assert.h>
#include <stdlib.h>

void test_list(){
    Slist s1= Slist_new();
    Slist *s = &s1;
    assert(s->count == 0);
}

void test_customer(){
    Customer c1 = queue_new();
    Customer *c = &c1;
    assert(c->countc == 0);
}

void test_new(){
    Slist s1= Slist_new();
    Slist *s = &s1;
    assert(s->count == 0);
    Customer c1 = queue_new();
    Customer *c = &c1;
    assert(c->countc == 0);
    QueueResult res;
    Transaction t;
    c = enqueue(s, c,'sa', 10, 3000, 1002, 22, &res, &t);
    assert(res.status == QUEUE_OK);
    c = enqueue(s, c,'uv', 11, 4000, 2003, 22, &res, &t);
    assert(res.status == QUEUE_OK);
    c = enqueue(s, c,'rp', 12, 1000, 3004, 22, &res, &t);
    assert(res.status == QUEUE_OK);
    c = enqueue(s, c,'rr', 13, 2000, 4005, 22, &res, &t);
    assert(res.status == QUEUE_OK);
    c = enqueue(s, c,'xf', 14, 5000, 5006, 22, &res, &t);
    assert(res.status == QUEUE_OK);
    c = enqueue(s, c,'fd', 14, 400, 5007, 22, &res, &t);
    assert(res.status == QUEUE_OK);
    assert(t.t_status = CREDIT);
}

void test_debit(){
    Slist s1= Slist_new();
    Slist *s = &s1;
    assert(s->count==0);
    Customer c1 = queue_new();
    Customer *c = &c1;
    assert(c->countc==0);
    QueueResult res;
    Transaction t;
    c = enqueue(s, c,'rp', 12, 1000, 3004, 22, &res, &t);
    assert(res.status == QUEUE_OK);
    c = dequeue(s, c, &res, &t,'rr', 1000);
    assert(res.status == QUEUE_OK);
    assert(res.acc_number == 1000);
    assert(t.t_status = DEBIT);
    assert(t.acc_number == 1000);
}

void test_lookup(){
    Slist s1= Slist_new();
    Slist *s = &s1;
    assert(s->count == 0);
    Customer c1 = queue_new();
    Customer *c = &c1;
    assert(c->countc == 0);
    QueueResult res;
    Transaction t;
    c = enqueue(s, c,'sa', 10, 3000, 1002, 22, &res, &t);
    assert(res.status == QUEUE_OK);
    assert(lookup(s,c,'sa')==1);


}
void test_credit(){
    Slist s1= Slist_new();
    Slist *s = &s1;
    assert(s->count == 0);
    Customer c1 = queue_new();
    Customer *c = &c1;
    assert(c->countc == 0);
    QueueResult res;
    Transaction t;
    c = enqueue(s, c,'sa', 10, 3000, 1002, 22, &res, &t);
    assert(res.status == QUEUE_OK);
    c = topup(s, c, 'sa', 1000, 22, &res, &t);
    assert(res.status == QUEUE_OK);
    assert(res.acc_number == 1000);
    assert(t.t_status == CREDIT);

}

int main()
{
    //test_list();
    //test_customer();
    //test_enqueue();
    //test_dequeue();
    //test_lookup();
    //test_topup();
    return 0;
}
