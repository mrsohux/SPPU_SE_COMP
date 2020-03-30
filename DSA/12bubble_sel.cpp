
Problem Statement--
Write C++ program to store first year percentage of students in array. Write function for
sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort and display top five scores.
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
 	void selection();
	void bubble();
};
void Marksheet:: getdata()
{ 
	cout<<"\n Enter how many students are there?:= ";
  	cin>>size;
  	cout<<"\n Enter the first year percentage of "<<size<<" students= \n";
   	for(int i=0;i<size;i++)
    		cin>>array[i];
}
void Marksheet::bubble()
{

	int i,j,k,m;
	float temp;
  	
	for(i=0;i<size-1;i++)
	{
		
		for(j=0;j<size-i-1;j++)
		{
			if(array[j]>array[j+1])
			{
				temp=array[j];
				array[j]= array[j+1];
				array[j+1]=temp;
			}
			
		}
		cout<<"\nAfter Pass"<<i+1<<"-->";
		for(k=0;k<size;k++)
			cout<<" "<<array[k];
		
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

void Marksheet::selection()
{

	int i,j,min,k,m;
	float temp;
  	
	for(i=0;i<size-1;i++)
	{
		min=i;
		for(j=i+1;j<size;j++)
		{
			if(array[j]<array[min])
			{
				min=j;
			}	
		}	
		if(min!=i)
		{
			temp=array[i];
			array[i]= array[min];
			array[min]=temp;
		}
		cout<<"\nIteration No= "<<i+1<<"-->";
		for(k=0;k<size;k++)
			cout<<" "<<array[k];
		
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
				s1.bubble();
   			break;           
  			case 2:
				s1.getdata();
				s1.selection();
   			break;
  	  		case 3:
    				exit(0);
    		}
	}
return 0;
}

/* ****************** OUTPUT *********************************
[student@localhost ~]$ g++ sort1.cpp
[student@localhost ~]$ ./a.out

 ****************** Sorting Techniques Main Menu ********************
 1. Bubble Sort
 2. Selection Sort 
 3. Exit
 Enter your choice:=1

 Enter how many students are there?:= 10

 Enter the first year percentage of 10 students= 
56.88
98.77
67.7
88.6
50.67
77.6
65.8
58.9
69.55
56.45

After Pass1--> 56.88 67.7 88.6 50.67 77.6 65.8 58.9 69.55 56.45 98.77
After Pass2--> 56.88 67.7 50.67 77.6 65.8 58.9 69.55 56.45 88.6 98.77
After Pass3--> 56.88 50.67 67.7 65.8 58.9 69.55 56.45 77.6 88.6 98.77
After Pass4--> 50.67 56.88 65.8 58.9 67.7 56.45 69.55 77.6 88.6 98.77
After Pass5--> 50.67 56.88 58.9 65.8 56.45 67.7 69.55 77.6 88.6 98.77
After Pass6--> 50.67 56.88 58.9 56.45 65.8 67.7 69.55 77.6 88.6 98.77
After Pass7--> 50.67 56.88 56.45 58.9 65.8 67.7 69.55 77.6 88.6 98.77
After Pass8--> 50.67 56.45 56.88 58.9 65.8 67.7 69.55 77.6 88.6 98.77
After Pass9--> 50.67 56.45 56.88 58.9 65.8 67.7 69.55 77.6 88.6 98.77
Top Five Scores are= 
 98.77 88.6 77.6 69.55 67.7
 ****************** Sorting Techniques Main Menu ********************
 1. Bubble Sort
 2. Selection Sort 
 3. Exit
 Enter your choice:=2

 Enter how many students are there?:= 8

 Enter the first year percentage of 8 students= 
55.6
67.9
66.9
77
55
46.8
68.5
79.8

After Pass1--> 46.8 67.9 66.9 77 55 55.6 68.5 79.8
After Pass2--> 46.8 55 66.9 77 67.9 55.6 68.5 79.8
After Pass3--> 46.8 55 55.6 77 67.9 66.9 68.5 79.8
After Pass4--> 46.8 55 55.6 66.9 67.9 77 68.5 79.8
After Pass5--> 46.8 55 55.6 66.9 67.9 77 68.5 79.8
After Pass6--> 46.8 55 55.6 66.9 67.9 68.5 77 79.8
After Pass7--> 46.8 55 55.6 66.9 67.9 68.5 77 79.8
Top Five Scores are= 
 79.8 77 68.5 67.9 66.9
 ****************** Sorting Techniques Main Menu ********************
 1. Bubble Sort
 2. Selection Sort 
 3. Exit
 Enter your choice:=3
[student@localhost ~]$ 
*/













