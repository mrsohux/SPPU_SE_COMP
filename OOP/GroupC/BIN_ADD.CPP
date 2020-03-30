#include<iostream>
#include<stack>
using namespace std;
int main()
{
stack<int>s1,s2,s3;
int i;
int a,b,carry=0,result,sum;
char num1[5],num2[5];
cout<<"Enter First binary No.";
cin>>num1;
for(i=0;num1[i]!='\0';i++)
{
  if (num1[i]=='0')
	  s1.push(0);
  else
	  s1.push(1);
}
cout<<"Enter Second binary No.";
cin>>num2;
for(i=0;num2[i]!='\0';i++)
{
  if (num2[i]=='0')
	  s2.push(0);
  else
	  s2.push(1);
}

//int a,b,carry=0,result,sum;
while(!s1.empty()||!s2.empty())
{

a=0;
b=0;

 if(!s1.empty())
 {
  a=s1.top();
  s1.pop();
 }
 if(!s2.empty())
 {
  b=s2.top();
  s2.pop();
 }

 sum=carry+a+b;
 result=sum%2;
  
 
 s3.push(result);
 carry=sum/2;
} //end of while;

if(carry==1)
  s3.push(carry);

while(!s3.empty())
{
  cout<<""<<s3.top();
  s3.pop();
}
cout<<"\n";
return 0;
}
