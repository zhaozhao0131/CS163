#include"queue.h"
//queue.cpp
//
//Jiacheng Zhao
//
//922943778
//
//CS163

using namespace std;

/*==================================
	    Constructor
===================================*/

queue::queue()
{   
    rear = NULL;
}

/*==================================
	    Destructor
===================================*/

queue::~queue()
{
    if(rear)
    {
	C_node* head = rear->next;
	rear->next = NULL;
	while(head)
	{
	    C_node* p = head->next;
	    delete [] head->name;
	    delete [] head->special;
	    delete head;
	    head = p;
	}
	rear = NULL;
    }
}

/*==================================
    Wrapper function of enqueue
===================================*/

bool queue::enqueue(char* name,int number, char* special, int promo)
{
    return enqueue(rear,name,number,special,promo);
}

/*==================================
    Add the node at the end of CLL
===================================*/

bool queue::enqueue(C_node*& rear, char* name,int number, char* special, int promo)
{
    if(!rear)
    {
	rear = new C_node;
	rear->name = new char[strlen(name)+1];
	strcpy(rear->name, name);
	rear->number = number;
	rear->special = new char[strlen(special)+1];
	strcpy(rear->special,special);
	rear->promo = promo;
	rear->next = rear;
	return true;
    }
    C_node* temp = new C_node;
    temp->name = new char[strlen(name)+1];
    strcpy(temp->name,name);
    temp->number = number;
    temp->special = new char[strlen(special)+1];
    strcpy(temp->special,special);
    temp->promo = promo;
    temp->next = rear->next;
    rear->next = temp;
    rear = temp;
    return true;
}

/*==================================
    Wrapper function of dequeue
===================================*/

bool queue::dequeue()
{
    return dequeue(rear);
}

/*==================================
Remove the node at the front of CLL
===================================*/

bool queue::dequeue(C_node*& rear)
{
    if(!rear)
	return false;
    C_node* temp = rear->next;
    rear->next = rear->next->next;
    delete [] temp->name;
    delete [] temp->special;
    temp->name = NULL;
    delete temp;
    temp = NULL;
    return true;
}

/*==================================
	Function of peek
===================================*/

bool queue::peek()
{
    if(!rear)
	return false;
    cout<<"PEEK first ONE: "<<rear->next->name<<endl;
    return true;
}

/*==================================
    Wrapper function of display
===================================*/

void queue::display_all()
{
    if(!rear)
	return;
    return display_all(rear,rear->next);
}

/*==================================
     Display all node in CLL
===================================*/

void queue::display_all(C_node* rear, C_node* head)
{
    if(head==rear)
    {
	cout<<"NAME: "<<rear->name<<endl;
	cout<<"NUMBER: "<<rear->number<<endl;
	cout<<"SPECIAL INFOR: "<<rear->special<<endl;
	cout<<"PROMO: "<<rear->promo<<endl;
	return;
    }
    cout<<"NAME: "<<head->name<<endl;
    cout<<"NUMBER: "<<head->number<<endl;
    cout<<"SPECIAL INFOR: "<<head->special<<endl;
    cout<<"PROMO: "<<head->promo<<endl;

    return display_all(rear,head->next);
}
