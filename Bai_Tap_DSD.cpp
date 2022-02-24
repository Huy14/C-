#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include<cstring>
#define MAX 100
using namespace std;

typedef struct DanhSach
{
	int MSSV;
	float Toan,Ly,Hoa,TB;
	char Ten[25];
	char Ho[25];
}Item;

typedef struct
{
	Item DS[MAX];
	int n; 
}List;

//DOC VA GHI FILE DANH SACH
int ReadFile(List &list)
{
		//OPEN AND READ TEXT
	ifstream DanhSach("C:/Users/admin/Desktop/input.txt");
	
	if(!DanhSach)
	{
		cerr<<"Khong the mo file !! "<<endl;
		return 0;
	}
}

int WriteFileText(List &list)
{
	ifstream DanhSach("C:/Users/admin/Desktop/input.txt");
	{
			DanhSach>>list.n;
			for(int i = 1 ; i<=list.n ; i++)
		{
			DanhSach>>list.DS[i].MSSV>>list.DS[i].Toan>>list.DS[i].Ly>>list.DS[i].Hoa>>list.DS[i].TB>>list.DS[i].Ho>>list.DS[i].Ten;
		}
		
		cout<<"MSSV\t"<<"Toan\t"<<"Ly\t"<<"Hoa\t"<<"TB\t"<<"Ho\t\t"<<"Ten"<<endl;
		cout<<list.n<<endl;
		cout<<"____________________________________________________________________________________________\n\n";
			for(int i = 1 ; i<=list.n ; i++)
		{
			cout<<list.DS[i].MSSV<<"\t"<<list.DS[i].Toan<<"\t"<<list.DS[i].Ly<<"\t"<<list.DS[i].Hoa<<"\t"<<"\t  "<<list.DS[i].Ho<<"\t"<<list.DS[i].Ten<<endl;
		}
	}

	DanhSach.close();
}

void Init(List &list)
{
	list.n = 0;
}

void Average(List &list)
{
	for(int i = 1 ; i<=list.n ; i++)
	{
		list.DS[i].TB = (list.DS[i].Toan + list.DS[i].Ly + list.DS[i].Hoa) /3;
	}
}


//DANH SACH SINH VIEN TOAN < 8
int ToanBeHon8(List list)
{
	cout<<"DANH SACH SINH VIEN DIEM TOAN DUOI 8 :\n";
	cout<<"MSSV\t"<<"Toan\t"<<"Ly\t"<<"Hoa\t"<<"TB\t"<<"Ho\t\t"<<"Ten"<<endl;
	cout<<"____________________________________________________________________________________________\n";
	
	for(int i = 1 ; i<=list.n ; i++)
	{
		if(list.DS[i].Toan < (8*1.0) )
		{
			Average(list);
			cout<< list.DS[i].MSSV<<"\t"<<list.DS[i].Toan<<"\t"<<list.DS[i].Ly<<"\t"<<list.DS[i].Hoa<<"\t"<<list.DS[i].TB<<"\t  "<<list.DS[i].Ho<<"\t"<<list.DS[i].Ten<<endl;
		}
	}
	fflush(stdin);
}

//DIEM TB 3 MON
void DTB(List list)
{
	cout<<"DANH SACH SINH VIEN DIEM TRUNG BINH :\n";
	
		cout<<"MSSV\t"<<"Toan\t"<<"Ly\t"<<"Hoa\t"<<"TB\t"<<"Ho\t\t"<<"Ten"<<endl;
		cout<<"____________________________________________________________________________________________\n\n";
			for(int i = 1 ; i<=list.n ; i++)
		{
				Average(list);
			cout<< list.DS[i].MSSV<<"\t"<<list.DS[i].Toan<<"\t"<<list.DS[i].Ly<<"\t"<<list.DS[i].Hoa<<"\t"<<list.DS[i].TB<<"\t  "<<list.DS[i].Ho<<"\t"<<list.DS[i].Ten<<endl;
		}
	fflush(stdin);
}

//DEM XEM CO BAO NHIEU SINH VIEN DTB > 7.0
void Dem(List list)
{
	int count = 0;
	cout<<"DANH SACH SINH VIEN DIEM TRUNG BINH > 7.0 :\n";
	cout<<"____________________________________________________________________________________________\n\n";
	
	
			for(int i = 0 ; i<=list.n ; i++)
			{
				if( list.DS[i].TB > (7*1.0) )
				{
					count++;
					Average(list);	
					cout<< list.DS[i].MSSV<<"\t"<<list.DS[i].Toan<<"\t"<<list.DS[i].Ly<<"\t"<<list.DS[i].Hoa<<"\t"<<list.DS[i].TB<<"\t  "<<list.DS[i].Ho<<"\t"<<list.DS[i].Ten<<endl;
				}
			}
			cout<<"Co "<<count<<" sinh vien co dtb > 7.0";
			fflush(stdin);
}

//TIM THONG TIN DIEM LY CAO NHAT
void MaxLy(List list)
{
	float Max = list.DS[1].Ly;
	cout<<"DANH SACH SINH VIEN LY CAO NHAT :\n";

	
	cout<<"Sinh vien co diem ly cao nhat la :\n";
	for(int i = 2 ; i<=list.n ; i++)
	{
		if( Max < list.DS[i].Ly )
		{
			Average(list);
			Max = list.DS[i].Ly;
			cout<< list.DS[i].MSSV<<"\t"<<list.DS[i].Toan<<"\t"<<list.DS[i].Ly<<"\t"<<list.DS[i].Hoa<<"\t"<<list.DS[i].TB<<"\t  "<<list.DS[i].Ho<<"\t"<<list.DS[i].Ten<<endl;
		}
	}
	fflush(stdin);		
}

//HAM XOA SINH VIEN
void XoaSinhVien(List list)
{
	int x;
	
	
	cout<<"Nhap vao MSSV can xoa : ";cin>>x;
	for(int i = 1 ; i <= list.n ; i++)
	{
		if( x == list.DS[i].MSSV )
		{
				list.DS[i] = list.DS[i+1];
		}
		Average(list);
		cout<< list.DS[i].MSSV<<"\t"<<list.DS[i].Toan<<"\t"<<list.DS[i].Ly<<"\t"<<list.DS[i].Hoa<<"\t"<<list.DS[i].TB<<"\t  "<<list.DS[i].Ho<<"\t"<<list.DS[i].Ten<<endl;
		list.n--;
	}
	fflush(stdin);
}

//HAM XOA SINH VIEN HOA < 6.0
void XoaSinhVienHoa(List list)
{
	for(int i = 1 ; i <= list.n ; i++)
	{
		if( list.DS[i].Hoa < (6 * 1.0) )
		{
				list.DS[i] = list.DS[i+1];
		}
		
			Average(list);
			cout<< list.DS[i].MSSV<<"\t"<<list.DS[i].Toan<<"\t"<<list.DS[i].Ly<<"\t"<<list.DS[i].Hoa<<"\t"<<list.DS[i].TB<<"\t  "<<list.DS[i].Ho<<"\t"<<list.DS[i].Ten<<endl;
			list.n--;
	}
	fflush(stdin);
}

//THEM THONG TIN SINH VIEN
void ThemSinhVien(List &list)
{

	int them;
	
	cout<<"Nhap vao vi tri can them sinh vien : ";cin>>them;
	if( them >= 1 && them <= list.n)
	{
		
			list.n++;
			
				
			for(int i = list.n ; i > them ; i-- )
			{
				list.DS[i] = list.DS[i-1];
				strcpy(list.DS[i].Ho , list.DS[i-1].Ho);
				strcpy(list.DS[i].Ten , list.DS[i-1].Ten);
			}
			
			cout<<"Nhap MSSV : ";cin>>list.DS[them].MSSV;
			cout<<"Nhap Diem Toan : ";cin>>list.DS[them].Toan;
			cout<<"Nhap Diem Ly : ";cin>>list.DS[them].Ly;
			cout<<"Nhap Diem Hoa : ";cin>>list.DS[them].Hoa;
			fflush(stdin);
			cout<<"Nhap Ho : ";gets(list.DS[them].Ho);
			cout<<"Nhap Ten: ";gets(list.DS[them].Ten);
					
			cout<<"MSSV\t"<<"Toan\t"<<"Ly\t"<<"Hoa\t"<<"TB\t"<<"Ho\t\t"<<"Ten"<<endl;
			cout<<list.n<<endl;
			for(int i = 1; i <= list.n ; i++)
			{
				Average(list);
				cout<< list.DS[i].MSSV<<"\t"<<list.DS[i].Toan<<"\t"<<list.DS[i].Ly<<"\t"<<list.DS[i].Hoa<<"\t"<<list.DS[i].TB<<"\t  "<<list.DS[i].Ho<<"\t"<<list.DS[i].Ten<<endl;
			}
				
	}
	fflush(stdin);
}
	



//KIEM THONG TIN SINH VIEN
void KiemSV(List list)
{
	char temp[25];
	int count;
	cout<<"Nhap vao ten sv muon tim : ";cin>>(temp);
	for(int i=1 ; i<=list.n ; i++)
	{
		if(strcmp(list.DS[i].Ten , temp ) == 0 )
		{
			cout<< list.DS[i].MSSV<<"\t"<<list.DS[i].Toan<<"\t"<<list.DS[i].Ly<<"\t"<<list.DS[i].Hoa<<"\t"<<list.DS[i].TB<<"\t  "<<list.DS[i].Ho<<"\t"<<list.DS[i].Ten<<endl;
			count++;
		}
				
	}cout<<endl;
	
		if(count==0)
		{
			cout<<"Khong tim thay sv \n";
		}
		fflush(stdin);
}


//LUU THONG TIN FILE
void LuuThongTin(List &list)
{
	FILE *f;
	f = fopen("C:/Users/admin/Desktop/input.txt" , "wt");
	if(f == NULL)
		cout<<"Tao file khong thanh cong";
	else
		{
			cout<<list.n<<endl;
			cout<<"Tao file thanh cong\n";
			for(int i=1 ; i<=list.n ; i++)
			{
				cout<< list.DS[i].MSSV<<"\t"<<list.DS[i].Toan<<"\t"<<list.DS[i].Ly<<"\t"<<list.DS[i].Hoa<<"\t"<<list.DS[i].TB<<"\t  "<<list.DS[i].Ho<<"\t"<<list.DS[i].Ten<<endl;
				cout<<endl;	
			}
		}
		int fclose(FILE *f);
		cout<<endl;
		
}

//XOA FILE
void XoaFile(List &list)
{
	{
	  if( remove( "C:/Users/admin/Desktop/input.txt" ) != 0 )
	    perror( "Error deleting file" );
	  else
	    puts( "File successfully deleted" );
	}
}
	
int main()
{
	List list;
	//Init(list);
	int key;
	bool DaNhap;
	bool ended = false;
	while(!ended){
		cout<<"****************************************************\n";
		cout<<"		CHUONG TRINH DANH SACH SINH VIEN		\n";
		cout<<"		1.DOC VA GHI FILE DS SINH VIEN		\n";
		cout<<"		2.TINH DIEM TRUNG BINH 3 MON		\n";
		cout<<"		3.SINH VIEN DIEM TOAN < 8.0			\n";
		cout<<"		4.DEM SO SINH VIEN DTB > 7.0		\n";
		cout<<"		5.SINH VIEN CO DIEM LY CAO NHAT		\n";
		cout<<"		6.THEM SINH VIEN						\n";
		cout<<"		7.XOA SINH VIEN						\n";
		cout<<"		8.XOA SINH VIEN	HOA < 6.0					\n";
		cout<<"		9.TIM KIEM SINH VIEN					\n";
		cout<<"		10.LUU THONG TIN FILE					\n";
		cout<<"		11.XOA FILE					\n";
		cout<<"		12.Exit								\n";
		cout<<"****************************************************\n";
		
		cout<<"Nhap vao lua chon tren : ";cin>>key;
		switch(key)
		{
			case 1 :
				Init(list);
				ReadFile(list);
				WriteFileText(list);
				DaNhap = true;
				cout<<endl;
				break;
			case 2 :	
				if(DaNhap)
				{
					DTB(list);
					cout<<endl;
				}
				else cout<<"Xuat Danh Sach SV Truoc !!\n";
				break;
			case 3 :
				if(DaNhap)
				{
					ToanBeHon8(list);
					cout<<endl; 
				}
				else cout<<"Xuat Danh Sach SV Truoc !!\n";
				break;
			case 4 :
				if(DaNhap)
				{
					Dem(list);
					cout<<endl;
				}
				else cout<<"Xuat Danh Sach SV Truoc !!\n";
				break;
			case 5 :
				if(DaNhap)
				{
					MaxLy(list);
					cout<<endl;
				}
				else cout<<"Xuat Danh Sach SV Truoc !!\n";
				break;
			case 6 :
				if(DaNhap)
				{
					ThemSinhVien(list);
					cout<<endl;
				}
				else cout<<"Xuat Danh Sach SV Truoc !!\n";
				break;
			case 7 :
				if(DaNhap)
				{
					XoaSinhVien(list);
					cout<<endl;
				}
				else cout<<"Xuat Danh Sach SV Truoc !!\n";
				break;
			case 8 :
				if(DaNhap)
				{
					XoaSinhVienHoa(list);
					cout<<endl;
				}
				else cout<<"Xuat Danh Sach SV Truoc !!\n";
				break;
			case 9 :
				if(DaNhap)
				{
					KiemSV(list);
					cout<<endl;
				}
				else cout<<"Xuat Danh Sach SV Truoc !!\n";
				break;
			case 10 :
				if(DaNhap)
				{
					LuuThongTin(list);
					cout<<endl;
				}
				else cout<<"Xuat Danh Sach SV Truoc !!\n";
				break;
			case 11 :
				if(DaNhap)
				{
					XoaFile(list);
					cout<<endl;
				}
				else cout<<"Xuat Danh Sach SV Truoc !!\n";
				break;
			case 12 :
				exit(0);
			default :
				cout<<"Lua chon khong hop le !!!\n";
				break;
		}
	}
	
}
