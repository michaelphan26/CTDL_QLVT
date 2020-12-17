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

void GiaoDienMenuChinh(DS_NV &ds_nv,TREE_VATTU &ds_vt);
void GiaoDienMenuQuanLyNhanVien();
void GiaoDienDSNhanVien(DS_NV &ds_nv,TREE_VATTU &ds_vt);

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

void xoaToanBoKhungPhu(){
	xoaKhung1();
	xoaKhung2();
	xoaKhungThongBao();
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
	xoaKhung2();
	char ma[3];
	char ho[10];
	char ten[20];
	char phai[5];
	char cmnd[12];

	while(true){
		gotoxy(125,25);
		cout<<"Nhap ma nhan vien: ";
		InputNumber(ma,3);
		if (strcmp(ma,"quit")==0){
			xoaKhung2();
			nv.MANV=-1;
			return nv;
		}	
		if (Search_NV(ds,atoi(ma))==1){
			thongBaoLoi("Ma nhan vien bi trung");
			getch();
			continue;
		}
		break;
	}
	

	gotoxy(125,26);
	cout<<"Nhap ho nhan vien: ";
	InputStringSpace(ho,20);
	if (strcmp(cmnd,"quit")==0){
		xoaKhung2();
		nv.MANV=-1;
		return nv;
	}
	
	gotoxy(125,27);
	cout<<"Nhap ten nhan vien: ";
	InputString(ten,20);
	if (strcmp(cmnd,"quit")==0){
		xoaKhung2();
		nv.MANV=-1;
		return nv;
	}
	
	while(true){
		gotoxy(125,28);
		cout<<"Nhap phai: ";
		InputString(phai,3);
		if (strcmp(phai,"quit")==0){
			xoaKhung2();
			nv.MANV=-1;
			return nv;
		}
		if (stricmp(phai,"nam")==0 || stricmp(phai,"Nam")==0){
			strcpy(phai,"Nam");
			break;
		}
		if (stricmp(phai,"nu")==0 || stricmp(phai,"Nu")==0) {
			strcpy(phai,"Nu");
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
		InputNumber(cmnd,12);
		if (strcmp(cmnd,"quit")==0){
			xoaKhung2();
			nv.MANV=-1;
			break;
		}
		if (strlen(cmnd)<9 || strlen(cmnd)>12){
			thongBaoLoi("CMND khong hop le");
			getch();
			xoaKhungThongBao();
			continue;
		}
		if (Search_CMND(ds,cmnd)==1){
			thongBaoLoi("CMND nhan vien bi trung");
			getch();
			xoaKhungThongBao();
			continue;
		}
		break;
	}
		
	nv.MANV=atoi(ma);	    strcpy(nv.HO,ho);	  strcpy(nv.TEN,ten);
	strcpy(nv.PHAI,phai);	
	strcpy(nv.CMND,cmnd);
	return nv;		
}

void Insert_DSNV(DS_NV &ds){
	if (Full_DSNV(ds)==true)	return;	//thongBaoLoi("Danh sach nhan vien da day");
	else{
		NHANVIEN nv;
		ds.nodes[ds.soluong]=new NHANVIEN;
		*ds.nodes[ds.soluong]=Insert_NV(ds,nv);
		ds.soluong++;
	}
}

void Insert_Last(DS_NV &ds, Nhanvien &nv){
	if (Full_DSNV(ds)==true){
		thongBaoLoi("Danh sach nhan vien da day");
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
		thongBaoLoi("Nhan vien khong ton tai");
	}
	else if (EmptyHDCheck(ds,kq)==0){
		thongBaoLoi("Khong the xoa nhan vien");
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
		thongBaoLoi("Nhan vien khong ton tai");
	}
	else{
		Display_NV(ds,kq);
	}
		
	NHANVIEN nv;
	nv=Insert_NV(ds,nv);
	
	//
	if(nv.MANV!=-1){
		ds.nodes[kq]->MANV=nv.MANV;
		strcpy(ds.nodes[kq]->HO,nv.HO);
		strcpy(ds.nodes[kq]->TEN,nv.TEN);
		strcpy(ds.nodes[kq]->PHAI,nv.PHAI);
		strcpy(ds.nodes[kq]->CMND,nv.CMND);
		xoaKhung1();
		xoaKhung2();
		thongBaoLoi("Sua thong tin nhan vien thanh cong");
		GiaoDienMenuQuanLyNhanVien();
	}
	else{
		xoaKhung1();
		xoaKhung2();
		GiaoDienMenuQuanLyNhanVien();
	}
}

void GiaoDienHienHoaDonNhanVien(DS_NV ds, TREE_VATTU ds_vt, int viTri){
	clrscr();
	giaoDienKhung();
	gotoxy(5,14);
	cout<<"5 hoa don gan nhat";
	gotoxy(5,44);
	cout<<"Esc: Quay lai";
	
	int y=16;
	int dem=0;
	if (EmptyHDCheck(ds,viTri)==0){
		for (NODES_HOADON j=ds.nodes[viTri]->PTR_HD.first; j!=NULL; j=j->next){
			dem++;
		}
	}
	if(dem>5){
		dem=dem-4;
	}
	if (EmptyHDCheck(ds,viTri)==0){
		for (NODES_HOADON j=ds.nodes[viTri]->PTR_HD.first; j!=NULL; j=j->next){
			dem--;
			if(dem<1){
				gotoxy(5,y);
				cout<<"So HD: "<<j->info.SOHD;
				y++;
				gotoxy(5,y);
				cout<<"Ngay lap: "<<j->info.date.day<<"/"<<j->info.date.month<<"/"<<j->info.date.year;
				y++;
				gotoxy(5,y);
				cout<<"Loai HD: "<<j->info.LoaiHD;
				y+=2;
				
			}
		}
	}
}

void Sort_NhanVien(DS_NV &ds){
	for (int i=0;i<ds.soluong;i++){
		for (int j=i+1;j<ds.soluong;j++){
			if (strcmp(ds.nodes[i]->TEN,ds.nodes[j]->TEN)>0){
				NHANVIEN *nv;
				nv=ds.nodes[i];
				ds.nodes[i]=ds.nodes[j];
				ds.nodes[j]=nv;
			}
			else if(strcmp(ds.nodes[i]->TEN,ds.nodes[j]->TEN)==0){
				if(strcmp(ds.nodes[i]->HO,ds.nodes[j]->HO)>0){
					NHANVIEN *nv;
					nv=ds.nodes[i];
					ds.nodes[i]=ds.nodes[j];
					ds.nodes[j]=nv;
				}	
			}
		}
	}	
}


void ThongKeDoanhThu(DS_NV ds,TREE_VATTU ds_vt){
	clrscr();
	giaoDienKhung();
	DS_CTHD dscthd;
	char year_insert[4]; 
	char month_insert[2];
	gotoxy(5,44);
	cout<<"Esc: Quay lai";	
	gotoxy(30,44);
	cout<<"Nhap quit huy viec nhap lieu";
	
	while(true){
		gotoxy(5,13);
		cout << "Nhap thang: ";
		InputNumber(month_insert,2);
		if(strcmp(month_insert,"quit")==0){
			break;
		}
		if(atoi(month_insert)<1 || atoi(month_insert)>12){
			clrscr();
			giaoDienKhung();
			thongBaoLoi("Thang khong hop le");
			gotoxy(5,44);
			cout<<"Esc: Quay lai";	
			gotoxy(30,44);
			cout<<"Nhap quit huy viec nhap lieu";
			continue;
		}
		else break;
	}
	if(strcmp(month_insert,"quit")==0){
		return;
	}
	
	while(true){
		gotoxy(5,14);
		cout << "Nhap nam: ";
		InputNumber(year_insert,4);
		if(strcmp(year_insert,"quit")==0){
			break;
		}
		if(atoi(year_insert)<1990 || atoi(year_insert)>2020){
			clrscr();
			giaoDienKhung();
			gotoxy(5,44);
			cout<<"Esc: Quay lai";	
			gotoxy(30,44);
			cout<<"Nhap quit huy viec nhap lieu";
			gotoxy(5,13);
			cout << "Nhap thang: "<<month_insert;
			thongBaoLoi("Nam khong hop le");
			continue;
		}
		else break;
	}
	if(strcmp(year_insert,"quit")==0){
		return;
	}

	
	Date date2;
	strcpy(date2.month,month_insert);
	strcpy(date2.year,year_insert);
	
	double doanhthu=0;
	
	for (int i=0;i<ds.soluong;i++){
		if (EmptyHDCheck(ds,i)==0){
			for (NODES_HOADON j=ds.nodes[i]->PTR_HD.first; j!=NULL; j=j->next){
				if (atoi(j->info.date.month)==atoi(date2.month) && 
					atoi(j->info.date.year)==atoi(date2.year)){
					for (int k=0;k<j->info.PTR_CTHD.soluong;k++){
						doanhthu+= doanhthu + (j->info.PTR_CTHD.nodes[k].DonGia * j->info.PTR_CTHD.nodes[k].SL 
												* (1 + (j->info.PTR_CTHD.nodes[k].VAT/100.0)));
					}	
				}
			}
		}
	}
	
	gotoxy(5,15);
	cout<<"Doanh thu thang "<<date2.month<<"/"<<date2.year<<": "<<doanhthu<<endl;
	thongBaoLoi("Nhan phim bat ky de tiep tuc");
	char c=getch();
	if (c!=27){
		ThongKeDoanhThu(ds,ds_vt);
	}
	else return;
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
		thongBaoLoi("Hoa don rong");
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
		thongBaoLoi("Hoa don rong");
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

int FULL_CTHD(DS_CTHD ds_cthd){
	if (ds_cthd.soluong==MAXVT){
		return 1;
	}
	return 0;
}

void InsertLast_CTHD(DS_CTHD &ds_cthd,CHITIET_HOADON cthd){
	if (FULL_CTHD(ds_cthd)==1){ 
		thongBaoLoi("Hoa don da day");
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
		thongBaoLoi("Khong the doc file vat tu");
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
	thongBaoLoi("Doc File thanh cong");
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
	
	//Doc hoa don
	CreateList_HOADON(NV.PTR_HD);
	HOADON hd;
	while(line[i]!='$'){
		CreateList_CTHD(hd.PTR_CTHD);
		CHITIET_HOADON cthd;
		
		while(line[i]!='|'){
			line_temp=line_temp+line[i];
			i++;
		}
		strcpy(hd.SOHD,line_temp.c_str());
		line_temp="";
		i++;
		
		while(line[i]!='|'){
			line_temp=line_temp+line[i];
			i++;
		}
		strcpy(hd.date.day,line_temp.c_str());
		line_temp="";
		i++;
		
		while(line[i]!='|'){
			line_temp=line_temp+line[i];
			i++;
		}
		strcpy(hd.date.month,line_temp.c_str());
		line_temp="";
		i++;
		
		while(line[i]!='|'){
			line_temp=line_temp+line[i];
			i++;
		}
		strcpy(hd.date.year,line_temp.c_str());
		line_temp="";
		i++;

		while(line[i]!='|'){
			line_temp=line_temp+line[i];
			i++;
		}
		strcpy(hd.LoaiHD,line_temp.c_str());
		line_temp="";
		i++;
		
		while(line[i]!='*'){
			while(line[i]!='!'){
				line_temp=line_temp+line[i];
 				i++;
			}
			strcpy(cthd.MAVT,line_temp.c_str());
			line_temp="";
			i++;
			
			while(line[i]!='!'){
				line_temp=line_temp+line[i];
				i++;
			}
			cthd.SL=atoi(line_temp.c_str());
			line_temp="";
			i++;
			
			while(line[i]!='!'){
				line_temp=line_temp+line[i];
				i++;
			}
			cthd.DonGia=atoi(line_temp.c_str());
			line_temp="";
			i++;
			
			while(line[i]!='!'){
				line_temp=line_temp+line[i];
				i++;
			}
			cthd.VAT=atoi(line_temp.c_str());
			line_temp="";
			i++;
			
			while(line[i]!='!'){
				line_temp=line_temp+line[i];
				i++;
			}
			cthd.TrangThai=atoi(line_temp.c_str());
			line_temp="";
			i++;
			
			InsertLast_CTHD(hd.PTR_CTHD,cthd);
				
		}
		InsertLast_HOADON(NV.PTR_HD,hd);
		line_temp="";
		i++;
		
	}
}

void ReadFile_NV(DS_NV &ds, char* fileName){
	fstream f;
	f.open(fileName,ios::in);
	
	if(f.fail()){
		thongBaoLoi("Khong the doc file nhan vien");
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
	
	Sort_NhanVien(ds);
	thongBaoLoi("Doc file nhan vien thanh cong");
	f.close();
}

void SaveFile_NV(DS_NV &ds, char *fileName){
	fstream f;
	f.open(fileName,ios::out);
	
	if(f.fail()){
		thongBaoLoi("Khong the doc file nhan vien");
		return;
	}
	
	for (int i=0;i<ds.soluong;i++){
		f<<ds.nodes[i]->MANV<<"_";
		f<<ds.nodes[i]->HO<<"_";
		f<<ds.nodes[i]->TEN<<"_";
		f<<ds.nodes[i]->PHAI<<"_";
		f<<ds.nodes[i]->CMND<<"_";
		//Ghi hoa don
		if (EmptyHDCheck(ds,i)==0){
			for (NODES_HOADON a=ds.nodes[i]->PTR_HD.first; a!=NULL; a=a->next){
				f<<a->info.SOHD<<"|";
				f<<a->info.date.day<<"|";
				f<<a->info.date.month<<"|";
				f<<a->info.date.year<<"|";
				f<<a->info.LoaiHD<<"|";
				
				for (int j=0;j<a->info.PTR_CTHD.soluong;i++){
					f<<a->info.PTR_CTHD.nodes[j].MAVT<<"!";
					f<<a->info.PTR_CTHD.nodes[j].SL<<"!";
					f<<a->info.PTR_CTHD.nodes[j].DonGia<<"!";
					f<<a->info.PTR_CTHD.nodes[j].VAT<<"!";
					f<<a->info.PTR_CTHD.nodes[j].TrangThai<<"!";
				}
				f<<"*";
			}
		}
		f<<"$"<<endl;
		f<<endl;
	}
	
	f.close();
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

void GiaoDienMenuQuanLyNhanVien(){
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
	gotoxy(55,43);
	cout<<"Nhap quit huy viec nhap lieu";
}

void GiaoDienDSNhanVien(DS_NV &ds, TREE_VATTU &ds_vt){
	GiaoDienMenuQuanLyNhanVien();
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
					GiaoDienMenuQuanLyNhanVien();
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
					GiaoDienMenuChinh(ds,ds_vt);
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						Insert_NV(ds,nv);
						if(nv.MANV!=-1){
							Insert_Last(ds,nv);		
							thongBaoLoi("Them nhan vien thanh cong");
			
						}
						else GiaoDienDSNhanVien(ds,ds_vt);

					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
				}
				if (c==13){	//Enter
					GiaoDienHienHoaDonNhanVien(ds,ds_vt,dem);
					char c=getch();
					if(c==27){
						clrscr();
						GiaoDienDSNhanVien(ds,ds_vt);	
					}
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
					clrscr();
					GiaoDienMenuChinh(ds,ds_vt);
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						Insert_NV(ds,nv);
						if(nv.MANV!=-1){
							Insert_Last(ds,nv);
							thongBaoLoi("Them nhan vien thanh cong");						
						}					
						else GiaoDienDSNhanVien(ds,ds_vt);
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
				}
				if (c==13){	//Enter
					GiaoDienHienHoaDonNhanVien(ds,ds_vt,dem);
					char c=getch();
					if(c==27){
						clrscr();
						GiaoDienDSNhanVien(ds,ds_vt);	
					}
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
					GiaoDienMenuQuanLyNhanVien();
					y=14;
					List_NhanVien_TT(ds,0,28);
					dem=1;
					gotoxy(x,y);
					Highlight();
				}
				if (c==27){ //Esc
					clrscr();
					GiaoDienMenuChinh(ds,ds_vt);
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						Insert_NV(ds,nv);
						if(nv.MANV!=-1){
							Insert_Last(ds,nv);
							thongBaoLoi("Them nhan vien thanh cong");						
						}
						else GiaoDienDSNhanVien(ds,ds_vt);
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
				}
				if (c==13){	//Enter
					GiaoDienHienHoaDonNhanVien(ds,ds_vt,dem);
					char c=getch();
					if(c==27){
						clrscr();
						GiaoDienDSNhanVien(ds,ds_vt);	
					}
				}
			}
			else if(y==14 && dem>0){
				if (c==72){	//Up
					dem--;
					clrscr();
					GiaoDienMenuQuanLyNhanVien();
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
					GiaoDienMenuChinh(ds,ds_vt);
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						Insert_NV(ds,nv);
						if(nv.MANV!=-1){
							Insert_Last(ds,nv);
							thongBaoLoi("Them nhan vien thanh cong");						
						}
						else GiaoDienDSNhanVien(ds,ds_vt);
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
				}
				if (c==13){	//Enter
					GiaoDienHienHoaDonNhanVien(ds,ds_vt,dem);
					char c=getch();
					if(c==27){
						clrscr();
						GiaoDienDSNhanVien(ds,ds_vt);
					}
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
					GiaoDienMenuQuanLyNhanVien();
					List_NhanVien_TT(ds,dem-28,dem);
					gotoxy(x,y);
				}
				if (c==27){ //Esc
					clrscr();
					GiaoDienMenuChinh(ds,ds_vt);
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						Insert_NV(ds,nv);
						if(nv.MANV!=-1){
							Insert_Last(ds,nv);
							thongBaoLoi("Them nhan vien thanh cong");						
						}
						else GiaoDienDSNhanVien(ds,ds_vt);
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
				}
				if (c==13){	//Enter
					GiaoDienHienHoaDonNhanVien(ds,ds_vt,dem);
					char c=getch();
					if(c==27){
						clrscr();
						GiaoDienDSNhanVien(ds,ds_vt);	
					}
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
					GiaoDienMenuChinh(ds,ds_vt);
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						Insert_NV(ds,nv);
						if(nv.MANV!=-1){
							Insert_Last(ds,nv);
							thongBaoLoi("Them nhan vien thanh cong");						
						}
						else GiaoDienDSNhanVien(ds,ds_vt);
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
				}
				if (c==13){	//Enter
					GiaoDienHienHoaDonNhanVien(ds,ds_vt,dem);
					char c=getch();
					if(c==27){
						clrscr();
						GiaoDienDSNhanVien(ds,ds_vt);	
					}
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
					GiaoDienMenuChinh(ds,ds_vt);
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						Insert_NV(ds,nv);
						if(nv.MANV!=-1){
							Insert_Last(ds,nv);
							thongBaoLoi("Them nhan vien thanh cong");						
						}
						else GiaoDienDSNhanVien(ds,ds_vt);
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
				}
				if (c==13){	//Enter
					GiaoDienHienHoaDonNhanVien(ds,ds_vt,dem);
					char c=getch();
					if(c==27){
						clrscr();
						GiaoDienDSNhanVien(ds,ds_vt);	
					}
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
					GiaoDienMenuChinh(ds,ds_vt);
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						Insert_NV(ds,nv);
						if(nv.MANV!=-1){
							Insert_Last(ds,nv);
							thongBaoLoi("Them nhan vien thanh cong");						
						}
						else GiaoDienDSNhanVien(ds,ds_vt);
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
				}
				if (c==13){	//Enter
					GiaoDienHienHoaDonNhanVien(ds,ds_vt,dem);
					char c=getch();
					if(c==27){
						clrscr();
						GiaoDienDSNhanVien(ds,ds_vt);
					}
				}
			}
		}
	}
}

void GiaoDienMenuChinh(DS_NV &ds_nv, TREE_VATTU &ds_vt){
	clrscr();
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
	gotoxy(30,44);
	cout<<"Esc: Thoat";
	gotoxy(5,13);
	Highlight();
	int x=5,y=13;
	while(true){
		int c=getch();
		if(y>13 && y<37){
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
		if (c==ESC){
			xoaKhungThongBao();
			gotoxy(122,44);
			cout<<"Ban co chac chan muon thoat? (Y/N): ";
			char thoat[3];
			gets(thoat);
			if (strcmp(thoat,"Y")==0 || strcmp(thoat,"y")==0 || 
				strcmp(thoat,"Yes")==0 || strcmp(thoat,"yes")==0){
					return;
			}
			else{
				xoaKhungThongBao();
				gotoxy(5,13);	
			}
		}
		if (c==ENTER){
			y=wherey();
			switch(y){
				case 13:{
					GiaoDienMenuQuanLyVatTu(ds_vt);
					
				}
				case 16:{
					GiaoDienMenuQuanLyNhanVien();
					GiaoDienDSNhanVien(ds_nv,ds_vt);
				}
				case 25:{
					
				}
				case 31:{
					ThongKeDoanhThu(ds_nv,ds_vt);
					GiaoDienMenuChinh(ds_nv,ds_vt);
				}
				case 37:{
					xoaKhungThongBao();
					gotoxy(122,44);
					cout<<"Ban co chac chan muon thoat? (Y/N): ";
					char thoat[3];
					gets(thoat);
					if (strcmp(thoat,"Y")==0 || strcmp(thoat,"y")==0 || 
						strcmp(thoat,"Yes")==0 || strcmp(thoat,"yes")==0){
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

	DS_NV ds_nv;
	NHANVIEN nv;
	ds_nv.soluong=0;
	
	TREE_VATTU ds_vt;
	VATTU vt;
	ds_vt=NULL;

	
	ReadFile_NV(ds_nv,"NhanVien.txt");
	GiaoDienMenuChinh(ds_nv,ds_vt);
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
