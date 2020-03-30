/*
Write a function to get the number of vertices in an undirected graph and its edges. You may assume that no edges in input twice.
	i. Use adjacency list representation of graph and find runtime of the function	
*/
#define MAX 20
#include<iostream>
#include<stdlib.h>

using namespace std;

struct node 	//Node structure of graph
  {
	node *next;
	int vertex;
  };

class graph 	//Graph 
{
public:
	node *G[20];  		        //heads of the linked list
	void insert(int vi,int vj);     //insert an edge (vi,vj)in adj.list
	void readgraph();
	void Vertices();
	void Edges();
	void Display();
};

void graph :: Display()
{
        int i;
        node *p;
        for(i=0; i<MAX; i++)
	{
	        if(G[i]!=NULL)
	        {
	                cout<<i<<" ";
                        p=G[i];
                	while(p!=NULL)
                        {
                                cout<<p->vertex<<" ";
                	        p=p->next;
                	}
                }
                cout<<endl;
        }   
}
void graph :: Vertices()
{
	int count, i;
	count = 0;
	cout<<"\nNo. of Vertices are : ";
	for(i=0; i<MAX; i++)
	{
		if(G[i]!=NULL)
			count++;
	}
	cout<<count;
	cout<<endl;
}

void graph :: Edges()
{      
        int count, i;
        node *p;
        p = new node;
        count = 0;
        for(i=0; i<MAX; i++)
	{
	        if(G[i]!=NULL)
	        {
                        p=G[i];
                	while(p!=NULL)
                	{
                	        count++;
                	        p=p->next;
                	}
                }
        }               
	cout<<"\nNo. of Edges are : "<<count/2;
}
void graph::readgraph()
{
	int i,vi,vj;
	char ch;
	for(i=0;i<MAX;i++)
		G[i]=NULL;
	do
	{
		cout<<"\nEnter an edge (u,v)  :";
		cin>>vi>>vj;
		insert(vi,vj);
		insert(vj,vi);
		cout<<"Do you want to continue?(y/n) : ";
		cin>>ch;
	}while(ch != 'n');
}
void graph::insert(int vi,int vj)
{
	node *p,*q;
	q=new node ; 	//acquire memory for the new node
	q->vertex=vj;
	q->next=NULL;
	
	if(G[vi]==NULL) //insert the node in the linked list for the vertex no. vi
		G[vi]=q;
	else
	{
		// go to the end of linked list
		p=G[vi];
		while(p->next!=NULL)
			p=p->next;
		p->next=q;
	}
} 
int main()
{       int op,start,n, i, count;
        node *p,*q;
	graph g1;
	cout<<"\n-----------------------------------------";
	cout<<"\n**************ASSUMPTIONS****************";
	cout<<"\n-----------------------------------------";
	cout<<"\n1. Max No. of Vertices are 20";
	cout<<"\n2. Vertex are numbered as 0, 1, 2,........,20";
	cout<<"\n3. Always keep the vertext no. '0' as start vertex";
	cout<<"\n4. Edges are entered as (V1, V2), for example, 0 1\n\n";
	do {
		cout<<"\n\n1)Create a graph" 
		<<"\n2)No. of Vertices"
		<<"\n3)No. of Edges"
		<<"\n4)Display"
		<<"\n5)Quit";
		cout<<"\nEnter Your Choice : ";
		cin >> op;
		switch(op)
		   {
			case 1:	g1.readgraph();
				break;
			case 2: 
				g1.Vertices();
				break;
			case 3: 
			        g1.Edges();
				break;
			case 4: 
			        g1.Display();
			        break;
		    }

	    }while(op != 5);
	return 0;
}

