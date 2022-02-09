#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<string> 
using namespace std;

int DoDaiChuoi (char name[])
{
	int i=0;
	while (name[i]!=NULL)
		i++;
	return i;
}

void ChuyenChu(char name[],int i)
{
	if (name[i] >= 'A' && name[i] <= 'Z')
		name[i] += 32; 
}

void InTen(char name[], int &i, int &j){
	for ( i= DoDaiChuoi(name); i>=0; i--)
	{
	
		if (name[i]==' ')
		{
			for (j=i; j<DoDaiChuoi(name);j++)
			{
				ChuyenChu(name,j);
				cout<<name[j];
			}
			break;
		}
		
	}	
}

void InHo(char name[], int &i, int &j)
{
	for (i = 0; i<DoDaiChuoi(name); i++)
	{
		if(i == 0)
		{
			ChuyenChu(name,i);
			i+1;
			break;
		}
		
	}
	cout<<name[i];	
	
	for (i = 0; i<DoDaiChuoi(name); i++)
	{
		if(name[i] == ' ')
		{
			i++;
			ChuyenChu(name,i);
			break;
		}	
	}
	cout<<name[i];	
}

int main()
{
	int i,j;
	string MSSV;
	char name[50];	
	cout<<"Nhap ho ten: ";
	gets(name);
	cout<<"Nhap MSSV: ";
	getline(cin,MSSV);
	InTen(name,i,j);
	cout<<".";
	InHo(name, i , j);
	string sub = MSSV.substr(2,MSSV.length());
	cout<<sub;
	cout<<"@hoasen.edu.vn";
	
	
}

