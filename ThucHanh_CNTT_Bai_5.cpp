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
	int sum;
	cout<<"Nhap N : ";cin>>n;
	srand(time(NULL));
	for(int i=0 ; i<n ; i++)
	{
		number = rand() % 51;
		sum+=number;
		cout<<number<<" ";
	}
	cout<<" = "<<sum;
}

