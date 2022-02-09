#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
	int n;
	cout<<"Enter n : ";cin>>n;
	cout<<"Hinh vuong \n";
		for(int i=0 ; i<n ; i++)
			{
				for(int j=0 ; j<n ; j++)
					{
						cout<<" * ";
					}cout<<endl;
			}
	cout<<"_______________________________________________________________________"<<endl;
	cout<<"Hinh vuong rong\n";
		for(int i=0 ; i<=n ; i++)
			{
				for(int j=0 ; j<=n ; j++)
					{
						if(i == 0 || i == n || j == 0 || j == n)
							cout<<" * ";
						else cout<<"   ";	
					}
				cout<<endl;	
			}
}

