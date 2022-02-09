#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	int n, number;
	int sum=0;
	cout<<"Nhap n so muon khoi tao : ";cin>>n;
	srand(time(NULL));
	for(int i=0 ; i<n; i++)
	{
		number = rand() % 51;
		cout<<number<<" ";
		sum+=number;
	}cout<<endl;
	cout<<"Tong la : "<<sum;
	
}

