#include<conio.h>
#include<stdio.h>
#include<string.h>
#include <stdlib.h>  
#include <windows.h>
#include <time.h>

typedef struct ngayThang
{
	int ngay, thang , nam;
}ngayThang;

typedef struct SanPham
{
	int MaSP, soLuongTon;
	char tenSP[20];
	char loaiSP[20];
	float gia;
	ngayThang ngayNhapHang;
}SanPham;

struct Node
{
	SanPham info;
	Node *next;
};

typedef struct {
	Node* head;
} LIST;

void Initialize(LIST &L) {
	L.head = NULL;
}

Node* MakeNode(SanPham sp)
{
	Node *n=new Node;
	n->info=sp;
	n->next=NULL;
	return n;
}

void ThemSP(LIST &L, SanPham sp)
{
	Node *p;
	if(L.head==NULL)
		L.head=MakeNode(sp);
	else
	{
		p=L.head;
		while(p->next!=NULL)
			p=p->next;
		p->next=MakeNode(sp);
	}

}

bool IsEmpty(LIST list) {
	if (list.head == NULL) return true;
	return false;
}

void ReadFileToList(LIST &list)
{
	FILE           *in_file;    /* file for input */
	SanPham sp;
	int SIZE;
	in_file = fopen("sanPham.txt", "r");
    if (in_file == NULL) {
        fprintf(stderr, "Could not open file\n");
        exit(1);
    }
    fscanf(in_file, "%d\n",&SIZE);  
    
    for (int i=0;i<SIZE;i++)
    {
        fscanf(in_file, "%d\t%s\t%s\t%f\t%d\t%d/%d/%d\n",&sp.MaSP, &sp.tenSP,&sp.loaiSP,&sp.gia,&sp.soLuongTon, &sp.ngayNhapHang.ngay,&sp.ngayNhapHang.thang, &sp.ngayNhapHang.nam);  
		ThemSP(list,sp);
    }
    fclose(in_file);
  	
}

void In(LIST L)
{
	Node *sp=L.head;
	while(sp!=NULL)
	{
		printf("%d\t%s\t%s\t%f\t%d\t%d/%d/%d\n",sp->info.MaSP, sp->info.tenSP,sp->info.loaiSP,sp->info.gia,sp->info.soLuongTon, sp->info.ngayNhapHang.ngay,sp->info.ngayNhapHang.thang, sp->info.ngayNhapHang.nam);
		sp=sp->next;
	}
}

void InTheoLoai(LIST L)
{
	Node *sp=L.head;
	char loaiCanHienThi[20];
	printf("Nhap loai sp can hien thi:");
	fflush(stdin);
	gets(loaiCanHienThi);
	while(sp!=NULL)
	{
		if(strcmp(sp->info.loaiSP,loaiCanHienThi)==0)
			printf("%d\t%s\t%s\t%f\t%d\t%d/%d/%d\n",sp->info.MaSP, sp->info.tenSP,sp->info.loaiSP,sp->info.gia,sp->info.soLuongTon, sp->info.ngayNhapHang.ngay,sp->info.ngayNhapHang.thang, sp->info.ngayNhapHang.nam);
		sp=sp->next;
	}
}

void InSpNhapTu3Nam(LIST L)
{
	time_t curtime, oldtime;
	struct tm info;
	double diff_t;
	
	time(&curtime);
	Node *sp=L.head;
	while(sp!=NULL)
	{
		info.tm_year = sp->info.ngayNhapHang.nam - 1900;
	    info.tm_mon = sp->info.ngayNhapHang.thang - 1;
	    info.tm_mday = sp->info.ngayNhapHang.ngay-1;
	    oldtime = mktime(&info);
		diff_t = difftime(curtime, oldtime);
		if(diff_t/31556926>=3)
			printf("%d\t%s\t%s\t%f\t%d\t%d/%d/%d\n",sp->info.MaSP, sp->info.tenSP,sp->info.loaiSP,sp->info.gia,sp->info.soLuongTon, sp->info.ngayNhapHang.ngay,sp->info.ngayNhapHang.thang, sp->info.ngayNhapHang.nam);	
		sp=sp->next;
	}
}


SanPham taoSP()
{
	SanPham sp;	
	scanf("%d",&sp.MaSP);
	fflush(stdin);
	gets(sp.tenSP);
	fflush(stdin);
	gets(sp.loaiSP);
	scanf("%f",&sp.gia);
	scanf("%d",&sp.soLuongTon);
	scanf("%d",&sp.ngayNhapHang.ngay);
	scanf("%d",&sp.ngayNhapHang.thang);
	scanf("%d",&sp.ngayNhapHang.nam);
	return sp;
}

// q is previous of p
Node* SearchName(LIST list, char x[], Node* &q) {
    Node* p = list.head;
    while (p != NULL) {
		if (strcmp(p->info.tenSP, x)==0) break;
		q = p;
		p = p->next;
    }
    return p;
}

Node* SearchId(LIST list, int x, Node* &q) {
    Node* p = list.head;
    while (p != NULL) {
		if (p->info.MaSP == x) break;
		q = p;
		p = p->next;
    }
    return p;
}

bool DeleteHead(LIST &list) {
	if ( !IsEmpty(list) ) {
		Node* p = list.head;
		list.head = list.head->next;
		delete p; 
		return true;
	}
	return false;
}

bool DeleteAfter(LIST &list, Node* q) {
	if (q != NULL) {
		Node* p = q->next;
		if (p != NULL) {
			q->next = p->next;
			delete p; return true;
		}
	}
	return false;
}

bool DeleteNodeByName(LIST &list, char tenSp[]) {
	// 1. search with x --> p
	Node* q = NULL; // q is previous of p
	Node* p = SearchName(list, tenSp, q);
	if (p == NULL) return false; // not found
	// 2. delete p
	if (q == NULL) // p is head
		return DeleteHead(list);
	else // p is not head
		return DeleteAfter(list, q);
}

bool DeleteNodeById(LIST &list, int maSp) {
	// 1. search with x --> p
	Node* q = NULL; // q is previous of p
	Node* p = SearchId(list, maSp, q);
	if (p == NULL) return false; // not found
	// 2. delete p
	if (q == NULL) // p is head
		return DeleteHead(list);
	else // p is not head
		return DeleteAfter(list, q);
}



int main()
{
	int i,n;
	LIST list;
	SanPham sp;
	Node *p;
	
	Initialize(list);
	ReadFileToList(list);
	//In danh sach vua nhap
	printf(" \n Danh sach sp vua nhap : \n");
	In(list);
	getch();
	
	
	int lua_chon;
	do
    {
    	system("cls");
	    printf("Moi ban chon thao tac:");
	    printf("\n1: Them sp");
	    printf("\n2: Xoa sp theo ten");
	    printf("\n3: Xoa san pham theo ma");
	    printf("\n4: Hien thi thong tin sp theo loai");
		printf("\n5: Hien thi thong tin sp nhap hang cach hien tai 3 nam");
		printf("\n6: Hien thi thong tin cac sp");
	    printf("\n7: Thoat");
	    
	    printf("\nBan chon: ");
	    scanf("%d",&lua_chon);
	    switch (lua_chon)
	    {
	        case 1:
	        {
	        
	            ThemSP(list,taoSP());
	            break;
	        }
	       
	        case 2: 
	        {
	        	char tenSpCanXoa[20];
	        	printf("Nhap ten sp can xoa:");
	        	fflush(stdin);
	        	gets(tenSpCanXoa);
	        	DeleteNodeByName(list,tenSpCanXoa);
	        	break;
			}
 			
	        case 3:
	        {
	         	int maSpCanXoa;
	        	printf("Nhap ma sp can xoa:");
	        	scanf("%d",&maSpCanXoa);
	        	DeleteNodeById(list,maSpCanXoa);
	        	break;
	        }
	        case 4:
	        {
	            InTheoLoai(list);
	            break;
	        }
	        case 5:
	        {
	        	InSpNhapTu3Nam(list);
	        
	        	break;            
	        }
	        case 6:
	        {
	        	In(list);
	        	break;            
	        }

	        case 7: break;
	    }
	    getch();
	}while (lua_chon !=7);	


}

