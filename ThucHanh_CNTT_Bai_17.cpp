#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
#define MAX 100
using namespace std;

//NHAP VA TAO MANG NGAU NHIEN
void Nhap(int &Rows , int &Columns,int array[MAX][MAX])
{
	cout<<"Rows : ";cin>>Rows;
	cout<<"Columns : ";cin>>Columns;
	srand(time(NULL));
	for(int i=0 ; i<Rows ; i++)
	{
		for(int j=0 ; j<Columns; j++)
		{
			array[i][j] =  rand() % 101;
		}
	}
}

//XUAT MANG NGAU NHIEN
void Xuat(int &Rows , int &Columns,int array[MAX][MAX])
{
	cout<<"Mang 2 chieu la :"<<endl;
	for(int i=0 ; i<Rows ; i++)
	{
		for(int j=0 ; j<Columns; j++)
		{
			cout<<array[i][j]<<" ";
		}cout<<endl;
	}
}

//TINH TONG CUA MANG 2 CHIEU
void Tong(int &Rows , int &Columns,int array[MAX][MAX])
{
	int sum = 0;
	for(int i=0 ; i<Rows ; i++)
	{
		for(int j=0 ; j<Columns; j++)
		{
			sum += array[i][j];
		}
	}
	cout<<"Tong cua mang 2 chieu la : "<<sum<<endl;
}

//TINH TONG CUA CAC PHAN TU NAM TREN DUONG VIEN HINH CHU NHAT
void DuongVien(int &Rows , int &Columns,int array[MAX][MAX])
{
	int sum = 0;
	for(int i=0 ; i<=Rows ; i++)
	{
		for(int j=0 ; j<=Columns; j++)
		{
			if(i == 0 || i == Rows || j == 0 || j == Columns)
			{
				sum += array[i][j];
			}
		}
	}
	cout<<"Tong cua mang 2 chieu nam tren duong vien la : "<<sum<<endl;	
}

//TIM SO COT CO GIA TRI SUM LON NHAT
void CotMax(int &Rows , int &Columns,int array[MAX][MAX])
{
	int sum=0;
	int index = 0;
	int arr[MAX];
	for(int i=0 ; i<Columns ; i++)
    {
		for(int j=0 ; j<Rows ; j++)
        sum += array[j][i];
        cout<<"Sum of Column "<<i+1<<" is "<<sum;
        arr[index] = sum;
        index++;
        sum = 0;
        cout<<endl;
	} 
	
	int max = arr[0] ;
	for(int i=0 ; i<index ; i++)
	{
		if(max < arr[i])
		{
			max = arr[i];
		}
		
	}cout<<endl;
	cout<<"Largest Columns is "<<max;
	
	
}

//TIM SO DONG CO GIA TRI SUM LON NHAT
void DongMin(int &Rows , int &Columns,int array[MAX][MAX])
{
	int sum=0;
	int index = 0;
	int arr[100];
	for(int i=0 ; i<Rows ; i++)
    {
		for(int j=0 ; j<Columns ; j++)
        sum += array[i][j];
        cout<<"Sum of Row "<<i+1<<" is "<<sum;
        arr[index] = sum;
        index++;
        sum = 0;
        cout<<endl;
	}
	int min = arr[0] ;
	for(int i=0 ; i<index ; i++)
	{
		if(min > arr[i])
		{
			min = arr[i];
		}
		
	}cout<<endl;
	cout<<"Smallest Rows is "<<min;
}   
    
int main()
{
	int key, Rows, Columns;
	int array[MAX][MAX];
	bool ended = false;
	bool DaNhap;
	while(!ended)
	{
		cout<<"_________________________________________________________\n";
		cout<<"1.Nhap rows , columns va tao mang ngau nhien\n";
		cout<<"2.In mang 2 chieu\n";
		cout<<"3.In tong cua mang 2 chieu\n";
		cout<<"4.In tong cac mang nam tren duong vien\n";
		cout<<"5.Tim cot MAX\n";
		cout<<"6.Tim dong co tong bang min\n";
		cout<<"7.Exit\n";
		cout<<"__________________________________________________________\n";
		cout<<"Nhap vao cac lua chon tren : ";cin>>key;
		cout<<endl;
		
		switch(key)
		{
			case 1 : 
				Nhap(Rows,Columns,array);
			    DaNhap = true;
				cout<<endl;
			break;
			
			case 2 :
				if(DaNhap)
				{
					Xuat(Rows,Columns,array);
				}else cout<<"Nhap mang truoc!!!!";
				cout<<endl;
			break;
			
			case 3 :
				if(DaNhap)
				{
					Tong(Rows,Columns,array);
				}else cout<<"Nhap mang truoc!!!!";
				cout<<endl;
			break;
			
			case 4 :
				if(DaNhap)
				{
					DuongVien(Rows,Columns,array);
				}else cout<<"Nhap mang truoc!!!!";
				cout<<endl;
			break;
			
			case 5 :
				if(DaNhap)
				{
					CotMax(Rows,Columns,array);
				}else cout<<"Nhap mang truoc!!!!";
				cout<<endl;
			break;
			
			case 6 :
				if(DaNhap)
				{
					DongMin(Rows,Columns,array);
				}else cout<<"Nhap mang truoc!!!!";
				cout<<endl;
			break;
			
			case 7 : 
				cout<<"Ban da thoat chuong trinh!!!!\n";
				exit(0);
				
			default : 
				cout<<"Lua chon khong hop le \n";
				
		}
		
	}
}

