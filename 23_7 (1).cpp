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
	int day;
	int month;
	int year;
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
	VeKhung(1,1,117,44);
	
	//vach ngan
	for(int i=6;i<=40;i++){
		gotoxy(60,i);
		cout << char(179);
	}
	//Khung phu 1
	VeKhung(120,1,44,19);
	
	//Khung phu 2
	VeKhung(120,21,44,19);
	
	//Khung phu 3
	VeKhung(120,41,44,4);
	
	
}

void thongBaoLoi(string s) {
	SetColor(DODAM);
	gotoxy(120,43);
	cout << s;
	SetColor(TRANG);
}

void xoaKhung1() {
	int j=2;
	for (int i =121 ; i<= 163 ;i++) {
		gotoxy(i,j);
		SetBGColor(0);
		cout << char(32);
		if(i==163) {
			j++; 
			i=121;
		}
		if(j==20) break;
	}

	
}

void xoaKhung2() {
	int j=22;
	for (int i =121 ; i<= 159 ;i++) {
		
		gotoxy(i,j);
		SetBGColor(0);
		cout << char(32);
		if(i==159) {
			j++; 
			i=121;
		}
		if(j==40) break; 
		
	}

}

void xoaKhungThongBao() {
	for (int i=121;i<=159;i++) {
		gotoxy(i,42);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i=121;i<=159;i++) {
		gotoxy(i,43);
		SetBGColor(0);
		cout << char(32);
	}
	for (int i=121;i<=159;i++) {
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
		InputNumber(mvt,10);
		if(atoi(mvt)<0) break;
		if(Search_MaVT(hd,mvt)==1) {
			thongBaoLoi("Ma vat tu da co");
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
		gotoxy(120,43);
		cout << "danh sach da day!";
		getch();
	}
}

void nhapHoaDonCuoi(NODES_HOADON& first) {
	
	NODES_HOADON p, last; HOADON hd;
	char day[2],month[2],year[4];
	
	if (first != NULL)
		for ( last = first ; last->next !=NULL; last=last->next) ;
	while(1) {
		xoaKhung2();
		gotoxy(125,25);
		cout << "Nhap so hoa don: ";
		InputNumber(hd.SOHD,20);
		if(Search_MSHD(first,hd.SOHD)==1) {
			thongBaoLoi("So hoa don da co");
			getch();
			xoaKhungThongBao();
			continue;
		}
		if(atoi(hd.SOHD)<0) break;
		gotoxy(125,26);
		cout << "Nhap ngay: ";
		InputNumber(day,2);
		gotoxy(125,27);
		cout << "Nhap thang: ";
		InputNumber(month,2);
		gotoxy(125,28);
		cout << "Nhap nam: ";
		InputNumber(year,4);
		hd.date.day = atoi(day);
		hd.date.month = atoi(month);
		hd.date.year = atoi(year);
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

void lietKeHoaDon(NODES_HOADON hd) {
	int i=1;
	for (NODES_HOADON p = hd; p!=NULL; p = p->next) {
		gotoxy(6,i+5);
		cout << i;
		gotoxy(15,i+5);
		cout << p->info.SOHD;
		gotoxy(40,i+5);
		cout << p->info.date.day <<"/"<<p->info.date.month <<"/"<<p->info.date.year;
		gotoxy(53,i+5);
		cout << p->info.LoaiHD;
		i++;
	}
}

void veKhungHoaDon() {
	VeKhung(4,3,53,40);
	for (int i=5;i<=56;i++) { // line ngang 
		gotoxy(i,5);
		cout << char(196);
		gotoxy(4,5);
		cout << char(195);
		gotoxy(57,5);
		cout << char(180);
	}
	for (int i=4;i<=42;i++) { // line doc 1
		gotoxy(9,i);
		cout << char(179);
		gotoxy(9,3);
		cout << char(194);
		gotoxy(9,5);
		cout << char(197);
		gotoxy(9,43);
		cout << char(193);
	}
	for (int i=4;i<=42;i++) { // line doc 2
		gotoxy(38,i);
		cout << char(179);
		gotoxy(38,3);
		cout << char(194);
		gotoxy(38,5);
		cout << char(197);
		gotoxy(38,43);
		cout << char(193);
	}
	for (int i=4;i<=42;i++) { // line doc 3
		gotoxy(51,i);
		cout << char(179);
		gotoxy(51,3);
		cout << char(194);
		gotoxy(51,5);
		cout << char(197);
		gotoxy(51,43);
		cout << char(193);
	}
	SetColor(LUC);
	gotoxy(5,4);
	cout << "STT";
	gotoxy(19,4);
	cout << "SO HOA DON";
	gotoxy(41,4);
	cout << "NGAY LAP";
	gotoxy(52,4);
	cout << "LOAI";
	SetColor(TRANG);
}

void veKhungChiTietHoaDon() {
	VeKhung(63,3,53,40);
	for (int i=5;i<=56;i++) { // line ngang 
		gotoxy(i,5);
		cout << char(196);
		gotoxy(4,5);
		cout << char(195);
		gotoxy(57,5);
		cout << char(180);
	}
	for (int i=4;i<=42;i++) { // line doc 1
		gotoxy(9,i);
		cout << char(179);
		gotoxy(9,3);
		cout << char(194);
		gotoxy(9,5);
		cout << char(197);
		gotoxy(9,43);
		cout << char(193);
	}
	for (int i=4;i<=42;i++) { // line doc 2
		gotoxy(38,i);
		cout << char(179);
		gotoxy(38,3);
		cout << char(194);
		gotoxy(38,5);
		cout << char(197);
		gotoxy(38,43);
		cout << char(193);
	}
	for (int i=4;i<=42;i++) { // line doc 3
		gotoxy(51,i);
		cout << char(179);
		gotoxy(51,3);
		cout << char(194);
		gotoxy(51,5);
		cout << char(197);
		gotoxy(51,43);
		cout << char(193);
	}
	SetColor(LUC);
	gotoxy(5,4);
	cout << "STT";
	gotoxy(19,4);
	cout << "SO HOA DON";
	gotoxy(41,4);
	cout << "NGAY LAP";
	gotoxy(52,4);
	cout << "LOAI";
	SetColor(TRANG);
}

int main(){
	resizeConsole(1920,1080);
	fullScreen();
	RemoveScroll();
	giaoDienKhung();
	veKhungHoaDon();
	veKhungChiTietHoaDon(); 
	gotoxy(163,2);
	cout << "A";
	gotoxy(163,3);
	cout << "A";
	gotoxy(163,4);
	cout << "A";
	gotoxy(163,5);
	cout << "A";
	gotoxy(163,6);
	cout << "A";
	gotoxy(163,7);
	cout << "A";
	gotoxy(163,8);
	cout << "A";
	gotoxy(163,9);
	cout << "A";
	getch();	
	xoaKhung1();
	//NODES_HOADON first=NULL;
	//nhapHoaDonCuoi(first);
	//lietKeHoaDon(first);
	//giaoDienMenu();
	//getch();
	getch();
}
