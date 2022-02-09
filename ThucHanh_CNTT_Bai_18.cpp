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

		ChuyenChu(name,i);
		if (name[i] == ' ')		
			continue;
		for (j = DoDaiChuoi(name); j>=0; j--)
		{
			if (name[j]==' ')
				{
					j++;
					break;
				}
		}
		if (name[i] == name[j])
			break;
		else cout<<name[i];			
		}		
}

int main()
{
	int i,j;
	char name[50];	
	cout<<"Nhap ho ten: ";
	gets(name);
	InTen(name,i,j);
	cout<<".";
	InHo(name, i , j);
	cout<<"@hoasen.edu.vn";
	
	
}

