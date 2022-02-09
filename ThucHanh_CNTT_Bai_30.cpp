#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<fstream>
using namespace std;
struct Sach{
	char Ma_Sach[20];
	int So_Luong;
	char Ten[50];
}s[20];

void NhapSach(int n)
{
	for(int i=0 ; i<n ; i++)
	{
		cout<<"Nhap thong tin sach\n";
		cout<<"Sach No. "<<i+1;
		cout<<endl;
		fflush(stdin);
		cout<<"Ten sach : ";gets(s[i].Ten);
		cout<<"Ma sach : ";gets(s[i].Ma_Sach);
		cout<<"So luong : ";cin>>s[i].So_Luong;
		cout<<"___________________________________\n";
	}cout<<endl;
}

void InSach(int n)
{
	for(int i=0 ; i<n ; i++)
	{
		cout<<"Sach No. "<<i+1;
		cout<<endl;
		cout<<"Ten sach : ";puts(s[i].Ten);
		cout<<endl;
		cout<<"Ma sach : ";puts(s[i].Ma_Sach);
		cout<<endl;
		cout<<"So luong : "<<s[i].So_Luong;
		cout<<endl;
		cout<<"___________________________________\n";
	}cout<<endl;
}

void KiemDanhSach(int n)
{
	char temp[50];
	int count;
	cout<<"Nhap vao ten sach muon tim : ";cin>>(temp);
	for(int i=0 ; i<n ; i++)
	{
		if(strcmp(s[i].Ten , temp ) == 0 )
		{
				cout<<"Sach No. "<<i+1<<endl;
				cout<<"Ten sach : ";puts(s[i].Ten);
				cout<<"Ma sach : ";puts(s[i].Ma_Sach);
				cout<<endl;
				cout<<"So luong : "<<s[i].So_Luong;
				cout<<endl;
				cout<<"___________________________________\n";
				count++;
		}cout<<endl;
		if(count==0)
		{
			cout<<"Khong tim thay sach\n";
		}
	}
	
}

void LuuThongTin(int n)
{
	FILE *f;
	f = fopen("D:/DAI HOC HOA SEN/BAITAP THUCHANH CNTT/Tuan 1/File Text Bai 30/Thong_tin_sach.text" , "wt");
	if(f == NULL)
		cout<<"Tao file khong thanh cong";
	else
		{
			cout<<"Tao file thanh cong\n";
			for(int i=0 ; i<n ; i++)
			{
				fprintf(f,"Ten sach %d : [%s] ; Ma So : [%s] ; So Luong : [%d]\n",i+1,s[i].Ten,s[i].Ma_Sach,s[i].So_Luong);
				cout<<endl;	
			}
		}
		int fclose(FILE *f);
		cout<<endl;
}

void XoaFile(int n)
{
	{
	  if( remove( "D:/DAI HOC HOA SEN/BAITAP THUCHANH CNTT/Tuan 1/File Text Bai 30/Thong_tin_sach.text" ) != 0 )
	    perror( "Error deleting file" );
	  else
	    puts( "File successfully deleted" );
	}
}



int main()
{
	int key, number;
	bool ended = false;
	bool DaNhap;
	while(!ended)
	{
	cout<<"====================================\n";
	cout<<"1.Nhap thong tin sach                \n";
	cout<<"2.In thong tin sach                  \n";
	cout<<"3.Kiem thong tin sach                  \n";
	cout<<"4.Luu thong tin sach vao file text     \n";
	cout<<"5.Xoa thong tin sinh vien trong file text\n";
	cout<<"6.Exit									\n";
	cout<<"====================================\n";
	cout<<"Nhap vao lua chon tren : ";cin>>key;
	cout<<endl;
	
	switch(key)
	{
		case 1 : 
			cout<<"Nhap vao so luong sach : ";cin>>number;
			NhapSach(number);
			DaNhap = true;
		break;
		
		case 2 :
			if(DaNhap)
			{
				InSach(number);
			}else cout<<"Nhap thong tin sach truoc!!!";
			cout<<endl;
		break;
		
		case 3 : 
			if(DaNhap)
			{
				KiemDanhSach(number);
			}else cout<<"Nhap thong tin sach truoc!!!";
			cout<<endl;
		break;
		
		case 4 :
			if(DaNhap)
			{
				LuuThongTin(number);
			}else cout<<"Nhap thong tin sach truoc!!!";
			cout<<endl;
		break;
		
		case 5 :
			XoaFile(number);
			cout<<"Only can be deleted when you re-use the program";
			cout<<endl;
		break;
		
		case 6 : 
			cout<<"Xin cam on\n";
			exit(0);
			break;
			
		default :
			cout<<"Lua chon khong hop le\n";
		
	}
	
	
	}
}

