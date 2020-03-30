
Implement C++ program for expression conversion as infix to postfix and its evaluation
using stack based on given conditions
i. Operands and operator, both must be single character.
ii. Input Postfix expression must be in a desired format.
iii. Only '+', '-', '*' and '/ ' operators are expected.
*/

#include<iostream>
#include<string.h>
#define MAX 50
using namespace std;
class stack
{
	char data[MAX];
	int top;
	public:
	stack()
	{
		top=-1;
	}
	void push(char x)
	{
		data[++top]=x;
	}
	char pop()
	{
		if(!empty())
		return data[top--];
	}
	int getTop()
	{
		if(!empty())
		return data[top];
	}
	int empty()
	{
		if(top==-1)
		return 1;
		else
		return 0;	
	}
	int full()
	{
		if(top==MAX-1)
		return 1;
		else
		return 0;
	}
};
int precedence(char ch)
{
	if(ch=='+'||ch=='-')
		return 1;
	else if(ch=='*'||ch=='/')
		return 2;
}
void infixtopostfix(stack s)
{
	char infix[30],postfix[10],ch,temp;
	cout<<"\nEnter the infix expression:";
	cin>>infix;
	cout<<"\nThe postfix expression is:";
	int i=0;
	while(infix[i]!='\0')
	{
		ch=infix[i];
		if(ch=='(')
			s.push(ch);
		else if(ch==')')
		{
			temp=s.pop();
			while(temp!='(')
			{
				cout<<temp;
				temp=s.pop();
			}
		}
		else if(isalpha(ch))
			cout<<ch;
		else
		{
			if(s.empty())
				s.push(ch);
			else
			{
				if(s.getTop()=='(')
				{
					s.push(ch);
				}
				else if(precedence(ch)>precedence(s.getTop()))
				{
					s.push(ch);
				}
				else
				{
					while(precedence(ch)<=precedence(s.getTop()))
					{
						cout<<s.pop();
					}
					s.push(ch);
				}
			}
		}
		i++;
	}
	while(!s.empty())
	{
		ch=s.pop();
		cout<<ch;
	}
	cout<<"\n";
}
int main()
{
	stack s;
	infixtopostfix(s);
	return 0;
}
/*****************************OUTPUT*******************************************8
[student@localhost ~]$ g++ infixtopost.cpp
[student@localhost ~]$ ./a.out

Enter the infix expression:(A+B)*D+E/(F+A*D)+C

The postfix expression is:AB+D*EFAD*+/+C+
[student@localhost ~]$ 
*/


