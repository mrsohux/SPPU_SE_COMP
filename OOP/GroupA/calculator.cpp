//Assignment No. 2 "Calculator"
#include<iostream>
using namespace std;

class calci
{
	float n1,ans;
	public:
		void setvalue(int temp)
		{
			n1=temp;
		}

		calci operator +(calci obj3)
		{
			calci obj4;
			obj4.ans=n1+obj3.n1;
			return obj4;
		}
		
		calci operator -(calci obj3)
		{
			calci obj4;
			obj4.ans=n1-obj3.n1;
			return obj4;
		}
		
		calci operator *(calci obj3)
		{
			calci obj4;
			obj4.ans=n1*obj3.n1;
			return obj4;
		}
		
		calci operator /(calci obj3)
		{
			calci obj4;
			obj4.ans=n1/obj3.n1;
			return obj4;
		}
		void display()
		{
			cout<<"answer="<<ans<<endl;
		}
};

int main()
{
	calci obj,obj1,obj2;
	float a,b;
	char ch;
	
	do
	{
		cout<<"enter the value of a : ";
		cin>>a;
		obj.setvalue(a);
		cout<<"operator : ";
		cin>>ch;
		cout<<"enter the value of b : ";
		cin>>b;
		obj1.setvalue(b);

		switch(ch)
		{
			case '+':obj2=obj+obj1;
				break;

			case '-':obj2=obj-obj1;
				break;
		
			case '*':obj2=obj*obj1;
				break;
		
			case '/':obj2=obj/obj1;
				break;
		}
		obj2.display();
		
		cout<<"do you want to continue('y/n'):";
		cin>>ch;
	}	
	while(ch=='y'|| ch=='Y');
	return 0;
}


/***************OUTPUT********************/
/*

Test Case 1:
enter the value of a: 33

operator:/

enter the value of b: 3

answer= 11

do you want to continue('y/n'):y

enter the value of a: 40

operator: *

enter the value of b: 2

answer=80

do you want to continue('y/n'):y

enter the value of a: 4

operator: +

enter the value of b: 3

answer=7

do you want to continue('y/n'):y

enter the value of a:5

operator:-

enter the value of b:3

answer=2

do you want to continue('y/n'):y

enter the value of a: 30

operator: *

enter the value of b: 2

answer=60

do you want to continue('y/n'):n
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Test Case 2:
enter the value of a : 10

operator : +

enter the value of b : 12

answer=22

do you want to continue('y/n'):y

enter the value of a : 12

operator : -

enter the value of b : 3

answer=9

do you want to continue('y/n'):n
*/

