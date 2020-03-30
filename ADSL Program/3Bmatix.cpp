/*
Write a function to get the number of vertices in an undirected graph and its edges. You may assume that no edges in input twice.
	i. Use adjacency matrix representation of graph and find runtime of the function	
*/
# include <iostream>
# include <stdlib.h>
# define MAX 10
using namespace std;
class graph
{
        public:
                int G[MAX][MAX];
                void readgraph();
                void Vertices();
	        void Edges();
	        void Display();
};
void graph :: readgraph()
{
        int i, j, vi, vj;
        char ch;
	for(i=0;i<MAX;i++)
	        for(j=0;j<MAX;j++)
		        G[i][j]=0;
	do
	{
		cout<<"\nEnter an edge (u,v)  :";
		cin>>vi>>vj;
		G[vi][vj]=1;
		G[vj][vi]=1;
		cout<<"Do you want to continue?(y/n) : ";
		cin>>ch;
	}while(ch != 'n');
}
void graph :: Display()
{
	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
		{
			cout<<G[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void graph :: Edges()
{      
        int count = 0;
        for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			if(G[i][j]!=0)
			        count++;             
	cout<<"\nNo. of Edges are : "<<count/2;
}	
void graph :: Vertices()
{
	int count = 0;
        for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			if(G[i][j]!=0)
			{
			        count++;
			        break;
			}  
	cout<<"\nNo. of Vertices are : "<<count;
}
int main()
{
         int op;
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
