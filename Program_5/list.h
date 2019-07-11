#include<cstring>
#include<cctype>
#include<iostream>

//Jiacheng Zhao
//
//Program5
//
//list.h

using namespace std;

#define SIZE_name 50
#define SIZE_des 50
#define SIZE_info 50

/*===================================
    Vertex structure has name and 
    info data and one head pointer
===================================*/

struct vertex
{
    char* name;
    char* info;
    struct node* head;
};

/*===================================
    Node structure has edge of 
    vertex tpye and description
    length and next pointer
===================================*/

struct node
{
    vertex* edge;
    char* des;
    int length;
    node* next;
};

/*===================================
    Graph class has public and 
    private memeber function to 
    insert vertex and insert edge
    and display the data for user
===================================*/

class graph
{
    public:
	graph(int size);
	~graph();
	int insert_vertex(char*,char*);
	int insert_edge(char*,char*,char*,int);
	bool display_all_path(char*);
	bool display_all_connect(char*);
    private:
	int list_size;
	vertex* vertex_list;

	int get_vertex(char*);
	bool delete_all(node*&);
	int insert_edge(node*&, int, char*, int);
	bool display_all_path(node*);
	bool display_all_connect(node*);
    
};
