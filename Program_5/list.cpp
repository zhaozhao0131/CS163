#include"list.h"
//Jiacheng Zhao
//
//Program5
//
//list.cpp
/*===================================
	    Constructor
===================================*/

graph::graph(int size)
{
    list_size = size;
    vertex_list = new vertex[size];
    for(int i=0;i<list_size;++i)
    {
	vertex_list[i].head = NULL;
	vertex_list[i].name = NULL;
	vertex_list[i].info = NULL;
    }
}

/*===================================
	    Destructor
===================================*/

graph::~graph()
{
    for(int i=0;i<list_size;++i)
    {
	delete_all(vertex_list[i].head);

	delete [] vertex_list[i].name;
	vertex_list[i].name = NULL;
	delete [] vertex_list[i].info;
	vertex_list[i].info = NULL;

	delete vertex_list[i].head;
	vertex_list[i].head = NULL;
    }
    delete [] vertex_list;
    vertex_list = NULL;
}

/*===================================
    Delete all function to help
    destructor delete the data 
===================================*/

bool graph::delete_all(node*& head)
{
    if(!head)
	return true;
    node* temp = head;
    head = head->next;
    delete temp;
    temp = NULL;
    return delete_all(head);
}

/*===================================
    Insert vertex function to 
    insert the vertex into array
===================================*/

int graph::insert_vertex(char* Name, char* Info)
{
    for(int i=0;i<list_size;++i)
    {
	if(!vertex_list[i].name&&!vertex_list[i].info)
	{
	    vertex_list[i].name = new char[strlen(Name)+1];
	    strcpy(vertex_list[i].name,Name);
	    vertex_list[i].info = new char[strlen(Info)+1];
	    strcpy(vertex_list[i].info,Info);
	    return 1;
	}
    }
    return 0;
}

/*===================================
    Get vertex function to help 
    get the number of vertex and 
    pass to other function use
===================================*/

int graph::get_vertex(char* key)
{
    for(int i=0;i<list_size;++i)
    {
	if(!strcmp(vertex_list[i].name,key))
	    return i;
    }
}

/*===================================
    Wrapper function insert edge
===================================*/

int graph::insert_edge(char* current_vertex,char* connect_vertex,char* Des, int Len)
{
    int refer = get_vertex(connect_vertex);

    for(int i=0;i<list_size;++i)
    {
	if(!strcmp(current_vertex, vertex_list[i].name))
	{
	    insert_edge(vertex_list[i].head, refer, Des, Len);
	}
    }
    return 1;
}

/*===================================
     Insert edge function to 
    connnect two vertex and build 
    a edge has des and length   
===================================*/

int graph::insert_edge(node*& head, int refer, char* Des, int Len)
{
    node* temp = new node;
    temp->edge = &vertex_list[refer];
    temp->length = Len;
    temp->next = head;
    head = temp;
    return 1;
}

/*===================================
    Wrapper function display path
===================================*/

bool graph::display_all_path(char* current_vertex)
{
    for(int i=0;i<list_size;++i)
    {
	if(vertex_list[i].name)
	{
	    if(!strcmp(vertex_list[i].name, current_vertex))
	    {
		display_all_connect(vertex_list[i].head);
		return true;
	    }
	}
	return false;
    }
    return false;
}

/*===================================
    Display all path function to 
    display all path it through
===================================*/

bool graph::display_all_path(node* head)
{
    if(!head)
	return false;
    cout<<"Path: "<<head->edge->name<<endl;
    cout<<"Length: "<<head->length<<endl;
    return display_all_connect(head->next)+true;
}

/*===================================
    Wrapper function display connect
===================================*/

bool graph::display_all_connect(char* current_vertex)
{
    for(int i=0;i<list_size;++i)
    {
	if(vertex_list[i].name)
	{
	    if(!strcmp(vertex_list[i].name,current_vertex))
	    {
		display_all_connect(vertex_list[i].head);
		return true;
	    }
	}
	return false;
    }
    return false;
}

/*===================================
    Dipslay all connect function
    to display all connection of 
    the part of special graph
===================================*/

bool graph::display_all_connect(node* head)
{
    if(!head)
	return false;
    cout<<"vertex: "<<head->edge->name<<endl;
    return display_all_connect(head->next)+true;
}

