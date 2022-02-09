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
int calender( int month , int year)
{
	int day= Day( month,  year);
	int Wd = weekday(1,month,year);
	cout<<"CN\tThu 2\tThu 3\tThu 4\tThu 5\tThu 6\tThu 7\n";
	for(int i=1 ; i<Wd; i++)
	{
		cout<<"\t";
	}
	for(int i=1 ; i<=day; i++)
	{
		cout<<i<<"\t";
		if(Wd %7==0) 
		{
			cout<<"\n";
			Wd++;
		}
	}
}
int main()
{
	int month,year;
	
	
	calender(10 , 2021);
}

