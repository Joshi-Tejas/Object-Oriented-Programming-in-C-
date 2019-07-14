#include<iostream>
#include<string.h>
using namespace std;

class book
{
	char *name,*author,*pub;
	int stock;
	float price;
	public:
	book(char* a,char* b,char *c,int st,float pr)
	{	
		name=new char(strlen(a)+1);
		author=new char(strlen(b)+1);
		pub=new char(strlen(c)+1);
		strcpy(name,a);
		strcpy(author,b);
		strcpy(pub,c);
		stock=st;
		price=pr;
	}	
	
	void display()
	{
		cout<<"Name: "<<name<<endl<<"Author: "<<author<<endl<<"Publication: "<<pub<<endl<<"Stock: "<<stock<<endl<<"Price: "<<price<<endl; 
	}	
	
	int search(char arr1[],char arr2[])
	{
		return (strcmp(arr1,name)==0 && strcmp(arr2,author)==0);
	}	
	
	int avail(int num_book,float *total)
	{
		if(stock>=num_book)
		{
			stock = stock - num_book;
			*total=*total+price*num_book;
			return 0;
		}	
		else 
			return 1;
	}
	
	~book()
	{
		delete name, author, pub;
	}					
};

int main()
{
	int num,stock,i,ser,flag=0,st,choice,num_book;
	float price,total=0.0;
	char name[20],aut[20],pub[20];
	book *b[100];
	cout<<"enter number of books\n";
	cin>>num;
	while(1)
	{
		cout<<"Enter your choice\n1. Enter data\n2. display\n3. search\n4. Buy\n5. Exit\n";
		cin>>choice;
		switch (choice)
		{
			case 1: for(i=0;i<num;i++)
				{
				cout<<"For book "<<i+1<<endl;
				cout<<"enter name, author, publisher, stock and price of the book.\n";
				cin>>name>>aut>>pub>>stock>>price;
				b[i]=new book(name,aut,pub,stock,price);
				}
			break;
			case 2: for(i=0;i<num;i++)
				{
				cout<<"For book "<<i+1<<endl;
				b[i]->display();
				}
			break;	
			case 3: cout<<"Enter name and author of book to search\n";
			cin>>name>>aut;
			for(i=0;i<num;i++)
			{
				flag=0;
				ser=b[i]->search(name,aut);
				if(ser==1)
				{
					flag=1;
					break;
				}			
			}
			if(flag==1)
				cout<<"THE BOOK IS FOUND\n";
			else
				cout<<"NOT FOUND\n";
			break;	
			case 4: cout<<"Enter name and author of book to buy\n";
			cin>>name>>aut;
			flag=0;
			for(i=0;i<num;i++)
			{
		
				ser=b[i]->search(name,aut);
				if(ser==1)
				{	cout<<"Enter number of books to by\n";
					cin>>num_book;
					st=b[i]->avail(num_book,&total);
					flag = 1;
				}			
			}		
			if(flag==1)
				cout<<"Thank you for purchase\n";
			else
				cout<<"Sorry, no stock or book available\n"; 	
			break;
			case 5: cout<<"your total is:"<<total<<endl; 
				exit(1);
			break;
			default: cout<<"wrong choice\n";
		}
	}			
	return 0;
}				
