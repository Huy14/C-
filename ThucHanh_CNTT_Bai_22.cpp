#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
	int n , space;
	cout<<"Enter n : ";cin>>n;
	for(int i = 1 ; i<=n ; i++)
		{
			for(int j = 1 ; j<=i ; j++)
			{
				cout<<" * ";
			}cout<<endl;
		}
	cout<<"__________________________________________________________"<<endl;
		for(int i = 1 ; i<=n ; i++)
		{
			for(int j = 1 ; j<=i ; j++)
			{

				if( i == 3 && j == 2)
				{
					cout<<"   ";
				}else cout<<" * ";
			}cout<<endl;
		}
		
	cout<<"__________________________________________________________"<<endl;
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j<=n ; j++)
			{
			
				if(j <= n-i )
					{
						cout<<"   ";
					}else cout<<"  *";
			}cout<<endl;
		}
	cout<<"__________________________________________________________"<<endl;
			for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j<=n ; j++)
			{
			
				if(j <= n-i || i == 3 && j == 3 )
					{
							
								cout<<"   ";
							
					} else cout<<"  *";
						
			}cout<<endl;
		}
	
		
	
}

