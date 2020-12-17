#include "lib.h"
#include "QLVT.h"
#include<string>
using namespace std;
#define MAXNV 500
#define MAXVT 20
int Index = 1;

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
	else if (strcmp(maVT.c_str(),tree->info.MAVT)<0){
		ThemCay(tree->left,vt,maVT);
	}
	else{
		ThemCay(tree->right,vt,maVT);
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

int KiemTraVatTuTrung(char MVT[], TREE_VATTU tree)
{
	if (TimKiemVatTu(tree, MVT) == NULL) {
		return 0;
	}
	return 1;
}

int KiemTraVatTuDeSua(char FixMVT[], VATTU NodeHienTai, TREE_VATTU tree)
{
	if (strcmp(FixMVT, NodeHienTai.MAVT) != 0) { //chi xet trung khi ma vat tu cua fixing bi thay doi
		if (TimKiemVatTu(tree, FixMVT) != NULL) { //trung ma vat tu
			return 1;
		}
	}
	return 0;
}


void thongBaoLoi(string s) {
	SetColor(DODAM);
	gotoxy(120,43);
	cout << s;
	SetColor(TRANG);
}

string FloatToString(float a)
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


void TreeToArr(TREE_VATTU t,VATTU* arr){
	if (t == NULL)
		return;
	TreeToArr(t->right, arr); 
	strcpy(arr[Index].MAVT, t->info.MAVT);
	strcpy(arr[Index].TENVT, t->info.TENVT);
	strcpy(arr[Index].DVT, t->info.DVT);
	arr[Index++].SLT = t->info.SLT;
	TreeToArr(t->left, arr);
}

void XuatArr(TREE_VATTU tree, VATTU* arr){
	TreeToArr(tree,arr);
	for(int i = 1; i <= DemNode(tree);i++)
	{
		cout<<"\n\t"<<arr[i].MAVT;
		cout<<"\t"<<arr[i].TENVT;
		cout<<"\t"<<arr[i].DVT;
		cout<<"\t"<<arr[i].SLT<<endl;
	}
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
		if(strcmp(MVT,"quit")==0){
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


void XuatNodeLa(TREE_VATTU t)
{
	if (t != NULL)
	{
		// x? lý cái node hi?n t?i
		if (t->left == NULL && t->right == NULL)
		{
			cout <<endl<< t->info.MAVT << "  ";
			cout << t->info.TENVT << "  ";
			cout << t->info.DVT << "  ";
			cout << t->info.SLT << "  ";
		}
		XuatNodeLa(t->left);
		XuatNodeLa(t->right);
	}
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

void XoaCay(TREE_VATTU& tree, char deleteKey[])
{
	if (tree == NULL) //dieu kien dung de quy
		cout << "Phan tu can xoa khong ton tai!";
	else //van con phan tu
	{
		if (strcmp(deleteKey, tree->info.MAVT) < 0) //khoa can them nho hon nut hien tai thi qua trai
			XoaCay(tree->left, deleteKey);
		else if (strcmp(deleteKey, tree->info.MAVT) > 0) //khoa can them lon hon nut hien tai thi qua phai
			XoaCay(tree->right, deleteKey);
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





void menu(){
	TREE_VATTU tree;
	Khoi_Tao_Cay(tree);
	VATTU *arr = new VATTU[DemNode(tree)];
	DocFileVatTu(tree,"VATTU.txt");
	char luachon[2];
	while(true){
		cout<<"Nhap lua chon: "<<endl;
		cout<<"1./Them vat tu"<<endl;
		cout<<"2./Xuat vat tu"<<endl;
		InputNumber(luachon,2);
		cout<<endl;
		switch(atoi(luachon)){
			case 1:{
				
				NhapMotVatTu(tree);
				XuatNodeLa(tree);
				break;
			}
			case 2:{
				cout<<"\n"<<DemNode(tree);
				break;
			}
			case 3:{
				XuatArr(tree,arr);
				break;
			}
			case 4:{
				char deleteKey[10];
				InputString(deleteKey,11);
				XoaCay(tree,deleteKey);
				GhiFileVT(tree,"VATTU.txt");
				break;
			}
			default: break;		
			
		}
	}
}


int main(){
	TREE_VATTU tree;
	VATTU vt;
	menu();
	
}



