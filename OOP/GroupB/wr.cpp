
/*
Assignment No: 10 Group:B
Write a c++ program that creates an output file, writes information to it, closes the file and open it again as an input file and read the information to it.
*/


#include<fstream>
#include<iostream>
#include<stdlib.h>
using namespace  std;
void write();
void read();


         ofstream outfile;
	 ifstream infile;

int main()
{
int ch;
         
while(1)
{
cout<<"\n1. Write\n";
cout<<"\n2. Read \n";
cout<<"\n3. Exit\n";
cout<<"\n Enter your Choice\n";
cin>>ch;
	switch(ch)
	{
	case 1: write();
	break;
	case 2: read();
	break;
	case 3: exit(0);
	}

}
return 0;
}


void write()
{
string str;
char  data[100];
// open a file in write mode.
	   outfile.open("a.txt",ios::app);
	   cout<<"Writing to the file"<<endl;
	  cout<<"Enter your Name: ";
	  cin>>data;
          outfile<<data<<endl;
	  cin.ignore();		

          cout<<"Enter your Age: ";
	  cin>>data;
          outfile<<data<<endl;
		
cout<<"\n";
cin.ignore();	
 // close the opened file.
   outfile.close();
}

void read()
{
char  data[100];
// open a file
   string line;
  
   infile.open("a.txt",ios::in);
   cout<<"Reading from the file"<< endl;
   
//display the file data on screen using getline function
	while (getline (infile,line) )
    {
      cout << line << '\n';
    }

// close the opened file.*/
   infile.close();
}

