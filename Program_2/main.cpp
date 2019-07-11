#include"stack.h"
#include"queue.h"

using namespace std;
//main.cpp
//
//Jiacheng Zhao
//
//922943778
//
//CS163

int main()
{
    queue cll;
    stack lll;

    int input;
    cout<<"This is a line system"<<endl;
    cout<<"Input the following code for the function."<<endl;

    char name[20];
    int number;
    char special[50];
    int promo = 0;
    char name_email[50];

    do{
	cout<<"====================================================="<<endl;
	cout<<"1 Add one group"<<endl;
	cout<<"2 Delete one group"<<endl;
	cout<<"3 Display all group"<<endl;
	cout<<"4 Add in promo"<<" *FOR PROMO GROUP*"<<endl;
	cout<<"5 Delete one promo"<<endl;
	cout<<"6 Display all promo"<<endl;
	cout<<"7 Display the top promo"<<endl;
	cout<<"0 Exit the system"<<endl;
	cin>>input;
	cin.ignore();
	switch(input){
	    case 1:{
	//=========================Add one group==============================
		       cout<<"Please enter the name"<<endl;
		       cin.get(name,20,'\n');
		       cin.ignore(100,'\n');
		       cout<<"Please enter the number"<<endl;
		       cin>>number;
		       cin.ignore();
		       cout<<"Please enter the special information"<<endl;
		       cin.get(special,50,'\n');
		       cin.ignore(100,'\n');
		       cout<<"Please enter 1/0 for PROMO or NOT"<<endl;
		       cin>>promo;
		       cin.ignore();
		       cll.enqueue(name,number,special,promo);

		       break;
		   }
	    case 2:{
	//========================Delete one group============================
		       if(cll.dequeue())
			   cout<<"Delete Success"<<endl;
		       else
			   cout<<"Delete False"<<endl;
		       break;
		   }
	    case 3:{
	//=======================Display all group============================
		       cll.display_all();
		       break;
		   }
	    case 4:{
	//=========================Add in promo===============================
		       cout<<"JUST FOR INTEREST PROMO GROUP"<<endl;
		       cout<<"Please enter the name and email"<<endl;
		       cin.get(name_email,20,'\n');
		       cin.ignore(100,'\n');
		       lll.push(name_email);
		       break;
		   }
	    case 5:{
	//========================Delete one promo============================
		       if(lll.pop())
			   cout<<"Delete success"<<endl;
		       else
			   cout<<"Delete false"<<endl;
		       break;
		   }
	    case 6:{
	//========================Display all promo===========================
		       lll.display_all();
		       break;
		   }
	    case 7:{
	//=====================Display the top of promo=======================
		       cout<<"the TOP infor: "<<endl;
		       lll.peek();
		   }
	    default:{
			if(input)
			    cout<<"Invalid input"<<endl;
			break;
		    }
	}
    }while(input!=0);
}
