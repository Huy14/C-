#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
void TaoText(){
	FILE *f;
	f = fopen("D:/DAI HOC HOA SEN/BAITAP THUCHANH CNTT/Tuan 1/File Text Bai 27/bai27.text" , "wt");
	if ( f == NULL )
	{
		printf("Tao file khong thanh cong\n");
	}
	else
	{
		srand(time(NULL));
		for(int i = 1 ; i<=100 ; i++)
		{
			fprintf(f, "%d " , rand() % 100);
			if (i % 10 == 0)
			{
				fprintf(f , "\n");
			}
		}
		printf("Tao file thanh cong \n");
	}
	fclose(f);
}

void XoaText(){
	 if( remove( "D:/DAI HOC HOA SEN/BAITAP THUCHANH CNTT/Tuan 1/File Text Bai 27/bai27.text" ) != 0 )
	    perror( "Error deleting file\n" );
	  else
	    printf( "File successfully deleted\n" );
}
int main()
{
	int n;
	bool key=false;
	while(!key)
		{
			printf("1.Tao file \n");
			printf("2.Xoa file \n");
			printf("3.Thoat \n");
			printf("---------- \n");
			printf("Nhap vao lua chon: \n");
			scanf("%d" , &n);
			
				switch(n)
				{
					case 1 : 
					TaoText();
					printf("\n");
					break;
					
					case 2 :
					XoaText();
					printf("\n");
					break;
					
					case 3:
					exit(0);
				}
		}			
}
		
	


