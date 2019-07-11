//CS163
//
//Jiacheng Zhao
//
//Program 3
//
//list.h
#include<cstring>
#include<fstream>
#include<cctype>
#include<iostream>
using namespace std;
/*======================================
    Website class include pubile and 
	private member function
     copy data,initilize,retrieve 
	and display function
======================================*/
class website{
    public:
	website();
	~website();
	void remove();
	website(char*, char*, char*,int);
	int copy(const website & copy_from);
	void add(char*,char*,char*,int);
	int retrieve(char*);
	void display();
    private:
	char* name;
	char* summary;
	char* review;
	int rate;
};

/*======================================
     Structure of liner link list
    has entry data of website type
 	  and next pointer
======================================*/

struct node{
    website entry;
    node * next;
};

/*======================================
     Table class include pubilc and 
	private member function
     hash function, insert, retrieve
      remove and display function
======================================*/

class table{
    public: 
	table(int size = 5);
	~table();
	void read_file(website & to_add, table & list);
	void creat_file(char*,char*,char*,int);

	int hash_function(char*);
	int insert(char*, website & to_add);
	int retrieve(char* find);
	bool remove(char*find);

	void display_all();
    private:
	node**hash_table;
	int hash_table_size;
	int retrieve(char* find, node*);
	void display(node*);
	bool remove(char*find, node*&);
};
