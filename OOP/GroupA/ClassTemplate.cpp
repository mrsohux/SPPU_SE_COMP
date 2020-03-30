#include<iostream>
#include<stdlib.h>
using namespace std;
template<class T>
class vector
{
	T v[10];
	int size;
	T new_val;
public:
	void create();
	void display();
	void modify();
	void multiply();
};

template<class T>
void vector < T > :: create()
{
	int i;
	cout<<"Enter size to store vector data: ";
	cin>>size;
	cout<<"Enter element up to "<<size<<" : ";
	for(i=0;i<size;i++)
	{
	cin>>v[i];
	}
}

template<class T>
void vector < T > :: display()
{
	int i;
	cout<<"\nThe element of Vector is : ";
	cout<<"(";
	for(i=0;i<size-1;i++)
	{
	cout<<v[i]<<" , ";
	}
	cout<<v[i];
	cout<<")";
}

template<class T>
void vector < T > :: modify()
{
	int key;
	cout<<"Enter Index: ";
	cin>>key;
	cout<<"Enter New Value: ";
	cin>>new_val;
	v[key]=new_val;
}

template<class T>
void vector < T > :: multiply()
{
	int scalar_val,i;
	cout<<"Enter the scalar value: ";
	cin>>scalar_val;
	for(i=0;i<size;i++)
	{
	v[i]*=scalar_val;
	}
}


int main()
{
	int ch,ch1,ch3;
	vector<int> v;
	vector<float> v1;
		do
		{
		cout<<"\n1.Integer \n2.Double \n3.Exit";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
			{
			case 1:
			do
				{
				cout<<"\n1.Accept \n2.Display \n3.Modify \n4.Multiplication \n5.Exit";
				cout<<"\nEnter your choice: ";
				cin>>ch1;
			switch(ch1)
				{
				case 1:
				v.create();
				break;
				case 2:
				v.display();
				break;
				case 3:
				v.modify();
				break;
				case 4:
				v.multiply();
				break;
				case 5:
				break;
				}
			}while(ch1!=5);
			break;
			case 2:
			do
				{
				cout<<"\n1.Accept \n2.Display \n3.Modify \n4.Multiplication \n5.Exit";
				cout<<"\nEnter your choice: ";
				cin>>ch3;
			switch(ch3)
				{
				case 1:
				v1.create();
				break;
				case 2:
				v1.display();
				break;
				case 3:
				v1.modify();
				break;
				case 4:
				v1.multiply();
				break;
				case 5: 
				break;
				}
			}while(ch3!=5);
			break;
			case 3: exit(0);
			break;
			}
			}while(ch!=3);
			return 0;
}

