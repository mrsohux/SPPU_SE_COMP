
Write C++ program for storing binary number using doubly linked lists. Write functions-
a) to compute 1‘s and 2‘s complement b) add two binary numbers
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class node
{
	int data;
	node *next;
	node *prev;
	public:
	node *create(node *head)
	{
		head=new node;
		head->data=0;
		head->next=NULL;
		head->prev=NULL;
		return head;
	}

	void display(node *head)
	{
		node *temp;
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
			cout<<temp->data<<"\t";
		}
	}

	void insert_at_begin(node *head,int x)
	{
		node *nw,*temp;
		nw=new node;
		nw->next=nw->prev=NULL;
		nw->data=x;
		if(head->next==NULL)
		{
			head->next=nw;
			nw->prev=head;
		}
		else
		{
			nw->next=head->next;
			head->next->prev=nw;
			head->next=nw;
			nw->prev=head;
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
		nw->prev=temp;
	}
	node *ones_complement(node *head)
	{
		node *temp,*ones_head;
		ones_head=create(ones_head);
		temp=head;
		while(temp->next!=NULL)
		{
			if(temp->next->data==0)
			{
				insert_at_end(ones_head,1);
			}
			else
			{
				insert_at_end(ones_head,0);
			}
			temp=temp->next;
		}
		return ones_head;
	}
	node *twos_complement(node *head)
	{
		node *temp,*twos_head;
		int carry=1;
		twos_head=create(twos_head);
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		while(temp->prev!=NULL)
		{
			if(temp->data==1 && carry==1)
			{
				insert_at_begin(twos_head,0);
			}
			else if(temp->data==0 && carry==1)
			{
				insert_at_begin(twos_head,1);
				carry=0;
			}
			else
			{
				insert_at_begin(twos_head,temp->data);
			}
			temp=temp->prev;
		}
		return twos_head;
	}
	void add(node *head,node *head1)
	{
		node *temp1,*temp2,*a_head;
		int carry=0;
		a_head=create(a_head);
		temp1=head;
		temp2=head1;
		while(temp1->next!=NULL)
			temp1=temp1->next;
		while(temp2->next!=NULL)
			temp2=temp2->next;
		while(temp1->prev!=NULL)
		{
			insert_at_begin(a_head,(temp1->data+temp2->data+carry)%2);
			carry=(temp1->data+temp2->data+carry)/2;
			temp1=temp1->prev;
			temp2=temp2->prev;
		}
		if(carry==1)
		{
			insert_at_begin(a_head,1);
		}
		cout<<"\nAddition of binary numbers is:";
		display(a_head);
	}
};


int main()
{
	node s;
	node *head1,*head2,*ones_head1,*ones_head2,*twos_head1,*twos_head2;
	int ch,i,x;

	while(1)
	{
		cout<<"\n---------MENU---------";
		cout<<"\n 1.CREATE HEAD NODES";
		cout<<"\n 2.ENTER TWO BINARY NUMBERS";
		cout<<"\n 3.1's COMPLEMENT";
		cout<<"\n 4.2's COMPLEMENT";
		cout<<"\n 5.ADD TWO BINARY NUMBERS";
		cout<<"\n 6.EXIT";
		cout<<"\n enter your choice"<<endl;
		cin>>ch;

		switch(ch)
		{
			case 1:head1=s.create(head1);
				head2=s.create(head2);
				break;

			case 2:
				cout<<"\nEnter first 4 digit binary number:";
				for(i=0;i<4;i++)
				{
					cin>>x;
					s.insert_at_end(head1,x);
				}
				cout<<"\nFirst Binary number is:";
				s.display(head1);
				cout<<"\nEnter second 4 digit binary number:";
				for(i=0;i<4;i++)
				{
					cin>>x;
					s.insert_at_end(head2,x);
				}
				cout<<"\nSecond Binary number is:";
				s.display(head2);	
				break;

			case 3:ones_head1=s.ones_complement(head1);
				cout<<"\nOnes complement of First binary Number is:";
				s.display(ones_head1);
				ones_head2=s.ones_complement(head2);
				cout<<"\nOnes complement of Second binary Number is:";
				s.display(ones_head2);
				break;

			case 4:twos_head1=s.twos_complement(ones_head1); 
				cout<<"\nTwos complement of First Binary Number is:";
				s.display(twos_head1);
				twos_head2=s.twos_complement(ones_head2); 
				cout<<"\nTwos complement of Second Binary Number is:";
				s.display(twos_head2);
				break;
		
			case 5:s.add(head1,head2);
				break;

			case 6:exit(0);

		}
		
		
		
	}
	return 0;
}

/*************************************OUTPUT*************************************************
[student@localhost ~]$ g++ binary.cpp
[student@localhost ~]$ ./a.out

---------MENU---------
 1.CREATE HEAD NODES
 2.ENTER TWO BINARY NUMBERS
 3.1's COMPLEMENT
 4.2's COMPLEMENT
 5.ADD TWO BINARY NUMBERS
 6.EXIT
 enter your choice
1

---------MENU---------
 1.CREATE HEAD NODES
 2.ENTER TWO BINARY NUMBERS
 3.1's COMPLEMENT
 4.2's COMPLEMENT
 5.ADD TWO BINARY NUMBERS
 6.EXIT
 enter your choice
2

Enter first 4 digit binary number:0 1 0 0

First Binary number is:0	1	0	0	
Enter second 4 digit binary number:1 0 1 1

Second Binary number is:1	0	1	1	
---------MENU---------
 1.CREATE HEAD NODES
 2.ENTER TWO BINARY NUMBERS
 3.1's COMPLEMENT
 4.2's COMPLEMENT
 5.ADD TWO BINARY NUMBERS
 6.EXIT
 enter your choice
3

Ones complement of First binary Number is:1	0	1	1	
Ones complement of Second binary Number is:0	1	0	0	
---------MENU---------
 1.CREATE HEAD NODES
 2.ENTER TWO BINARY NUMBERS
 3.1's COMPLEMENT
 4.2's COMPLEMENT
 5.ADD TWO BINARY NUMBERS
 6.EXIT
 enter your choice
4

Twos complement of First Binary Number is:1	1	0	0	
Twos complement of Second Binary Number is:0	1	0	1	
---------MENU---------
 1.CREATE HEAD NODES
 2.ENTER TWO BINARY NUMBERS
 3.1's COMPLEMENT
 4.2's COMPLEMENT
 5.ADD TWO BINARY NUMBERS
 6.EXIT
 enter your choice
5

Addition of binary numbers is:1	   1	1	1	
---------MENU---------
 1.CREATE HEAD NODES
 2.ENTER TWO BINARY NUMBERS
 3.1's COMPLEMENT
 4.2's COMPLEMENT
 5.ADD TWO BINARY NUMBERS
 6.EXIT
 enter your choice
6
[student@localhost ~]$ 

*/
