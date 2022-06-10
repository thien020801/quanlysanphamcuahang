#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
struct banhang
{
	int masp;
	char tensp[20];
	char maloaisp[20];
	int ngaysx,thangsx,namsx;
	int ngaysd,thangsd,namsd;
};

struct banhang a[200];



void nhap(struct banhang a[],int &n)
{
	FILE*f;
	char ch;
	int i=0;
	f=fopen("d:\\vanban.txt","wt");
	if(f==NULL)
		printf("khong tao duoc file");
	else 
		printf("Ban muon nhap bao nhieu san pham: ");
		scanf("%d",&n);
			do
			{
				fflush(stdin);
				printf("Ma hang: ");
				scanf("%d",&a[i].masp);
				fflush(stdin);
				printf("Ten hang: ");
				scanf("%s",&a[i].tensp);
				fflush(stdin);
				printf("Ma loai san pham: ");
				scanf("%s",&a[i].maloaisp);
				fflush(stdin);
				printf("Ngay, Thang, Nam san xuat: ");
				scanf("%d%d%d",&a[i].ngaysx,&a[i].thangsx,&a[i].namsx);
				fflush(stdin);
				printf("Ngay, Thang, Nam het han: ");
				scanf("%d%d%d",&a[i].ngaysd,&a[i].thangsd,&a[i].namsd);
				fprintf(f,"%d\t%s\t%s\t%d %d %d\t%d %d %d\n",a[i].masp,a[i].tensp,a[i].maloaisp,a[i].ngaysx,a[i].thangsx,a[i].namsx,a[i].ngaysd,a[i].thangsd,a[i].namsd);
				i++;
				fflush(stdin);
			}
			while(i<n);
			fclose(f);
		
		
}

void xuat(struct banhang a[],int n)
{
	FILE*f;
	f=fopen("d:\\vanban.txt","rt");
	if(f==NULL)
		printf("khong tao duoc file");
	else	
	{	printf("Mahang-----Tenhang-----Maloaisp-----ngaysanxuat-----ngayhethan\n");
		for(int i= 0;i<n;i++)
		{
			fscanf(f,"%d\t%s\t%s\t%d %d %d\t%d %d %d",&a[i].masp,&a[i].tensp,&a[i].maloaisp,&a[i].ngaysx,&a[i].thangsx,&a[i].namsx,&a[i].ngaysd,&a[i].thangsd,&a[i].namsd);
			printf("     %d-----%s------%s------%d-%d-%d------%d-%d-%d\n",a[i].masp,a[i].tensp,a[i].maloaisp,a[i].ngaysx,a[i].thangsx,a[i].namsx,a[i].ngaysd,a[i].thangsd,a[i].namsd);
		}
		fclose(f);
	}
}

void timmasp(struct banhang a[],int n)
{
	fflush(stdin);
	char b[20];
	printf("nhap ma loai san pham can tim: ");
	scanf("%s",&b);
	for (int i = 0; i < n; i++)
	{
		if(strcmp(a[i].maloaisp,b)==0)
		{
				printf("    %d-----%s------%s------%d-%d-%d------%d-%d-%d\n",a[i].masp,a[i].tensp,a[i].maloaisp,a[i].ngaysx,a[i].thangsx,a[i].namsx,a[i].ngaysd,a[i].thangsd,a[i].namsd);
		}
	}getch();
}

void timsphethan(struct banhang a[],int n)
{
	int ngayht,thanght,namht;
	printf("ngay, thang, nam hien nay: ");
	scanf("%d%d%d",&ngayht,&thanght,&namht);
	for (int i = 0; i < n; i++)
	{
		if(namht==a[i].namsd)
		{ 
			if(thanght==a[i].thangsd)
			{
				if(ngayht>a[i].ngaysd)
				{
					printf("san pham het han: %d-----%s------%s------%d-%d-%d------%d-%d-%d\n",a[i].masp,a[i].tensp,a[i].maloaisp,a[i].ngaysx,a[i].thangsx,a[i].namsx,a[i].ngaysd,a[i].thangsd,a[i].namsd);
				}
			}
			else
			if(thanght>a[i].thangsd)
			{
				printf("san pham het han: %d-----%s------%s------%d-%d-%d------%d-%d-%d\n",a[i].masp,a[i].tensp,a[i].maloaisp,a[i].ngaysx,a[i].thangsx,a[i].namsx,a[i].ngaysd,a[i].thangsd,a[i].namsd);
			}
		}
		else 
		if(namht>a[i].namsd)
		{
			printf("san pham het han: %d-----%s------%s------%d-%d-%d------%d-%d-%d\n",a[i].masp,a[i].tensp,a[i].maloaisp,a[i].ngaysx,a[i].thangsx,a[i].namsx,a[i].ngaysd,a[i].thangsd,a[i].namsd);
		}	
	}
}

int main()
{
	a[200];
	int luachon;
	int n;
	int flag=0;
	do
	{
		system("cls");
		printf("1/ Nhap thong tin san pham: \n");
		printf("2/ Hien thi danh sach ca san pham hien co: \n");
		printf("3/ Hien thi thong tin cac san pham thuoc ma loai san pham: \n");
		printf("4/ In thong tin cac san pham het han su dung tinh den ngay thang nam hien tai: \n");
		printf("5/ Thoat khoi chuong trinh\n");
		printf("Hay chon lua 1 chuc nang de thuc hien: \n");
		scanf("%d",&luachon);
		switch(luachon)
		{
			case 1:
				nhap(a,n);
				flag=1;
				break;
			case 2: 
				if(flag==1)
				{
					xuat(a,n);	
				}
				else
				{
					printf("mang trong vui long chon lai so 1");
				}
				getch();
			break;
			case 3: 
				if(flag==1)
				{
					timmasp(a,n);
				}
				else
				{
					printf("mang trong vui long chon lai so 1");
				}
				getch();
			break;
			case 4: 
				if(flag==1)
				{
					timsphethan(a,n);
				}
				else
				{
					printf("mang trong vui long chon lai so 1");
				}
				getch();
			break;
			case 5: break;
		}
	}
	while(luachon!=5);
}
