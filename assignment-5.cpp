#include<iostream>
using namespace std;

class personal
{
	protected:
	string name,city;
	int phone;
	public:	
	void display()
	{
		cout<<"Name: "<<name<<endl<<"City: "<<city<<endl<<"Phone number: "<<phone<<endl;
	}
};

class academic
{
	protected:
	string college,degree;
	int marks;
	public:	
	void display()
	{
		cout<<"College: "<<college<<endl<<"Degree: "<<degree<<endl<<"Marks: "<<marks<<endl;
	}
};		

class pro : public academic
{
	protected:
	string company,post;
	int exp;
	public:	
	void display()
	{
		cout<<"Company: "<<company<<endl<<"Post: "<<post<<endl<<"Experience: "<<exp<<endl;
	}
}; 

class bio : public personal,public academic, public pro
{
	public:
	void getdata()
	{
		cout<<"enter name, city and phone number\n";
		cin>>name>>city>>phone;
		cout<<"enter college, degree and marks\n";
		cin>>college>>degree>>marks;
		cout<<"enter company, post and experience in years\n";
		cin>>company>>post>>exp;
	}	
	void display()
	{
		cout<<"Name: "<<name<<endl<<"City: "<<city<<endl<<"Phone number: "<<phone<<endl;
		cout<<"College: "<<college<<endl<<"Degree: "<<degree<<endl<<"Marks: "<<marks<<endl;
		cout<<"Company: "<<company<<endl<<"Post: "<<post<<endl<<"Experience: "<<exp<<endl;
	}
};

int main()
{
	int ch;
	bio app;
	app.getdata();
	while(1)
	{
		cout<<"Enter your choice:\n\n1. Display all\n2. Display personal data\n3. Display academic data\n4. Display professional data\n";
		cin>>ch;
		switch (ch)
		{
			case 1: app.display();
			break;
			case 2: app.personal::display();
			break;
			case 3: app.academic::display();
			break;
			case 4: app.pro::display();
			break;
			default: cout<<"Wrong choice\n"; exit(1);
		}
	}
	return 0;
}					
