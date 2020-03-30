

Problem Statements- Pizza parlor accepting maximum M orders. Orders are served in first come first served basis. Order once placed can not be cancelled. Write C++ program to simulate the system
using circular queue using array.
*/

#include<iostream>
#include<stdlib.h>
#define MAX 10
using namespace std;

class pizza
{
	int rear,front;
	int queue[MAX];
public:
	
	void initialize();
	void insert(int x);
	int delete1();
	void display();
};
void pizza::initialize()
{
	int i;
	front=rear=-1;
	for(i=0;i<MAX;i++)
	{
		queue[i]=0;
	}
}
void pizza::insert(int x)
{   
	if(((rear+1)%MAX)==front)
	{
		cout<<"\n Circular Queue is full...";
	}
	else
	{  
		rear=(rear+1)%MAX;
		queue[rear]=x;
		if(front==-1)
         	    front=0;
       
	}
}
int pizza::delete1()
{
		int data;
		if(front==-1)
		{
			cout<<"\n Circular Queue is empty... ";
		}
	
		data=queue[front];
		queue[front]=0;
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front=(front+1)%MAX;
		}
	return(data);
}
void pizza::display()
{
	int i;	
  cout<<"\n All orders.............Consider 0 as Blank....\n";
  for(i=0;i<MAX;i++)
  {
	cout<<"  "<<queue[i];
  }
	
}

int main()
{
	pizza s1;
	int ch,n,x;
	s1.initialize();
	while(1)
	{
		cout<<"\n Xenon Pizza parlor....Maximum size is 10 \n";
		cout<<"\n 1. Accept Order (Insert order in queue)";
		cout<<"\n 2. Served order (Delete entry from queue)";
		cout<<"\n 3. Display All order Scenario..";
		cout<<"\n 4. Exit ";
		cout<<"\n Enter your choice= ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n Enter the New Order Number=  ";
				cin>>x;
				s1.insert(x);
				s1.display();
			break;

			case 2:
				x=s1.delete1();
				cout<<"\n Order number "<<x<<" is Serverd to the Customer...\n(Deleted from the Queue.)";
				s1.display();
			break;

			case 3:
				s1.display();
			break;
			case 4:
				exit(0);
		}
	}

}
	
/* ******************** OUTPUT **********************************************

[DSA@localhost ~]$ g++ pizzashop.cpp
[DSA@localhost ~]$ ./a.out

 Xenon Pizza parlor....Maximum size is 10 

 1. Accept Order (Insert order in queue)
 2. Served order (Delete entry from queue)
 3. Display All order Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the New Order Number=  10

 All orders.............Consider 0 as Blank....
  10  0  0  0  0  0  0  0  0  0
 Xenon Pizza parlor....Maximum size is 10 

 1. Accept Order (Insert order in queue)
 2. Served order (Delete entry from queue)
 3. Display All order Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the New Order Number=  20

 All orders.............Consider 0 as Blank....
  10  20  0  0  0  0  0  0  0  0
 Xenon Pizza parlor....Maximum size is 10 

 1. Accept Order (Insert order in queue)
 2. Served order (Delete entry from queue)
 3. Display All order Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the New Order Number=  30

 All orders.............Consider 0 as Blank....
  10  20  30  0  0  0  0  0  0  0
 Xenon Pizza parlor....Maximum size is 10 

 1. Accept Order (Insert order in queue)
 2. Served order (Delete entry from queue)
 3. Display All order Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the New Order Number=  40

 All orders.............Consider 0 as Blank....
  10  20  30  40  0  0  0  0  0  0
 Xenon Pizza parlor....Maximum size is 10 

 1. Accept Order (Insert order in queue)
 2. Served order (Delete entry from queue)
 3. Display All order Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the New Order Number=  50

 All orders.............Consider 0 as Blank....
  10  20  30  40  50  0  0  0  0  0
 Xenon Pizza parlor....Maximum size is 10 

 1. Accept Order (Insert order in queue)
 2. Served order (Delete entry from queue)
 3. Display All order Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the New Order Number=  60

 All orders.............Consider 0 as Blank....
  10  20  30  40  50  60  0  0  0  0
 Xenon Pizza parlor....Maximum size is 10 

 1. Accept Order (Insert order in queue)
 2. Served order (Delete entry from queue)
 3. Display All order Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the New Order Number=  70

 All orders.............Consider 0 as Blank....
  10  20  30  40  50  60  70  0  0  0
 Xenon Pizza parlor....Maximum size is 10 

 1. Accept Order (Insert order in queue)
 2. Served order (Delete entry from queue)
 3. Display All order Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the New Order Number=  80

 All orders.............Consider 0 as Blank....
  10  20  30  40  50  60  70  80  0  0
 Xenon Pizza parlor....Maximum size is 10 

 1. Accept Order (Insert order in queue)
 2. Served order (Delete entry from queue)
 3. Display All order Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the New Order Number=  90

 All orders.............Consider 0 as Blank....
  10  20  30  40  50  60  70  80  90  0
 Xenon Pizza parlor....Maximum size is 10 

 1. Accept Order (Insert order in queue)
 2. Served order (Delete entry from queue)
 3. Display All order Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the New Order Number=  100

 All orders.............Consider 0 as Blank....
  10  20  30  40  50  60  70  80  90  100
 Xenon Pizza parlor....Maximum size is 10 

 1. Accept Order (Insert order in queue)
 2. Served order (Delete entry from queue)
 3. Display All order Scenario..
 4. Exit 
 Enter your choice= 2

 Order number 10 is Serverd to the Customer...
(Deleted from the Queue.)
 All orders.............Consider 0 as Blank....
  0  20  30  40  50  60  70  80  90  100
 Xenon Pizza parlor....Maximum size is 10 

 1. Accept Order (Insert order in queue)
 2. Served order (Delete entry from queue)
 3. Display All order Scenario..
 4. Exit 
 Enter your choice= 2

 Order number 20 is Serverd to the Customer...
(Deleted from the Queue.)
 All orders.............Consider 0 as Blank....
  0  0  30  40  50  60  70  80  90  100
 Xenon Pizza parlor....Maximum size is 10 

 1. Accept Order (Insert order in queue)
 2. Served order (Delete entry from queue)
 3. Display All order Scenario..
 4. Exit 
 Enter your choice= 2

 Order number 30 is Serverd to the Customer...
(Deleted from the Queue.)
 All orders.............Consider 0 as Blank....
  0  0  0  40  50  60  70  80  90  100
 Xenon Pizza parlor....Maximum size is 10 

 1. Accept Order (Insert order in queue)
 2. Served order (Delete entry from queue)
 3. Display All order Scenario..
 4. Exit 
 Enter your choice= 2

 Order number 40 is Serverd to the Customer...
(Deleted from the Queue.)
 All orders.............Consider 0 as Blank....
  0  0  0  0  50  60  70  80  90  100
 Xenon Pizza parlor....Maximum size is 10 

 1. Accept Order (Insert order in queue)
 2. Served order (Delete entry from queue)
 3. Display All order Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the New Order Number=  110

 All orders.............Consider 0 as Blank....
  110  0  0  0  50  60  70  80  90  100
 Xenon Pizza parlor....Maximum size is 10 

 1. Accept Order (Insert order in queue)
 2. Served order (Delete entry from queue)
 3. Display All order Scenario..
 4. Exit 
 Enter your choice= 
*/


		
	














	





	




	
