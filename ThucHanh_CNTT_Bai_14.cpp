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
	int array[n];
	int sum=0;
	cout<<"Nhap vao phan tu trong mang : ";cin>>n;
	for(int i=0 ; i<n; i++)
	{
		cout<<"Nhap array ["<<i+1<<"] : ";cin>>array[i];
		sum+=array[i];
	}
	cout<<"Cac phan tu trong mang : ";
		for(int i=0 ; i<n; i++)
	{
		cout<<array[i]<<"  ";
	}
	cout<<" = "<<sum;
		

}

