/*
Write C++ program to store set of negative and positive numbers using linked list. Write
functions to
a) Insert numbers
b) Delete nodes with negative numbers
c) Create two more linked lists using this list, one containing all positive numbers and
other containing negative numbers
d) For two lists that are sorted; Merge these two lists into third resultant list that is sorted
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class node
{
	int data;
	node *next;
	public:
	node *create(node *head)
	{
		head=new node;
		head->data=0;
		head->next=NULL;
		return head;
	}

	void display(node *head)
	{
		node *temp;
		temp=head;
		cout<<"\nLINKED LIST IS:";
		while(temp->next!=NULL)
		{
			temp=temp->next;
			cout<<temp->data<<"\t";
		}
	}

	void insert_at_end(node *head,int x)
	{
		node *nw,*temp;
		nw=new node;
		nw->next=NULL;
		nw->data=x;
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=nw;
		head->data++;
	}
	void delete_node(node *head)
	{
		node *temp,*t1;
		int x;
		temp=head;
		while(temp->next!=NULL)
		{
			if(temp->next->data<0)
			{
				t1=temp->next;
				temp->next=t1->next;
				delete(t1);
				head->data--;
			}
			else
			{
				temp=temp->next;	
			}
		}
		display(head);
	}
	void separate(node *head)
	{
		node *head1=NULL,*head2=NULL,*temp;
		head1=create(head1);
		head2=create(head2);
		temp=head;
		while(temp->next!=NULL)
		{
			if(temp->next->data>0)
				insert_at_end(head1,temp->next->data);
			else
				insert_at_end(head2,temp->next->data);
			temp=temp->next;		
		}
		cout<<"\nPositive Nodes are:\n";
		display(head1);
		cout<<"\nNegative Nodes are:\n";
		display(head2);
		merge(head1,head2);
	}
	void merge(node *head1,node *head2)
	{
		node *mhead=NULL,*temp1,*temp2;
		mhead=create(mhead);
		temp1=head1;
		temp2=head2;
		while(temp1->next!=NULL && temp2->next!=NULL)
		{
			if(temp1->next->data<temp2->next->data)
			{
				insert_at_end(mhead,temp1->next->data);
				temp1=temp1->next;
			}
			else
			{
				insert_at_end(mhead,temp2->next->data);
				temp2=temp2->next;
			}
		}
		while(temp1->next!=NULL)
		{
			insert_at_end(mhead,temp1->next->data);
			temp1=temp1->next;
		}
		while(temp2->next!=NULL)
		{
			insert_at_end(mhead,temp2->next->data);
			temp2=temp2->next;
		}
		cout<<"\nLinked List after Merging is:";
		display(mhead);
	}	

};

int main()
{
	node s;
	node *head=NULL;
	int ch,x;
	while(1)
	{
		cout<<"\n---------MENU---------";
		cout<<"\n 1.CREATE NODE";
		cout<<"\n 2.INSERT A NODE IN LINKED LIST";
		cout<<"\n 3.DELETE NODE WITH (-VE) NUMBERS";
		cout<<"\n 4.SEPARATE LINKED LIST INTO +VE AND -VE NUMBERS AND MERGE";
		cout<<"\n 5.DISPLAY";
		cout<<"\n 6.EXIT";
		cout<<"\n enter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:head=s.create(head);
				cout<<"\nHead Node created\n";
				break;

			case 2:	cout<<"\n enter the data for new node";
				cin>>x;
				s.insert_at_end(head,x);
				break;

			case 3:s.delete_node(head);
				break;

			case 4:s.separate(head);
				break;
		
			case 5:s.display(head);
				break;

			case 6:exit(0);
		}	
	}
	return 0;
}

/**********OUTPUT***********************************************************
[student@localhost ~]$ g++ singly1.cpp
[student@localhost ~]$ ./a.out

---------MENU---------
 1.CREATE NODE
 2.INSERT A NODE IN LINKED LIST
 3.DELETE NODE WITH (-VE) NUMBERS
 4.SEPARATE LINKED LIST INTO +VE AND -VE NUMBERS AND MERGE
 5.DISPLAY
 6.EXIT
 enter your choice
1

Head Node created

---------MENU---------
 1.CREATE NODE
 2.INSERT A NODE IN LINKED LIST
 3.DELETE NODE WITH (-VE) NUMBERS
 4.SEPARATE LINKED LIST INTO +VE AND -VE NUMBERS AND MERGE
 5.DISPLAY
 6.EXIT
 enter your choice
2

 enter the data for new node1

---------MENU---------
 1.CREATE NODE
 2.INSERT A NODE IN LINKED LIST
 3.DELETE NODE WITH (-VE) NUMBERS
 4.SEPARATE LINKED LIST INTO +VE AND -VE NUMBERS AND MERGE
 5.DISPLAY
 6.EXIT
 enter your choice
2

 enter the data for new node-2

---------MENU---------
 1.CREATE NODE
 2.INSERT A NODE IN LINKED LIST
 3.DELETE NODE WITH (-VE) NUMBERS
 4.SEPARATE LINKED LIST INTO +VE AND -VE NUMBERS AND MERGE
 5.DISPLAY
 6.EXIT
 enter your choice
2

 enter the data for new node3

---------MENU---------
 1.CREATE NODE
 2.INSERT A NODE IN LINKED LIST
 3.DELETE NODE WITH (-VE) NUMBERS
 4.SEPARATE LINKED LIST INTO +VE AND -VE NUMBERS AND MERGE
 5.DISPLAY
 6.EXIT
 enter your choice
2

 enter the data for new node-4

---------MENU---------
 1.CREATE NODE
 2.INSERT A NODE IN LINKED LIST
 3.DELETE NODE WITH (-VE) NUMBERS
 4.SEPARATE LINKED LIST INTO +VE AND -VE NUMBERS AND MERGE
 5.DISPLAY
 6.EXIT
 enter your choice
2

 enter the data for new node5

---------MENU---------
 1.CREATE NODE
 2.INSERT A NODE IN LINKED LIST
 3.DELETE NODE WITH (-VE) NUMBERS
 4.SEPARATE LINKED LIST INTO +VE AND -VE NUMBERS AND MERGE
 5.DISPLAY
 6.EXIT
 enter your choice
5

LINKED LIST IS:1	-2	3	-4	5	
---------MENU---------
 1.CREATE NODE
 2.INSERT A NODE IN LINKED LIST
 3.DELETE NODE WITH (-VE) NUMBERS
 4.SEPARATE LINKED LIST INTO +VE AND -VE NUMBERS AND MERGE
 5.DISPLAY
 6.EXIT
 enter your choice
3

LINKED LIST IS:1	3	5	
---------MENU---------
 1.CREATE NODE
 2.INSERT A NODE IN LINKED LIST
 3.DELETE NODE WITH (-VE) NUMBERS
 4.SEPARATE LINKED LIST INTO +VE AND -VE NUMBERS AND MERGE
 5.DISPLAY
 6.EXIT
 enter your choice
2

 enter the data for new node-6

---------MENU---------
 1.CREATE NODE
 2.INSERT A NODE IN LINKED LIST
 3.DELETE NODE WITH (-VE) NUMBERS
 4.SEPARATE LINKED LIST INTO +VE AND -VE NUMBERS AND MERGE
 5.DISPLAY
 6.EXIT
 enter your choice
2

 enter the data for new node-4

---------MENU---------
 1.CREATE NODE
 2.INSERT A NODE IN LINKED LIST
 3.DELETE NODE WITH (-VE) NUMBERS
 4.SEPARATE LINKED LIST INTO +VE AND -VE NUMBERS AND MERGE
 5.DISPLAY
 6.EXIT
 enter your choice
2

 enter the data for new node7

---------MENU---------
 1.CREATE NODE
 2.INSERT A NODE IN LINKED LIST
 3.DELETE NODE WITH (-VE) NUMBERS
 4.SEPARATE LINKED LIST INTO +VE AND -VE NUMBERS AND MERGE
 5.DISPLAY
 6.EXIT
 enter your choice
5

LINKED LIST IS:1	3	5	-6	-4	7	
---------MENU---------
 1.CREATE NODE
 2.INSERT A NODE IN LINKED LIST
 3.DELETE NODE WITH (-VE) NUMBERS
 4.SEPARATE LINKED LIST INTO +VE AND -VE NUMBERS AND MERGE
 5.DISPLAY
 6.EXIT
 enter your choice
4

Positive Nodes are:

LINKED LIST IS:1	3	5	7	
Negative Nodes are:

LINKED LIST IS:-6	-4	
Linked List after Merging is:
LINKED LIST IS:-6	-4	1	3	5	7	
---------MENU---------
 1.CREATE NODE
 2.INSERT A NODE IN LINKED LIST
 3.DELETE NODE WITH (-VE) NUMBERS
 4.SEPARATE LINKED LIST INTO +VE AND -VE NUMBERS AND MERGE
 5.DISPLAY
 6.EXIT
 enter your choice
6
[student@localhost ~]$ 
*/
