#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

struct SV{
	char Ho_Ten[50];
	int Tuoi;
	float DTB;
}s[20];

void NhapThongTin(int n)
{
	for(int i=0 ; i<n ;i++)
	{
		cout<<"Sinh Vien No. "<<i+1<<endl;
		fflush(stdin);
		cout<<"Ho va Ten : ";gets(s[i].Ho_Ten);
		fflush(stdin);
		cout<<"Tuoi : ";cin>>s[i].Tuoi;
		cout<<"Diem Trung Binh : ";cin>>s[i].DTB;
		cout<<endl;
	}
}
void InThongTin(int n)
{
	for(int i=0 ; i<n ;i++)
	{
		cout<<"Sinh Vien No. "<<i+1<<endl;
		cout<<"Ho va Ten : ";puts(s[i].Ho_Ten);
		cout<<"Tuoi : "<<s[i].Tuoi<<endl;
		cout<<"Diem Trung Binh : "<<s[i].DTB;
		cout<<endl;
	}
}
void SapXepDiem(int n)
{
	int temp;
	cout<<"Sap xep theo DTB : \n";
	for(int i=0 ; i<n-1 ;i++)
	{
		for(int j=0+i; j<n ; j++)
		{
			if(s[i].DTB<s[j].DTB)
			{
				temp=s[i].DTB;
				s[i].DTB=s[j].DTB;
				s[j].DTB=temp;
			}
		}
	}
	
	for(int i=0 ; i<n ;i++)
	{
		cout<<"Sinh Vien No. "<<i+1<<endl;
		cout<<"Ho va Ten : ";puts(s[i].Ho_Ten);
		cout<<"Tuoi : "<<s[i].Tuoi<<endl;
		cout<<"Diem Trung Binh : "<<s[i].DTB;
		cout<<endl;
	}
	
}

void TimKiem(int n)
{
	char Ten[50];
	int count;
	cout<<"Nhap Ho Ten ban can tim : ";cin>>Ten;
	fflush(stdin);
	for(int i=0 ; i<n ;i++)
	{
		if (strstr(s[i].Ho_Ten,Ten))
		{
			cout<<"Sinh Vien No. "<<i+1<<endl;
			cout<<"Ho va Ten : ";puts(s[i].Ho_Ten);
			cout<<"Tuoi : "<<s[i].Tuoi<<endl;
			cout<<"Diem Trung Binh : "<<s[i].DTB;
			cout<<endl;
			count++;
		}
	}cout<<endl;
	
	if(count==0)
	{
		cout<<"Ko tim thay sinh vien \n";
	}
}

int main()
{
	int number;
	int key;
	bool ended = false;
	while(!ended)
	{
	cout<<"=========================================================="<<endl;
	cout<<" 1.NhapThongTin					"<<endl;
	cout<<" 2.InThongTin					"<<endl;
	cout<<" 3.SapXepTheoDTB					"<<endl;
	cout<<" 4.TimSVTheoHovaTen				"<<endl;
	cout<<" 5.Exit							"<<endl;
	cout<<"==========================================================="<<endl;
	cout<<"Enter an option : ";cin>>key;
	
	switch(key)
	{
		case 1 : 
			cout<<"Nhap vao so luong Sinh Vien : ";cin>>number;
			NhapThongTin(number);
		break;
		
		case 2 : 
			InThongTin(number);
		break;
		
		case 3 : 
			SapXepDiem(number);
		break;
		
		case 4 :
			TimKiem(number);
		break;
		
		case 5 :
			exit(0);
			
		default : 
			cout<<"Ko hop le \n";
			 
	}
	}
	
}

