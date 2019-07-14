#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main()
{
	int vowel=0,space=0,character=0,line=0;
	string str;
	char ch;
	ofstream fout("data.txt");
	cout<<"Give input :\n";
	do
	{
		getline(cin,str);
		fout<<str<<endl;
	}while(str.length()>0);
	fout.close();
	ifstream fin("data.txt");
	cout<<"The data in file is :\n";
	while(!fin.eof())
	{
		fin.get(ch);
		cout<<ch;
		if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
            		vowel++;
		if(ch==' ')
			space++;
		if((int(ch)>=65 && int(ch)<=90) || (int(ch)>=97 && int(ch)<=122))
			character++; 
		if(ch=='\n')
			line++;
	}
	cout<<"The Data has :\n";
	cout<<"Vowels : "<<vowel<<endl<<"spaces : "<<space<<endl<<"characters : "<<character<<endl<<"lines : "<<(line-2)<<endl;
	return 0;
}		
