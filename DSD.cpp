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
int READ(List &list , int &size , SV sv)
{
	ifstream DanhSach("C:/Users/admin/Desktop/sinhVien.txt");
	if(!DanhSach)
	{
		cerr<<"Khong the mo file !! "<<endl;
		return 0;
	}
}
int WRITE(List &list , int &size , SV sv)
{
	ifstream SinhVien("C:/Users/admin/Desktop/sinhVien.txt");
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

//SWAP 2 NODES
void swap(struct Node* a , struct Node* b)
{
	SV temp;
	temp = a->info;
	a->info = b->info;
	b->info = temp;
}

//SORT MSSV INTERCHANGE SORT
void SortMssv(List &list)
{
	Node* p;
	Node* q;
	
		for( p = list.pHead ; (p->pNext) != NULL ; p = p->pNext)
		{
			for(q = p->pNext ; q->pNext != NULL ; q = q->pNext)
			{
				if(p->info.MSSV > q->info.MSSV)
				{
					swap(p,q);
				}
			}
			cout<<p->info.MSSV<<"\t"<<p->info.Toan<<"\t"<<p->info.Ly<<"\t"<<p->info.Hoa<<"\t"<<p->info.TB<<"\t"<<p->info.Ho<<"  \t"<<p->info.Ten<<"\t"<<endl;	
		}
	cout<<"\n\n";
}

int Ouput1(List &list , int &size , SV sv)
{
	ofstream Output1 ("C:/Users/admin/Desktop/Output1.txt");
	Output1<<"MSSV\t"<<"Toan\t"<<"Ly\t"<<"Hoa\t"<<"TB\t"<<"Ho\t\t"<<"Ten"<<endl;
	
	
	Node* p = list.pHead;
	while( p != NULL )
	{
		Output1<<p->info.MSSV<<"\t"<<p->info.Toan<<"\t"<<p->info.Ly<<"\t"<<p->info.Hoa<<"\t"<<p->info.TB<<"\t"<<p->info.Ho<<"  \t"<<p->info.Ten<<"\t"<<endl;
		p = p->pNext;
	}
	
	Output1.close();
	return 0;
}
//SORT TEN INTERCHANGE SORT
void SortTen(List &list)
{
	Node* p;
	Node* q;
		for( p = list.pHead ; (p->pNext) != NULL ; p = p->pNext)
		{
			for(q = p->pNext ; q->pNext != NULL ; q = q->pNext)
			{
				if( strcmp(p->info.Ten , q->info.Ten) > 0 )
				{
					swap(p,q);
				}
			}
			cout<<p->info.MSSV<<"\t"<<p->info.Toan<<"\t"<<p->info.Ly<<"\t"<<p->info.Hoa<<"\t"<<p->info.TB<<"\t"<<p->info.Ho<<"  \t"<<p->info.Ten<<"\t"<<endl;	
		}
		cout<<"\n\n";
}

int Ouput2(List &list , int &size , SV sv)
{
	ofstream Output2 ("C:/Users/admin/Desktop/Output2.txt");
	Output2<<"MSSV\t"<<"Toan\t"<<"Ly\t"<<"Hoa\t"<<"TB\t"<<"Ho\t\t"<<"Ten"<<endl;

	Node* p = list.pHead;
	while( p != NULL )
	{
		Output2<<p->info.MSSV<<"\t"<<p->info.Toan<<"\t"<<p->info.Ly<<"\t"<<p->info.Hoa<<"\t"<<p->info.TB<<"\t"<<p->info.Ho<<"  \t"<<p->info.Ten<<"\t"<<endl;
		p = p->pNext;
	}
	
	Output2.close();
	return 0;
}

//DELETE MSSV
Node *Search2(List list , int &MSSV , Node* &q)
{
	Node* p = list.pHead;
	while(p != NULL)
	{
		if(p->info.MSSV == MSSV)
		{
			break;
		}
		q = p;
		p = p->pNext;
	}
	return p;
}

bool DeleteHead(List &list)
{
	if(!IsEmpty(list))
	{
		Node *p = list.pHead;
		list.pHead = list.pHead->pNext;
		delete p;
		return true;
	}
	return false;
}

bool DeleteAfter(List &list , Node* q)
{
	if(q != NULL)
	{
		Node* p = q->pNext;
		if(p != NULL)
		{
			q->pNext = p->pNext;
			delete p;
			return true;
		}
	}
	return false;
}
int DeleteMssv(List &list , int &MSSV)
{
	Node* q = NULL;
	Node* p = Search2(list , MSSV , q);
	
	cout<<"DS SINH VIEN SAU KHI XOA  : \n";
	if(p == NULL)
	{
		return false;
	}
	if(q == NULL)
	{
		return DeleteHead(list);
	}else 
		return DeleteAfter(list , q);
	cout<<"\n\n";
}

//INSERT SINH VIEN
int Insert(List &list , SV info , Node *q , int &MSSV )
{
	Node* p = CreateNode(info);
	if( p != NULL )
	{
		p->pNext = q->pNext;
		q->pNext = p;
	}
	return p;
}

void NhapThongTin(List &list , SV sv)
{
	
	cout<<"Nhap MSSV : ";cin>>sv.MSSV;
	fflush(stdin);
	cout<<"Nhap vao diem Toan , Ly , Hoa : ";cin>>sv.Toan;cin>>sv.Ly;cin>>sv.Hoa;
	fflush(stdin);
	cout<<"Nhap vao Ho : ";gets(sv.Ho);
	fflush(stdin);
	cout<<"Nhap vao Ho : ";gets(sv.Ten);
	
	Node *p = new Node;
	p = CreateNode(sv);

}
int main()
{
	int MSSV;
	int size;
	List list;
	SV sv;
	Node* q;
	Node* p;
	
	Init(list);
	IsEmpty(list);
	CreateNode(sv);

	READ(list , size , sv);
	WRITE(list , size , sv);
	
	Toan(list , size);
	Average(list , size);
	CountAverage(list, size);
	MaxLy(list , size , q);
	MinHoa(list , size , q);
	
	cout<<"SINH VIEN SAU KHI SORT THEO MSSV : \n";
	SortMssv(list);
	Ouput1(list , size , sv);
	cout<<"SINH VIEN SAU KHI SORT THEO TEN : \n";
	SortTen(list);
	Ouput2(list , size , sv);
	
	cout<<"Nhap vao MSSV can xoa : ";cin>>MSSV;
	DeleteMssv(list , MSSV);
	SortMssv(list);
	
}
