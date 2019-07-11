#include"stack.h"
//stack.cpp
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

stack::stack()
{
    head = NULL;
    index = 0;
}

/*==================================
	    Destructor
===================================*/

stack::~stack()
{
    remove_all(head);
}

/*==================================
    Remove all item from stack
===================================*/

bool stack::remove_all(node*&head)
{ 
    if(!head)
	return true;
    remove_all(head->next);
    delete [] head->name_email;
    delete head;
    head = NULL;
}

/*==================================
    Wrapper function of push
===================================*/

bool stack::push(char* word)
{
    return push(head,word);
}

/*==================================
  Add the item on the top of stack
===================================*/

bool stack::push(node*& head,char* word)
{
    if(head==NULL)
    {
	head = new node;
	head->name_email = new char*[MAX];
	head->name_email[index] = new char[strlen(word)+1];
	strcpy(head->name_email[index],word);
	head->next = NULL;

	++index;
	return true;
    }
    if(index == MAX)
    {
	index = 0;
	node* temp = new node;
	temp -> name_email = new char*[MAX];
	temp -> name_email[index] = new char[strlen(word)+1];
	strcpy(temp->name_email[index],word);
	temp->next = head;
	head = temp;
	++index;
	return true;
    }
    else
    {
	head->name_email[index] = new char[strlen(word)+1];
	strcpy(head->name_email[index],word);
	++index;
	return true;
    }
    return false;
}

/*==================================
     Wrapper function of pop
===================================*/

bool stack::pop()
{
    return pop(head);
}

/*==================================
  Remove item on the top of stack
===================================*/

bool stack::pop(node*& head)
{
    if(!head)
	return false;
    if(index == 0)
    {
	index = MAX;
	node * temp = head;
	head = head->next;
	delete [] temp->name_email;
	temp = NULL;
	return true;
    }
    if(index > 0)
    {
	head->name_email[index-1]=NULL;
	--index;
	return true;
    }
}

/*==================================
    Find the most top item
===================================*/

bool stack::peek()
{
    if(!head)
	return false;
    if(index == 0)
    {
	cout<<head->name_email[0]<<endl;
	return true;
    }
    if(index > 0)
    {
	cout<<head->name_email[index-1]<<endl;
	return true;
    }
}

/*==================================
    Wrapper function of display
===================================*/

void stack::display_all()
{
    display_all(head);
}

/*==================================
    Display all item on stack
===================================*/

void stack::display_all(node* head)
{
    if(!head)
	return;
    for(int i=0;i<MAX;++i)
    {
	if(head->name_email[i])
	    cout<<head->name_email[i]<<endl;
    }
    return display_all(head->next);
}

