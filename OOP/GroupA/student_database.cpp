//ASSIGNMENT NO. 3 "Student Database"


#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class student
{
	char *name,*date,*bgroup,*ip,*pa,*driving_license_no;
	float height,weight;
	double mobile_no,no;
	static long int pin;
	public:
	friend class callinfo;
	student()
	{
		name=new char[30];
		date=new char[30];
		bgroup=new char[30];
		ip=new char[30];
		pa=new char[30];
		driving_license_no=new char[30];
		strcpy(this->name,"");
		strcpy(this->date,"");
		strcpy(this->bgroup,"");
		strcpy(this->ip,"");
		strcpy(this->pa,"");
		strcpy(this->driving_license_no,"");
		height=0.0;
		weight=0.0;
		mobile_no=0.0;
	}
	student(student&s,long int d)
	{
		strcpy(this->name,s.name);
		strcpy(this->date,s.date);
		strcpy(this->bgroup,s.bgroup);
		strcpy(this->ip,s.ip);
		strcpy(this->pa,s.pa);
		strcpy(this->driving_license_no,s.driving_license_no);
		mobile_no=s.mobile_no;
		no=s.no;
		pin=d;
	}
	inline void accept()
	{
		cout<<"\nEnter the Name : ";
		cin>>name;
		cout<<"\nEnter the Date of Birth : ";
		cin>>date;
		cout<<"\nEnter the Blood Group : ";
		cin>>bgroup;
		cout<<"\nEnter the Insurance Policys : ";
		cin>>ip;
		cout<<"\nEnter the Permenant Address : ";
		cin>>pa;
		cout<<"\nEnter the Driving Licence No. : ";
		cin>>driving_license_no;
	}
	inline void display()
	{
		cout<<"\nstudent Name is : "<<name;
		cout<<"\nstudent Date of Birth is : "<<date;
		cout<<"\nstudent Blood Group is : "<<bgroup;
		cout<<"\nstudent Insurance Policys is : "<<ip;
		cout<<"\nstudent Permenant Address is : "<<pa;
		cout<<"\nstudent Driving Licence No. is : "<<driving_license_no;
	}
	static void accpin()
	{	
		cout<<"\nEnter PIN Code : ";
		cin>>pin;
	}
	static void display_pin()
	{	
		cout<<"\nstudent PIN Code : "<<pin;
	}
	~student()
	{
	    
		delete(date);
		delete(bgroup);
		delete(ip);
		delete(pa);
		delete(driving_license_no);
		delete(name);
	}
};
long int student::pin;
class callinfo
{	
	public:
	student st;
	void accept_callinfo()
	{
		cout<<"\nEnter student Height : ";
		cin>>st.height;
		cout<<"\nEnter student weight : ";
		cin>>st.weight;
	}
	void display_callinfo()
	{
		cout<<"\nstudent Height is : "<<st.height;
		cout<<"\nstudent weight is : "<<st.weight;
	}
};
int main()
{	student k[10];
	student p[10];
	callinfo k1[10];
	int ch,n;
	do
	{	cout<<"\n*******WELCOME TO DATABASE*******\n\v";	
		cout<<"\n1. Accept Student Details\n2. Display Student Details\n3. Exit\v";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter how many data you want : ";
				cin>>n;
				for(int i=0;i<n;i++)
				{
					cout<<"\nEnter Data For Student "<<i+1<<" : "<<endl;
					k[i].accept();
					student::accpin();
					k1[i].accept_callinfo();
					p[i]=student(k[i]);
					cout<<endl<<"////////////////////////////////////////////////////////////"<<endl;
				}
				break;
			case 2:
				for(int j=0;j<n;j++)
				{
					cout<<"\nData For Student "<<j+1<<" : "<<endl;
					k[j].display();
					student::display_pin();
					k1[j].display_callinfo();
					p[j].display();
					cout<<endl<<"////////////////////////////////////////////////////////////"<<endl;
				}
				break;
			case 3:	
				exit(0);
				break;
			default:
			        cout<<"Wrong Choice"<<endl;
		}
		
	}while(1);
	return 0;
}

/****************OUTPUT**********************/

/*
1. Accept Student Details
2. Display Student Details
3. Exit

Enter your choice : 1

Enter how many data you want : 2

Enter Data For Student 1 : 

Enter the Name : John

Enter the Date of Birth : 01/11/1996

Enter the Blood Group : B+

Enter the Insurance Policys : LIC

Enter the Permenant Address : Pune

Enter the Driving Licence No. : 1234 

Enter PIN Code : 411047

Enter student Height : 6

Enter student weight : 65

////////////////////////////////////////////////////////////

Enter Data For Student 2 : 

Enter the Name : Alice

Enter the Date of Birth : 18/02/1995

Enter the Blood Group : O-

Enter the Insurance Policys : MAXLIFE

Enter the Permenant Address : Goa

Enter the Driving Licence No. : 5678

Enter PIN Code : 400011

Enter student Height : 5

Enter student weight : 66

////////////////////////////////////////////////////////////

*******WELCOME TO DATABASE*******


1. Accept Student Details
2. Display Student Details
3. Exit

Enter your choice : 2

Data For Student 1 : 

student Name is : John
student Date of Birth is : 01/11/1996
student Blood Group is : B+
student Insurance Policys is : LIC
student Permenant Address is : Pune
student Driving Licence No. is : 1234
student PIN Code : 400011
student Height is : 6
student weight is : 65
student Name is : John
student Date of Birth is : 01/11/1996
student Blood Group is : B+
student Insurance Policys is : LIC
student Permenant Address is : Pune
student Driving Licence No. is : 1234
////////////////////////////////////////////////////////////

Data For Student 2 : 

student Name is : Alice
student Date of Birth is : 18/02/1995
student Blood Group is : O-
student Insurance Policys is : MAXLIFE
student Permenant Address is : Goa
student Driving Licence No. is : 5678
student PIN Code : 400011
student Height is : 5
student weight is : 66
student Name is : Alice
student Date of Birth is : 18/02/1995
student Blood Group is : O-
student Insurance Policys is : MAXLIFE
student Permenant Address is : Goa
student Driving Licence No. is : 5678
////////////////////////////////////////////////////////////
*/
