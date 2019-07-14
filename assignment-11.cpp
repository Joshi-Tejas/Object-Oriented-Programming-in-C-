#include<iostream>
#include<stack>
using namespace std;

class binary
{
	stack<int> s1,s2,s3;
	public:
	void getdata()
	{
		int i,n,bit,num1[10],num2[10];
		cout<<"Enter number of bits : ";
		cin>>n;
		cout<<"Enter first number bit by bit : ";
		for(i=0;i<n;i++)
		{
			cin>>bit;
			num1[i]=bit;
			s1.push(bit);
		}
		cout<<"The first number is : ";
		for(i=0;i<n;i++)
		{
			cout<<num1[i]<<" ";
		}
		cout<<endl;
		cout<<"Enter second number bit by bit : ";
		for(i=0;i<n;i++)
		{
			cin>>bit;
			num2[i]=bit;
			s2.push(bit);
		}
		cout<<"The second number is : ";
		for(i=0;i<n;i++)
		{
			cout<<num2[i]<<" ";
		}
		cout<<endl;
	}
	
	void addition()
	{
		int carry=0,temp,bit1,bit2;
		while(!s1.empty() && !s2.empty())
		{
			bit1=s1.top();
			s1.pop();
			bit2=s2.top();
			s2.pop();
			temp=bit1+bit2+carry;
			temp=temp%2;
			s3.push(temp);
			if(((bit1==0 && bit2==1) || (bit1==1 && bit2==0) || (bit1==1 && bit2==1)) && carry==1)
				carry=1;
			else if(carry==0 && (bit1==1 && bit2==1))
				carry=1;
			else carry=0;	
		}
		if(carry==1)
			s3.push(1);
		cout<<"Addition of these two numbers  is : ";
		while(!s3.empty())
		{
			cout<<s3.top()<<" ";
			s3.pop();
		}
		cout<<endl;
	}			 
};

int main()
{
	binary num;
	num.getdata();
	num.addition();
	return 0;
}	
