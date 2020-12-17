#pragma once
#include"lib.h"
#define MAXVT 20
#define MAXNV 500




//***************************Cau Truc***************************

struct Vattu{
	char MAVT[11];
	char TENVT[51];
	char DVT[11];
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

struct DSLKD{
	NODES_HOADON first;
	NODES_HOADON last;
};
typedef struct DSLKD DS_HOADON;


struct Nhanvien{
	int MANV;
	char HO[21];
	char TEN[21];
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

//***************************Cau Truc Xu Li Nhap***************************
struct InputSTR {
	unsigned int n;
	char *Key[255];
};


//***************************Vat Tu***************************

//Tao Cay
void Khoi_Tao_Cay(TREE_VATTU &tree);
void ThemCay(TREE_VATTU &tree, VATTU &vt, string maVT);

//Mot So  Ham Kiem Tra
int Cay_Rong(TREE_VATTU tree);
TREE_VATTU TimKiemVatTu(TREE_VATTU tree, char MVT[]);
int KiemTraVatTuTrung(char MVT[], TREE_VATTU tree);
int KiemTraVatTuDeSua(char FixMVT[], TREE_VATTU NodeHienTai, TREE_VATTU tree);

//Doc-Ghi File Vat Tu
void GhiFileVT_NLR(TREE_VATTU tree, fstream& f);
void GhiFileVT(TREE_VATTU tree, string nameFile);
void LineToVatTu(string line, char MVT[], VATTU &vt);
void DocFileVatTu(TREE_VATTU &tree, string fileName);

//Nhap-Xuat Vat Tu
void NhapMotVatTu(TREE_VATTU &tree);
void XuatMotPhanTu(TREE_VATTU tree); 
char IsLeaf(TREE_VATTU &tree);
int DemNode(TREE_VATTU &tree); //Dem So Node Co Trong Cay De Xuat Bang Mang
void showDSVatTu (TREE_VATTU ds,int k);

//Xoa Vat Tu
void XoaCayTHCo2NodeLa(TREE_VATTU& tree, TREE_VATTU& temp);
void XoaVT(TREE_VATTU& tree, char deleteKey[]);

//Sua Vat Tu
void SuaVT(TREE_VATTU &tree);
void SuaCay(TREE_VATTU &tree);

//***************************Nhan Vien***************************









//***************************Hoa Don***************************

//Khoi Tao Danh Sach Lien Ket
void CreateList_HOADON(DS_HOADON &dshd);

//Them Dau-Cuoi
void InsertFirst_HOADON(DS_HOADON &dshd, HOADON &hd);
int InsertLast_HOADON(DS_HOADON &dshd, HOADON &hd);

//Kiem Tra - Tim Kiem
int EmptyList_HOADON(DS_HOADON &dshd);
int Search_MSHD(NODES_HOADON First, char* x);

//Nhap-Xuat Hoa Don
void CapNhatSoLuongTon(HOADON addHoaDon, TREE_VATTU& tree); //Ham Giup Cap Nhat Lai So Luong Ton Cua Vat Tu Thong Qua Loai Hoa Don
HOADON nhapHoaDon(NODES_HOADON& first);
void lietKeHoaDon(NODES_HOADON hd);



//***************************Chi Tiet Hoa Don***************************

//Khoi Tao Danh Sach Tuyen Tinh
void CreateList_CTHD(DS_CTHD &ds_cthd);

//Ham Kiem Tra - Tim Kiem
int Search_MaVT(DS_CTHD& hd, char* x);
int FULL_CTHD(DS_CTHD ds_cthd);

//Them Vao Cuoi
void InsertLast_CTHD(DS_CTHD &ds_cthd,CHITIET_HOADON cthd);

//Nhap-Xuat Chi Tiet Hoa Don
CHITIET_HOADON nhapChiTietHoaDon(DS_CTHD& hd);
void showCTHD(HOADON hd);


//***************************Do Hoa***************************

void xoaDataChiTietHoaDon();
void xoaDataHoaDon();
void xoaKhungTrai();
void xoaKhungPhai();
void xoaKhungChinh();
void xoaKhung1();
void xoaKhung2();
void xoaKhungThongBao();

void veKhungHoaDon();
void veKhungChiTietHoaDon();
void veKhungVatTu();

void toMauHoaDon(HOADON hd,int i);
void boToMauHoaDon(HOADON hd,int i,int key);

void vachNgan();
void giaoDienKhung();


////***************************Xu Li***************************

//Kiem Tra
void thongBaoLoi(string s);
int checkDateTime(struct Date tg);

//Xu Li Chuoi - So
Date StringToDate(string s); //Chuyen Tu Chuoi Sang Ngay - Thang - Nam
string FloatToString(float a); // Chuyen Tu So Thuc Sang Chuoi

//Xu Li Nhap Vao Tu Ban Phim
void InputStringSpace(char *variable, int max);
void InputNumber(char *variable, int max);
void InputLoai(char *variable, int max);
void InputString(char *variable, int max);

