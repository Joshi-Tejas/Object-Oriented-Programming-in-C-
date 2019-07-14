#include<iostream>
using namespace std;

class employee
{
	string city;
	int age, vehicle;
	float income;
	public:
	int get_age(int a)
	{
		try
		{
			if(a<18 || a>55)
				throw (1);
			else
			{
				age=a;
				return 1;
			}	
		}
		catch(int x)
		{
			cout<<"Invalid age!\n";
		}
		return 0;
	}
	
	int get_city(string a)
	{
		try
		{
			if(a!="pune" && a!="chennai" && a!="bangalore" && a!="mumbai")
				throw (1.1);
			else
			{
				city=a;
				return 1;
			}	
		}
		catch(double x)
		{
			cout<<"Invalid city!\n";
		}
		return 0;
	}
	
	int get_income(float a)
	{
		try
		{
			if(a<50000 || a>100000)
				throw ('a');
			else
			{
				income=a;
				return 1;
			}	
		}
		catch(char x)
		{
			cout<<"Invalid income!\n";
		}
		return 0;
	}
	
	int get_vehicle(int a)
	{
		try
		{
			if(a!=4)
				throw (1);
			else
			{
				vehicle=a;
				return 1;
			}	
		}
		catch(int x)
		{
			cout<<"Invalid vehicle!\n";
		}
		return 0;
	}
	
	void display()
	{
		cout<<"Age : "<<age<<endl<<"City : "<<city<<endl;
		cout<<"Income : "<<income<<endl<<"Vehicle : "<<vehicle<<" wheeler"<<endl;
	}					
};

int main()
{
	int age,take=1,vehicle;
	float income;
	string city;
	employee emp;
	do 
	{
		cout<<"Enter age : ";
		cin>>age;
		take=emp.get_age(age);
	}while(take==0);
	do 
	{
		cout<<"Enter city : ";
		cin>>city;
		take=emp.get_city(city);
	}while(take==0);
	do 
	{
		cout<<"Enter income : ";
		cin>>income;
		take=emp.get_income(income);
	}while(take==0);
	do 
	{
		cout<<"Enter kind of vehicle(4 wheeler/2 wheeler) : ";
		cin>>vehicle;
		take=emp.get_vehicle(vehicle);
	}while(take==0);
	emp.display();
	return 0;
}		
