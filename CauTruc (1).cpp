#pragma once
#include"CauTruc.h"

// cac ham giao dien

void vachNgan() {
	//vach ngan
	SetColor(LAM);
	for(int i=6;i<=40;i++){
		gotoxy(58,i);
		cout << char(179);
	}
	SetColor(TRANG);
}

void giaoDienKhung(){
	//Khung chinh
	VeKhung(1,1,117,44);
	
	//Khung phu 1
	VeKhung(120,1,44,19);
	
	//Khung phu 2
	VeKhung(120,21,44,19);
	
	//Khung phu 3
	VeKhung(120,41,44,4);
	
}

void thongBaoLoi(string s) {
	SetColor(DODAM);
	gotoxy(123,42);
	cout << s;
	gotoxy(123,43);
	cout << "Nhan phim bat ki de tiep tuc";
	SetColor(TRANG);
}

int checkDateTime(struct Date tg)
{
	
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
		strcat(year, " la nam khong nhuan nen thang 2 chi co 28 ngay!");
		thongBaoLoi(year);			
		return 1;
	}
	if (tg.day > 31)
	{
		char month[2];
		itoa(tg.month, month, 10);
		char thongbao[7] = "Thang ";
		strcat(month, " chi co 31 ngay!");
		strcat(thongbao, month);
		thongBaoLoi(thongbao);
		return 1;
	}
	return -1;
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


void InputString(char *variable, int max)
{
	int MaxNhap = max;
	rewind(stdin);
	InputSTR Nhap;	
	Nhap.n = 0;
	while(true)
	{
		if(kbhit())
		{
			char c = getch();
			if(c==27) {
				strcpy(variable,"quit");
				return;
			}
			if(!kbhit() && !(!((int)c >= 65 && (int)c <= 90) && !((int)c >= 97 && (int)c <= 122) && !((int)c>=48 && (int)c<=57)) && Nhap.n < MaxNhap)
			{
				if (Nhap.n == 0 && (int)c>=48 && (int)c<=57) {
					continue;
				}
				Nhap.Key[Nhap.n] = new char;
				cout << c;
				*Nhap.Key[Nhap.n] = c;
				Nhap.n++;
			}
			
			if(Nhap.n>0 && c == '\r')
			{
				if(Nhap.n > 0 && *Nhap.Key[Nhap.n - 1] == ' ')
				{
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
					if(Nhap.n > 0)
					{
						Nhap.n--;
					}
				}	
				break;
			}
			if(c == BACKSPACE && Nhap.n > 0)
			{
				gotoxy(wherex() - 1, wherey());
				cout << " ";
				gotoxy(wherex() - 1, wherey());
				Nhap.n--;
			}
		}
	}
	for(int i = 0; i < Nhap.n; i++)
	{
		variable[i] = *Nhap.Key[i];
	}
	variable[Nhap.n] = '\0';
}

void InputLoai(char *variable, int max)
{
	int MaxNhap = max;
	rewind(stdin);
	InputSTR Nhap;	
	Nhap.n = 0;
	while(true)
	{
		if(kbhit())
		{
			char c = getch();
			if(c==27) {
				strcpy(variable,"quit");
				return;
			}
			if(!kbhit() && ((int)c == 78 || (int)c == 88 || (int)c == 110 || (int)c == 120) && Nhap.n < MaxNhap)
			{
				
				c = toupper(c);
				Nhap.Key[Nhap.n] = new char;
				cout << c;
				*Nhap.Key[Nhap.n] = c;
				Nhap.n++;
			}
			
			if(Nhap.n>0 && c == '\r')
			{
				if(Nhap.n > 0 && *Nhap.Key[Nhap.n - 1] == ' ')
				{
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
					if(Nhap.n > 0)
					{
						Nhap.n--;
					}
				}	
				break;
			}
			if(c == BACKSPACE && Nhap.n > 0)
			{
				gotoxy(wherex() - 1, wherey());
				cout << " ";
				gotoxy(wherex() - 1, wherey());
				Nhap.n--;
			}
		}
	}
	for(int i = 0; i < Nhap.n; i++)
	{
		variable[i] = *Nhap.Key[i];
	}
	variable[Nhap.n] = '\0';
}

void InputNumber(char *variable, int max) //Ham Chi CHo Nhap So
{
	int MaxNhap = max;
	rewind(stdin);
	InputSTR Nhap;	
	Nhap.n = 0;
	while(true)
	{
		if(kbhit())
		{
			char c = getch();
			if(c==27) {
				strcpy(variable,"quit");
				return;
			}
			if(!kbhit() && !(!((int)c>=48 && (int)c<=57) && !((int)c==45)) && Nhap.n < MaxNhap)
			{
				if(Nhap.n > 0 && c == int(45)) continue;
				c = toupper(c);
				Nhap.Key[Nhap.n] = new char;
				cout << c;
				*Nhap.Key[Nhap.n] = c;
				Nhap.n++;
				
			}
			if(Nhap.n>0 && c== '\r')
			{
				if(Nhap.n > 0 && *Nhap.Key[Nhap.n - 1] == ' ')
				{
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
					if(Nhap.n > 0)
					{
						Nhap.n--;
					}
				}	
				break;
			}
			if(c == BACKSPACE && Nhap.n > 0)
			{
				gotoxy(wherex() - 1, wherey());
				cout << " ";
				gotoxy(wherex() - 1, wherey());
				Nhap.n--;
			}
		}		
	}
	for(int i = 0; i < Nhap.n; i++)
	{
		variable[i] = *Nhap.Key[i];
	}
	variable[Nhap.n] = '\0';

}

void InputStringSpace(char *variable, int max) //Ham Chi Cho Phep Nhap Chuoi + Khoang Trang
{
	int MaxNhap = max;
	InputSTR Nhap;	
	Nhap.n = 0;
	while(true)
	{
		if(kbhit())
		{
			char c = getch();
			if(!kbhit() && !(!((int)c >= 65 && (int)c <= 90) && !((int)c >= 97 && (int)c <= 122) && c != ' ' && !((int)c>=48 && (int)c<=57)))
			{
				if(Nhap.n > 0 && *Nhap.Key[Nhap.n - 1] == ' ' && c == ' ')
				{
					continue;
				}
				if (Nhap.n == 0 && (int)c>=48 && (int)c<=57) {
					continue;
				}
				if(!(Nhap.n == 0 && c == ' ') )
				{
					if(Nhap.n == 0)
						c = toupper(c);
					else
					{
						if(*Nhap.Key[Nhap.n - 1] == ' ')
							c = toupper(c);
						else 
							c = tolower(c);
					}
					Nhap.Key[Nhap.n] = new char;
					cout << c;
					*Nhap.Key[Nhap.n] = c;
					Nhap.n++;
				}
			}
			if(Nhap.n > 0 && c == '\r')
			{
				if(Nhap.n > 0 && *Nhap.Key[Nhap.n - 1] == ' ')
				{
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
					if(Nhap.n > 0)
					{
						Nhap.n--;
					}
				}	
				break;
			}
			if(c == BACKSPACE && Nhap.n > 0)
			{
				gotoxy(wherex() - 1, wherey());
				cout << " ";
				gotoxy(wherex() - 1, wherey());
				Nhap.n--;
			}
		}
			
	}
	for(int i = 0; i < Nhap.n; i++)
	{
		variable[i] = *Nhap.Key[i];
	}
	variable[Nhap.n] = '\0';
}

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


Date StringToDate(string s) //Chuyen Strig Thanh Ngay Thang Nam
{
    Date result;
    result.day = 0;
    result.month = 0;
    result.year = 0;

    result.day = (int)(s[0] - '0') * 10 + (int)(s[1] - '0');
    result.month = (int)(s[2] - '0') * 10 + (int)(s[3] - '0');
    for (int i = 4; i < s.length(); i++) //bat dau tu phan tu 5 (index la 4) tro di, vi 4 phan tu dau la ngay va thang
        result.year = result.year * 10 + (int)(s[i] - '0');

    return result;
}







// cau e


int Search_MSHD(NODES_HOADON First, char* x)
{
	for (NODES_HOADON p = First;  p  != NULL ; p=p->next )
    	if ( strcmp(p->info.SOHD,x)==0  ) return 1;
	return 0;
}

int Search_MaVT(DS_CTHD& hd, char* x){
	for (int i=0;i<hd.soluong;i++) {
		if (strcmp(hd.nodes[i].MAVT,x)==0) return 1;
	}
	return 0;	
}

CHITIET_HOADON nhapChiTietHoaDon(DS_CTHD& hd){
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
		InputNumber(mvt,10);
		if(Search_MaVT(hd,mvt)==1) {
			thongBaoLoi("Ma vat tu da co");
			getch();
			xoaKhungThongBao();
			continue;
		}
		break;	
	}while(true);
	
	gotoxy(125,26);
	cout << "Nhap so luong: ";
	InputNumber(sl,4);

	gotoxy(125,27);
	cout << "Nhap don gia: ";
	InputNumber(dg,9);

	gotoxy(125,28);
	cout << "Nhap trang thai: ";
	InputNumber(tt,1);

	gotoxy(125,29);
	cout << "Nhap VAT: ";
	InputNumber(vat,3);

	strcpy(cthd.MAVT,mvt);
	cthd.SL=atoi(sl);
	cthd.DonGia=atoi(dg);
	cthd.TrangThai=atoi(tt);
	cthd.VAT=atoi(vat);
	return cthd;
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

//void InsertLast_HOADON(DS_HOADON &dshd, HOADON &hd){
//
//	
//	NODES_HOADON nodes_hd=new Nodes_Hoadon;
//	nodes_hd->info=hd;
//	nodes_hd->next=NULL;
//	
//	if (EmptyList_HOADON(dshd)==1){
//		dshd.first=nodes_hd;
//		dshd.last=NULL;
//	}
//	else{
//		dshd.last->next=nodes_hd->next;
//		dshd.last=nodes_hd;
//	}
//}

 int InsertLast_HOADON(DS_HOADON &dshd, HOADON &hd)
{
	NODES_HOADON p = new Nodes_Hoadon;
	if (p == NULL)
	{
		return 1;
	}
	p->info = hd;
	p->next = NULL;
	//TH rong va TH khong rong
	if (EmptyList_HOADON(dshd))
	{
		dshd.first = dshd.last = p;
	}
	else
	{
		dshd.last->next = p;
		dshd.last = p;
	}
	return 0;
}

HOADON nhapHoaDon(NODES_HOADON& first) {
	HOADON hd;
	char day[2],month[2],year[4];
	
	do {
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
		break;
	}while(true);
	
	while(true) {
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
		if(checkDateTime(hd.date)==1) {
			thongBaoLoi("Ngay thang khong dung dinh dang");
			getch();
			xoaKhungThongBao();
			continue;
		}
		break;
	}
	
	gotoxy(125,29);
	cout << "Nhap loai: ";
	InputLoai(hd.LoaiHD,1);
	return hd;
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

void toMauHoaDon(HOADON hd,int i) {
	SetColor(VANGDAM);
	gotoxy(5,i+6);
	cout << i+1;
	gotoxy(15,i+6);
	cout << hd.SOHD;
	gotoxy(39,i+6);
	cout << hd.date.day <<"/"<<hd.date.month <<"/"<<hd.date.year;
	gotoxy(53,i+6);
	cout << hd.LoaiHD;
	SetBGColor(DEN);
}

void boToMauHoaDon(HOADON hd,int i,int key) {
	if (key==UP) {
		SetColor(TRANG);
		gotoxy(5,i+7);
		cout << i+2;
		gotoxy(15,i+7);
		cout << hd.SOHD;
		gotoxy(39,i+7);
		cout << hd.date.day <<"/"<<hd.date.month <<"/"<<hd.date.year;
		gotoxy(53,i+7);
		cout << hd.LoaiHD;
	}
	else if (key==DOWN) {
		SetColor(TRANG);
		gotoxy(5,i+5);
		cout << i;
		gotoxy(15,i+5);
		cout << hd.SOHD;
		gotoxy(39,i+5);
		cout << hd.date.day <<"/"<<hd.date.month <<"/"<<hd.date.year;
		gotoxy(53,i+5);
		cout << hd.LoaiHD;
	}
	
}

void lietKeHoaDon(NODES_HOADON hd) {
	bool exit = false;
	int i=0;
	HOADON ds[100];
	for (NODES_HOADON p = hd; p!=NULL; p = p->next) {
		gotoxy(5,i+6);
		cout << i+1;
		gotoxy(15,i+6);
		cout << p->info.SOHD;
		gotoxy(39,i+6);
		cout << p->info.date.day <<"/"<<p->info.date.month <<"/"<<p->info.date.year;
		gotoxy(53,i+6);
		cout << p->info.LoaiHD;
		ds[i++]=p->info;
	}
	int first=0;
	toMauHoaDon(ds[first],first);
	showCTHD(ds[first]);
	while(!exit) {
		char key;
		key = getch();
		if (key==UP) {
			first--;
			if(first<0) first=0;
			xoaDataChiTietHoaDon();
			showCTHD(ds[first]);
			boToMauHoaDon(ds[first+1],first,key);
			toMauHoaDon(ds[first],first);
		}
		if (key==DOWN) {
			first++;
			if(first<i) {
				xoaDataChiTietHoaDon();
				showCTHD(ds[first]);
				boToMauHoaDon(ds[first-1],first,key);
				toMauHoaDon(ds[first],first);
			}else first--;
			
		}
		if (key==ESC) exit=true;
	}
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

void veKhungVatTu() {
	VeKhung(6,3,91,40);
	// line ngang
	for (int i=7;i<=97;i++) {  
		gotoxy(i,5);
		cout << char(196);
	}
		gotoxy(6,5);
		cout << char(195);
		gotoxy(97,5);
		cout << char(180);
	// line doc 1	
	for (int i=4;i<=42;i++) { 
		gotoxy(11,i);
		cout << char(179);
	}
		gotoxy(11,3);
		cout << char(194);
		gotoxy(11,5);
		cout << char(197);
		gotoxy(11,43);
		cout << char(193);
	// line doc 2	
	for (int i=4;i<=42;i++) { 
		gotoxy(25,i);
		cout << char(179);
	}
		gotoxy(25,3);
		cout << char(194);
		gotoxy(25,5);
		cout << char(197);
		gotoxy(25,43);
		cout << char(193);
	// line doc 3	
	for (int i=4;i<=42;i++) { 
		gotoxy(77,i);
		cout << char(179);
	}
		gotoxy(77,3);
		cout << char(194);
		gotoxy(77,5);
		cout << char(197);
		gotoxy(77,43);
		cout << char(193);
	// line doc 4	
	for (int i=4;i<=42;i++) { 
		gotoxy(91,i);
		cout << char(179);
	}
		gotoxy(91,3);
		cout << char(194);
		gotoxy(91,5);
		cout << char(197);
		gotoxy(91,43);
		cout << char(193);
	SetColor(LUC);
	gotoxy(7,4);
	cout << "STT";
	gotoxy(14,4);
	cout << "MA VAT TU";
	gotoxy(47,4);
	cout << "TEN VAT TU";	
	gotoxy(79,4);
	cout << "DON VI TINH";
	gotoxy(93,4);
	cout << "SLT";
	SetColor(TRANG);
}
	
	
	
int Full_DSNV(DS_NV ds){
	if(ds.soluong==MAXNV) return true;
	else return false;
}

int Check_NV(DS_NV &ds, char* ma){
	for (int i=0;i<ds.soluong;i++){
		if (ds.nodes[i]->MANV,atoi(ma)==0) return 1;
	}
	return 0;
}

int Check_CMND(DS_NV &ds, char *cmnd){
	for (int i=0;i<ds.soluong;i++){
		if(stricmp(ds.nodes[i]->CMND,cmnd)==0)return 1;
	}	
	return 0;
}

NHANVIEN Insert_NV(DS_NV &ds){
	NHANVIEN nv;
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


void List_NhanVien_All(DS_NV ds){
		int y=6;
		for (int i=0; i<ds.soluong;i++){
			gotoxy(6,y+i);
			cout<<ds.nodes[i]->MANV<<endl;
			gotoxy(20,y+i);
			cout<<ds.nodes[i]->HO<<endl;
			gotoxy(35,y+i);
			cout<<ds.nodes[i]->TEN<<endl;
			gotoxy(50,y+i);
			cout<<ds.nodes[i]->PHAI<<endl;
			gotoxy(65,y+i);
			cout<<ds.nodes[i]->CMND<<endl;
		}
		
}

void InsertLastNhanVien(DS_NV& ds, NHANVIEN nv) {
	if (Full_DSNV(ds)==true){
		thongBaoLoi("Danh sach nhan vien da day");
		getch();
		xoaKhungThongBao();
		return;
	}	
	else{
		ds.nodes[ds.soluong]=new NHANVIEN;
		*ds.nodes[ds.soluong]=nv;
		ds.soluong++;
	}
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
		hd.date.day=stoi(line_temp);
		line_temp="";
		i++;
		
		while(line[i]!='|'){
			line_temp=line_temp+line[i];
			i++;
		}
		hd.date.month=stoi(line_temp);
		line_temp="";
		i++;
		
		while(line[i]!='|'){
			line_temp=line_temp+line[i];
			i++;
		}
		hd.date.year=stoi(line_temp);
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

void DocFileNhanVien(DS_NV& dsnv, string nameFile)
{
	fstream f;
	f.open(nameFile, ios::in);

	if (f.fail()) {
		thongBaoLoi("DOC FILE THAT BAI!");
		getch();
		xoaKhungThongBao();
		return;
	}

	string line;
	
	NHANVIEN addNhanVien;

	while (!f.eof()) {
		getline(f, line); //doc 1 dong va cho vao line

		if (line == "") { //neu rong thi ko xet 
			continue;
		}
		
		ReadLine_NhanVien(line, addNhanVien);
		InsertLastNhanVien(dsnv, addNhanVien);
		
	}

	f.close();
}

// vat tu

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
	cout<<"\n"<<tree->info.MAVT;
	cout<<"\n"<<tree->info.TENVT;
	cout<<"\n"<<tree->info.DVT;
	cout<<"\n"<<tree->info.SLT<<endl;	
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


void NhapMotVatTu(TREE_VATTU &tree){
	VATTU vt;
	char MVT[21];
	char TenVT[51];
	char DonViTinh[11];
	char SoLuongTon[11];
	
	int a=0;
	do{
		cout<<"\n\tNhap ma vat tu : ";
		InputString(MVT, 20);
		a=1;
		if(stricmp(MVT,"quit")==0){
			ThemCay(tree,vt,MVT);
			return;	
		}
		if(Cay_Rong(tree)==false){
			if(KiemTraVatTuTrung(MVT,tree)!=0){
				cout<<"\n\tMa vat tu da ton tai, nhap lai: ";
				a=0;
			}	
		}
	}while(a == 0);
			
		cout<<"\n\tNhap ten vat tu: ";
		fflush(stdin);
		InputStringSpace(TenVT, 50);
		cout<<"\n\tNhap don vi tinh: ";
		fflush(stdin);
		InputString(DonViTinh, 10);
		cout<<"\n\tNhap so luong ton: ";
		fflush(stdin);
		InputNumber(SoLuongTon, 10);
		
		strcpy(vt.TENVT,TenVT);
		strcpy(vt.DVT,DonViTinh);
		vt.SLT=atoi(SoLuongTon);
		ThemCay(tree,vt,MVT);
		GhiFileVT(tree,"VATTU.txt");
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

void XoaVT(TREE_VATTU& tree, char deleteKey[])
{
	if (tree == NULL) //dieu kien dung de quy
		cout << "Phan tu can xoa khong ton tai!";
	else //van con phan tu
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
	}

}

void SuaVT(TREE_VATTU &tree){
	VATTU vt;	
	cout <<"\nMoi ban nhap ten moi: ";
	InputStringSpace(vt.TENVT,50);
	strcpy(tree->info.TENVT,vt.TENVT);
	cout <<"\nMoi ban nhap don vi tinh moi: ";
	InputString(vt.DVT,10);
	strcpy(tree->info.DVT,vt.DVT);

}

void SuaCay(TREE_VATTU &tree){
	TREE_VATTU p;
	char MVT[10];
	int a = 0;
	while(a==0){
		InputString(MVT,10);
		p = TimKiemVatTu(tree,MVT);
		if(p==NULL){
			cout<<"\nMa vat tu khong ton tai, xin hay nhap lai!"<<endl;
		}
		else{
			XuatMotPhanTu(p);
			SuaVT(p);
			a=1;
		}
	}	
}

void CapNhatSoLuongTon(HOADON addHoaDon, TREE_VATTU& tree)
{
	TREE_VATTU temp;

	for (int i = 0; i < addHoaDon.PTR_CTHD.soluong; i++) {
		temp = TimKiemVatTu(tree, addHoaDon.PTR_CTHD.nodes[i].MAVT); //con tro temp tro toi phan tu can xu ly

		if (stricmp(addHoaDon.LoaiHD,"X")==0) {
			temp->info.SLT -= addHoaDon.PTR_CTHD.nodes[i].SL; //cap nhat
		}
		else {
			temp->info.SLT += addHoaDon.PTR_CTHD.nodes[i].SL; //cap nhat
		}	
	}
}

int main(){
	resizeConsole(1920,1080);
	fullScreen();
	RemoveScroll();
	giaoDienKhung(); 
	TREE_VATTU tree;
	Khoi_Tao_Cay(tree);
	VATTU vt;
	veKhungVatTu();
	DocFileVatTu(tree,"VATTU.txt");
	//veKhungHoaDon();
	//veKhungChiTietHoaDon(); 
	//SuaCay(tree);
	//NhapMotVatTu(tree);
	GhiFileVT(tree,"VATTU.txt");
	showDSVatTu(tree,0);
	//veKhungNhanVien();
	//DS_NV NV;
	//NV.soluong=0;
//	HOADON hd;
//	DS_HOADON hoadon;
//	CreateList_HOADON(hoadon);
//	hd=nhapHoaDon(hoadon.first);
//	InsertLast_HOADON(hoadon,hd);
//	hoadon.first->next;
	//DocFileNhanVien(NV,"NhanVien.txt");
	//List_NhanVien_All(NV);
	//cout << NV.nodes[0]->CMND;
	//lietKeHoaDon(NV.nodes[0]->PTR_HD.first);
	//giaoDienMenu();

	getch();
}
