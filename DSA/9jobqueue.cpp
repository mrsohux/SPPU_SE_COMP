
Problem Statements- Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. If the operating system does not use priorities, then
the jobs are processed in the order they enter the system. Write C++ program for simulating
job queue. Write functions to add job and delete job from queue.
*/

#include<iostream>
#include<stdlib.h>
#define MAX 10
using namespace std;

class Jobqueue
{
	int rear,front;
	int queue[MAX];
public:
	
	void initialize();
	void insert(int x);
	int delete1();
	void display();
};
void Jobqueue::initialize()
{
	int i;
	front=rear=-1;
	for(i=0;i<MAX;i++)
	{
		queue[i]=0;
	}
}
void Jobqueue::insert(int x)
{   
	if(rear==MAX-1)
	{
		cout<<"\n Job Queue is full...";
	}
	else
	{  
		rear ++;
		queue[rear]=x;
		if(front==-1)
         	    front=0;
       
	}
}
int Jobqueue::delete1()
{
		int data;
		if(front==-1 && rear==-1)
		{
			cout<<"\n Job Queue is empty... ";
		}
	
		data=queue[front];
		queue[front]=0;
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front ++;
		}
	return(data);
}
void Jobqueue::display()
{
	int i;	
  cout<<"\n Operating System Job Queue......Consider 0 as Blank....\n";
  for(i=0;i<MAX;i++)
  {
	cout<<"  "<<queue[i];
  }
	
}

int main()
{
	Jobqueue s1;
	int ch,n,x;
	s1.initialize();
	while(1)
	{
		cout<<"\n\n Opearting System Job Queue...(Queue size is 10)";
		cout<<"\n 1. Add Job (Insert Job in queue)";
		cout<<"\n 2. Delete Job (Delete entry from queue)";
		cout<<"\n 3. Display Job queue Scenario..";
		cout<<"\n 4. Exit ";
		cout<<"\n Enter your choice= ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n Enter the Job Number=  ";
				cin>>x;
				s1.insert(x);
				s1.display();
			break;

			case 2:
				x=s1.delete1();
				if(x > 0)
				{
					cout<<"\n Job number "<<x<<" is Completed...\n(Deleted from the Queue.)";
				}
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
[DSA@localhost ~]$ g++ jobqueue.cpp
[DSA@localhost ~]$ ./a.out


 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  10

 Operating System Job Queue......Consider 0 as Blank....
  10  0  0  0  0  0  0  0  0  0

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  20

 Operating System Job Queue......Consider 0 as Blank....
  10  20  0  0  0  0  0  0  0  0

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  30

 Operating System Job Queue......Consider 0 as Blank....
  10  20  30  0  0  0  0  0  0  0

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  40

 Operating System Job Queue......Consider 0 as Blank....
  10  20  30  40  0  0  0  0  0  0

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  50

 Operating System Job Queue......Consider 0 as Blank....
  10  20  30  40  50  0  0  0  0  0

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  60

 Operating System Job Queue......Consider 0 as Blank....
  10  20  30  40  50  60  0  0  0  0

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  70

 Operating System Job Queue......Consider 0 as Blank....
  10  20  30  40  50  60  70  0  0  0

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  80

 Operating System Job Queue......Consider 0 as Blank....
  10  20  30  40  50  60  70  80  0  0

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  90

 Operating System Job Queue......Consider 0 as Blank....
  10  20  30  40  50  60  70  80  90  0

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  100

 Operating System Job Queue......Consider 0 as Blank....
  10  20  30  40  50  60  70  80  90  100

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  110

 Job Queue is full...
 Operating System Job Queue......Consider 0 as Blank....
  10  20  30  40  50  60  70  80  90  100

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 2

 Job number 10 is Completed...
(Deleted from the Queue.)
 Operating System Job Queue......Consider 0 as Blank....
  0  20  30  40  50  60  70  80  90  100

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 2

 Job number 20 is Completed...
(Deleted from the Queue.)
 Operating System Job Queue......Consider 0 as Blank....
  0  0  30  40  50  60  70  80  90  100

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 2

 Job number 30 is Completed...
(Deleted from the Queue.)
 Operating System Job Queue......Consider 0 as Blank....
  0  0  0  40  50  60  70  80  90  100

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 2

 Job number 40 is Completed...
(Deleted from the Queue.)
 Operating System Job Queue......Consider 0 as Blank....
  0  0  0  0  50  60  70  80  90  100

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 2

 Job number 50 is Completed...
(Deleted from the Queue.)
 Operating System Job Queue......Consider 0 as Blank....
  0  0  0  0  0  60  70  80  90  100

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 2

 Job number 60 is Completed...
(Deleted from the Queue.)
 Operating System Job Queue......Consider 0 as Blank....
  0  0  0  0  0  0  70  80  90  100

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 2

 Job number 70 is Completed...
(Deleted from the Queue.)
 Operating System Job Queue......Consider 0 as Blank....
  0  0  0  0  0  0  0  80  90  100

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 2

 Job number 80 is Completed...
(Deleted from the Queue.)
 Operating System Job Queue......Consider 0 as Blank....
  0  0  0  0  0  0  0  0  90  100

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 2

 Job number 90 is Completed...
(Deleted from the Queue.)
 Operating System Job Queue......Consider 0 as Blank....
  0  0  0  0  0  0  0  0  0  100

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 2

 Job number 100 is Completed...
(Deleted from the Queue.)
 Operating System Job Queue......Consider 0 as Blank....
  0  0  0  0  0  0  0  0  0  0

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 2

 Job Queue is empty... 
 Operating System Job Queue......Consider 0 as Blank....
  0  0  0  0  0  0  0  0  0  0

 Opearting System Job Queue...(Queue size is 10)
 1. Add Job (Insert Job in queue)
 2. Delete Job (Delete entry from queue)
 3. Display Job queue Scenario..
 4. Exit 
 Enter your choice= 4    
[DSA@localhost ~]$ 

*/


		
	














	





	




	
