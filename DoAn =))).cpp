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
	char MAVT[11];
	char TENVT[50];
	char DVT[10];
	float SLT;
};
typedef struct Vattu VATTU;

struct Nodes_Vattu{
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

void xoaKhungDSNhanVien(){
	for (int i=14;i<=42;i++){
		gotoxy(2,i);
		SetBGColor(0);
		cout << "                                                                                                              ";
	}
}


void xoaKhung1() {
	for (int i =2 ; i<= 19 ;i++) {
		gotoxy(117,i);
		SetBGColor(0);
		cout << "                                               ";
	}
}

void xoaKhung2() {
	for (int i =22 ; i<= 39 ;i++) {
		
		gotoxy(117,i);
		SetBGColor(0);
		cout << "                                               ";		
	}
}

void xoaKhungThongBao() {
	for (int i=42;i<=44;i++) {
		gotoxy(117,i);
		SetBGColor(0);
		cout << "                                               ";
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

int checkDateTime(struct Date tg)
{
	
	if (tg.day > 31)
	{
		thongBaoLoi("mot thang chi co 31 ngay");
		return 1;
	}
	if(tg.month > 12) {
		thongBaoLoi("mot nam chi co 12 thang");
		return 1;
	}
	if(tg.year<2000) {
		thongBaoLoi("nhap nam sau 2000");
		return 1;
	}
	if (tg.day >= 31 && (tg.month == 4 || tg.month == 6 || tg.month == 9 || tg.month == 11))
	{
		char month[2];
		itoa(tg.month, month, 10);
		char thongbao[7] = "Thang ";
		strcat(month, " chi co 30 ngay!");
		strcat(thongbao, month);
		thongBaoLoi(thongbao);
		return 1;
	}
	if(tg.day > 29 && tg.month == 2)
	{
		char month[2];
		itoa(tg.month, month, 10);
		char thongbao[7] = "Thang ";
		strcat(month, " chi co 29 ngay!");
		strcat(thongbao, month);
		thongBaoLoi(thongbao);
		return 1;
	}
	if(!((tg.year % 4 == 0 && tg.year % 100 != 0) || tg.year % 400 == 0) && tg.day == 29 && tg.month == 2) // kiem tra nam nhuan
	{		
		char year[4];
		itoa(tg.year, year, 10);
		strcat(year, "la nam khong nhuan nen thang 2 chi co 28 ngay!");
		thongBaoLoi(year);			
		return 1;
	}
	
	return -1;
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

// vat tu

string FloatToString(float a) //Doi So Thuc Sang Chuoi
{
    if (a == 0) {
        return "0.00";
    }

    int temp_int = a * 100.0; //lay sau dau phay 2 so

    if (a < 0.1) { //vi du: 0.02 -> temp_int = 2
        return "0.0" + to_string(temp_int);

    }
    else if (a < 1) { //vi du 0.22 -> temp_int = 22
        return "0." + to_string(temp_int);
    }
    else {
        char soThapPhan1, soThapPhan2;
        string s = to_string(temp_int);
        soThapPhan1 = s[(s.length() - 1) - 1]; //so gan cuoi
        soThapPhan2 = s[(s.length() - 1)]; //so cuoi

        //xoa 2 so cuoi roi them dau cham, sau do them 2 so do vao lai
        s.erase(s.length() - 1, 1);
        s.erase(s.length() - 1, 1);

        s.insert(s.length(), 1, '.');
        s.insert(s.length(), 1, soThapPhan1);
        s.insert(s.length(), 1, soThapPhan2);
        return s;
    }
}

void Khoi_Tao_Cay(TREE_VATTU &tree){
	tree = NULL;
}

int Cay_Rong(TREE_VATTU tree){
	return (tree == NULL ? true : false);
}

void ThemCay(TREE_VATTU &tree, VATTU &vt, string maVT){
	if (tree==NULL){
		tree=new Nodes_Vattu;
		strcpy(tree->info.MAVT,maVT.c_str());
		strcpy(tree->info.TENVT,vt.TENVT);
		strcpy(tree->info.DVT,vt.DVT);
		tree->info.SLT=vt.SLT;
		
		tree->left=NULL;
		tree->right=NULL;
	}
	else if (stricmp(maVT.c_str(),tree->info.MAVT)<0){
		ThemCay(tree->left,vt,maVT);
	}
	else{
		ThemCay(tree->right,vt,maVT);
	}
}

void GiaiPhongVungNhoVT( TREE_VATTU &tree )
{
    if ( tree == NULL )
        return;
    GiaiPhongVungNhoVT( tree->left );
    GiaiPhongVungNhoVT( tree->right );
    GiaiPhongVungNhoVT( tree );
}

void GiaiPhongVungNhoNhanVien(DS_NV& ds){
    NODES_HOADON temp;
    for(int i = 0; i < ds.soluong; i++){

        while(ds.nodes[i]->PTR_HD.first != NULL){

            temp = ds.nodes[i]->PTR_HD.first;
            ds.nodes[i]->PTR_HD.first = ds.nodes[i]->PTR_HD.first->next;
            delete temp;
        }
        delete ds.nodes[i];
    }
}

char IsLeaf(TREE_VATTU &tree){
   return (tree->left == NULL) && (tree->right == NULL);
}

int DemNode(TREE_VATTU &tree) {
   	if(tree == NULL)
    	return 0;
   	else
    	if(IsLeaf(tree))
    		return 1;
    	else{
      		return 1+DemNode(tree->left) + DemNode(tree->right);
	  	}
        
}


TREE_VATTU TimKiemVatTu(TREE_VATTU tree, char MVT[])
{
	if (tree == NULL){
		return NULL; //dieu kien dung de quy->ko tim thay node can tim
	}
	
	if (stricmp(MVT, tree->info.MAVT) == 0) {
		return tree;
	}
	else if (stricmp(MVT, tree->info.MAVT) > 0) {
		return TimKiemVatTu(tree->right, MVT); //return ve ham chu ko don thuan la chi goi ham nhu cac thuat toan duyet, nhu vay se giu duoc ket qua cua vong de quy sau nhat da di toi
	}
	else {
		return TimKiemVatTu(tree->left, MVT);
	}
}

int KiemTraVatTuTrung(char MVT[], TREE_VATTU tree)
{
	if (TimKiemVatTu(tree, MVT) == NULL) {
		return 0;
	}
	return 1;
}

int KiemTraVatTuDeSua(char FixMVT[], TREE_VATTU NodeHienTai, TREE_VATTU tree)
{
	if (stricmp(FixMVT, NodeHienTai->info.MAVT) != 0) { //chi xet trung khi ma vat tu cua fixing bi thay doi
		if (TimKiemVatTu(tree, FixMVT) != NULL) { //trung ma vat tu
			return 1;
		}
	}
	return 0;
}

void GhiFileVT_NLR(TREE_VATTU tree, fstream& f)
{
	
	if (tree != NULL)
	{
		f << tree->info.MAVT;
		f << "+";
		f << tree->info.TENVT;
		f << "+";
		f << tree->info.DVT;
		f << "+";
		f << FloatToString(tree->info.SLT);
		f << "+" << endl;
		GhiFileVT_NLR(tree->left, f);
		GhiFileVT_NLR(tree->right, f);		
	}
}

void GhiFileVT(TREE_VATTU tree, string nameFile)
{
	fstream f;
	f.open(nameFile, ios::out|ios::ate);
	if (f.fail()) {
		cout << "GHI FILE THAT BAI!";
		return;
	}
	GhiFileVT_NLR(tree, f);
}

void LineToVatTu(string line, char MVT[], VATTU &vt)
{
	string temp = "";
	int i = 0;

	while (line[i] != '+')
	{
		temp += line[i];	
		i++;
	}
	strcpy(MVT ,temp.c_str()); 

	i++;
	temp = "";

	while (line[i] != '+')
	{
		temp += line[i];
		i++;
	}
	strcpy(vt.TENVT, temp.c_str());

	i++;
	temp = "";

	while (line[i] != '+')
	{
		temp += line[i];
		i++;
	}

	strcpy(vt.DVT, temp.c_str());

	i++;
	temp = "";

	while (line[i] != '+')
	{
		temp += line[i];
		i++;
	}
	vt.SLT = stof(temp);
}

void Sort(VATTU *a[500],int q, int r) {
	int i=q;
	int j=r;
	VATTU x;
	VATTU *temp = new VATTU;
	strcpy(x.MAVT,a[(int)(q+r)/2]->MAVT);
	do {
		while (stricmp(a[i]->MAVT,x.MAVT) > 0) i++;
		while (stricmp(a[j]->MAVT,x.MAVT) < 0) j--;
		if (i<=j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	} while (i<=j);
	if (q<j) {
		Sort(a,q,j);
	}
	if (i<r) {
		Sort(a,i,r);
	}
}


void showDSVatTu (TREE_VATTU ds,int k) {
	TREE_VATTU p = ds;
	VATTU *arrtemp[500];
	TREE_VATTU Stack[500];
	int sp = -1;
	int i = 0;
	while(p != NULL)
	{
		 
		strcpy(arrtemp[i]->MAVT,p->info.MAVT);
		strcpy(arrtemp[i]->TENVT,p->info.TENVT);
		strcpy(arrtemp[i]->DVT,p->info.DVT);
		arrtemp[i]->SLT = p->info.SLT;
		if(p->left != NULL)
		{
			Stack[++sp] = p->left;
		}
		if(p->right != NULL)
		{
			p = p->right;
		}
		else if(sp == -1)
				break;
		else p = Stack[sp--];
		i++;
	}
	Sort(arrtemp,0,i);
	int j=1;

	for (k;k<=i;k++) {	
		gotoxy(8,j+5);
		cout << k+1;
		gotoxy(12,j+5);
		cout << arrtemp[k]->MAVT;
		gotoxy(27,j+5);
		cout << arrtemp[k]->TENVT;
		gotoxy(79,j+5);;
		cout << arrtemp[k]->DVT;
		gotoxy(93,j+5);
		cout << arrtemp[k]->SLT;
		j++;
	}
}

void XuatMotPhanTu(TREE_VATTU tree){
	gotoxy(117,5);
	cout<<"Ma vat tu: "<<tree->info.MAVT;
	gotoxy(117,6);
	cout<<"Ten vat tu: "<<tree->info.TENVT;
	gotoxy(117,7);
	cout<<"DVT: "<<tree->info.DVT;
	gotoxy(117,8);
	cout<<"SLT: "<<tree->info.SLT;	
}

void DocFileVatTu(TREE_VATTU &tree, string fileName)
{
	fstream f;
	f.open(fileName, ios::in);

	if (f.fail()) {
		cout << "DOC FILE THAT BAI!";
		return;
	}

	string line;
	VATTU vt;
	char MVT[10];

	while (!f.eof()) {
		getline(f, line); //doc 1 dong va cho vao line

		if (line == "") { //neu rong thi ko xet 
			continue;
		}

		LineToVatTu(line, MVT, vt);
		ThemCay(tree, vt, MVT);
	}

	f.close();
}


VATTU NhapMotVatTu(TREE_VATTU &tree, VATTU vt){
	xoaKhung2();
	char MVT[21];
	char TenVT[51];
	char DonViTinh[11];
	char SoLuongTon[11];
	
	int a=0;
	do{
		gotoxy(125,25);
		cout<<"Nhap ma vat tu : ";
		InputString(MVT, 20);
		a=1;
		if(stricmp(MVT,"quit")==0){
			xoaKhung2();
			strcpy(vt.MAVT,"quit");
			return vt;	
		}
		if(Cay_Rong(tree)==false){
			if(KiemTraVatTuTrung(MVT,tree)!=0){
				thongBaoLoi("Ma vat tu da ton tai");
				getch();
				xoaKhungThongBao();
				a=0;
			}	
		}
	}while(a == 0);
		
		gotoxy(125,26);
		cout<<"Nhap ten vat tu: ";
		fflush(stdin);
		InputStringSpace(TenVT, 50);
		gotoxy(125,27);
		cout<<"Nhap don vi tinh: ";
		fflush(stdin);
		InputString(DonViTinh, 10);
		gotoxy(125,28);
		cout<<"Nhap so luong ton: ";
		fflush(stdin);
		InputNumber(SoLuongTon, 10);
		
		strcpy(vt.MAVT,MVT);
		strcpy(vt.TENVT,TenVT);
		strcpy(vt.DVT,DonViTinh);
		vt.SLT=atoi(SoLuongTon);
		
		return vt;
}


void XoaCayTHCo2NodeLa(TREE_VATTU& tree, TREE_VATTU& temp)
{
	if (tree->left != NULL) //de quy de tim ra phan tu trai tan cung 
		XoaCayTHCo2NodeLa(tree->left, temp);
	else //p luc nay la phan tu trai tan cung, temp van giu gia tri p dau tien
	{
		//copy infoVatTu tu p qua temp
		strcpy(temp->info.MAVT, tree->info.MAVT);
		temp->info = tree->info;
		temp = tree; //temp giu vi tri can xoa
		tree = tree->right; //noi lai cay con ben phai cua p vao lai cay //vi no la nut tan cung ben trai nen no chi co cay con ben phai hoac ko co nut la nao
	}
}

void XoaVT(TREE_VATTU& tree, char *deleteKey)
{
	if (stricmp(deleteKey, tree->info.MAVT) < 0) //khoa can them nho hon nut hien tai thi qua trai
		XoaVT(tree->left, deleteKey);
	else if (stricmp(deleteKey, tree->info.MAVT) > 0) //khoa can them lon hon nut hien tai thi qua phai
		XoaVT(tree->right, deleteKey);
	else //tim duoc phan tu de xoa, deleteKey = p->MVT
	{
		TREE_VATTU temp = tree; //tao temp va tro vao vi tri cua phan tu can xoa
		if (tree->left == NULL) //TH ko co cay con ben trai
			tree = tree->right; // vi la de quy nen dong nay co nghia la p->right = p->right->right(TH can xoa nut ben phai cua nut nao do) hoac la p->left = p->left->right(TH can xoa nut ben trai cua nut nao do), the nen no lien ket voi nhau duoc
		else if (tree->right == NULL)//TH ko co cay con ben phai
			tree = tree->left;
		else
			XoaCayTHCo2NodeLa(tree->right, temp); //TH nut can xoa co 2 nut con, tim nut tan cung ben trai cua cay con ben phai
		delete temp;	
	}
	thongBaoLoi("Xoa vat tu thanh cong");
}

int XoaCay(TREE_VATTU tree,DS_NV ds_nv, char *deleteKey){
	if (tree == NULL) {
		return 0;
	}
	bool vatTuDaSuDung = false;
	for (int i = 0; i < ds_nv.soluong; i++) { //ktra tung nhan vien

		for (NODES_HOADON run = ds_nv.nodes[i]->PTR_HD.first; run != NULL; run = run->next) { //kiem tra tung hoa don cua nhan vien do

			for (int j = 0; j < run->info.PTR_CTHD.soluong; j++) {//kiem tra tung cthd cua hoa don do

				if (strcmp(deleteKey, run->info.PTR_CTHD.nodes[j].MAVT) == 0) { 
					vatTuDaSuDung = true;
					break;
				}
			}

			if (vatTuDaSuDung == true) { //break for hoa don
				break;
			}
		}

		if (vatTuDaSuDung == true) { //break for nhan vien
			break;
		}
	}
	if (vatTuDaSuDung == false) { //chua dc su dung -> cho xoa vat tu
		gotoxy(121,43);
		cout<<("Ban co chac chan muon xoa?: ");
		char thoat[3];
		fflush(stdin);
		InputString(thoat,3);
		if (strcmp(thoat,"Y")==0 || strcmp(thoat,"y")==0 || 
			strcmp(thoat,"Yes")==0 || strcmp(thoat,"yes")==0){

			//cap nhat current lat nua in ds ra man hinh
			if (tree->right != NULL) { //neu co phan tu ben trai thi cap nhat thanh node trai
				tree = tree->right;
			}
			else if (tree->left != NULL) { //ko co trai thi se la phai
				tree = tree->left;
			}
			else {//neu khong co ca 2 thi day la ds co 1 phan tu, sau khi xoa se thanh ds rong
				tree = NULL;
			}
			XoaVT(tree, deleteKey); //xoa o tree
			return 1;
		}
	}		
	else { //da duoc su dung -> ko cho xoa
		return 0;
	}

}

void SuaVT(TREE_VATTU &tree){
	char TENVT[50];
	char DVT[10];
	
	while(true){
		gotoxy(125,25);
		cout <<"Moi ban nhap ten moi: ";
		InputStringSpace(TENVT,50);
		if(strcmp(TENVT,"quit")==0){
			xoaKhung1();
			xoaKhung2();
			return;
		}
		else break;
	}
	
	strcpy(tree->info.TENVT,TENVT);
	
	while(true){
		gotoxy(125,26);
		cout <<"Moi ban nhap don vi tinh moi: ";
		InputString(DVT,10);
		if(strcmp(DVT,"quit")==0){
			xoaKhung1();
			xoaKhung2();
			return;
		}
		else break;
	}
	strcpy(tree->info.DVT,DVT);
	
	thongBaoLoi("Sua vat tu thanh cong");
	int c=getch();
	xoaKhung1();
	xoaKhung2();
}

VATTU SuaCay(TREE_VATTU &tree,VATTU &vt,char *maVT){
	TREE_VATTU p;
	p=TimKiemVatTu(tree,maVT);
	XuatMotPhanTu(p);
	SuaVT(p);
	strcpy(vt.TENVT,p->info.TENVT);
	strcpy(vt.DVT,p->info.DVT);
}

void CapNhatSoLuongTon(HOADON addHoaDon, TREE_VATTU& tree)
{
    TREE_VATTU temp;

    for (int i = 0; i < addHoaDon.PTR_CTHD.soluong; i++) {
        temp = TimKiemVatTu(tree, addHoaDon.PTR_CTHD.nodes[i].MAVT); //con tro temp tro toi phan tu can xu ly

        if (strcmp(addHoaDon.LoaiHD,"X")==0) {
            temp->info.SLT -= addHoaDon.PTR_CTHD.nodes[i].SL; //cap nhat
        }
        else {
            temp->info.SLT += addHoaDon.PTR_CTHD.nodes[i].SL; //cap nhat
        }
    }
}

int Search_MSHD(DS_NV ds_nv, char* x)
{
	for(int i=0;i<ds_nv.soluong;i++){
		for (NODES_HOADON p = ds_nv.nodes[i]->PTR_HD.first;  p  != NULL ; p=p->next )
    		if ( strcmp(p->info.SOHD,x)==0  ) return 1;
    }
	return 0;
}

int Search_MaVT(DS_CTHD& hd, char* x){
	for (int i=0;i<hd.soluong;i++) {
		if (strcmp(hd.nodes[i].MAVT,x)==0) return 1;
	}
	return 0;	
}

CHITIET_HOADON nhapChiTietHoaDon(DS_CTHD& hd,TREE_VATTU& tree,HOADON hoadon){
	CHITIET_HOADON cthd;
	char mvt[12];
	char sl[5];
	char dg[10];
	char tt[3];
	char vat[4];

	xoaKhung2();
	do {
		gotoxy(125,25);
		cout << "                                    ";
		gotoxy(125,25);
		cout << "Nhap ma vat tu: ";
		InputString(mvt,10);
		if(strcmp(mvt,"quit")==0) {
			strcpy(cthd.MAVT,"quit");
			return cthd;
		}
		if(Search_MaVT(hd,mvt)==1) {
			thongBaoLoi("Ma vat tu da co");
			getch();
			xoaKhungThongBao();
			continue;
		}
		break;	
	}while(true);
	
	do {
		gotoxy(125,26);
		cout << "Nhap so luong: ";
		InputFloatNumber(sl,4);
		if(strcmp(sl,"quit")==0) {
			strcpy(cthd.MAVT,"quit");
			return cthd;
		}
		if(tree->info.SLT<atof(sl)) {
			thongBaoLoi("so luong trong kho khong du");
			getch();
			xoaKhungThongBao();
			gotoxy(139,26);
			cout<<"    ";
			continue;
		}
		break;
	}while(true);
	

	gotoxy(125,27);
	cout << "Nhap don gia: ";
	InputNumber(dg,9);
	if(strcmp(dg,"quit")==0) {
		strcpy(cthd.MAVT,"quit");
		return cthd;
	}

	while(true){
		gotoxy(125,28);
		cout << "Nhap trang thai: ";
		InputNumber(tt,1);
		if(strcmp(tt,"quit")==0) {
			strcpy(cthd.MAVT,"quit");
			return cthd;
		}
		if(atoi(tt)>1 || atoi(tt) <0){
			thongBaoLoi("Trang thai khong dung");
			getch();
			xoaKhungThongBao();
			gotoxy(142,28);
			cout<<"    ";
			continue;	
		}
		else break;
	}

	while(true){
		gotoxy(125,29);
		cout << "Nhap VAT: ";
		InputNumber(vat,3);
		if(strcmp(vat,"quit")==0) {
			strcpy(cthd.MAVT,"quit");
			return cthd;
		}
		if(atoi(vat)>99){
			thongBaoLoi("VAT khong duoc >100");
			getch();
			xoaKhungThongBao();
			gotoxy(136,28);
			cout<<"    ";
			continue;
		}
		else break;
	}
		
	CapNhatSoLuongTon(hoadon,tree);
	
	strcpy(cthd.MAVT,mvt);
	cthd.SL=atof(sl);
	cthd.DonGia=atoi(dg);
	cthd.TrangThai=atoi(tt);
	cthd.VAT=atoi(vat);
	gotoxy(135,42);
	return cthd;
}

HOADON nhapHoaDon(DS_NV ds_nv,TREE_VATTU& tree ) {
	HOADON hd;
	CHITIET_HOADON cthd;
	CreateList_CTHD(hd.PTR_CTHD);
	char day[2],month[2],year[4];
	
	do {
		xoaKhung2();
		gotoxy(125,25);
		cout << "Nhap so hoa don: ";
		InputNumber(hd.SOHD,20);
		if(Search_MSHD(ds_nv,hd.SOHD)==1) {
			thongBaoLoi("So hoa don da co");
			getch();
			xoaKhungThongBao();
			continue;
		}
		if(stricmp(hd.SOHD,"quit")==0) {
			strcpy(hd.SOHD,"quit");
			return hd;
		}
		break;
	}while(true);
	
	while(true) {
		gotoxy(135,26);cout<<"     ";
		gotoxy(135,27);cout<<"     ";
		gotoxy(135,28);cout<<"     ";
		gotoxy(125,26);
		cout << "Nhap ngay: ";
		InputNumber(day,2);
		if(stricmp(day,"quit")==0) {
			strcpy(hd.SOHD,"quit");
			return hd;
		}
	
		gotoxy(125,27);
		cout << "Nhap thang: ";
		InputNumber(month,2);
		if(stricmp(month,"quit")==0) {
			strcpy(hd.SOHD,"quit");
			return hd;
		}
	
		gotoxy(125,28);
		cout << "Nhap nam: ";
		InputNumber(year,4);
		if(stricmp(year,"quit")==0) {
			strcpy(hd.SOHD,"quit");
			return hd;
		}
	
		hd.date.day = atoi(day);
		hd.date.month = atoi(month);
		hd.date.year = atoi(year);
		if(checkDateTime(hd.date)==1) {
			
			getch();
			xoaKhungThongBao();
			continue;
		}
		break;
	}
	
	gotoxy(125,29);
	cout << "Nhap loai: ";
	InputLoai(hd.LoaiHD,1);
	if(stricmp(hd.LoaiHD,"quit")==0) {
		strcpy(hd.SOHD,"quit");
		return hd;
	}
	int i=0;
	while (i<20) {
		cthd=nhapChiTietHoaDon(hd.PTR_CTHD,tree,hd);
		
		if(stricmp(cthd.MAVT,"quit")!=0) {
			InsertLast_CTHD(hd.PTR_CTHD,cthd);
			i++;
			
		}
		else break;
	}
	return hd;
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

int Search_NV(DS_NV &ds, int ma){
	for (int i=0;i<ds.soluong;i++){
		if (ds.nodes[i]->MANV==ma) return i;
	}
	return -1;
}

int Search_CMND(DS_NV &ds, char *cmnd){
	for (int i=0;i<ds.soluong;i++){
		if(strcmp(ds.nodes[i]->CMND,cmnd)==0) return i;
	}	
	return -1;
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

NHANVIEN Insert_NV(DS_NV &ds, NHANVIEN &nv){
	xoaKhung2();
	char ma[3];
	char ho[10];
	char ten[20];
	char phai[5];
	char cmnd[12];

	while(true){
		xoaKhung2();
		gotoxy(125,25);
		cout<<"Nhap ma nhan vien: ";
		InputNumber(ma,3);
		if (strcmp(ma,"quit")==0){
			xoaKhung2();
			nv.MANV=-1;
			return nv;
		}
		if (Search_NV(ds,atoi(ma))!=-1){
			thongBaoLoi("Ma nhan vien bi trung");
			getch();
			xoaKhungThongBao();
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
			gotoxy(136,29);
			cout<<"            ";
			xoaKhungThongBao();
			continue;
		}
		if (Search_CMND(ds,cmnd)!=-1){
			thongBaoLoi("CMND nhan vien bi trung");
			getch();
			gotoxy(136,29);
			cout<<"            ";
			xoaKhungThongBao();
			continue;
		}
		break;
	}
		
	nv.MANV=atoi(ma);	    strcpy(nv.HO,ho);	  strcpy(nv.TEN,ten);
	strcpy(nv.PHAI,phai);	
	strcpy(nv.CMND,cmnd);
	nv.PTR_HD.first=NULL;
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
		strcpy(tree->info.MAVT,maVT.c_str());
		strcpy(tree->info.TENVT,vt.TENVT);
		strcpy(tree->info.DVT,vt.DVT);
		tree->info.SLT=vt.SLT;
		
		tree->left=NULL;
		tree->right=NULL;
	}
	else if (strcmp(maVT.c_str(),tree->info.MAVT)<0){
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

void Delete_NhanVien(DS_NV &ds, int viTri){
	if (EmptyHDCheck(ds,viTri)==0){
		thongBaoLoi("Khong the xoa nhan vien");
	}
	else{
		xoaKhungThongBao();
		thongBaoLoi("Ban co chac chan muon xoa?: ");
		char thoat[3];
		gets(thoat);
		if (strcmp(thoat,"Y")==0 || strcmp(thoat,"y")==0 || 
			strcmp(thoat,"Yes")==0 || strcmp(thoat,"yes")==0){
				delete ds.nodes[viTri];
				for (int i=viTri;i<ds.soluong;i++){
					ds.nodes[i]=ds.nodes[i+1];
				}
				ds.soluong--;	
				Sort_NhanVien(ds);
				thongBaoLoi("Xoa nhan vien thanh cong");	
		}
		else{
			xoaKhungThongBao();
		}
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
		Sort_NhanVien(ds);
		xoaKhung1();
		xoaKhung2();
		thongBaoLoi("Sua thong tin nhan vien thanh cong");
	}
	else{
		xoaKhung1();
		xoaKhung2();
	}
}

void KhungHienHoaDonNhanVienTheoNgayThang(struct Date tuNgay,struct Date denNgay,NHANVIEN nv) {
	VeKhung(6,3,109,40);
	// line ngang 1
	for (int i=7;i<=115;i++) {  
		gotoxy(i,7);
		cout << char(196);
	}
		gotoxy(6,7);
		cout << char(195);
		gotoxy(115,7);
		cout << char(180);
	// line ngang 2
	for (int i=7;i<=115;i++) {  
		gotoxy(i,9);
		cout << char(196);
	}
		gotoxy(6,9);
		cout << char(195);
		gotoxy(115,9);
		cout << char(180);
	// line doc 1
	for (int i=7;i<=42;i++) { 
		gotoxy(18,i);
		cout << char(179);
	}
		gotoxy(18,7);
		cout << char(194);
		gotoxy(18,9);
		cout << char(197);
		gotoxy(18,43);
		cout << char(193);
	// line doc 2
	for (int i=7;i<=42;i++) { 
		gotoxy(29,i);
		cout << char(179);
	}
		gotoxy(29,7);
		cout << char(194);
		gotoxy(29,9);
		cout << char(197);
		gotoxy(29,43);
		cout << char(193);
	// line doc 3
	for (int i=7;i<=42;i++) { 
		gotoxy(35,i);
		cout << char(179);
	}
		gotoxy(35,7);
		cout << char(194);
		gotoxy(35,9);
		cout << char(197);
		gotoxy(35,43);
		cout << char(193);
	// line doc 4
	for (int i=7;i<=42;i++) { 
		gotoxy(45,i);
		cout << char(179);
	}
		gotoxy(45,7);
		cout << char(194);
		gotoxy(45,9);
		cout << char(197);
		gotoxy(45,43);
		cout << char(193);
	// line doc 5
	for (int i=7;i<=42;i++) { 
		gotoxy(79,i);
		cout << char(179);
	}
		gotoxy(79,7);
		cout << char(194);
		gotoxy(79,9);
		cout << char(197);
		gotoxy(79,43);
		cout << char(193);
	// line doc 6
	for (int i=7;i<=42;i++) { 
		gotoxy(84,i);
		cout << char(179);
	}
		gotoxy(84,7);
		cout << char(194);
		gotoxy(84,9);
		cout << char(197);
		gotoxy(84,43);
		cout << char(193);
	// line doc 7
	for (int i=7;i<=42;i++) { 
		gotoxy(94,i);
		cout << char(179);
	}
		gotoxy(94,7);
		cout << char(194);
		gotoxy(94,9);
		cout << char(197);
		gotoxy(94,43);
		cout << char(193);
	// line doc 8
	for (int i=7;i<=42;i++) { 
		gotoxy(100,i);
		cout << char(179);
	}
		gotoxy(100,7);
		cout << char(194);
		gotoxy(100,9);
		cout << char(197);
		gotoxy(100,43);
		cout << char(193);
			
	SetColor(LUC);	
	gotoxy(34,4);
	cout << "BANG LIET KE CAC HOA DON TRONG KHOANG THOI GIAN";
	gotoxy(37,5);
	cout << "Tu ngay: "<<tuNgay.day<<"/"<<tuNgay.month<<"/"<<tuNgay.year;
	gotoxy(59,5);
	cout << "Den ngay: "<<denNgay.day<<"/"<<denNgay.month<<"/"<<denNgay.year;
	gotoxy(37,6);
	cout << "Nhan vien: "<<nv.HO<<" "<<nv.TEN;
	gotoxy(10,8);
	cout << "So HD";	
	gotoxy(20,8);
	cout << "NGAY LAP";
	gotoxy(30,8);
	cout << "LOAI";
	gotoxy(38,8);
	cout << "MA VT";
	gotoxy(59,8);
	cout << "TEN VT";
	gotoxy(81,8);
	cout << "SL";
	gotoxy(86,8);
	cout << "DON GIA";
	gotoxy(96,8);
	cout << "VAT";
	gotoxy(104,8);
	cout << "TRI GIA";
}

int CheckNgayThangLietKeHoaDon(Date dateInput, Date dateStart, Date dateEnd){
	if (dateInput.year<dateStart.year){
		return 0;
	}
	if (dateInput.year==dateStart.year && dateInput.year<dateEnd.year){
		if(dateInput.month<dateStart.month)	return 0;
		else if(dateInput.month==dateStart.month){
			if (dateInput.day<dateStart.day) return 0;
			else return 1;
		}
		else return 1;
	}
	if (dateInput.year==dateStart.year && dateInput.year==dateEnd.year){
		if (dateInput.month<dateStart.month) return 0;
		else if(dateInput.month==dateStart.month && dateInput.month<dateEnd.month){
			if (dateInput.day<dateStart.day) return 0;
			else return 1;
		}
		else if(dateInput.month>dateStart.month && dateInput.month<dateEnd.month){
			if (dateInput.month<dateEnd.month){
				return 1;
			}
			else if(dateInput.month==dateEnd.month){
				if(dateInput.day>dateEnd.day) return 0;
				else return 1;
			}
		}
		else if(dateInput.month==dateStart.month && dateInput.month==dateEnd.month){
			if (dateInput.day<dateStart.day) return 0;
			else if(dateInput.day==dateStart.day) return 1;
			else if(dateInput.day>dateStart.day && dateInput.day<=dateEnd.day) return 1;
		}
		else if(dateInput.month>dateStart.month && dateInput.month==dateEnd.month){
			if (dateInput.day>dateEnd.day) return 0;
			else return 1;
		}
		else if(dateInput.month>dateEnd.month) return 0;
	}
	if (dateInput.year>dateStart.year && dateInput.year==dateEnd.year){
		if (dateInput.month>dateEnd.month) return 0;
		else if(dateInput.month<dateEnd.month) return 1;
		else if(dateInput.month==dateEnd.month){
			if (dateInput.day<=dateEnd.day) return 1;
			else return 0;
		}
	}
	if (dateInput.year>dateEnd.year) return 0;
}

char* NameOfVatTu(TREE_VATTU ds_vt, char* maVT){
	TREE_VATTU p;
	p=TimKiemVatTu(ds_vt,maVT);
	return p->info.TENVT;
}

void GiaoDienHienHoaDonNhanVien(DS_NV ds, TREE_VATTU ds_vt, int viTri){
	while(true){
		clrscr();
		giaoDienKhung();
		gotoxy(5,44);
		cout<<"Esc: Quay lai";
		
		char day1[2],day2[2],month1[2],month2[2],year1[4],year2[4];
		Date date1, date2;
		
		while(true){
			gotoxy(125,25);
			cout << "Nhap ngay bat dau: ";
			InputNumber(day1,2);
			if(strcmp(day1,"quit")==0){
				break;
			}
			if(atoi(day1)<1 || atoi(day1)>31){
				thongBaoLoi("Ngay khong hop le");
				getch();
				gotoxy(144,25);
				cout<<"      ";
				xoaKhungThongBao();
				continue;
			}
			else break;
		}
		if(strcmp(day1,"quit")==0){
			return;
		}
		
		while(true){
			gotoxy(125,26);
			cout << "Nhap thang bat dau: ";
			InputNumber(month1,2);
			if(strcmp(month1,"quit")==0){
				break;
			}
			if(atoi(month1)<1 || atoi(month1)>13){
				thongBaoLoi("Thang khong hop le");
				getch();
				gotoxy(145,26);
				cout<<"       ";
				xoaKhungThongBao();
				continue;
			}
			if (atoi(day1)==31 && (atoi(month1)==4 || atoi(month1)==6 ||
								   atoi(month1)==9 || atoi(month1)==11)){
				thongBaoLoi("Thang khong hop le");
				getch();
				gotoxy(145,26);
				cout<<"      ";
				xoaKhungThongBao();
				continue;					   	
			}
			if (atoi(day1)==30 && (atoi(month1)==1 || atoi(month1)==3 || atoi(month1)==5 ||
								   atoi(month1)==7 || atoi(month1)==8 || atoi(month1)==10 || 
								   atoi(month1)==12)){
				thongBaoLoi("Thang khong hop le");
				getch();
				gotoxy(145,26);
				cout<<"      ";
				xoaKhungThongBao();
				continue;					   	
			}
			if (atoi(month1)==2 && atoi(day1)>29){
				thongBaoLoi("Thang khong hop le");
				getch();
				gotoxy(145,26);
				cout<<"      ";
				xoaKhungThongBao();
				continue;
			}
			else break;
		}
		if(strcmp(month1,"quit")==0){
			return;
		}
		
		while(true){
			gotoxy(125,27);
			cout << "Nhap nam bat dau: ";
			InputNumber(year1,4);
			if(strcmp(year1,"quit")==0){
				break;
			}
			if(atoi(year1)<1990 || atoi(year1)>2020){
				thongBaoLoi("Nam khong hop le");
				getch();
				gotoxy(143,27);
				cout<<"        ";
				xoaKhungThongBao();
				continue;
			}
			else break;
		}
		if(strcmp(year1,"quit")==0){
			return;
		}
		
		date1.day=atoi(day1);
		date1.month=atoi(month1);
		date1.year=atoi(year1);
		
		while(true){
			gotoxy(125,28);
			cout << "Nhap ngay ket thuc: ";
			InputNumber(day2,2);
			if(strcmp(day2,"quit")==0){
				break;
			}
			if(atoi(day2)<1 || atoi(day2)>31){
				thongBaoLoi("Ngay khong hop le");
				getch();
				gotoxy(144,28);
				cout<<"      ";
				xoaKhungThongBao();
				continue;
			}
			else break;
		}
		if(strcmp(day2,"quit")==0){
			return;
		}
		
		while(true){
			gotoxy(125,29);
			cout << "Nhap thang ket thuc: ";
			InputNumber(month2,2);
			if(strcmp(month2,"quit")==0){
				break;
			}
			if(atoi(month2)<1 || atoi(month2)>13){
				thongBaoLoi("Thang khong hop le");
				getch();
				gotoxy(145,29);
				cout<<"       ";
				xoaKhungThongBao();
				continue;
			}
			if (atoi(day2)==31 && (atoi(month2)==4 || atoi(month2)==6 ||
								   atoi(month2)==9 || atoi(month2) ==11)){
				thongBaoLoi("Thang khong hop le");
				getch();
				gotoxy(145,29);
				cout<<"      ";
				xoaKhungThongBao();
				continue;					   	
			}
			if (atoi(day2)==30 && (atoi(month2)==1 || atoi(month2)==3 || atoi(month2)==5 ||
								   atoi(month2)==7 || atoi(month2)==8 || atoi(month2)==10 || 
								   atoi(month2)==12)){
				thongBaoLoi("Thang khong hop le");
				getch();
				gotoxy(145,29);
				cout<<"      ";
				xoaKhungThongBao();
				continue;					   	
			}
			if (atoi(month2)==2 && atoi(day2)>29){
				thongBaoLoi("Thang khong hop le");
				getch();
				gotoxy(145,29);
				cout<<"      ";
				xoaKhungThongBao();
				continue;
			}
			else break;
		}
		if(strcmp(month2,"quit")==0){
			return;
		}
		
		while(true){
			gotoxy(125,30);
			cout << "Nhap nam ket thuc: ";
			InputNumber(year2,4);
			if(strcmp(year2,"quit")==0){
				break;
			}
			if(atoi(year2)<1990 || atoi(year2)>2020){
				thongBaoLoi("Nam khong hop le");
				getch();
				gotoxy(143,30);
				cout<<"        ";
				xoaKhungThongBao();
				continue;
			}
			if (atoi(year2)<date1.year){
				thongBaoLoi("Nam khong hop le");
				getch();
				gotoxy(143,30);
				cout<<"        ";
				xoaKhungThongBao();
				continue;
			}
			if (atoi(year1)==atoi(year2)){
				if (atoi(month1)>atoi(month2)){
					thongBaoLoi("Nam khong hop le");
					getch();
					gotoxy(143,30);
					cout<<"        ";
					xoaKhungThongBao();
					continue;
				}
				else if(atoi(month1)==atoi(month2)){
					if(day1>day2){
						thongBaoLoi("Nam khong hop le");
						getch();
						gotoxy(143,30);
						cout<<"    ";
						xoaKhungThongBao();
						continue;
					}
				}
			}
			else break;
		}
		if(strcmp(year2,"quit")==0){
			return;
		}
		
		date2.day=atoi(day2);
		date2.month=atoi(month2);
		date2.year=atoi(year2);
		
		int y=10;
		int soluong=0;
		int check=0;
		
		KhungHienHoaDonNhanVienTheoNgayThang(date1,date2,*ds.nodes[viTri]);
		if (EmptyHDCheck(ds,viTri)==0){
			for(NODES_HOADON i=ds.nodes[viTri]->PTR_HD.first;i!=NULL;i=i->next){
				check=CheckNgayThangLietKeHoaDon(i->info.date,date1,date2);
				if(check==1){
					gotoxy(11,y);
					cout<<i->info.SOHD;
					gotoxy(19,y);
					cout<<i->info.date.day<<"/"<<i->info.date.month<<"/"<<i->info.date.year;
					gotoxy(32,y);
					cout<<i->info.LoaiHD;
					for (int j=0;j<i->info.PTR_CTHD.soluong;j++){
						gotoxy(39,y);
						cout<<i->info.PTR_CTHD.nodes[j].MAVT;
						gotoxy(58,y);
						cout<<NameOfVatTu(ds_vt,i->info.PTR_CTHD.nodes[j].MAVT);
						gotoxy(81,y);
						cout<<i->info.PTR_CTHD.nodes[j].SL;
						gotoxy(87,y);
						cout<<i->info.PTR_CTHD.nodes[j].DonGia;
						gotoxy(96,y);
						cout<<i->info.PTR_CTHD.nodes[j].VAT;
						gotoxy(104,y);
						cout<<i->info.PTR_CTHD.nodes[j].DonGia * i->info.PTR_CTHD.nodes[j].SL 
													* (1 + (i->info.PTR_CTHD.nodes[j].VAT/100.0));
						y++;
					}
				}
			}
		}
		int c=getch();
		if (c==27){
			break;
		}
	}
}

int ThongKeDoanhThu(DS_NV ds,TREE_VATTU ds_vt){
	clrscr();
	giaoDienKhung();
	DS_CTHD dscthd;
	char year_insert[3];
	gotoxy(5,44);
	cout<<"Esc: Quay lai";	
	gotoxy(30,44);
	cout<<"Nhap quit huy viec nhap lieu";
	int y=17;
	
	while(true){
		gotoxy(125,25);
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
			thongBaoLoi("Nam khong hop le");
			continue;
		}
		else break;
	}
	if(strcmp(year_insert,"quit")==0){
		return -1;
	}
	
	Date date2;
	date2.year=atoi(year_insert);
	gotoxy(30,15);
	cout<<"BANG THONG KE DOANH THU NAM "<<date2.year;
	gotoxy(34,16);
	cout<<"THANG";
	gotoxy(50,16);
	cout<<"DOANH THU";
	
	double month[12];
	for(int i=0;i<12;i++){
		month[i]=0;
	}
	
	for (int i=0;i<ds.soluong;i++){
		if (EmptyHDCheck(ds,i)==0){
			for (NODES_HOADON j=ds.nodes[i]->PTR_HD.first; j!=NULL; j=j->next){
				if (j->info.date.year==date2.year){
					for (int k=0;k<j->info.PTR_CTHD.soluong;k++){
						month[j->info.date.month-1]= month[j->info.date.month-1] 
												+ (j->info.PTR_CTHD.nodes[k].DonGia * j->info.PTR_CTHD.nodes[k].SL 
												* (1 + (j->info.PTR_CTHD.nodes[k].VAT/100.0)));
					}	
				}
			}
		}
	}

	for(int i=0;i<12;i++){
		gotoxy(36,y);
		cout<<i+1;
		if(month[i]==0){
			gotoxy(55,y);
			cout<<month[i];
		}
		else{
			gotoxy(52,y);
			cout<<month[i];
		}

		y++;
	}
	
	thongBaoLoi("");
	int c=getch();
	if(c==27){
		return -1;
	}
	return month[1];
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
		dshd.last=nodes_hd;
	}
	else{
		dshd.last->next=nodes_hd;
		dshd.last=dshd.last->next;
	}
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

	while(line[i]!='$'){
		HOADON hd;
		CreateList_CTHD(hd.PTR_CTHD);
		
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
		hd.date.day=atoi(line_temp.c_str());
		line_temp="";
		i++;
		
		while(line[i]!='|'){
			line_temp=line_temp+line[i];
			i++;
		}
		hd.date.month=atoi(line_temp.c_str());
		line_temp="";
		i++;
		
		while(line[i]!='|'){
			line_temp=line_temp+line[i];
			i++;
		}
		hd.date.year=atoi(line_temp.c_str());
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
			CHITIET_HOADON cthd;
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
			cthd.SL=atof(line_temp.c_str());
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
				
				for (int j=0;j<a->info.PTR_CTHD.soluong;j++){
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
	}
	
	f.close();
}

void List_VatTu_All(VATTU *arr[500],int max){
	int y=14;
	while(y<43){
		for (int i=0; i<max;i++){
			gotoxy(5,y);
			cout<<arr[i]->MAVT<<endl;
			gotoxy(20,y);
			cout<<arr[i]->TENVT<<endl;
			gotoxy(35,y);
			cout<<arr[i]->DVT<<endl;
			gotoxy(50,y);
			cout<<arr[i]->SLT<<endl;
			y++;
		}
		break;
	}
}

void List_VatTu_TT(VATTU *arr[500], int begin, int end){
	int y=14;
	while(y<43){
		for (int i=begin; i<end;i++){
			gotoxy(5,y);
			cout<<arr[i]->MAVT<<endl;
			gotoxy(20,y);
			cout<<arr[i]->TENVT<<endl;
			gotoxy(35,y);
			cout<<arr[i]->DVT<<endl;
			gotoxy(50,y);
			cout<<arr[i]->SLT<<endl;
			y++;
		}
		break;
	}
}

void GiaoDienMenuQuanLyVatTu(){
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
	cout<<"Esc: Quay lai";
	gotoxy(5,44);
	cout<<"F1: Chinh sua vat tu";
	gotoxy(30,44);
	cout<<"F2: Xoa vat tu";
	gotoxy(55,43);
	cout<<"Nhap quit huy viec nhap lieu";
}

void GiaoDienDSVatTu(TREE_VATTU &ds_vt,DS_NV ds){
	GiaoDienMenuQuanLyVatTu();
	
	TREE_VATTU p = ds_vt;
	VATTU *arrtemp[500];
	TREE_VATTU Stack[500];
	int sp = -1;
	int i = 0;
	while(p != NULL)
	{
		arrtemp[i] = new VATTU;
		strcpy(arrtemp[i]->MAVT,p->info.MAVT);
		strcpy(arrtemp[i]->TENVT,p->info.TENVT);
		strcpy(arrtemp[i]->DVT,p->info.DVT);
		arrtemp[i]->SLT = p->info.SLT;
		if(p->left != NULL)
		{
			Stack[++sp] = p->left;
		}
		if(p->right != NULL)
		{
			p = p->right;
		}
		else if(sp == -1)
				break;
		else p = Stack[sp--];
		i++;
	}
	Sort(arrtemp,0,i);
	

	if (i>28){
		List_VatTu_TT(arrtemp,0,28);	
	}
	else{
		List_VatTu_All(arrtemp,i);
	}
	
	gotoxy(5,14);
	Highlight();
	
	int x=5,y=14;
	int dem=0;
	int check;
	while (true){
		int c=getch();
		if(i>28){
			if (y==14 && dem==0){
				if (c==72){	//Up
					xoaKhungDSNhanVien();
					GiaoDienMenuQuanLyVatTu();
					List_VatTu_TT(arrtemp,i-28,i);
					y=41;
					gotoxy(x,y);
					dem=i-1;
				}
				if (c==80){	//Down
					y++;
					gotoxy(x,y);
					Highlight();
					dem++;
				}
				if (c==27){ //Esc
					return;
				}
				if (c==82){	//Insert
					VATTU vt;
					vt=NhapMotVatTu(ds_vt,vt);
					if(strcmp(vt.MAVT,"quit")==0){
						gotoxy(x,y);
						break;
					}
					else{
						ThemCay(ds_vt,vt,vt.MAVT);	
						xoaKhungDSNhanVien();
						xoaKhung2();
						i++;
						arrtemp[i]=new VATTU;
						strcpy(arrtemp[i]->MAVT,vt.MAVT);
						strcpy(arrtemp[i]->TENVT,vt.TENVT);
						strcpy(arrtemp[i]->DVT,vt.DVT);
						arrtemp[i]->SLT = vt.SLT;
						Sort(arrtemp,0,i);
						List_VatTu_TT(arrtemp,0,28);	
						thongBaoLoi("Them vat tu thanh cong");
					}
				}
				if (c==59){	//F1
					VATTU vt;
					vt=SuaCay(ds_vt,vt,arrtemp[dem]->MAVT);
					if(vt.TENVT!="NULL"){
						strcpy(arrtemp[dem]->TENVT,vt.TENVT);
						strcpy(arrtemp[dem]->DVT,vt.DVT);
						xoaKhungDSNhanVien();
						Sort(arrtemp,0,i);
						List_VatTu_TT(arrtemp,0,28);
						gotoxy(x,y);
					}
					else{
						xoaKhungDSNhanVien();
						xoaKhung2;
						xoaKhungThongBao();
						gotoxy(x,y);
					}
				}
				if (c==60){	//F2
					check=XoaCay(ds_vt,ds,arrtemp[dem]->MAVT);
					xoaKhungDSNhanVien();
					if(check==1){	//Co xoa
						for(int j=dem;j<=i;j++){
							arrtemp[j]=arrtemp[j+1];
						}
						i--;
						Sort(arrtemp,0,i);
						List_VatTu_TT(arrtemp,0,28);
						gotoxy(x,y);
					}
					else{
						xoaKhungThongBao();
						thongBaoLoi("Vat tu dang su dung");
						List_VatTu_TT(arrtemp,0,28);
						gotoxy(x,y);
					}
				}
			}
			else if(y>14 && y<41 && dem>0 && dem<i-1){
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
					return;
				}
				if (c==82){	//Insert
					VATTU vt;
					vt=NhapMotVatTu(ds_vt,vt);
					if(strcmp(vt.MAVT,"quit")==0){
						gotoxy(x,y);
						break;
					}
					else{
						ThemCay(ds_vt,vt,vt.MAVT);	
						xoaKhungDSNhanVien();
						xoaKhung2();
						i++;
						arrtemp[i]=new VATTU;
						strcpy(arrtemp[i]->MAVT,vt.MAVT);
						strcpy(arrtemp[i]->TENVT,vt.TENVT);
						strcpy(arrtemp[i]->DVT,vt.DVT);
						arrtemp[i]->SLT = vt.SLT;
						//
						Sort(arrtemp,0,i);
						List_VatTu_TT(arrtemp,0,28);	
						thongBaoLoi("Them vat tu thanh cong");
					}
				}
				if (c==59){	//F1
					VATTU vt;
					vt=SuaCay(ds_vt,vt,arrtemp[dem]->MAVT);
					if(vt.TENVT!="NULL"){
						strcpy(arrtemp[dem]->TENVT,vt.TENVT);
						strcpy(arrtemp[dem]->DVT,vt.DVT);
						xoaKhungDSNhanVien();
						Sort(arrtemp,0,i);
						List_VatTu_TT(arrtemp,0,28);
						gotoxy(x,y);
					}
					else{
						xoaKhungDSNhanVien();
						xoaKhung2;
						xoaKhungThongBao();
						gotoxy(x,y);
					}
				}		
				if (c==60){	//F2
					check=XoaCay(ds_vt,ds,arrtemp[dem]->MAVT);
					xoaKhungDSNhanVien();
					if(check==1){	//Co xoa
						for(int j=dem;j<=i;j++){
							arrtemp[j]=arrtemp[j+1];
						}
						i--;
						Sort(arrtemp,0,i);
						xoaKhungThongBao();
						List_VatTu_TT(arrtemp,0,28);
						gotoxy(x,y);
					}
					else{
						xoaKhungThongBao();
						thongBaoLoi("Vat tu dang su dung");
						List_VatTu_TT(arrtemp,0,28);
						gotoxy(x,y);
					}
				}
			}
			else if (y==41 && dem==i-1){
				if (c==72){	//Up
					y--;
					dem--;
					gotoxy(x,y);
					Highlight();
				}
				if (c==80){	//Down
					xoaKhungDSNhanVien();
					GiaoDienMenuQuanLyVatTu();
					List_VatTu_TT(arrtemp,0,28);
					y=14;
					dem=1;
					gotoxy(x,y);
					Highlight();
				}
				if (c==27){ //Esc
					return;
				}
				if (c==82){	//Insert
					VATTU vt;
					vt=NhapMotVatTu(ds_vt,vt);
					if(strcmp(vt.MAVT,"quit")==0){
						gotoxy(x,y);
						break;
					}
					else{
						ThemCay(ds_vt,vt,vt.MAVT);	
						xoaKhungDSNhanVien();
						xoaKhung2();
						i++;
						arrtemp[i]=new VATTU;
						strcpy(arrtemp[i]->MAVT,vt.MAVT);
						strcpy(arrtemp[i]->TENVT,vt.TENVT);
						strcpy(arrtemp[i]->DVT,vt.DVT);
						arrtemp[i]->SLT = vt.SLT;
						//
						Sort(arrtemp,0,i);
						List_VatTu_TT(arrtemp,0,28);	
						thongBaoLoi("Them vat tu thanh cong");
					}
				}
				if (c==59){	//F1
					VATTU vt;
					vt=SuaCay(ds_vt,vt,arrtemp[dem]->MAVT);
					if(vt.TENVT!="NULL"){
						strcpy(arrtemp[dem]->TENVT,vt.TENVT);
						strcpy(arrtemp[dem]->DVT,vt.DVT);
						xoaKhungDSNhanVien();
						Sort(arrtemp,0,i);
						List_VatTu_TT(arrtemp,0,28);
						gotoxy(x,y);
					}
					else{
						xoaKhungDSNhanVien();
						xoaKhung2;
						xoaKhungThongBao();
						gotoxy(x,y);
					}
				}
				if (c==60){	//F2
					check=XoaCay(ds_vt,ds,arrtemp[dem]->MAVT);
					xoaKhungDSNhanVien();
					if(check==1){	//Co xoa
						for(int j=dem;j<=i;j++){
							arrtemp[j]=arrtemp[j+1];
						}
						i--;
						Sort(arrtemp,0,i);
						xoaKhungThongBao();
						List_VatTu_TT(arrtemp,0,28);
						gotoxy(x,y);
					}
					else{
						xoaKhungThongBao();
						thongBaoLoi("Vat tu dang su dung");
						List_VatTu_TT(arrtemp,0,28);
						gotoxy(x,y);
					}
				}
			}
			else if(y==14 && dem>0){
				if (c==72){	//Up
					dem--;
					xoaKhungDSNhanVien();
					GiaoDienMenuQuanLyVatTu();
					List_VatTu_TT(arrtemp,dem,dem+28);
					gotoxy(x,y);
				}
				if (c==80){	//Down
					dem++;
					y++;
					gotoxy(x,y);
					Highlight();
				}
				if (c==27){ //Esc
					return;
				}
				if (c==82){	//Insert
					VATTU vt;
					vt=NhapMotVatTu(ds_vt,vt);
					if(strcmp(vt.MAVT,"quit")==0){
						gotoxy(x,y);
						break;
					}
					else{
						ThemCay(ds_vt,vt,vt.MAVT);
						xoaKhungDSNhanVien();
						xoaKhung2();
						i++;
						arrtemp[i]=new VATTU;
						strcpy(arrtemp[i]->MAVT,vt.MAVT);
						strcpy(arrtemp[i]->TENVT,vt.TENVT);
						strcpy(arrtemp[i]->DVT,vt.DVT);
						arrtemp[i]->SLT = vt.SLT;

						Sort(arrtemp,0,i);
						List_VatTu_TT(arrtemp,0,28);	
						thongBaoLoi("Them vat tu thanh cong");
					}
				}
				if (c==59){	//F1
					VATTU vt;
					vt=SuaCay(ds_vt,vt,arrtemp[dem]->MAVT);
					if(vt.TENVT!="NULL"){
						strcpy(arrtemp[dem]->TENVT,vt.TENVT);
						strcpy(arrtemp[dem]->DVT,vt.DVT);
						xoaKhungDSNhanVien();
						Sort(arrtemp,0,i);
						List_VatTu_TT(arrtemp,0,28);
						gotoxy(x,y);
					}
					else{
						xoaKhungDSNhanVien();
						xoaKhung2;
						xoaKhungThongBao();
						gotoxy(x,y);
					}
				}
				if (c==60){	//F2
					check=XoaCay(ds_vt,ds,arrtemp[dem]->MAVT);
					xoaKhungDSNhanVien();
					if(check==1){	//Co xoa
						for(int j=dem;j<=i;j++){
							arrtemp[j]=arrtemp[j+1];
						}
						i--;
						Sort(arrtemp,0,i);
						xoaKhungThongBao();
						List_VatTu_TT(arrtemp,0,28);
						gotoxy(x,y);
					}
					else{
						xoaKhungThongBao();
						thongBaoLoi("Vat tu dang su dung");
						List_VatTu_TT(arrtemp,0,28);
						gotoxy(x,y);
					}
				}
			}
			else if(y==41 && dem<i-1){
				if (c==72){	//Up
					dem--;
					y--;
					gotoxy(x,y);
					Highlight();
				}
				if (c==80){	//Down
					dem++;
					xoaKhungDSNhanVien();
					GiaoDienMenuQuanLyVatTu();
					List_VatTu_TT(arrtemp,dem-28,dem);
					gotoxy(x,y);
				}
				if (c==27){ //Esc
					return;
				}
				if (c==82){	//Insert
					VATTU vt;
					vt=NhapMotVatTu(ds_vt,vt);
					if(strcmp(vt.MAVT,"quit")==0){
						gotoxy(x,y);
						break;
					}
					else{
						ThemCay(ds_vt,vt,vt.MAVT);	
						xoaKhungDSNhanVien();
						xoaKhung2();
						i++;
						arrtemp[i]=new VATTU;
						strcpy(arrtemp[i]->MAVT,vt.MAVT);
						strcpy(arrtemp[i]->TENVT,vt.TENVT);
						strcpy(arrtemp[i]->DVT,vt.DVT);
						arrtemp[i]->SLT = vt.SLT;
						//
						Sort(arrtemp,0,i);
						List_VatTu_TT(arrtemp,0,28);	
						thongBaoLoi("Them vat tu thanh cong");
					}
				}
				if (c==59){	//F1
					VATTU vt;
					vt=SuaCay(ds_vt,vt,arrtemp[dem]->MAVT);
					if(vt.TENVT!="NULL"){
						strcpy(arrtemp[dem]->TENVT,vt.TENVT);
						strcpy(arrtemp[dem]->DVT,vt.DVT);
						xoaKhungDSNhanVien();
						Sort(arrtemp,0,i);
						List_VatTu_TT(arrtemp,0,28);
						gotoxy(x,y);
					}
					else{
						xoaKhungDSNhanVien();
						xoaKhung2;
						xoaKhungThongBao();
						gotoxy(x,y);
					}
				}
				if (c==60){	//F2
					check=XoaCay(ds_vt,ds,arrtemp[dem]->MAVT);
					xoaKhungDSNhanVien();
					if(check==1){	//Co xoa
						for(int j=dem;j<=i;j++){
							arrtemp[j]=arrtemp[j+1];
						}
						i--;
						Sort(arrtemp,0,i);
						xoaKhungThongBao();
						List_VatTu_TT(arrtemp,0,28);
						gotoxy(x,y);
					}
					else{
						xoaKhungThongBao();
						thongBaoLoi("Vat tu dang su dung");
						List_VatTu_TT(arrtemp,0,28);
						gotoxy(x,y);
					}
				}
			}
		}
		
		//DS it hon 28
		else{
			if (y==14){
				if (c==72){	//Up
					dem=i-1;
					y=i+13;
					gotoxy(x,y);
				}
				if (c==80){	//Down
					y++;
					dem++;
					gotoxy(x,y);
					Highlight();
				}
				if (c==27){ //Esc
					return;
				}
				if (c==82){	//Insert
					VATTU vt;
					vt=NhapMotVatTu(ds_vt,vt);
					if(strcmp(vt.MAVT,"quit")==0){
						gotoxy(x,y);
						break;						
					}
					else{
						ThemCay(ds_vt,vt,vt.MAVT);
						xoaKhungDSNhanVien();
						xoaKhung2();
						i++;
						arrtemp[i]=new VATTU;
						strcpy(arrtemp[i]->MAVT,vt.MAVT);
						strcpy(arrtemp[i]->TENVT,vt.TENVT);
						strcpy(arrtemp[i]->DVT,vt.DVT);
						arrtemp[i]->SLT = vt.SLT;

						Sort(arrtemp,0,i);
						if (i>28){
							List_VatTu_TT(arrtemp,0,28);	
						}
						else{
							List_VatTu_All(arrtemp,i);
						}	
						thongBaoLoi("Them vat tu thanh cong");
					}
				}
				if (c==59){	//F1
					VATTU vt;
					vt=SuaCay(ds_vt,vt,arrtemp[dem]->MAVT);
					if(vt.TENVT!="NULL"){
						strcpy(arrtemp[dem]->TENVT,vt.TENVT);
						strcpy(arrtemp[dem]->DVT,vt.DVT);
						xoaKhungDSNhanVien();
						Sort(arrtemp,0,i);
						List_VatTu_All(arrtemp,i);
						gotoxy(x,y);
					}
					else{
						xoaKhungDSNhanVien();
						xoaKhung2;
						xoaKhungThongBao();
						gotoxy(x,y);
					}
				}
				if (c==60){	//F2
					check=XoaCay(ds_vt,ds,arrtemp[dem]->MAVT);
					xoaKhungDSNhanVien();
					if(check==1){	//Co xoa
						for(int j=dem;j<=i;j++){
							arrtemp[j]=arrtemp[j+1];
						}
						i--;
						Sort(arrtemp,0,i);
						xoaKhungThongBao();
						List_VatTu_All(arrtemp,i);
						gotoxy(x,y);
					}
					else{
						xoaKhungThongBao();
						thongBaoLoi("Vat tu dang su dung");
						List_VatTu_All(arrtemp,i);
						gotoxy(x,y);
					}
				}
			}
			else if(y==i+13){
				if (c==72){	//Up
					dem--;
					y--;
					gotoxy(x,y);
					Highlight();
				}
				if (c==80){	//Down
					dem=0;
					y=14;
					gotoxy(x,y);
					Highlight();
				}
				if (c==27){ //Esc
					return;
				}
				if (c==82){	//Insert
					VATTU vt;
					vt=NhapMotVatTu(ds_vt,vt);
					if(strcmp(vt.MAVT,"quit")==0){
						gotoxy(x,y);
						break;						
					}
					else{
						ThemCay(ds_vt,vt,vt.MAVT);
						xoaKhungDSNhanVien();
						xoaKhung2();
						i++;
						arrtemp[i]=new VATTU;
						strcpy(arrtemp[i]->MAVT,vt.MAVT);
						strcpy(arrtemp[i]->TENVT,vt.TENVT);
						strcpy(arrtemp[i]->DVT,vt.DVT);
						arrtemp[i]->SLT = vt.SLT;
						Sort(arrtemp,0,i);
						//
						if (i>28){
							List_VatTu_TT(arrtemp,0,28);	
						}
						else{
							List_VatTu_All(arrtemp,i);
						}	
						thongBaoLoi("Them vat tu thanh cong");
					}
				}
				if (c==59){	//F1
					VATTU vt;
					vt=SuaCay(ds_vt,vt,arrtemp[dem]->MAVT);
					if(vt.TENVT!="NULL"){
						strcpy(arrtemp[dem]->TENVT,vt.TENVT);
						strcpy(arrtemp[dem]->DVT,vt.DVT);
						xoaKhungDSNhanVien();
						Sort(arrtemp,0,i);
						List_VatTu_All(arrtemp,i);
						gotoxy(x,y);
					}
					else{
						xoaKhungDSNhanVien();
						xoaKhung2;
						xoaKhungThongBao();
						gotoxy(x,y);
					}
				}
				if (c==60){	//F2
					check=XoaCay(ds_vt,ds,arrtemp[dem]->MAVT);
					xoaKhungDSNhanVien();
					if(check==1){	//Co xoa
						for(int j=dem;j<=i;j++){
							arrtemp[j]=arrtemp[j+1];
						}
						i--;
						Sort(arrtemp,0,i);
						xoaKhungThongBao();
						List_VatTu_All(arrtemp,i);
						gotoxy(x,y);
					}
					else{
						xoaKhungThongBao();
						thongBaoLoi("Vat tu dang su dung");
						List_VatTu_All(arrtemp,i);
						gotoxy(x,y);
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
					return;
				}
				if (c==82){	//Insert
					VATTU vt;
					vt=NhapMotVatTu(ds_vt,vt);
					if(strcmp(vt.MAVT,"quit")==0){
						gotoxy(x,y);
						break;						
					}
					else{
						ThemCay(ds_vt,vt,vt.MAVT);
						xoaKhungDSNhanVien();
						xoaKhung2();
						i++;
						arrtemp[i]=new VATTU;
						strcpy(arrtemp[i]->MAVT,vt.MAVT);
						strcpy(arrtemp[i]->TENVT,vt.TENVT);
						strcpy(arrtemp[i]->DVT,vt.DVT);
						arrtemp[i]->SLT = vt.SLT;
						Sort(arrtemp,0,i);
						//
						if (i>28){
							List_VatTu_TT(arrtemp,0,28);	
						}
						else{
							List_VatTu_All(arrtemp,i);
						}	
						thongBaoLoi("Them vat tu thanh cong");
					}
				}
				if (c==59){	//F1
					VATTU vt;
					vt=SuaCay(ds_vt,vt,arrtemp[dem]->MAVT);
					if(vt.TENVT!="NULL"){
						strcpy(arrtemp[dem]->TENVT,vt.TENVT);
						strcpy(arrtemp[dem]->DVT,vt.DVT);
						xoaKhungDSNhanVien();
						Sort(arrtemp,0,i);
						List_VatTu_All(arrtemp,i);
						gotoxy(x,y);
					}
					else{
						xoaKhungDSNhanVien();
						xoaKhung2;
						xoaKhungThongBao();
						gotoxy(x,y);
					}
				}
				if (c==60){	//F2
					check=XoaCay(ds_vt,ds,arrtemp[dem]->MAVT);
					xoaKhungDSNhanVien();
					if(check==1){	//Co xoa
						for(int j=dem;j<=i;j++){
							arrtemp[j]=arrtemp[j+1];
						}
						i--;
						Sort(arrtemp,0,i);
						xoaKhungThongBao();
						List_VatTu_All(arrtemp,i);
						gotoxy(x,y);
					}
					else{
						xoaKhungThongBao();
						thongBaoLoi("Vat tu dang su dung");
						List_VatTu_All(arrtemp,i);
						gotoxy(x,y);
					}
				}
			}
		}
	}
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
	cout<<"F1: Chinh sua nhan vien";
	gotoxy(30,43);
	cout<<"F2: Xoa nhan vien";
	gotoxy(55,43);
	cout<<"F3: Lap hoa don cho nhan vien";
	gotoxy(5,44);
	cout<<"Ins: Them nhan vien moi";
	gotoxy(30,44);
	cout<<"Esc: Quay lai";
	gotoxy(55,44);
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
				gotoxy(121,25);
				if (c==72){	//Up
					xoaKhungDSNhanVien();
					GiaoDienMenuQuanLyNhanVien();
					List_NhanVien_TT(ds,ds.soluong-28,ds.soluong);
					y=41;
					gotoxy(x,y);
					dem=ds.soluong-1;
				}
				if (c==80){	//Down
					y++;
					gotoxy(x,y);
					Highlight();
					dem++;
				}
				if (c==27){ //Esc
					return;
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						nv=Insert_NV(ds,nv);
						if(nv.MANV!=-1){
							Insert_Last(ds,nv);	
							CreateList_HOADON(nv.PTR_HD);
							xoaKhungDSNhanVien();
							Sort_NhanVien(ds);
							List_NhanVien_TT(ds,0,28);	
							y=14;
							dem=0;
							gotoxy(x,y);
							thongBaoLoi("Them nhan vien thanh cong");
						}
						else{
							y=14;
							dem=0;
							gotoxy(x,y);
							break;
						}

					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
					xoaKhungDSNhanVien();
					List_NhanVien_TT(ds,0,28);	
					y=14;
					dem=0;
					gotoxy(x,y);
				}
				if (c==60){	//F2
					Delete_NhanVien(ds,dem);
					xoaKhungDSNhanVien();
					List_NhanVien_TT(ds,0,28);
					y=14;
					dem=0;	
					gotoxy(x,y);
				}
				if (c==61){ //F3
					while(true){
						HOADON hd;
						hd=nhapHoaDon(ds,ds_vt);
						if(strcmp(hd.SOHD,"quit")!=0){
							InsertLast_HOADON(ds.nodes[dem]->PTR_HD,hd);
							xoaKhung2();
							thongBaoLoi("Them hoa don thanh cong");
							xoaKhungDSNhanVien();
							List_NhanVien_TT(ds,0,28);	
							int c=getch();
							if(c==27){
								break;
							}
						}
						else{
							xoaKhung2();
							gotoxy(x,y);
							break;
						}
					}	
				}
				if (c==13){	//Enter
					if(EmptyHDCheck(ds,dem)==1){
						thongBaoLoi("Nhan vien chua co hoa don");
					}
					else{
						GiaoDienHienHoaDonNhanVien(ds,ds_vt,dem);
						clrscr();
						GiaoDienKhung();
						GiaoDienMenuQuanLyNhanVien();
						List_NhanVien_TT(ds,0,28);	
						gotoxy(x,y);
					}
				}
			}
			else if(y>14 && y<41 && dem>0 && dem<ds.soluong-1){
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
					return;
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						nv=Insert_NV(ds,nv);
						if(nv.MANV!=-1){
							Insert_Last(ds,nv);	
							CreateList_HOADON(nv.PTR_HD);
							xoaKhungDSNhanVien();
							Sort_NhanVien(ds);
							List_NhanVien_TT(ds,0,28);	
							y=14;
							dem=0;
							gotoxy(x,y);
							thongBaoLoi("Them nhan vien thanh cong");					
						}					
						else{
							y=14;
							dem=0;
							gotoxy(x,y);
							break;
						}
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
					xoaKhungDSNhanVien();
					List_NhanVien_TT(ds,0,28);	
					y=14;
					dem=0;
					gotoxy(x,y);
				}
				if (c==60){	//F2
					Delete_NhanVien(ds,dem);
					xoaKhungDSNhanVien();
					List_NhanVien_TT(ds,0,28);	
					y=14;
					dem=0;
					gotoxy(x,y);
				}
				if (c==61){ //F3
					while(true){
						HOADON hd;
						hd=nhapHoaDon(ds,ds_vt);
						if(strcmp(hd.SOHD,"quit")!=0){
							InsertLast_HOADON(ds.nodes[dem]->PTR_HD,hd);
							xoaKhung2();
							thongBaoLoi("Them hoa don thanh cong");
							xoaKhungDSNhanVien();
							List_NhanVien_TT(ds,0,28);	
							int c=getch();
							if(c==27){
								break;
							}
						}
						else{
							xoaKhung2();
							gotoxy(x,y);
							break;
						}
					}	
				}
				if (c==13){	//Enter
					if(EmptyHDCheck(ds,dem)==1){
						thongBaoLoi("Nhan vien chua co hoa don");
					}
					else{
						GiaoDienHienHoaDonNhanVien(ds,ds_vt,dem);
						clrscr();
						GiaoDienKhung();
						GiaoDienMenuQuanLyNhanVien();
						List_NhanVien_TT(ds,0,28);	
						gotoxy(x,y);
					}
				}
			}
			else if (y==41 && dem==ds.soluong-1){
				if (c==72){	//Up
					y--;
					dem--;
					gotoxy(x,y);
					Highlight();
				}
				if (c==80){	//Down
					xoaKhungDSNhanVien();
					GiaoDienMenuQuanLyNhanVien();
					y=14;
					List_NhanVien_TT(ds,0,28);
					dem=1;
					gotoxy(x,y);
					Highlight();
				}
				if (c==27){ //Esc
					return;
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						nv=Insert_NV(ds,nv);
						if(nv.MANV!=-1){
							Insert_Last(ds,nv);	
							CreateList_HOADON(nv.PTR_HD);
							xoaKhungDSNhanVien();
							Sort_NhanVien(ds);
							List_NhanVien_TT(ds,0,28);	
							y=14;
							dem=0;
							gotoxy(x,y);
							thongBaoLoi("Them nhan vien thanh cong");					
						}
						else{
							y=14;
							dem=0;
							gotoxy(x,y);
							break;
						}
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
					xoaKhungDSNhanVien();
					List_NhanVien_TT(ds,0,28);	
					y=14;
					dem=0;
					gotoxy(x,y);
					gotoxy(x,y);
				}
				if (c==60){	//F2
					Delete_NhanVien(ds,dem);
					xoaKhungDSNhanVien();
					List_NhanVien_TT(ds,0,28);
					y=14;
					dem=0;
					gotoxy(x,y);
				}
				if (c==61){ //F3
					while(true){
						HOADON hd;
						hd=nhapHoaDon(ds,ds_vt);
						if(strcmp(hd.SOHD,"quit")!=0){
							InsertLast_HOADON(ds.nodes[dem]->PTR_HD,hd);
							thongBaoLoi("Them hoa don thanh cong");
							xoaKhung2();
							xoaKhungDSNhanVien();
							List_NhanVien_TT(ds,0,28);	
							int c=getch();
							if(c==27){
								break;
							}
						}
						else{
							xoaKhung2();
							gotoxy(x,y);
							break;
						}
					}	
				}
				if (c==13){	//Enter
					if(EmptyHDCheck(ds,dem)==1){
						thongBaoLoi("Nhan vien chua co hoa don");
					}
					else{
						GiaoDienHienHoaDonNhanVien(ds,ds_vt,dem);
						clrscr();
						GiaoDienKhung();
						GiaoDienMenuQuanLyNhanVien();
						List_NhanVien_TT(ds,0,28);	
						gotoxy(x,y);
					}
				}
			}
			else if(y==14 && dem>0){
				if (c==72){	//Up
					dem--;
					xoaKhungDSNhanVien();
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
					return;
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						nv=Insert_NV(ds,nv);
						if(nv.MANV!=-1){
							Insert_Last(ds,nv);	
							CreateList_HOADON(nv.PTR_HD);
							xoaKhungDSNhanVien();
							Sort_NhanVien(ds);
							List_NhanVien_TT(ds,0,28);	
							y=14;
							dem=0;
							gotoxy(x,y);
							thongBaoLoi("Them nhan vien thanh cong");						
						}
						else{
							y=14;
							dem=0;
							gotoxy(x,y);
							break;
						}
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
					xoaKhungDSNhanVien();
					List_NhanVien_TT(ds,0,28);	
					y=14;
					dem=0;
					gotoxy(x,y);
				}
				if (c==60){	//F2
					Delete_NhanVien(ds,dem);
					xoaKhungDSNhanVien();
					List_NhanVien_TT(ds,0,28);	
					y=14;
					dem=0;
					gotoxy(x,y);
				}
				if (c==61){ //F3
					while(true){
						HOADON hd;
						hd=nhapHoaDon(ds,ds_vt);
						if(strcmp(hd.SOHD,"quit")!=0){
							InsertLast_HOADON(ds.nodes[dem]->PTR_HD,hd);
							thongBaoLoi("Them hoa don thanh cong");
							xoaKhung2();
							xoaKhungDSNhanVien();
							List_NhanVien_TT(ds,0,28);	
							int c=getch();
							if(c==27){
								break;
							}
						}
						else{
							gotoxy(x,y);
							break;
						}
					}	
				}
				if (c==13){	//Enter
					clrscr();
					GiaoDienKhung();
					GiaoDienMenuQuanLyNhanVien();
					List_NhanVien_TT(ds,0,28);	
					gotoxy(x,y);
				}
			}
			else if(y==41 && dem<ds.soluong-1){
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
					return;
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						nv=Insert_NV(ds,nv);
						if(nv.MANV!=-1){
							Insert_Last(ds,nv);	
							CreateList_HOADON(nv.PTR_HD);
							xoaKhungDSNhanVien();
							Sort_NhanVien(ds);
							List_NhanVien_TT(ds,0,28);
							y=14;
							dem=0;
							gotoxy(x,y);	
							thongBaoLoi("Them nhan vien thanh cong");						
						}
						else{
							y=14;
							dem=0;
							gotoxy(x,y);
							break;
						}
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
					xoaKhungDSNhanVien();
					List_NhanVien_TT(ds,0,28);	
					y=14;
					dem=0;
					gotoxy(x,y);
				}
				if (c==60){	//F2
					Delete_NhanVien(ds,dem);
					xoaKhungDSNhanVien();
					List_NhanVien_TT(ds,0,28);	
					y=14;
					dem=0;
					gotoxy(x,y);
				}
				if (c==61){ //F3
					while(true){
						HOADON hd;
						hd=nhapHoaDon(ds,ds_vt);
						if(strcmp(hd.SOHD,"quit")!=0){
							InsertLast_HOADON(ds.nodes[dem]->PTR_HD,hd);
							thongBaoLoi("Them hoa don thanh cong");
							xoaKhung2();
							xoaKhungDSNhanVien();
							List_NhanVien_TT(ds,0,28);	
							int c=getch();
							if(c==27){
								break;
							}
						}
						else{
							xoaKhung2();
							gotoxy(x,y);
							break;
						}
					}	
				}
				if (c==13){	//Enter
					if(EmptyHDCheck(ds,dem)==1){
						thongBaoLoi("Nhan vien chua co hoa don");
					}
					else{
						GiaoDienHienHoaDonNhanVien(ds,ds_vt,dem);
						clrscr();
						GiaoDienKhung();
						GiaoDienMenuQuanLyNhanVien();
						List_NhanVien_TT(ds,0,28);	
						gotoxy(x,y);
					}
				}
			}
		}
		
		//DS it hon 28
		else{
			if (y==14){
				if (c==72){	//Up
					dem=ds.soluong-1;
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
					return;
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						nv=Insert_NV(ds,nv);
						if(nv.MANV!=-1){
							Insert_Last(ds,nv);
							CreateList_HOADON(nv.PTR_HD);
							xoaKhungDSNhanVien();
							Sort_NhanVien(ds);
							if (ds.soluong>28){
								List_NhanVien_TT(ds,0,28);
								y=14;
								dem=0;
								gotoxy(x,y);	
							}
							else{
								y=14;
								dem=0;
								gotoxy(x,y);
								List_NhanVien_All(ds);
							}	
							thongBaoLoi("Them nhan vien thanh cong");						
						}
						else{
							y=14;
							dem=0;
							gotoxy(x,y);
							break;
						}
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
					xoaKhungDSNhanVien();
					List_NhanVien_All(ds);
					y=14;
					dem=0;
					gotoxy(x,y);
				}
				if (c==60){	//F2
					Delete_NhanVien(ds,dem);
					xoaKhungDSNhanVien();
					List_NhanVien_All(ds);	
					y=14;
					dem=0;
					gotoxy(x,y);
				}
				if (c==61){ //F3
					while(true){
						HOADON hd;
						hd=nhapHoaDon(ds,ds_vt);
						if(strcmp(hd.SOHD,"quit")!=0){
							InsertLast_HOADON(ds.nodes[dem]->PTR_HD,hd);
							thongBaoLoi("Them hoa don thanh cong");
							xoaKhung2();
							xoaKhungDSNhanVien();
							List_NhanVien_All(ds);	
							int c=getch();
							if(c==27){
								break;
							}
						}
						else{
							gotoxy(x,y);
							break;
						}
					}	
				}
				if (c==13){	//Enter
					if(EmptyHDCheck(ds,dem)==1){
						thongBaoLoi("Nhan vien chua co hoa don");
					}
					else{
						GiaoDienHienHoaDonNhanVien(ds,ds_vt,dem);
						clrscr();
						GiaoDienKhung();
						GiaoDienMenuQuanLyNhanVien();
						List_NhanVien_All(ds);	
						gotoxy(x,y);
					}
				}
			}
			else if(y==ds.soluong+13){
				if (c==72){	//Up
					dem--;
					y--;
					gotoxy(x,y);
					Highlight();
				}
				if (c==80){	//Down
					dem=0;
					y=14;
					gotoxy(x,y);
					Highlight();
				}
				if (c==27){ //Esc
					return;
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						nv=Insert_NV(ds,nv);
						if(nv.MANV!=-1){
							Insert_Last(ds,nv);	
							CreateList_HOADON(nv.PTR_HD);
							xoaKhungDSNhanVien();
							Sort_NhanVien(ds);
							if (ds.soluong>28){
								y=14;
								dem=0;
								gotoxy(x,y);
								List_NhanVien_TT(ds,0,28);	
							}
							else{
								y=14;
								dem=0;
								gotoxy(x,y);
								List_NhanVien_All(ds);
							}
							thongBaoLoi("Them nhan vien thanh cong");					
						}
						else{
							y=14;
							dem=0;
							gotoxy(x,y);
							break;
						}
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
					xoaKhungDSNhanVien();
					List_NhanVien_All(ds);
					y=14;
					dem=0;
					gotoxy(x,y);
				}
				if (c==60){	//F2
					Delete_NhanVien(ds,dem);
					xoaKhungDSNhanVien();
					List_NhanVien_All(ds);	
					y=14;
					dem=0;
					gotoxy(x,y);
				}
				if (c==61){ //F3
					while(true){
						HOADON hd;
						hd=nhapHoaDon(ds,ds_vt);
						if(strcmp(hd.SOHD,"quit")!=0){
							InsertLast_HOADON(ds.nodes[dem]->PTR_HD,hd);
							thongBaoLoi("Them hoa don thanh cong");
							xoaKhung2();
							xoaKhungDSNhanVien();
							List_NhanVien_All(ds);
							int c=getch();
							if(c==27){
								break;
							}							
						}
						else{
							xoaKhung2();
							gotoxy(x,y);
							break;
						}
					}	
				}
				if (c==13){	//Enter
					if(EmptyHDCheck(ds,dem)==1){
						thongBaoLoi("Nhan vien chua co hoa don");
					}
					else{
						GiaoDienHienHoaDonNhanVien(ds,ds_vt,dem);
						clrscr();
						GiaoDienKhung();
						GiaoDienMenuQuanLyNhanVien();
						List_NhanVien_All(ds);	
						gotoxy(x,y);
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
					return;
				}
				if (c==82){	//Insert
					while(true){
						NHANVIEN nv;
						nv=Insert_NV(ds,nv);
						if(nv.MANV!=-1){
							Insert_Last(ds,nv);	
							CreateList_HOADON(nv.PTR_HD);
							xoaKhungDSNhanVien();
							Sort_NhanVien(ds);
							if (ds.soluong>28){
								y=14;
								dem=0;
								gotoxy(x,y);
								List_NhanVien_TT(ds,0,28);	
							}
							else{
								y=14;
								dem=0;
								gotoxy(x,y);
								List_NhanVien_All(ds);
							}
							thongBaoLoi("Them nhan vien thanh cong");					
						}
						else{
							y=14;
							dem=0;
							gotoxy(x,y);
							break;
						}
					}
				}
				if (c==59){	//F1
					Edit_NV(ds,ds.nodes[dem]->MANV);
					xoaKhungDSNhanVien();
					List_NhanVien_All(ds);
					y=14;
					dem=0;
					gotoxy(x,y);
				}
				if (c==60){	//F2
					Delete_NhanVien(ds,dem);
					xoaKhungDSNhanVien();
					List_NhanVien_All(ds);	
					y=14;
					dem=0;
					gotoxy(x,y);
				}
				if (c==61){ //F3
					while(true){
						HOADON hd;
						hd=nhapHoaDon(ds,ds_vt);
						if(strcmp(hd.SOHD,"quit")!=0){
							InsertLast_HOADON(ds.nodes[dem]->PTR_HD,hd);
							thongBaoLoi("Them hoa don thanh cong");
							xoaKhung2();
							xoaKhungDSNhanVien();
							List_NhanVien_All(ds);
							int c=getch();
							if(c==27){
								break;
							}							
						}
						else{
							xoaKhung2();
							gotoxy(x,y);
							break;
						}
					}	
				}
				if (c==13){	//Enter
					if(EmptyHDCheck(ds,dem)==1){
						thongBaoLoi("Nhan vien chua co hoa don");
					}
					else{
						GiaoDienHienHoaDonNhanVien(ds,ds_vt,dem);
						clrscr();
						GiaoDienKhung();
						GiaoDienMenuQuanLyNhanVien();
						List_NhanVien_All(ds);	
						gotoxy(x,y);
					}
				}
			}
		}
	}
}

void inHoaDonTheoMa(DS_NV nv) { // cau g in hoa don dua vao so hoa don ta nhap vao
    xoaKhungDSNhanVien();
	char sohd[21];
    DS_HOADON ds;
    VeKhung(60,3,48,4);
    // line ngang 
    for (int i=61;i<=107;i++) { 
        gotoxy(i,5);
        cout << char(196);
    }
        gotoxy(60,5);
        cout << char(195);
        gotoxy(107,5);
        cout << char(180);
    // line doc 2
    for (int i=4;i<=6;i++) { 
        gotoxy(89,i);
        cout << char(179);
    }
        gotoxy(89,3);
        cout << char(194);
        gotoxy(89,5);
        cout << char(197);
        gotoxy(89,7);
        cout << char(193);
    // line doc 3
    for (int i=4;i<=6;i++) { 
        gotoxy(102,i);
        cout << char(179);
    }
        gotoxy(102,3);
        cout << char(194);
        gotoxy(102,5);
        cout << char(197);
        gotoxy(102,7);
        cout << char(193);
    SetColor(LUC);
    gotoxy(70,4);
    cout << "SO HOA DON";
    gotoxy(92,4);
    cout << "NGAY LAP";
    gotoxy(103,4);
    cout << "LOAI";
    SetColor(TRANG);
//    VeKhung(69,11,38,2);
//    gotoxy(70,12);
//    cout << "Nhap so hoa don: ";
    InputNumber(sohd,20);
    for(int i=0;i<nv.soluong;i++) {
        for (NODES_HOADON p = nv.nodes[i]->PTR_HD.first;p!=NULL;p=p->next) {
            if(strcmp(p->info.SOHD,sohd)==0) {
                gotoxy(12,i+13);
                cout << p->info.SOHD;
                gotoxy(39,i+13);
                cout << p->info.date.day <<"/"<<p->info.date.month <<"/"<<p->info.date.year;
                gotoxy(53,i+13);
                cout << p->info.LoaiHD;
               
            }
        }
    }
    int c=getch();
    if(c==27){
    	return;
	}
}

void traSoLuongTon(HOADON addHoaDon, TREE_VATTU& tree)
{
    TREE_VATTU temp;

    for (int i = 0; i < addHoaDon.PTR_CTHD.soluong; i++) {
        temp = TimKiemVatTu(tree, addHoaDon.PTR_CTHD.nodes[i].MAVT); //con tro temp tro toi phan tu can xu ly

        temp->info.SLT += addHoaDon.PTR_CTHD.nodes[i].SL;
    }
}

void traHang(DS_NV nv,TREE_VATTU& tree) {
	clrscr();
	GiaoDienKhung();
	VeKhung(64,3,48,4);
    // line ngang 
    for (int i=65;i<=111;i++) { 
        gotoxy(i,5);
        cout << char(196);
    }
        gotoxy(64,5);
        cout << char(195);
        gotoxy(112,5);
        cout << char(180);
    // line doc 2
    for (int i=4;i<=6;i++) { 
        gotoxy(93,i);
        cout << char(179);
    }
        gotoxy(93,3);
        cout << char(194);
        gotoxy(93,5);
        cout << char(197);
        gotoxy(93,7);
        cout << char(193);
    // line doc 3
    for (int i=4;i<=6;i++) { 
        gotoxy(106,i);
        cout << char(179);
    }
        gotoxy(106,3);
        cout << char(194);
        gotoxy(106,5);
        cout << char(197);
        gotoxy(106,7);
        cout << char(193);
    SetColor(LUC);
    gotoxy(74,4);
    cout << "SO HOA DON";
    gotoxy(96,4);
    cout << "NGAY LAP";
    gotoxy(107,4);
    cout << "LOAI";
    SetColor(TRANG);
	VeKhung(5,3,56,40);
	// line ngang
	for (int i=6;i<=60;i++) {  
		gotoxy(i,5);
		cout << char(196);
	}
		gotoxy(5,5);
		cout << char(195);
		gotoxy(61,5);
		cout << char(180);
	// line doc 1	
	for (int i=4;i<=42;i++) { 
		gotoxy(10,i);
		cout << char(179);
	}
		gotoxy(10,3);
		cout << char(194);
		gotoxy(10,5);
		cout << char(197);
		gotoxy(10,43);
		cout << char(193);
	// line doc 2	
	for (int i=4;i<=42;i++) { 
		gotoxy(26,i);
		cout << char(179);
	}
		gotoxy(26,3);
		cout << char(194);
		gotoxy(26,5);
		cout << char(197);
		gotoxy(26,43);
		cout << char(193);
	// line doc 3	
	for (int i=4;i<=42;i++) { 
		gotoxy(35,i);
		cout << char(179);
	}
		gotoxy(35,3);
		cout << char(194);
		gotoxy(35,5);
		cout << char(197);
		gotoxy(35,43);
		cout << char(193);
	// line doc 4	
	for (int i=4;i<=42;i++) { 
		gotoxy(47,i);
		cout << char(179);
	}
		gotoxy(47,3);
		cout << char(194);
		gotoxy(47,5);
		cout << char(197);
		gotoxy(47,43);
		cout << char(193);
	// line doc 5	
	for (int i=4;i<=42;i++) { 
		gotoxy(51,i);
		cout << char(179);	
	}
		gotoxy(51,3);
		cout << char(194);
		gotoxy(51,5);
		cout << char(197);
		gotoxy(51,43);
		cout << char(193);
	gotoxy(6,4);
	SetColor(LUC);
	cout << "STT";
	gotoxy(16,4);
	cout << "MA VT";
	gotoxy(30,4);
	cout << "SL";
	gotoxy(38,4);
	cout << "DON GIA";
	gotoxy(48,4);
	cout << "TT";
	gotoxy(55,4);
	cout << "VAT";
	gotoxy(5,44);
	cout<<"Enter: Tra hang";
	gotoxy(30,44);
	cout<<"Esc: Quay lai";
	SetColor(TRANG);
	char sohd[21];
	VeKhung(69,11,38,2);
    gotoxy(70,12);
    cout << "Nhap so hoa don: ";
    InputNumber(sohd,20);
    int dem=0;
    int x=7,y=6;
    for(int i=0;i<nv.soluong;i++) {
        for (NODES_HOADON p = nv.nodes[i]->PTR_HD.first;p!=NULL;p=p->next) {
            if(strcmp(p->info.SOHD,sohd)==0) {
            	gotoxy(70,i+5);
                cout << p->info.SOHD;
                gotoxy(95,i+5);
                cout << p->info.date.day <<"/"<<p->info.date.month <<"/"<<p->info.date.year;
                gotoxy(109,i+5);
                cout << p->info.LoaiHD;
                for (int j=0;j<p->info.PTR_CTHD.soluong;j++) {
                	gotoxy(7,j+6);
					cout << j+1;
					gotoxy(14,j+6);
					cout << p->info.PTR_CTHD.nodes[j].MAVT;
					gotoxy(30,j+6);
					cout << p->info.PTR_CTHD.nodes[j].SL;
					gotoxy(38,j+6);
					cout << p->info.PTR_CTHD.nodes[j].DonGia;
					gotoxy(49,j+6);
					cout << p->info.PTR_CTHD.nodes[j].TrangThai;
					gotoxy(55,j+6);
					cout << p->info.PTR_CTHD.nodes[j].VAT;
					
				}
				gotoxy(x,y);
			    while (true) {
					int c=getch();
					if(y==6) {
						if(c==72) {
							y=6+p->info.PTR_CTHD.soluong;
							dem = p->info.PTR_CTHD.soluong-1;
							gotoxy(x,y);
							
						}
						if(c==80) {
							y++;
							dem++;
							gotoxy(x,y);
						}
						if(c==ENTER) {
							if(p->info.PTR_CTHD.nodes[dem].TrangThai==1) {
								p->info.PTR_CTHD.nodes[dem].TrangThai=0;
								traSoLuongTon(p->info,tree);
							}
							gotoxy(49,dem+6);
							cout << p->info.PTR_CTHD.nodes[dem].TrangThai;
							thongBaoLoi("Tra hang thanh cong");
						}
						if(c==ESC) return;
						
					}
					if(y==5+p->info.PTR_CTHD.soluong) {
						if(c==UP) {
							y--;	
							dem--;
							gotoxy(x,y);
							
						}
						if(c==DOWN) {
							y=6;
							dem=0;
							gotoxy(x,y);
						}
						if(c==ENTER) {
							if(p->info.PTR_CTHD.nodes[dem].TrangThai==1) {
								p->info.PTR_CTHD.nodes[dem].TrangThai=0;
								traSoLuongTon(p->info,tree);
							}
							gotoxy(49,dem+6);
							cout << p->info.PTR_CTHD.nodes[dem].TrangThai;
							thongBaoLoi("Tra hang thanh cong");
						}
						if(c==ESC) return;
					}
					else{
						if(c==UP) {
							y--;
							dem--;
							gotoxy(x,y);
						}
						if (c==DOWN) {
							y++;
							dem++;
							gotoxy(x,y);
						}
						if(c==ENTER) {
							if(p->info.PTR_CTHD.nodes[dem].TrangThai==1) {
								p->info.PTR_CTHD.nodes[dem].TrangThai=0;
								traSoLuongTon(p->info,tree);
							}
							gotoxy(49,dem+6);
							cout << p->info.PTR_CTHD.nodes[dem].TrangThai;
							thongBaoLoi("Tra hang thanh cong");
						}
						if(c==ESC) return;
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
		int check=0;
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
					GhiFileVT(ds_vt,"VatTu.txt");
					SaveFile_NV(ds_nv,"NhanVien.txt");
					exit(0);
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
					GiaoDienDSVatTu(ds_vt,ds_nv);
					int c=getch();
					if(c==27){
						return;
					}
				}
				case 19:{
					GiaoDienDSNhanVien(ds_nv,ds_vt);
					return;
				}
				case 25:{
					traHang(ds_nv,ds_vt);
					return;	
				}
				case 31:{
					while(true){
						check=ThongKeDoanhThu(ds_nv,ds_vt);
						if(check==-1) break;
					}
					return;
				}
				case 37:{
					xoaKhungThongBao();
					gotoxy(122,44);
					cout<<"Ban co chac chan muon thoat? (Y/N): ";
					char thoat[3];
					gets(thoat);
					if (strcmp(thoat,"Y")==0 || strcmp(thoat,"y")==0 || 
						strcmp(thoat,"Yes")==0 || strcmp(thoat,"yes")==0){
							GhiFileVT(ds_vt,"VatTu.txt");
							SaveFile_NV(ds_nv,"NhanVien.txt");
							exit(0);
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

	DocFileVatTu(ds_vt,"VATTU2.txt");
	ReadFile_NV(ds_nv,"NhanVien.txt");
	while(true){
		clrscr();
		GiaoDienMenuChinh(ds_nv,ds_vt);
	}
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
