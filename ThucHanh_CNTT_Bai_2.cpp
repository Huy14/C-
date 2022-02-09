#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#define MAX 100
using namespace std;
int main()
{
	float number , sum , index = 0 , avg = 0;
	do
	{
		cout<<"Enter a number : ";cin>>number;
		index++;
		sum += number;
		avg = sum / (index-1);
	}while(number > 0);
	
	if(number==0)
	{
		cout<<"Sum of them is : \n"<<fixed<<setprecision(2)<<avg;
	}
}
