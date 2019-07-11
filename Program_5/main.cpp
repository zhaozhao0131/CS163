#include"list.h"

//Jiacheng Zhao
//
//Program5
//
//main.cpp

int main()
{
    cout<<"This is a graph system"<<endl;
    cout<<"Please input how many vertex you want"<<endl;
    int size = 10;
    cin>> size;
    cout<<endl;

    graph map(size);

    cout<<"Input the following code for the function"<<endl;

    int input=0;

    do
    {
	cout<<"==========================================="<<endl;
	cout<<"1 Insert a vertex"<<endl;
	cout<<"2 Insert edge"<<endl;
	cout<<"3 Display all path take from special head"<<endl;
	cout<<"4 Dipslay all connect vertices from special vertex"<<endl;
	cout<<"0 Exit system."<<endl;

	cin>>input;
	cin.ignore();
	switch(input)
	{
	    case 1:{
//===========================Insert a vertex================================
		       char Name[SIZE_name];
		       char Info[SIZE_info];

		       cout<<"Please enter vertex's name: "<<endl;
		       cin.get(Name,SIZE_name,'\n');
		       cin.ignore(100,'\n');
		       cout<<"Please enter vertex's info: "<<endl;
		       cin.get(Info,SIZE_info,'\n');
		       cin.ignore(100,'\n');

		       map.insert_vertex(Name,Info);

		       break;
		   }
	    case 2:{ 
//==========================Insert edge=====================================
		       char current[SIZE_name];
		       char connect[SIZE_name];
		       char Des[SIZE_des];
		       int Length;
		       cout<<"Plesase input current vertex's name: "<<endl;
		       cin.get(current,SIZE_name,'\n');
		       cin.ignore(100,'\n');

		       cout<<"Please input connected vertex's name: "<<endl;
		       cin.get(connect,SIZE_name,'\n');
		       cin.ignore(100,'\n');

		       cout<<"Please input edge's description: "<<endl;
		       cin.get(Des,SIZE_des,'\n');
		       cin.ignore(100,'\n');
		       cout<<"Please input edge's length: "<<endl;
		       cin>>Length;
		       
		       map.insert_edge(current,connect,Des,Length);

		       break;
		   }
	    case 3:{
//========================Display all path==================================
		       char key[SIZE_name];
		       cout<<"Please input current vertex's name: "<<endl;
		       cin.get(key,SIZE_name,'\n');
		       cin.ignore(100,'\n');
		       
		       map.display_all_path(key);

		       break;
		   }
	    case 4:{
//=========================Display all connection===========================
		       char key[SIZE_name];
		       cout<<"Please input current vertex's name: "<<endl;
		       cin.get(key,SIZE_name,'\n');
		       cin.ignore(100,'\n');

		       map.display_all_connect(key);

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
