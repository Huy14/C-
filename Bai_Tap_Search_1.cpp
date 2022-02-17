#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;

void TaoMang(int n , int array[])
{
	srand(time(NULL));
	
	for(int i = 0 ; i < n ; i++ )
	{
		array[i] = rand() % 100;
		cout<<"Array ["<<i+1<<"] : "<<array[i]<<"\n\n";
	}
}

void TimSo(int n , int array[] , int x)
{
	for(int i = 0 ; i < n ; i++)
	{
		if( x == array[i] )
		{
			cout<<"Ket qua : "<<x<<" nam tai vi tri "<<i+1<<"\n\n";
			break;
		} 
	} 
		cout<<"Ko tim thay "<<x<<" trong mang \n\n";
}

void SapXepTangDan(int n , int array[] , int temp)
{
	for(int i = 0 ; i <n ; i++)
	{
		for(int j = i+1 ; j<n ; j++)
		{
			if( array[i] > array[j] )
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
		cout<<"Array after reversed ["<<i+1<<"] : "<<array[i]<<"\n\n";
	}
}

void BinarySearch(int n , int array[] , int x)
{
	int Left = 0;
	int Right = n-1;
	int Mid;
	
	while (Left <= Right)
	{
		Mid = (Left + Right) / 2;
		if(x == array[Mid])
		{
			cout<<"Ket qua : "<<x<<" nam tai vi tri "<<Mid+1<<"\n";
			break;
		}
		else if (x < array[Mid])
		{
			Right = Mid - 1;
		}
		else if (x > array[Mid])
		{
			Left = Mid + 1;
		}
	
	}
		cout<<"Ket qua : "<<x<<" khong co trong mang "<<"\n";
}
int main()
{
	int n;
	cout<<"Nhap vao so luong phan tu mang : ";
	cin>>n;
	cout<<"\n\n";
	int array[n];
	TaoMang(n,array);
	
	//Tim So Trong Mang
	int x;
	cout<<"Nhap vao so can tim : ";
	cin>>x;
	cout<<"\n\n";
	TimSo(n,array,x);

	
	//Sap xep tang dan
	int temp;
	SapXepTangDan(n,array,temp);
	
	
	//BinarySearch
	BinarySearch( n ,  array ,  x);
}
