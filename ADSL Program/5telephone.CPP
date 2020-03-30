#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct record
{
	unsigned long int No;
	char name[10], add[10];
};
class Tel_Dir
{
public:
	record *Dir[10];
	void insert(record *r);
	void search();
	void remove();
	void display();
};
void Tel_Dir :: insert(record *r)
{
        int h, Hash;          
	r = new record;
	cout<<"\n Enter Tel No. 	Name 		Address \n";
	//cin>>r->No>>r->name>>r->add;
	cin>>r->No;
	h = r->No%10;           //Hash key
	if(Dir[h] == NULL)
        	Dir[r->No%10] = r;
        else    //Linear probing
        {
                Hash = h;
                h = h + 1;
                if(h == 10)
                        h = 0;
                while(Dir[h]!=NULL && h != Hash)
                {
                        h++;
                        if(h == 10)
                                h = 0;
                }
                Dir[h] = r;              
               
        }
}
void Tel_Dir :: search()
{
        int h, tel, Hash;
        cout<<"\n Enter the tel No. to be search ";
        cin>>tel;
        h = tel%10;           //Hash key
        if(Dir[h] == NULL)
                cout<<"\n Tel No. not found";
        else if(Dir[h]->No == tel)
        {
                cout<<"\nTel No. found with details as \n";
                //cout<<"\n"<<Dir[i]->No<<" "<<Dir[i]->name<<" "<<Dir[i]->add;
                cout<<"Index="<<h<<"\t\tTel No="<<Dir[h]->No<<endl;
        }
        else            //linear probing
        {
                Hash = h;
                h = h + 1;
                if(h == 10)
                        h = 0;
                while(Dir[h] != NULL)
                {
                        if(Dir[h]->No == tel)
                        {
                                cout<<"\nTel No. found with details as \n";
                                //cout<<"\n"<<Dir[i]->No<<" "<<Dir[i]->name<<" "<<Dir[i]->add;
                                cout<<"Index="<<h<<"\t\tTel No="<<Dir[h]->No<<endl;
                                break;
                        }
                        h++;
                }
                if(Dir[h] == NULL)
                        cout<<"\n Tel No. not found";
        }
}
void Tel_Dir :: remove()
{
        int h, tel, Hash;
        cout<<"\n Enter the tel No. to be delete ";
        cin>>tel;
        h = tel%10;           //Hash key
        if(Dir[h] == NULL)
                cout<<"\n Tel No. not found";
        else if(Dir[h]->No == tel)
        {
                cout<<"\nfollowing Tel No. deleted sucessfully\n";
                //cout<<"\n"<<Dir[i]->No<<" "<<Dir[i]->name<<" "<<Dir[i]->add;
                cout<<"Index="<<h<<"\t\tTel No="<<Dir[h]->No<<endl;
                delete Dir[h];
                Dir[h] = NULL;
        }
        else            //linear probing
        {
               Hash = h;
                h = h + 1;
                if(h == 10)
                        h = 0;
                while(Dir[h] != NULL)
                {
                        if(Dir[h]->No == tel)
                        {
                                cout<<"\nTel No. found with details as \n";
                                //cout<<"\n"<<Dir[i]->No<<" "<<Dir[i]->name<<" "<<Dir[i]->add;
                                cout<<"Index="<<h<<"\t\tTel No="<<Dir[h]->No<<endl;
                                delete Dir[h];
                                Dir[h] = NULL;
                                break;
                        }
                        h++;
                }
                if(Dir[h] == NULL)
                        cout<<"\n Tel No. not found";
        }
}
void Tel_Dir :: display()
{
	int i;
	for(i=0; i<10; i++)
	{
	        if(Dir[i] != NULL)
		//cout<<"\n"<<Dir[i]->No<<" "<<Dir[i]->name<<" "<<Dir[i]->add;
		cout<<"Index="<<i<<"\t\tTel No="<<Dir[i]->No<<endl;
	}
}
int main()
{
	record *r;
	Tel_Dir t;
	int ch,i;
	//initialize the directory
	for(i=0; i<10; i++)
		t.Dir[i] = NULL;
	do{
		cout<<"\n1. Insert Record"
		<<"\n2. Search Record"
		<<"\n3. Remove Record"
		<<"\n4. Display Record"
		<<"\n5. Exit";
		cout<<"\nEnter your choice :";
		cin>>ch;
		switch(ch)
		{
			case 1: t.insert(r);
				break;
			case 2: t.search();
				break;
			case 3: t.remove();
				break;
			case 4: t.display();
				break;
			default: exit(0);
				break;
		}
	}while(ch != 5);
	return 0;
}
