/*
Write a function in C++ to count and display the number of lines not starting with alphabet 'A'present in the text file "STORY.TXT".
*/



#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{

char name[21];

ofstream ofile ("abc.txt");
ofile<<"A he is very nice college\n";
ofile<<"The is very nice college\n";
ofile<<"A he roses is red\n";
ofile<<"A girl is playing there\n";
ofile<<"There is a playground\n";
ofile<<"An areoplane is in the sky\n";
ofile<<"Numbers are not allowed in the passowrd\n";
ofile.close();

string line;
  ifstream myfile ("abc.txt");
  if (myfile.is_open())
  {
    while (getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

myfile.open("abc.txt", ios::in);

char my_character;
int number_of_lines = 0;
	
int i=0;
	while (!myfile.eof() ) 
	{
		myfile.get(my_character);
		if(my_character=='A')
		i++;
	
		if(my_character == '\n')
		number_of_lines++;
	
	}
cout<<"\nNo. of Lines starting from 'A' character="<<i;
number_of_lines--;
cout << "\nTOTAL NUMBER OF LINES: " << number_of_lines << endl;
cout << "\nNo. of Lines starting from character other than 'A'=" <<number_of_lines-i << endl;
return 0;
}

