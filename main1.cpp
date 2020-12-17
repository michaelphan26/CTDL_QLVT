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

// cac ham giao dien
void giaoDienKhung(){
	//Khung chinh
	VeKhung(43,1,1,113,"");
	
	//Khung phu 1
	VeKhung(21,116,1,48,"");
	
	//Khung phu 2
	VeKhung(21,116,23,48,"");
}

void xoaKhung2(){
	for (int i=117;i<=163;i++){
		for (int j=24;j<=43;j++){
			gotoxy(i,j);
			cout<<"";
		}
	}
}

void NoColor(){
	SetBGColor(0);
	SetColor(15);
}

void Highlight(){
	SetBGColor(1);
	SetColor(15);
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
	Highlight();
	int x=5,y=13;
	while(true){
		int c=getch();
		if(y>13 && y<40){
			if(c==DOWN){
				y=y+3;
				NoColor();
				gotoxy(x,y);
				Highlight();
			}
			else if (c==UP){
				y=y-3;
				NoColor();
				gotoxy(x,y);
				Highlight();
			}
		}
		else if(y==40){
			if(c==UP){
				y=y-3;
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
				y=y+3;
				NoColor();
				Highlight();
			}
			else if (c==UP){
				NoColor();
				y=40;
				gotoxy(x,y);
				Highlight();
			}
		}
		
		if (c==ENTER){
			y=wherey();
			
		}
	}
}

void treeTraverse(TREE_VATTU tree){	//Inorder
	int MaxTraverse=500;
	TREE_VATTU Stack[MaxTraverse];
	int stack_point=-1;
	while(true){
		while (tree!=NULL){
			Stack[stack_point++]=tree;
			tree=tree->left;
		}
		if (stack_point!=-1){
			tree=Stack[stack_point--];
			tree=tree->right;
		}
		else break;
	}
	
	clrscr();
	gotoxy(5,13);
	cout<<"Ma VT";
	gotoxy(15,13);
	cout<<"Ten VT";
	gotoxy(35,13);
	cout<<"DVT";
	gotoxy(45,13);
	cout<<"SLTon";
	
	int y=15;
	for (int i=stack_point;i>-1;i--){
		gotoxy(5,y);
		cout<<tree->MAVT;
		gotoxy(15,y);
		cout<<tree->info.TENVT;
		gotoxy(35,y);
		cout<<tree->info.DVT;
		gotoxy(45,y);
		cout<<tree->info.SLT;
	}
	
}

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
		else return -1;
	}
}

int Search_CMND(DS_NV &ds, char *cmnd){
	for (int i=0;i<ds.soluong;i++){
		if(ds.nodes[i]->CMND==cmnd) return i;
		else return -1;
	}	
}

NHANVIEN Insert_NV(DS_NV &ds, NHANVIEN &nv){
//	xoaKhung2();
	int x;
	char ma[3];
	char ho[10];
	char ten[20];
	char phai[5];
	char cmnd[12];
	while(true){
		fflush(stdin);
		cout<<"Nhap ma nhan vien: ";
		gets(ma);
		fflush(stdin);
		sscanf(ma,"%d",&x);
		if (int_check(ma)==0){
			clrscr();
			BaoLoi("Ma nhan vien khong hop le");
			continue;
		}
//		else if (Search_NV(ds,x)!=-1){
//			clrscr();
//			BaoLoi("Ma nhan vien bi trung");
//			continue;
//		}
		else {
			break;
		}
	}
	
	while(true){
		fflush(stdin);
		cout<<"Nhap ho nhan vien: ";
		gets(ho);
		fflush(stdin);
		if (empty_check(ho)==1){
			clrscr();
			BaoLoi("Ho nhan vien khong duoc de trong");
			cout<<"Nhap ma nhan vien: "<<ma<<endl;
			continue;
		}
		else if (char_check(ho)==0){
			clrscr();
			BaoLoi("Ho khong the chua ky tu so");
			cout<<"Nhap ma nhan vien: "<<ma<<endl;
			continue;		
		}
		else{
			while(true){
				cout<<"Nhap ten nhan vien: ";
				gets(ten);
				fflush(stdin);
				if (empty_check(ten)==1){
					clrscr();
					BaoLoi("Ten nhan vien khong duoc de trong");
					cout<<"Nhap ma nhan vien: "<<ma<<endl;
					cout<<"Nhap ho nhan vien: "<<ho<<endl;
					continue;
				}
				else if (char_check(ten)==0){
					clrscr();
					BaoLoi("Ten khong the chua ky tu so");
					cout<<"Nhap ma nhan vien: "<<ma<<endl;
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
			clrscr();
			BaoLoi("Phai khong hop le");
			cout<<"Nhap ma nhan vien: "<<ma<<endl;
			cout<<"Nhap ho nhan vien: "<<ho<<endl;
			cout<<"Nhap ten nhan vien: "<<ten<<endl;
			continue;
		}
	}
	
	while(true){
		fflush(stdin);
		cout<<"Nhap CMND: ";
		gets(cmnd);
		fflush(stdin);
		if (empty_check(cmnd)==1){
			clrscr();
			BaoLoi("CMND khong duoc bo trong");
			cout<<"Nhap ma nhan vien: "<<ma<<endl;
			cout<<"Nhap ho nhan vien: "<<ho<<endl;
			cout<<"Nhap ten nhan vien: "<<ten<<endl;
			cout<<"Nhap phai: "<<phai;
			continue;
		}
		else if (strlen(cmnd)<9 || strlen(cmnd)>12 || char_check(cmnd)==1){
			clrscr();
			BaoLoi("CMND khong hop le");
			cout<<"Nhap ma nhan vien: "<<ma<<endl;
			cout<<"Nhap ho nhan vien: "<<ho<<endl;
			cout<<"Nhap ten nhan vien: "<<ten<<endl;
			cout<<"Nhap phai: "<<phai<<endl;
			continue;
		}
		
		else {
//			if (Search_CMND(ds,cmnd)!=-1){
//				clrscr();
//				BaoLoi("CMND bi trung");
//				continue;
//			}
//			else break;
break;
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
		cout<<"Insert OK";
	}
}

void List_NhanVien(DS_NV ds){
	for (int i=0; i<ds.soluong;i++){
		cout<<ds.nodes[i]->MANV<<endl;
		cout<<ds.nodes[i]->HO<<endl;
		cout<<ds.nodes[i]->TEN<<endl;
		cout<<ds.nodes[i]->PHAI<<endl;
		cout<<ds.nodes[i]->CMND<<endl;
	}
}

void Delete_NhanVien(DS_NV &ds, int ma){
	int kq=Search_NV(ds,ma);
	if  (kq==-1) {
		BaoLoi("Nhan vien khong ton tai");
	}
//	else if (ds.nodes[kq]->PTR_HD.=NULL){
//		BaoLoi("Khong the xoa nhan vien");
//	}
	else{
		delete ds.nodes[kq];
		for (int i=kq;i<ds.soluong;i++){
			ds.nodes[i]=ds.nodes[i+1];
		}
		ds.soluong--;
	}
}

void Display_NV(DS_NV &ds, int ma){
	int kq=Search_NV(ds,ma);
	if (kq==-1) {} //BaoLoi("Nhan vien khong ton tai");
	else{
		cout<<"Ma nhan vien: "<<ds.nodes[kq]->MANV;
		cout<<"Ho nhan vien: "<<ds.nodes[kq]->HO;
		cout<<"Ten nhan vien: "<<ds.nodes[kq]->TEN;
		cout<<"Phai: "<<ds.nodes[kq]->PHAI;
		cout<<"CMND: "<<ds.nodes[kq]->CMND;
	}
}

void Edit_NV(DS_NV &ds, int ma){
	while(true){
		Display_NV(ds,ma);
		
		
	}
	
}

//void ThongKeDoanhThu(NODES_HOADON First_HD, DS_CTHD dscthd){
//	NODES_HOADON p;
//	int year; 
//	int month;
//	while (true){
//		cout<<"Nhap thang muon thong ke: ";
//		gets(month);
//		if (month==NULL){
//			//BaoLoi("Thang khong duoc bo trong");
//		}
//		else if(char_check(month)==1){
//			//BaoLoi("Thang phai la chu so tu 1-12");
//		}
//		else if(month<1|| month>12){
//			//BaoLoi("Thang phai tu 1-12");
//		}
//		else {
//			cout<<"Nhap nam muon thong ke: ";
//			gets(year);
//			if (empty_check_int(year)==1){
//			//BaoLoi("Nam khong duoc bo trong");
//			}
//			else if(char_check(year)==1){
//				//BaoLoi("Nam phai la chu so tu 1-12");
//			}
//			else if(year<1990 || year>2020){
//				//BaoLoi("Nam khong hop le");
//			}
//			else break;
//		}
//	}
//	
//	p=First_HD;
//	double doanhthu;
//	if (p==NULL){
//		//BaoLoi("Danh sach hoa don rong");
//	}
//	while (p!=NULL){
//		if ((p.info->date.month)==month){
//			if ((p.info->date.year)==year){
//				for (int i=0;i<dscthd.soluong;i++){
//					doanhthu=doanhthu + (dscthd[i].nodes->DonGia * dscthd[i].nodes->SL)
//							*(1+(dscthd[i].nodes->VAT)*0.1);
//				}
//			}
//		}
//	}
//	
//	cout<<"Doanh thu thang "<<month<<" nam "<<year<<": "<<doanhthu<<" VND";
//}

void ReadFile_VATTU(TREE_VATTU &vatTu, char *fileName){
	fstream f;
	f.open(fileName,ios::in);
	
	if (f.fail()){
		//BaoLoi("Khong the doc file vat tu");
		return;
	}	
	
	string line;
	VATTU VT;
	
	while(!f.eof()){
		getline(f,line);
		if (line==""){
			continue;
		}
		
		//ReadLine_VatTu(line,VT);
		//Insert_Vattu(line,vatTu);
	}
	
	f.close();
}

void ReadLine_VatTu(string line, VATTU &VT){
	int i=0;
	string line_temp="";
	
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
	cout<<"Read OK"<<endl;
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
		cout<<ds.soluong;
		Insert_Last(ds,NV);
	}
	BaoLoi("Doc file nhan vien thanh cong");
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
		f<<ds.nodes[i]->CMND;
//		f<<ds.nodes[i]->CMND<<"_";
		//Ghi hoa don
	}
	
	f.close();
}

int main(){
	resizeConsole(1920,1080);
//	giaoDienKhung();
//	giaoDienMenu();
	DS_NV ds_nv;
	NHANVIEN nv;
	
//	Insert_NV(ds_nv,nv);
//	Insert_Last(ds_nv,nv);
	ReadFile_NV(ds_nv,"NhanVien.txt");
	List_NhanVien(ds_nv);
//	SaveFile_NV(ds_nv,"NhanVien.txt");
}
