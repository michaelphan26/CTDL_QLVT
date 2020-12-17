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
	char TENVT[51];
	char DVT[11];
	float SLT;
};
typedef struct Vattu VATTU;

struct Nodes_Vattu{
	char MAVT[11];
	VATTU info;
	struct Nodes_Vattu *left;
	struct Nodes_Vattu *right;
};
typedef struct Nodes_Vattu *TREE_VATTU;


struct Chitiet_Hoadon{
	char MAVT[11];
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
	char SOHD[21];
	Date date;
	char LoaiHD[2];
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
	char HO[21];
	char TEN[21];
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
	SetColor(LAM);
	for(int i=6;i<=40;i++){
		gotoxy(58,i);
		cout << char(179);
	}
	SetColor(TRANG);
	//Khung phu 1
	VeKhung(120,1,44,19);
	
	//Khung phu 2
	VeKhung(120,21,44,19);
	
	//Khung phu 3
	VeKhung(120,41,44,4);
	
	
}

void thongBaoLoi(string s) {
	SetColor(DODAM);
	gotoxy(125,43);
	cout << s;
	gotoxy(125,44);
	cout << "Nhan phim bat ki de tiep tuc";
	SetColor(TRANG);
}

void xoaKhungTrai() {
	for(int i=2;i<=44;i++) {
		gotoxy(2,i);
		SetBGColor(0);
		cout << "                                                        ";
	}
}

void xoaKhungPhai() {
	for(int i=2;i<=44;i++) {
		gotoxy(59,i);
		SetBGColor(0);
		cout << "                                                           ";
	}
}

void xoaKhungChinh() {
	xoaKhungTrai();
	xoaKhungPhai();
}

void xoaKhung1() {
	for (int i =2 ; i<= 19 ;i++) {
		gotoxy(121,i);
		SetBGColor(0);
		cout << "                                           ";
	}
}

void xoaKhung2() {
	for (int i =22 ; i<= 39 ;i++) {
		
		gotoxy(121,i);
		SetBGColor(0);
		cout << "                                           ";		
	}
}

void xoaKhungThongBao() {
	for (int i=42;i<=44;i++) {
		gotoxy(121,i);
		SetBGColor(0);
		cout << "                                           ";
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
	char mvt[12];
	char sl[5];
	char dg[10];
	char tt[3];
	char vat[4];
	while(hd.PTR_CTHD.soluong<MAXVT) {
		
		xoaKhung2();
		gotoxy(125,25);
		cout << "Nhap ma vat tu thu " << hd.PTR_CTHD.soluong+1 <<  ": ";
		InputNumber(mvt,10);
		//if(atoi(mvt)<0) break;
		if(Search_MaVT(hd,mvt)==1) {
			thongBaoLoi("Ma vat tu da co");
			getch();
			xoaKhungThongBao();
			continue;
		}
		if(strcmp(mvt,"quit")==0) return;
		gotoxy(125,26);
		cout << "Nhap so luong: ";
		InputNumber(sl,4);
		if(strcmp(sl,"quit")==0) return;
		gotoxy(125,27);
		cout << "Nhap don gia: ";
		InputNumber(dg,9);
		if(strcmp(dg,"quit")==0) return;
		gotoxy(125,28);
		cout << "Nhap trang thai: ";
		InputNumber(tt,1);
		if(strcmp(tt,"quit")==0) return;
		gotoxy(125,29);
		cout << "Nhap VAT: ";
		InputNumber(vat,3);
		if(strcmp(vat,"quit")==0) return;
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
	
	if (first != NULL) {
		for ( last = first ; last->next !=NULL; last=last->next) ;
	}
	xoaKhung2();	
	while(true) {
		gotoxy(125,25);
		cout << "Nhap so hoa don: ";
		InputNumber(hd.SOHD,20);
		if(Search_MSHD(first,hd.SOHD)==1) {
			thongBaoLoi("So hoa don da co");
			getch();
			xoaKhungThongBao();
			continue;
		}
		break;
	}

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

void xoaDataChiTietHoaDon() {
	for(int i=6;i<=42;i++) {
		gotoxy(61,i);
		cout << "    ";
		gotoxy(66,i);
		cout << "               ";
		gotoxy(82,i);
		cout << "        ";
		gotoxy(91,i);
		cout << "           ";
		gotoxy(103,i);
		cout << "   ";
		gotoxy(107,i);
		cout << "         ";
	}
}

void xoaDataHoaDon(){
	for(int i=6;i<=42;i++) {
		gotoxy(4,i);
		cout << "    ";
		gotoxy(9,i);
		cout << "                            ";
		gotoxy(38,i);
		cout << "            ";
		gotoxy(51,i);
		cout << "     ";
	}
}

void showCTHD(HOADON hd) {

	for (int i=0;i<hd.PTR_CTHD.soluong;i++) {
		gotoxy(62,i+6);
		cout << i+1;
		gotoxy(69,i+6);
		cout << hd.PTR_CTHD.nodes[i].MAVT;
		gotoxy(85,i+6);
		cout << hd.PTR_CTHD.nodes[i].SL;
		gotoxy(93,i+6);
		cout << hd.PTR_CTHD.nodes[i].DonGia;
		gotoxy(104,i+6);
		cout << hd.PTR_CTHD.nodes[i].TrangThai;
		gotoxy(110,i+6);
		cout << hd.PTR_CTHD.nodes[i].VAT;

	}
}

void lietKeChiTietHoaDon(NODES_HOADON hd) {
	bool exit = false;
	HOADON ds[MAXVT];
	int i=0;
	for (NODES_HOADON p = hd; p!=NULL; p = p->next) {
		gotoxy(6,i+6);
		cout << i+1;
		gotoxy(15,i+6);
		cout << p->info.SOHD;
		gotoxy(40,i+6);
		cout << p->info.date.day <<"/"<<p->info.date.month <<"/"<<p->info.date.year;
		gotoxy(53,i+6);
		cout << p->info.LoaiHD;
		ds[i++] = p->info;
	}
	showCTHD(ds[0]);
//	int first=0;
//	while(!exit) {
//		char key;
//		key = getch();
//		if (key==UP) {
//			first--;
//			if(first<0) first=i-1;
//			xoaDataChiTietHoaDon();
//			showCTHD(ds[first]);
//		}
//		if (key==DOWN) {
//			first++;
//			if(first>i) first=0;
//			xoaDataChiTietHoaDon();
//			showCTHD(ds[first]);
//		}
//		if (key==ESC) exit=true;
//	}
}



void veKhungHoaDon() {
	VeKhung(3,3,53,40);
	// line ngang 
	for (int i=4;i<=55;i++) { 
		gotoxy(i,5);
		cout << char(196);
	}
		gotoxy(3,5);
		cout << char(195);
		gotoxy(56,5);
		cout << char(180);
	// line doc 1	
	for (int i=4;i<=42;i++) { 
		gotoxy(8,i);
		cout << char(179);
	}
		gotoxy(8,3);
		cout << char(194);
		gotoxy(8,5);
		cout << char(197);
		gotoxy(8,43);
		cout << char(193);
	// line doc 2
	for (int i=4;i<=42;i++) { 
		gotoxy(37,i);
		cout << char(179);
	}
		gotoxy(37,3);
		cout << char(194);
		gotoxy(37,5);
		cout << char(197);
		gotoxy(37,43);
		cout << char(193);
	// line doc 3
	for (int i=4;i<=42;i++) { 
		gotoxy(50,i);
		cout << char(179);
	}
		gotoxy(50,3);
		cout << char(194);
		gotoxy(50,5);
		cout << char(197);
		gotoxy(50,43);
		cout << char(193);
	SetColor(LUC);
	gotoxy(4,4);
	cout << "STT";
	gotoxy(18,4);
	cout << "SO HOA DON";
	gotoxy(40,4);
	cout << "NGAY LAP";
	gotoxy(51,4);
	cout << "LOAI";
	SetColor(TRANG);
}

void veKhungChiTietHoaDon() {
	VeKhung(60,3,56,40);
	// line ngang
	for (int i=61;i<=116;i++) {  
		gotoxy(i,5);
		cout << char(196);
	}
		gotoxy(60,5);
		cout << char(195);
		gotoxy(116,5);
		cout << char(180);
	// line doc 1	
	for (int i=4;i<=42;i++) { 
		gotoxy(65,i);
		cout << char(179);
	}
		gotoxy(65,3);
		cout << char(194);
		gotoxy(65,5);
		cout << char(197);
		gotoxy(65,43);
		cout << char(193);
	// line doc 2	
	for (int i=4;i<=42;i++) { 
		gotoxy(81,i);
		cout << char(179);
	}
		gotoxy(81,3);
		cout << char(194);
		gotoxy(81,5);
		cout << char(197);
		gotoxy(81,43);
		cout << char(193);
	// line doc 3	
	for (int i=4;i<=42;i++) { 
		gotoxy(90,i);
		cout << char(179);
	}
		gotoxy(90,3);
		cout << char(194);
		gotoxy(90,5);
		cout << char(197);
		gotoxy(90,43);
		cout << char(193);
	// line doc 4	
	for (int i=4;i<=42;i++) { 
		gotoxy(102,i);
		cout << char(179);
	}
		gotoxy(102,3);
		cout << char(194);
		gotoxy(102,5);
		cout << char(197);
		gotoxy(102,43);
		cout << char(193);
	// line doc 5	
	for (int i=4;i<=42;i++) { 
		gotoxy(106,i);
		cout << char(179);	
	}
		gotoxy(106,3);
		cout << char(194);
		gotoxy(106,5);
		cout << char(197);
		gotoxy(106,43);
		cout << char(193);
	gotoxy(61,4);
	SetColor(LUC);
	cout << "STT";
	gotoxy(71,4);
	cout << "MA VT";
	gotoxy(85,4);
	cout << "SL";
	gotoxy(93,4);
	cout << "DON GIA";
	gotoxy(103,4);
	cout << "TT";
	gotoxy(110,4);
	cout << "VAT";
	SetColor(TRANG);
}

int Full_DSNV(DS_NV ds){
	if(ds.soluong==MAXNV) return true;
	else return false;
}

int Check_NV(DS_NV &ds, char* ma){
	for (int i=0;i<ds.soluong;i++){
		if (ds.nodes[i]->MANV==atoi(ma)==0) return 1;
	}
	return 0;
}

int Check_CMND(DS_NV &ds, char *cmnd){
	for (int i=0;i<ds.soluong;i++){
		if(strcmp(ds.nodes[i]->CMND,cmnd)==0)return 1;
	}	
	return 0;
}

NHANVIEN Insert_NV(DS_NV &ds, NHANVIEN &nv){

	char ma[4];
	char ho[21];
	char ten[21];
	char phai[5];
	char cmnd[12];

	while(true){
		gotoxy(125,25);
		cout<<"Nhap ma nhan vien: ";
		InputNumber(ma,3);
		if (Check_NV(ds,ma)==1){
			thongBaoLoi("Ma nhan vien bi trung");
			getch();
			continue;
		}
		break;
	}
	

	gotoxy(125,26);
	cout<<"Nhap ho nhan vien: ";
	InputStringSpace(ho,20);
	
	gotoxy(125,27);
	cout<<"Nhap ten nhan vien: ";
	InputString(ten,20);
	
	while(true){

		gotoxy(125,28);
		cout<<"Nhap phai: ";
		InputString(phai,3);
		
		if (stricmp(phai,"nam")==0){
			strcpy(phai,"nam");
			break;
		}
		if (stricmp(phai,"nu")==0) {
			strcpy(phai,"nu");
			break;
		}
		gotoxy(136,28);
		cout << "   ";
		thongBaoLoi("Chi duoc nhap nam hoac nu");
		getch();
		continue;
		
	}
	
	while (true) {
		gotoxy(125,29);
		cout<<"Nhap CMND: ";
		InputNumber(cmnd,10);
		if (Check_CMND(ds,cmnd)==1){
			thongBaoLoi("CMND nhan vien bi trung");
			getch();
			xoaKhungThongBao();
			continue;
		}
		break;
	}
	
		
	nv.MANV=atoi(ma);	    
	strcpy(nv.HO,ho);	  
	strcpy(nv.TEN,ten);
	strcpy(nv.PHAI,phai);	
	strcpy(nv.CMND,cmnd);
	return nv;		
}

void Insert_DSNV(DS_NV &ds){
	if (Full_DSNV(ds)==true)	return;	//BaoLoi("Danh sach nhan vien da day");
	else{
		NHANVIEN nv;
		ds.nodes[ds.soluong]=new NHANVIEN;
		*ds.nodes[ds.soluong]=Insert_NV(ds,nv);
		ds.soluong++;
	}
}

void List_NhanVien_All(DS_NV ds){
		int y=6;
		for (int i=0; i<ds.soluong;i++){
			gotoxy(6,y);
			cout<<ds.nodes[i]->MANV<<endl;
			gotoxy(20,y);
			cout<<ds.nodes[i]->HO<<endl;
			gotoxy(35,y);
			cout<<ds.nodes[i]->TEN<<endl;
			gotoxy(50,y);
			cout<<ds.nodes[i]->PHAI<<endl;
			gotoxy(65,y);
			cout<<ds.nodes[i]->CMND<<endl;
			if(ds.nodes[i]->PTR_HD==NULL) 
				gotoxy(70,y);
				cout << "NULL";
			
		}

		
}

int main(){
	resizeConsole(1920,1080);
	fullScreen();
	RemoveScroll();
	giaoDienKhung();
//	veKhungHoaDon();
//	veKhungChiTietHoaDon(); 
//	NODES_HOADON first=NULL;

	DS_NV nv;
	Insert_DSNV(nv);
	List_NhanVien_All(nv);

	//giaoDienMenu();
	//getch();
	getch();
}
