/* 
Problem Statement- 
Write C++ program to store roll numbers of student in array who attended training program
in random order. Write function for-
a) Searching whether particular student attended training program or not using linear search
and sentinel search. b) Searching whether particular student attended training program or
not using binary search and Fibonacci search.
*/

#include<iostream>
#include<stdlib.h>
using namespace std;
#define M 20
class search
{
	 int array[M];
 	 int size;
public:

 int getdata();
 void display();
 void sort();
 int linear(int);
 int binary(int);
 int fib(int n);
 void fibonaccy(int key,int f, int b, int a);
 int sentinel(int); 
 
}; 
int search :: getdata()
{ 
	cout<<"\n Enter how many students are there?:= ";
  	cin>>size;
  	cout<<"\n Enter the Roll no of each student attending the training program= \n";
   	for(int i=0;i<size;i++)
    		cin>>array[i];
   return size;
}
void search:: display()
{ 
  cout<<"\n The Roll numbers of the students are:.....\n";
  for(int i=0;i<size;i++)
    cout<<"  "<<array[i];
}
void search::sort()
{
  int i,j,temp; 
  for(i=0;i<size;i++)
  {
	for(j=0;j<size-i-1;j++)
	{
	 	if(array[j]>array[j+1])
		{
			temp=array[j];
			array[j]=array[j+1];
			array[j+1]=temp;
		}
	}
  }
}


int search::linear(int value)
{ 
  int i;
  
  for(i=0;i<size;i++)
  {
	if(value==array[i])
    	{ 
      		return(i+1);		
      	}
   }
return -1;
}

int search::sentinel(int value)
{ 
  int i;
  array[size]=value;
  i=0;
  while(array[i]!=value)
  {
	i++;
  }
  if(i!=size)
	return i+1;
  
   
return -1;
}
int search::binary(int value)
{ 
  int mid,lower=0,upper=size-1;
  
  
  while(lower<=upper)
  { 
	mid=(lower+upper)/2;

	if(value==array[mid])
	{ 
      		return (mid+1); 
    	}
   	else if(value>array[mid])
       		lower=mid+1;
   	else if(value<array[mid])
        	upper=mid-1;
  }  
   
return -1;
}  

int search::fib(int n)
{
 int a,b,f;
 if(n<1)
      return n;
 a=0;
 b=1;
 while(b<n)
 {
	f=a+b;
	a=b;
	b=f;
 }
 return a;

}

void search::fibonaccy(int key,int f, int b, int a)
{

 if(f<1 || f>size-1)
 	cout<<"\n Student Roll Number is Not found...";
 else if(key< array[f-1])
 {
	if(a<=0)
		cout<<"\n Student Roll Number is Not found...";
	else
		fibonaccy(key,f-a,a,b-a);
 }
 else if(key> array[f])
 {
	if(b<=1)
		cout<<"\n Student Roll Number is Not found...";
	else
		fibonaccy(key,f+a,b-a,a-b);
 }
 else
	cout<<"\n Student Roll Number is found...";
}
int main()
{ 
  search obj;
  int ch,pos,x,n;
  n=obj.getdata();
while(1) 
{  cout<<"\n ****************** Searching Techniques Main Menu ********************";
   cout<<"\n 1.Linear_Search\n 2.Sentinel_Search \n 3.Binary_Search\n 4.Fibonnacy_Search\n 5.Exit";
   cout<<"\n Enter your choice:=";
   cin>>ch;
    switch(ch)
    { 
	case 1:
		cout<<"\n Enter the student roll number to be search:= ";
  		cin>>x; 
		pos=obj.linear(x);
		if(pos>-1)
			cout<<"\n Roll Number is found at "<<pos<<" location......";
		else
			cout<<"\n Roll Number is not found.";
   	break;           
  	case 2:
		cout<<"\n Enter the student roll number to be search:= ";
  		cin>>x; 
		pos=obj.sentinel(x);
		if(pos>-1)
			cout<<"\n Roll Number is found at "<<pos<<" location......";
		else
			cout<<"\n Roll Number is not found.";
   		
   	break;
  	case 3:
		obj.sort();
		obj.display();
		cout<<"\n Enter the student roll number to be search:= ";
  		cin>>x;

   		pos=obj.binary(x);
		if(pos>-1)
			cout<<"\n Roll Number is found at "<<pos<<" location......";
		else
			cout<<"\n Roll Number is not found.";
   	break;
  	case 4:
		obj.sort();
		obj.display();
		cout<<"\n Enter the student roll number to be search:= ";
  		cin>>x;

   		obj.fibonaccy(x,n,obj.fib(n-1),obj.fib(obj.fib(n-1)));
   	break;
  	case 5:
    		exit(0);
    }
}
return 0;
}

/* *************************** OUTPUT ***************************************************************

[DSA@localhost ~]$ g++ search.cpp
[DSA@localhost ~]$ ./a.out

 Enter how many students are there?:= 5

 Enter the Roll no of each student attending the training program= 
11 88 22 44 55

 ****************** Searching Techniques Main Menu ********************
 1.Linear_Search
 2.Sentinel_Search 
 3.Binary_Search
 4.Fibonnacy_Search
 5.Exit
 Enter your choice:=1

 Enter the student roll number to be search:= 55

 Roll Number is found at 5 location......
 ****************** Searching Techniques Main Menu ********************
 1.Linear_Search
 2.Sentinel_Search 
 3.Binary_Search
 4.Fibonnacy_Search
 5.Exit
 Enter your choice:=2

 Enter the student roll number to be search:= 88

 Roll Number is found at 2 location......
 ****************** Searching Techniques Main Menu ********************
 1.Linear_Search
 2.Sentinel_Search 
 3.Binary_Search
 4.Fibonnacy_Search
 5.Exit
 Enter your choice:=3

 The Roll numbers of the students are:.....
  11  22  44  55  88
 Enter the student roll number to be search:= 44

 Roll Number is found at 3 location......
 ****************** Searching Techniques Main Menu ********************
 1.Linear_Search
 2.Sentinel_Search 
 3.Binary_Search
 4.Fibonnacy_Search
 5.Exit
 Enter your choice:=4

 The Roll numbers of the students are:.....
  11  22  44  55  88
 Enter the student roll number to be search:= 55

 Student Roll Number is found...
 ****************** Searching Techniques Main Menu ********************
 1.Linear_Search
 2.Sentinel_Search 
 3.Binary_Search
 4.Fibonnacy_Search
 5.Exit
 Enter your choice:=5
*/


