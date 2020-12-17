
TREE_VATTU TimKiemVatTu(TREE_VATTU tree, char MVT[])
{
    if (tree == NULL){
        return NULL; //dieu kien dung de quy->ko tim thay node can tim
    }

    if (strcmp(MVT, tree->info.MAVT) == 0) {
        return tree;
    }
    else if (strcmp(MVT, tree->info.MAVT) > 0) {
        return TimKiemVatTu(tree->right, MVT); //return ve ham chu ko don thuan la chi goi ham nhu cac thuat toan duyet, nhu vay se giu duoc ket qua cua vong de quy sau nhat da di toi
    }
    else {
        return TimKiemVatTu(tree->left, MVT);
    }
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

	gotoxy(125,28);
	cout << "Nhap trang thai: ";
	InputNumber(tt,1);
	if(strcmp(tt,"quit")==0) {
		strcpy(cthd.MAVT,"quit");
		return cthd;
	}

	gotoxy(125,29);
	cout << "Nhap VAT: ";
	InputNumber(vat,3);
	if(strcmp(vat,"quit")==0) {
		strcpy(cthd.MAVT,"quit");
		return cthd;
	}
	
	CapNhatSoLuongTon(hoadon,tree);
	
	strcpy(cthd.MAVT,mvt);
	cthd.SL=atof(sl);
	cthd.DonGia=atoi(dg);
	cthd.TrangThai=atoi(tt);
	cthd.VAT=atoi(vat);
	gotoxy(135,42);
	cout << (float)cthd.SL;
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



HOADON nhapHoaDon(NODES_HOADON& first,TREE_VATTU& tree ) {
	HOADON hd;
	CHITIET_HOADON cthd;
	CreateList_CTHD(hd.PTR_CTHD);
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
		if(stricmp(hd.SOHD,"quit")==0) {
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
		}else break;
	}
	if(stricmp(cthd.MAVT,"quit")==0) {
		strcpy(hd.SOHD,"quit");
	}
	return hd;
}


