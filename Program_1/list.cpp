#include"list.h"

//CS163
//Jiacheng Zhao
//Program 1
//list.cpp

/*=========================================
		Constructor
==========================================*/

list::list()
{
    head = NULL;
}

/*=========================================
		Destructor
==========================================*/

list::~list()
{
    artist *temp;
    while(head)
    {
	temp = head->next;
	delete head;
	head = temp;
    }
}

/*=========================================
	    ADD node of artist 
    Create new artist for list and put 
      Data of artist in artist node
==========================================*/

bool list :: AddArtist(char*Name, char*Story, char*Des)
{
    if(!head)
    {
	head = new artist;
	head->next = NULL;
	head->name = new char[strlen(Name)+1];
	strcpy(head->name, Name);
	head->story = new char[strlen(Story)+1];
	strcpy(head->story, Story);
	head->des = new char[strlen(Des)+1];
	strcpy(head->des, Des);
	return true;
    }
    artist *temp = new artist;
    temp->next = head;
    head = temp;
    temp->name = new char[strlen(Name)+1];
    strcpy(temp->name,Name);
    temp->story = new char[strlen(Story)+1];
    strcpy(temp->story, Story);
    temp->des = new char[strlen(Des)+1];
    strcpy(temp->des, Des);
    return true;
}

/*=========================================
       	 Add node of song list
   Create new song for list and put 
      Date of song in song node
==========================================*/

bool list :: AddSong(char*Title,int Length, int View, int Like)
{
    if(!head->song_head)
    {
	head->song_head = new song;
	head->song_head->next = NULL;
	head->song_head->title = new char[strlen(Title)+1];
	strcpy(head->song_head->title,Title);
	head->song_head->length = Length;
	head->song_head->views = View;
	head->song_head->likes = Like;
	return true;
    }
    song * temp = new song;
    temp->next = head -> song_head;
    head -> song_head = temp;
    head->song_head->title = new char[strlen(Title)+1];
    strcpy(head->song_head->title,Title);
    head->song_head->length = Length;
    head->song_head->views = View;
    head->song_head->likes = Like;
}

/*=========================================
	    Edit data of song
      find the artist and the song
    change the data of views and likes
==========================================*/

bool list :: EditNumber(int view, int like, char* Name, char* Title)
{
    return EditNumber(view, like, Name, Title, head);
}
bool list :: EditNumber(int view, int like, char* Name, char* Title, artist * head)
{
    if(!head)
	return false;
    if(!strcmp(Name, head -> name))
    {
	while(head -> song_head){
	if(!strcmp(Title, head -> song_head -> title))
	{
	    head -> song_head -> views = view;
	    head -> song_head -> likes = like;
	    return true;
	}
	    head -> song_head = head -> song_head -> next;
	}
    }
    return EditNumber(view, like, Name, Title, head->next);
}
/*=========================================
	    Display all artist
	Display data of all artist
	Name story and description
==========================================*/


bool list :: DisplayArtist()
{
    return DisplayArtist(head);
}
bool list :: DisplayArtist(artist*head)
{
    if(!head)
	return false;
    cout<<"name of artist: "<<head->name<<endl;
    cout<<"story of artist: "<<head->story<<endl;
    cout<<"description of artist: "<<head->des<<endl;
    return DisplayArtist(head->next);
}
/*=========================================
	Display song of artist
     Find the artist and display
     Title length views and likes
==========================================*/

bool list :: DisplaySong(char* Name)
{
    return DisplaySong(Name,head);
}

bool list :: DisplaySong(char* Name,artist* head)
{
    if(!head)
	return false;
    if(!strcmp(head->name,Name))
	DisplaySong(head);
    return DisplaySong(Name,head->next);
}
bool list :: DisplaySong(artist* head)
{
    if(!head->song_head)
	return false;
    while(head->song_head)
    {
	cout<<"title of song: "<<head->song_head->title<<endl;
	cout<<"length of song: "<<head->song_head->length<<endl;
	cout<<"views of song: "<<head->song_head->views<<endl;
	cout<<"likes of song: "<<head->song_head->likes<<endl<<endl;
	head->song_head = head->song_head->next;
    }
    return true;
}
 /*=========================================
	Remove lower views songs
    Compare every views of songs with 
  A number from client and remove smaller
==========================================*/
   
void list :: RemoveSpecial(int M)
{
    if(!head->song_head)
	return;
    if(head->song_head->next==NULL)
    {
	if(head->song_head->views < M)
	{
	    delete head->song_head;
	    head->song_head = NULL;
	    return;
	}
    }
    else
    {
	if(head->song_head->next->views < M)
	{
	    song* temp = head->song_head->next;
	    head->song_head = head->song_head->next->next;
	    delete temp;
	    temp = NULL;
	    return;
	}
    }
    return;
}
	

