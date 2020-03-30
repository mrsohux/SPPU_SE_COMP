#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class exc
{	int age,wheeler;
	long int income;
	char city[12];
	public:
		exc()
		{	age=20;
			income=52000;
			wheeler=4;
			strcpy(city,"pune");
		}
		void accept();
		void reset();
		void display();
};



void exc::accept()
{
int a;
try
   {	cout<<"\nEnter the age\n";
	cin>>age;
	if(age>55||age<18)
	throw(-1);
	//if(a==0)
	cout<<"\nEnter the income\n";
	cin>>income;
	if((income<50000)||(income>100000))
	throw(0);			
	cout<<"\nEnter the city\n";
	cin>>city;
	if(strcmp(city,"Pune")!=0)
	if(strcmp(city,"Mumbai")!=0)
	if(strcmp(city,"Bangalore")!=0)
	if(strcmp(city,"Chennai")!=0)
	throw(1);
	cout<<"\nEnter the wheeler\n";
	cin>>wheeler;
	if((wheeler!=4))
		throw(2);
     }
     catch(int val)
     {
	switch(val)
	{
		case -1:
			cout<<"exc caught at age is less than 18 & greater than 50....\n";
			//ac1();			
			reset();
			display();
						
			break;
		case 0:
			cout<<"exc caught at income greater than 100000 & less than 50000...\n";
			//ac2();
			reset();
			display();
			break;
		case 1:
			cout<<"\nexc caught at city is not Pune, Mumbai, Bangalore, Chennai  \n";
			//ac3();
			reset();
			display();
			break;
		case 2:
			cout<<"exc caught at vechile should not have 4-wheeler....\n";
			reset();
			display();
			break;
	
     }

}

}

void exc::display()
{
cout<<"\n Age:- "<<age;
cout<<"\n Income:- "<<income;
cout<<"\n City:- "<<city;
cout<<"\n Wheeler:- "<<wheeler<<"\n";
}


void exc::reset()
{	age=0;
	income=0;
	wheeler=0;
	strcpy(city," ");
}


int main()
{	int ch;
	exc e;	
	do
	{
	  cout<<"\n1. Accept Data\n2. Display\n3. Exit\n";
	  cout<<"Enter your choice: ";
	  cin>>ch;
	   switch(ch)
		{
			case 1:e.accept();
				break;

			case 2:e.display();
			         break;

			case 3:exit(0);
		}
	}while(ch!=3);
return 0;
}
