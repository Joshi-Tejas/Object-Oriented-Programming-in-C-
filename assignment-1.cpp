#include<iostream>
using namespace std;

int main()
{
	float a,b,c;
	char ch,ch1;
	do 
	{
		cout<<"Enter expression:\n";
		cin>>a>>ch>>b;
		switch (ch)
		{
			case '+': c=a+b;
				  cout<<c<<endl;
			break;
			case '-': c=a-b;
				  cout<<c<<endl;
			break;
			case '/': c=a/b;
				  cout<<c<<endl;
			break;
			case '*': c=a*b;
				  cout<<c<<endl;
			break;
			default: cout<<"invalid expression\n";
			break;
		}
		cout<<"Do you want to continue?(y/n)\n";
		cin>>ch1;
	}while(ch1=='y');			  	  	   	 	  	  
	return 0;
}	
