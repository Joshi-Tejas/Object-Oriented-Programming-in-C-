//author:Tejas joshi
//date: 03/08/2017
#include<iostream>
#include<math.h>
using namespace std;

class polynomial
{
	float a,b,c;
	public: 
	polynomial(){}
	polynomial(float x,float y,float z)
	{
		a=x;
		b=y;
		c=z;
	}	
	friend istream & operator>>(istream &i,polynomial &x);
	friend ostream & operator<<(ostream &o,polynomial &x);
	
	polynomial operator+(polynomial x)
	{	
		polynomial p;
		p.a=a+x.a;
		p.b=b+x.b;
		p.c=c+x.c;
		return p;
	}
	
	polynomial operator-(polynomial x)
	{	
		polynomial p;
		p.a=a-x.a;
		p.b=b-x.b;
		p.c=c-x.c;
		return p;
	}	
	void root()
	{
		int y,z;
		if((b*b-4*a*c)>=0)
		{
			y=-b/(2*a) + sqrt(b*b-4*a*c)/(2*a);
			z=-b/(2*a) - sqrt(b*b-4*a*c)/(2*a);
			cout<<"one root is:"<<y<<endl<<"second root is:"<<z<<endl;
		}
		else if((b*b-4*a*c)<0)
		{
			cout<<"as discriminent of this polynomial is negeative, roots are imaginary.\n";
			cout<<"one root is:"<<-b/(2*a)<<" + i"<<sqrt(-(b*b-4*a*c))/(2*a)<<endl;
			cout<<"second root is:"<<-b/(2*a)<<" - i"<<sqrt(-(b*b-4*a*c))/(2*a)<<endl;
		}	
	}
	void eval(int num)
	{
		cout<<num*num*a+num*b+c<<endl;
	}		 
};

istream & operator>>(istream &i,polynomial &x)
{
	cin>>x.a>>x.b>>x.c;
	return i;
}

ostream & operator<<(ostream &o,polynomial &x)
{
	cout<<x.a<<"x^2+"<<x.b<<"x+"<<x.c;
	return o;
}

int main()
{
	int ch;
	polynomial A(0.0,0.0,0.0),B(0.0,0.0,0.0),C,D;
	cout<<"enter first polynomial's coefficients.\n";
	cin>>A;
	cout<<"you entered polynomial:"<<A<<endl;
	cout<<"enter second polynomial's coefficients.\n";
	cin>>B;
	cout<<"you entered polynomial:"<<B<<endl;
	cout<<"enter your choice\n1. Addition\n2. Subtraction\n3. Evaluation\n4. Roots\n";
	cin>>ch;
	switch (ch)
	{
		case 1:{
			cout<<"addition of these polynomials is:\n";
			C=A+B;
			cout<<C<<endl;
			}
		break;
		case 2:{
			cout<<"Subtraction is:\n";
			D=A-B;
			cout<<D<<endl;
			}
		break;
		case 3:{
			int num;
			cout<<"enter number to evaluate the expression.\n";
			cin>>num;
			cout<<"envaluation of first polynomial:";
			A.eval(num);
			cout<<"envaluation of second polynomial:";
			B.eval(num);
			}	
		break;	
		case 4:{	
			cout<<"roots of first polynomial are:\n";
			A.root();
			cout<<"roots of second polynomial are:\n";
			B.root();
			}	
		break;
		default	: cout<<"invalid choice.\n";
		break;
	}			
	return 0;
}				
