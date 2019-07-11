#include"list.h"
//Jiacheng Zhao
//
//Program4
//
//main.cpp

int main()
{
    website web;
    table tree;

    int input;
    cout<<"This is a search system."<<endl;
    cout<<"Input the following code for the function"<<endl;

    char name[20];
    char address[100];
    char summary[100];
    char review[100];

    name[0] = '\0';
    tree.read_file(web,tree);

    do
    {
	cout<<"==========================================="<<endl;
	cout<<"1 Add website"<<endl;
	cout<<"2 Retrieve website"<<endl;
	cout<<"3 Remove a website"<<endl;
	cout<<"4 Remove all website"<<endl;
	cout<<"5 Display all website"<<endl;
	cout<<"0 Exit the system"<<endl;
	cin>>input;
	cin.ignore();

	switch(input){
	    case 1:{
//===========================Add website=============================
		       cout<<"Please enter the name"<<endl;
		       cin.get(name,20,'\n');
		       cin.ignore(100,'\n');
		       cout<<"Please enter the address"<<endl;
		       cin.get(address,100,'\n');
		       cin.ignore(100,'\n');
		       cout<<"Please enter the summary"<<endl;
		       cin.get(summary,100,'\n');
		       cin.ignore(100,'\n');
		       cout<<"please enter review"<<endl;
		       cin.get(review,100,'\n');
		       cin.ignore(100,'\n');
		       web.add(name,address,summary,review);
		       tree.insert(web);

		       break;
		   }
	    case 2:{
//========================Retrieve website===========================
		       cout<<"What website you want to retrieve, enter its name"<<endl;
		       cin.get(name,20,'\n');
		       cin.ignore(100,'\n');
		       tree.retrieve(name);

		       break;
		   }
	    case 3:{
//=======================Remove a website============================
		       cout<<"What event you want to remove, enter its name"<<endl;
		       cin.get(name,20,'\n');
		       cin.ignore(100,'\n');
		       tree.remove(name);
		       cout<<"success"<<endl;

		       break;
		   }
	    case 4:{
//======================Remove all website===========================
		       if(tree.delete_all())
			   cout<<"success"<<endl;

		       break;
		   }
	    case 5:{
//======================Display all website==========================
		       if(tree.display_all()==0)
			   cout<<"no data in tree"<<endl;

		       break;
		   }
	    default:{
			if(input)
			    cout<<"invalid input"<<endl;
			break;
		    }
	}
    }while(input!=0);
}
