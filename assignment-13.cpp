#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

class stud
{
	char fname[20],name[20];
	long int phone;
	public:
	
	void getdata()
	{
		fstream f;
		int choice;
		cout<<"Enter file name (with extension) : ";
		cin>>fname;
		f.open(fname);
		if(f.fail())
		{
			cout<<"Error opening file\nEnter choice\n";
			cout<<"1. To re-open the file\n2. To create a new file with name : "<<fname<<"\n";
			cin>>choice;
			switch (choice)
			{
				case 1: getdata();
				break;
				case 2: create();
				break;
				default: cout<<"Wrong choice\n";
				break;
			}
		}
		else
		{
			cout<<"File opened successfully\n";
		}		
	}
	
	void create()
	{
		int num,i;
		stud s;
		ofstream fout;
		cout<<"Enter number of students : ";
		cin>>num;
		fout.open(fname);
		if(fout.fail())
			cout<<"Failed to open file\n";
		else
		{
			cout<<"Enter data :\n";
			for(i=0;i<num;i++)
			{
				cout<<"Enter name : ";
				cin>>s.name;
				cout<<"Enter phone number : ";
				cin>>s.phone;
				fout.write((char*)&s,sizeof(s));
			}
			cout<<"File sucessfully created\n";
		}
		fout.close();
	}
	
	void display()
	{
		stud s;
		ifstream fin;
		fin.open(fname);
		cout<<"NAME\t"<<"PHONE\n";
		if(fin.fail())
			cout<<"Failed to open file\n";
		else
		{	
			while(fin.read((char*)&s,sizeof(s)))
			{
				cout<<s.name<<"\t"<<s.phone<<endl;
			}
			fin.close();
		}
	}
	
	void searchn()
	{
		char n[20];
		stud s;
		int flag=0;
		ifstream fin;
		fin.open(fname);
		cout<<"Enter name to be searched : ";
		cin>>n;
		if(fin.fail())
			cout<<"Failed to open file\n";
		else
		{
			while(fin.read((char*)&s,sizeof(s)))
			{
				if(strcmp(s.name,n)==0)
				{
					cout<<"Entry found!!!\n";
					cout<<"NAME\t"<<"PHONE\n";
					cout<<s.name<<"\t"<<s.phone<<endl;
					flag=1;
				}
			}
			if(flag==0)
				cout<<"No data found\n";
		}
		fin.close();
	}	
	
	void searchp()
	{	
		int temp;
		stud s;
		int flag=0;
		ifstream fin;
		fin.open(fname);
		cout<<"Enter phone number to be searched : ";
		cin>>temp;
		if(fin.fail())
			cout<<"Failed to open file\n";
		else
		{
			while(fin.read((char*)&s,sizeof(s)))
			{
				if(s.phone==temp)
				{
					cout<<"Entry found!!!\n";
					cout<<"NAME\t"<<"PHONE\n";
					cout<<s.name<<"\t"<<s.phone<<endl;
					flag=1;
				}
			}
			if(flag==0)
				cout<<"No data found\n";
		}
		fin.close();	
	}	
	
	void editpn()
	{
	  	char temp[20];
		cout<<"Enter name whose ph no is to be edited:\n";
		cin>>temp;
 		int flag=0,pos=0;
	 	fstream f;
	  	stud s;
	  	f.open(fname);
	  		if(f.fail())
			{
	    		cout<<"Failed to open the file\n";
			}
        		else
			{
				while( f.read((char*)&s,sizeof(s)))
				{
					if(strcmp(s.name,temp)==0)
					{
				 	cout<<"RECORD FOUND........................ :-)\n";
				 	cout<<"Enter new ph no. for "<<s.name<<"\n";
				 	cin>>s.phone;
				 	f.seekp(pos*sizeof(s),ios::beg);
				 	f.write((char*)&s,sizeof(s));			 
				 	flag=1;
					}
					else
					{
						pos++;
					}
				}
			if(flag==1)
			{
			 cout<<"RECORD EDITED SUCCESSFULLY...!!!!\n";	 
			}
			else
			{
			 cout<<"Record not found.....\n";
			}
			}
			f.close();
	}								
};

int main()
{
	int choice;
	stud s;
	s.getdata();
	do
	{
		cout<<"Enter choice\n1. Overwrite file\n2. display\n3. Search by name\n4. Search by phone number\n.5. Edit phone number\n6. Exit\n";
		cin>>choice;
		switch (choice)
		{
			case 1: s.create();
			break;
			case 2: s.display();
			break;
			case 3: s.searchn();
			break;
			case 4: s.searchp();
			break;
			case 5: s.editpn();
			break;
		}
	}while(choice!=6);		
	return 0;
}	
