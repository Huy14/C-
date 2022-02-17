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
}SV[5];


//READ VA WRITE TEXT
int ReadFileText()
{
		//OPEN AND READ TEXT
	ifstream SinhVien("C:/Users/admin/Desktop/sinhVien.txt");
	
	if(!SinhVien)
	{
		cerr<<"Khong the mo file !! "<<endl;
		return 0;
	}
}

	
int WriteFileText()
{
	ifstream SinhVien("C:/Users/admin/Desktop/sinhVien.txt");
	{
			for(int i = 1 ; i<5 ; i++)
		{
			SinhVien>>SV[i].ma>>SV[i].Ho>>SV[i].Ten;
		}
			
			for(int i = 1 ; i<5 ; i++)
		{
			cout<<SV[i].ma<<"\t"<<SV[i].Ho<<"\t"<<SV[i].Ten<<endl;
		}
	}

	SinhVien.close();
}

//NHAP VAO MA SO SINH VIEN
void MaSoSV(int maSo)
{
	cout<<"Vui long nhap vao ma so sinh vien can tim : ";
	cin>>maSo;
	cout<<endl;
}

//TIM SINH VIEN THEO MA SO
void MaSoLinear(int maSo , int count)
{
	for(int i = 1 ; i < 5 ; i++)
	{
		if ( maSo == SV[i].ma )
		{
			count ++;
			cout<<"Co "<<count<<" sinh vien "<<endl;
			cout<<"Tim thay sinh vien co Ma So la "<<maSo<<"\t"<<" Ten : "<<SV[i].Ten<<endl;
		}		
	}
	
	cout<<endl;
	
		if( count == 0 )
	{
		cout<<"Khong tim thay sinh vien co Ma So la "<<maSo<<endl;
	}
}

//NHAP TEN SINH VIEN
void NhapTenSV(char *TenSV)
{
	cout<<"Nhap vao ten sinh vien can tim : ";
	cin>>TenSV;
}

//TIM SINH VIEN THEO TEN
void TenLinear (char *TenSV , int count)
{

	
	for(int i = 1 ; i < 5 ; i++)
	{
		if ( strcmp( TenSV , SV[i].Ten ) == 0 )
		{
			count ++;
			cout<<"Co "<<count<<" sinh vien "<<endl;
			cout<<"Tim thay sinh vien co Ten la "<<TenSV<<endl;
			
		}		
	}
	
	cout<<endl;
	
		if( count == 0 )
	{
		cout<<"Khong tim thay sinh vien co ten la : "<<TenSV<<endl;
	}
}

//SORT TEN
void SapXep()
{
	char temp1 [10];
	char temp2 [10];
	
	for(int i = 1 ; i < 5 ; i++)
	{
		for(int j = i + 1 ; j < 5 ; j++)
		{
			if(strcmp(SV[i].Ho , SV[j].Ho) > 0)
			{
				strcpy(temp1 , SV[i].Ho);
				strcpy(SV[i].Ho , SV[j].Ho);
				strcpy(SV[j].Ho , temp1);
			}
			
			if(strcmp(SV[i].Ten , SV[j].Ten) > 0)
			{
				strcpy(temp2 , SV[i].Ten);
				strcpy(SV[i].Ten , SV[j].Ten);
				strcpy(SV[j].Ten , temp2);
			}
		}
	}
	
	cout<<"Sau khi sap xep : \n";
	for(int i = 1 ; i < 5 ; i++ )
	{
		cout<<SV[i].ma<<"\t"<<SV[i].Ho<<"\t"<<SV[i].Ten<<endl;
	}
	
}


int main()
{
	char TenSV[10];
	int count = 0;
	int maSo;
	
	ReadFileText();
	WriteFileText();
	
	MaSoSV(maSo);
	
	MaSoLinear( maSo ,  count);
	
	NhapTenSV(TenSV);
	TenLinear( TenSV , count);
	
	SapXep();
}

	
