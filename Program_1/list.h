#include<iostream>
#include<cctype>
#include<stdio.h>
#include <cstring>

//CS163
//Jiacheng Zhao
//Program 1
//list.h

using namespace std;

struct song;

/*=========================================
	The structure of artist
    Name story description of data
     The pointer of list of song
    The pointer of next artist node
==========================================*/

struct artist{

    char * name;
    char * story;
    char * des;

    song * song_head;
    artist * next;
};

/*=========================================
	The structure of song
    Title length views likes of data
     The pointer of next song node
==========================================*/

struct song{

    char * title;
    int length;
    int views;
    int likes;

    song * next;
};

/*=========================================
	  The class of list 
    Public and private member function 
     The private head of artist type
      Constucture and destructure
==========================================*/

class list{
    
    public:
	list();
	~list();
	bool AddArtist(char*,char*,char*);
	bool AddSong(char*,int, int, int);
	bool EditNumber(int, int, char*, char*);
	bool DisplayArtist();
	bool DisplaySong(char*);
	void RemoveSpecial(int);

    private:
	artist * head;
	bool EditNumber(int, int, char*, char*, artist*);
	bool DisplayArtist(artist*);
	bool DisplaySong(char*, artist*);
	bool DisplaySong(artist*);

};

