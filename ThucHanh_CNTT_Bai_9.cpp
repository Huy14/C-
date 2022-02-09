#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
int Day(int month, int year)
{
	switch(month)
	{
		case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 : return 31;
		case 4 : case 6 : case 9 : case 11 : return 30;
		case 2 :
			if(year%4==0 && year%100!=0 || year%100==0 && year%400==0)
			{
				return 29;
			}else return 28;
	}
}
int C(int day , int month , int year)
{
	int s = day;
	for(int i = 1 ; i<month ; i++)
	{
		s+= Day(i, year);
	}
	return s;
}
int weekday(int day , int month , int year)
{
	int N1=(year-1)/4;
	int N2=(year-1)/100;
	int N3=(year-1)/400;
	int N = (year-1) + N1 - N2 + N3 + C(day,month,year);
	int wd = N % 7 +1;
	return wd;
	
}
int main()
{
	int day,month,year;
	cout<<"Nhap ngay : ";cin>>day;
	cout<<"Nhap vao thang : ";cin>>month;
	cout<<"Nhap vao nam : ";cin>>year;
	int wd = weekday(day,month,year);
	if(wd==1)
	{
		cout<<"Chu Nhat\n";
	}else cout<<"Thu "<<wd<<endl;
}

