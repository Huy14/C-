#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#define MAX 100
using namespace std;
int main()
{
	int number;
	float avg , sum;
	do
	{
		cout<<"Enter a number : ";cin>>number;
		sum += number;
		avg = sum / number;
	}while(number > 0);
	if(number==0)
	{
		cout<<"Sum of them is : \n"<<avg;
	}
}
