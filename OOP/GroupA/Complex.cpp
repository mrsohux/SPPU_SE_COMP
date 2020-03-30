//ASSIGNMENT NO. 2 "Complex no. using  Operator Overloading"
#include<iostream>
#include<stdlib.h>
using namespace std;

class Complex
{

	float real,imag;
	public:
	Complex()
	{
		real=0.0;
		imag=0.0;
	}
	friend istream &operator >>(istream &input,Complex &obj)
	{
		cout<<"Enter Real no. ";
		input>>obj.real;
		cout<<"Enter Imag no. ";
		input>>obj.imag;	
	        return input;
	}
	friend ostream &operator <<(ostream &output,Complex &obj)
	{
		if(obj.imag>=0)
		output<<obj.real<<"+"<<obj.imag<<"i";
		else if(obj.imag<0)
		output<<obj.real<<obj.imag<<"i";
		cout<<endl;
		return output;
	}
	Complex operator +(Complex object1)
	{
		Complex object3;	
		object3.real=real+object1.real;
		object3.imag=imag+object1.imag;
		return object3;	
	}

	Complex operator -(Complex object1)
	{
		Complex object3;	
		object3.real=real-object1.real;
		object3.imag=imag-object1.imag;
		return object3;	
	}
	Complex operator *(Complex object1)
	{
		Complex object3;	
		object3.real=real*object1.real-imag*object1.imag;
		object3.imag=imag*object1.real+real*object1.imag;
		return object3;	
	}
	Complex operator /(Complex object1)
	{
		Complex object3;	
		int val=object1.real*object1.real+object1.imag*object1.imag;
		object3.real=(real*object1.real+imag*object1.imag)/val;
		object3.imag=(imag*object1.real-real*object1.imag)/val;
		return object3;	
	}

};

int main()
{
	Complex obj1,obj2,obj3;
	cout<<"Enter Values for 1st Complex no."<<endl;
	cin>>obj1;
	cout<<endl;
	cout<<"Enter Values for 2nd Complex no."<<endl;
	cin>>obj2;
	cout<<endl;
	int n;
	do
	{	cout<<"Menu....."<<endl<<"1. Addition"<<endl<<"2. Subtraction"<<endl<<"3. Multiplication"<<endl<<"4. Division"<<endl<<"5.    			Exit"<<endl;	
		cout<<"Enter Choice : ";
		cin>>n;
		switch(n)
		{
			case 1:
				obj3=obj1+obj2;	
				cout<<"Addition of Complex no. is "<<obj3;
			break;
			case 2:
				obj3=obj1-obj2;
				cout<<"Subtraction of Complex no. is "<<obj3;
			break;
			case 3:
				obj3=obj1*obj2;
				cout<<"Multiplication of Complex no. is "<<obj3;
			break;
			case 4:
				obj3=obj1/obj2;
				cout<<"Division of Complex no. is "<<obj3;
			break;
			case 5:
				exit(0);
			break;	
		}	
	}while(n<=5);
return 0;
}
/*
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Test Case 1:

Enter Values for 1st Complex no.
Enter Real no. 3
Enter Imag no. -2

Enter Values for 2nd Complex no.
Enter Real no. 6
Enter Imag no. -9

Addition of Complex no. is 9-11i

Subtraction of Complex no. is -3+7i

Multiplication of Complex no. is 0-39i

Division of Complex no. is 0.307692+0.128205i
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Test Case 2:

Enter Values for 1st Complex no.
Enter Real no. 7
Enter Imag no. -8

Enter Values for 2nd Complex no.
Enter Real no. 5
Enter Imag no. -2
Addition of Complex no. is 12-10i

Subtraction of Complex no. is 2-6i

Multiplication of Complex no. is 19-54i

Division of Complex no. is 1.75862-0.896552i

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
