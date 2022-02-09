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
	float number , sum;
	float max = sum;
	srand(time(NULL));
	cout<<"Nhap n : ";cin>>n;		
	for(char a = 'A' ; a < 'A'+n ; a++)
	{
		cout<<a<<" : ";
			for(int j = 1 ; j<n ; j++)
			{
				number = (rand() % 101) * 0.1;
				cout<<fixed<<setprecision(2)<<number<<"  ";
				sum += number;
			}
			
			cout<<" = "<<fixed<<setprecision(2)<<sum<<endl;
			
			for(int i = 0 ; i<n ; i++)
			{
				if(max < sum)
				{
					max = sum;
				}
			}		
	}
	
			cout<<"Day lon nhat : "<<fixed<<setprecision(2)<<max;
}


