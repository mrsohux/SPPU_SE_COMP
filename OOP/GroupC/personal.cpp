/*Personal Information using stl*/
#include<iostream>
#include<list>
#include<string.h>
#include<stdlib.h>
using namespace std;

class person
{
 	char name[30];
	char dob[15];
	char phno[15];
	list<person>s1;

public: 
	bool operator<(person q)
	{
		if(strcmp(dob,q.dob)<0)
			 return true;
 		else 
			 return false;
	}	

	void insert(person p1)
	{
 		int i,n;
 		cout<<"\nHow many records Do u want to insert : ";
 		cin>>n;
		
 		for(i=0;i<n;i++)
 		{
			cout<<"\nEnter Records for : "<<i+1<<endl;
			cout<<"Enter name : ";
			cin>>p1.name;
 			cout<<"Enter Date_Of_Birth : ";
			cin>>p1.dob;
			cout<<"Enter phone number : ";
 			cin>>p1.phno;
			s1.push_back(p1);
		 }
	}

	void display()
	{
		 list<person>::iterator P;
		 cout<<"\nThe Elememts of list are : ";
		 cout<<"\nName \t Date-Of-Birth \t Phone No.\n";
 		 for(P=s1.begin();P!=s1.end();P++)
  		{
   			cout<<"\n"<<(*P).name;
			cout<<"\t"<<(*P).dob;
			cout<<"\t"<<(*P).phno;
 		}
	}

	void search()
	{
		list<person>::iterator P;
 		char item[20];
		int flag;
		cout<<"\nEnter name to be searched:";
		cin>>item;
		for(P=s1.begin();P!=s1.end();P++)
 		{
 			if(strcmp((*P).name,item)==0)
  			{
    				cout<<"\nRecord is found!!";
				cout<<"\nName";
				cout<<"\tDate_Of_Birth";
				cout<<"\tPhone No.";
				cout<<"\n"<<(*P).name;
				cout<<"\t"<<(*P).dob;
				cout<<"\t"<<(*P).phno;
				flag=1;
				break;
  			}
 		}
 		if(flag==0)
			 cout<<"\nRecord not found!!";
	}		
	void sort()
	{
		s1.sort();
		cout<<"Records sorted successfully!";
	}
};
int main()
{
  	person p,p1;
	int ch;
	do
	{
 		cout<<"\n1. Create \n2. Display \n3. Search \n4. Sort \n5. Exit\n\nEnter your choice : ";
 		cin>>ch;
		switch(ch)
 		{
			case 1:
				p.insert(p1);
				break;
 			case 2:
				p.display();
 				break;
 			case 3:
				p.search();
 		        	break;
 			case 4:
		                 p.sort();
 				 break;
 			case 5:
				exit(0);
 		 }
	 }while(ch!=5);



return 0;
}
/*
1. Create 
2. Display 
3. Search 
4. Sort 
5. Exit

Enter your choice : 1

How many records Do u want to insert : 2

Enter Records for : 1
Enter name : john
Enter Date_Of_Birth : 01/01/1997
Enter phone number : 1234567890

Enter Records for : 2
Enter name : jane
Enter Date_Of_Birth : 22/02/1980
Enter phone number : 9326452451    

1. Create 
2. Display 
3. Search 
4. Sort 
5. Exit

Enter your choice : 2

The Elememts of list are : 
Name 	 Date-Of-Birth 	 Phone No.

john	01/01/1997	1234567890
jane	22/02/1980	9326452451
1. Create 
2. Display 
3. Search 
4. Sort 
5. Exit

Enter your choice : 3

Enter name to be searched:jane

Record is found!!
Name	Date_Of_Birth	Phone No.
jane	22/02/1980	9326452451
1. Create 
2. Display 
3. Search 
4. Sort 
5. Exit

Enter your choice : 4
Records sorted successfully!
1. Create 
2. Display 
3. Search 
4. Sort 
5. Exit

Enter your choice : 2

The Elememts of list are : 
Name 	 Date-Of-Birth 	 Phone No.

john	01/01/1997	1234567890
jane	22/02/1980	9326452451
1. Create 
2. Display 
3. Search 
4. Sort 
5. Exit

Enter your choice : 1

How many records Do u want to insert : 1   

Enter Records for : 1
Enter name : marry
Enter Date_Of_Birth : 01/01/1995
Enter phone number : 9874561230

1. Create 
2. Display 
3. Search 
4. Sort 
5. Exit

Enter your choice : 2

The Elememts of list are : 
Name 	 Date-Of-Birth 	 Phone No.

john	01/01/1997	1234567890
jane	22/02/1980	9326452451
marry	01/01/1995	9874561230
1. Create 
2. Display 
3. Search 
4. Sort 
5. Exit

Enter your choice : 4
Records sorted successfully!
1. Create 
2. Display 
3. Search 
4. Sort 
5. Exit

Enter your choice : 2

The Elememts of list are : 
Name 	 Date-Of-Birth 	 Phone No.

marry	01/01/1995	9874561230
john	01/01/1997	1234567890
jane	22/02/1980	9326452451
1. Create 
2. Display 
3. Search 
4. Sort 
5. Exit

Enter your choice : 5

*/
