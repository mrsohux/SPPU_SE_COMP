
Let x = (x1,x2, ... , xn) and y = (y 1, y2,.... , ym) be two doubly linked lists. Assume that in
each linked list, the nodes are in non-decreasing order of their data-field values. Write
C/C++ program to merge the two lists to obtain a new linked list z in which the nodes are
also in this order. Following the merge, x and y should represent empty lists because each
node initially in x or y is now in z. No additional nodes may be used.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
	int data;
	node *next,*prev;
	public:
		node *create(node *head)
		{
			head=new node;
			head->data=0;
			head->next=NULL;
			head->prev=NULL;
			return head;
		}
		void insertnode(node *head, int x)
		{
			node *nw,*temp;
			nw=new node;
			nw->data=x;
			nw->next=nw->prev=NULL;
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=nw;
			nw->prev=temp;
			head->data++;
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
		void merge(node *head1, node *head2)
		{
			node *temp1, *temp2, *mhead;
			mhead=create(mhead);
			temp1=head1;
			temp2=head2;
			while(temp1->next!=NULL&&temp2->next!=NULL)
			{
				if(temp1->next->data<temp2->next->data)
				{
					insertnode(mhead,temp1->next->data);
					temp1=temp1->next;
				}				
				else
				{
					insertnode(mhead,temp2->next->data);
					temp2=temp2->next;
				}
			}
			while(temp1->next!=NULL)
			{
				insertnode(mhead,temp1->next->data);
				temp1=temp1->next;
			}
			while(temp2->next!=NULL)
			{
				insertnode(mhead,temp2->next->data);
				temp2=temp2->next;
			}
			cout<<"\nList after Merging is:";
			display(mhead);
		}
};
int main()
{
	node s;
	node *head1, *head2;
	int i,n,x,ch;
	while(1)
	{
		cout<<"\nMENU";
		cout<<"\n1.CREATE TWO HEAD NODES";
		cout<<"\n2.INSERT NODES IN FIRT LINKED LIST";
		cout<<"\n3.INSERT NODES IN SECOND LINKED LIST";
		cout<<"\n4.MERGE BOTH LINKED LISTS";
		cout<<"\n5.EXIT";
		cout<<"\nEnter youur choice:- ";
		cin>>ch;	
		switch(ch)
		{
			case 1:head1=s.create(head1);
				head2=s.create(head2);
				break;
			case 2:cout<<"\n Enter a how many nodes you want:- ";
				cin>>n;
				cout<<"\nEnter data in nodes for 1st linklist:- ";
				for(i=0;i<n;i++)
				{
					cin>>x;
					s.insertnode(head1,x);
				}
				s.display(head1);
				break;
			case 3:cout<<"\n Enter a how many nodes you want:- ";
				cin>>n;
				cout<<"\nEnter data in nodes for 2nd linklist:- ";
				for(i=0;i<n;i++)
				{
					cin>>x;
					s.insertnode(head2,x);
				}
				s.display(head2);
				break;
			case 4:s.merge(head1,head2);
				break;
			case 5:exit(0);
		}
	}
	return 0;
}
/***************************OUTPUT***********************************************
[student@localhost ~]$ g++ merge.cpp
[student@localhost ~]$ ./a.out

MENU
1.CREATE TWO HEAD NODES
2.INSERT NODES IN FIRT LINKED LIST
3.INSERT NODES IN SECOND LINKED LIST
4.MERGE BOTH LINKED LISTS
5.EXIT
Enter youur choice:- 1

MENU
1.CREATE TWO HEAD NODES
2.INSERT NODES IN FIRT LINKED LIST
3.INSERT NODES IN SECOND LINKED LIST
4.MERGE BOTH LINKED LISTS
5.EXIT
Enter youur choice:- 2

 Enter a how many nodes you want:- 4

Enter data in nodes for 1st linklist:- 1 3 5 7
1	3	5	7	
MENU
1.CREATE TWO HEAD NODES
2.INSERT NODES IN FIRT LINKED LIST
3.INSERT NODES IN SECOND LINKED LIST
4.MERGE BOTH LINKED LISTS
5.EXIT
Enter youur choice:- 3

 Enter a how many nodes you want:- 4

Enter data in nodes for 2nd linklist:- 2 4 6 8
2	4	6	8	
MENU
1.CREATE TWO HEAD NODES
2.INSERT NODES IN FIRT LINKED LIST
3.INSERT NODES IN SECOND LINKED LIST
4.MERGE BOTH LINKED LISTS
5.EXIT
Enter youur choice:- 4
1	2	3	4	5	6	7	8	
MENU
1.CREATE TWO HEAD NODES
2.INSERT NODES IN FIRT LINKED LIST
3.INSERT NODES IN SECOND LINKED LIST
4.MERGE BOTH LINKED LISTS
5.EXIT
Enter youur choice:- 5
[student@localhost ~]$ 

*/
