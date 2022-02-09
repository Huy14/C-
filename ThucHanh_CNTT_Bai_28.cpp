#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
int Prime(int n)
{
	if(n <= 2)
	{
		return 0;
	} 
	else 
	{
			for(int i=2 ; i<=sqrt(n) ; i++)
		{
			 if(n % i == 0) {
				return 0;	
			}
			
		}
		
	}
		return 1;
}
int main()
{
	FILE *f1 , *f2;
	int n;
	f1 = fopen("D:/DAI HOC HOA SEN/BAITAP THUCHANH CNTT/Tuan 1/File Text Bai 28/bai28songuyento.text" , "wt");
	f2 = fopen("D:/DAI HOC HOA SEN/BAITAP THUCHANH CNTT/Tuan 1/File Text Bai 28/bai28_SoNguyen.text" , "rt");
	if( f1 == NULL || f2 == NULL)
	{
		printf("Tao va doc file khong thanh cong");
	}
	else
	{
		while ( !feof(f2) ) // foef return n0n-0 if f2 in on EOF otherwise 0
		{
			fscanf(f2, "%d" , &n);
			if (Prime(n))
			{
				fprintf(f1 , "%d " ,n );
			}
		}
		printf("Tao va doc file thanh cong");
	}
	fclose(f1); 
	fclose(f2);
	
}

