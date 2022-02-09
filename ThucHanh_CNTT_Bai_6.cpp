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
	int number;
	float sum, avg;
	cout<<"Nhap N : ";cin>>n;
	srand(time(NULL));
	for(int i=0 ; i<n ; i++)
	{
		number = rand() % 41 - 20 ;
		sum+=number;
		cout<<number<<" ";
	}
	avg = sum / n;
	cout<<" = "<<fixed<<setprecision(2)<<avg;
}

