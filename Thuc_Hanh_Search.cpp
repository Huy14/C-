#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

struct SV
{
	int ma;
	char Ho[15];
	char Ten[15];
}SV[5];

int main()
{
	ifstream SinhVien("C:/Users/admin/Desktop/sinhVien.txt");
	
	if(!SinhVien)
	{
		cerr<<"Khong the mo file !! "<<endl;
		return 0;
	}
	
	else
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
