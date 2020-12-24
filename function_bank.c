
#include <stdint.h>
#include "function.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//CREATING A LIST OF ALL CUSTOMERS//
Slist Slist_new(){
    Slist s1= {NULL,0,NULL};
    return s1;
}

//CREATING QUEUE FOR EACH CUSTOMER//
Customer queue_new(){
    Customer c1 = {0,NULL,NULL,NULL};
    return c1;
}

//CREATING A NODE//
static Node* _get_new_node_(char* name, int* acc_type, int32_t balance, int32_t acc_number, int* branch){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->name = name;
    newnode->branch = branch;
    newnode->acc_type = acc_type;
    newnode->balance = balance;
    newnode->acc_number = acc_number;
    newnode->next=NULL;
    return newnode;
}

//ENQUEUE NEW SHARE FOR A PERTICULAR CUSTOMER//
Customer* new(Slist* s, Customer *c, char* name, int* acc_type, int32_t balance, int32_t acc_number, int* branch, QueueResult *res, Transaction *t){
    assert(s!=NULL && c!= NULL);
    //GOING THROUGH LIST OF CUSTOMERS AND ADDING AT HEAD//
    c->next = s->head;
    if(s->head==NULL){
        s->head = s->tail = c;
    }
	else
    s->head = c;


    //ENQUEUE THE NEW SHARES//
    Node *newnode = _get_new_node_(name, acc_type, balance, acc_number, branch);
    if(c->countc<MAX_SIZE) {
        if(c->rear!=NULL) {
        c->rear->next = newnode;
        c->rear = newnode;
        }
		else
        c->rear = c->front = newnode;
    }
	else if(c->countc == MAX_SIZE) {         //IF QUEUE IS FULL DEQUEUE THE NODE AND ADD A NEWNODE//
        Node* temp;
        if(c->front!=NULL) {
            temp=c->front;
            c->front = c->front->next;
            if(c->front==NULL) {
                c->rear =NULL;
            }
            --c->countc;
            res->status = QUEUE_OK;
            free(temp);
        }
		else
        res->status = QUEUE_FULL;
        if(c->rear!=NULL) {
        c->rear->next = newnode;
        c->rear = newnode;
        }
		else
        c->rear = c->front = newnode;

    }

    ++c->countc;
    ++s->count;
    res->status = QUEUE_OK;
    //STORING IN TRANSACTION STRUCTURE//
    t->branch = branch;
    t->acc_type = acc_type;
    t->balance = balance;
    t->acc_number = acc_number;
    t->t_status = CREDIT;
    return c;

}

//DEQUEUE THE SHARES FOR GIBEN NAME AND acc_number(Only last node)//
Customer* debit(Slist* s, Customer *c, QueueResult *res, Transaction *t, char* name, int32_t acc_number){
    assert(s!=NULL && c!= NULL);
    Node *temp;
    Node *ctemp;
    temp=s->head;
    while(strcmp(temp->name,name)!=0) {
        temp=temp->next;
    }
    get = minimum_balance(t.balance);
    if (get) {
    	if(c->front!=NULL) {
        	if(c->front->acc_number == acc_number) {
            	    ctemp = c->front;
                	c->front = c->front->next;
                	if(c->front == NULL){
                    c->rear = NULL;
                	}
        		--c->countc;
        		res->status = QUEUE_OK;
        		free(ctemp);
        		}
			else {
            c->front->acc_number=(c->front->acc_number) - acc_number;
            res->status = QUEUE_OK;
            res->acc_number = c->front->acc_number;
        	}
    	}	
		else 
		res->status = QUEUE_EMPTY;
		t->branch = c->front->branch;
		t->acc_type = c->front->acc_type;
		t->balance = c->front->balance;
		t->acc_number = c->front->acc_number;
		t->t_status = DEBIT;


    return c;
	}
    
}

//Looking for a customer having any shares in the list//
int32_t list(const Slist *s, const Customer* c, char *name){
    assert(c!=NULL && s!=NULL);
    Node *temp;
    Node *ctemp;
    temp=s->head;
    while(strcmp(temp->name,name)!=0){
        temp=temp->next;
    }
    return(temp!=NULL);
}

//adding new acc_number for a particular customer given company name//
Customer* credit(Slist* s, Customer *c, char* name, int32_t acc_number, int* branch, QueueResult *res, Transaction *t){
    assert(s!=NULL && c!= NULL);
    Node *temp;
    Node *ctemp;
    temp=s->head;
    
    while(strcmp(temp->name,name)!=0){
        temp=temp->next;
    }
    ctemp = temp;
    while(strcmp(ctemp->branch,branch)!=0){
        ctemp = ctemp->next;
    }
    ctemp->acc_number = (ctemp->acc_number) + acc_number;
    res->status =QUEUE_OK;
    
	//storing information in the transaction structure//
    res->acc_number = ctemp->acc_number;
    t->branch = ctemp->branch;
    t->acc_type = ctemp->acc_type;
    t->balance = ctemp->balance;
    t->acc_number = ctemp->acc_number;
    t->t_status = CREDIT;

    return c;
}

int8_t minimum_balance(int32_t balance){
 	if(balance > 2000){
 		assert(marks < 2000);                                             //assert failed if marks are more than 10
 		return 0;
	 }
	 else{
	 	return 1;
	 }
 } 




