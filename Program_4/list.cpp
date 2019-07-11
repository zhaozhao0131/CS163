#include"list.h"
//Jiacheng Zhao
//
//Program4
//
//list.cpp
/*================================
	Constructor
================================*/
website::website()
{
    name=NULL;
    address=NULL;
    summary=NULL;
    review=NULL;
}
/*================================
    website function hold data
================================*/
website::website(char*Name,char*Address,char*Summary,char*Review)
{
    name=new char[strlen(Name)+1];
    strcpy(name,Name);
    address=new char[strlen(Address)+1];
    strcpy(address,Address);
    summary=new char[strlen(Summary)+1];
    strcpy(summary,Summary);
    review=new char[strlen(Review)+1];
    strcpy(review,Review);
}
/*================================
	Destructor
================================*/
website::~website()
{
    remove();
}
/*================================
    Remove function to help
    destructor remove all data
================================*/
bool website::remove()
{
    delete [] name;
    name=NULL;
    delete [] address;
    address=NULL;
    delete [] summary;
    summary=NULL;
    delete [] review;
    review=NULL;
    return true;
}
/*================================
    Copy function to copy all
    data from the list
================================*/
int website::copy(const website& copy_from)
{
    if(!copy_from.name ||!copy_from.address ||!copy_from.summary ||!copy_from.review)
	return 0;
    if(name)
	delete [] name;
    name=new char[strlen(copy_from.name)+1];
    strcpy(name,copy_from.name);
    if(address)
	delete [] address;
    address=new char[strlen(copy_from.address)+1];
    strcpy(address,copy_from.address);
    if(summary)
	delete [] summary;
    summary=new char[strlen(copy_from.summary)+1];
    strcpy(summary,copy_from.summary);
    if(review)
	delete [] review;
    review=new char[strlen(copy_from.review)+1];
    strcpy(review,copy_from.review);
    return 1;
}
/*================================
    Add function to help the 
    table class add a new node
================================*/
bool website::add(char*Name,char*Address,char*Summary,char*Review)
{
    if(name)
	delete [] name;
    name=new char[strlen(Name)+1];
    strcpy(name,Name);
    if(address)
	delete [] address;
    address=new char[strlen(Address)+1];
    strcpy(address,Address);
    if(summary)
	delete [] summary;
    summary=new char[strlen(Summary)+1];
    strcpy(summary,Summary);
    if(review)
	delete [] review;
    review=new char[strlen(Review)+1];
    strcpy(review,Review);
    return true;
}
/*================================
    Retrieve function to help
    the table class retrieve
================================*/
int website::retrieve(char*match)
{
    if(strcmp(name,match)==0)
	return 0;
    if(strcmp(name,match)>0)
	return 2;
    if(strcmp(name,match)<0)
	return -1;
}
/*================================
    Display function to help
    the table class display
================================*/
bool website::display()
{
    if(!name)
	return false;
    cout<<"Name: "<<name<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"Summary: "<<summary<<endl;
    cout<<"Review: "<<review<<endl;
    return true;
}
/*================================
    Compare function to help
    the table class compare
================================*/
int website::compare(website& match)
{
    if(strcmp(match.name,name)>0)
	return 1;
    else
	return -1;
}
/*================================
    Get name function to help
    table class get name data
================================*/
char* website::get_name()
{
    return name;
}
/*================================
    Deallocate function to 
    help table deallocate
================================*/
bool website:: deallocate()
{
    if(name)
	return false;
    delete [] name;
    delete [] address;
    delete [] summary;
    delete [] review;
    return true;
}
//
//
//
/*================================
	Constructor
================================*/
table::table()
{
    root=NULL;
}
/*================================
	Destructor
================================*/
table::~table()
{
    delete_all(root);
}
/*================================
    Delete all function to 
    help destructor delete 
================================*/
bool table::delete_all()
{
    return delete_all(root);
}
/*================================
    Wrapper function of delete
================================*/
bool table::delete_all(node*&root)
{
    if(!root)
	return false;
    delete_all(root->left);
    delete_all(root->right);
    delete root;
    root=NULL;
    return true;
}
/*================================
    Read file function to 
    read the data from file
================================*/
void table::read_file(website& to_add, table& list)
{
    char Name[20];
    char Address[100];
    char Summary[100];
    char Review[100];

    ifstream fn;
    fn.open("event.txt");
    if(fn)
    {
	fn.get(Name,20,'|');
	fn.ignore(100,'|');
	while(!fn.eof())
	{
	    fn.get(Address,100,'|');
	    fn.ignore(100,'|');
	    cout<<Address;
	    
	    fn.get(Summary,100,'|');
	    fn.ignore(100,'|');
	    cout<<Summary;

	    fn.get(Review,100,'|');
	    fn.ignore(100,'|');
	    cout<<Review;

	    to_add.add(Name,Address,Summary,Review);
	    list.insert(to_add);

	    fn.get(Name,20,'|');
	    fn.ignore(100,'|');
	}
	cout<<"=====================Reading file=========================="<<endl;}
    else
	cout<<"=====================Cant read file!!====================="<<endl;
    fn.close();
    return;
}
/*================================
    The wrapper function of 
    insert function
================================*/
node* table::insert(website& to_add)
{
    return insert(root,to_add);
}
/*================================
    Insert function to insert
    a new node into table
================================*/
node* table::insert(node*&root,website& to_add)
{
    if(!root)
    {
	root=new node;
	root->entry.copy(to_add);
	root->left=root->right=NULL;
    }
    else if(root->entry.compare(to_add)<0)
	root->left=insert(root->left,to_add);
    else
	root->right=insert(root->right,to_add);
    return root;
}
/*================================
   Wrapper fucntion of retrieve
================================*/
bool table::retrieve(char*find)
{
    return retrieve(find,root);
}
/*================================
    Retrieve function to find 
    the data the client ask
================================*/
bool table::retrieve(char*find,node*root)
{
    if(!root)
    {
	root=NULL;
	return false;
    }
    if(root->entry.retrieve(find)==0)
    {
	root->entry.display();
	return true;
    }
    retrieve(find,root->left);
    retrieve(find,root->right);
    return false;
}
/*================================
    Successor function to 
    find the successor data
================================*/
node* table::successor(node*&root)
{
    if(!root)
    {
	root=NULL;
	return root;
    }
    if(root->left=NULL)
	return root;
    else
	return successor(root->left);
}
/*================================
    Wrapper function of remove
================================*/
node*& table::remove(char*find)
{
    remove(find,root);
}
/*================================
    Remove function to remove
    the data of the table
================================*/
node*& table::remove(char*find,node*&root)
{
    if(!root)
	return root;
    if(root->entry.retrieve(find)==0)
    {
	if(!root->left&&!root->right)
	//NO child
	{
	    root->entry.remove();
	    delete root;
	    root=NULL;
	    return root;
	}
	else if(!root->left&&root->right)
	//ONE child
	{
	    node*temp=root;
	    root=root->right;
	    temp->entry.remove();
	    delete temp;
	    temp=NULL;
	    return root;
	}
	else if(!root->right&&root->left)
	{
	    node*temp=root;
	    root=root->left;
	    temp->entry.remove();
	    delete temp;
	    temp=NULL;
	    return root;
	}
	else
	//TWO child
	{
	    node*temp=successor(root->right);
	    root->entry.copy(temp->entry);
	    root->right=remove(temp->entry.get_name(),root->right);
	}
    }
    if(root->entry.retrieve(find)<0)
	return remove(find,root->left);
    else
	return remove(find,root->right);
    return root;
}
/*================================
    Wrapper function of display
================================*/
bool table::display_all()
{
    return display_all(root);
}
/*================================
    Display function to display
    the data of tree table
================================*/
bool table::display_all(node*root)
{
    if(!root)
	return false;
    root->entry.display();
    display_all(root->left);
    display_all(root->right);
    return true;
}
