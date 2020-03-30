// Experiment No. 9 "Selection Sort Using Function Template"
#include<iostream>
#include<stdlib.h>

using namespace std;

template<class T>
void selection_sort(T a[1000],int n)
{
	int i,j,mid;
	T temp;
	for(i=0;i<n;++i)
	{
		mid=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[mid])
				mid=j;
		temp=a[mid];
		a[mid]=a[i];
		a[i]=temp;	
	}
}

int main()
{
	int a[1000];
	float b[1000];
	char c[100];
	int n,l;
	
	do
	{
		cout<<"................Menu.............."<<endl<<"1. Sort Integer Array"<<endl<<"2. Sort Float Array"
			<<endl<<"3. exit"<<endl<<"Enter Choice : ";
	
		cin>>l;
		switch(l)
		{
			case 1:
				cout<<"Enter how many elements you want to insert"<<endl;
				cin>>n;				
				cout<<"Insert Elements"<<endl;
				for(int i=0;i<n;++i)
					cin>>a[i];
				cout<<"Elements before Sorting"<<endl;
				for(int i=0;i<n;++i)
					cout<<a[i]<<" ";
				cout<<endl;
				selection_sort(a,n);
				cout<<"Elements after Sorting"<<endl;
				for(int i=0;i<n;++i)
					cout<<a[i]<<" ";
				cout<<endl;
				break;
			case 2:
				cout<<"Enter how many elements you want to insert"<<endl;
				cin>>n;				
				cout<<"Insert Elements"<<endl;
				for(int i=0;i<n;++i)
					cin>>b[i];
				cout<<"Elements before Sorting"<<endl;
				for(int i=0;i<n;++i)
					cout<<b[i]<<" ";
				cout<<endl;
				selection_sort(b,n);
				cout<<"Elements after Sorting"<<endl;
				for(int i=0;i<n;++i)
					cout<<b[i]<<" ";
				cout<<endl;
				break;
			case 3:
				exit(0);	
				break;	
		}
			
	}while(1);
return 0;
}

/*************************************************OUTPUT***********************************************************************************/
/*
................Menu..............
1. Sort Integer Array
2. Sort Float Array
3. exit
Enter Choice : 1
Enter how many elements you want to insert
10
Insert Elements
9
7
5
3
1
8
2
15
23
18
Elements before Sorting
9 7 5 3 1 8 2 15 23 18 
Elements after Sorting
1 2 3 5 7 8 9 15 18 23 
................Menu..............
1. Sort Integer Array
2. Sort Float Array
3. exit
Enter Choice : 2
Enter how many elements you want to insert
10
Insert Elements
1.0
2.5
0.9
0.99
1.8
5.9
6.3
2.5
1.2
0.45
Elements before Sorting
1 2.5 0.9 0.99 1.8 5.9 6.3 2.5 1.2 0.45 
Elements after Sorting
0.45 0.9 0.99 1 1.2 1.8 2.5 2.5 5.9 6.3 
................Menu..............
1. Sort Integer Array
2. Sort Float Array
3. exit
Enter Choice : 3
*/
