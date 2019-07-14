#include<iostream>
#include<list>
using namespace std;

class dequeue
{
	list<int> l1;
	public:
	void push_front(int num)
	{
		l1.push_front(num);
	}
	
	void push_back(int num)
	{
		l1.push_back(num);
	}
	
	void display()
	{
		list<int>::iterator p;
		for(p=l1.begin();p!=l1.end();p++)
		{
			cout<<*p<<" ";
		}
	}
	
	int isempty()
	{
		return l1.empty();
	}	
	
	int del_front()
	{
		int n;
		n=l1.front();
		l1.pop_front();
		return n;
	}
	
	int del_back()
	{
		int n;
		n=l1.back();
		l1.pop_back();
		return n;
	}	
};
	
int main()
{
	int i,n,num,choice,k;
	dequeue d1;
	do 
	{
		cout<<"Enter your choice\n1. Add at front\n2. Add at back\n3. Display\n4. Remove from front\n5. Remove from back\n6. Exit\n";
		cin>>choice;
		switch (choice)
		{
		case 1: 
			cout<<"Enter element : ";
			cin>>num;
			d1.push_front(num);
		break;
		case 2: 
			cout<<"Enter element : ";
			cin>>num;
			d1.push_back(num);
		break;	
		case 3:	cout<<"Entered stack is : ";
			k=d1.isempty();
			if(k==1)
				cout<<"The stack is empty\n";
			else	
			{
				d1.display();
				cout<<endl;
			}	
		break;
		case 4: cout<<"Removed element is : ";
			k=d1.isempty();
			if(k==1)
				cout<<"The stack is empty\n";
			else
			{	
				k=d1.del_front();
				cout<<k<<endl;
			}	
		break;
		case 5: cout<<"Removed element is : ";
			k=d1.isempty();
			if(k==1)
				cout<<"The stack is empty\n";
			else
			{	
				k=d1.del_back();
				cout<<k<<endl;
			}	
		break;
		}
	}while(choice!=6);
	return 0;
}		
