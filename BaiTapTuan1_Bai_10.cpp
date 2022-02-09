#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

void Day(int month, int year)
{
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	{
		cout<<"Thang co 31 ngay \n";
	}
	if(month==4||month==6||month==9||month==11)
	{
		cout<<"Thang co 30 ngay \n";
	}
	if(month==2)
	{
		if(year%4==0 && year%100!=0 || year%400==0)
		{
			cout<<"Thang co 29 ngay \n";
		}else cout<<"Thang co 28 ngay \n";
	}
}
int main()
{
	int month,year;
	cout<<"Nhap vao thang : ";cin>>month;
	cout<<"Nhap vao nam : ";cin>>year;
	Day(month,year);
}

