#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>
using namespace std;

struct SV
{
	int ma;
	char Ho[15];
	char Ten[15];
}SV[4];


//READ VA WRITE TEXT
long ReadFileText( )
{
		//OPEN AND READ TEXT
	ifstream SinhVien("C:/Users/Gum1410/OneDrive/Desktop/sinhVien.txt");
	
	if(!SinhVien)
	{
		cerr<<"Khong the mo file !! "<<endl;
		return 0;
	}
}

	
long WriteFileText()
{
	ifstream SinhVien("C:/Users/Gum1410/OneDrive/Desktop/sinhVien.txt");
	{
			for(int i = 0 ; i<4 ; i++)
		{
			SinhVien>>SV[i].ma>>SV[i].Ho>>SV[i].Ten;
		}
			
			for(int i = 0 ; i<4 ; i++)
		{
			cout<<SV[i].ma<<"\t"<<SV[i].Ho<<"\t"<<SV[i].Ten<<endl;
		}
	}

	SinhVien.close();
}

//SORT TEN BUBBLE SORT
void SapXep( )
{
	char temp2 [10];
	
	for(int i = 0 ; i < 4 ; i++)
	{
		for(int j = 4-1 ; j > i ; j--)
		{
			if(strcmp(SV[j].Ten , SV[j-1].Ten) > 0)
			{
				strcpy(temp2 , SV[j].Ten);
				strcpy(SV[j].Ten , SV[j-1].Ten);
				strcpy(SV[j-1].Ten , temp2);
			}
		}
	}
	
	cout<<"Sau khi sap xep : \n";
	for(int i = 0 ; i < 4 ; i++ )
	{
		cout<<SV[i].ma<<"\t"<<SV[i].Ho<<"\t"<<SV[i].Ten<<endl;
	}
}

//NHAP TEN SINH VIEN
void NhapTenSV(char *TenSV)
{
	cout<<"Nhap vao ten sinh vien can tim : ";
	cin>>TenSV;
}

//BINAY SEARCH
int Binary(char *TenSV)
{
	for(int i = 0 ; i < 4 ; i++ )
	{
		 int left = 0;
		 int right = 4-1;
		
		int mid;
		
		while(left <= right)
		{
			mid = (left + right) / 2;
			
			if(strcmp(TenSV , SV[mid].Ten) == 0 )
			{
				return mid;
			}
			else if (strcmp(TenSV , SV[mid].Ten) < 0 )
			{
				left = mid + 1;
			}
			else if (strcmp(TenSV , SV[mid].Ten) > 0 )
			{
				right = mid - 1;
			}
			else return -1;
		}
	}
}

int BinaryDQ(char *TenSV , int left , int right )
{
	for(int i = 0 ; i < 4 ; i++ )
	{
		if(left > right)
		{
			return -1;
		}
		
		else
		{
			int mid = (left + right) / 2;
			if(strcmp(TenSV , SV[mid].Ten) == 0 )
			{
				return  mid;
			}
			else if (strcmp(TenSV , SV[mid].Ten) < 0 )
			{
				return  BinaryDQ(TenSV , mid+1 , right);
			}
			else if (strcmp(TenSV , SV[mid].Ten) > 0 )
			{
				return  BinaryDQ(TenSV , left, mid-1 );
			}
			else return -1;
		}
	}		
}

int main()
{
	
	ReadFileText();
	WriteFileText();
	
	cout<<endl;
	
	SapXep();
	cout<<endl;
	
	char TenSV[15];
	NhapTenSV(TenSV);

	cout<<endl;

	int kq1 = Binary(TenSV);
	
	if (kq1 == -1)
	{
		cout<<"Khong tim thay Sinh Vien ten "<<TenSV<<"trong danh sach!!/n";
	}
	else cout<<"Tim thay Sinh Vien ten "<<TenSV<<" trong danh sach tai vi tri "<<kq1+1<<endl;
	
	int left = 0;
	int right = 4-1;
	
	int kq2 = BinaryDQ(TenSV , left , right);
	

	if (kq2 == -1)
	{
		cout<<"Khong tim thay Sinh Vien ten "<<TenSV<<" trong danh sach!!/n";
	}
	else cout<<"Tim thay Sinh Vien ten "<<TenSV<<" trong danh sach tai vi tri "<<kq2+1<<endl;
			
}
