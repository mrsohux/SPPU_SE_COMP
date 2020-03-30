//ASSIGNMENT NO. 5 "Employee Database"
#include<iostream>
#include<stdlib.h>
using namespace std;
/*************************************Personal Class***********************************************************************************************/
class personal
{
	/*int employee_id;
	char* name;
	char* bgrp;
	char* addr;
	char* date;*/

	int employee_id;
	char name[12];
	char bgrp[12];
	char addr[12];
	char date[12];

public:
/*	personal()
	{
		employee_id=0;
		name =new char[30];
		bgrp=new char[10];
		addr=new char[30];
		date=new char[10];
	}*/
	void get_per()
	{
		cout<<"Enter Employee Name : ";
		cin>>name;
		cout<<"Enter Employee id : ";
		cin>>employee_id;		
		cout<<"Enter Residental address : ";
		cin>>addr;		
		cout<<"Enter Blood Group : ";
		cin>>bgrp;		
		cout<<"Enter Date Of Birth : ";
		cin>>date;		
		cout<<endl;
	}
	void display_per()
	{
		cout<<"Employee Name :"<<name<<endl;		
		cout<<"Employee id : "<<employee_id<<endl;		
		cout<<"Residental address : "<<addr<<endl;		
		cout<<"Blood Group : "<<bgrp<<endl;		
		cout<<"Date Of Birth : "<<date<<endl;		
	}
	/*~personal()
	{
		delete(name);
		delete(bgrp);
		delete(addr);
		delete(date);
		cout<<"Personal Data Deleted"<<endl;
	}*/
};
/*********************************************Professional Class***************************************************************************************/
class professional
{
	/*int exp;
	char* post;
	char* comp;
	char* sal;
	char* date;
	*/
	int exp;
	char post[12];
	char comp[12];
	char sal[12];
	char date[12];
public:
	/*professional()
	{
		exp=0;
		post =new char[30];
		comp=new char[10];
		sal=new char[10];
		date=new char[10];
	}*/
	void get_pro()
	{
		cout<<"Enter Employee post : ";
		cin>>post;		
		cout<<"Enter Experience : ";
		cin>>exp;		
		cout<<"Enter Salary : ";
		cin>>sal;		
		cout<<"Enter Company Name : ";
		cin>>comp;		
		cout<<"Enter Date Of Joining : ";
		cin>>date;	
		cout<<endl;	
	}
	void display_pro()
	{
		cout<<"Employee post :"<<post<<endl;		
		cout<<"Experience : "<<exp<<endl;		
		cout<<"Salary : "<<sal<<endl;		
		cout<<"Company: "<<comp<<endl;		
		cout<<"Date Of Joining : "<<date<<endl;		
	}
	/*~professional()
	{
		delete(post);
		delete(comp);
		delete(sal);
		delete(date);
		cout<<"Professional Data Deleted"<<endl;
	}*/
};
/******************************************************Academics Class******************************************************************************/
class academics
{
	//char* name;
	char name[12];
	float mark_10;
	float mark_12;
	float mark_degree;

public:
	/*academics()
	{
		mark_10=0;
		mark_12=0;
		mark_degree=0;
		name =new char[30];
	}*/
	void get_acad()
	{
		cout<<"Enter University : ";
		cin>>name;	
		cout<<"Enter 10th class Marks : ";
		cin>>mark_10;	
		cout<<"Enter 12th class Marks : ";
		cin>>mark_12;	
		cout<<"Enter degree marks : ";
		cin>>mark_degree;	
		cout<<endl;	
	}
	void display_acad()
	{
		cout<<"University Name : "<<name<<endl;		
		cout<<"Marks in 10th class : "<<mark_10<<endl;		
		cout<<"Marks in 12th class : "<<mark_12<<endl;		
		cout<<"Marks in degree : "<<mark_degree<<endl;		
	}
/*	~academics()
	{
		delete(name);
		cout<<"Academic Data Deleted"<<endl;
	}*/
};
/******************************************************Employee Class******************************************************************************/

class employee : public personal,public professional,public academics
{
public: 
		/*void set_personal()
		{
			get_per();	
		}
		void set_academics()
		{
			get_acad();
		}
		void set_professional()
		{
			get_pro();	
		}*/
		void go_set_choice(int data_choice)
		{
			if(data_choice==1)
				get_per();
			else if(data_choice==3)
				get_acad();
			else if(data_choice==2)
				get_pro();
		}
		/*void get_professional()
		{
			display_pro();	
		}
		void get_personal()
		{
			display_per();	
		}
		void get_academics()
		{
			display_acad();	
		}*/
		void go_get_choice(int data_choice)
		{
			if(data_choice==1)
				display_per();
			if(data_choice==2)
				display_pro();
			if(data_choice==3)
				display_acad();
		}
		/*~employee()
		{
			cout<<"All Data Deleted"<<endl;	
		}*/
		
};	
	


int main()
{
	int n,tya;
	int l,i=0,k=0;
	employee DB;
	cout<<endl;
	int data_choice;
		do{
		cout<<".............MENU................."<<endl
		<<"1. Set Employee Data"<<endl<<"2. Get Employee Data"<<endl////    	//<<"3. Delete Data & Exit"<<endl
		<<"Enter Choice : ";
		int reset[3]	;
		cin>>l;
		cout<<endl;
	switch(l)
	{
	case 1:	
	cout<<endl<<"1. Set Personal Data"<<endl<<"2. Set Professional Data"<<endl<<"3. set Academic Data"<<endl;
	cout<<"Enter Choice : ";
	cin>>data_choice; cout<<endl;	
	cout<<"Set Data ."<<endl;
	DB.go_set_choice(data_choice);
	break;
	
	case 2:
	cout<<endl<<"1. Get Personal Data"<<endl<<"2. Get Professional Data"<<endl<<"3. Get Academic Data"<<endl;
	cout<<"Enter Choice : ";
	cin>>data_choice; cout<<endl;	
	cout<<"Get Data ."<<endl;		
	DB.go_get_choice(data_choice);
	break;		
	}
	}while(l<=2);
return 0;
}


/***********************OUTPUT**********************************/


/*
.............MENU.................
1. Set Employee Data
2. Get Employee Data
3. Delete Data
Enter Choice : 1

1. Set Personal Data
2. Set Professional Data
3. set Academic Data
Enter Choice : 1

Set Data .
Enter Employee Name : John
Enter Employee id : 5679
Enter Residental address : Pune
Enter Blood Group : B+
Enter Date Of Birth : 01/12/1980

.............MENU.................
1. Set Employee Data
2. Get Employee Data
3. Delete Data
Enter Choice : 1

1. Set Personal Data
2. Set Professional Data
3. set Academic Data
Enter Choice : 2

Set Data .
Enter Employee post : Developer
Enter Experience : 6
Enter Salary : 15000000
Enter Company Name : Cognizant
Enter Date Of Joining : 04/05/2005

.............MENU.................
1. Set Employee Data
2. Get Employee Data
3. Delete Data
Enter Choice : 1

1. Set Personal Data
2. Set Professional Data
3. set Academic Data
Enter Choice : 3

Set Data .
Enter University : Pune
Enter 10th class Marks : 68
Enter 12th class Marks : 79
Enter degree marks : 64

.............MENU.................
1. Set Employee Data
2. Get Employee Data
3. Delete Data
Enter Choice : 2

1. Get Personal Data
2. Get Professional Data
3. Get Academic Data
Enter Choice : 1

Get Data .
Employee Name :John
Employee id : 5679
Residental address : Pune
Blood Group : B+
Date Of Birth : 01/12/1980
.............MENU.................
1. Set Employee Data
2. Get Employee Data
3. Delete Data
Enter Choice : 2

1. Get Personal Data
2. Get Professional Data
3. Get Academic Data
Enter Choice : 2

Get Data .
Employee post :Developer
Experience : 6
Salary : 15000000
Company: Cognizant
Date Of Joining : 04/05/2005
.............MENU.................
1. Set Employee Data
2. Get Employee Data
3. Delete Data
Enter Choice : 2

1. Get Personal Data
2. Get Professional Data
3. Get Academic Data
Enter Choice : 3

Get Data .
University Name : Pune
Marks in 10th class : 68
Marks in 12th class : 79
Marks in degree : 64
.............MENU.................
1. Set Employee Data
2. Get Employee Data
3. Delete Data & Exit
Enter Choice : 3

All Data Deleted
Academic Data Deleted
Professional Data Deleted
Personal Data Deleted

*/
