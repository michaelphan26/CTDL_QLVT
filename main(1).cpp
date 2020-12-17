#include <iostream>
#include <malloc.h>
#include<string>
#include<string.h>
#include<cstring>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
#include<iomanip>
#include<time.h>
#include<math.h>
#include"lib.h"
#include"graphics.h"

using namespace std;
#define MAXNV 500
#define MAXVT 20

struct Vattu{
	char MAVT[10];
	char TENVT[50];
	char DVT[10];
	float SLT;
	struct Vattu *left;
	struct Vattu *right;
};
typedef struct Vattu *TREE_VATTU;

struct BST {
	int soluong = 0;
	TREE_VATTU nodes = NULL;
};
typedef struct BST DS_VATTU;

struct Chitiet_Hoadon{
	char MAVT[10];
	int SL;
	int DonGia;
	int VAT;
	int TrangThai;	
};
typedef struct Chitiet_Hoadon CHITIET_HOADON;

struct DSTT{
	int soluong = 0;
	CHITIET_HOADON nodes[MAXVT];
};
typedef struct DSTT DS_CTHD;

struct Date{
	char day[2];
	char month[2];
	char year[4];
};

struct Hoadon{
	char SOHD[20];
	Date date;
	char LoaiHD[1];
	// Con tro DSCTHD
	DS_CTHD PTR_CTHD;

	Hoadon* next;
};
typedef struct Hoadon HOADON;

struct DSLKD{
	int soluong = 0;
	HOADON* head = NULL;
};
typedef struct DSLKD DS_HOADON;


struct Nhanvien{
	int MANV;
	char HO[20];
	char TEN[20];
	char PHAI[5];
	char CMND[12];
	// Con tro DSHD
	DS_HOADON PTRhd;
};
typedef struct Nhanvien NHANVIEN;
struct DSMCT{
	int n;
	Nhanvien *nodes[MAXNV];
};
typedef struct DSMCT DS_NV;

void giaoDienKhung(){
	//Khung chinh
	VeKhung(43,1,1,113,"");
	
	//Khung phu 1
	VeKhung(21,116,1,48,"");
	
	//Khung phu 2
	VeKhung(21,116,23,48,"");
	
	
}

void giaoDienMenu(){
	gotoxy(5,13);
	cout<<"1. Cap nhat vat tu";
	gotoxy(5,16);
	cout<<"2. Liet ke vat tu ton kho";
	gotoxy(5,19);
	cout<<"3. Cap nhat nhan vien";
	gotoxy(5,22);
	cout<<"4. Liet ke danh sach nhan vien";
	gotoxy(5,25);
	cout<<"5. Lap hoa don";
	gotoxy(5,28);
	cout<<"6. Tra hang";
	gotoxy(5,31);
	cout<<"7. In hoa don";
	gotoxy(5,34);
	cout<<"8. Liet ke hoa don theo nhan vien";
	gotoxy(5,37);
	cout<<"9. Thong ke doanh thu";
	gotoxy(5,40);
	cout<<"10. Thoat chuong trinh";
	gotoxy(5,42);
	getch();
}


int main(){
	giaoDienKhung();
	giaoDienMenu();
}
