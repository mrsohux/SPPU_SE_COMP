/*
Write C++ program to store second year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using
a) Insertion sort 
b) Shell Sort and display top five scores.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
#define M 60
class Marksheet
{
	float array[M];
	int size;
	public:
	void getdata();
 	void insertion();
	void shell();
};
void Marksheet:: getdata()
{ 
	cout<<"\n Enter how many students are there?:= ";
  	cin>>size;
  	cout<<"\n Enter the first year percentage of "<<size<<" students= \n";
   	for(int i=0;i<size;i++)
    		cin>>array[i];
}
void Marksheet::insertion()
{

	int i,j,key,k,m;
	for(i=1;i<n;i++)
	{
		key=a[i];
		for(j=i-1;j>=0&&a[j]>key;j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=key;
		cout<<"\nAfter pass "<<i<<" :- ";
		for(d=0;d<n;d++)
			cout<<a[d]<<" ";
	}

	cout<<"\nTop Five Scores are= \n";
	for(k=size-1,m=1;k>=0;k--,m++)
	{
		if(m<=5)
		{
			cout<<" "<<array[k];
		}
	}
}

void Marksheet::shell()
{

	int i,j,min,k,m;
	float temp;
  	
	int temp,gap,i;
	int swapped;
	gap=n/2;
	do
	{
		do
		{
			swapped=0;
			for(i=0;i<n-gap;i++)
			{
				if(a[i]>a[i+gap])
				{
					temp=a[i];
					a[i]=a[i+gap];
					a[i+gap]=temp;
					swapped=1;
				}
				
			}
			
		}while(swapped==1);
		cout<<"\nAfter pass :- ";
				for(i=0;i<n;i++)
				cout<<a[i]<<" ";
	}while((gap=gap/2)>=1);

	cout<<"\nTop Five Scores are= \n";
	for(k=size-1,m=1;k>=0;k--,m++)
	{
		if(m<=5)
		{
			cout<<" "<<array[k];
		}
	}
}

int main()
{ 
  	Marksheet s1;
  	int ch;
  	
	while(1) 
	{  
		cout<<"\n ****************** Sorting Techniques Main Menu ********************";
		cout<<"\n 1. Bubble Sort\n 2. Selection Sort \n 3. Exit";
   		cout<<"\n Enter your choice:=";
   		cin>>ch;
    		switch(ch)
    		{ 
			case 1:
				s1.getdata();
				s1.insertion();
   			break;           
  			case 2:
				s1.getdata();
				s1.shell();
   			break;
  	  		case 3:
    				exit(0);
    		}
	}
return 0;
}













