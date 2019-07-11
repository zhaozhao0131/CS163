#include<iostream>
#include<fstream>
#include<cstring>
#include<cctype>
//Jiacheng Zhao
//
//Program4
//
//list.h
using namespace std;
/*================================
    Website class has public
    and private member function
    deal with the data to table
================================*/
class website
{
    private:
	char* name;
	char* address;
	char* summary;
	char* review;
    public:
	website();
	~website();

	website(char*,char*,char*,char*);
	bool remove();
	int copy(const website& copy_from);
	bool add(char*, char*, char*, char*);
	int retrieve(char*match);
	bool display();
	int compare(website& match);
	char* get_name();
	bool deallocate();
};
/*================================
    Node structure has two ptr
    entry data of website type
================================*/
struct node
{
    website entry;
    node * left;
    node * right;
};
/*================================
    Table class has public and 
    private member fucntion
    to insert remove display
================================*/
class table
{
    public:
	table();
	~table();
	void read_file(website& to_add, table& list);

	bool delete_all();
	node*insert(website& to_add);
	bool retrieve(char* find);
	node*& remove(char* find);
	bool display_all();
    private:
	node* root;
	bool delete_all(node*&);
	node* insert(node*&,website& to_add);
	bool retrieve(char* find, node*);
	node* successor(node*&);
	node*& remove(char* find, node*&);
	bool display_all(node*);
};
