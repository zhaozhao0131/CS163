#include"list.h"

//CS163
//Jiacheng Zhao
//Program 1
//main.cpp

using namespace std;


int main(){

    list art;


    int input;
    cout<<"This is a songs system"<<endl;
    cout<<"Input the following code for the function."<<endl;

    char Name[20];
    char Story[100];
    char Des[100];
    char Title[20];
    int Length = 0;
    int View = 0;
    int Likes = 0;


    
    do
    {
	cout<<"======================================================="<<endl;
	cout<<"1 Add artist"<<endl;
	cout<<"2 Add song of artist"<<endl;
	cout<<"3 Edit the number of song"<<endl;
	cout<<"4 Display all artist"<<endl;
	cout<<"5 Display all songs"<<endl;
	cout<<"6 Remove lower songs"<<endl;
	cout<<"0 Exit system"<<endl;
	cin>>input;
	cin.ignore();
	switch(input){
    //------------------------------Add artist----------------------------------
	    case 1:{		        
			cout<<"Please enter name"<<endl;
			cin.get(Name,20,'\n');
			cin.ignore(100,'\n');
			cout<<"Please enter story"<<endl;
			cin.get(Story,100,'\n');
			cin.ignore(100,'\n');
			cout<<"Pleaase enter description"<<endl;
			cin.get(Des,100,'\n');
			cin.ignore(100,'\n');

			art.AddArtist(Name, Story, Des);	

		       break;
		   }
    //-----------------------------Add song of artist---------------------------
	    case 2:{
			cout<<"Please enter title"<<endl;
			cin.get(Title,20,'\n');
			cin.ignore(100,'\n');
			cout<<"Please enter length"<<endl;
			cin>>Length;
			cin.ignore(100,'\n');
			cout<<"Please enter views"<<endl;
			cin>>View;
			cin.ignore(100,'\n');
			cout<<"Please enter likes"<<endl;
			cin>>Likes;
			cin.ignore(100,'\n');

			art.AddSong(Title, Length, View, Likes);

		       break;
		   }
    //-----------------------Edit the number of song----------------------------
	    case 3:{
		       cout<<"Enter name of artist"<<endl;
		       cin.get(Name,20,'\n');
		       cin.ignore(100,'\n');
		       cout<<"Enter title of song"<<endl;
		       cin.get(Title,20,'\n');
	               cin.ignore(100,'\n');
		       cout<<"Enter new views"<<endl;
		       cin>>View;
		       cin.ignore(100,'\n');
		       cout<<"Enter new likes"<<endl;
		       cin>>Likes;
		       cin.ignore(100,'\n');

		       art.EditNumber(View,Likes,Name,Title);

		       break;
		   }
    //--------------------------Display all artist------------------------------
	    case 4:{
		       art.DisplayArtist();

		       break;
		   }
    //--------------------------Display all songs-------------------------------
	    case 5:{ 
		       cout<<"Enter artist'name to check song"<<endl;
		       cin.get(Name,20,'\n');
		       cin.ignore(100,'\n');
		       
		       if(art.DisplaySong(Name)==0)
			   cout<<"there is no artist in list"<<endl;

		       break;
		   }
    //-------------------------Remove lower songs------------------------------
	    case 6:{
		       cout<<"Please enter views to delete lower song"<<endl;
		       int M = 0;
		       cin>>M;
		       cin.ignore(100,'\n');

		       art.RemoveSpecial(M);

		       break;
		   }
	    default:{
			if(input)
			    cout<<"Invalid input"<<endl;
			break;
		    }
	}
    }while(input!=0);
}
