#ifndef _STACK_H_
#define _STACK_H_
//stack.h
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
	Structure of LLL 
    of array name_email data
      and the next pointer
===============================*/

struct node
{
    char ** name_email;
    node * next;
};

const int MAX = 5;

/*==============================
	Class of stack
    private and public member
      and member function
===============================*/

class stack
{
    public:
	stack();
	~stack();
	bool push(char*);
	bool pop();
	bool peek();
	void display_all();
    private:
	int index;
	node * head;
	bool remove_all(node*&head);
	bool push(node *&, char*);
	bool pop(node *&);
	void display_all(node*);
};

#endif
