#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct SymbTab
{
	char label[10],symbol[10];
	int addr;
	struct SymbTab *next;
};
struct SymbTab *first,*last;
class Table
{
public:
	int size;
	Table()
	{
		size=0;
	}
	void Insert();
	void Display();
	void Delete();
	int Search(char lab[]);
	void Modify();
};
void Table::Insert()
{
	int n;
	char l[10];
	cout<<"\n\tEnter the label : ";
	cin>>l;
	n=Search(l);
	if(n==1)
		cout<<"\n\tThe label exists already in the symbol table"
		<<"\n\tDuplicate can't be inserted";
	else
	{
		struct SymbTab *p;
		p=new SymbTab;
		strcpy(p->label,l);
		cout<<"\n\tEnter symbol & address: ";
		cin>>p->symbol>>p->addr;
		p->next=NULL;
		if(size==0)
		{
			first=p;
			last=p;
		}
		else
		{
			last->next=p;
			last=p;
		}
		size++;
	}
	cout<<"\n\tLabel inserted\n";
}
void Table::Display()
{
	int i;
	struct SymbTab *p;
	p=first;
	cout<<"\n\tLABEL\t\tSYMBOL\t\tADDRESS\n";
	for(i=0;i<size;i++)
	{
		cout<<"\t"<<p->label<<"\t\t"<<p->symbol<<"\t\t"<<p->addr<<endl;
		p=p->next;
	}
}
int Table::Search(char lab[])
{
	int i,flag=0;
	struct SymbTab *p;
	p=first;
	for(i=0;i<size;i++)
	{
		if(strcmp(p->label,lab)==0)
			flag=1;
		p=p->next;
	}
	return flag;
}
void Table::Modify()
{
	char l[10],nl[10];
	int add,choice,i,s;
	struct SymbTab *p;
	p=first;

	cout<<"\n\tEnter the old label : ";
	cin>>l;
	s=Search(l);
	if(s==0)
		cout<<"\n\tLabel not found\n";
	else
	{
		cout<<"\n\tEnter the new label and address: ";
		cin>>nl>>add;
		for(i=0;i<size;i++)
		{
			if(strcmp(p->label,l)==0)
			{
				strcpy(p->label,nl);
				p->addr=add;
			}
			p=p->next;
		}
		cout<<"\n\tAfter Modification:\n";
		Display();
	}

}
void Table::Delete()
{
	int a;
	char l[10];
	struct SymbTab *p,*q;
	p=first;
	cout<<"\n\tEnter the label to be deleted : ";
	cin>>l;
	a=Search(l);
	if(a==0)
		cout<<"\n\tLabel not found\n";
	else
	{
		if(strcmp(first->label,l)==0)
			first=first->next;
		else if(strcmp(last->label,l)==0)
		{
			q=p->next;
			while(strcmp(q->label,l)!=0)
			{
				p=p->next;
				q=q->next;
			}
			p->next=NULL;
			last=p;
		}
		else
		{
			q=p->next;
			while(strcmp(q->label,l)!=0)
			{
				p=p->next;
				q=q->next;
			}
			p->next=q->next;
		}
		size--;
		cout<<"\n\tAfter Deletion:\n";
		Display();
	}
}
int main()
{
	Table t;
	int op,y;
	char la[10];
	do
	{
		cout<<"\n\tSYMBOL TABLE IMPLEMENTATION\n";
		cout<<"\n\t1.INSERT"
		<<"\n\t2.DISPLAY"
		<<"\n\t3.DELETE"
		<<"\n\t4.SEARCH"
		<<"\n\t5.MODIFY"
		<<"\n\t6.END\n";
		cout<<"\n\tEnter your option : ";
		cin>>op;
		switch(op)
		{
			case 1:
				t.Insert();
				break;
			case 2:
				t.Display();
				break;
			case 3:
				t.Delete();
				break;
			case 4:
				cout<<"\n\tEnter the label to be searched : ";
				cin>>la;
				y=t.Search(la);
				cout<<"\n\tSearch Result:";
				if(y==1)
					cout<<"\n\tThe label is present in the symbol table\n";
				else
					cout<<"\n\tThe label is not present in the symbol table\n";
				break;
			case 5:
				t.Modify();
				break;
			case 6:
				exit(0);
		}
	}while(op<6);
	return 0;
}
