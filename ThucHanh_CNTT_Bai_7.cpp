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
	float number;
	float sum;
	cout<<"Nhap N : ";cin>>n;
	srand(time(NULL));
	for(int i=0 ; i<n ; i++)
	{
		number = rand() % 11 * 0.1 ;
		sum+=number;
		cout<<number<<" ";
	}
	cout<<fixed<<setprecision(2)<<" = "<<sum;
}

