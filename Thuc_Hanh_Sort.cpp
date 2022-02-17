#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;

//ENTER ARRAY
void EnterArray(int &n)
{
	cout<<"Vui long nhap vao so luong phan tu trong mang : ";
	cin>>n;
}

//RANDOM NUMBER
void Random(int Array[] , int &n)
{
	srand(time(NULL));
	
	for(int i = 0 ; i < n ; i++ )
	{
		Array[i]=rand() % 100;
	}
}

//COUT RANDOM NUMBER
void CoutRandom(int Array[] , int &n)
{
	for(int i = 0 ; i < n ; i ++)
	{
		cout<<"Array ["<<i+1<<"] : "<<Array[i]<<"\t\t";	
	}
	cout<<endl;
}

//INTERCHANGE SORT
void InterChangeSort(int Array[] , int &n , int temp)
{
	for(int i = 0 ; i < n-1 ; i++)
	{
		for(int j = i + 1 ; j < n ; j++)
		{
			if( Array[i] > Array[j] )
			{
				temp = Array[i];
				Array[i] = Array[j];
				Array[j] = temp;
			}
		}
	}	
	
	cout<<endl;
	
	cout<<"Array after InterChange Sort : \n";
	for(int i = 0 ; i < n ; i++)
	{
		cout<<Array[i]<<"\t";
	}
	
	cout<<endl;
}

//BUBBLESORT
void BubbleSort(int Array[] , int &n , int temp)
{
	for(int i = 0 ; i < n-1 ; i++)
	{
		for(int j = n-1 ; j > i ; j--)
		{
			if( Array[i] > Array[j] )
			{
				temp = Array[i];
				Array[i] = Array[j];
				Array[j] = temp;
			}
		}
	}
	
	cout<<endl;
	
	cout<<"Array after Bubble Sort : \n";
	for(int i = 0 ; i < n ; i++)
	{
		cout<<Array[i]<<"\t";
	}
	
	cout<<endl;
}
int main()
{
	int n;
	int temp;
	
	EnterArray(n);
	int Array[n];
	
	Random(Array , n);
	CoutRandom(Array , n );
	
	InterChangeSort(Array , n , temp);
	
	BubbleSort(Array , n,  temp);
}
