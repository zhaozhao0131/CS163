#include"list.h"
//CS163
//
//Jiacheng Zhao
//
//Program 3
//
//list.cpp



/*======================================
	    Constructor
======================================*/

website::website()
{
    name = NULL;
    summary = NULL;
    review = NULL;
    rate = 0;
}

/*======================================
	    Destructor
======================================*/

website::~website()
{
    remove();
}

/*======================================
	Remove all function
    help destructor to clean data
======================================*/

void website::remove()
{
    delete [] name;
    name = NULL;
    delete [] summary;
    summary = NULL;
    delete [] review;
    review = NULL;
    rate = 0;
    return;
}

/*======================================
	Initilize the data 
======================================*/

website::website(char*Name, char* Summary, char*Review, int Rate)
{
    name=new char[strlen(Name)+1];
    strcpy(name,Name);
    summary=new char[strlen(Summary)+1];
    strcpy(summary,Summary);
    review=new char[strlen(Review)+1];
    strcpy(review,Review);
    rate = Rate;
}

/*======================================
    Copy function to get the data
    to help table class get data
======================================*/

int website::copy(const website & copy_from)
{
    if(!copy_from.name||!copy_from.summary||!copy_from.review||!copy_from.rate)
	return 0;
    name=new char[strlen(copy_from.name)+1];
    strcpy(name,copy_from.name);
    summary=new char[strlen(copy_from.summary)+1];
    strcpy(summary,copy_from.summary);
    review=new char[strlen(copy_from.review)+1];
    strcpy(review,copy_from.review);
    rate = copy_from.rate;
    return 1;
}

/*======================================
    Add function to help table class
	insert new node into LLL
======================================*/

void website::add(char*Name, char* Summary, char*Review, int Rate)
{
    if(!Name||!Summary||!Review||!Rate)
	return;
    name=new char[strlen(Name)+1];
    strcpy(name,Name);
    summary=new char[strlen(Summary)+1];
    strcpy(summary,Summary);
    review=new char[strlen(Review)+1];
    strcpy(review,Review);
    rate = Rate;
    return;
}

/*======================================
	Retrieve function
    to help table class retrieve
     the data in liner link list
======================================*/

int website::retrieve(char*match)
{
    if(strcmp(name,match)==0)
	return 1;
    else
	return 0;
}

/*======================================
	Display function
    to help table class display 
	the data of node
======================================*/

void website::display()
{
    if(!name)
	return;
    cout<<"Name: "<<name<<endl;
    cout<<"Summary: "<<summary<<endl;
    cout<<"Review: "<<review<<endl;
    cout<<"Rate: "<<rate<<endl;
}

/*======================================
	    Constructor
======================================*/

table::table(int size)
{
    hash_table_size = size;
    hash_table = new node*[hash_table_size];
    for(int i=0;i<size;i++)
    {
	hash_table[i]=NULL;
    }
}

/*======================================
	    Destructor
======================================*/

table::~table()
{
    hash_table_size = 0;
    *hash_table=NULL;
}

/*======================================
	 Read file function
     to read the data from file 
    and get them for other function
======================================*/

void table::read_file(website & to_add,table & list)
{
    char Name[20];
    char Summary[100];
    char Review[100];
    int Rate = 0;
    
    ifstream fn;
    fn.open("event.txt");
    if(fn)
    {
	fn.get(Name,20,'|');
	fn.ignore(100,'|');
	while(!fn.eof())
	{
	    fn.get(Summary,100,'|');
	    fn.ignore(100,'|');
	    cout<<Summary;

	    fn.get(Review,100,'|');
	    fn.ignore(100,'|');
	    cout<<Review;

	    fn>>Rate; //cin instead fn?
	    fn.ignore(100,'|');
	    cout<<Rate<<endl;

	    to_add.add(Name,Summary,Review,Rate);
	    list.insert(Name,to_add);

	    fn.get(Name,20,'|');
	    fn.ignore(100,'|');
	}
	cout<<"==============Reading file================"<<endl;
    }
    else
	cout<<"==============Can NOT open file!!!=============="<<endl;
    fn.close();
    return;
}

/*======================================
	Create file function
      to create a file for user 
======================================*/

void table::creat_file(char* Name, char* Summary, char* Review, int Rate)
{
    ofstream fo("event.txt");
    if(fo)
    {
	fo<<Name<<'|'<<endl;
	fo<<Summary<<'|'<<endl;
	fo<<Review<<'|'<<endl;
	fo<<Rate<<'|'<<endl;
	cout<<"Loading file"<<endl;
    }
    else 
	cout<<"Cant open file"<<endl;
    fo.close();
}

/*======================================
	    Hash function
    to deal with the key word into 
   a unifrom data for other function
======================================*/

int table::hash_function(char* key)
{
    if(!key)
	return -1;
    int sum=0;
    int len = strlen(key);
    for(int i=len-1;i>=0;i--)
    {
	sum = (key[i]+128*sum) % hash_table_size;
    }
//    cout<<"hash_key = "<<sum%hash_table_size;
    return sum%hash_table_size;
}

/*======================================
	 Insert function
    to add one more node into array
	of liner link list
======================================*/

int table::insert(char* key, website & to_add)
{
    int p = 0;
    p = hash_function(key);
    if(p < 0 || p > hash_table_size)
	return 0;
    else
    {
	node*temp = new node;
	temp ->entry.copy(to_add);
	temp->next = hash_table[p];
	hash_table[p]=temp;
    }
    return 1;
}

/*======================================
	Retrieve function 
    to find data relate with key
======================================*/

int table::retrieve(char* find)
{
    int p = hash_function(find);
    return retrieve(find, hash_table[p]);
}

/*======================================
    Wrapper function of retrieve
======================================*/

int table::retrieve(char* find, node*head)
{
    if(!head)
	return 0;
    if(head->entry.retrieve(find) ==1)
    {
	head->entry.display();
	return 1;
    }
    return retrieve(find,head->next);
}

/*======================================
	 Remove function
    to delete one node into array 
        of liner link list
======================================*/

bool table::remove(char* find)
{
    int i = hash_function(find);
    return remove(find,hash_table[i]);
}

/*======================================
	Wrapper function of remove
======================================*/

bool table::remove(char* find, node*& head)
{
    if(!head)
	return false;
    node*temp = head;
    if(temp->entry.retrieve(find) ==1)
    {
	temp->entry.remove();
	head=head->next;
	delete temp;
	temp = NULL;
	return true;
    }
    return remove(find,head->next);
}

/*======================================
	  Display function
    to display all data into array
         of liner link list
======================================*/

void table::display_all()
{
    for(int i=0;i<5;i++)
    {
	node*temp = new node;
	temp = hash_table[i];
	display(temp);
    }
    return;
}

/*======================================
	Wrapper function of display
======================================*/

void table::display(node*head)
{
    if(!head)
	return;
    head->entry.display();
    return display(head->next);
}
