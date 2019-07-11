#ifndef _QUEUE_H_
#define _QUEUE_H_
//queue.h
//
//Jiacheng Zhao
//
//922943778
//
//CS163

#include<iostream>
#include<cstring>
#include<cctype>
/*==============================
       Structure of CLL
  name, number, sepcial infor
  promo data and next pointer
===============================*/
struct C_node
{
    char * name;
    int number;
    char * special;
    int promo;

    C_node * next;
};

/*==============================
	Class of queue
    private and public member
      and member function
===============================*/

class queue
{
    public:
	queue();
	~queue();
	bool enqueue(char*,int,char*,int);
	bool dequeue();
	bool peek();
	void display_all();
    private:
	C_node * rear;
	bool enqueue(C_node *&, char*,int,char*,int);
	bool dequeue(C_node*&);
	void display_all(C_node*, C_node*);
};

#endif

