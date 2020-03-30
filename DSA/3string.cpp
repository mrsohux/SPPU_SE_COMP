/*Write C++ program for string operations- copy, concatenate, check substring, equal, reverse
and length
*/

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class Stringop
{
	char str[30];
	public:
	Stringop accept(Stringop);
	int Strlength(Stringop);
	void Strcopy(Stringop);
	void Strcompare(Stringop, Stringop);
	void Strconcate(Stringop, Stringop);
	void Strreverse(Stringop);
	void StrSubstring(Stringop);

};

Stringop Stringop :: accept(Stringop s1)
{
	cout<<"\nEnter the string := ";
  	cin>>s1.str;
 	return(s1);
}

int Stringop :: Strlength(Stringop s1)
{
	int i;
  	i=0;
	while(s1.str[i]!='\0')
	{
		i++;
	}
  	return(i);
}
  
void Stringop :: Strcopy(Stringop s1)
{
	Stringop s2;
  	int i;

 	for(i=0;s1.str[i]!='\0';i++)
		s2.str[i]=s1.str[i];
 	s2.str[i]='\0';
 	cout<<"\nCopied string is := "<<s2.str;
}

void Stringop ::Strcompare(Stringop s1, Stringop s2)
{
	int k,len=0;
  	int i= Strlength(s1);
  	int j= Strlength(s2);
  	if(i==j)
  	{
		for(k=0;k<i;k++)
		{
			if(s1.str[k]==s2.str[k])
			len++;
		}
		if(len==i)
			cout<<"\nBoth strings are equal.";
		else
			cout<<"\nNot equal.";
  	}
  	else
 		cout<<"\nNot equal.";
}

void Stringop ::Strreverse(Stringop s1)
{
	Stringop s2;
  	int i,j,k;
  	i= Strlength(s1);
  	i--;
  	for(j=0,k=i;s1.str[j]!='\0';j++,k--)
		s2.str[j] = s1.str[k];
  	s2.str[j]='\0';
  	cout<<"\nReverse of string := "<<s2.str;
}

void Stringop ::Strconcate(Stringop s1, Stringop s2)
{
	int i,j,k;	
  	i= Strlength(s1);
  	for(j=0;s2.str[j]!='\0';j++)
  	{
		s1.str[i]=s2.str[j];
		i++;
  	}
  	s2.str[j]='\0';
  	cout<<"\nString after concatenate is := "<<s1.str;
}

void Stringop ::StrSubstring(Stringop s1)
{
	char sub;
	Stringop s2;
	int i,j,k,flag=0;

	cout<<"\nEnter character :";
	cin>>sub;

	for(i=0;s1.str[i]!='\0';i++)
	{
		if(s1.str[i]==sub)
		{
                	flag=1;
			break;
		}
		else
		      	flag=0;
	}
        if(flag==0)
	{
           cout<<"\nGiven Character is not Sub string of original string";
	}
        else
	{
		for(j=i,k=0;s1.str[j]!='\0';j++,k++)
			s2.str[k]=s1.str[j];
		s2.str[k]='\0';
		cout<<"\nSub string is := "<<s2.str;
	}
}

int main()
{
	int ch,len;
	Stringop str1,str2,obj;
	
	while(1)
	{
		cout<<"\n----------Menu of Program.----------\n1. String length\n2. String copy\n3. String compare\n4. String reverse\n5. String concatenate\n6. Substring\n7. Exit";

		cout<<"\nEnter ur choice :";
		cin>>ch;

		switch(ch)
		{
		case 1:
			str1=obj.accept(str1);
			len=obj.Strlength(str1);
			cout<<"\nLength of string is :="<< len;
			break;
		case 2:
			str1=obj.accept(str1);
			obj.Strcopy(str1);
			break;
		case 3:
			str1=obj.accept(str1);
			str2=obj.accept(str2);
			obj.Strcompare(str1,str2);
			break;
		case 4:
			str1=obj.accept(str1);
			obj.Strreverse(str1);
			break;
		case 5:
			str1=obj.accept(str1);
			str2=obj.accept(str2);
			obj.Strconcate(str1,str2);
			break;
		case 6:
			str1=obj.accept(str1);
			obj.StrSubstring(str1);
			break;
		case 7:
			exit(0);
		}
	}
}


/******************* OUTPUT *********************************************
[student@localhost ~]$ g++ string.cpp
[student@localhost ~]$ ./a.out

----------Menu of Program.----------
1. String length
2. String copy
3. String compare
4. String reverse
5. String concatenate
6. Substring
7. Exit
Enter ur choice :1

Enter the string := lohgaon

Length of string is :=7
----------Menu of Program.----------
1. String length
2. String copy
3. String compare
4. String reverse
5. String concatenate
6. Substring
7. Exit
Enter ur choice :2

Enter the string := mmit

Copied string is := mmit
----------Menu of Program.----------
1. String length
2. String copy
3. String compare
4. String reverse
5. String concatenate
6. Substring
7. Exit
Enter ur choice :3

Enter the string := lohgaon

Enter the string := lohgaon

Both strings are equal.
----------Menu of Program.----------
1. String length
2. String copy
3. String compare
4. String reverse
5. String concatenate
6. Substring
7. Exit
Enter ur choice :4

Enter the string := mmit

Reverse of string := timm
----------Menu of Program.----------
1. String length
2. String copy
3. String compare
4. String reverse
5. String concatenate
6. Substring
7. Exit
Enter ur choice :5

Enter the string := mmit

Enter the string := lohgaon

String after concatenate is := mmitlohgaon
----------Menu of Program.----------
1. String length
2. String copy
3. String compare
4. String reverse
5. String concatenate
6. Substring
7. Exit
Enter ur choice :6

Enter the string := lohgaon

Enter character :h

Sub string is := hgaon
----------Menu of Program.----------
1. String length
2. String copy
3. String compare
4. String reverse
5. String concatenate
6. Substring
7. Exit
Enter ur choice :7
[student@localhost ~]$ 
*/
