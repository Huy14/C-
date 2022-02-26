#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

//CREATE LINKED LIST
typedef struct
{
	int MSSV;
	float Toan,Ly,Hoa,TB;
	char Ho[15];
	char Ten[15];
}SV;

typedef struct Node
{
	SV info;
	Node* pNext;
}Node;

typedef struct
{
	Node* pHead;
	Node* pTail;
}List;

//CREATE EMPTY LIST
void Init(List &list)
{
	list.pHead = NULL;
}

//CHECK LISTS ARE EMPTY
bool IsEmpty(List list)
{
	if(list.pHead == NULL)
	{
		return true;
	}
	
	return false;
}

//CREATE NEW NODE
Node* CreateNode(SV sv)
{
	Node* n = new Node;
	if (n != NULL)
	{
		n->info = sv;
		n->pNext = NULL;
	}
	
	return n;
}

//ADD DATA INTO LIST
void AddData(List &list , SV sv)
{
	Node* p;
	if(list.pHead == NULL)
	{
		list.pHead = CreateNode(sv);
	}
	else
	{
		p=list.pHead;
		while(p->pNext != NULL)
		{
			p = p->pNext;
		}
		p->pNext = CreateNode(sv);
	}
}

//READ AND WRITE TEX
int READWRITE(List &list , int &size , SV sv)
{
	ifstream DanhSach("D:/Vo_Tuan_Huy_22005416/sinhVien.txt");
	if(!DanhSach)
	{
		cerr<<"Khong the mo file !! "<<endl;
		return 0;
	}
	
	ifstream SinhVien("D:/Vo_Tuan_Huy_22005416/sinhVien.txt");
	{
			SinhVien>>size;
			for(int i = 0 ; i < size ; i++)
			{
				SinhVien>>sv.MSSV>>sv.Toan>>sv.Ly>>sv.Hoa>>sv.TB>>sv.Ho>>sv.Ten;
				AddData(list , sv );
			}
			
				Node* p = list.pHead;
				cout<<"MSSV\t"<<"Toan\t"<<"Ly\t"<<"Hoa\t"<<"TB\t"<<"Ho\t\t"<<"Ten"<<endl;
				cout<<size<<endl;
			while(p != NULL)
			{
					cout<<p->info.MSSV<<"\t"<<p->info.Toan<<"\t"<<p->info.Ly<<"\t"<<p->info.Hoa<<"\t"<<p->info.TB<<"\t"<<p->info.Ho<<"  \t"<<p->info.Ten<<"\t"<<endl;
					p = p->pNext;
			}
	}
	SinhVien.close();
	cout<<"\n\n";
}

//SINH VIEN DIEM TOAN < 8
void Toan(List list , int &size)
{
	Node* p = list.pHead;
	int count = 0;
	cout<<"SINH VIEN CO DIEM TOAN < 8 : \n";
	while( p != NULL )
	{
		if( p->info.Toan < 8.0 )
		{
			count ++;
				cout<<p->info.MSSV<<"\t"<<p->info.Toan<<"\t"<<p->info.Ly<<"\t"<<p->info.Hoa<<"\t"<<p->info.TB<<"\t"<<p->info.Ho<<"  \t"<<p->info.Ten<<"\t"<<endl;
		}
		p = p->pNext;
	}
	cout<<"Co "<<count<<" sinh vien \n\n";
}

//TINH DIEM TB
void Average(List &list , int size)
{
	Node* p = list.pHead;
	cout<<"SINH VIEN CO DTB : \n";
	cout<<size<<endl;
	while( p != NULL )
	{
		{
			p->info.TB = (p->info.Toan + p->info.Ly + p->info.Hoa) / 3;
			cout<<p->info.MSSV<<"\t"<<p->info.Toan<<"\t"<<p->info.Ly<<"\t"<<p->info.Hoa<<"\t"<<p->info.TB<<"\t"<<p->info.Ho<<"  \t"<<p->info.Ten<<"\t"<<endl;
		}
		p = p->pNext;
	}
	cout<<"\n\n";
}

//DEM SINH VIEN DTB < 7.0
void CountAverage(List list , int &size)
{
	Node* p = list.pHead;
	int count = 0;
	cout<<"SINH VIEN CO DTB < 7.0 : \n";
	while( p != NULL )
	{
			if( p->info.TB < 7.0 )
			{
				count++;
				cout<<p->info.MSSV<<"\t"<<p->info.Toan<<"\t"<<p->info.Ly<<"\t"<<p->info.Hoa<<"\t"<<p->info.TB<<"\t"<<p->info.Ho<<"  \t"<<p->info.Ten<<"\t"<<endl;	
			}
		p = p->pNext;
	}
	cout<<"Co "<<count<<" sinh vien DTB < 7.0";
	cout<<"\n\n";
}

//SINH VIEN LY CAO NHAT
void MaxLy(List list , int &size , Node* &q)
{
	Node* p = list.pHead;
	float Max = p->info.Ly;
	cout<<"SINH VIEN CO DIEM LY CAO NHAT  : \n";
	while( p != NULL )
	{
			if( Max < p->info.Ly )
			{
				Max = p->info.Ly;
				cout<<p->info.MSSV<<"\t"<<p->info.Toan<<"\t"<<p->info.Ly<<"\t"<<p->info.Hoa<<"\t"<<p->info.TB<<"\t"<<p->info.Ho<<"  \t"<<p->info.Ten<<"\t"<<endl;	
			}
		q = p;
		p = p->pNext;
	}
	cout<<"\n\n";
}

//SINH VIEN HOA THAP NHAT
void MinHoa(List list , int &size , Node* &q)
{
	Node* p = list.pHead;
	int count = 0;
	float Min = p->info.Hoa;
	cout<<"SINH VIEN CO DIEM HOA THAP NHAT  : \n";
	while( p != NULL )
	{
			if( Min > p->info.Hoa )
			{
				Min = p->info.Hoa;
				cout<<p->info.MSSV<<"\t"<<p->info.Toan<<"\t"<<p->info.Ly<<"\t"<<p->info.Hoa<<"\t"<<p->info.TB<<"\t"<<p->info.Ho<<"  \t"<<p->info.Ten<<"\t"<<endl;	
			}
		q = p;
		p = p->pNext;
	}
	cout<<"\n\n";
}
int main()
{
	int size;
	List list;
	SV sv;
	Node* q;
	
	Init(list);
	IsEmpty(list);
	CreateNode(sv);
	READWRITE(list , size , sv);
	AddData(list , sv);

	Toan(list , size);
	Average(list , size);
	CountAverage(list, size);
	MaxLy(list , size , q);
	MinHoa(list , size , q);
	
}
	
	
