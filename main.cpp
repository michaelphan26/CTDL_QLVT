#include <iostream>
#include <alloc.h>

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
typedef struct Vattu *VT;


struct CT_Hoadon{
	char MAVT[10];
	int SL;
	int DonGia;
	int VAT;
	int TrangThai;	
};
struct DSTT{
	int m;
	CT_Hoadon *nodes[MAXVT];
};
typedef struct DSTT cthd;

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
	cthd PTRcthd;
};
struct DSLKD{
	Hoadon hd;
	struct Hoadon *next;
};
typedef struct DSLKD *dshd;


struct Nhanvien{
	int MANV;
	char HO[20];
	char TEN[20];
	char PHAI[5];
	char CMND[12];
	// Con tro DSHD
	dshd PTRhd;
};
typedef struct Nhanvien NV;
struct DSCT{
	int n;
	NV *nodes[MAXNV];	
};
typedef struct DSCT dsnv;



int Empty_NhanVien(dsnv &ds){
	return ds.n=0;
}
int Full_NhanVien(dsnv &ds) {
	return ds.n=MAXNV; 
}

void Initialize_HD(dshd &First){
	First=NULL;
}

int Empty_CTHD(dscthd &ds){
	return ds.n=0;
}
int Full_CTHD(dscthd &ds) {
	return ds.n=MAXVT; 
}

int main{
	
};
