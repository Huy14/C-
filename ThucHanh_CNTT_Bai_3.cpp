#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
int Check_So_Nguyen_To (int &index)
{
	if( index<2 )
		return 0;
	else
		for(int i=2 ; i<=sqrt(index) ; i++)
		{
			if( index%2 == 0 )
				return 0;
			return 1;
		}

}
int main()
{
	int a[50];
	int index;
	do{
		cout<<"Enter a number : ";
		index++;
		cin>>a[index];
	}while(a[index]>0);
	
	cout<<"All the numbers are : "<<endl;
	for(int i=1 ; i<=index-1 ; i++)
	{
		cout<<a[i]<<" ";
	}cout<<endl;
	
	//SO CHAN 
	cout<<"So chan la : "<<endl;
	for(int i=1 ; i<=index-1 ; i++)
	{
		if(a[i] % 2 == 0)
			{
				cout<<a[i]<<" ";
			}
	}cout<<endl;
	
	//SO LE
	cout<<"So le la : "<<endl;
	for(int i=1 ; i<=index-1 ; i++)
	{
		if(a[i] % 2 != 0)
			{
				cout<<a[i]<<" ";
			}
	}cout<<endl;
	
	//SO NGUYEN TO
	cout<<"So nguyen to : ";
	for(int i=1 ; i<=index-1 ; i++)
	{
		if(Check_So_Nguyen_To(a[i]))
		{
			cout<<a[i]<<" ";
		}
	}cout<<endl;
	
}


