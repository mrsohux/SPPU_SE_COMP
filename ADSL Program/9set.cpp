#include<iostream>
#include<vector>
#include <algorithm>    // std::set_union, std::sort
#include<stdlib.h>	

using namespace std;

int main()
{
	vector<int>l;	//STL declaration of vector
	vector<int>set1;	//for set operations
	vector<int>set2;
	vector<int> v(10); 	//set operation result
	int n, i, item, no;
	int flag = 0;
	vector<int>::iterator p;	//declaration of iterator 
	int new_val;
	char ans = 'y';
	int choice;

	while(ans == 'y')
	{
		cout<<"\n Main Menu";
		cout<<"\n 1. 	Create";
		cout<<"\n 2. 	Insert";
		cout<<"\n 3. 	Delete";
		cout<<"\n 4. 	Search";
		cout<<"\n 5. 	Get Size";
		cout<<"\n 6. 	Intersection";
		cout<<"\n 7. 	Union";
		cout<<"\n 8. 	Difference";
		cout<<"\n 9. 	Display";
		cout<<"\n 10. 	Exit";
		cout<<"\n Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
		case 1:	//Create set
			cout<<"\n Enter the number of elments in the vector :";
			cin>>no;
			for(i = 0; i<no; i++)
			{
				cout<<"\n Enter the elements in the vector : ";
				cin>>n;
				l.push_back(n);	//push element at the end
			}
			break;
		case 2: //Insert element
			cout<<"\n Enter the elements in the vector : ";
			cin>>n;
			l.push_back(n);	//push element at the end
			break;
		case 3: //Delete element
			cout<<"\n Enter the element which you want to delete";
			cin>>item;
			p = l.begin();
			flag = 0;
			while(p != l.end())
			{
				if(*p == item)
				{
					flag = 1;
					break;
				}
				p++;
			}
			if(flag == 1)
			{
				cout<<"\n The element is deleted";
				l.erase(p);
			}
			else
				cout<<"\n The element is  not found";
			break;
		case 4://Search element
			cout<<"\n Enter the element which you want to search ";
			cin>>item;
			flag = 0;
			while(p != l.end())
			{
				if(*p == item)
				{
					flag = 1;
					break;
				}
				p++;
			}
			if(flag == 1)
				cout<<"\n The element is found";
			else
				cout<<"\n The element is not found";
			break;
		case 5: //Get size of vector
			cout<<"\n The size of the vector is : "<<l.size();
			break;
		case 6: //Intersection of two sets
			//Accept element for set 1
			cout<<"\n Enter the number of elments in the Set 1 :";
			cin>>no;
			for(i = 0; i<no; i++)
			{
				cout<<"\n Enter the elements in the set 1 : ";
				cin>>n;
				set1.push_back(n);	//push element at the end
			}
			//Accept element for set 2
			cout<<"\n Enter the number of elments in the Set 2 :";
			cin>>no;
			for(i = 0; i<no; i++)
			{
				cout<<"\n Enter the elements in the set 2 : ";
				cin>>n;
				set2.push_back(n);	//push element at the end
			}
			//sort both set first
			sort (set1.begin(),set1.end());     
  			sort (set2.begin(),set2.end());  
			//perform union operation
			p=set_intersection (set1.begin(), set1.end(), set2.begin(), set2.end(), v.begin());
			v.resize(p-v.begin()); 	//resize the vector size
			cout << "The intersection has " << (v.size()) << " elements:\n";
  			for (p=v.begin(); p!=v.end(); ++p)
    				cout << " " << *p;
  			cout << "\n";
			break;
		case 7: //Unioun of two sets
			//Accept element for set 1
			cout<<"\n Enter the number of elments in the Set 1 :";
			cin>>no;
			for(i = 0; i<no; i++)
			{
				cout<<"\n Enter the elements in the set 1 : ";
				cin>>n;
				set1.push_back(n);	//push element at the end
			}
			//Accept element for set 2
			cout<<"\n Enter the number of elments in the Set 2 :";
			cin>>no;
			for(i = 0; i<no; i++)
			{
				cout<<"\n Enter the elements in the set 2 : ";
				cin>>n;
				set2.push_back(n);	//push element at the end
			}
			//sort both set first
			sort (set1.begin(),set1.end());     
  			sort (set2.begin(),set2.end());  
			//perform union operation
			p=set_union (set1.begin(), set1.end(), set2.begin(), set2.end(), v.begin());
			v.resize(p-v.begin()); 	//resize the vector size
			cout << "The union has " << (v.size()) << " elements:\n";
  			for (p=v.begin(); p!=v.end(); ++p)
    				cout << " " << *p;
  			cout << "\n";
			break;
		case 8: //Difference of two sets
			//Accept element for set 1
			cout<<"\n Enter the number of elments in the Set 1 :";
			cin>>no;
			for(i = 0; i<no; i++)
			{
				cout<<"\n Enter the elements in the set 1 : ";
				cin>>n;
				set1.push_back(n);	//push element at the end
			}
			//Accept element for set 2
			cout<<"\n Enter the number of elments in the Set 2 :";
			cin>>no;
			for(i = 0; i<no; i++)
			{
				cout<<"\n Enter the elements in the set 2 : ";
				cin>>n;
				set2.push_back(n);	//push element at the end
			}
			//sort both set first
			sort (set1.begin(),set1.end());     
  			sort (set2.begin(),set2.end());  
			//perform union operation
			p=set_difference (set1.begin(), set1.end(), set2.begin(), set2.end(), v.begin());
			v.resize(p-v.begin()); 	//resize the vector size
			cout << "The difference has " << (v.size()) << " elements:\n";
  			for (p=v.begin(); p!=v.end(); ++p)
    				cout << " " << *p;
  			cout << "\n";
			break;
		case 9: //Display vector
			p = l.begin();
			while(p != l.end())
			{
				cout<<*p<<" ";
				p++;
			}
			cout<<endl;
			break;
		case 10: //exit
			exit(0);
			break;
		}
		cout<<"\n Do u want to go Main Menu? (y/n): ";
		cin>>ans;
	}
	return 0;
}
