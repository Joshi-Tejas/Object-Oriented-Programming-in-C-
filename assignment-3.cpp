//author:Tejas Joshi
//Date:02/08/2017
//this is OOP assignment
#include<iostream>
using namespace std;

class complex
{
	float real,img;
	public:
	complex()
	{
		real=0;
		img=0;
	}
	
	complex(complex &c)
	{
		real=c.real;
		img=c.img;
		cout<<"copy constructor is called\n";
	}	
	
	friend istream & operator>>(istream &i,complex &c);
	friend ostream & operator<<(ostream &o,complex &c);
	
	void display()
	{
		cout<<real<<"+ i"<<"("<<img<<")"<<endl;
	}	
	complex operator+(complex c)
	{
		complex cc;
		cc.real=real + c.real;
		cc.img=img + c.img;
		return cc;
	}
	complex operator-(complex c)
	{
		complex cc;
		cc.real=real-c.real;
		cc.img=img-c.img;
		return cc;
	}	
	complex operator*(complex c)
	{
		complex cc;
		cc.real=(real*c.real)-(img*c.img);
		cc.img=(real*c.img)+(img*c.real);
		return cc;
	}		
};

istream & operator>>(istream &i,complex &c)
{
	cin>>c.real>>c.img;
	return i;
}

ostream & operator<<(ostream &o,complex &c)
{
	cout<<c.real<<" + i"<<c.img;
	return o;
}	

int main()
{
	char c;
	int ch;
	complex C1,C2,C3,C4,C5;
	cout<<"enter two complex numbers.\n";
	cin>>C1>>C2;
	complex C6(C1);
	cout<<"your two complex numbers are:\n"<<C1<<endl<<C2<<endl;
	do
	{
		cout<<"enter your choice\n1. Addition\n2. Subtraction\n3. Multiplication\n";
		cin>>ch;
		switch (ch)
		{
			case 1:{
				 C3=C1+C2;
				 cout<<"addition is:\n";
				 C3.display();
				}
			break;
			case 2:{
				C4=C1-C2;
				cout<<"Subtraction is:\n";
				C4.display();
				}
			break;
			case 3:{
				cout<<"Multiplication is:\n";
				C5=C1*C2;
				C5.display();
				}
			break;		
			default: {cout<<"invalid operation.\n"; exit(1);}
			break;	
		}	
		cout<<"do you want to continue? (y/n)";
		
		cin>>c;
	}while(c=='y');		 
	return 0;
}		
