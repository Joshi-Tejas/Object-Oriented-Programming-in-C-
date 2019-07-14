#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class student
{
	string name,date,bg,dept;
	int roll_no;
	public:
	void getdata()
	{
		cout<<"enter name, roll number, department, birthdate and bloodgroup\n";
		cin>>name>>roll_no>>dept>>date>>bg;
	}	
	void display()
	{
		cout<<"\nstudent name:"<<setw(15)<<name<<"\nstudent roll number:"<<setw(10)<<roll_no<<"\nstudent department:"<<setw(10)<<dept<<"\nstudent birth date:"<<setw(10)<<date<<"\nstudent blood group:"<<setw(10)<<bg<<endl;
	}	
	
	void ser(int y)
	{
		if(y==roll_no)
			cout<<"FOUND\n";
	}
	
	friend void del(int,int,student s[]);
		
	friend void mod(int,int,student s[]);
	
};
void del(int z,int x,student s[])
	{
		int i,store=0,flag=0;
		for(i=0;i<x;i++)
		{
			if(z==s[i].roll_no)
			{	store=i;flag=1;break;}
		}
		if(flag==0)
		{cout<<"roll number not found.\n"; exit(1);}		
		for(i=store;i<x-1;i++)
		{
			s[i]=s[i+1];
		}	
		cout<<"process successful.\n";
	}
	
void mod(int r,int x,student s[])
{
	int i,ch,flag=0;
	for(i=0;i<x;i++)
	{	
		if(r==s[i].roll_no)
		{
			flag=1;
		}
	}
	if(flag==1)
	{		
		cout<<"Choose the field you want to modify.\n1. Name\n2. Roll number\n3. Department\n4. All data\n";
		cin>>ch;
		switch (ch)
		{
			case 1: cin>>s[i].name;
			break;
			case 2: cin>>s[i].roll_no;
			break;
			case 3: cin>>s[i].dept;
			break;
			case 4: s[i].getdata();
			break;
			default:cout<<"no match\n";
			break;
		}
	}
	else
		cout<<"no match found.\n";					
}

	
int main()
{
	int n,i,ch,roll;
	cout<<"enter number of students.\n";
	cin>>n;
	student s[20];
	for(i=0;i<n;i++)
	{
		s[i].getdata();
	}
	while(1)
	{
		cout<<"Enter your choice\n1. Display\n2. Modify\n3. Search\n4. Delete\n5. Exit\n";
		cin>>ch;
		switch (ch)
		{
			case 1:{
				for(i=0;i<n;i++)
				{
					s[i].display();
				}
				}
			break;	
			case 2:{
				cout<<"Enter roll number to modify.\n";
				cin>>roll;
				mod(roll,n,s);	
				}
			break;
			case 3:{
				int i;
				cout<<"enter roll number to search.\n";
				cin>>roll;
				for(i=0;i<n;i++)
				{
					s[i].ser(roll);
				}
				}		
			break;
			case 4:{
				cout<<"enter roll number to delete.\n";
				cin>>roll;
				del(roll,n,s);
				}
			break;	
			case 5:{ exit(1); break;}
			break;
		}
	}
	return 0;		
}			
				
