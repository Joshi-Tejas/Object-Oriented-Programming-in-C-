#include<iostream>
#include<list>
using namespace std;

class stack
{
	list<int> l1;
	public:
	void push(int num)
	{
		l1.push_front(num);
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
	
	int pop()
	{
		int n;
		n=l1.back();
		l1.pop_front();
		return n;
	}	
};

class queue
{
	list<int> l2;
	public:
	void push(int num)
	{
		l2.push_back(num);
	}
	
	void display()
	{
		list<int>::iterator p;
		for(p=l2.begin();p!=l2.end();p++)
		{
			cout<<*p<<" ";
		}
	}
	
	int isempty()
	{
		return l2.empty();
	}	
	
	int del()
	{
		int n;
		n=l2.front();
		l2.pop_front();
		return n;
	}
};	
int main()
{
	int i,n,num,choice1,choice,k;
	stack s1;
	queue q1;
	do
	{
		cout<<"Enter your choice\n1. Stack\n2. queue\n3. Exit\n";
		cin>>choice1;
		switch(choice1)
		{
			case 1:do 
				{
					cout<<"Enter your choice\n1. Add element\n2. Display\n3. Pop element\n4. Exit\n";
					cin>>choice;
					switch (choice)
					{
					case 1: 
						cout<<"Enter element : ";
						cin>>num;
						s1.push(num);
					break;	
					case 2:	cout<<"Entered stack is : ";
						k=s1.isempty();
						if(k==1)
							cout<<"The stack is empty\n";
						else	
						{
							s1.display();
							cout<<endl;
						}	
					break;
					case 3: cout<<"Popped element is : ";
						k=s1.isempty();
						if(k==1)
							cout<<"The stack is empty\n";
						else
						{	
							k=s1.pop();
							cout<<k<<endl;
						}	
					break;
					}
				}while(choice!=4);
			break;	
			case 2:do 
				{
					cout<<"Enter your choice\n1. Add element\n2. Display\n3. Remove element\n4. Exit\n";
					cin>>choice;
					switch (choice)
					{
					case 1: 
						cout<<"Enter element : ";
						cin>>num;
						q1.push(num);
					break;	
					case 2:	cout<<"Entered queue is : ";
						k=q1.isempty();
						if(k==1)
							cout<<"The queue is empty\n";
						else	
						{
							q1.display();
							cout<<endl;
						}	
					break;
					case 3: cout<<"Removed element is : ";
						k=q1.isempty();
						if(k==1)
							cout<<"The queue is empty\n";
						else
						{	
							k=q1.del();
							cout<<k<<endl;
						}	
					break;
					}
				}while(choice!=4);
			break;
		}
	}while(choice1!=3);
	return 0;
}		
