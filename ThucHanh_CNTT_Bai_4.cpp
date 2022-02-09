#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
#define MAX 100
using namespace std;
void Xuat(int array[], int &index)
{
	while(1)
	{
		cout<<"Enter a number : ";cin>>array[index];
		if(array[index] == 0) break;
		index++;
	}
	
	for(int i=0 ; i<index ; i++)
	{
		cout<<array[i]<<" ";
	}cout<<endl;
}
//Check So Hoan Hao
int kt_HH(int &index)
{
	int temp = 0;
	for(int i=1 ; i<index ; i++)
	{
		if(index % i == 0)
			temp += i;
	}
	if(temp==index && temp!=0)
		return 1;
	return 0;
}
//Check So Nguyen To
int Check_So_Nguyen_To (int &index)
{
	if(index<2)
		return 0;
	else
		for(int i=0 ; i<sqrt(index) ; i++)
		{
			if(index%2==0)
				return 0;
			return 1;
		}
}
//Check So Chinh Phuong
bool Check_Chinh_Phuong(int &index)
{
	if(index<1)
		return false;
	int i = sqrt(index);
	if(i*i == index)
		return true;
	return false;
}
void SoChinhPhuong(int array[] , int &index, int &count2)	
{
	
	for(int i=0 ; i<index ; i++)
	{
		if(Check_Chinh_Phuong(array[i]))
		{
			count2++;
		}
	}cout<<count2<<" so chinh phuong";
	cout<<endl;
}	
void SHH(int array[] , int &index, int &count3)	
{
	
	for(int i=0 ; i<index ; i++)
	{
		if(kt_HH(array[i]))
		{
			count3++;
		}
	}cout<<count3<<" so hoan hao";
}	
void SNT(int array[] , int &index, int &count)	
{
	
	for(int i=0 ; i<index ; i++)
	{
		if(Check_So_Nguyen_To(array[i]))
		{
			count++;
		}
	}cout<<count<<" so nguyen to";
	cout<<endl;
}	
int main()
{
	int array[MAX];
	int index, count, count2, count3;
	Xuat(array, index);
	SNT(array, index, count);
	SoChinhPhuong(array, index , count2);
	SHH(array, index, count3);
}

