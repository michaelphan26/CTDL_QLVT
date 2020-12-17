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

struct DSLKD{
	NODES_HOADON first;
	NODES_HOADON last;
};
typedef struct DSLKD DS_HOADON;


struct Nhanvien{
	int MANV;
	char HO[20];
	char TEN[20];
	char PHAI[5];
	char CMND[12];
	// Con tro DSHD
	DS_HOADON PTR_HD;
};
typedef struct Nhanvien NHANVIEN;
struct DSMCT{
	int soluong;
	Nhanvien *nodes[MAXNV];
};
typedef struct DSMCT DS_NV;

int Empty_DSNV(DS_NV ds){
	if(ds.soluong==0) return true;
	else return false;
}

int Full_DSNV(DS_NV ds){
	if(ds.soluong==MAXNV) return true;
	else return false;
}

void GiaoDienMenuChinh(DS_NV &ds);
void GiaoDienMenuQuanLyNhanVien(DS_NV &ds);

void xoaKhung1() {
	
	for (int i =117 ; i<= 163 ;i++) {
		for (int j=2;j<=19;j++) {
			gotoxy(i,j);
			SetBGColor(0);
			cout << char(32);
		}	
	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,2);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,3);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,4);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,5);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,6);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,7);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,8);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,9);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,10);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,11);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,12);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,13);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,14);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,15);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,16);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,17);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,18);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,19);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	
}

void xoaKhung2() {
	
	for (int i =117 ; i<= 163 ;i++) {
		for (int j=22;j<=39;j++) {
			gotoxy(i,j);
			//SetBGColor(0);
			cout << char(32);
		}	
	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,22);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,23);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,24);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,25);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,26);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,27);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,28);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,29);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,30);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,31);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,32);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,33);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,34);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,35);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,36);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,37);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,38);
//		SetBGColor(0);
//		cout << char(32);
//	}
//	for (int i =117 ; i<= 163 ;i++) {
//		gotoxy(i,39);
//		SetBGColor(0);
//		cout << char(32);
//	}
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

void xoaToanBoKhungPhu(){
	xoaKhung1();
	xoaKhung2();
	xoaKhungThongBao();
}

void BaoLoi (char *s){
	xoaKhungThongBao();
	gotoxy(117,42);
	cout<<s;
	Sleep(2000);
}

//void treeTraverse(TREE_VATTU tree){	//Inorder
//	int MaxTraverse=500;
//	TREE_VATTU Stack[MaxTraverse];
//	TREE_VATTU node=tree;
//	int stack_point=-1;
//	while(true){
//		while (node!=NULL){
//			Stack[stack_point++]=node;
//			node=node->left;
//		}
//		if (stack_point!=-1){
//			node=Stack[stack_point--];
//			cout<<node->MAVT<<endl;;
//			cout<<node->info.TENVT<<endl;
//			cout<<node->info.DVT<<endl;
//			cout<<node->info.SLT<<endl;;
//			node=node->right;
//		}
//		else break;
//	}
//	
////	clrscr();
////	gotoxy(5,13);
////	cout<<"Ma VT";
////	gotoxy(15,13);
////	cout<<"Ten VT";
////	gotoxy(35,13);
////	cout<<"DVT";
////	gotoxy(45,13);
////	cout<<"SLTon";
////	
//	
//}

//void tree_Traverse(TREE_VATTU tree, int y){
//	y++;
//	if (tree!=NULL){
//		tree_Traverse(tree->left);
//		gotoxy(5,y);
//		cout<<tree->MAVT;
//		gotoxy(20,y);
//		cout<<tree->info.TENVT;
//		gotoxy(35,y);
//		cout<<tree->info.DVT
//		gotoxy(50,y);
//		cout<<tree->info.SLT;
//		tree_Traverse(tree->right);
//	}
//}

int char_check(char *c){
	for (int i=0;i<strlen(c);i++){
		if (int(c[i])<96 || int(c[i])>123) 
			return 0;
		else if(int(c[i])>96 || int(c[i])<123){
			//Check chu thuong ko viet hoa
			if(int(c[i])>64 || int(c[i])<91) return 1;
			else return 0;
		}
	}
}

int int_check(char *c){
	for (int i=0;i<strlen(c);i++){
		if (int(c[i])<48 || int(c[i])>57) 
			return 0;
		else {
			return 1;
		}
	}
}

int empty_check(char *c){
	if (c==NULL) return 1;
	else return 0;
}

//int empty_check_int(int a){
//	if (a==NULL) return 1;
//	else return 0;
//}

int Search_NV(DS_NV &ds, int ma){
	for (int i=0;i<ds.soluong;i++){
		if (ds.nodes[i]->MANV==ma) return i;
	}
	return -1;
}

int Search_CMND(DS_NV &ds, char *cmnd){
	for (int i=0;i<ds.soluong;i++){
		if(ds.nodes[i]->CMND==cmnd) return i;
	}	
	return -1;
}

NHANVIEN Insert_NV(DS_NV &ds, NHANVIEN &nv){
	int x;
	char ma[3];
	char ho[10];
	char ten[20];
	char phai[5];
	char cmnd[12];

	while(true){
		fflush(stdin);
		gotoxy(117,22);
		cout<<"Nhap ma nhan vien: ";
		gets(ma);
		fflush(stdin);
		sscanf(ma,"%d",&x);
		if (int (ma)==27){
			return nv;
		}
		if (int_check(ma)==0){
			xoaKhung2();
			BaoLoi("Ma nhan vien khong hop le");
			continue;
		}
		else if (Search_NV(ds,x)!=-1){
			xoaKhung2();
			BaoLoi("Ma nhan vien bi trung");
			continue;
		}
		else {
			break;
		}
	}
	
	while(true){
		fflush(stdin);
		gotoxy(117,23);
		cout<<"Nhap ho nhan vien: ";
		gets(ho);
		fflush(stdin);
		if (empty_check(ho)==1){
			xoaKhung2();
			BaoLoi("Ho nhan vien khong duoc de trong");
			gotoxy(117,22);
			cout<<"Nhap ma nhan vien: "<<ma<<endl;
			continue;
		}
		else if (char_check(ho)==0){
			xoaKhung2();
			BaoLoi("Ho khong the chua ky tu so");
			gotoxy(117,22);
			cout<<"Nhap ma nhan vien: "<<ma<<endl;
			continue;		
		}
		else{
			while(true){
				gotoxy(117,24);
				cout<<"Nhap ten nhan vien: ";
				gets(ten);
				fflush(stdin);
				if (empty_check(ten)==1){
					xoaKhung2();
					BaoLoi("Ten nhan vien khong duoc de trong");
					gotoxy(117,22);
					cout<<"Nhap ma nhan vien: "<<ma<<endl;
					gotoxy(117,23);
					cout<<"Nhap ho nhan vien: "<<ho<<endl;
					continue;
				}
				else if (char_check(ten)==0){
					xoaKhung2();
					BaoLoi("Ten khong the chua ky tu so");
					gotoxy(117,22);
					cout<<"Nhap ma nhan vien: "<<ma<<endl;
					gotoxy(117,23);
					cout<<"Nhap ho nhan vien: "<<ho<<endl;
					continue;
				}
				else break;
			}
			break;
		}
		break;
	}
	
	while(true){
		fflush(stdin);
		gotoxy(117,25);
		cout<<"Nhap phai: ";
		gets(phai);
		fflush(stdin);
		if (strcmp(phai,"Nam")==0 || strcmp(phai,"nam")==0){
			strcpy(phai,"Nam");
			break;
		}
		else if (strcmp(phai,"Nu")==0 || strcmp(phai,"nu")==0){
			strcpy(phai,"Nu");
			break;
		}
		else {
			xoaKhung2();
			BaoLoi("Phai khong hop le");
			gotoxy(117,22);
			cout<<"Nhap ma nhan vien: "<<ma<<endl;
			gotoxy(117,23);
			cout<<"Nhap ho nhan vien: "<<ho<<endl;
			gotoxy(117,24);
			cout<<"Nhap ten nhan vien: "<<ten<<endl;
			continue;
		}
	}
	
	while(true){
		fflush(stdin);
		gotoxy(117,26);
		cout<<"Nhap CMND: ";
		gets(cmnd);
		fflush(stdin);
		if (empty_check(cmnd)==1){
			xoaKhung2();
			BaoLoi("CMND khong duoc bo trong");
			gotoxy(117,22);
			cout<<"Nhap ma nhan vien: "<<ma<<endl;
			gotoxy(117,23);
			cout<<"Nhap ho nhan vien: "<<ho<<endl;
			gotoxy(117,24);
			cout<<"Nhap ten nhan vien: "<<ten<<endl;
			gotoxy(117,25);
			cout<<"Nhap phai: "<<phai;
			continue;
		}
		else if (strlen(cmnd)<9 || strlen(cmnd)>12 || char_check(cmnd)==1){
			xoaKhung2();
			BaoLoi("CMND khong hop le");
			gotoxy(117,22);
			cout<<"Nhap ma nhan vien: "<<ma<<endl;
			gotoxy(117,23);
			cout<<"Nhap ho nhan vien: "<<ho<<endl;
			gotoxy(117,24);
			cout<<"Nhap ten nhan vien: "<<ten<<endl;
			gotoxy(117,25);
			cout<<"Nhap phai: "<<phai;
			continue;
		}
		
		else {
			if (Search_CMND(ds,cmnd)!=-1){
				xoaKhung2();
				BaoLoi("CMND bi trung");
				gotoxy(117,22);
				cout<<"Nhap ma nhan vien: "<<ma<<endl;
				gotoxy(117,23);
				cout<<"Nhap ho nhan vien: "<<ho<<endl;
				gotoxy(117,24);
				cout<<"Nhap ten nhan vien: "<<ten<<endl;
				gotoxy(117,25);
				cout<<"Nhap phai: "<<phai;
				continue;
			}
			else break;
		}
	}
		
	nv.MANV=x;	    strcpy(nv.HO,ho);	  strcpy(nv.TEN,ten);
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

void Insert_Last(DS_NV &ds, Nhanvien &nv){
	if (Full_DSNV(ds)==true){
		BaoLoi("Danh sach nhan vien da day");
		return;
	}	
	else{
		ds.nodes[ds.soluong]=new NHANVIEN;
		*ds.nodes[ds.soluong]=nv;
		ds.soluong++;
	}
}

void Insert_Tree(TREE_VATTU &tree, VATTU &vt, string maVT){
	if (tree==NULL){
		tree=new Nodes_Vattu;
		strcpy(tree->MAVT,maVT.c_str());
		strcpy(tree->info.TENVT,vt.TENVT);
		strcpy(tree->info.DVT,vt.DVT);
		tree->info.SLT=vt.SLT;
		
		tree->left=NULL;
		tree->right=NULL;
	}
	else if (strcmp(maVT.c_str(),tree->MAVT)<0){
		Insert_Tree(tree->left,vt,maVT);
	}
	else{
		Insert_Tree(tree->right,vt,maVT);
	}
}

void List_NhanVien_All(DS_NV ds){
	int y=14;
	while(y<43){
		for (int i=0; i<ds.soluong;i++){
			gotoxy(5,y);
			cout<<ds.nodes[i]->MANV<<endl;
			gotoxy(20,y);
			cout<<ds.nodes[i]->HO<<endl;
			gotoxy(35,y);
			cout<<ds.nodes[i]->TEN<<endl;
			gotoxy(50,y);
			cout<<ds.nodes[i]->PHAI<<endl;
			gotoxy(65,y);
			cout<<ds.nodes[i]->CMND<<endl;
			int sl=0;
			for (NODES_HOADON j=ds.nodes[i]->PTR_HD.first;j!=NULL;j=j->next){
				sl++;
			}
			gotoxy(80,y);
			cout<<sl;
			y++;
		}
		break;
		
	}
}

void List_NhanVien_TT(DS_NV ds, int begin, int end){
	int y=14;
	while(y<43){
		for (int i=begin; i<end;i++){
			gotoxy(5,y);
			cout<<ds.nodes[i]->MANV<<endl;
			gotoxy(20,y);
			cout<<ds.nodes[i]->HO<<endl;
			gotoxy(35,y);
			cout<<ds.nodes[i]->TEN<<endl;
			gotoxy(50,y);
			cout<<ds.nodes[i]->PHAI<<endl;
			gotoxy(65,y);
			cout<<ds.nodes[i]->CMND<<endl;
			int sl=0;
			for (NODES_HOADON j=ds.nodes[i]->PTR_HD.first;j!=NULL;j=j->next){
				sl++;
			}
			gotoxy(80,y);
			cout<<sl<<endl;
			y++;
		}
		break;
	}
}

int EmptyHDCheck(DS_NV ds, int viTri){
	if(ds.nodes[viTri]->PTR_HD.first==NULL){
		return 1;
	}
	return 0;
}

void Delete_NhanVien(DS_NV &ds, int ma){
	int kq=Search_NV(ds,ma);
	if  (kq==-1) {
		BaoLoi("Nhan vien khong ton tai");
	}
	else if (EmptyHDCheck(ds,kq)==0){
		BaoLoi("Khong the xoa nhan vien");
	}
	else{
		delete ds.nodes[kq];
		for (int i=kq;i<ds.soluong;i++){
			ds.nodes[i]=ds.nodes[i+1];
		}
		ds.soluong--;
	}
}

void Display_NV(DS_NV &ds, int viTri){
	gotoxy(117,5);
	cout<<"Ma nhan vien: "<<ds.nodes[viTri]->MANV;
	gotoxy(117,6);
	cout<<"Ho nhan vien: "<<ds.nodes[viTri]->HO;
	gotoxy(117,7);
	cout<<"Ten nhan vien: "<<ds.nodes[viTri]->TEN;
	gotoxy(117,8);
	cout<<"Phai: "<<ds.nodes[viTri]->PHAI;
	gotoxy(117,9);
	cout<<"CMND: "<<ds.nodes[viTri]->CMND;
}

void Edit_NV(DS_NV &ds, int ma){
	int kq=Search_NV(ds,ma);
	gotoxy(117,42);
	cout<<kq;
	if (kq==-1) {
		BaoLoi("Nhan vien khong ton tai");
	}
	else{
		Display_NV(ds,kq);
	}
		
	NHANVIEN nv;
	nv=Insert_NV(ds,nv);
	
	//
	ds.nodes[kq]->MANV=nv.MANV;
	strcpy(ds.nodes[kq]->HO,nv.HO);
	strcpy(ds.nodes[kq]->TEN,nv.TEN);
	strcpy(ds.nodes[kq]->PHAI,nv.PHAI);
	strcpy(ds.nodes[kq]->CMND,nv.CMND);
	
	xoaKhung1();
	xoaKhung2();
	BaoLoi("Sua thong tin nhan vien thanh cong");
	GiaoDienMenuQuanLyNhanVien(ds);
}

void ThongKeDoanhThu(DS_NV ds){
	DS_CTHD dscthd;
	char year[4]; 
	char month[2];
	while (true){
		cout<<"Nhap thang muon thong ke: ";
		gets(month);
		if (month==NULL){
			BaoLoi("Thang khong duoc bo trong");
		}
		else if(char_check(month)==1){
			BaoLoi("Thang phai la chu so tu 1-12");
		}
		else if(atoi(month)<1 || atoi(month)>12){
			BaoLoi("Thang phai tu 1-12");
		}
		else {
			cout<<"Nhap nam muon thong ke: ";
			gets(year);
			if (year==NULL){
				BaoLoi("Nam khong duoc bo trong");
			}
			else if(char_check(year)==1){
				BaoLoi("Nam phai la chu so tu 1-12");
			}
			else if(atoi(year)<1990 || atoi(year)>2020){
				BaoLoi("Nam khong hop le");
			}
			else break;
		}
	}
	
	Date date2;
	strcpy(date2.month,month);
	strcpy(date2.year,year);
	
	double doanhthu=0;
	
	for (int i=0;i<ds.soluong;i++){
		if (EmptyHDCheck(ds,i)==0){
			for (NODES_HOADON j=ds.nodes[i]->PTR_HD.first; j!=NULL; j=j->next){
				if (strcmp(j->info.date.month,date2.month)==0 && 
					strcmp(j->info.date.year,date2.year)==0){
					for (int k=0;k<j->info.PTR_CTHD.soluong;k++){
						doanhthu+= doanhthu + (j->info.PTR_CTHD.nodes[k].DonGia * j->info.PTR_CTHD.nodes[k].SL 
												* (1 + (j->info.PTR_CTHD.nodes[k].VAT/100.0)));
					}	
				}
			}
		}
	}
	
	gotoxy(117,42);
	cout<<doanhthu;
}


void CreateList_HOADON(DS_HOADON &dshd){
	dshd.first=NULL;
	dshd.last=NULL;
}

int EmptyList_HOADON(DS_HOADON &dshd){
	if (dshd.first==NULL){
		return 1;
	}
	else return 0;
}

void InsertFirst_HOADON(DS_HOADON &dshd, HOADON &hd){
	if (hd.SOHD==NULL){
		BaoLoi("Hoa don rong");
	}	
	
	NODES_HOADON nodes_hd=new Nodes_Hoadon;
	nodes_hd->info=hd;
	nodes_hd->next=NULL;
	
	if (EmptyList_HOADON(dshd)==1){
		dshd.first=nodes_hd;
		dshd.last=NULL;
	}
	else{
		nodes_hd->next=dshd.first;
		dshd.first=nodes_hd;
	}
}

void InsertLast_HOADON(DS_HOADON &dshd, HOADON &hd){
	if (hd.SOHD==NULL){
		BaoLoi("Hoa don rong");
	}
	
	NODES_HOADON nodes_hd=new Nodes_Hoadon;
	nodes_hd->info=hd;
	nodes_hd->next=NULL;
	
	if (EmptyList_HOADON(dshd)==1){
		dshd.first=nodes_hd;
		dshd.last=NULL;
	}
	else{
		dshd.last->next=nodes_hd->next;
		dshd.last=nodes_hd;
	}
}

void CreateList_CTHD(DS_CTHD &ds_cthd){
	ds_cthd.soluong=0;
}

int FULL_CTHD(DS_CTHD &ds_cthd){
	if (ds_cthd.soluong==20){
		return 1;
	}
	return 0;
}

void InsertLast_CTHD(DS_CTHD &ds_cthd, CHITIET_HOADON &cthd){
	if (FULL_CTHD(ds_cthd)==1){
		BaoLoi("Hoa don da day");
	}
	
	ds_cthd.nodes[ds_cthd.soluong]=cthd;
	ds_cthd.soluong++;
}

void ReadLine_VatTu(string line, VATTU &VT, string maVT){
	int i=0;
	string line_temp="";
	
	while(line[i]!='_'){
		line_temp=line_temp+line[i];
		i++;
	}
	maVT=line_temp;
	line_temp="";
	i++;
	
	while(line[i]!='_'){
		line_temp=line_temp+line[i];
		i++;
	}
	strcpy(VT.TENVT,line_temp.c_str());
	line_temp="";
	i++;
	
	while(line[i]!='_'){
		line_temp=line_temp+line[i];
		i++;
	}
	strcpy(VT.DVT,line_temp.c_str());
	line_temp="";
	i++;
	
	while(line[i]!='_'){
		line_temp=line_temp+line[i];
		i++;
	}
	VT.SLT=atoi(line_temp.c_str());
	line_temp="";
	i++;
}

void ReadFile_VATTU(TREE_VATTU &vatTu, char *fileName){
	fstream f;
	f.open(fileName,ios::in);
	
	if (f.fail()){
		BaoLoi("Khong the doc file vat tu");
		return;
	}	
	
	string line;
	string maVT;
	VATTU VT;
	
	while(!f.eof()){
		getline(f,line);
		if (line==""){
			continue;
		}	
		ReadLine_VatTu(line,VT,maVT);
		Insert_Tree(vatTu,VT,maVT);
	}
	BaoLoi("Doc File thanh cong");
	f.close();
}


void ReadLine_NhanVien(string line, Nhanvien &NV){
	int i=0;
	string line_temp="";
	
	while(line[i]!='_'){
		line_temp=line_temp+line[i];
		i++;
	}
	NV.MANV=atoi(line_temp.c_str());
	line_temp="";
	i++;
	
	while(line[i]!='_'){
		line_temp=line_temp+line[i];
		i++;
	}
	strcpy(NV.HO,line_temp.c_str());
	line_temp="";
	i++;
	
	while(line[i]!='_'){
		line_temp=line_temp+line[i];
		i++;
	}
	strcpy(NV.TEN,line_temp.c_str());
	line_temp="";
	i++;
	
	while(line[i]!='_'){
		line_temp=line_temp+line[i];
		i++;
	}
	strcpy(NV.PHAI,line_temp.c_str());
	line_temp="";
	i++;
	
	while(line[i]!='_'){
		line_temp=line_temp+line[i];
		i++;
	}
	strcpy(NV.CMND,line_temp.c_str());
	line_temp="";
	i++;
	
//	//Doc hoa don
//	CreateList_HOADON(NV.PTR_HD);
//	HOADON hd;
//	while(line[i]!='$'){
//		CreateList_CTHD(hd.PTR_CTHD);
//		
//		while(line[i]!='|'){
//			line_temp=line_temp+line[i];
//			i++;
//		}
//		strcpy(hd.SOHD,line_temp.c_str());
//		line_temp="";
//		i++;
//		
////		while(line[i]!='|'){
////			line_temp=line_temp+line[i];
////			i++;
////		}
////		strcpy(hd.date,line_temp.c_str());
//
//		while(line[i]!='|'){
//			line_temp=line_temp+line[i];
//			i++;
//		}
//		strcpy(hd.LoaiHD,line_temp.c_str());
//		line_temp="";
//		i++;
//		
//		while(line[i]!='*'){
//			CHITIET_HOADON cthd;
//			
//			while(line[i]!='|'){
//				line_temp=line_temp+line[i];
// 				i++;
//			}
//			strcpy(cthd.MAVT,line_temp.c_str());
//			line_temp="";
//			i++;
//			
//			while(line[i]!='|'){
//				line_temp=line_temp+line[i];
//				i++;
//			}
//			cthd.SL=atoi(line_temp.c_str());
//			line_temp="";
//			i++;
//			
//			while(line[i]!='|'){
//				line_temp=line_temp+line[i];
//				i++;
//			}
//			cthd.DonGia=atoi(line_temp.c_str());
//			line_temp="";
//			i++;
//			
//			while(line[i]!='|'){
//				line_temp=line_temp+line[i];
//				i++;
//			}
//			cthd.VAT=atoi(line_temp.c_str());
//			line_temp="";
//			i++;
//			
//			while(line[i]!='|'){
//				line_temp=line_temp+line[i];
//				i++;
//			}
//			cthd.TrangThai=atoi(line_temp.c_str());
//			line_temp="";
//			i++;
//			
//			InsertLast_CTHD(hd.PTR_CTHD,cthd);
//			
//			i++;
//			line_temp="";
//			
//		}
//				
//		InsertLast_HOADON(NV.PTR_HD,hd);
//		line_temp="";
//		i++;
//	}
}

void ReadFile_NV(DS_NV &ds, char *fileName){
	fstream f;
	f.open(fileName,ios::in);
	
	if(f.fail()){
		BaoLoi("Khong the doc file nhan vien");
		return;
	}
	string line;
	Nhanvien NV;
	
	while(!f.eof()){
		getline(f,line);
		if(line==""){
			continue;
		}

		ReadLine_NhanVien(line,NV);
		Insert_Last(ds,NV);
	}
//	BaoLoi("Doc file nhan vien thanh cong");
	f.close();
}

void SaveFile_NV(DS_NV &ds, char *fileName){
	fstream f;
	f.open(fileName,ios::out);
	
	if(f.fail()){
		BaoLoi("Khong the doc file nhan vien");
		return;
	}
	
	for (int i=0;i<ds.soluong;i++){
		f<<ds.nodes[i]->MANV<<"_";
		f<<ds.nodes[i]->HO<<"_";
		f<<ds.nodes[i]->TEN<<"_";
		f<<ds.nodes[i]->PHAI<<"_";
		f<<ds.nodes[i]->CMND<<"_";
		//Ghi hoa don
//		if (EmptyHDCheck(ds,i)==0){
//			for (NODES_HOADON a=ds.nodes[i]->PTR_HD.first; a!=NULL; a=a->next){
//				f<<a->info.SOHD<<"-";
////				f<<a->info.date<<"-";
//				f<<a->info.LoaiHD<<"-";
//				
//				for (int j=0;j<a->info.PTR_CTHD.soluong;i++){
//					f<<a->info.PTR_CTHD.nodes[j].MAVT<<"-";
//					f<<a->info.PTR_CTHD.nodes[j].SL<<"-";
//					f<<a->info.PTR_CTHD.nodes[j].DonGia<<"-";
//					f<<a->info.PTR_CTHD.nodes[j].VAT<<"-";
//					f<<a->info.PTR_CTHD.nodes[j].TrangThai<<"-";
//				}
//				f<<"*";
//			}
//		}
//		f<<"$"<<endl;
		f<<endl;
	}
	
	f.close();
}

// cac ham giao dien
void GiaoDienKhung(){
	//Khung chinh
	VeKhung(1,1,113,44);
	
	//Khung phu 1
	VeKhung(116,1,48,19);
	
	//Khung phu 2
	VeKhung(116,21,48,19);
	
	//Khung phu 3 (Khung thong bao)
	VeKhung(116,41,48,4);
}

void NoColor(){
	SetBGColor(0);
	SetColor(15);
}

void Highlight(){
	SetBGColor(1);
	SetColor(15);
}

void TieuDe(){
	
}

void GiaoDienMenuQuanLyVatTu(TREE_VATTU &ds_vt){
	clrscr();
	GiaoDienKhung();
	gotoxy(5,13);
	cout<<"Ma vat tu";
	gotoxy(20,13);
	cout<<"Ten vat tu";
	gotoxy(35,13);
	cout<<"Don vi tinh";
	gotoxy(50,13);
	cout<<"So luong ton";
	
	gotoxy(5,43);
	cout<<"Ins: Them vat tu moi";
	gotoxy(30,43);
	cout<<"Del: Xoa vat tu";
	gotoxy(5,44);
	cout<<"F1: Chinh sua vat tu";
	gotoxy(30,44);
	cout<<"Esc: Quay lai";
}

void GiaoDienMenuQuanLyNhanVien(DS_NV &ds){
	clrscr();
	GiaoDienKhung();
	gotoxy(5,13);
	cout<<"Ma nhan vien";
	gotoxy(20,13);
	cout<<"Ho";
	gotoxy(35,13);
	cout<<"Ten";
	gotoxy(50,13);
	cout<<"Phai";
	gotoxy(65,13);
	cout<<"CMND";
	gotoxy(80,13);
	cout<<"So HD da lap";
	
	gotoxy(5,43);
	cout<<"Ins: Them nhan vien moi";
	gotoxy(30,43);
	cout<<"Del: Xoa nhan vien";
	gotoxy(5,44);
	cout<<"F1: Chinh sua nhan vien";
	gotoxy(30,44);
	cout<<"Esc: Quay lai";
}

//void GiaoDienDSVatTu(TREE_VATTU &ds){
//	if (ds.soluong>28){
//		tree_Traverse(tree);
//	}
//	else{
//		tree_Traverse(tree);
//	}
//	
//	gotoxy(5,14);
//	Highlight();
//	
//	int x=5,y=14;
//	int dem=0;
//	while (true){
//		int c=getch();
//		if(ds.soluong>28){
//			if (y==14 && dem==0){
//				if (c==72){	//Up
//					clrscr();
//					GiaoDienMenuQuanLyNhanVien(ds);
//					List_NhanVien_TT(ds,ds.soluong-28,ds.soluong);
//					y=41;
//					gotoxy(x,y);
//					dem=ds.soluong--;
//				}
//				if (c==80){	//Down
//					y++;
//					gotoxy(x,y);
//					Highlight();
//					dem++;
//				}
//				if (c==27){ //Esc
//					clrscr();
//					GiaoDienMenuChinh(ds);
//				}
//				if (c==82){	//Insert
//					while(true){
//						NHANVIEN nv;
//						Insert_NV(ds,nv);
//						Insert_Last(ds,nv);
//						BaoLoi("Them nhan vien thanh cong");
//					}
//				}
//				if (c==59){	//F1
//					Edit_NV(ds,ds.nodes[dem]->MANV);
//				}
//			}
//			else if(y>14 && y<41 && dem>0 && dem<ds.soluong--){
//				if (c==72){ //Up
//					y--;
//					dem--;
//					gotoxy(x,y);
//					Highlight();
//				}
//				if (c==80){ //Down
//					y++;
//					dem++;
//					gotoxy(x,y);
//					Highlight();
//				}
//				if (c==27){ //Esc
//					GiaoDienMenuChinh(ds);
//				}
//				if (c==27){ //Esc
//					clrscr();
//					GiaoDienMenuChinh(ds);
//				}
//				if (c==82){	//Insert
//					while(true){
//						NHANVIEN nv;
//						Insert_NV(ds,nv);
//						Insert_Last(ds,nv);
//						BaoLoi("Them nhan vien thanh cong");
//					}
//				}
//				if (c==59){	//F1
//					Edit_NV(ds,ds.nodes[dem]->MANV);
//				}
//			}
//			else if (y==41 && dem==ds.soluong--){
//				if (c==72){	//Up
//					y--;
//					dem--;
//					gotoxy(x,y);
//					Highlight();
//
//				}
//				if (c==80){	//Down
//					clrscr();
//					GiaoDienMenuQuanLyNhanVien(ds);
//					y=14;
//					List_NhanVien_TT(ds,0,28);
//					dem=1;
//					gotoxy(x,y);
//					Highlight();
//				}
//				if (c==27){ //Esc
//					clrscr();
//					GiaoDienMenuChinh(ds);
//				}
//				if (c==82){	//Insert
//					while(true){
//						NHANVIEN nv;
//						Insert_NV(ds,nv);
//						Insert_Last(ds,nv);
//						BaoLoi("Them nhan vien thanh cong");
//					}
//				}
//				if (c==59){	//F1
//					Edit_NV(ds,ds.nodes[dem]->MANV);
//				}
//			}
//			else if(y==14 && dem>0){
//				if (c==72){	//Up
//					dem--;
//					clrscr();
//					GiaoDienMenuQuanLyNhanVien(ds);
//					List_NhanVien_TT(ds,dem,dem+28);
//					gotoxy(x,y);
//				}
//				if (c==80){	//Down
//					dem++;
//					y++;
//					gotoxy(x,y);
//					Highlight();
//				}
//				if (c==27){ //Esc
//					clrscr();
//					GiaoDienMenuChinh(ds);
//				}
//				if (c==82){	//Insert
//					while(true){
//						NHANVIEN nv;
//						Insert_NV(ds,nv);
//						Insert_Last(ds,nv);
//						BaoLoi("Them nhan vien thanh cong");
//					}
//				}
//				if (c==59){	//F1
//					Edit_NV(ds,ds.nodes[dem]->MANV);
//				}
//			}
//			else if(y==41 && dem<ds.soluong--){
//				if (c==72){	//Up
//					dem--;
//					y--;
//					gotoxy(x,y);
//					Highlight();
//				}
//				if (c==80){	//Down
//					dem++;
//					clrscr();
//					GiaoDienMenuQuanLyNhanVien(ds);
//					List_NhanVien_TT(ds,dem-28,dem);
//					gotoxy(x,y);
//				}
//				if (c==27){ //Esc
//					clrscr();
//					GiaoDienMenuChinh(ds);
//				}
//				if (c==82){	//Insert
//					while(true){
//						NHANVIEN nv;
//						Insert_NV(ds,nv);
//						Insert_Last(ds,nv);
//						BaoLoi("Them nhan vien thanh cong");
//					}
//				}
//				if (c==59){	//F1
//					Edit_NV(ds,ds.nodes[dem]->MANV);
//				}		
//			}
//		}
//		
//		//DS it hon 28
//		else{
//			if (y==14 && dem==0){
//				if (c==72){	//Up
//					dem=ds.soluong--;
//					y=ds.soluong+13;
//					gotoxy(x,y);
//				}
//				if (c==80){	//Down
//					y++;
//					dem++;
//					gotoxy(x,y);
//					Highlight();
//				}
//				if (c==27){ //Esc
//					clrscr();
//					GiaoDienMenuChinh(ds);
//				}
//				if (c==82){	//Insert
//					while(true){
//						NHANVIEN nv;
//						Insert_NV(ds,nv);
//						Insert_Last(ds,nv);
//						BaoLoi("Them nhan vien thanh cong");
//					}
//				}
//				if (c==59){	//F1
//					Edit_NV(ds,ds.nodes[dem]->MANV);
//				}
//			}
//			else if(y==ds.soluong+13 && dem==ds.soluong--){
//				if (c==72){	//Up
//					dem--;
//					y--;
//					gotoxy(x,y);
//					Highlight();
//				}
//				if (c==80){	//Down
//					dem=1;
//					y=14;
//					gotoxy(x,y);
//					Highlight();
//				}
//				if (c==27){ //Esc
//					clrscr();
//					GiaoDienMenuChinh(ds);
//				}
//				if (c==82){	//Insert
//					while(true){
//						NHANVIEN nv;
//						Insert_NV(ds,nv);
//						Insert_Last(ds,nv);
//						BaoLoi("Them nhan vien thanh cong");
//					}
//				}
//				if (c==59){	//F1
//					Edit_NV(ds,ds.nodes[dem]->MANV);
//				}
//			}
//			else{
//				if(c==72){	//Up
//					dem--;
//					y--;
//					gotoxy(x,y);
//					Highlight();
//				}
//				if(c==80){	//Down
//					dem++;
//					y++;
//					gotoxy(x,y);
//					Highlight();
//				}
//				if (c==27){ //Esc
//					clrscr();
//					GiaoDienMenuChinh(ds);
//				}
//				if (c==82){	//Insert
//					while(true){
//						NHANVIEN nv;
//						Insert_NV(ds,nv);
//						Insert_Last(ds,nv);
//						BaoLoi("Them nhan vien thanh cong");
//					}
//				}
//				if (c==59){	//F1
//					Edit_NV(ds,ds.nodes[dem]->MANV);
//				}
//			}
//		}
//		
//	}
//}

void GiaoDienDSNhanVien(DS_NV &ds){
	if (ds.soluong>28){
		List_NhanVien_TT(ds,0,28);	
	}
	else{
		List_NhanVien_All(ds);
	}
	
	gotoxy(5,14);
	Highlight();
	
	int x=5,y=14;
	int dem=0;
	while (true){
		int c=getch();
		if(ds.soluong>28){
			if (y==14 && dem==0){
				if (c==72){	//Up
					clrscr();
					GiaoDienMenuQuanLyNhanVien(ds);
					List_NhanVien_TT(ds,ds.soluong-28,ds.soluong);
					y=41;
					gotoxy(x,y);
					dem=ds.soluong--;
				}
				if (c==80){	//Down
					y++;
					gotoxy(x,y);
					Highlight();
					dem++;
				}
				if (c==27){ //Esc
					clrscr();
					GiaoDienMenuChinh(ds);
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						Insert_NV(ds,nv);
						if(nv.MANV!=NULL){
							Insert_Last(ds,nv);
							BaoLoi("Them nhan vien thanh cong");						
						}

					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
				}
				if (c==13){	//Enter
					//Hoa don nhan vien da lap cau h
				}
			}
			else if(y>14 && y<41 && dem>0 && dem<ds.soluong--){
				if (c==72){ //Up
					y--;
					dem--;
					gotoxy(x,y);
					Highlight();
				}
				if (c==80){ //Down
					y++;
					dem++;
					gotoxy(x,y);
					Highlight();
				}
				if (c==27){ //Esc
					GiaoDienMenuChinh(ds);
				}
				if (c==27){ //Esc
					clrscr();
					GiaoDienMenuChinh(ds);
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						Insert_NV(ds,nv);
						if(nv.MANV!=NULL){
							Insert_Last(ds,nv);
							BaoLoi("Them nhan vien thanh cong");						
						}					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
				}
				if (c==13){	//Enter
					//Hoa don nhan vien da lap cau h
				}
			}
			else if (y==41 && dem==ds.soluong--){
				if (c==72){	//Up
					y--;
					dem--;
					gotoxy(x,y);
					Highlight();

				}
				if (c==80){	//Down
					clrscr();
					GiaoDienMenuQuanLyNhanVien(ds);
					y=14;
					List_NhanVien_TT(ds,0,28);
					dem=1;
					gotoxy(x,y);
					Highlight();
				}
				if (c==27){ //Esc
					clrscr();
					GiaoDienMenuChinh(ds);
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						Insert_NV(ds,nv);
						if(nv.MANV!=NULL){
							Insert_Last(ds,nv);
							BaoLoi("Them nhan vien thanh cong");						
						}
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
				}
				if (c==13){	//Enter
					//Hoa don nhan vien da lap cau h
				}
			}
			else if(y==14 && dem>0){
				if (c==72){	//Up
					dem--;
					clrscr();
					GiaoDienMenuQuanLyNhanVien(ds);
					List_NhanVien_TT(ds,dem,dem+28);
					gotoxy(x,y);
				}
				if (c==80){	//Down
					dem++;
					y++;
					gotoxy(x,y);
					Highlight();
				}
				if (c==27){ //Esc
					clrscr();
					GiaoDienMenuChinh(ds);
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						Insert_NV(ds,nv);
						if(nv.MANV!=NULL){
							Insert_Last(ds,nv);
							BaoLoi("Them nhan vien thanh cong");						
						}
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
				}
				if (c==13){	//Enter
					//Hoa don nhan vien da lap cau h
				}
			}
			else if(y==41 && dem<ds.soluong--){
				if (c==72){	//Up
					dem--;
					y--;
					gotoxy(x,y);
					Highlight();
				}
				if (c==80){	//Down
					dem++;
					clrscr();
					GiaoDienMenuQuanLyNhanVien(ds);
					List_NhanVien_TT(ds,dem-28,dem);
					gotoxy(x,y);
				}
				if (c==27){ //Esc
					clrscr();
					GiaoDienMenuChinh(ds);
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						Insert_NV(ds,nv);
						if(nv.MANV!=NULL){
							Insert_Last(ds,nv);
							BaoLoi("Them nhan vien thanh cong");						
						}
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
				}
				if (c==13){	//Enter
					//Hoa don nhan vien da lap cau h
				}
			}
		}
		
		//DS it hon 28
		else{
			if (y==14 && dem==0){
				if (c==72){	//Up
					dem=ds.soluong--;
					y=ds.soluong+13;
					gotoxy(x,y);
				}
				if (c==80){	//Down
					y++;
					dem++;
					gotoxy(x,y);
					Highlight();
				}
				if (c==27){ //Esc
					clrscr();
					GiaoDienMenuChinh(ds);
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						Insert_NV(ds,nv);
						if(nv.MANV!=NULL){
							Insert_Last(ds,nv);
							BaoLoi("Them nhan vien thanh cong");						
						}
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
				}
				if (c==13){	//Enter
					//Hoa don nhan vien da lap cau h
				}
			}
			else if(y==ds.soluong+13 && dem==ds.soluong--){
				if (c==72){	//Up
					dem--;
					y--;
					gotoxy(x,y);
					Highlight();
				}
				if (c==80){	//Down
					dem=1;
					y=14;
					gotoxy(x,y);
					Highlight();
				}
				if (c==27){ //Esc
					clrscr();
					GiaoDienMenuChinh(ds);
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						Insert_NV(ds,nv);
						if(nv.MANV!=NULL){
							Insert_Last(ds,nv);
							BaoLoi("Them nhan vien thanh cong");						
						}
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
				}
				if (c==13){	//Enter
					//Hoa don nhan vien da lap cau h
				}
			}
			else{
				if(c==72){	//Up
					dem--;
					y--;
					gotoxy(x,y);
					Highlight();
				}
				if(c==80){	//Down
					dem++;
					y++;
					gotoxy(x,y);
					Highlight();
				}
				if (c==27){ //Esc
					clrscr();
					GiaoDienMenuChinh(ds);
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						Insert_NV(ds,nv);
						if(nv.MANV!=NULL){
							Insert_Last(ds,nv);
							BaoLoi("Them nhan vien thanh cong");						
						}
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
				}
				if (c==13){	//Enter
					//Hoa don nhan vien da lap cau h
				}
			}
		}
		
	}
}

void GiaoDienMenuChinh(DS_NV &ds_nv, TREE_VATTU &ds_vt){
	//Tieu de
	TieuDe();	
	
	//Khung phu
	GiaoDienKhung();
	
	//Lua chon Menu
	gotoxy(5,13);
	cout<<"1. Quan ly vat tu";
	gotoxy(5,19);
	cout<<"2. Quan ly nhan vien";
	gotoxy(5,25);
	cout<<"3. Quan ly hoa don";
	gotoxy(5,31);
	cout<<"4. Thong ke doanh thu theo nam";
	gotoxy(5,37);
	cout<<"5.Thoat chuong trinh";
	gotoxy(5,44);
	cout<<"Enter: Lua chon";
	gotoxy(5,13);
	Highlight();
	int x=5,y=13;
	while(true){
		int c=getch();
		if(y>13 && y<40){
			if(c==DOWN){
				y=y+6;
				NoColor();
				gotoxy(x,y);
				Highlight();
			}
			else if (c==UP){
				y=y-6;
				NoColor();
				gotoxy(x,y);
				Highlight();
			}
		}
		else if(y==37){
			if(c==UP){
				y=y-6;
				NoColor();
				gotoxy(x,y);
				Highlight();
			}
			else if(c==DOWN){
				NoColor();
				y=13;
				gotoxy(x,y);
				Highlight();
			}
		}
		else if(y==13){
			if(c==DOWN){
				y=y+6;
				NoColor();
				Highlight();
			}
			else if (c==UP){
				NoColor();
				y=37;
				gotoxy(x,y);
				Highlight();
			}
		}
		
		if (c==ENTER){
			y=wherey();
			switch(y){
				case 13:{
					GiaoDienMenuQuanLyVatTu(ds_vt);
					
				}
				case 16:{
					GiaoDienMenuQuanLyNhanVien(ds_nv);
					GiaoDienDSNhanVien(ds_nv);
				}
				case 25:{
					
				}
				case 31:{
					ThongKeDoanhThu(ds_nv);
				}
				case 37:{
					xoaKhungThongBao();
					gotoxy(117,44);
					cout<<"Ban co chac chan muon thoat? (Y/N): ";
					char thoat[3];
					gets(thoat);
					if (strcmp(thoat,"Y")==0 || strcmp(thoat,"Yes")==0 || 
						strcmp(thoat,"y")==0 || strcmp(thoat,"yes")==0){
							return;
					}
					else{
						xoaKhungThongBao();
						gotoxy(5,13);	
					}
				}
			}
		}
	}
}

int main(){
	resizeConsole(1920,1080);
	
	DS_CTHD dscthd;
	dscthd.soluong=0;

	DS_HOADON dshd;
	dshd.first=NULL;

	DS_NV ds_nv;
	NHANVIEN nv;
	ds_nv.soluong=0;
	
	TREE_VATTU ds_vt;
	VATTU vt;
	ds_vt=NULL;
	
	
	ReadFile_NV(ds_nv,"NhanVien.txt");
	GiaoDienMenuChinh(ds_nv);
//	Insert_NV(ds_nv,nv);
//	Insert_Last(ds_nv,nv);

//	Edit_NV(ds_nv,2);
//	Display_NV(ds_nv,2);
////	Edit_NV(ds_nv,2);
////	List_NhanVien(ds_nv);
//	SaveFile_NV(ds_nv,"NhanVien.txt");
	
//	ReadFile_VATTU(ds_vt,"VatTu.txt");
//	treeTraverse(ds_vt);

}
