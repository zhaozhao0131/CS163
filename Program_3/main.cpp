#include"list.h"
//CS163
//
//Jiacheng Zhao
//
//Program 3
//
//main.cpp
using namespace std;

int main()
{
    website act;
    table hash;
    
    int input;
    cout<<"This is a search system"<<endl;
    cout<<"Input the following code for the function."<<endl;

    char name[20];
    char summary[100];
    char review[100];
    int rate = 0;

    name[0] = '\0';
       cout<<"Please enter the name"<<endl;
       cin.get(name,20,'\n');
       cin.ignore(100,'\n');
       cout<<"Please enter the summary"<<endl;
       cin.get(summary,100,'\n');
       cin.ignore(100,'\n');
       cout<<"Please enter the review"<<endl;
       cin.get(review,100,'\n');
       cin.ignore(100,'\n');
       cout<<"Please enter the rate"<<endl;
       cin>>rate;
		       cin.ignore(100,'\n');
    hash.creat_file(name,summary,review,rate);
    hash.read_file(act,hash);
    do{
	cout<<"=============================================="<<endl;
	cout<<"1 Add new information"<<endl;
	cout<<"2 Retrieve website"<<endl;
	cout<<"3 Remove website"<<endl;
	cout<<"4 Display all website"<<endl;
	cout<<"0 Exit the system"<<endl;
	cin>>input;
	cin.ignore();
	switch(input){
	    case 1:{
//--------------------------Add new information-------------------------------
		       cout<<"Please enter the name"<<endl;
		       cin.get(name,20,'\n');
		       cin.ignore(100,'\n');
		       cout<<"Please enter the summary"<<endl;
		       cin.get(summary,100,'\n');
		       cin.ignore(100,'\n');
		       cout<<"Please enter the review"<<endl;
		       cin.get(review,100,'\n');
		       cin.ignore(100,'\n');
		       cout<<"Please enter the rate"<<endl;
		       cin>>rate;
		       cin.ignore(100,'\n');
		       act.add(name,summary,review,rate);
		       hash.insert(name,act);

		       break;
		   }
	    case 2:{
//--------------------------Retrieve website----------------------------------
		       cout<<"What you want to find, enter the name"<<endl;
		       cin.get(name,20,'\n');
		       cin.ignore(100,'\n');
		       if(hash.retrieve(name)==0)
			   cout<<"Not exist"<<endl;

		       break;
		   }
	    case 3:{ 
//-------------------------Remove website-------------------------------------
		       cout<<"What website you want to delete, enter the name"<<endl;
		       cin.get(name,20);
		       cin.ignore(100,'\n');
		       if(hash.remove(name)==0)
			   cout<<"Not find"<<endl;

		       break;
		   }
	    case 4:{
//---------------------------Display all system-------------------------------
		       hash.display_all();
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
