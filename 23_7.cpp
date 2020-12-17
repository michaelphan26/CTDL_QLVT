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
//#include"graphics.h"

using namespace std;
#define MAXNV 500
#define MAXVT 20

struct Vattu{
	char TENVT[50];
	char DVT[10];
	float SLT;
};
typedef struct Vattu VATTU;

struct Nodes_Vattu{
	char MAVT[10];
	VATTU info;
	struct Nodes_Vattu *left;
	struct Nodes_Vattu *right;
};
typedef struct Nodes_Vattu *TREE_VATTU;


struct Chitiet_Hoadon{
	char MAVT[10];
	int SL;
	int DonGia;
	int VAT;
	int TrangThai;	
};
typedef struct Chitiet_Hoadon CHITIET_HOADON;

struct DSTT{
	int soluong;
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
};
typedef struct Hoadon HOADON;

struct Nodes_Hoadon{
	HOADON info;
	Nodes_Hoadon *next;
};
typedef struct Nodes_Hoadon *NODES_HOADON;

//struct DSLKD{
//	NODES_HOADON first;
//	NODES_HOADON last;
//};
//typedef struct DSLKD DS_HOADON;


struct Nhanvien{
	int MANV;
	char HO[20];
	char TEN[20];
	char PHAI[5];
	char CMND[12];
	// Con tro DSHD
	NODES_HOADON PTR_HD;
};
typedef struct Nhanvien NHANVIEN;
struct DSMCT{
	int soluong;
	Nhanvien *nodes[MAXNV];
};
typedef struct DSMCT DS_NV;



// cac ham giao dien

void giaoDienKhung(){
	//Khung chinh
	VeKhung(1,1,113,44);
	
	//Khung phu 1
	VeKhung(116,1,48,19);
	
	//Khung phu 2
	VeKhung(116,21,48,19);
	
	//Khung phu 3
	VeKhung(116,41,48,4);
	
	gotoxy(120,43);
	cout << "CHO NAY DE THONG BAO";
}

void xoaKhung1() {
	
//	for (int i =117 ; i<= 163 ;i++) {
//		for (int j=2;j<=19;j++) {
//			gotoxy(i,j);
//			SetBGColor(0);
//			cout << char(32);
//		}	
//	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,2);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,3);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,4);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,5);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,6);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,7);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,8);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,9);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,10);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,11);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,12);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,13);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,14);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,15);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,16);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,17);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,18);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,19);
		SetBGColor(0);
		cout << char(32);
	}
	
}

void xoaKhung2() {
	
//	for (int i =117 ; i<= 163 ;i++) {
//		for (int j=22;j<=39;j++) {
//			gotoxy(i,j);
//			//SetBGColor(0);
//			cout << char(32);
//		}	
//	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,22);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,23);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,24);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,25);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,26);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,27);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,28);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,29);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,30);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,31);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,32);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,33);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,34);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,35);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,36);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,37);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,38);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i =117 ; i<= 163 ;i++) {
		gotoxy(i,39);
		SetBGColor(0);
		cout << char(32);
	}
}

void xoaKhungThongBao() {
	for (int i=117;i<=163;i++) {
		gotoxy(i,42);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i=117;i<=163;i++) {
		gotoxy(i,43);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i=117;i<=163;i++) {
		gotoxy(i,44);
		SetBGColor(0);
		cout << char(32);
	}
}
	
void giaoDienMenu(){
	//Tieu de
	
	
	//Lua chon Menu
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
	gotoxy(5,13);
	SetBGColor(255);
	int x=5,y=13;
	while(true){
		int c=getch();
		if(y>13 && y<40){
			if(c==DOWN){
				y=y+3;
				SetBGColor(0);
				gotoxy(x,y);
				SetBGColor(255);
			}
			else if (c==UP){
				y=y-3;
				SetBGColor(0);
				gotoxy(x,y);
				SetBGColor(255);
			}
		}
		else if(y==40){
			if(c==UP){
				y=y-3;
				SetBGColor(0);
				gotoxy(x,y);
				SetBGColor(255);
			}
			else if(c==DOWN){
				SetBGColor(0);
				y=13;
				gotoxy(x,y);
				SetBGColor(255);
			}
		}
		else if(y==13){
			if(c==DOWN){
				y=y+3;
				SetBGColor(0);
				gotoxy(x,y);
				SetBGColor(255);
			}
			else if (c==UP){
				SetBGColor(0);
				y=40;
				gotoxy(x,y);
				SetBGColor(255);
			}
		}
		
		if (c==ENTER){
			y=wherey();
			return;
		}
	}
}

// cau e

void khoiTaoChiTietHD(HOADON& hd) {
	hd.PTR_CTHD.soluong=0;
}

int Search_MSHD(NODES_HOADON First, char* x)
{
	for (NODES_HOADON p = First;  p  != NULL ; p=p->next )
    	if ( strcmp(p->info.SOHD,x)==0  ) return 1;
	return 0;
}

int Search_MaVT(HOADON& hd, char* x){
	for (int i=0;i<hd.PTR_CTHD.soluong;i++) {
		if (strcmp(hd.PTR_CTHD.nodes[i].MAVT,x)==0) return 1;
	}
	return 0;	
}
void nhapChiTietHoaDon(HOADON& hd){
	khoiTaoChiTietHD(hd);
	char mvt[4];
	char sl[5];
	char dg[9];
	char tt[1];
	char vat[3];
	while(hd.PTR_CTHD.soluong<MAXVT) {
		
		xoaKhung2();
		gotoxy(125,25);
		cout << "Nhap ma vat tu thu " << hd.PTR_CTHD.soluong+1 <<  ": ";
		InputNumber(mvt,4);
		if(atoi(mvt)<0) break;
		if(Search_MaVT(hd,mvt)==1) {
			gotoxy(120,43);
			cout << "Ma vat tu da co";
			getch();
			xoaKhungThongBao();
			continue;
		}
		gotoxy(125,26);
		cout << "Nhap so luong: ";
		InputNumber(sl,5);
		gotoxy(125,27);
		cout << "Nhap don gia: ";
		InputNumber(dg,9);
		gotoxy(125,28);
		cout << "Nhap trang thai: ";
		InputNumber(tt,1);
		gotoxy(125,29);
		cout << "Nhap VAT: ";
		InputNumber(vat,3);
		
		strcpy(hd.PTR_CTHD.nodes[hd.PTR_CTHD.soluong].MAVT,mvt);
		hd.PTR_CTHD.nodes[hd.PTR_CTHD.soluong].SL=atoi(sl);
		hd.PTR_CTHD.nodes[hd.PTR_CTHD.soluong].DonGia=atoi(dg);
		hd.PTR_CTHD.nodes[hd.PTR_CTHD.soluong].TrangThai=atoi(tt);
		hd.PTR_CTHD.nodes[hd.PTR_CTHD.soluong].VAT=atoi(vat);
		hd.PTR_CTHD.soluong++;
	}
	if(hd.PTR_CTHD.soluong==MAXVT) {
		gotoxy(125,25);
		cout << "danh sach da day!";
		getch();
	}
}

void nhapHoaDonCuoi(NODES_HOADON& first) {
	
	NODES_HOADON p, last; HOADON hd;
	if (first != NULL)
		for ( last = first ; last->next !=NULL; last=last->next) ;
	while(1) {
		xoaKhung2();
		gotoxy(125,25);
		cout << "Nhap so hoa don: ";
		InputNumber(hd.SOHD,4);
		if(Search_MSHD(first,hd.SOHD)==1) {
			gotoxy(120,43);
			cout << "So hoa don da co";
			getch();
			xoaKhungThongBao();
			continue;
		}
		if(atoi(hd.SOHD)<0) break;
		gotoxy(125,26);
		cout << "Nhap ngay: ";
		InputNumber(hd.date.day,2);
		gotoxy(125,27);
		cout << "Nhap thang: ";
		InputNumber(hd.date.month,2);
		gotoxy(125,28);
		cout << "Nhap nam: ";
		InputNumber(hd.date.year,4);
		gotoxy(125,29);
		cout << "Nhap loai: ";
		InputLoai(hd.LoaiHD,1);
		nhapChiTietHoaDon(hd); 		
		p = new Nodes_Hoadon;
		p->info = hd;
		p->next = NULL;
		if(first == NULL) first = p;
		else last->next = p;
		last = p;	
	}

}

void lietKe(NODES_HOADON hd) {
	int i=2;
	for (NODES_HOADON p = hd; p!=NULL; p = p->next) {
		gotoxy(2,i);
		printf ("%5s %-30s %-10s\n",p->info.SOHD , p->info.date.day, p->info.date.month );
		i++;
	}
}

void DrawTableLTC() {
	VeKhung(4,4,95,33);
	for (int i=5;i<=98;i++) { // line ngang 
		gotoxy(i,6);
		cout << char(196);
		gotoxy(4,6);
		cout << char(195);
		gotoxy(99,6);
		cout << char(180);
	}
	for (int i=5;i<=36;i++) { // line doc
		gotoxy(12,i);
		cout << char(179);
		gotoxy(12,4);
		cout << char(194);
		gotoxy(12,6);
		cout << char(197);
		gotoxy(12,37);
		cout << char(193);
		//
		gotoxy(26,i);
		cout << char(179);
		gotoxy(26,4);
		cout << char(194);
		gotoxy(26,6);
		cout << char(197);
		gotoxy(26,37);
		cout << char(193);
		//
		gotoxy(48,i);
		cout << char(179);
		gotoxy(48,4);
		cout << char(194);
		gotoxy(48,6);
		cout << char(197);
		gotoxy(48,37);
		cout << char(193);
		//
		gotoxy(65,i);
		cout << char(179);
		gotoxy(65,4);
		cout << char(194);
		gotoxy(65,6);
		cout << char(197);
		gotoxy(65,37);
		cout << char(193);
		//
		gotoxy(75,i);
		cout << char(179);
		gotoxy(75,4);
		cout << char(194);
		gotoxy(75,6);
		cout << char(197);
		gotoxy(75,37);
		cout << char(193);
		//
		gotoxy(86,i);
		cout << char(179);
		gotoxy(86,4);
		cout << char(194);
		gotoxy(86,6);
		cout << char(197);
		gotoxy(86,37);
		cout << char(193);
	}
	gotoxy(7,5);
	cout << "STT";
	gotoxy(16,5);
	cout << "MALOPTC";
	gotoxy(35,5);
	cout << "MA MH";
	gotoxy(52,5);
	cout << "NIEN KHOA";
	gotoxy(67,5);
	cout << "HOC KY";
	gotoxy(79,5);
	cout << "NHOM";
	gotoxy(89,5);
	cout << "SO SVMAX";
}

int main(){
	resizeConsole(1920,1080);
	fullScreen();
	RemoveScroll();
	giaoDienKhung();
	DrawTableLTC();
//	NODES_HOADON first=NULL;
//	nhapHoaDonCuoi(first);
	//lietKe(first);
	//giaoDienMenu();
	//getch();
	getch();
}
