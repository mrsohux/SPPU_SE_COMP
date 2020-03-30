
A palindrome is a string of character that‘s the same forward and backward. Typically,
punctuation, capitalization, and spaces are ignored. For example, ‖Poor Dan is in a droop‖ is
a palindrome, as can be seen by examining the characters ―poor danisina droop‖ and
observing that they are the same forward and backward. One way to check for a
palindrome is to reverse the characters in the string and then compare with them the
original-in a palindrome, the sequence will be identical. Write C++ program with functions-
1. To check whether given string is palindrome or not that uses a stack to determine whether
a string is a palindrome.
2. to remove spaces and punctuation in string, convert all the Characters to lowercase, and
then call above Palindrome checking function to check for a palindrome
3. to print string in reverse order using stack
*/
#include<iostream>
using namespace std;
#define MAX 30
class stack
{
	char data[MAX],top;
	public:
	stack()
	{
		top=-1;
	}
	int full()
	{
		if(top==MAX-1)
			return 1;
		else
			return 0;
	}
	int empty()
	{
		if(top==-1)
			return 1;
		else
			return 0;
	}
	void push(char x)
	{
		data[++top]=x;
	}
	char pop()
	{
		return data[top--];
	}
	char gettop()
	{
		return data[top];
	}
	string reverse(string str)
	{
		string s1;
		char ch;
		int i=0,j;
		while(str[i]!='\0')
		{
			push(str[i]);
			i++;
		}
		i=0;
		while(!empty())
		{
			ch=pop();
			s1+=ch;
			i++;
		}
		s1[i]='\0';
		return s1;
	}
	void palindrome(string str)
	{
		string s1;
		s1=reverse(str);
		cout<<"\nReverse string:"<<s1;
		if(s1==str)
			cout<<"\nString is palindrome";
		else
			cout<<"\nString is not a palindrome";
	}
	string remove_spaces(string str)
	{
		int i=0;
		while(str[i]!='\0')
		{
			if((str[i]==' ')||(str[i]=='?'))
			str.erase(i,1);
			i++;
		}
		i=0;
		while(str[i]!='\0')
		{
			str[i]=char(tolower(str[i]));
			i++;
		}
		str[i]='\0';
		return str;
	}
};
int main()
{
	stack s;
	string str1,str2,str3;
	int ch;
	cout<<"\nEnter a string";
	getline(cin,str1);
	cout<<"\nYou entered:";
	cout<<str1;
	do
	{
		cout<<"\n1.Reverse string using stack\n2.Check for Palindrome \n3.Remove spaces and Punctuations,convert to lower case and check for palindrome\n4.Exit";
		cout<<"\nEnter your choice";
		cin>>ch;
		switch(ch)
		{
			case 1:str2=s.reverse(str1);
				cout<<"\nReversed string is:";
				cout<<str2;
				
				break;
			case 2:s.palindrome(str1);
				break;
			case 3:str3=s.remove_spaces(str1);
				cout<<"\nString after removing spaces and converting to lower case is:"<<str3;
				s.palindrome(str3);
				break;
		}
	}while(ch<4);
	return 0;
}
/********OUTPUT**************************
[student@localhost ~]$ g++ palindrome.cpp
[student@localhost ~]$ ./a.out

Enter a stringPoor Dan is in a Droop

You entered:Poor Dan is in a Droop
1.Reverse string using stack
2.Check for Palindrome 
3.Remove spaces and Punctuations,convert to lower case and check for palindrome
4.Exit
Enter your choice1

Reversed string is:poorD a ni si naD rooP
1.Reverse string using stack
2.Check for Palindrome 
3.Remove spaces and Punctuations,convert to lower case and check for palindrome
4.Exit
Enter your choice2

Reverse string:poorD a ni si naD rooP
String is not a palindrome
1.Reverse string using stack
2.Check for Palindrome 
3.Remove spaces and Punctuations,convert to lower case and check for palindrome
4.Exit
Enter your choice3

String after removing spaces and converting to lower case is:poordanisinadroop
Reverse string:poordanisinadroop
String is palindrome
1.Reverse string using stack
2.Check for Palindrome 
3.Remove spaces and Punctuations,convert to lower case and check for palindrome
4.Exit
Enter your choice4
[student@localhost ~]$ 
*/
