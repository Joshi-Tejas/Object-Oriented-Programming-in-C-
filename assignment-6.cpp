#include<iostream>
using namespace std;

template<class T>
void select(T arr[],int n)
{
	int i,j,index;
	T key;
	for(i=0;i<n-1;i++)
	{
		key=arr[i];
		index=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<key)
			{
				key=arr[j];
				index=j;
			}	
		}
		arr[index]=arr[i];
		arr[i]=key;
	}
	cout<<"Sorted array is :\n";
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int i,n,arr[50];
	float arr1[50];
	cout<<"Enter number elements : ";
	cin>>n;
	cout<<"Enter data (int)\n";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	select(arr,n);
	
	cout<<"Enter number elements : ";
	cin>>n;
	cout<<"Enter data (float)\n";
	for(i=0;i<n;i++)
	{
		cin>>arr1[i];
	}
	select(arr1,n);
	return 0;
}	
